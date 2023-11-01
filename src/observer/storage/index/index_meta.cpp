/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai.wyl on 2021/5/18.
//

#include "storage/index/index_meta.h"
#include "storage/field/field_meta.h"
#include "storage/table/table_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "json/json.h"

const static Json::StaticString FIELD_NAME("name");
const static Json::StaticString FIELD_FIELD_NAME("field_name");
const static Json::StaticString FIELD_UNIQUE("unique");

RC IndexMeta::init(const char *name, std::vector<const FieldMeta *> &fields, bool is_unique)
{
  if (common::is_blank(name)) {
    LOG_ERROR("Failed to init index, name is empty.");
    return RC::INVALID_ARGUMENT;
  }

  name_ = name;
  for (size_t i = 0; i < fields.size(); i++) {
    fields_.push_back(fields[i]->name());
  }
  is_unique_ = is_unique;
  return RC::SUCCESS;
}

void IndexMeta::to_json(Json::Value &json_value) const
{
  json_value[FIELD_NAME] = name_;
  std::string fields_string;
  for (size_t i = 0; i < fields_.size(); i++) {
    fields_string += fields_[i];
    if (i != fields_.size() - 1) {
      // spliter
      fields_string += '@';
    }
  }
  json_value[FIELD_FIELD_NAME] = fields_string;
  json_value[FIELD_UNIQUE] = is_unique_;
}

RC IndexMeta::from_json(const TableMeta &table, const Json::Value &json_value, IndexMeta &index)
{
  const Json::Value &name_value = json_value[FIELD_NAME];
  const Json::Value &field_value = json_value[FIELD_FIELD_NAME];
  const Json::Value &is_unique_value = json_value[FIELD_UNIQUE];
  if (!name_value.isString()) {
    LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
    return RC::INTERNAL;
  }

  if (!field_value.isString()) {
    LOG_ERROR("Field name of index [%s] is not a string. json value=%s",
        name_value.asCString(),
        field_value.toStyledString().c_str());
    return RC::INTERNAL;
  }

  std::string fields_string = field_value.asCString();

  int start = 0, end = 0;
  std::vector<const FieldMeta *> fields;
  bool stop = false;
  while (!stop) {
    end = fields_string.find('@', start);
    if (end < 0) {
      stop = true;
      end = fields_string.size();
    }
    const FieldMeta *field = table.field(fields_string.substr(start, end - start).c_str());
    if (nullptr == field) {
      LOG_ERROR("Deserialize index [%s]: no such field: %s", name_value.asCString(), field_value.asCString());
      return RC::SCHEMA_FIELD_MISSING;
    }

    fields.push_back(field);
    start = end + 1;
  }

  return index.init(name_value.asCString(), fields, is_unique_value.asBool());
}

const char *IndexMeta::name() const
{
  return name_.c_str();
}

std::vector<std::string> IndexMeta::fields() const
{
  return fields_;
}

const bool IndexMeta::is_unique() const
{
  return is_unique_;
}

void IndexMeta::desc(std::ostream &os) const
{
  os << "index name=" << name_ << ", field=";
  for (size_t i = 0; i < fields_.size(); i++) {
    os << fields_[i];
    if (i != fields_.size() - 1) {
      os << ' ';
    }
  }
  os << ", unique=" << is_unique_;
}