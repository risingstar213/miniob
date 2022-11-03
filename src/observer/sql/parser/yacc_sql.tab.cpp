/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "yacc_sql.y" /* yacc.c:339  */


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


#line 115 "yacc_sql.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yacc_sql.tab.h".  */
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
#line 51 "yacc_sql.y" /* yacc.c:355  */

#include <deque>
#include <string>
typedef struct _RelAttr RelAttr;
typedef struct _Relation Relation;
typedef struct _Selects Selects;
typedef struct _Value Value;
typedef struct _Condition Condition;
typedef struct _Join Join;
typedef struct _UpdateValue UpdateValue;
typedef struct _SelectExpr SelectExpr;
typedef struct _ConditionExpr ConditionExpr;
typedef struct _GroupBy GroupBy;
typedef std::deque<RelAttr> AttrList;
typedef std::deque<Value> ValueList;
typedef std::deque<Condition> ConditionList;
typedef std::deque<Join> JoinList;
typedef std::deque<UpdateValue> UpdateValueList;
typedef std::deque<SelectExpr> SelectExprList;
typedef std::deque<ConditionExpr> ConditionExprList;
typedef std::deque<char *> IdList;
typedef std::deque<Relation> RelationList;
// typedef std::string String;

#line 170 "yacc_sql.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IS = 258,
    NULL_ = 259,
    NULLABLE = 260,
    SEMICOLON = 261,
    CREATE = 262,
    DROP = 263,
    TABLE = 264,
    TABLES = 265,
    INDEX = 266,
    SELECT = 267,
    DESC = 268,
    SHOW = 269,
    SYNC = 270,
    INSERT = 271,
    DELETE = 272,
    UPDATE = 273,
    LBRACE = 274,
    RBRACE = 275,
    COMMA = 276,
    TRX_BEGIN = 277,
    TRX_COMMIT = 278,
    TRX_ROLLBACK = 279,
    INT_T = 280,
    STRING_T = 281,
    FLOAT_T = 282,
    DATE_T = 283,
    TEXT_T = 284,
    HELP = 285,
    EXIT = 286,
    DOT = 287,
    INTO = 288,
    VALUES = 289,
    FROM = 290,
    WHERE = 291,
    AND = 292,
    OR = 293,
    SET = 294,
    NOT = 295,
    LIKE = 296,
    INNER = 297,
    JOIN = 298,
    ON = 299,
    LOAD = 300,
    DATA = 301,
    INFILE = 302,
    UNIQUE = 303,
    MAX = 304,
    MIN = 305,
    SUM = 306,
    COUNT = 307,
    AVG = 308,
    ADD_OP = 309,
    SUB_OP = 310,
    DIV_OP = 311,
    IN = 312,
    EXISTS = 313,
    GROUP = 314,
    BY = 315,
    HAVING = 316,
    AS = 317,
    EQ = 318,
    LT = 319,
    GT = 320,
    LE = 321,
    GE = 322,
    NE = 323,
    NUMBER = 324,
    FLOAT = 325,
    DATE_DATA = 326,
    ID = 327,
    PATH = 328,
    SSS = 329,
    LIKE_SSS = 330,
    STAR = 331,
    STRING_V = 332,
    UNARYMINUS = 333
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 148 "yacc_sql.y" /* yacc.c:355  */

  RelAttr *attr1;
  Relation *relation1;
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
  RelationList *relations1;
  UpdateValueList *updatevaluelist1;
  SelectExprList *selectexprs1;
  ConditionExprList *conditionexprs1;

