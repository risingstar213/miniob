/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Meiyi & Wangyunlai on 2021/5/13.
//

#include <limits.h>
#include <string.h>
#include <algorithm>

#include "common/defs.h"
#include "storage/table/table.h"
#include "storage/table/table_meta.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/buffer/disk_buffer_pool.h"
#include "storage/record/record_manager.h"
#include "storage/common/condition_filter.h"
#include "storage/common/meta_util.h"
#include "storage/index/index.h"
#include "storage/index/bplus_tree_index.h"
#include "storage/trx/trx.h"

#include "sql/operator/physical_operator.h"
#include "sql/stmt/select_stmt.h"
#include "sql/expr/expression.h"

#include "sql/optimizer/logical_plan_generator.h"
#include "sql/optimizer/physical_plan_generator.h"

Table::~Table()
{
  if (record_handler_ != nullptr) {
    delete record_handler_;
    record_handler_ = nullptr;
  }

  if (data_buffer_pool_ != nullptr) {
    data_buffer_pool_->close_file();
    data_buffer_pool_ = nullptr;
  }

  for (std::vector<Index *>::iterator it = indexes_.begin(); it != indexes_.end(); ++it) {
    Index *index = *it;
    delete index;
  }
  indexes_.clear();

  // if (view_stmt_ != nullptr) {
  //   delete view_stmt_;
  //   view_stmt_ = nullptr;
  // }

  if (view_operator_ != nullptr) {
    delete view_operator_;
    view_operator_ = nullptr;
  }

  LOG_INFO("Table has been closed: %s", name());
}

RC Table::create(int32_t table_id, 
                 const char *path, 
                 const char *name, 
                 const char *base_dir, 
                 int attribute_count, 
                 const AttrInfoSqlNode attributes[])
{
  if (table_id < 0) {
    LOG_WARN("invalid table id. table_id=%d, table_name=%s", table_id, name);
    return RC::INVALID_ARGUMENT;
  }

  if (common::is_blank(name)) {
    LOG_WARN("Name cannot be empty");
    return RC::INVALID_ARGUMENT;
  }
  LOG_INFO("Begin to create table %s:%s", base_dir, name);

  if (attribute_count <= 0 || nullptr == attributes) {
    LOG_WARN("Invalid arguments. table_name=%s, attribute_count=%d, attributes=%p", name, attribute_count, attributes);
    return RC::INVALID_ARGUMENT;
  }

  RC rc = RC::SUCCESS;

  // 使用 table_name.table记录一个表的元数据
  // 判断表文件是否已经存在
  int fd = ::open(path, O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
  if (fd < 0) {
    if (EEXIST == errno) {
      LOG_ERROR("Failed to create table file, it has been created. %s, EEXIST, %s", path, strerror(errno));
      return RC::SCHEMA_TABLE_EXIST;
    }
    LOG_ERROR("Create table file failed. filename=%s, errmsg=%d:%s", path, errno, strerror(errno));
    return RC::IOERR_OPEN;
  }

  close(fd);

  // 创建文件
  if ((rc = table_meta_.init(table_id, name, attribute_count, attributes)) != RC::SUCCESS) {
    LOG_ERROR("Failed to init table meta. name:%s, ret:%d", name, rc);
    return rc;  // delete table file
  }

  std::fstream fs;
  fs.open(path, std::ios_base::out | std::ios_base::binary);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", path, strerror(errno));
    return RC::IOERR_OPEN;
  }

  // 记录元数据到文件中
  table_meta_.serialize(fs);
  fs.close();

  std::string data_file = table_data_file(base_dir, name);
  BufferPoolManager &bpm = BufferPoolManager::instance();
  rc = bpm.create_file(data_file.c_str());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to create disk buffer pool of data file. file name=%s", data_file.c_str());
    return rc;
  }

  rc = init_record_handler(base_dir);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to create table %s due to init record handler failed.", data_file.c_str());
    // don't need to remove the data_file
    return rc;
  }

  base_dir_ = base_dir;
  LOG_INFO("Successfully create table %s:%s", base_dir, name);
  return rc;
}

