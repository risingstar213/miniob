
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

%}

%define api.pure full
%define parse.error verbose
/** 启用位置标识 **/
%locations
%lex-param { yyscan_t scanner }
/** 这些定义了在yyparse函数中的参数 **/
%parse-param { const char * sql_string }
%parse-param { ParsedSqlResult * sql_result }
%parse-param { void * scanner }

//标识tokens
%token  SEMICOLON
        CREATE
        DROP
        TABLE
        TABLES
        INDEX
        CALC
        SELECT
        DESC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        STRING_T
        FLOAT_T
        DATE_T
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        WHERE
        AND
        OR
        SET
        ON
        LOAD
        DATA
        INFILE
        EXPLAIN
        EQ
        LT
        GT
        LE
        GE
        NE
        NOT
        LIKE
        INNER
        JOIN
        UNIQUE
        MAX
        MIN
        SUM
        COUNT
        AVG
        LENGTH
        ROUND
        DATE_FORMAT
        /* ADD_OP
		    SUB_OP
		    DIV_OP */
		    IN
		    EXISTS
		    GROUP
		    HAVING
		    AS
        ORDER
		    BY 
		    ASC
        IS
        NULL_LITERAL
        NULLABLE


/** union 中定义各种数据类型，真实生成的代码也是union类型，所以不能有非POD类型的数据 **/
%union {
  ParsedSqlNode *                   sql_node;
  Value *                           value;
  std::deque<Value> *               value_list;
  enum CompOp                       comp;
  RelAttrSqlNode *                  rel_attr;
  std::deque<RelAttrSqlNode> *      rel_attr_list;
  RelSqlNode *                      relation;
  std::deque<RelSqlNode> *          relation_list;
  AttrInfoSqlNode *                 attr_info;
  std::deque<AttrInfoSqlNode> *     attr_infos;
  DynNodeSqlNode *                  dyn_node;
  ExprSqlNode *                     expression;
  std::deque<ExprSqlNode> *         expression_list;
  ConditionSqlNode *                condition;
  std::deque<ConditionSqlNode> *    condition_list;
  JoinSqlNode *                     join;
  std::deque<JoinSqlNode> *         join_list;
  GroupBySqlNode *                  groupby;
  OrderBySqlNode *                  orderby;
  std::deque<OrderBySqlNode> *      orderby_list;
  InsertRowNode *                   insert_row;
  std::deque<InsertRowNode> *       insert_row_list;
  UpdatePairSqlNode *               update_pair;
  std::deque<UpdatePairSqlNode> *   update_pair_list;
  std::deque<std::string> *         id_list;
  SelectSqlNode *                   select;
  char *                            string;
  int                               number;
  float                             floats;
  bool                              bools;
}

%token <number> NUMBER
%token <floats> FLOAT
%token <string> DATE
%token <string> ID
%token <string> SSS
//非终结符

/** type 定义了各种解析后的结果输出的是什么类型。类型对应了 union 中的定义的成员变量名称 **/
%type <number>              type
%type <condition>           condition
%type <value>               value
%type <value>               value_list_cell
%type <number>              is_nullable
%type <number>              number
%type <comp>                comp_op
%type <relation>            relation
%type <rel_attr>            rel_attr
%type <attr_infos>          attr_def_list
%type <attr_info>           attr_def
%type <value_list>          value_list
%type <condition_list>      where
%type <condition_list>      condition_list
%type <condition_list>      or_where
%type <condition_list>      or_condition_list
%type <expression_list>     select_attr
%type <relation_list>       rel_list
%type <rel_attr_list>       attr_list
%type <expression>          expression
%type <expression_list>     expression_list
%type <dyn_node>            dyn_node
%type <join_list>           join_list
%type <condition_list>      join_conditions
%type <condition_list>      having
%type <groupby>             groupby
%type <orderby>             orderby_col
%type <orderby_list>        orderby_list
%type <orderby_list>        orderby
%type <insert_row_list>     insert_row_list
%type <update_pair>         update_pair
%type <update_pair_list>    update_list
%type <id_list>             id_list
%type <bools>               is_unique
%type <select>              select
%type <sql_node>            calc_stmt
%type <sql_node>            select_stmt
%type <sql_node>            insert_stmt
%type <sql_node>            update_stmt
%type <sql_node>            delete_stmt
%type <sql_node>            create_table_stmt
%type <sql_node>            drop_table_stmt
%type <sql_node>            show_tables_stmt
%type <sql_node>            show_index_stmt
%type <sql_node>            desc_table_stmt
%type <sql_node>            create_index_stmt
%type <sql_node>            drop_index_stmt
%type <sql_node>            sync_stmt
%type <sql_node>            begin_stmt
%type <sql_node>            commit_stmt
%type <sql_node>            rollback_stmt
%type <sql_node>            load_data_stmt
%type <sql_node>            explain_stmt
%type <sql_node>            set_variable_stmt
%type <sql_node>            help_stmt
%type <sql_node>            exit_stmt
%type <sql_node>            command_wrapper
// commands should be a list but I use a single command instead
%type <sql_node>            commands

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%%