#line 288 "yacc_sql.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 304 "yacc_sql.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   376

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   333

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   228,   228,   230,   234,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   259,   264,   269,   275,   281,   287,   293,   299,
     305,   312,   318,   327,   334,   341,   348,   350,   354,   365,
     381,   383,   390,   395,   403,   406,   407,   408,   409,   410,
     413,   422,   436,   438,   442,   453,   456,   465,   469,   473,
     478,   482,   490,   493,   500,   505,   513,   523,   532,   537,
     545,   550,   558,   582,   606,   633,   637,   641,   645,   649,
     653,   657,   661,   668,   676,   681,   689,   695,   704,   714,
     724,   734,   744,   754,   758,   762,   766,   770,   777,   780,
     786,   793,   801,   810,   813,   821,   824,   833,   842,   854,
     863,   866,   875,   878,   889,   892,   900,   905,   909,   916,
     919,   927,   934,   941,   948,   961,   968,   978,   991,  1004,
    1005,  1006,  1007,  1008,  1009,  1013,  1014,  1018,  1019,  1023,
    1024,  1027,  1028,  1032
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IS", "NULL_", "NULLABLE", "SEMICOLON",
  "CREATE", "DROP", "TABLE", "TABLES", "INDEX", "SELECT", "DESC", "SHOW",
  "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA",
  "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES",
  "FROM", "WHERE", "AND", "OR", "SET", "NOT", "LIKE", "INNER", "JOIN",
  "ON", "LOAD", "DATA", "INFILE", "UNIQUE", "MAX", "MIN", "SUM", "COUNT",
  "AVG", "ADD_OP", "SUB_OP", "DIV_OP", "IN", "EXISTS", "GROUP", "BY",
  "HAVING", "AS", "EQ", "LT", "GT", "LE", "GE", "NE", "NUMBER", "FLOAT",
  "DATE_DATA", "ID", "PATH", "SSS", "LIKE_SSS", "STAR", "STRING_V",
  "UNARYMINUS", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "drop_index", "show_index", "create_table",
  "attr_def_list", "attr_def", "id_list", "number", "type", "ID_get",
  "insert", "row_list", "row", "value_list", "value", "insert_value",
  "like_value", "delete", "update", "update_list", "update_value",
  "select", "select_arith_expr", "select_expr_list", "select_attr",
  "aggregtion_attr", "alias", "rel_attr", "attr_list", "rel_list",
  "join_list", "join_condition_list", "having", "groupby", "where",
  "or_where", "condition_expr", "and_condition_list", "or_condition_list",
  "condition", "comOp", "like_comOp", "in_comOp", "exist_comOp",
  "is_null_comOp", "load_data", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333
};
# endif

