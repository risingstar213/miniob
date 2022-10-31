
%{

#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.hpp"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  char id[MAX_NUM];
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = (char *)malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->ssql->sstr.insertion.row_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)

extern int atoi();
extern double atof();

%}

%code requires{
#include <deque>
#include <string>
typedef struct _RelAttr RelAttr;
typedef struct _Selects Selects;
typedef struct _Value Value;
typedef struct _Condition Condition;
typedef struct _Join Join;
typedef struct _UpdateValue UpdateValue;
typedef struct _SelectExpr SelectExpr;
typedef struct _ConditionExpr ConditionExpr;
typedef std::deque<RelAttr> AttrList;
typedef std::deque<Value> ValueList;
typedef std::deque<Condition> ConditionList;
typedef std::deque<Join> JoinList;
typedef std::deque<UpdateValue> UpdateValueList;
typedef std::deque<SelectExpr> SelectExprList;
typedef std::deque<ConditionExpr> ConditionExprList;
typedef std::deque<char *> IdList;
// typedef std::string String;
}

%define api.pure full
%lex-param { yyscan_t scanner }
%parse-param { void *scanner }

//标识tokens
%token  IS
		NULL_
		NULLABLE
		SEMICOLON
        CREATE
        DROP
        TABLE
        TABLES
        INDEX
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
		TEXT_T
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        WHERE
        AND
        SET
        NOT
        LIKE
        INNER
        JOIN
        ON
        LOAD
        DATA
        INFILE
		UNIQUE
		MAX
		MIN
		SUM
		COUNT
		AVG
		ADD_OP
		SUB_OP
		DIV_OP
		IN
        EQ
        LT
        GT
        LE
        GE
        NE

%union {
  RelAttr *attr1;
  Condition *condition1;
  Value *value1;
  Join *join1;
  Selects *select1;
  UpdateValue *updatevalue1;
  SelectExpr *selectexpr1;
  ConditionExpr *conditionexpr1;
  char *string1;
  int number1;
  float floats1;
  char position1;
  int comp1;
  ValueList *values1;
  ConditionList *conditions1;
  JoinList *joins1;
  IdList *ids1;
  AttrList *attrs1;
  UpdateValueList *updatevaluelist1;
  SelectExprList *selectexprs1;
  ConditionExprList *conditionexprs1;
}

%token <string1> NUMBER
%token <string1> FLOAT 
%token <string1> DATE_DATA
%token <string1> ID
%token <string1> PATH
%token <string1> SSS
%token <string1> LIKE_SSS
%token <string1> STAR
%token <string1> STRING_V
//非终结符

%type <number1> type;
%type <condition1> condition;
%type <value1> value;
%type <value1> insert_value;
%type <value1> like_value;
%type <number1> number;
%type <comp1> comOp;
%type <comp1> like_comOp;
%type <comp1> is_null_comOp;
%type <attr1> aggration_attr;
%type <attr1> rel_attr;
%type <select1> select;
%type <updatevalue1> update_value;
%type <selectexpr1> select_arith_expr;

%type <values1> value_list;
%type <conditions1> where;
%type <conditions1> condition_list;
%type <conditions1> join_condition_list;
%type <joins1> join_list;
%type <ids1> id_list;
%type <ids1> rel_list;
%type <attrs1> attr_list;
%type <attrs1> select_attr;
%type <selectexprs1> select_expr_list;

// 运算符优先级结合型定义
// 从上向下依次增高
%left ADD_OP SUB_OP
%left STAR DIV_OP
%left UNARYMINUS  // important !!!

%%

commands:		//commands or sqls. parser starts here.
    /* empty */
    | commands command
    ;

command:
	  select SEMICOLON {
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->ssql->sstr.selection = *$1;
		delete $1;
	  }
	| insert
	| update
	| delete
	| create_table
	| drop_table
	| show_tables
	| desc_table
	| create_index	
	| drop_index
	| show_index
	| sync
	| begin
	| commit
	| rollback
	| load_data
	| help
	| exit
    ;

exit:			
    EXIT SEMICOLON {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    };

help:
    HELP SEMICOLON {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    };