commands: command_wrapper opt_semicolon  //commands or sqls. parser starts here.
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>($1);
    sql_result->add_sql_node(std::move(sql_node));
  }
  ;

command_wrapper:
    calc_stmt
  | select_stmt
  | insert_stmt
  | update_stmt
  | delete_stmt
  | create_table_stmt
  | drop_table_stmt
  | show_tables_stmt
  | desc_table_stmt
  | show_index_stmt
  | create_index_stmt
  | drop_index_stmt
  | sync_stmt
  | begin_stmt
  | commit_stmt
  | rollback_stmt
  | load_data_stmt
  | explain_stmt
  | set_variable_stmt
  | help_stmt
  | exit_stmt
    ;

exit_stmt:      
    EXIT {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      $$ = new ParsedSqlNode(SCF_EXIT);
    };

help_stmt:
    HELP {
      $$ = new ParsedSqlNode(SCF_HELP);
    };

sync_stmt:
    SYNC {
      $$ = new ParsedSqlNode(SCF_SYNC);
    }
    ;

begin_stmt:
    TRX_BEGIN  {
      $$ = new ParsedSqlNode(SCF_BEGIN);
    }
    ;

commit_stmt:
    TRX_COMMIT {
      $$ = new ParsedSqlNode(SCF_COMMIT);
    }
    ;

rollback_stmt:
    TRX_ROLLBACK  {
      $$ = new ParsedSqlNode(SCF_ROLLBACK);
    }
    ;

drop_table_stmt:    /*drop table 语句的语法解析树*/
    DROP TABLE ID {
      $$ = new ParsedSqlNode(SCF_DROP_TABLE);
      $$->drop_table.relation_name = $3;
      free($3);
    };

show_tables_stmt:
    SHOW TABLES {
      $$ = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
    ;

show_index_stmt:
  SHOW INDEX FROM ID
		{
			$$ = new ParsedSqlNode(SCF_SHOW_INDEX);
			$$->show_index.relation_name = $4;
      free($4);
		}
  ;

desc_table_stmt:
    DESC ID  {
      $$ = new ParsedSqlNode(SCF_DESC_TABLE);
      $$->desc_table.relation_name = $2;
      free($2);
    }
    ;

is_unique:
  /* empty */ {
    $$ = false;
  }
  | UNIQUE {
    $$ = true;
  }
  ;

id_list:
  ID {
    $$ = new std::deque<std::string>();
    std::string attribute_name = $1;
    free($1);
    $$->emplace_back(attribute_name);
  }
  | ID COMMA id_list {
    $$ = $3;
    std::string attribute_name = $1;
    free($1);
    $$->emplace_front(attribute_name);
  }
  ;
create_index_stmt:    /*create index 语句的语法解析树*/
    CREATE is_unique INDEX ID ON ID LBRACE id_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.index_name = $4;
      create_index.relation_name = $6;
      create_index.attribute_names = std::move(*$8);
      create_index.is_unique = $2;
      free($4);
      free($6);
      delete $8;
    }
    ;

drop_index_stmt:      /*drop index 语句的语法解析树*/
    DROP INDEX ID ON ID
    {
      $$ = new ParsedSqlNode(SCF_DROP_INDEX);
      $$->drop_index.index_name = $3;
      $$->drop_index.relation_name = $5;
      free($3);
      free($5);
    }
    ;