#define YYPACT_NINF -236

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-236)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -236,   293,  -236,     6,   102,    49,   -45,   122,    51,    39,
      40,    22,    97,   108,   111,   116,   118,    84,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,   131,  -236,    95,    96,   165,
     105,   106,  -236,   141,   161,   163,   182,   183,   188,   141,
    -236,  -236,  -236,   -10,  -236,  -236,  -236,   103,     2,   147,
    -236,   208,   210,   190,  -236,   145,   151,   196,  -236,  -236,
    -236,  -236,  -236,   197,  -236,   218,   201,   174,   242,   244,
       4,    -2,   177,   214,   222,   227,  -236,   179,   180,  -236,
     141,   141,   141,   141,   141,   189,  -236,  -236,  -236,   198,
     220,   226,   215,    -7,   194,   216,   217,   225,  -236,  -236,
    -236,  -236,   270,   272,   270,  -236,   275,  -236,   276,  -236,
     277,  -236,   282,   147,  -236,   -31,   -31,  -236,  -236,   103,
     147,   306,   294,    57,   308,   255,   247,   314,   288,  -236,
      25,   136,   303,   253,   232,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,    74,  -236,    73,   305,   134,   269,  -236,
     -21,   192,   291,   310,  -236,    65,   267,  -236,   322,  -236,
     216,   328,   313,  -236,  -236,  -236,  -236,  -236,   315,   263,
     317,   270,   265,   296,   304,   226,   320,   294,   336,   323,
    -236,   -25,  -236,  -236,    66,   325,   307,  -236,  -236,  -236,
    -236,  -236,  -236,   169,   169,    57,  -236,   333,   333,  -236,
    -236,    65,   274,    25,  -236,   342,   280,   128,   344,   263,
    -236,   147,   279,    57,   295,  -236,  -236,   101,   332,   305,
    -236,  -236,  -236,  -236,  -236,  -236,  -236,   162,  -236,   103,
    -236,  -236,   291,   335,   337,  -236,   347,  -236,  -236,  -236,
     338,  -236,   263,  -236,   350,   339,   318,   321,   113,   301,
    -236,   297,  -236,   320,  -236,  -236,   320,   343,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  -236,    57,   326,    57,    57,
     232,  -236,  -236,   345,  -236,   291,  -236,  -236,  -236,   270,
    -236,  -236,   309,    57,  -236,   291,  -236
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    21,
      20,    15,    16,    17,    18,     9,    10,    11,    12,    13,
      14,     8,     5,     7,     6,     0,    19,     0,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
      57,    58,    61,    98,    59,    83,    80,    84,     0,    98,
      79,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,   100,
       0,     0,     0,     0,     0,     0,   102,    30,    29,     0,
       0,   114,     0,   114,     0,     0,     0,     0,    28,    33,
      81,    93,   103,     0,   103,    94,     0,    95,     0,    96,
       0,    97,     0,    98,    99,    75,    76,    78,    77,    85,
      98,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      36,     0,     0,     0,     0,    86,    88,    87,    89,    90,
      91,    92,   101,   105,    34,     0,    52,     0,     0,   139,
     117,     0,   119,     0,    66,     0,     0,    67,     0,    41,
       0,     0,     0,    45,    46,    47,    48,    49,    39,     0,
       0,   103,     0,     0,   114,   114,    55,     0,     0,     0,
     140,     0,   136,   137,     0,     0,   141,   129,   130,   131,
     132,   133,   134,     0,     0,     0,   115,     0,     0,    70,
      68,     0,     0,    36,    40,     0,     0,     0,     0,     0,
     104,    98,     0,     0,   112,    73,    74,     0,     0,    52,
      51,   118,   135,   138,    65,    64,   124,     0,   142,   117,
     123,   125,   119,     0,     0,    69,     0,    37,    35,    44,
       0,    42,     0,    31,     0,   105,     0,   116,   119,     0,
      72,     0,    62,    55,    54,    53,    55,     0,   120,   128,
      71,   143,    38,    43,    32,   106,     0,   107,     0,     0,
       0,    63,    56,     0,   126,   119,   108,   122,   121,   103,
     127,   109,   110,     0,   113,   119,   111
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  -236,   154,   199,  -209,  -236,
    -236,  -236,  -236,   135,   184,  -235,  -144,  -236,  -236,  -236,
    -236,  -236,   164,  -145,    -5,  -236,   -43,  -236,   -52,   -80,
    -108,   117,    99,  -236,  -236,  -236,   -94,  -236,   -49,  -229,
    -236,  -197,  -236,  -236,  -236,  -236,  -236,  -236
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   172,   140,   218,   250,
     178,   141,    32,   188,   156,   228,    56,   263,   236,    33,
      34,   103,   210,    35,   160,    58,   113,    59,    89,    60,
     145,   184,   185,   277,   294,   260,   134,   225,   161,   206,
     257,   162,   203,   194,   195,   163,   204,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      57,   114,   114,   114,   114,   114,   147,    96,   242,   137,
     254,   186,   189,   268,   136,    37,   232,    38,   111,   191,
     192,   209,    87,    94,   110,    92,   258,    61,   282,   133,
     169,   283,   233,    90,    91,    92,   193,    95,    80,   116,
     118,   120,   122,   273,    86,    93,   170,    44,    45,    46,
      47,    48,    88,    42,    39,    93,   291,    64,    90,    91,
      92,    42,   243,   244,   181,   171,   296,   209,    43,    42,
      53,   152,    65,   220,   112,    66,   157,    42,   153,   285,
      93,   287,   288,   262,   208,   125,   126,   127,   128,   129,
     224,   226,   267,   266,    67,   182,   295,   158,    44,    45,
      46,    47,    48,    68,    49,    42,    44,    45,    46,    47,
      48,    40,    49,    41,    69,   159,   183,    70,    50,    51,
      52,    53,    71,    54,    72,    55,    50,    51,    52,    53,
      73,    54,    62,    63,    50,    51,    52,    74,    42,    54,
     234,   235,    50,    51,    52,    42,     5,    54,   251,   252,
     205,   279,    80,    43,   240,   241,   261,    90,    91,    92,
      43,   173,   174,   175,   176,   177,    42,    75,    76,   255,
      50,    51,    52,    42,     5,    54,    77,    78,    79,    93,
      81,   292,    82,    44,    45,    46,    47,    48,   157,    49,
      44,    45,    46,    47,    48,   196,    49,   115,   239,   239,
     289,    83,    84,    50,    51,    52,    53,    85,    54,    88,
      50,    51,    52,    53,    97,    54,    98,   100,    44,    45,
      46,    47,    48,   101,    49,    99,    44,    45,    46,    47,
      48,    50,    51,    52,   117,   102,    54,   105,    50,    51,
      52,    53,   119,    54,   104,   106,   107,   121,   108,    53,
     109,   123,   124,   112,   132,   197,   198,   199,   200,   201,
     202,   130,   133,    44,    45,    46,    47,    48,   138,   143,
     131,    44,    45,    46,    47,    48,    44,    45,    46,    47,
      48,    44,    45,    46,    47,    48,    53,   135,   139,   142,
     112,   144,   146,     2,    53,   148,   149,   150,   112,    53,
       3,     4,   151,   112,    53,     5,     6,     7,     8,     9,
      10,    11,   154,   155,   164,    12,    13,    14,   165,   166,
     167,   168,   179,    15,    16,   180,   187,   190,   205,   207,
     211,   212,   214,   215,   216,   217,   219,   221,    17,   222,
     223,   227,   230,   231,   237,     5,   246,   238,   248,   249,
     253,   256,   264,   271,   259,   269,   274,   270,   272,   278,
     182,   280,   276,   284,   265,   290,   281,   247,   183,   213,
     293,   229,   275,     0,     0,   245,   286
};