sync:
    SYNC SEMICOLON {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
    ;

begin:
    TRX_BEGIN SEMICOLON {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
    ;

commit:
    TRX_COMMIT SEMICOLON {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
    ;

rollback:
    TRX_ROLLBACK SEMICOLON {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
    ;

drop_table:		/*drop table 语句的语法解析树*/
    DROP TABLE ID SEMICOLON {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, $3);
    };

show_tables:
    SHOW TABLES SEMICOLON {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
    ;

desc_table:
    DESC ID SEMICOLON {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, $2);
    }
    ;

create_index:		/*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE id_list SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, $3, $5, *$7, false);
			delete $7;
		}
	| CREATE UNIQUE INDEX ID ON ID LBRACE id_list SEMICOLON
		{
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, $4, $6, *$8, true);
			delete $8;
		}
    ;

drop_index:			/*drop index 语句的语法解析树*/
    DROP INDEX ID  SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, $3);
		}
    ;
show_index:
	SHOW INDEX FROM ID SEMICOLON
		{
			CONTEXT->ssql->flag=SCF_SHOW_INDEX;//"show_index";
			show_index_init(&CONTEXT->ssql->sstr.show_index, $4);
		}
	;
create_table:		/*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, $3);
		}
    ;
attr_def_list:
    /* empty */
    | COMMA attr_def attr_def_list {    }
    ;
    
attr_def:
    ID_get type LBRACE number RBRACE 
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, AttrType($2), $4);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;

		}
    |ID_get type
		{
			AttrInfo attribute;
			if ($2 == DATES) {
				attr_info_init(&attribute, CONTEXT->id, AttrType($2), 12);
			} else if ($2 == TEXTS) {
				attr_info_init(&attribute, CONTEXT->id, AttrType($2), 4096);
			} else {
				attr_info_init(&attribute, CONTEXT->id, AttrType($2), 4);
			}
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
		}
	|attr_def NOT NULL_
		{}
	|attr_def NULLABLE
		{
			CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->ssql->sstr.create_table.attribute_count-1].nullable = true;
		}
    ;

id_list:
	ID RBRACE
	{
		$$ = new IdList();
		$$->push_front($1);
	}
	| ID COMMA id_list
	{
		$$ = $3;
		$$->push_front($1);
	}
	;

number:
		NUMBER {$$ = atoi($1);}
		;
type:
	INT_T { $$=INTS; }
       | STRING_T { $$=CHARS; }
       | FLOAT_T { $$=FLOATS; }
	   | DATE_T { $$=DATES; }
	   | TEXT_T { $$=TEXTS; }
       ;
ID_get:
	ID 
	{
		char *temp=$1; 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
	;

	
insert:				/*insert   语句的语法解析树*/
    INSERT INTO ID VALUES row row_list SEMICOLON 
		{
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, $3);
    }
	;

row_list:
	/* empty */
	| COMMA row row_list
	{	/* do nothing here */	}

row:
	LBRACE value value_list RBRACE {
		$3->push_front(*$2);
		inserts_row_init(&CONTEXT->ssql->sstr.insertion.rows[CONTEXT->ssql->sstr.insertion.row_num], *$3);
		(CONTEXT->ssql->sstr.insertion.row_num)++;

		delete $2;
		delete $3;
	}
	;

value_list:
    /* empty */ {
		$$ = new ValueList();
	}
    | COMMA insert_value value_list  { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
		$$ = $3;
		$$->push_front(*$2);

		delete $2;
	}
    ;
value:
    NUMBER{	
  		$$ = new Value();
		value_init_integer($$, atoi($1), $1);
		}
    |FLOAT{
  		$$ = new Value();
		value_init_float($$, (float)(atof($1)), $1);
		}
    |SSS {
		$1 = substr($1,1,strlen($1)-2);
		$$ = new Value();
  		value_init_string($$, $1);
		}
	|NULL_ {
		$$ = new Value();
		value_init_null($$);
	}
	|DATE_DATA {
		$1 = substr($1,1,strlen($1)-2);
		$$ = new Value();
		value_init_date($$, $1);
	}
    ;