create_table_stmt:    /*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = $$->create_table;
      create_table.relation_name = $3;
      free($3);

      std::deque<AttrInfoSqlNode> *src_attrs = $6;

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_front(std::move(*$5));
      // std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete $5;
      delete $6;
    }
    ;
attr_def_list:
    /* empty */
    {
      $$ = new std::deque<AttrInfoSqlNode>;
    }
    | COMMA attr_def attr_def_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::deque<AttrInfoSqlNode>;
      }
      $$->emplace_front(std::move(*$2));
      delete $2;
    }
    ;
is_nullable:
  /* empty */ {
    $$ = -1;
  }
  | NOT NULL_LITERAL {
    $$ = 0;
  }
  | NULLABLE {
    $$ = 1;
  }
  | NULL_LITERAL {
    $$ = 1;
  }
  ;

attr_def:
    ID type LBRACE number RBRACE is_nullable
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = $4;
      $$->unsolved = $6;
      free($1);
    }
    | ID type is_nullable
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      if ((AttrType)$2 == AttrType::DATES) {
        $$->length = 12;
      } else {
        $$->length = 4;
      }
      $$->unsolved = $3;
      free($1);
    }
    ;
number:
    NUMBER {$$ = $1;}
    ;
type:
    INT_T      { $$=INTS; }
    | STRING_T { $$=CHARS; }
    | FLOAT_T  { $$=FLOATS; }
    | DATE_T   { $$=DATES; }
    ;
insert_stmt:        /*insert   语句的语法解析树*/
    INSERT INTO ID VALUES insert_row_list 
    {
      $$ = new ParsedSqlNode(SCF_INSERT);
      $$->insertion.relation_name = $3;
      if ($5 != nullptr) {
        $$->insertion.rows.swap(*$5);
        delete $5;
      }
      // $$->insertion.values.emplace_front(std::move(*$6);
      // std::reverse($$->insertion.values.begin(), $$->insertion.values.end());
      free($3);
    }
    ;

value_list_cell:
  value {
    $$ = $1;
  }
  | '-' NUMBER {
    $$ = new Value(-(int)$2);
    // @$ = @1;
  }
  | '-' FLOAT {
    $$ = new Value(-(float)$2);
    // @$ = @1;
  }
  ;
value_list:
    value_list_cell
    {
      $$ = new std::deque<Value>;
      $$->emplace_back(std::move(*$1));
      delete $1;
    }
    | value_list COMMA value_list_cell  { 
      if ($1 != nullptr) {
        $$ = $1;
      } else {
        $$ = new std::deque<Value>;
      }
      $$->emplace_back(std::move(*$3));
      delete $3;
    }
    ;
value:
    NUMBER {
      $$ = new Value((int)$1);
      @$ = @1;
    }
    |FLOAT {
      $$ = new Value((float)$1);
      @$ = @1;
    }
    |DATE {
      char *tmp = common::substr($1,1,strlen($1)-2);
      $$ = new Value(tmp, true, true);
      free(tmp);
    }
    |SSS {
      char *tmp = common::substr($1,1,strlen($1)-2);
      $$ = new Value(tmp);
      free(tmp);
    }
    |NULL_LITERAL {
      $$ = new Value(0);
      $$->set_null(true);
    }
    ;
    
delete_stmt:    /*  delete 语句的语法解析树*/
    DELETE FROM ID where 
    {
      $$ = new ParsedSqlNode(SCF_DELETE);
      $$->deletion.relation_name = $3;
      if ($4 != nullptr) {
        $$->deletion.conditions.swap(*$4);
        delete $4;
      }
      free($3);
    }
    ;
update_stmt:      /*  update 语句的语法解析树*/
    UPDATE ID update_list where 
    {
      $$ = new ParsedSqlNode(SCF_UPDATE);
      $$->update.relation_name = $2;
      if ($3 != nullptr) {
        $$->update.attr_values.swap(*$3);
        delete $3;
      }
      if ($4 != nullptr) {
        $$->update.conditions.swap(*$4);
        delete $4;
      }
      free($2);
    }
    ;

select_stmt:        /*  select 语句的语法解析树*/
    select {
      $$ = new ParsedSqlNode(SCF_SELECT);
      $$->selection = std::move(*$1);
      delete $1;
    }
    ;