static const yytype_int16 yycheck[] =
{
       5,    81,    82,    83,    84,    85,   114,    59,   205,   103,
     219,   155,   157,   242,    21,     9,    41,    11,    20,    40,
      41,   165,    32,    21,    20,    56,   223,    72,   263,    36,
       5,   266,    57,    54,    55,    56,    57,    35,    43,    82,
      83,    84,    85,   252,    49,    76,    21,    49,    50,    51,
      52,    53,    62,     4,    48,    76,   285,     6,    54,    55,
      56,     4,   207,   208,   144,    40,   295,   211,    19,     4,
      72,   123,    33,   181,    76,    35,    19,     4,   130,   276,
      76,   278,   279,   227,    19,    90,    91,    92,    93,    94,
     184,   185,   237,   237,    72,    21,   293,    40,    49,    50,
      51,    52,    53,     6,    55,     4,    49,    50,    51,    52,
      53,     9,    55,    11,     6,    58,    42,     6,    69,    70,
      71,    72,     6,    74,     6,    76,    69,    70,    71,    72,
      46,    74,    10,    11,    69,    70,    71,     6,     4,    74,
      74,    75,    69,    70,    71,     4,    12,    74,    20,    21,
      37,    38,   157,    19,   203,   204,    55,    54,    55,    56,
      19,    25,    26,    27,    28,    29,     4,    72,    72,   221,
      69,    70,    71,     4,    12,    74,    11,    72,    72,    76,
      19,   289,    19,    49,    50,    51,    52,    53,    19,    55,
      49,    50,    51,    52,    53,     3,    55,    20,   203,   204,
     280,    19,    19,    69,    70,    71,    72,    19,    74,    62,
      69,    70,    71,    72,     6,    74,     6,    72,    49,    50,
      51,    52,    53,    72,    55,    35,    49,    50,    51,    52,
      53,    69,    70,    71,    20,    39,    74,    19,    69,    70,
      71,    72,    20,    74,    47,    44,    72,    20,     6,    72,
       6,    72,    72,    76,    34,    63,    64,    65,    66,    67,
      68,    72,    36,    49,    50,    51,    52,    53,    74,    44,
      72,    49,    50,    51,    52,    53,    49,    50,    51,    52,
      53,    49,    50,    51,    52,    53,    72,    72,    72,    72,
      76,    21,    20,     0,    72,    20,    20,    20,    76,    72,
       7,     8,    20,    76,    72,    12,    13,    14,    15,    16,
      17,    18,     6,    19,     6,    22,    23,    24,    63,    72,
       6,    33,    19,    30,    31,    72,    21,    58,    37,    19,
      63,     9,     4,    20,    19,    72,    19,    72,    45,    43,
      36,    21,     6,    20,    19,    12,    72,    40,     6,    69,
       6,    72,    20,     6,    59,    20,     6,    20,    20,    38,
      21,    60,    44,    20,   229,    20,    69,   213,    42,   170,
      61,   187,   255,    -1,    -1,   211,   277
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    80,     0,     7,     8,    12,    13,    14,    15,    16,
      17,    18,    22,    23,    24,    30,    31,    45,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   101,   108,   109,   112,   136,     9,    11,    48,
       9,    11,     4,    19,    49,    50,    51,    52,    53,    55,
      69,    70,    71,    72,    74,    76,   105,   113,   114,   116,
     118,    72,    10,    11,     6,    33,    35,    72,     6,     6,
       6,     6,     6,    46,     6,    72,    72,    11,    72,    72,
     113,    19,    19,    19,    19,    19,   113,    32,    62,   117,
      54,    55,    56,    76,    21,    35,   117,     6,     6,    35,
      72,    72,    39,   110,    47,    19,    44,    72,     6,     6,
      20,    20,    76,   115,   118,    20,   115,    20,   115,    20,
     115,    20,   115,    72,    72,   113,   113,   113,   113,   113,
      72,    72,    34,    36,   125,    72,    21,   125,    74,    72,
      96,   100,    72,    44,    21,   119,    20,   119,    20,    20,
      20,    20,   117,   117,     6,    19,   103,    19,    40,    58,
     113,   127,   130,   134,     6,    63,    72,     6,    33,     5,
      21,    40,    95,    25,    26,    27,    28,    29,    99,    19,
      72,   118,    21,    42,   120,   121,   105,    21,   102,   112,
      58,    40,    41,    57,   132,   133,     3,    63,    64,    65,
      66,    67,    68,   131,   135,    37,   128,    19,    19,   105,
     111,    63,     9,    96,     4,    20,    19,    72,    97,    19,
     119,    72,    43,    36,   125,   126,   125,    21,   104,   103,
       6,    20,    41,    57,    74,    75,   107,    19,    40,   113,
     127,   127,   130,   112,   112,   111,    72,    95,     6,    69,
      98,    20,    21,     6,    97,   117,    72,   129,   130,    59,
     124,    55,   105,   106,    20,   102,   105,   112,   128,    20,
      20,     6,    20,    97,     6,   120,    44,   122,    38,    38,
      60,    69,   104,   104,    20,   130,   121,   130,   130,   118,
      20,   128,   119,    61,   123,   130,   128
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    91,    92,    93,    94,    95,    95,    96,    96,
      96,    96,    97,    97,    98,    99,    99,    99,    99,    99,
     100,   101,   102,   102,   103,   104,   104,   105,   105,   105,
     105,   105,   106,   106,   107,   107,   108,   109,   110,   110,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   115,   115,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     123,   123,   124,   124,   125,   125,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   130,   130,   130,   130,   131,
     131,   131,   131,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   136
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     8,     9,     4,     5,     8,     0,     3,     5,     2,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     7,     0,     3,     4,     0,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     5,     5,     4,     5,
       1,     3,     8,     7,     7,     3,     3,     3,     3,     1,
       1,     3,     2,     1,     1,     3,     2,     2,     4,     4,
       4,     4,     4,     3,     3,     3,     3,     3,     0,     2,
       2,     4,     2,     0,     3,     0,     4,     4,     5,     3,
       0,     3,     0,     5,     0,     3,     2,     1,     3,     0,
       3,     3,     3,     3,     3,     3,     5,     6,     4,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     1,
       2,     1,     2,     8
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, void *scanner)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *scanner)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 234 "yacc_sql.y" /* yacc.c:1646  */
    {
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->ssql->sstr.selection = *(yyvsp[-1].select1);
		delete (yyvsp[-1].select1);
	  }