RC Table::create_view(int table_id,
                const char *name,
                int attribute_count,
                const AttrInfoSqlNode attributes[],
                SelectStmt *view_stmt)
{
  if (table_id < 0) {
    LOG_WARN("invalid table id. table_id = %d, view_name=%s", table_id, name);
  }

  if (common::is_blank(name)) {
    LOG_WARN("Name cannot be empty");
    return RC::INVALID_ARGUMENT;
  }

  LOG_INFO("Begin to create view %s", name);

  if (attribute_count <= 0 || nullptr == attributes) {
    LOG_WARN("Invalid arguments. table_name=%s, attribute_count=%d, attributes=%p", name, attribute_count, attributes);
    return RC::INVALID_ARGUMENT;
  }

  RC rc = RC::SUCCESS;
  // no persistence temporarily
  if ((rc = table_meta_.init(table_id, name, attribute_count, attributes)) != RC::SUCCESS) {
    LOG_ERROR("Failed to init table meta. name:%s, ret:%d", name, rc);
    return rc;  // delete table file
  }

  view_can_update_ = view_check_can_update(view_stmt);

  if (view_can_update_) {
    Table *table = view_stmt->tables()[0];
    auto &exprs = view_stmt->query_exprs();
    for (int i = 0; i < exprs.size(); i++) {
      FieldExpr *expr = dynamic_cast<FieldExpr *>(exprs[i]);
      view_field_metas_.emplace_back(expr->field().meta());
    }
  }

  is_view_ = true;
  // view_stmt_ = view_stmt;

  view_table_ = view_stmt->tables()[0];

  std::unique_ptr<LogicalOperator> logical_oper;
  LogicalPlanGenerator logical_generator;
  logical_generator.create(view_stmt, logical_oper);
  PhysicalPlanGenerator physical_generator;
  std::unique_ptr<PhysicalOperator> physical_oper;
  physical_generator.create(*logical_oper, physical_oper);
  view_operator_ = physical_oper.release();

  return RC::SUCCESS;
}

void Table::set_view_trx(Trx *trx)
{
  view_trx_ = trx;
}

bool Table::view_check_can_update(SelectStmt *view_stmt)
{
  if (view_stmt->order_fields().size() > 0 || view_stmt->group_fields().size() >0 ) {
    return false;
  }
  if (view_stmt->has_aggregation()) {
    return false;
  }

  auto &exprs = view_stmt->query_exprs();
  for (int i = 0; i < exprs.size(); i++) {
    if (exprs[i]->type() != ExprType::FIELD) {
      return false;
    }
  }

  if (view_stmt->tables().size() > 1) {
    return false;
  }

  return true;
}

static int find_index_in_tuple(Table *table, const FieldMeta* field)
{
  int field_num = table->table_meta().field_num();
  int sys_field_num = table->table_meta().sys_field_num();
  for (int i = 0; i < field_num - sys_field_num; i++) {
    if (table->table_meta().field(i + sys_field_num)->name() == field->name()) {
      return i;
    }
  }
  return 0;
}

RC Table::view_insert_record(std::vector<Value> values)
{
  if (!view_can_update_) {
    return RC::INTERNAL;
  }

  Table *table = view_table_; // view_stmt_->tables()[0];
  
  std::vector<Value> new_values;
  Value temp;
  int field_num = table->table_meta().field_num();
  int sys_field_num = table->table_meta().sys_field_num();
  for (int i = sys_field_num; i < field_num; i++) {
    table->table_meta().field(i);
    temp.cast_to_null(table->table_meta().field(i)->type());
    new_values.emplace_back(temp);
  }

  for (int i = 0; i < view_field_metas_.size(); i++) {
    // FieldExpr *expr = dynamic_cast<FieldExpr *>(exprs[i]);
    int field_index = find_index_in_tuple(table, view_field_metas_[i]);
    new_values[field_index] = values[i];
  }

  // check null
  for (int i = 0; i < field_num - sys_field_num; i++) {
    if (new_values[i].is_null() && !table->table_meta().field(i + sys_field_num)->nullable()) {
      return RC::INTERNAL;
    }
  }

  Record new_record;
  RC rc = table->make_record(new_values.size(), new_values.data(), new_record);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  rc = table->resolve_unique_before_insert(view_trx_, &new_record);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  
  rc = table->insert_record(new_record);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  return RC::SUCCESS;
}