select:
    SELECT select_attr FROM relation rel_list join_list where groupby orderby
    {
      $$ = new SelectSqlNode;
      $$->condtion_is_or = false;
      if ($2 != nullptr) {
        $$->select_exprs.swap(*$2);
        delete $2;
      }
      if ($5 != nullptr) {
        $$->relations.swap(*$5);
        delete $5;
      }
      $$->relations.push_front(std::move(*$4));
      // std::reverse($$->selection.relations.begin(), $$->selection.relations.end());
      delete $4;
      if ($6 != nullptr) {
        $$->joins.swap(*$6);
        delete $6;
      }

      if ($7 != nullptr) {
        $$->conditions.swap(*$7);
        delete $7;
      }

      if ($8 != nullptr) {
        $$->group_by = std::move(*$8);
        delete $8;
      }

      if ($9 != nullptr) {
        $$->order_bys.swap(*$9);
        delete $9;
      }

    }
    | SELECT select_attr FROM relation rel_list join_list or_where groupby orderby {
      $$ = new SelectSqlNode;
      $$->condtion_is_or = true;
      if ($2 != nullptr) {
        $$->select_exprs.swap(*$2);
        delete $2;
      }
      if ($5 != nullptr) {
        $$->relations.swap(*$5);
        delete $5;
      }
      $$->relations.push_front(std::move(*$4));
      delete $4;
      // std::reverse($$->selection.relations.begin(), $$->selection.relations.end());

      if ($6 != nullptr) {
        $$->joins.swap(*$6);
        delete $6;
      }

      if ($7 != nullptr) {
        $$->conditions.swap(*$7);
        delete $7;
      }

      if ($8 != nullptr) {
        $$->group_by = std::move(*$8);
        delete $8;
      }

      if ($9 != nullptr) {
        $$->order_bys.swap(*$9);
        delete $9;
      }
    }
    ;
calc_stmt:
    CALC expression_list
    {
      $$ = new ParsedSqlNode(SCF_CALC);
      // std::reverse($2->begin(), $2->end());
      $$->calc.expressions.swap(*$2);
      delete $2;
    }
    ;

// not empty
expression_list:
    expression
    {
      $$ = new std::deque<ExprSqlNode>;
      $$->emplace_back(std::move(*$1));
      delete $1;
    }
    | expression COMMA expression_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::deque<ExprSqlNode>;
      }
      $$->emplace_front(std::move(*$1));
      delete $1;
    }
    ;
expression:
    expression '+' expression {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
      $$ = new ExprSqlNode();
      $$->type = ExprNodeType::E_ADD;
      $$->left = std::unique_ptr<ExprSqlNode>($1);
      $$->right = std::unique_ptr<ExprSqlNode>($3);
    }
    | expression '-' expression {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
      $$ = new ExprSqlNode();
      $$->type = ExprNodeType::E_SUB;
      $$->left = std::unique_ptr<ExprSqlNode>($1);
      $$->right = std::unique_ptr<ExprSqlNode>($3);
    }
    | expression '*' expression {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
      $$ = new ExprSqlNode();
      $$->type = ExprNodeType::E_MUL;
      $$->left = std::unique_ptr<ExprSqlNode>($1);
      $$->right = std::unique_ptr<ExprSqlNode>($3);
    }
    | expression '/' expression {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
      $$ = new ExprSqlNode();
      $$->type = ExprNodeType::E_DIV;
      $$->left = std::unique_ptr<ExprSqlNode>($1);
      $$->right = std::unique_ptr<ExprSqlNode>($3);
    }
    | LBRACE expression RBRACE {
      // $$ = $2;
      // $$->set_name(token_name(sql_string, &@$));
      $$ = $2;
      $$->has_brace = true;
    }
    | '-' expression %prec UMINUS {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, $2, nullptr, sql_string, &@$);
      $$ = new ExprSqlNode();
      $$->type = ExprNodeType::E_NEGATIVE;
      $$->right = std::unique_ptr<ExprSqlNode>($2);
    }
    | value {
      // $$ = new ValueExpr(std::move(*$1);
      // $$->set_name(token_name(sql_string, &@$));
      // delete $1;
      $$ = new ExprSqlNode();
      $$->type = ExprNodeType::E_VAL;
      $$->value = std::unique_ptr<Value>($1);
    }
    | dyn_node {
      $$ = new ExprSqlNode();
      $$->type = ExprNodeType::E_DYN;
      $$->attr = std::unique_ptr<DynNodeSqlNode>($1);
    }
    ;