#line 1627 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 259 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1635 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 264 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1643 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 269 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1651 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 275 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1659 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 281 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1667 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 287 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1675 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 293 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string1));
    }
#line 1684 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 299 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1692 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 305 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string1));
    }
#line 1701 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 313 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), false);
			delete (yyvsp[-1].ids1);
		}
#line 1711 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 319 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), true);
			delete (yyvsp[-1].ids1);
		}
#line 1721 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 328 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string1));
		}
#line 1730 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 335 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_SHOW_INDEX;//"show_index";
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string1));
		}
#line 1739 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 342 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string1));
		}
#line 1749 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 350 "yacc_sql.y" /* yacc.c:1646  */
    {    }
#line 1755 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 355 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[-3].number1)), (yyvsp[-1].number1));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;

		}
#line 1770 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 366 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			if ((yyvsp[0].number1) == DATES) {
				attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[0].number1)), 12);
			} else if ((yyvsp[0].number1) == TEXTS) {
				attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[0].number1)), 4096);
			} else {
				attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[0].number1)), 4);
			}
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
		}
#line 1790 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 382 "yacc_sql.y" /* yacc.c:1646  */
    {}
#line 1796 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 384 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->ssql->sstr.create_table.attribute_count-1].nullable = true;
		}
#line 1804 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 391 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ids1) = new IdList();
		(yyval.ids1)->push_front((yyvsp[-1].string1));
	}