insert_value:
	value {
		$$ = $1;
	}
	| SUB_OP NUMBER {	
  		$$ = new Value();
		value_init_integer($$, -atoi($2), $2);
	}
	;

like_value:
	LIKE_SSS {
		$1 = substr($1,1,strlen($1)-2);
		$$ = new Value();
  		value_init_string($$, $1);
	}
	|SSS {
		$1 = substr($1,1,strlen($1)-2);
		$$ = new Value();
  		value_init_string($$, $1);
	}
	;
    
delete:		/*  delete 语句的语法解析树*/
    DELETE FROM ID where SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, $3);
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, *$4);

			delete $4;
    }
    ;
update:			/*  update 语句的语法解析树*/
    UPDATE ID update_list where SEMICOLON
		{
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, $2, *$4);
			delete $4;
		}
    ;

update_list:
	SET ID EQ update_value
		{
			update_append_attribute(&CONTEXT->ssql->sstr.update, $2, $4);
			delete $4;
		}
	| update_list COMMA ID EQ update_value
		{
			update_append_attribute(&CONTEXT->ssql->sstr.update, $3, $5);
			delete $5;
		}
	;

update_value:
	value {
		$$ = new UpdateValue();
		updatevalue_init_value($$, $1);
		delete $1;
	}
	| LBRACE select RBRACE {
		$$ = new UpdateValue();
		updatevalue_init_select($$, $2);
		delete $2;
	}
	;

select:				/*  select 语句的语法解析树*/
    SELECT select_expr_list FROM ID rel_list where
		{
			$$ = new Selects();
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			$5->push_back($4);
			selects_append_relation($$, *$5);

			selects_append_select_exprs($$, *$2);

            selects_append_joins($$, JoinList());

			selects_append_conditions($$, *$6);

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete $2;
			delete $6;
			delete $5;

	}
	| SELECT select_expr_list FROM ID join_list where {
		// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			$$ = new Selects();
			IdList relation_list;
			relation_list.push_back($4);
			selects_append_relation($$, relation_list);

			selects_append_select_exprs($$, *$2);

            selects_append_joins($$, *$5);

			selects_append_conditions($$, *$6);

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete $2;
			delete $5;
			delete $6;
	}
	;


select_arith_expr:
	select_arith_expr ADD_OP select_arith_expr {
		$$ = new SelectExpr();
		select_subexpr_init($$, $1, $3, ARITH_ADD);
	}
	| select_arith_expr SUB_OP select_arith_expr {
		$$ = new SelectExpr();
		select_subexpr_init($$, $1, $3, ARITH_SUB);
	}
	| select_arith_expr STAR select_arith_expr {
		$$ = new SelectExpr();
		select_subexpr_init($$, $1, $3, ARITH_MUL);
	}
	| select_arith_expr DIV_OP select_arith_expr {
		$$ = new SelectExpr();
		select_subexpr_init($$, $1, $3, ARITH_DIV);
	}
	| rel_attr {
		$$ = new SelectExpr();
		select_attr_init($$, $1);
	}
	| value {
		$$ = new SelectExpr();
		select_value_init($$, $1);
	}
	| LBRACE select_arith_expr RBRACE {
		$$ = $2;
		$$->is_brace = true;
	}
	| SUB_OP select_arith_expr %prec UNARYMINUS {
		$$ = new SelectExpr();
		select_subexpr_init($$, nullptr, $2, ARITH_NEG);
	}
	;

select_expr_list:
	STAR {
		RelAttr *attr = new RelAttr();
		relation_attr_init_with_aggregation(attr, NULL, "*", AGG_NONE, true);
		SelectExpr expr;
		select_attr_init(&expr, attr);
		$$ = new SelectExprList();
		$$->push_back(expr);
	}
	| select_arith_expr {
		$$ = new SelectExprList();
		$$->push_back(*$1);
		delete $1;
	}
	| select_expr_list COMMA select_arith_expr {
		$$ = $1;
		$$->push_back(*$3);
		delete $3;
	}
	;

select_attr:
    STAR attr_list {  
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, NULL, "*", AGG_NONE, true);
			$2->push_front(attr);
			$$ = $2;
		}
	| rel_attr attr_list {
		$2->push_front(*$1);
		// selects_append_attribute(&CONTEXT->ssql->sstr.selection, *$2);
		delete($1);
		$$ = $2;
	}
	;