/* select_attr:
    '*' {
      $$ = new std::vector<RelAttrSqlNode>;
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      $$->emplace_back(attr);
    }
    | rel_attr attr_list {
      if ($2 != nullptr) {
        $$ = $2;
      } else {
        $$ = new std::vector<RelAttrSqlNode>;
      }
      $$->emplace_back(std::move(*$1);
      delete $1;
    }
    ; */

select_attr:
  '*' {
    $$ = new std::deque<ExprSqlNode>();
    ExprSqlNode expr;
    expr.type = ExprNodeType::E_DYN;
    expr.attr = std::unique_ptr<DynNodeSqlNode>(new DynNodeSqlNode);

    expr.attr->node.attribute_name = "*";
    
    $$->push_back(std::move(expr));
  }
  | expression_list {
    $$ = $1;
    // $2->push_front(std::move(*$1);
    // delete $1;
  }
  ;

rel_attr:
    ID {
      $$ = new RelAttrSqlNode;
      $$->attribute_name = $1;
      free($1);
    }
    | ID DOT ID {
      $$ = new RelAttrSqlNode;
      $$->relation_name  = $1;
      $$->attribute_name = $3;
      free($1);
      free($3);
    }
    | ID DOT '*' {
      $$ = new RelAttrSqlNode;
      $$->relation_name  = $1;
      $$->attribute_name = "*";
      free($1);
    }
    ;

dyn_node:
  rel_attr {
    $$ = new DynNodeSqlNode();
    $$->node = std::move(*$1);
    delete $1;
  }
  | MAX LBRACE rel_attr RBRACE {
    $$ = new DynNodeSqlNode();
    $$->aggType = AggregationType::A_MAX;
    $$->node = std::move(*$3);
    delete $3;
  }
  | MIN LBRACE rel_attr RBRACE {
    $$ = new DynNodeSqlNode();
    $$->aggType = AggregationType::A_MIN;
    $$->node = std::move(*$3);
    delete $3;
  }
  | COUNT LBRACE rel_attr RBRACE {
    $$ = new DynNodeSqlNode();
    $$->aggType = AggregationType::A_COUNT;
    $$->node = std::move(*$3);
    delete $3;
  }
  | COUNT LBRACE '*' RBRACE {
    $$ = new DynNodeSqlNode();
    $$->aggType = AggregationType::A_COUNT;
    $$->node.attribute_name = '*';
    // $$->node = std::move(*$3);
    // delete $3;
  }
  | AVG LBRACE rel_attr RBRACE {
    $$ = new DynNodeSqlNode();
    $$->aggType = AggregationType::A_AVG;
    $$->node = std::move(*$3);
    delete $3;
  }
  | SUM LBRACE rel_attr RBRACE {
    $$ = new DynNodeSqlNode();
    $$->aggType = AggregationType::A_SUM;
    $$->node = std::move(*$3);
    delete $3;
  }
  ;

relation: 
  ID {
    $$ = new RelSqlNode;
    $$->relation = $1;
    free($1);
  }
  ;

attr_list:
    /* empty */
    {
      $$ = new std::deque<RelAttrSqlNode>;
    }
    | COMMA rel_attr attr_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::deque<RelAttrSqlNode>;
      }

      $$->emplace_front(std::move(*$2));
      delete $2;
    }
    ;

rel_list:
    /* empty */
    {
      $$ = new std::deque<RelSqlNode>;
    }
    | COMMA relation rel_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::deque<RelSqlNode>;
      }

      $$->push_front(std::move(*$2));
      delete $2;
    }
    ;
where:
    /* empty */
    {
      $$ = new std::deque<ConditionSqlNode>();
    }
    | WHERE condition_list {
      $$ = $2;  
    }
    ;

or_where:
  WHERE or_condition_list {
		$$ = $2;
  }
	;
condition_list:
    condition {
      $$ = new std::deque<ConditionSqlNode>;
      $$->emplace_back(std::move(std::move(*$1)));
      delete $1;
    }
    | condition AND condition_list {
      $$ = $3;
      $$->emplace_front(std::move(std::move(*$1)));
      delete $1;
    }
    ;