#line 1813 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 396 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ids1) = (yyvsp[0].ids1);
		(yyval.ids1)->push_front((yyvsp[-2].string1));
	}
#line 1822 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 403 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number1) = atoi((yyvsp[0].string1));}
#line 1828 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 406 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=INTS; }
#line 1834 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 407 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=CHARS; }
#line 1840 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 408 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=FLOATS; }
#line 1846 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 409 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=DATES; }
#line 1852 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 410 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=TEXTS; }
#line 1858 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 414 "yacc_sql.y" /* yacc.c:1646  */
    {
		char *temp=(yyvsp[0].string1); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1867 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 423 "yacc_sql.y" /* yacc.c:1646  */
    {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-4].string1));
    }
#line 1883 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 439 "yacc_sql.y" /* yacc.c:1646  */
    {	/* do nothing here */	}
#line 1889 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 442 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[-1].values1)->push_front(*(yyvsp[-2].value1));
		inserts_row_init(&CONTEXT->ssql->sstr.insertion.rows[CONTEXT->ssql->sstr.insertion.row_num], *(yyvsp[-1].values1));
		(CONTEXT->ssql->sstr.insertion.row_num)++;

		delete (yyvsp[-2].value1);
		delete (yyvsp[-1].values1);
	}
#line 1902 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 453 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.values1) = new ValueList();
	}
#line 1910 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 456 "yacc_sql.y" /* yacc.c:1646  */
    { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
		(yyval.values1) = (yyvsp[0].values1);
		(yyval.values1)->push_front(*(yyvsp[-1].value1));

		delete (yyvsp[-1].value1);
	}
#line 1922 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 465 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), atoi((yyvsp[0].string1)), (yyvsp[0].string1));
		}
#line 1931 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 469 "yacc_sql.y" /* yacc.c:1646  */
    {
  		(yyval.value1) = new Value();
		value_init_float((yyval.value1), (float)(atof((yyvsp[0].string1))), (yyvsp[0].string1));
		}
#line 1940 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 473 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
		}
#line 1950 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 478 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.value1) = new Value();
		value_init_null((yyval.value1));
	}
#line 1959 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 482 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
		value_init_date((yyval.value1), (yyvsp[0].string1));
	}
#line 1969 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 490 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.value1) = (yyvsp[0].value1);
	}
#line 1977 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 493 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), -atoi((yyvsp[0].string1)), (yyvsp[0].string1));
	}
#line 1986 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 500 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 1996 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 505 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 2006 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 514 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string1));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, *(yyvsp[-1].conditions1));

			delete (yyvsp[-1].conditions1);
    }
#line 2018 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 524 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string1), *(yyvsp[-1].conditions1));
			delete (yyvsp[-1].conditions1);
		}
#line 2028 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 533 "yacc_sql.y" /* yacc.c:1646  */
    {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2037 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 538 "yacc_sql.y" /* yacc.c:1646  */
    {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2046 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 545 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_value((yyval.updatevalue1), (yyvsp[0].value1));
		delete (yyvsp[0].value1);
	}
#line 2056 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 550 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_select((yyval.updatevalue1), (yyvsp[-1].select1));
		delete (yyvsp[-1].select1);
	}
#line 2066 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 559 "yacc_sql.y" /* yacc.c:1646  */
    {
			(yyval.select1) = new Selects();
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			Relation rel;
			relation_name_init(&rel, (yyvsp[-4].string1), (yyvsp[-3].string1));
			(yyvsp[-2].relations1)->push_back(rel);
			selects_append_relation((yyval.select1), *(yyvsp[-2].relations1));

			selects_append_select_exprs((yyval.select1), *(yyvsp[-6].selectexprs1));

            selects_append_joins((yyval.select1), JoinList());

			selects_append_conditions((yyval.select1), *(yyvsp[-1].conditions1));

			selects_append_groupby((yyval.select1), (yyvsp[0].groupby1));

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-6].selectexprs1);
			delete (yyvsp[-1].conditions1);
			delete (yyvsp[-2].relations1);

	}
