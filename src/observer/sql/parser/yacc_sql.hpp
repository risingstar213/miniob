/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_SQL_HPP_INCLUDED
# define YY_YY_YACC_SQL_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    CREATE = 259,                  /* CREATE  */
    DROP = 260,                    /* DROP  */
    TABLE = 261,                   /* TABLE  */
    TABLES = 262,                  /* TABLES  */
    INDEX = 263,                   /* INDEX  */
    VIEW = 264,                    /* VIEW  */
    CALC = 265,                    /* CALC  */
    SELECT = 266,                  /* SELECT  */
    DESC = 267,                    /* DESC  */
    SHOW = 268,                    /* SHOW  */
    SYNC = 269,                    /* SYNC  */
    INSERT = 270,                  /* INSERT  */
    DELETE = 271,                  /* DELETE  */
    UPDATE = 272,                  /* UPDATE  */
    LBRACE = 273,                  /* LBRACE  */
    RBRACE = 274,                  /* RBRACE  */
    COMMA = 275,                   /* COMMA  */
    TRX_BEGIN = 276,               /* TRX_BEGIN  */
    TRX_COMMIT = 277,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 278,            /* TRX_ROLLBACK  */
    INT_T = 279,                   /* INT_T  */
    STRING_T = 280,                /* STRING_T  */
    FLOAT_T = 281,                 /* FLOAT_T  */
    DATE_T = 282,                  /* DATE_T  */
    TEXT_T = 283,                  /* TEXT_T  */
    HELP = 284,                    /* HELP  */
    EXIT = 285,                    /* EXIT  */
    DOT = 286,                     /* DOT  */
    INTO = 287,                    /* INTO  */
    VALUES = 288,                  /* VALUES  */
    FROM = 289,                    /* FROM  */
    WHERE = 290,                   /* WHERE  */
    AND = 291,                     /* AND  */
    OR = 292,                      /* OR  */
    SET = 293,                     /* SET  */
    ON = 294,                      /* ON  */
    LOAD = 295,                    /* LOAD  */
    DATA = 296,                    /* DATA  */
    INFILE = 297,                  /* INFILE  */
    EXPLAIN = 298,                 /* EXPLAIN  */
    EQ = 299,                      /* EQ  */
    LT = 300,                      /* LT  */
    GT = 301,                      /* GT  */
    LE = 302,                      /* LE  */
    GE = 303,                      /* GE  */
    NE = 304,                      /* NE  */
    NOT = 305,                     /* NOT  */
    LIKE = 306,                    /* LIKE  */
    INNER = 307,                   /* INNER  */
    JOIN = 308,                    /* JOIN  */
    UNIQUE = 309,                  /* UNIQUE  */
    MAX = 310,                     /* MAX  */
    MIN = 311,                     /* MIN  */
    SUM = 312,                     /* SUM  */
    COUNT = 313,                   /* COUNT  */
    AVG = 314,                     /* AVG  */
    LENGTH = 315,                  /* LENGTH  */
    ROUND = 316,                   /* ROUND  */
    DATE_FORMAT = 317,             /* DATE_FORMAT  */
    IN = 318,                      /* IN  */
    EXISTS = 319,                  /* EXISTS  */
    GROUP = 320,                   /* GROUP  */
    HAVING = 321,                  /* HAVING  */
    AS = 322,                      /* AS  */
    ORDER = 323,                   /* ORDER  */
    BY = 324,                      /* BY  */
    ASC = 325,                     /* ASC  */
    IS = 326,                      /* IS  */
    NULL_LITERAL = 327,            /* NULL_LITERAL  */
    NULLABLE = 328,                /* NULLABLE  */
    NUMBER = 329,                  /* NUMBER  */
    FLOAT = 330,                   /* FLOAT  */
    DATE = 331,                    /* DATE  */
    ID = 332,                      /* ID  */
    SSS = 333,                     /* SSS  */
    UMINUS = 334                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 134 "yacc_sql.y"

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

#line 176 "yacc_sql.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner);


#endif /* !YY_YY_YACC_SQL_HPP_INCLUDED  */