or_condition_list:
  condition OR condition {
    $$ = new std::deque<ConditionSqlNode>();
		$$->push_back(std::move(*$1));
		$$->push_back(std::move(*$3));
		delete $1;
		delete $3;
  }
  | condition OR or_condition_list {
    $$ = $3;
		$$->push_front(std::move(*$1));
		delete $1;
  }
  ;

// TODO
condition:
    expression comp_op expression
    {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = false;
      $$->right_expr = std::unique_ptr<ExprSqlNode>($3);
      $$->op = $2;

    }
    | LBRACE select RBRACE comp_op expression
    {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = true;
      $$->left_subquery = std::unique_ptr<SelectSqlNode>($2);
      $$->right_is_subquery = false;
      $$->right_expr = std::unique_ptr<ExprSqlNode>($5);
      $$->op= $4;

    }
    |  expression comp_op LBRACE select RBRACE
    {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = true;
      $$->right_subquery = std::unique_ptr<SelectSqlNode>($4);
      $$->op = $2;

    }
    | LBRACE select RBRACE comp_op LBRACE select RBRACE {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = true;
      $$->left_subquery = std::unique_ptr<SelectSqlNode>($2);
      $$->right_is_subquery = true;
      $$->right_subquery = std::unique_ptr<SelectSqlNode>($6);
      $$->op = $4;

    }
    | expression IN LBRACE select RBRACE {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = true;
      $$->right_subquery = std::unique_ptr<SelectSqlNode>($4);
      $$->op = CompOp::IN_SQ;
    }
    | expression NOT IN LBRACE select RBRACE {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = true;
      $$->right_subquery = std::unique_ptr<SelectSqlNode>($5);
      $$->op = CompOp::NOT_IN_SQ;
    }
    | expression IN LBRACE value_list RBRACE {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = false;
      $$->value_list = std::move(*$4);
      $$->right_is_list = true;
      $$->op = CompOp::IN_SQ;
      delete $4;
    }
    | expression NOT IN LBRACE value_list RBRACE {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = false;
      $$->value_list = std::move(*$5);
      $$->right_is_list = true;
      $$->op = CompOp::NOT_IN_SQ;
      delete $5;
    }
    | EXISTS LBRACE select RBRACE {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->right_is_subquery = true;
      $$->right_subquery = std::unique_ptr<SelectSqlNode>($3);
      $$->op = CompOp::EXISTS_SQ;
    }
    | NOT EXISTS LBRACE select RBRACE {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->right_is_subquery = true;
      $$->right_subquery = std::unique_ptr<SelectSqlNode>($4);
      $$->op = CompOp::NOT_EXISTS_SQ;
    }
    | expression IS NOT NULL_LITERAL {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = false;
      $$->op = CompOp::IS_NOT_NULL;
    }
    | expression IS NULL_LITERAL {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = false;
      $$->op = CompOp::IS_NULL;
    }
    | expression LIKE expression {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = false;
      $$->right_expr = std::unique_ptr<ExprSqlNode>($3);
      $$->op = LIKE_SCH;
    }
    | expression NOT LIKE expression {
      $$ = new ConditionSqlNode;
      $$->left_is_subquery = false;
      $$->left_expr = std::unique_ptr<ExprSqlNode>($1);
      $$->right_is_subquery = false;
      $$->right_expr = std::unique_ptr<ExprSqlNode>($4);
      $$->op = NOT_LIKE_SCH;
    }
    ;

comp_op:
      EQ { $$ = EQUAL_TO; }
    | LT { $$ = LESS_THAN; }
    | GT { $$ = GREAT_THAN; }
    | LE { $$ = LESS_EQUAL; }
    | GE { $$ = GREAT_EQUAL; }
    | NE { $$ = NOT_EQUAL; }
    ;

join_conditions:
  /* empty */ {
    $$ = new std::deque<ConditionSqlNode>;
  }
  | ON condition_list {
    $$ = $2;
  }
  ;

