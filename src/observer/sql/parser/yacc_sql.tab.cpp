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
#define YYLAST   381

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  302

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
     653,   657,   661,   668,   679,   684,   692,   701,   710,   720,
     730,   740,   750,   760,   764,   768,   772,   776,   783,   786,
     789,   795,   802,   810,   817,   826,   829,   837,   840,   849,
     858,   870,   879,   882,   891,   894,   905,   908,   916,   921,
     925,   932,   935,   943,   950,   957,   964,   977,   984,   994,
    1007,  1020,  1021,  1022,  1023,  1024,  1025,  1029,  1030,  1034,
    1035,  1039,  1040,  1043,  1044,  1048
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

#define YYPACT_NINF -230

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-230)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -230,   315,  -230,     3,    14,    48,   -37,    62,    27,    21,
      12,   -12,    60,    68,    77,    79,    98,    22,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,   103,  -230,    -8,    41,   130,
      81,    83,  -230,   138,   139,   146,   149,   151,   152,   138,
    -230,  -230,  -230,   -19,  -230,   -38,  -230,   -35,     7,   -38,
    -230,   143,   166,   141,  -230,   107,   120,   156,  -230,  -230,
    -230,  -230,  -230,   154,  -230,   175,   158,   134,   207,   215,
       2,   191,   203,   208,   242,   248,  -230,   -40,   150,  -230,
    -230,  -230,   138,   138,   138,   138,   138,   173,  -230,  -230,
    -230,   192,   193,   202,   194,     9,   195,   198,   201,   221,
    -230,  -230,  -230,  -230,   -38,   254,   255,  -230,   257,  -230,
     258,  -230,   261,  -230,   262,   -38,   -38,  -230,   -39,   -39,
    -230,  -230,   -35,   -38,   283,   264,    76,   284,   233,   236,
     303,   278,  -230,    10,   277,   291,   240,   255,  -230,   147,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,     6,  -230,   104,
     292,   111,   259,  -230,   231,   183,   279,   300,  -230,    36,
     263,  -230,   312,  -230,   198,   321,   314,  -230,  -230,  -230,
    -230,  -230,   316,   268,   317,  -230,   255,   269,   299,   307,
     202,   323,   264,   341,   328,  -230,    18,  -230,  -230,    58,
     330,   310,  -230,  -230,  -230,  -230,  -230,  -230,   165,   165,
      76,  -230,   339,   339,  -230,  -230,    36,   280,    10,  -230,
     347,   285,   118,   349,   268,  -230,   -38,   286,    76,   297,
    -230,  -230,    66,   337,   292,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,   155,  -230,   -35,  -230,  -230,   279,   342,   343,
    -230,   353,  -230,  -230,  -230,   344,  -230,   268,  -230,   355,
     345,   324,   327,   106,   309,  -230,   298,  -230,   323,  -230,
    -230,   323,   350,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,    76,   329,    76,    76,   147,  -230,  -230,   352,  -230,
     279,  -230,  -230,  -230,   255,  -230,  -230,   313,    76,  -230,
     279,  -230
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
      57,    58,    61,    98,    59,    98,    80,    84,     0,    98,
      79,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,   100,
     101,    83,     0,     0,     0,     0,     0,     0,   104,    30,
      29,     0,     0,   116,     0,   116,     0,     0,     0,     0,
      28,    33,    81,    93,    98,     0,   105,    94,     0,    95,
       0,    96,     0,    97,     0,    98,    98,    99,    75,    76,
      78,    77,    85,    98,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    36,     0,     0,     0,   105,    88,     0,
      87,    89,    90,    91,    92,   102,   103,   107,    34,     0,
      52,     0,     0,   141,   119,     0,   121,     0,    66,     0,
       0,    67,     0,    41,     0,     0,     0,    45,    46,    47,
      48,    49,    39,     0,     0,    86,   105,     0,     0,   116,
     116,    55,     0,     0,     0,   142,     0,   138,   139,     0,
       0,   143,   131,   132,   133,   134,   135,   136,     0,     0,
       0,   117,     0,     0,    70,    68,     0,     0,    36,    40,
       0,     0,     0,     0,     0,   106,    98,     0,     0,   114,
      73,    74,     0,     0,    52,    51,   120,   137,   140,    65,
      64,   126,     0,   144,   119,   125,   127,   121,     0,     0,
      69,     0,    37,    35,    44,     0,    42,     0,    31,     0,
     107,     0,   118,   121,     0,    72,     0,    62,    55,    54,
      53,    55,     0,   122,   130,    71,   145,    38,    43,    32,
     108,     0,   109,     0,     0,     0,    63,    56,     0,   128,
     121,   110,   124,   123,   105,   129,   111,   112,     0,   115,
     121,   113
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,   157,   199,  -208,  -230,
    -230,  -230,  -230,   142,   185,  -157,  -130,  -230,  -230,  -230,
    -230,  -230,   162,  -150,    -5,  -230,   148,  -230,   -49,   -80,
    -140,   119,    99,  -230,  -230,  -230,   -96,  -230,   -57,  -229,
    -230,  -202,  -230,  -230,  -230,  -230,  -230,  -230
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   176,   143,   223,   255,
     182,   144,    32,   193,   160,   233,    56,   268,   241,    33,
      34,   105,   215,    35,   164,    58,   115,    59,    90,    60,
     150,   189,   190,   282,   299,   265,   137,   230,   165,   211,
     262,   166,   208,   199,   200,   167,   209,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      57,   116,   116,   116,   116,   116,    91,   185,   247,   140,
      98,   194,    37,    87,    38,   173,   259,    94,   273,    92,
      93,    94,   112,    40,    88,    41,   263,   187,    96,   191,
     139,   174,   125,    64,    89,    61,   126,    95,    80,   214,
      42,    95,    97,    88,    86,   136,   225,    66,   188,   278,
     175,    39,    42,    89,    65,   213,    92,    93,    94,   237,
      67,   296,   248,   249,    75,   147,    68,    43,    73,   186,
      42,   301,    62,    63,    69,   238,   155,   156,    95,   290,
      42,   292,   293,    70,   157,    71,   214,   128,   129,   130,
     131,   132,   272,   229,   231,   161,   300,    44,    45,    46,
      47,    48,   267,    49,    72,    50,    51,    52,    42,    74,
      54,   287,   271,    76,   288,    42,   162,    50,    51,    52,
      53,   266,    54,     5,    55,    44,    45,    46,    47,    48,
      43,    49,   239,   240,   163,    50,    51,    52,   256,   257,
      54,    77,    42,   210,   284,    50,    51,    52,    53,    99,
      54,   245,   246,    78,   297,    79,    80,    43,    81,    42,
      44,    45,    46,    47,    48,    82,    49,     5,    83,    42,
      84,    85,   100,    50,    51,    52,   101,   260,    54,   102,
      50,    51,    52,    53,   161,    54,   201,    44,    45,    46,
      47,    48,   103,    49,   107,   104,    44,    45,    46,    47,
      48,   106,   108,   244,   244,   294,   109,    50,    51,    52,
      53,   113,    54,   110,    44,    45,    46,    47,    48,    53,
      49,   111,   127,   117,    50,    51,    52,   135,   119,    54,
     118,   120,   122,   124,    50,    51,    52,    53,   136,    54,
      44,    45,    46,    47,    48,   133,   202,   203,   204,   205,
     206,   207,    44,    45,    46,    47,    48,    44,    45,    46,
      47,    48,   121,    53,   134,   146,   138,   114,   123,   141,
     142,   196,   197,   145,   148,    53,   149,   151,   152,   114,
      53,   153,   154,   159,   114,    92,    93,    94,   198,   158,
     168,    44,    45,    46,    47,    48,   169,    44,    45,    46,
      47,    48,   177,   178,   179,   180,   181,    95,   170,   171,
     183,   172,   184,   192,    53,     2,   210,   195,   114,   212,
      53,   217,     3,     4,   114,   219,   216,     5,     6,     7,
       8,     9,    10,    11,   220,   221,   224,    12,    13,    14,
     222,   226,   227,   228,   232,    15,    16,   235,   236,   242,
     243,     5,   251,   253,   254,   258,   264,   269,   261,   276,
      17,   279,   274,   275,   277,   283,   187,   286,   281,   285,
     289,   188,   295,   218,   298,   252,   270,   234,   250,   280,
       0,   291
};