RC Table::view_delete_record()
{
  if (!view_can_update_) {
    return RC::INTERNAL;
  }

  Table *table = view_table_; // view_stmt_->tables()[0];

  Record *record;
  if (!view_operator_->current_tuple()->get_record(table, record)) {
    return RC::INTERNAL;
  }
  // delete it straightly
  RC rc = view_trx_->delete_record(table, *record);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to delete record: %s", strrc(rc));
    return rc;
  }
  return RC::SUCCESS;
}

RC Table::view_update_record(std::vector<Value> values)
{
  if (!view_can_update_) {
    return RC::INTERNAL;
  }

  Table *table = view_table_; // view_stmt_->tables()[0];

  Record *record;
  if (!view_operator_->current_tuple()->get_record(table, record)) {
    return RC::INTERNAL;
  }

  std::vector<Value> new_values;
  int field_num = table->table_meta().field_num();
  int sys_field_num = table->table_meta().sys_field_num();
  for (int i = sys_field_num; i < field_num; i++) {
    Value temp;
    // RC rc = row_tuple->cell_at(i, temp);
    // if (rc != RC::SUCCESS) {
    //   return rc;
    // }

    const FieldMeta *field_meta = table->table_meta().field(i);
    temp.set_type(field_meta->type());
    temp.set_data(record->data() + field_meta->offset(), field_meta->len());
    if (field_meta->nullable()) {
      temp.set_null(*(bool *)(record->data() + field_meta->offset() - 1));
    } else {
      temp.set_null(false);
    }
    new_values.emplace_back(temp);
  }

  // auto &exprs = view_stmt_->query_exprs();
  for (int i = 0; i < view_field_metas_.size(); i++) {
    // FieldExpr *expr = dynamic_cast<FieldExpr *>(exprs[i]);
    int field_index = find_index_in_tuple(table, view_field_metas_[i]);
    new_values[field_index] = values[i];
  }

  // check null
  for (int i = 0; i < field_num - sys_field_num; i++) {
    if (new_values[i].is_null() && !table->table_meta().field(i + sys_field_num)->nullable()) {
      return RC::INTERNAL;
    }
  }

  Record new_record;
  RC rc = table->make_record(new_values.size(), new_values.data(), new_record);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  rc = table->resolve_unique_before_update(view_trx_, record, &new_record);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  rc = view_trx_->update_record(table, *record, new_record);

  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to update record: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC Table::remove(const char *name)
{
  if (common::is_blank(name)) {
    LOG_WARN("Name cannot be empty");
    return RC::INVALID_ARGUMENT;
  }
  LOG_INFO("Begin to remove table %s:%s", base_dir_.c_str(), name);

  // remove the relevant index files
  for (auto idx : indexes_) {
    std::string index_file = table_index_file(base_dir_.c_str(), name, idx->index_meta().name());
    delete idx;  // the file will be closed in dtor
    if (0 != ::unlink(index_file.c_str())) {
      LOG_ERROR("Delete index file failed. filename=%s, errmsg=%d:%s", index_file.c_str(), errno, strerror(errno));
      return RC::IOERR_CLOSE;
    }
  }
  indexes_.clear();

  // close the data file and clean relevant resources
  assert(nullptr != record_handler_);
  record_handler_->close();
  delete record_handler_;
  record_handler_ = nullptr;

  std::string data_file = table_data_file(base_dir_.c_str(), name);
  assert(nullptr != data_buffer_pool_);
  BufferPoolManager::instance().close_file(data_file.c_str());
  // NOTE: after bpm.close_file, the dbp has been released
  data_buffer_pool_ = nullptr;

  // remove the data file
  if (0 != ::unlink(data_file.c_str())) {
    LOG_ERROR("Delete data file failed. filename=%s, errmsg=%d:%s", data_file.c_str(), errno, strerror(errno));
    return RC::IOERR_CLOSE;
  }

  // remove the meta file
  std::string meta_file = table_meta_file(base_dir_.c_str(), name);
  if (0 != ::unlink(meta_file.c_str())) {
    LOG_ERROR("Delete data file failed. filename=%s, errmsg=%d:%s", meta_file.c_str(), errno, strerror(errno));
    return RC::IOERR_CLOSE;
  }

  return RC::SUCCESS;
  // after we invoke the func, the dtor do nothing.
}

RC Table::open(const char *meta_file, const char *base_dir)
{
  // 加载元数据文件
  std::fstream fs;
  std::string meta_file_path = std::string(base_dir) + common::FILE_PATH_SPLIT_STR + meta_file;
  fs.open(meta_file_path, std::ios_base::in | std::ios_base::binary);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open meta file for read. file name=%s, errmsg=%s", meta_file_path.c_str(), strerror(errno));
    return RC::IOERR_OPEN;
  }
  if (table_meta_.deserialize(fs) < 0) {
    LOG_ERROR("Failed to deserialize table meta. file name=%s", meta_file_path.c_str());
    fs.close();
    return RC::INTERNAL;
  }
  fs.close();

  // 加载数据文件
  RC rc = init_record_handler(base_dir);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to open table %s due to init record handler failed.", base_dir);
    // don't need to remove the data_file
    return rc;
  }

  base_dir_ = base_dir;

  const int index_num = table_meta_.index_num();
  for (int i = 0; i < index_num; i++) {
    const IndexMeta *index_meta = table_meta_.index(i);
    std::vector<string> field_names = index_meta->fields();
    std::vector<FieldMeta> field_metas;
    for (size_t i = 0; i < field_names.size(); i++) {
      const FieldMeta *field_meta = table_meta_.field(field_names[i].c_str());
      if (field_meta == nullptr) {
        LOG_ERROR("Found invalid index meta info which has a non-exists field. table=%s, index=%s",
            name(),
            index_meta->name());
        // skip cleanup
        //  do all cleanup action in destructive Table function
        return RC::INTERNAL;
      }
      field_metas.push_back(*field_meta);
    }

    BplusTreeIndex *index = new BplusTreeIndex();
    std::string index_file = table_index_file(base_dir, name(), index_meta->name());
    rc = index->open(index_file.c_str(), *index_meta, field_metas);
    if (rc != RC::SUCCESS) {
      delete index;
      LOG_ERROR("Failed to open index. table=%s, index=%s, file=%s, rc=%d:%s",
          name(),
          index_meta->name(),
          index_file.c_str(),
          rc,
          strrc(rc));
      // skip cleanup
      //  do all cleanup action in destructive Table function.
      return rc;
    }
    indexes_.push_back(index);
  }

  return rc;
}