join_list:
  /* EMPTY */{
    $$ = new std::deque<JoinSqlNode>();
  }
	| INNER JOIN ID join_conditions join_list {
		$$ = $5;
		JoinSqlNode join;
		join.relation = $3;
		join.on_coditions = std::move(*$4);
		$$->push_front(std::move(join));

    free($3);
    delete $4;
	}
	;

having:
  /* empty */{
		$$ = new std::deque<ConditionSqlNode>;
	}
	| HAVING condition_list {
		$$ = $2;
		// $$->push_front(std::move(*$2);
		// delete $2;
	}
	;

groupby:
  /* empty */ {
    $$ = nullptr;
  }
  | GROUP BY rel_attr attr_list having {
    $$ = new GroupBySqlNode();
    $4->push_front(std::move(*$3));
    delete $3;
    $$->by_attrs          = std::move(*$4);
    $$->having_conditions = std::move(*$5);
    delete $4;
    delete $5;
  }
  ;

orderby:
	/* empty */ {
		$$ = new std::deque<OrderBySqlNode>();
	}
	| ORDER BY orderby_col orderby_list {
		$$ = $4;
		$$->push_front(std::move(*$3));
    delete $3;
	}
	;

orderby_list:
  /* empty */ {
    $$ = new std::deque<OrderBySqlNode>();
  }
  | COMMA orderby_col orderby_list {
    $$ = $3;
    $$->push_front(std::move(*$2));
    delete $2;
  }
  ;

orderby_col:
  rel_attr {
    $$ = new OrderBySqlNode();
    $$->by_attr = std::unique_ptr<RelAttrSqlNode>($1);
    $$->is_asc  = true;
  }
  | rel_attr ASC {
    $$ = new OrderBySqlNode();
    $$->by_attr = std::unique_ptr<RelAttrSqlNode>($1);
    $$->is_asc  = true;
  }
  | rel_attr DESC {
    $$ = new OrderBySqlNode();
    $$->by_attr = std::unique_ptr<RelAttrSqlNode>($1);
    $$->is_asc  = false;
  }
  ;

insert_row_list:
  LBRACE value_list RBRACE {
    InsertRowNode row;
    row.values = std::move(*$2);
    delete $2;
    $$ = new std::deque<InsertRowNode>();
    $$->push_back(std::move(row));
  }
  | LBRACE value_list RBRACE COMMA insert_row_list {
    InsertRowNode row;
    row.values = std::move(*$2);
    delete $2;
    $$ = $5;
    $$->push_back(std::move(row));
  }
  ;

update_list:
	SET update_pair
		{
			$$ = new std::deque<UpdatePairSqlNode>;
      $$->push_back(std::move(*$2));
      delete $2;
		}
	| update_list COMMA update_pair
		{
			$$ = $1;
      $$->push_back(std::move(std::move(*$3)));
      delete $3;
		}
	;

update_pair:
	ID EQ value_list_cell {
		$$ = new UpdatePairSqlNode();
    $$->attr.attribute_name = $1;
		$$->is_select = false;
    $$->value = std::move(std::move(*$3));
		delete $3;
    free($1);
	}
	| ID EQ LBRACE select RBRACE {
		$$ = new UpdatePairSqlNode();
    $$->attr.attribute_name = $1;
		$$->is_select = true;
    $$->select_value = std::move(std::move(*$4));
		delete $4;
    free($1);
  }
	;

load_data_stmt:
    LOAD DATA INFILE SSS INTO TABLE ID 
    {
      char *tmp_file_name = common::substr($4, 1, strlen($4) - 2);
      
      $$ = new ParsedSqlNode(SCF_LOAD_DATA);
      $$->load_data.relation_name = $7;
      $$->load_data.file_name = tmp_file_name;
      free($7);
      free(tmp_file_name);
    }
    ;

explain_stmt:
    EXPLAIN command_wrapper
    {
      $$ = new ParsedSqlNode(SCF_EXPLAIN);
      $$->explain.sql_node = std::unique_ptr<ParsedSqlNode>($2);
    }
    ;

set_variable_stmt:
    SET ID EQ value
    {
      $$ = new ParsedSqlNode(SCF_SET_VARIABLE);
      $$->set_variable.name  = $2;
      $$->set_variable.value = std::move(std::move(*$4));
      free($2);
      delete $4;
    }
    ;

opt_semicolon: /*empty*/
    | SEMICOLON
    ;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