static const yytype_int16 yycheck[] =
{
       5,    81,    82,    83,    84,    85,    55,   147,   210,   105,
      59,   161,     9,    32,    11,     5,   224,    56,   247,    54,
      55,    56,    20,     9,    62,    11,   228,    21,    21,   159,
      21,    21,    72,     6,    72,    72,    76,    76,    43,   169,
       4,    76,    35,    62,    49,    36,   186,    35,    42,   257,
      40,    48,     4,    72,    33,    19,    54,    55,    56,    41,
      72,   290,   212,   213,    72,   114,     6,    19,    46,   149,
       4,   300,    10,    11,     6,    57,   125,   126,    76,   281,
       4,   283,   284,     6,   133,     6,   216,    92,    93,    94,
      95,    96,   242,   189,   190,    19,   298,    49,    50,    51,
      52,    53,   232,    55,     6,    69,    70,    71,     4,     6,
      74,   268,   242,    72,   271,     4,    40,    69,    70,    71,
      72,    55,    74,    12,    76,    49,    50,    51,    52,    53,
      19,    55,    74,    75,    58,    69,    70,    71,    20,    21,
      74,    11,     4,    37,    38,    69,    70,    71,    72,     6,
      74,   208,   209,    72,   294,    72,   161,    19,    19,     4,
      49,    50,    51,    52,    53,    19,    55,    12,    19,     4,
      19,    19,     6,    69,    70,    71,    35,   226,    74,    72,
      69,    70,    71,    72,    19,    74,     3,    49,    50,    51,
      52,    53,    72,    55,    19,    39,    49,    50,    51,    52,
      53,    47,    44,   208,   209,   285,    72,    69,    70,    71,
      72,    20,    74,     6,    49,    50,    51,    52,    53,    72,
      55,     6,    72,    20,    69,    70,    71,    34,    20,    74,
      82,    83,    84,    85,    69,    70,    71,    72,    36,    74,
      49,    50,    51,    52,    53,    72,    63,    64,    65,    66,
      67,    68,    49,    50,    51,    52,    53,    49,    50,    51,
      52,    53,    20,    72,    72,    44,    72,    76,    20,    74,
      72,    40,    41,    72,    20,    72,    21,    20,    20,    76,
      72,    20,    20,    19,    76,    54,    55,    56,    57,     6,
       6,    49,    50,    51,    52,    53,    63,    49,    50,    51,
      52,    53,    25,    26,    27,    28,    29,    76,    72,     6,
      19,    33,    72,    21,    72,     0,    37,    58,    76,    19,
      72,     9,     7,     8,    76,     4,    63,    12,    13,    14,
      15,    16,    17,    18,    20,    19,    19,    22,    23,    24,
      72,    72,    43,    36,    21,    30,    31,     6,    20,    19,
      40,    12,    72,     6,    69,     6,    59,    20,    72,     6,
      45,     6,    20,    20,    20,    38,    21,    69,    44,    60,
      20,    42,    20,   174,    61,   218,   234,   192,   216,   260,
      -1,   282
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
     113,    19,    19,    19,    19,    19,   113,    32,    62,    72,
     117,   117,    54,    55,    56,    76,    21,    35,   117,     6,
       6,    35,    72,    72,    39,   110,    47,    19,    44,    72,
       6,     6,    20,    20,    76,   115,   118,    20,   115,    20,
     115,    20,   115,    20,   115,    72,    76,    72,   113,   113,
     113,   113,   113,    72,    72,    34,    36,   125,    72,    21,
     125,    74,    72,    96,   100,    72,    44,   117,    20,    21,
     119,    20,    20,    20,    20,   117,   117,   117,     6,    19,
     103,    19,    40,    58,   113,   127,   130,   134,     6,    63,
      72,     6,    33,     5,    21,    40,    95,    25,    26,    27,
      28,    29,    99,    19,    72,   119,   118,    21,    42,   120,
     121,   105,    21,   102,   112,    58,    40,    41,    57,   132,
     133,     3,    63,    64,    65,    66,    67,    68,   131,   135,
      37,   128,    19,    19,   105,   111,    63,     9,    96,     4,
      20,    19,    72,    97,    19,   119,    72,    43,    36,   125,
     126,   125,    21,   104,   103,     6,    20,    41,    57,    74,
      75,   107,    19,    40,   113,   127,   127,   130,   112,   112,
     111,    72,    95,     6,    69,    98,    20,    21,     6,    97,
     117,    72,   129,   130,    59,   124,    55,   105,   106,    20,
     102,   105,   112,   128,    20,    20,     6,    20,    97,     6,
     120,    44,   122,    38,    38,    60,    69,   104,   104,    20,
     130,   121,   130,   130,   118,    20,   128,   119,    61,   123,
     130,   128
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
     117,   118,   118,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   123,   124,   124,   125,   125,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   130,   130,   130,
     130,   131,   131,   131,   131,   131,   131,   132,   132,   133,
     133,   134,   134,   135,   135,   136
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
       1,     3,     2,     2,     1,     3,     3,     2,     4,     4,
       4,     4,     4,     3,     3,     3,     3,     3,     0,     2,
       1,     2,     4,     4,     2,     0,     3,     0,     4,     4,
       5,     3,     0,     3,     0,     5,     0,     3,     2,     1,
       3,     0,     3,     3,     3,     3,     3,     3,     5,     6,
       4,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     1,     2,     1,     2,     8
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
#line 1632 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 259 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1640 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 264 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1648 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 269 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1656 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 275 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1664 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 281 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1672 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 287 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1680 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 293 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string1));
    }
