/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_YACC_SQL_TAB_H_INCLUDED
# define YY_YY_YACC_SQL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 51 "yacc_sql.y"

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
typedef struct _OrderCol OrderCol;
typedef struct _GroupBy GroupBy;
typedef std::deque<RelAttr> AttrList;
typedef std::deque<Value> ValueList;
typedef std::deque<Condition> ConditionList;
typedef std::deque<Join> JoinList;
typedef std::deque<UpdateValue> UpdateValueList;
typedef std::deque<SelectExpr> SelectExprList;
typedef std::deque<ConditionExpr> ConditionExprList;
typedef std::deque<char *> IdList;
typedef std::deque<OrderCol> OrderColList;
// typedef std::string String;

#line 73 "yacc_sql.tab.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ORDER = 258,
    BY = 259,
    ASC = 260,
    IS = 261,
    NULL_ = 262,
    NULLABLE = 263,
    SEMICOLON = 264,
    CREATE = 265,
    DROP = 266,
    TABLE = 267,
    TABLES = 268,
    INDEX = 269,
    SELECT = 270,
    DESC = 271,
    SHOW = 272,
    SYNC = 273,
    INSERT = 274,
    DELETE = 275,
    UPDATE = 276,
    LBRACE = 277,
    RBRACE = 278,
    COMMA = 279,
    TRX_BEGIN = 280,
    TRX_COMMIT = 281,
    TRX_ROLLBACK = 282,
    INT_T = 283,
    STRING_T = 284,
    FLOAT_T = 285,
    DATE_T = 286,
    TEXT_T = 287,
    HELP = 288,
    EXIT = 289,
    DOT = 290,
    INTO = 291,
    VALUES = 292,
    FROM = 293,
    WHERE = 294,
    AND = 295,
    OR = 296,
    SET = 297,
    NOT = 298,
    LIKE = 299,
    INNER = 300,
    JOIN = 301,
    ON = 302,
    LOAD = 303,
    DATA = 304,
    INFILE = 305,
    UNIQUE = 306,
    MAX = 307,
    MIN = 308,
    SUM = 309,
    COUNT = 310,
    AVG = 311,
    ADD_OP = 312,
    SUB_OP = 313,
    DIV_OP = 314,
    IN = 315,
    EXISTS = 316,
    GROUP = 317,
    HAVING = 318,
    EQ = 319,
    LT = 320,
    GT = 321,
    LE = 322,
    GE = 323,
    NE = 324,
    NUMBER = 325,
    FLOAT = 326,
    DATE_DATA = 327,
    ID = 328,
    PATH = 329,
    SSS = 330,
    LIKE_SSS = 331,
    STAR = 332,
    STRING_V = 333,
    UNARYMINUS = 334
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 149 "yacc_sql.y"

  RelAttr *attr1;
  Condition *condition1;
  Value *value1;
  Join *join1;
  Selects *select1;
  UpdateValue *updatevalue1;
  SelectExpr *selectexpr1;
  ConditionExpr *conditionexpr1;
  GroupBy *groupby1;
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
  OrderCol *ocol1; 		// order column
  OrderColList *ocol_list1;

#line 191 "yacc_sql.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */
