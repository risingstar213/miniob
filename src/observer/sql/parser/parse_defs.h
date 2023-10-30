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
// Created by Meiyi
//

#pragma once

#include <stddef.h>
#include <memory>
#include <vector>
#include <deque>
#include <string>

#include "sql/parser/value.h"

class Expression;
class Table;
class FieldMeta;
struct SelectSqlNode;

/**
 * @defgroup SQLParser SQL Parser 
 */

/**
 * @brief 描述一个属性
 * @ingroup SQLParser
 * @details 属性，或者说字段(column, field)
 * Rel -> Relation
 * Attr -> Attribute
 */
struct RelAttrSqlNode
{
  std::string relation_name;   ///< relation name (may be NULL) 表名
  std::string attribute_name;  ///< attribute name              属性名
};

// 表名结构体
struct RelSqlNode
{
  std::string relation;
  // drop alias temporarily
  // std::string alias;
};

// The same with Arithmetic Expr
enum ExprNodeType {
  E_ADD,
  E_SUB,
  E_MUL,
  E_DIV,
  E_NEGATIVE,
  E_AGG,
  E_FUNCTION,
  E_VAL,
  E_DYN,
};

enum AggregationType {
  A_UNDEFINED,
  A_MAX,
  A_MIN,
  A_COUNT,
  A_AVG,
  A_SUM
};

enum FunctionType {
  F_UNDEFINED,
  F_LENGTH,
  F_ROUND,
  F_FORMAT,
};

struct DynNodeSqlNode {
  AggregationType aggType = AggregationType::A_UNDEFINED;
  // FunctionType    funcType = FunctionType::UNDEFINED;
  RelAttrSqlNode  node;
  // drop alias temporarily
  // std::string alias;
};

// Expression Node Definition
struct ExprSqlNode {
  ExprNodeType type;
  std::unique_ptr<ExprSqlNode> left = nullptr;
  std::unique_ptr<ExprSqlNode> right = nullptr;

  std::unique_ptr<Value>       value = nullptr;
  std::unique_ptr<DynNodeSqlNode> attr  = nullptr;

  bool has_brace;

  // other infomation
  AttrType attrType = UNDEFINED;
  // Field *field = nullptr;
  const Table *table_ = nullptr;
  const FieldMeta *field_ = nullptr;
  int aggregation_num = 0;
  int attr_num = 0;

  void release();
};

/**
 * @brief 描述比较运算符
 * @ingroup SQLParser
 */
enum CompOp 
{
  EQUAL_TO,     ///< "="
  LESS_EQUAL,   ///< "<="
  NOT_EQUAL,    ///< "<>"
  LESS_THAN,    ///< "<"
  GREAT_EQUAL,  ///< ">="
  GREAT_THAN,   ///< ">"
  LIKE_SCH,     // LIKE   6
  UNLIKE_SCH,   // UNLIKE 7
  IS_NULL,      // IS     8
  IS_NOT_NULL,  // IS NOT 9
  IN_SQ,        // in     10
  NOT_IN_SQ,    // not in 11
  EXISTS_SQ,    // exsits 12
  NOT_EXISTS_SQ,// not exists 13
  NO_OP
};

/**
 * @brief 表示一个条件比较
 * @ingroup SQLParser
 * @details 条件比较就是SQL查询中的 where a>b 这种。
 * 一个条件比较是有两部分组成的，称为左边和右边。
 * 左边和右边理论上都可以是任意的数据，比如是字段（属性，列），也可以是数值常量。
 * 这个结构中记录的仅仅支持字段和值。
 */
// struct ConditionSqlNode
// {
//   int             left_is_attr;    ///< TRUE if left-hand side is an attribute
//                                    ///< 1时，操作符左边是属性名，0时，是属性值
//   Value           left_value;      ///< left-hand side value if left_is_attr = FALSE
//   RelAttrSqlNode  left_attr;       ///< left-hand side attribute
//   CompOp          comp;            ///< comparison operator
//   int             right_is_attr;   ///< TRUE if right-hand side is an attribute
//                                    ///< 1时，操作符右边是属性名，0时，是属性值
//   RelAttrSqlNode  right_attr;      ///< right-hand side attribute if right_is_attr = TRUE 右边的属性
//   Value           right_value;     ///< right-hand side value if right_is_attr = FALSE
// };

struct ConditionSqlNode
{
  bool                           left_is_subquery;
  std::unique_ptr<ExprSqlNode>   left_expr = nullptr;
  std::unique_ptr<SelectSqlNode> left_subquery = nullptr;
  CompOp op;
  bool                           right_is_subquery;
  std::unique_ptr<ExprSqlNode>   right_expr = nullptr;
  std::unique_ptr<SelectSqlNode> right_subquery = nullptr;