#line 1689 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 299 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1697 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 305 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string1));
    }
#line 1706 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 313 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), false);
			delete (yyvsp[-1].ids1);
		}
#line 1716 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 319 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), true);
			delete (yyvsp[-1].ids1);
		}
#line 1726 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 328 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string1));
		}
#line 1735 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 335 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_SHOW_INDEX;//"show_index";
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string1));
		}
#line 1744 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 342 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string1));
		}
#line 1754 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 350 "yacc_sql.y" /* yacc.c:1646  */
    {    }
#line 1760 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 1775 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 1795 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 382 "yacc_sql.y" /* yacc.c:1646  */
    {}
#line 1801 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 384 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->ssql->sstr.create_table.attribute_count-1].nullable = true;
		}
#line 1809 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 391 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ids1) = new IdList();
		(yyval.ids1)->push_front((yyvsp[-1].string1));
	}
#line 1818 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 396 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ids1) = (yyvsp[0].ids1);
		(yyval.ids1)->push_front((yyvsp[-2].string1));
	}
#line 1827 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 403 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number1) = atoi((yyvsp[0].string1));}
#line 1833 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 406 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=INTS; }
#line 1839 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 407 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=CHARS; }
#line 1845 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 408 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=FLOATS; }
#line 1851 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 409 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=DATES; }
#line 1857 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 410 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=TEXTS; }
#line 1863 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 414 "yacc_sql.y" /* yacc.c:1646  */
    {
		char *temp=(yyvsp[0].string1); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1872 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 1888 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 439 "yacc_sql.y" /* yacc.c:1646  */
    {	/* do nothing here */	}
#line 1894 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 1907 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 453 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.values1) = new ValueList();
	}