aggration_attr:
	MAX LBRACE select_attr RBRACE {
		$$ = new RelAttr();
		if ($3->size() != 1) {
			relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*$3)[0];
			relation_attr_init_copy($$, attr, AGG_MAX);
		}
		delete $3;
	}
	| MIN LBRACE select_attr RBRACE {
		$$ = new RelAttr();
		if ($3->size() != 1) {
			relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*$3)[0];
			relation_attr_init_copy($$, attr, AGG_MIN);
		}
		delete $3;
	}
	| SUM LBRACE select_attr RBRACE {
		$$ = new RelAttr();
		if ($3->size() != 1) {
			relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*$3)[0];
			relation_attr_init_copy($$, attr, AGG_SUM);
		}
		delete $3;
	}
	| COUNT LBRACE select_attr RBRACE {
		$$ = new RelAttr();
		if ($3->size() != 1) {
			relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*$3)[0];
			relation_attr_init_copy($$, attr, AGG_COUNT);
		}
		delete $3;
	}
	| AVG LBRACE select_attr RBRACE {
		$$ = new RelAttr();
		if ($3->size() != 1) {
			relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*$3)[0];
			relation_attr_init_copy($$, attr, AGG_AVG);
		}
		delete $3;
	}
	| MAX LBRACE RBRACE {
		$$ = new RelAttr();
		relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
	}
	| MIN LBRACE RBRACE {
		$$ = new RelAttr();
		relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
	}
	| SUM LBRACE RBRACE {
		$$ = new RelAttr();
		relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
	}
	| COUNT LBRACE RBRACE {
		$$ = new RelAttr();
		relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
	}
	| AVG LBRACE RBRACE {
		$$ = new RelAttr();
		relation_attr_init_with_aggregation($$, NULL, NULL, AGG_NONE, false);
	}
	;

rel_attr:
	ID {
		$$ = new RelAttr();
		relation_attr_init_with_aggregation($$, NULL, $1, AGG_NONE,true);
	}
	| ID DOT ID {
		$$ = new RelAttr();
		relation_attr_init_with_aggregation($$, $1, $3, AGG_NONE,true);
	}
	| aggration_attr {
		$$ = $1;
	}
	;

attr_list:
    /* empty */ {
		$$ = new AttrList();
	}
	| COMMA rel_attr attr_list {
		$$ = $3;
		$$->push_front(*$2);
		delete $2;
	}
  	;

rel_list:
    /* empty */ {
		$$ = new IdList();
	}
    | COMMA ID rel_list {	
		$$ = $3;
		$$->push_back($2);
	}
    ;

join_list:
	INNER JOIN ID join_condition_list {
		$$ = new JoinList();
		Join join;
		join_set_relation(&join, $3);
		join_append_conditions(&join, *$4);
		$$->push_back(join);

		delete $4;
	}
	| INNER JOIN ID join_condition_list join_list {
		$$ = $5;
		Join join;
		join_set_relation(&join, $3);
		join_append_conditions(&join, *$4);
		$$->push_front(join);

		delete $4;
	}
	;

join_condition_list:
	ON condition condition_list {
		$$ = $3;
		$$->push_front(*$2);

		delete $2;
	}
	;

where:
    /* empty */ {
		$$ = new ConditionList();
	}
    | WHERE condition condition_list {
		$$ = $3;
		$$->push_front(*$2);
		delete $2;
	}
    ;
condition_list:
    /* empty */ {
		$$ = new ConditionList();
	}
    | AND condition condition_list {
		$$ = $3;
		$$->push_front(*$2);
		delete $2;
	}
    ;