#line 2094 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 583 "yacc_sql.y" /* yacc.c:1646  */
    {
			(yyval.select1) = new Selects();
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			Relation rel;
			relation_name_init(&rel, (yyvsp[-3].string1), (yyvsp[-2].string1));
			(yyvsp[-1].relations1)->push_back(rel);
			selects_append_relation((yyval.select1), *(yyvsp[-1].relations1));

			selects_append_select_exprs((yyval.select1), *(yyvsp[-5].selectexprs1));

            selects_append_joins((yyval.select1), JoinList());

			selects_append_conditions((yyval.select1), *(yyvsp[0].conditions1), true);

			selects_append_groupby((yyval.select1), nullptr);

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-5].selectexprs1);
			delete (yyvsp[0].conditions1);
			delete (yyvsp[-1].relations1);

	}
#line 2122 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 606 "yacc_sql.y" /* yacc.c:1646  */
    {
		// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			(yyval.select1) = new Selects();
			Relation rel;
			relation_name_init(&rel, (yyvsp[-3].string1), (yyvsp[-2].string1));
			RelationList relation_list;
			relation_list.push_back(rel);
			selects_append_relation((yyval.select1), relation_list);

			selects_append_select_exprs((yyval.select1), *(yyvsp[-5].selectexprs1));

            selects_append_joins((yyval.select1), *(yyvsp[-1].joins1));

			selects_append_conditions((yyval.select1), *(yyvsp[0].conditions1));

			selects_append_groupby((yyval.select1), nullptr);

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-5].selectexprs1);
			delete (yyvsp[-1].joins1);
			delete (yyvsp[0].conditions1);
	}
#line 2150 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 633 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_ADD);
	}
#line 2159 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 637 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_SUB);
	}
#line 2168 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 641 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_MUL);
	}
#line 2177 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 645 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_DIV);
	}
#line 2186 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 649 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_attr_init((yyval.selectexpr1), (yyvsp[0].attr1));
	}
#line 2195 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 653 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_value_init((yyval.selectexpr1), (yyvsp[0].value1));
	}
#line 2204 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 657 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = (yyvsp[-1].selectexpr1);
		(yyval.selectexpr1)->is_brace = true;
	}
#line 2213 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 661 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), nullptr, (yyvsp[0].selectexpr1), ARITH_NEG);
	}
#line 2222 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 668 "yacc_sql.y" /* yacc.c:1646  */
    {
		RelAttr *attr = new RelAttr();
		relation_attr_init_with_aggregation(attr, NULL, "*", AGG_NONE, true);
		SelectExpr expr;
		select_attr_init(&expr, attr);
		(yyval.selectexprs1) = new SelectExprList();
		(yyval.selectexprs1)->push_back(expr);
	}
#line 2235 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 676 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexprs1) = new SelectExprList();
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2245 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 681 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexprs1) = (yyvsp[-2].selectexprs1);
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2255 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 689 "yacc_sql.y" /* yacc.c:1646  */
    {  
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, NULL, "*", AGG_NONE, true);
			(yyvsp[0].attrs1)->push_front(attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
		}
#line 2266 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 695 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].attrs1)->push_front(*(yyvsp[-1].attr1));
		// selects_append_attribute(&CONTEXT->ssql->sstr.selection, *$2);
		delete((yyvsp[-1].attr1));
		(yyval.attrs1) = (yyvsp[0].attrs1);
	}
#line 2277 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 704 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_copy((yyval.attr1), attr, AGG_MAX);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2292 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 714 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_copy((yyval.attr1), attr, AGG_MIN);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2307 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 724 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_copy((yyval.attr1), attr, AGG_SUM);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2322 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 734 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_copy((yyval.attr1), attr, AGG_COUNT);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2337 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 744 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_copy((yyval.attr1), attr, AGG_AVG);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2352 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 754 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2361 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 758 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2370 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 762 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2379 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 766 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2388 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 770 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2397 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 777 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.string1) = nullptr;
	}
#line 2405 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 780 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.string1) = (yyvsp[0].string1);
	}
#line 2413 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 786 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, (yyvsp[-1].string1), AGG_NONE,true);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2425 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 793 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), (yyvsp[-3].string1), (yyvsp[-1].string1), AGG_NONE,true);

		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2438 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 801 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = (yyvsp[-1].attr1);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2449 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 810 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attrs1) = new AttrList();
	}
#line 2457 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 813 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attrs1) = (yyvsp[0].attrs1);
		(yyval.attrs1)->push_front(*(yyvsp[-1].attr1));
		delete (yyvsp[-1].attr1);
	}
#line 2467 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 821 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.relations1) = new RelationList();
	}