#line 1915 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 456 "yacc_sql.y" /* yacc.c:1646  */
    { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
		(yyval.values1) = (yyvsp[0].values1);
		(yyval.values1)->push_front(*(yyvsp[-1].value1));

		delete (yyvsp[-1].value1);
	}
#line 1927 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 465 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), atoi((yyvsp[0].string1)), (yyvsp[0].string1));
		}
#line 1936 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 469 "yacc_sql.y" /* yacc.c:1646  */
    {
  		(yyval.value1) = new Value();
		value_init_float((yyval.value1), (float)(atof((yyvsp[0].string1))), (yyvsp[0].string1));
		}
#line 1945 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 473 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
		}
#line 1955 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 478 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.value1) = new Value();
		value_init_null((yyval.value1));
	}
#line 1964 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 482 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
		value_init_date((yyval.value1), (yyvsp[0].string1));
	}
#line 1974 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 490 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.value1) = (yyvsp[0].value1);
	}
#line 1982 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 493 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), -atoi((yyvsp[0].string1)), (yyvsp[0].string1));
	}
#line 1991 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 500 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 2001 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 505 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 2011 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 514 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string1));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, *(yyvsp[-1].conditions1));

			delete (yyvsp[-1].conditions1);
    }
#line 2023 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 524 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string1), *(yyvsp[-1].conditions1));
			delete (yyvsp[-1].conditions1);
		}