condition:
    select_arith_expr comOp select_arith_expr
	{
		$$ = new Condition();
		condition_init($$, CompOp($2), $1, $3);
		delete $1;
		delete $3;
	}
	|ID like_comOp like_value
	{
		RelAttr *left_attr = new RelAttr();
		relation_attr_init(left_attr, NULL, $1);
		SelectExpr *left_expr = new SelectExpr();
		select_attr_init(left_expr, left_attr);

		Value *right_value = $3;
		SelectExpr *right_expr = new SelectExpr();
		select_value_init(right_expr, right_value);

		$$ = new Condition();
		condition_init($$, CompOp($2), left_expr, right_expr);
		delete left_expr;
		delete right_expr;

		// $$ = ( Condition *)malloc(sizeof( Condition));
		// $$->left_is_attr = 1;
		// $$->left_attr.relation_name = NULL;
		// $$->left_attr.attribute_name= $1;
		// $$->comp = CONTEXT->comp;
		// $$->right_is_attr = 0;
		// $$->right_attr.relation_name = NULL;
		// $$->right_attr.attribute_name = NULL;
		// $$->right_value = *$3;
	}
	|ID DOT ID like_comOp like_value
		{
			RelAttr *left_attr = new RelAttr();
			relation_attr_init(left_attr, $1, $3);
			SelectExpr *left_expr = new SelectExpr();
			select_attr_init(left_expr, left_attr);

			Value *right_value = $5;
			SelectExpr *right_expr = new SelectExpr();
			select_value_init(right_expr, right_value);

			$$ = new Condition();
			condition_init($$, CompOp($4), left_expr, right_expr);
			delete left_expr;
			delete right_expr;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
	ID is_null_comOp NULL_ {
		RelAttr *left_attr = new RelAttr();
		relation_attr_init(left_attr, NULL, $1);
		SelectExpr *left_expr = new SelectExpr();
		select_attr_init(left_expr, left_attr);

		Value *right_value = $3;
		SelectExpr *right_expr = new SelectExpr();
		select_value_init(right_expr, right_value);

		$$ = new Condition();
		condition_init($$, CompOp($2), left_expr, right_expr);
		delete left_expr;
		delete right_expr;
	}
	ID DOT ID is_null_comOp NULL_ {
		RelAttr *left_attr = new RelAttr();
		relation_attr_init(left_attr, $1, $3);
		SelectExpr *left_expr = new SelectExpr();
		select_attr_init(left_expr, left_attr);

		Value *right_value = $5;
		SelectExpr *right_expr = new SelectExpr();
		select_value_init(right_expr, right_value);

		$$ = new Condition();
		condition_init($$, CompOp($4), left_expr, right_expr);
		delete left_expr;
		delete right_expr;
	}
	NULL_ is_null_comOp ID { // 左右操作数互换
		RelAttr *left_attr = new RelAttr();
		relation_attr_init(left_attr, NULL, $3);
		SelectExpr *left_expr = new SelectExpr();
		select_attr_init(left_expr, left_attr);

		Value *right_value = $1;
		SelectExpr *right_expr = new SelectExpr();
		select_value_init(right_expr, right_value);

		$$ = new Condition();
		condition_init($$, CompOp($2), left_expr, right_expr);
		delete left_expr;
		delete right_expr;
	}
	NULL_ is_null_comOp ID DOT ID { // 左右操作数互换
		RelAttr *left_attr = new RelAttr();
		relation_attr_init(left_attr, $3, $5);
		SelectExpr *left_expr = new SelectExpr();
		select_attr_init(left_expr, left_attr);

		Value *right_value = $1;
		SelectExpr *right_expr = new SelectExpr();
		select_value_init(right_expr, right_value);

		$$ = new Condition();
		condition_init($$, CompOp($2), left_expr, right_expr);
		delete left_expr;
		delete right_expr;
	}
    ;

comOp:
  	  EQ { $$ = EQUAL_TO; }
    | LT { $$ = LESS_THAN; }
    | GT { $$ = GREAT_THAN; }
    | LE { $$ = LESS_EQUAL; }
    | GE { $$ = GREAT_EQUAL; }
    | NE { $$ = NOT_EQUAL; }
    ;

like_comOp:
	  NOT LIKE { $$ = UNLIKE_SCH; }
	| LIKE { $$ = LIKE_SCH; }
    ;

is_null_comOp:
	  IS { $$ = IS_NULL; }
	| IS NOT { $$ = IS_NOT_NULL; }	
	;

load_data:
		LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON
		{
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, $7, $4);
		}
		;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