RC Table::insert_record(Record &record)
{
  RC rc = RC::SUCCESS;
  rc = record_handler_->insert_record(record.data(), table_meta_.record_size(), &record.rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Insert record failed. table name=%s, rc=%s", table_meta_.name(), strrc(rc));
    return rc;
  }

  rc = insert_entry_of_indexes(record.data(), record.rid());
  if (rc != RC::SUCCESS) { // 可能出现了键值重复
    RC rc2 = delete_entry_of_indexes(record.data(), record.rid(), false/*error_on_not_exists*/);
    if (rc2 != RC::SUCCESS) {
      LOG_ERROR("Failed to rollback index data when insert index entries failed. table name=%s, rc=%d:%s",
                name(), rc2, strrc(rc2));
    }
    rc2 = record_handler_->delete_record(&record.rid());
    if (rc2 != RC::SUCCESS) {
      LOG_PANIC("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
                name(), rc2, strrc(rc2));
    }
  }
  return rc;
}

RC Table::visit_record(const RID &rid, bool readonly, std::function<void(Record &)> visitor)
{
  return record_handler_->visit_record(rid, readonly, visitor);
}

RC Table::get_record(const RID &rid, Record &record)
{
  const int record_size = table_meta_.record_size();
  char *record_data = (char *)malloc(record_size);
  ASSERT(nullptr != record_data, "failed to malloc memory. record data size=%d", record_size);

  auto copier = [&record, record_data, record_size](Record &record_src) {
    memcpy(record_data, record_src.data(), record_size);
    record.set_rid(record_src.rid());
  };
  RC rc = record_handler_->visit_record(rid, true/*readonly*/, copier);
  if (rc != RC::SUCCESS) {
    free(record_data);
    LOG_WARN("failed to visit record. rid=%s, table=%s, rc=%s", rid.to_string().c_str(), name(), strrc(rc));
    return rc;
  }

  record.set_data_owner(record_data, record_size);
  return rc;
}