#line 2033 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 533 "yacc_sql.y" /* yacc.c:1646  */
    {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2042 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 538 "yacc_sql.y" /* yacc.c:1646  */
    {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2051 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 545 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_value((yyval.updatevalue1), (yyvsp[0].value1));
		delete (yyvsp[0].value1);
	}
#line 2061 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 550 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_select((yyval.updatevalue1), (yyvsp[-1].select1));
		delete (yyvsp[-1].select1);
	}
#line 2071 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 2099 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 2127 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 2155 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 633 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_ADD);
	}
#line 2164 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 637 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_SUB);
	}
#line 2173 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 641 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_MUL);
	}
#line 2182 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 645 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_DIV);
	}
#line 2191 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 649 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_attr_init((yyval.selectexpr1), (yyvsp[0].attr1));
	}
#line 2200 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 653 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_value_init((yyval.selectexpr1), (yyvsp[0].value1));
	}
#line 2209 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 657 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = (yyvsp[-1].selectexpr1);
		(yyval.selectexpr1)->is_brace = true;
	}
#line 2218 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 661 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), nullptr, (yyvsp[0].selectexpr1), ARITH_NEG);
	}
#line 2227 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 668 "yacc_sql.y" /* yacc.c:1646  */
    {
		RelAttr *attr = new RelAttr();
		relation_attr_init_with_aggregation(attr, NULL, "*", AGG_NONE, true);
		if ((yyvsp[0].string1) != nullptr) {
			attr->alias = strdup((yyvsp[0].string1));
		}
		SelectExpr expr;
		select_attr_init(&expr, attr);
		(yyval.selectexprs1) = new SelectExprList();
		(yyval.selectexprs1)->push_back(expr);
	}
#line 2243 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 679 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexprs1) = new SelectExprList();
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2253 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 684 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexprs1) = (yyvsp[-2].selectexprs1);
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2263 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 692 "yacc_sql.y" /* yacc.c:1646  */
    {  
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, NULL, "*", AGG_NONE, true);
			if ((yyvsp[-1].string1) != nullptr) {
				attr.alias = strdup((yyvsp[-1].string1));
			}
			(yyvsp[0].attrs1)->push_front(attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
		}
#line 2277 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 701 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].attrs1)->push_front(*(yyvsp[-1].attr1));
		// selects_append_attribute(&CONTEXT->ssql->sstr.selection, *$2);
		delete((yyvsp[-1].attr1));
		(yyval.attrs1) = (yyvsp[0].attrs1);
	}
#line 2288 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 710 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2303 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 720 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2318 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 730 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2333 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 740 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2348 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 750 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2363 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 760 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2372 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 764 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2381 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 768 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2390 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 772 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2399 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 776 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2408 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 783 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.string1) = nullptr;
	}
#line 2416 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 786 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.string1) = (yyvsp[0].string1);
	}
#line 2424 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 789 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.string1) = (yyvsp[0].string1);
	}
#line 2432 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 795 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, (yyvsp[-1].string1), AGG_NONE,true);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2444 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 802 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), (yyvsp[-3].string1), (yyvsp[-1].string1), AGG_NONE,true);

		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2457 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 810 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), (yyvsp[-3].string1), "*", AGG_NONE,true);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2469 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 817 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = (yyvsp[-1].attr1);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2480 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 826 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attrs1) = new AttrList();
	}