#line 2475 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 824 "yacc_sql.y" /* yacc.c:1646  */
    {	
		Relation rel;
		relation_name_init(&rel, (yyvsp[-2].string1), (yyvsp[-1].string1));
		(yyval.relations1) = (yyvsp[0].relations1);
		(yyval.relations1)->push_back(rel);
	}
#line 2486 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 833 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.joins1) = new JoinList();
		Join join;
		join_set_relation(&join, (yyvsp[-1].string1));
		join_append_conditions(&join, *(yyvsp[0].conditions1));
		(yyval.joins1)->push_back(join);

		delete (yyvsp[0].conditions1);
	}
#line 2500 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 842 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.joins1) = (yyvsp[0].joins1);
		Join join;
		join_set_relation(&join, (yyvsp[-2].string1));
		join_append_conditions(&join, *(yyvsp[-1].conditions1));
		(yyval.joins1)->push_front(join);

		delete (yyvsp[-1].conditions1);
	}
#line 2514 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 854 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));

		delete (yyvsp[-1].condition1);
	}
#line 2525 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 863 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2533 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 866 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2543 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 875 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.groupby1) = nullptr;
	}
#line 2551 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 878 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.groupby1) = new GroupBy();
		(yyvsp[-1].attrs1)->push_front(*(yyvsp[-2].attr1));
		delete (yyvsp[-2].attr1);
		group_init((yyval.groupby1), *(yyvsp[-1].attrs1), *(yyvsp[0].conditions1));
		delete (yyvsp[-1].attrs1);
		delete (yyvsp[0].conditions1);
	}
#line 2564 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 889 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2572 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 892 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2582 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 900 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
	}
#line 2590 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 905 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_expr((yyval.conditionexpr1), (yyvsp[0].selectexpr1));
	}
#line 2599 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 910 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_sq((yyval.conditionexpr1), (yyvsp[-1].select1));
	}
#line 2608 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 916 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2616 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 919 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2626 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 927 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
		(yyval.conditions1)->push_back(*(yyvsp[-2].condition1));
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[-2].condition1);
		delete (yyvsp[0].condition1);
	}
#line 2638 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 934 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[-2].conditions1);
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[0].condition1);
	}
#line 2648 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 942 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2659 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 949 "yacc_sql.y" /* yacc.c:1646  */
    {		
		ConditionExpr left_cexpr;
		condition_expr_init_expr(&left_cexpr, (yyvsp[-2].selectexpr1));
		
		SelectExpr *sexpr = new SelectExpr();
		select_value_init(sexpr, (yyvsp[0].value1));
		ConditionExpr right_cexpr;
		condition_expr_init_expr(&right_cexpr, sexpr);

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)) ,&left_cexpr, &right_cexpr);
    }
#line 2676 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 962 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2687 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 968 "yacc_sql.y" /* yacc.c:1646  */
    {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, (yyvsp[-4].selectexpr1));

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2702 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 979 "yacc_sql.y" /* yacc.c:1646  */
    {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, (yyvsp[-5].selectexpr1));

		(yyvsp[-1].values1)->push_front(*(yyvsp[-2].value1));
		ConditionExpr right_expr;
		condition_expr_init_valuelist(&right_expr, (yyvsp[-1].values1));
		delete (yyvsp[-2].value1);

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-4].comp1)), &left_expr, &right_expr);
	}
#line 2719 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 991 "yacc_sql.y" /* yacc.c:1646  */
    {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, nullptr);

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2734 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1004 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = EQUAL_TO; }
#line 2740 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1005 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LESS_THAN; }
#line 2746 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1006 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = GREAT_THAN; }
#line 2752 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1007 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LESS_EQUAL; }
#line 2758 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1008 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = GREAT_EQUAL; }
#line 2764 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1009 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_EQUAL; }
#line 2770 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1013 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = UNLIKE_SCH; }
#line 2776 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1014 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LIKE_SCH; }
#line 2782 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1018 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = IN_SQ; }
#line 2788 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1019 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_IN_SQ; }
#line 2794 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1023 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = EXISTS_SQ; }
#line 2800 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1024 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_EXISTS_SQ; }
#line 2806 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1027 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = IS_NULL; }
#line 2812 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1028 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = IS_NOT_NULL; }
#line 2818 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1033 "yacc_sql.y" /* yacc.c:1646  */
    {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string1), (yyvsp[-4].string1));
		}
#line 2827 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;


#line 2831 "yacc_sql.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1038 "yacc_sql.y" /* yacc.c:1906  */

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