RC Table::recover_insert_record(Record &record)
{
  RC rc = RC::SUCCESS;
  rc = record_handler_->recover_insert_record(record.data(), table_meta_.record_size(), record.rid());
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Insert record failed. table name=%s, rc=%s", table_meta_.name(), strrc(rc));
    return rc;
  }

  rc = insert_entry_of_indexes(record.data(), record.rid());
  if (rc != RC::SUCCESS) { // 可能出现了键值重复
    RC rc2 = delete_entry_of_indexes(record.data(), record.rid(), false/*error_on_not_exists*/);
    if (rc2 != RC::SUCCESS) {
      LOG_ERROR("Failed to rollback index data when insert index entries failed. table name=%s, rc=%d:%s",
                name(), rc2, strrc(rc2));
    }
    rc2 = record_handler_->delete_record(&record.rid());
    if (rc2 != RC::SUCCESS) {
      LOG_PANIC("Failed to rollback record data when insert index entries failed. table name=%s, rc=%d:%s",
                name(), rc2, strrc(rc2));
    }
  }
  return rc;
}

const char *Table::name() const
{
  return table_meta_.name();
}

const TableMeta &Table::table_meta() const
{
  return table_meta_;
}

RC Table::make_record(int value_num, const Value *values, Record &record)
{
  // 检查字段类型是否一致
  if (value_num + table_meta_.sys_field_num() != table_meta_.field_num()) {
    LOG_WARN("Input values don't match the table's schema, table name:%s", table_meta_.name());
    return RC::SCHEMA_FIELD_MISSING;
  }

  const int normal_field_start_index = table_meta_.sys_field_num();
  for (int i = 0; i < value_num; i++) {
    const FieldMeta *field = table_meta_.field(i + normal_field_start_index);
    const Value &value = values[i];
    if (field->type() != value.attr_type()) {
      LOG_ERROR("Invalid value type. table name =%s, field name=%s, type=%d, but given=%d",
                table_meta_.name(), field->name(), field->type(), value.attr_type());
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  }

  // 复制所有字段的值
  int record_size = table_meta_.record_size();
  char *record_data = (char *)malloc(record_size);

  for (int i = 0; i < value_num; i++) {
    const FieldMeta *field = table_meta_.field(i + normal_field_start_index);
    const Value &value = values[i];
    if (field->type() == TEXTS) {
      if (value.get_text().size() > 65535) {
        return RC::INVALID_ARGUMENT;
        // value.set_string(value)
      }

      TextDataMeta *meta = (TextDataMeta *)(record_data + field->offset());
      record_handler_->insert_text(value.get_text(), meta);
      
      if (field->nullable()) {
        *(bool *)(record_data + field->offset() - 1) = value.is_null();
      }
      continue;
    }
    size_t copy_len = field->len();
    if (field->type() == CHARS || field->type() == DATES) {
      const size_t data_len = value.length();
      if (copy_len > data_len) {
        copy_len = data_len + 1;
      }
    }
    memcpy(record_data + field->offset(), value.data(), copy_len);
    if (field->nullable()) {
      *(bool *)(record_data + field->offset() - 1) = value.is_null();
    }
  }

  record.set_data_owner(record_data, record_size);
  return RC::SUCCESS;
}

RC Table::init_record_handler(const char *base_dir)
{
  std::string data_file = table_data_file(base_dir, table_meta_.name());

  RC rc = BufferPoolManager::instance().open_file(data_file.c_str(), data_buffer_pool_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to open disk buffer pool for file:%s. rc=%d:%s", data_file.c_str(), rc, strrc(rc));
    return rc;
  }

  record_handler_ = new RecordFileHandler();
  rc = record_handler_->init(data_buffer_pool_);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to init record handler. rc=%s", strrc(rc));
    data_buffer_pool_->close_file();
    data_buffer_pool_ = nullptr;
    delete record_handler_;
    record_handler_ = nullptr;
    return rc;
  }

  return rc;
}

RC Table::get_record_scanner(RecordFileScanner &scanner, Trx *trx, bool readonly)
{
  RC rc = scanner.open_scan(this, *data_buffer_pool_, trx, readonly, nullptr);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("failed to open scanner. rc=%s", strrc(rc));
  }
  return rc;
}