#line 2488 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 829 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attrs1) = (yyvsp[0].attrs1);
		(yyval.attrs1)->push_front(*(yyvsp[-1].attr1));
		delete (yyvsp[-1].attr1);
	}
#line 2498 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 837 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.relations1) = new RelationList();
	}
#line 2506 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 840 "yacc_sql.y" /* yacc.c:1646  */
    {	
		Relation rel;
		relation_name_init(&rel, (yyvsp[-2].string1), (yyvsp[-1].string1));
		(yyval.relations1) = (yyvsp[0].relations1);
		(yyval.relations1)->push_back(rel);
	}
#line 2517 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 849 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.joins1) = new JoinList();
		Join join;
		join_set_relation(&join, (yyvsp[-1].string1));
		join_append_conditions(&join, *(yyvsp[0].conditions1));
		(yyval.joins1)->push_back(join);

		delete (yyvsp[0].conditions1);
	}
#line 2531 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 858 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.joins1) = (yyvsp[0].joins1);
		Join join;
		join_set_relation(&join, (yyvsp[-2].string1));
		join_append_conditions(&join, *(yyvsp[-1].conditions1));
		(yyval.joins1)->push_front(join);

		delete (yyvsp[-1].conditions1);
	}
#line 2545 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 870 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));

		delete (yyvsp[-1].condition1);
	}
#line 2556 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 879 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2564 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 882 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2574 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 891 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.groupby1) = nullptr;
	}
#line 2582 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 894 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.groupby1) = new GroupBy();
		(yyvsp[-1].attrs1)->push_front(*(yyvsp[-2].attr1));
		delete (yyvsp[-2].attr1);
		group_init((yyval.groupby1), *(yyvsp[-1].attrs1), *(yyvsp[0].conditions1));
		delete (yyvsp[-1].attrs1);
		delete (yyvsp[0].conditions1);
	}
#line 2595 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 905 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2603 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 908 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2613 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 916 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
	}
#line 2621 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 921 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_expr((yyval.conditionexpr1), (yyvsp[0].selectexpr1));
	}
#line 2630 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 926 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_sq((yyval.conditionexpr1), (yyvsp[-1].select1));
	}
#line 2639 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 932 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2647 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 935 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2657 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 943 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
		(yyval.conditions1)->push_back(*(yyvsp[-2].condition1));
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[-2].condition1);
		delete (yyvsp[0].condition1);
	}
#line 2669 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 950 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[-2].conditions1);
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[0].condition1);
	}
#line 2679 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 958 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2690 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 965 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2707 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 978 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2718 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 984 "yacc_sql.y" /* yacc.c:1646  */
    {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, (yyvsp[-4].selectexpr1));

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2733 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 995 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2750 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1007 "yacc_sql.y" /* yacc.c:1646  */
    {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, nullptr);

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2765 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1020 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = EQUAL_TO; }
#line 2771 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1021 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LESS_THAN; }
#line 2777 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1022 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = GREAT_THAN; }
#line 2783 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1023 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LESS_EQUAL; }
#line 2789 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1024 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = GREAT_EQUAL; }
#line 2795 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1025 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_EQUAL; }
#line 2801 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1029 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = UNLIKE_SCH; }
#line 2807 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1030 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LIKE_SCH; }
#line 2813 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1034 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = IN_SQ; }
#line 2819 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1035 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_IN_SQ; }
#line 2825 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1039 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = EXISTS_SQ; }
#line 2831 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1040 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_EXISTS_SQ; }
#line 2837 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1043 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = IS_NULL; }
#line 2843 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1044 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = IS_NOT_NULL; }
#line 2849 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1049 "yacc_sql.y" /* yacc.c:1646  */
    {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string1), (yyvsp[-4].string1));
		}
#line 2858 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;


#line 2862 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 1054 "yacc_sql.y" /* yacc.c:1906  */

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