  bool                           right_is_list = false;
  std::deque<Value>              value_list;

  void release();
};

/**
 * @brief 描述一个select语句
 * @ingroup SQLParser
 * @details 一个正常的select语句描述起来比这个要复杂很多，这里做了简化。
 * 一个select语句由三部分组成，分别是select, from, where。
 * select部分表示要查询的字段，from部分表示要查询的表，where部分表示查询的条件。
 * 比如 from 中可以是多个表，也可以是另一个查询语句，这里仅仅支持表，也就是 relations。
 * where 条件 conditions，这里表示使用AND串联起来多个条件。正常的SQL语句会有OR，NOT等，
 * 甚至可以包含复杂的表达式。
 */

// struct SelectSqlNode
// {
//   std::deque<RelAttrSqlNode>     attributes;    ///< attributes in select clause
//   std::deque<std::string>        relations;     ///< 查询的表
//   std::deque<ConditionSqlNode>   conditions;    ///< 查询条件，使用AND串联起来多个条件
// };

struct JoinSqlNode
{
  std::string                  relation;
  std::deque<ConditionSqlNode> on_coditions;

  void release();
};

struct GroupBySqlNode
{
  std::deque<RelAttrSqlNode>   by_attrs;
  std::deque<ConditionSqlNode> having_conditions;

  void release();
};

struct OrderBySqlNode
{
  std::unique_ptr<RelAttrSqlNode> by_attr = nullptr;
  bool                       is_asc;

  void release();
};

struct SelectSqlNode
{
  std::deque<ExprSqlNode>        select_exprs;
  std::deque<RelSqlNode>         relations;
  bool                           condtion_is_or;
  std::deque<JoinSqlNode>        joins;
  std::deque<ConditionSqlNode>   conditions;
  GroupBySqlNode                 group_by;
  std::deque<OrderBySqlNode>     order_bys;

  void release();
};

/**
 * @brief 算术表达式计算的语法树
 * @ingroup SQLParser
 */
struct CalcSqlNode
{
  // std::deque<Expression *> expressions;  ///< calc clause
  std::deque<ExprSqlNode>        expressions;

  void release();
  ~CalcSqlNode();
};

/**
 * @brief 描述一个insert语句
 * @ingroup SQLParser
 * @details 于Selects类似，也做了很多简化
 */

struct InsertRowNode
{
  std::deque<Value> values;
};

// struct InsertSqlNode
// {
//   std::string        relation_name;  ///< Relation to insert into
//   std::deque<Value> values;         ///< 要插入的值
// };

struct InsertSqlNode
{
  std::string                relation_name;
  std::deque<InsertRowNode>  rows;
};

/**
 * @brief 描述一个delete语句
 * @ingroup SQLParser
 */
struct DeleteSqlNode
{
  std::string                   relation_name;  ///< Relation to delete from
  std::deque<ConditionSqlNode>  conditions;

  void release();
};

/**
 * @brief 描述一个update语句
 * @ingroup SQLParser
 */

struct UpdatePairSqlNode
{
  RelAttrSqlNode attr;
  bool          is_select;
  SelectSqlNode select_value;
  Value         value;

  void release();
};

// struct UpdateSqlNode
// {
//   std::string                   relation_name;         ///< Relation to update
//   std::string                   attribute_name;        ///< 更新的字段，仅支持一个字段
//   Value                         value;                 ///< 更新的值，仅支持一个字段
//   std::deque<ConditionSqlNode> conditions;
// };


struct UpdateSqlNode
{
  std::string                    relation_name;
  std::deque<UpdatePairSqlNode>  attr_values;
  std::deque<ConditionSqlNode>   conditions;

  void release();
};

/**
 * @brief 描述一个属性
 * @ingroup SQLParser
 * @details 属性，或者说字段(column, field)
 * Rel -> Relation
 * Attr -> Attribute
 */
struct AttrInfoSqlNode
{
  AttrType    type;       ///< Type of attribute
  std::string name;       ///< Attribute name
  size_t      length;     ///< Length of attribute
};

/**
 * @brief 描述一个create table语句
 * @ingroup SQLParser
 * @details 这里也做了很多简化。
 */
struct CreateTableSqlNode
{
  std::string                  relation_name;         ///< Relation name
  std::deque<AttrInfoSqlNode> attr_infos;            ///< attributes
};