RC Table::create_index(Trx *trx, std::vector<const FieldMeta *> field_metas, const char *index_name, bool is_unique)
{
  if (common::is_blank(index_name) || field_metas.size() == 0) {
    LOG_INFO("Invalid input arguments, table name is %s, index_name is blank or attribute_name is blank", name());
    return RC::INVALID_ARGUMENT;
  }

  IndexMeta new_index_meta;
  RC rc = new_index_meta.init(index_name, field_metas, is_unique);
  if (rc != RC::SUCCESS) {
    LOG_INFO("Failed to init IndexMeta in table:%s, index_name:%s", 
             name(), index_name);
    return rc;
  }

  // 创建索引相关数据
  BplusTreeIndex *index = new BplusTreeIndex();
  std::string index_file = table_index_file(base_dir_.c_str(), name(), index_name);

  std::vector<FieldMeta> field_metas_copy;
  for (int i = 0; i < field_metas.size(); i++) {
    field_metas_copy.emplace_back(*field_metas[i]);
  }

  rc = index->create(index_file.c_str(), new_index_meta, field_metas_copy);
  if (rc != RC::SUCCESS) {
    delete index;
    LOG_ERROR("Failed to create bplus tree index. file name=%s, rc=%d:%s", index_file.c_str(), rc, strrc(rc));
    return rc;
  }

  // 遍历当前的所有数据，插入这个索引
  RecordFileScanner scanner;
  rc = get_record_scanner(scanner, trx, true/*readonly*/);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create scanner while creating index. table=%s, index=%s, rc=%s", 
             name(), index_name, strrc(rc));
    return rc;
  }

  Record record;
  while (scanner.has_next()) {
    rc = scanner.next(record);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to scan records while creating index. table=%s, index=%s, rc=%s",
               name(), index_name, strrc(rc));
      return rc;
    }
    rc = index->insert_entry(record.data(), &record.rid());
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to insert record into index while creating index. table=%s, index=%s, rc=%s",
               name(), index_name, strrc(rc));
      return rc;         
    }
  }
  scanner.close_scan();
  LOG_INFO("inserted all records into new index. table=%s, index=%s", name(), index_name);
  
  indexes_.push_back(index);

  /// 接下来将这个索引放到表的元数据中
  TableMeta new_table_meta(table_meta_);
  rc = new_table_meta.add_index(new_index_meta);
  if (rc != RC::SUCCESS) {
    LOG_ERROR("Failed to add index (%s) on table (%s). error=%d:%s", index_name, name(), rc, strrc(rc));
    return rc;
  }

  /// 内存中有一份元数据，磁盘文件也有一份元数据。修改磁盘文件时，先创建一个临时文件，写入完成后再rename为正式文件
  /// 这样可以防止文件内容不完整
  // 创建元数据临时文件
  std::string tmp_file = table_meta_file(base_dir_.c_str(), name()) + ".tmp";
  std::fstream fs;
  fs.open(tmp_file, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
  if (!fs.is_open()) {
    LOG_ERROR("Failed to open file for write. file name=%s, errmsg=%s", tmp_file.c_str(), strerror(errno));
    return RC::IOERR_OPEN;  // 创建索引中途出错，要做还原操作
  }
  if (new_table_meta.serialize(fs) < 0) {
    LOG_ERROR("Failed to dump new table meta to file: %s. sys err=%d:%s", tmp_file.c_str(), errno, strerror(errno));
    return RC::IOERR_WRITE;
  }
  fs.close();

  // 覆盖原始元数据文件
  std::string meta_file = table_meta_file(base_dir_.c_str(), name());
  int ret = rename(tmp_file.c_str(), meta_file.c_str());
  if (ret != 0) {
    LOG_ERROR("Failed to rename tmp meta file (%s) to normal meta file (%s) while creating index (%s) on table (%s). "
              "system error=%d:%s",
              tmp_file.c_str(), meta_file.c_str(), index_name, name(), errno, strerror(errno));
    return RC::IOERR_WRITE;
  }

  table_meta_.swap(new_table_meta);

  LOG_INFO("Successfully added a new index (%s) on the table (%s)", index_name, name());
  return rc;
}

RC Table::delete_record(const Record &record)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->delete_entry(record.data(), &record.rid());
    ASSERT(RC::SUCCESS == rc, 
           "failed to delete entry from index. table name=%s, index name=%s, rid=%s, rc=%s",
           name(), index->index_meta().name(), record.rid().to_string().c_str(), strrc(rc));
  }
  rc = record_handler_->delete_record(&record.rid());
  return rc;
}

RC Table::insert_entry_of_indexes(const char *record, const RID &rid)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->insert_entry(record, &rid);
    if (rc != RC::SUCCESS) {
      break;
    }
  }
  return rc;
}

RC Table::delete_entry_of_indexes(const char *record, const RID &rid, bool error_on_not_exists)
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->delete_entry(record, &rid);
    if (rc != RC::SUCCESS) {
      if (rc != RC::RECORD_INVALID_KEY || !error_on_not_exists) {
        break;
      }
    }
  }
  return rc;
}

Index *Table::find_index(const char *index_name) const
{
  for (Index *index : indexes_) {
    if (0 == strcmp(index->index_meta().name(), index_name)) {
      return index;
    }
  }
  return nullptr;
}
Index *Table::find_index_by_field(std::vector<std::string> field_name) const
{
  const TableMeta &table_meta = this->table_meta();
  const IndexMeta *index_meta = table_meta.find_index_by_field(field_name);
  if (index_meta != nullptr) {
    return this->find_index(index_meta->name());
  }
  return nullptr;
}

RC Table::sync()
{
  RC rc = RC::SUCCESS;
  for (Index *index : indexes_) {
    rc = index->sync();
    if (rc != RC::SUCCESS) {
      LOG_ERROR("Failed to flush index's pages. table=%s, index=%s, rc=%d:%s",
          name(),
          index->index_meta().name(),
          rc,
          strrc(rc));
      return rc;
    }
  }
  LOG_INFO("Sync table over. table=%s", name());
  return rc;
}

RC Table::get_text_record(TextDataMeta *meta, std::string &text_data) const
{
  return record_handler_->get_text(meta, text_data);
}

RC Table::resolve_unique_before_insert(Trx *trx, Record *record)
{
  for (size_t i = 0; i < indexes_.size(); i++) {
    // is unique
    if (indexes_[i]->index_meta().is_unique()) {
      if (indexes_[i]->has_null(record->data())) {
        continue;
      }
      std::list<RID> rids;
      RC rc = indexes_[i]->get_entry(record->data(), rids);
      if (rc != RC::SUCCESS && rc != RC::EMPTY) {
        return rc;
      }
      if (rids.size() > 0) {
        LOG_INFO("insert duplicate keys into unique index");
        return RC::INVALID_ARGUMENT;
      }
    }
  }
  return RC::SUCCESS;
}

RC Table::resolve_unique_before_update(Trx *trx, Record *old_record, Record *new_record)
{
  LOG_INFO("resolve_unique_before_update");
  for (size_t i = 0; i < indexes_.size(); i++) {
    // is unique
    if (indexes_[i]->index_meta().is_unique()) {
      if (indexes_[i]->has_null(new_record->data())) {
        continue;
      }
      std::vector<FieldMeta> field_metas = indexes_[i]->field_metas();
      bool equal = true;
      for (size_t j = 0; j < field_metas.size() && equal; j++) {
        switch (field_metas[j].type()) {
          case INTS: {
            equal = common::compare_int(old_record->data() + field_metas[j].offset(), 
                          new_record->data() + field_metas[j].offset()) == 0;
          } break;
          case FLOATS: {
            equal = common::compare_float(old_record->data() + field_metas[j].offset(), 
                          new_record->data() + field_metas[j].offset()) == 0;
          } break;
          case TEXTS:
          case CHARS: {
            equal = common::compare_string(old_record->data() + field_metas[j].offset(), field_metas[j].len(),
                          new_record->data() + field_metas[j].offset(),field_metas[j].len()) == 0;
          } break;
          case DATES: {
            Value::DateMeta left, right;
            left.set_date(old_record->data() + field_metas[j].offset());
            right.set_date(new_record->data() + field_metas[j].offset());
            equal = left.compare(right) == 0;
          } break;
          default:
           break;
        }
      }
      if (equal) {
        continue;
      }
      LOG_INFO("resolve_unique_before_update ask in b+tree");
      std::list<RID> rids;
      RC rc = indexes_[i]->get_entry(new_record->data(), rids);
      if (rc != RC::SUCCESS && rc != RC::EMPTY) {
        return rc;
      }
      if (rids.size() > 0) {
        LOG_INFO("insert duplicate keys into unique index");
        return RC::INVALID_ARGUMENT;
      }
    }
  }
  return RC::SUCCESS;
}