/**
 * @brief 描述一个drop table语句
 * @ingroup SQLParser
 */
struct DropTableSqlNode
{
  std::string relation_name;  ///< 要删除的表名
};

/**
 * @brief 描述一个create index语句
 * @ingroup SQLParser
 * @details 创建索引时，需要指定索引名，表名，字段名。
 * 正常的SQL语句中，一个索引可能包含了多个字段，这里仅支持一个字段。
 */
struct CreateIndexSqlNode
{
  std::string index_name;      ///< Index name
  std::string relation_name;   ///< Relation name
  std::string attribute_name;  ///< Attribute name
};

/**
 * @brief 描述一个drop index语句
 * @ingroup SQLParser
 */
struct DropIndexSqlNode
{
  std::string index_name;     ///< Index name
  std::string relation_name;  ///< Relation name
};

/**
 * @brief 描述一个desc table语句
 * @ingroup SQLParser
 * @details desc table 是查询表结构信息的语句
 */
struct DescTableSqlNode
{
  std::string relation_name;
};

/**
 * @brief 描述一个load data语句
 * @ingroup SQLParser
 * @details 从文件导入数据到表中。文件中的每一行就是一条数据，每行的数据类型、字段个数都与表保持一致
 */
struct LoadDataSqlNode
{
  std::string relation_name;
  std::string file_name;
};

/**
 * @brief 设置变量的值
 * @ingroup SQLParser
 * @note 当前还没有查询变量
 */
struct SetVariableSqlNode
{
  std::string name;
  Value       value;
};

class ParsedSqlNode;

/**
 * @brief 描述一个explain语句
 * @ingroup SQLParser
 * @details 会创建operator的语句，才能用explain输出执行计划。
 * 一个command就是一个语句，比如select语句，insert语句等。
 * 可能改成SqlCommand更合适。
 */
struct ExplainSqlNode
{
  std::unique_ptr<ParsedSqlNode> sql_node;
};

/**
 * @brief 解析SQL语句出现了错误
 * @ingroup SQLParser
 * @details 当前解析时并没有处理错误的行号和列号
 */
struct ErrorSqlNode
{
  std::string error_msg;
  int         line;
  int         column;
};

/**
 * @brief 表示一个SQL语句的类型
 * @ingroup SQLParser
 */
enum SqlCommandFlag
{
  SCF_ERROR = 0,
  SCF_CALC,
  SCF_SELECT,
  SCF_INSERT,
  SCF_UPDATE,
  SCF_DELETE,
  SCF_CREATE_TABLE,
  SCF_DROP_TABLE,
  SCF_CREATE_INDEX,
  SCF_DROP_INDEX,
  SCF_SYNC,
  SCF_SHOW_TABLES,
  SCF_DESC_TABLE,
  SCF_BEGIN,        ///< 事务开始语句，可以在这里扩展只读事务
  SCF_COMMIT,
  SCF_CLOG_SYNC,
  SCF_ROLLBACK,
  SCF_LOAD_DATA,
  SCF_HELP,
  SCF_EXIT,
  SCF_EXPLAIN,
  SCF_SET_VARIABLE, ///< 设置变量
};
/**
 * @brief 表示一个SQL语句
 * @ingroup SQLParser
 */
class ParsedSqlNode
{
public:
  enum SqlCommandFlag       flag;
  ErrorSqlNode              error;
  CalcSqlNode               calc;
  SelectSqlNode             selection;
  InsertSqlNode             insertion;
  DeleteSqlNode             deletion;
  UpdateSqlNode             update;
  CreateTableSqlNode        create_table;
  DropTableSqlNode          drop_table;
  CreateIndexSqlNode        create_index;
  DropIndexSqlNode          drop_index;
  DescTableSqlNode          desc_table;
  LoadDataSqlNode           load_data;
  ExplainSqlNode            explain;
  SetVariableSqlNode        set_variable;

public:
  ParsedSqlNode();
  ~ParsedSqlNode();
  void release();
  explicit ParsedSqlNode(SqlCommandFlag flag);
};

/**
 * @brief 表示语法解析后的数据
 * @ingroup SQLParser
 */
class ParsedSqlResult
{
public:
  void add_sql_node(std::unique_ptr<ParsedSqlNode> sql_node);
  std::vector<std::unique_ptr<ParsedSqlNode>> &sql_nodes()
  {
    return sql_nodes_;
  }

private:
  std::vector<std::unique_ptr<ParsedSqlNode>> sql_nodes_;  ///< 这里记录SQL命令。虽然看起来支持多个，但是当前仅处理一个
};
