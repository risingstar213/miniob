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
typedef std::deque<Relation> RelationList;
// typedef std::string String;

#line 172 "yacc_sql.tab.c" /* yacc.c:355  */

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
    LENGTH = 312,
    ROUND = 313,
    DATE_FORMAT = 314,
    ADD_OP = 315,
    SUB_OP = 316,
    DIV_OP = 317,
    IN = 318,
    EXISTS = 319,
    GROUP = 320,
    HAVING = 321,
    AS = 322,
    EQ = 323,
    LT = 324,
    GT = 325,
    LE = 326,
    GE = 327,
    NE = 328,
    NUMBER = 329,
    FLOAT = 330,
    DATE_DATA = 331,
    ID = 332,
    PATH = 333,
    SSS = 334,
    LIKE_SSS = 335,
    FORMAT_SSS = 336,
    STAR = 337,
    STRING_V = 338,
    UNARYMINUS = 339
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 155 "yacc_sql.y" /* yacc.c:355  */

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
  OrderCol *ocol1; 		// order column
  OrderColList *ocol_list1;

#line 298 "yacc_sql.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 314 "yacc_sql.tab.c" /* yacc.c:358  */

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
#define YYLAST   437

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  337

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   241,   241,   243,   247,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   272,   277,   282,   288,   294,   300,   306,   312,
     318,   325,   331,   340,   347,   354,   361,   363,   367,   378,
     394,   396,   403,   408,   416,   419,   420,   421,   422,   423,
     426,   435,   449,   451,   455,   466,   469,   478,   482,   486,
     491,   495,   503,   506,   510,   517,   522,   530,   540,   549,
     554,   562,   567,   575,   601,   627,   652,   670,   674,   678,
     682,   686,   690,   694,   698,   702,   706,   710,   714,   722,
     733,   738,   746,   755,   764,   774,   784,   794,   804,   814,
     818,   822,   826,   830,   837,   840,   843,   849,   856,   864,
     871,   881,   884,   892,   895,   902,   906,   910,   916,   919,
     927,   930,   939,   948,   960,   969,   972,   981,   984,   995,
     998,  1006,  1011,  1015,  1022,  1025,  1033,  1040,  1047,  1054,
    1067,  1074,  1084,  1097,  1110,  1111,  1112,  1113,  1114,  1115,
    1119,  1120,  1124,  1125,  1129,  1130,  1133,  1134,  1138
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ORDER", "BY", "ASC", "IS", "NULL_",
  "NULLABLE", "SEMICOLON", "CREATE", "DROP", "TABLE", "TABLES", "INDEX",
  "SELECT", "DESC", "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE",
  "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T",
  "STRING_T", "FLOAT_T", "DATE_T", "TEXT_T", "HELP", "EXIT", "DOT", "INTO",
  "VALUES", "FROM", "WHERE", "AND", "OR", "SET", "NOT", "LIKE", "INNER",
  "JOIN", "ON", "LOAD", "DATA", "INFILE", "UNIQUE", "MAX", "MIN", "SUM",
  "COUNT", "AVG", "LENGTH", "ROUND", "DATE_FORMAT", "ADD_OP", "SUB_OP",
  "DIV_OP", "IN", "EXISTS", "GROUP", "HAVING", "AS", "EQ", "LT", "GT",
  "LE", "GE", "NE", "NUMBER", "FLOAT", "DATE_DATA", "ID", "PATH", "SSS",
  "LIKE_SSS", "FORMAT_SSS", "STAR", "STRING_V", "UNARYMINUS", "$accept",
  "commands", "command", "exit", "help", "sync", "begin", "commit",
  "rollback", "drop_table", "show_tables", "desc_table", "create_index",
  "drop_index", "show_index", "create_table", "attr_def_list", "attr_def",
  "id_list", "number", "type", "ID_get", "insert", "row_list", "row",
  "value_list", "value", "insert_value", "like_value", "delete", "update",
  "update_list", "update_value", "select", "select_arith_expr",
  "select_expr_list", "select_attr", "aggregtion_attr", "alias",
  "rel_attr", "order", "order_col_list", "order_col", "attr_list",
  "rel_list", "join_list", "join_condition_list", "having", "groupby",
  "where", "or_where", "condition_expr", "and_condition_list",
  "or_condition_list", "condition", "comOp", "like_comOp", "in_comOp",
  "exist_comOp", "is_null_comOp", "load_data", YY_NULLPTR
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339
};
# endif

#define YYPACT_NINF -267

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-267)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -267,   365,  -267,    13,    85,    63,   -57,    96,    19,    -4,
       7,   -24,    53,    75,    78,    89,   114,    80,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,   125,  -267,    67,    73,   143,
      95,    99,  -267,   208,   144,   162,   165,   166,   167,   171,
     183,   184,   208,  -267,  -267,  -267,   -20,  -267,    -2,  -267,
     -26,    45,    -2,  -267,   202,   203,   176,  -267,   145,   146,
     182,  -267,  -267,  -267,  -267,  -267,   189,  -267,   220,   196,
     173,   235,   242,   113,   236,   247,   256,   291,   297,   208,
     208,   208,  -267,    18,   175,  -267,  -267,  -267,   208,   208,
     208,   208,   208,   180,  -267,  -267,  -267,   204,   249,   258,
     238,     9,   237,   240,   244,   272,  -267,  -267,  -267,  -267,
      -2,   299,   301,  -267,   300,  -267,   303,  -267,   305,  -267,
     307,   245,   -10,   280,    -2,    -2,  -267,   -38,   -38,  -267,
    -267,   -26,    -2,   322,   310,   106,   325,   267,   259,   328,
     312,  -267,    35,   168,   317,   277,   301,  -267,   341,  -267,
    -267,  -267,  -267,  -267,    -2,    -2,   281,   275,  -267,  -267,
      -8,  -267,   134,   333,   179,   294,  -267,   -21,   148,   319,
     338,  -267,    51,   293,  -267,   351,  -267,   240,   357,   343,
    -267,  -267,  -267,  -267,  -267,   345,   292,   348,  -267,   301,
    -267,  -267,   349,   354,   311,   332,   350,   258,   347,   310,
     378,   377,  -267,   -25,  -267,  -267,    52,   379,   359,  -267,
    -267,  -267,  -267,  -267,  -267,   219,   219,   106,  -267,   388,
     388,  -267,  -267,    51,   327,    35,  -267,   396,   334,   129,
     397,   292,  -267,    -2,    -2,    -2,   330,   106,   344,   407,
     407,    72,   389,   333,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,   128,  -267,   -26,  -267,  -267,   319,   391,   392,  -267,
     402,  -267,  -267,  -267,   393,  -267,   292,  -267,   408,  -267,
    -267,   395,   373,   380,   115,   418,   407,   419,  -267,  -267,
      94,  -267,   347,  -267,  -267,   347,   401,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,   106,   381,   106,   106,   341,
    -267,   341,  -267,  -267,  -267,   404,  -267,   319,  -267,  -267,
    -267,   301,    55,   405,  -267,  -267,   362,  -267,  -267,   341,
    -267,   106,  -267,   405,   319,  -267,  -267
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
       0,     0,     0,    57,    58,    61,   104,    59,   104,    82,
      90,    76,   104,    81,     0,     0,     0,    24,     0,     0,
       0,    25,    26,    27,    23,    22,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,   106,   107,    89,     0,     0,
       0,     0,     0,     0,   110,    30,    29,     0,     0,   129,
       0,   129,     0,     0,     0,     0,    28,    33,    83,    99,
     104,     0,   118,   100,     0,   101,     0,   102,     0,   103,
       0,     0,     0,     0,   104,   104,   105,    77,    78,    80,
      79,    91,   104,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    36,     0,     0,     0,   118,    94,     0,    93,
      95,    96,    97,    98,   104,   104,     0,     0,   108,   109,
     120,    34,     0,    52,     0,     0,   154,   132,     0,   134,
       0,    67,     0,     0,    68,     0,    41,     0,     0,     0,
      45,    46,    47,    48,    49,    39,     0,     0,    92,   118,
      85,    86,     0,     0,     0,     0,   129,   129,    55,     0,
       0,     0,   155,     0,   151,   152,     0,     0,   156,   144,
     145,   146,   147,   148,   149,     0,     0,     0,   130,     0,
       0,    71,    69,     0,     0,    36,    40,     0,     0,     0,
       0,     0,   119,   104,   104,   104,     0,     0,   127,   111,
     111,     0,     0,    52,    51,   133,   150,   153,    66,    65,
     139,     0,   157,   132,   138,   140,   134,     0,     0,    70,
       0,    37,    35,    44,     0,    42,     0,    31,     0,    87,
      88,   120,     0,   131,   134,     0,   111,     0,    74,    75,
       0,    62,    55,    54,    53,    55,     0,   135,   143,    72,
     158,    38,    43,    32,   121,     0,   122,     0,     0,     0,
      73,     0,    63,    64,    56,     0,   141,   134,   123,   137,
     136,   118,   115,   113,   142,   124,   125,   116,   117,     0,
     112,     0,   128,   113,   134,   114,   126
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,   190,   243,  -210,  -267,
    -267,  -267,  -267,   178,   223,  -266,  -165,  -267,  -267,  -267,
    -267,  -267,   200,  -153,     3,  -267,   161,  -267,   -53,   -84,
    -232,   101,   107,  -150,   154,   131,  -267,  -267,  -267,  -100,
    -267,   -47,  -254,  -267,  -217,  -267,  -267,  -267,  -267,  -267,
    -267
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   189,   152,   240,   274,
     195,   153,    32,   210,   173,   252,    59,   292,   260,    33,
      34,   111,   232,    35,   177,    61,   121,    62,    96,    63,
     288,   330,   323,   159,   206,   207,   306,   332,   286,   146,
     249,   178,   228,   283,   179,   225,   216,   217,   180,   226,
      36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     122,   122,   122,   122,   122,    97,   198,   208,    60,   104,
     266,   149,   297,   165,   166,    93,   204,   231,   289,   256,
      64,   211,   213,   214,   100,    37,   314,    38,    67,   315,
     284,   278,    68,   148,    98,    99,   100,   205,   257,    98,
      99,   100,   215,   186,   101,    69,    83,    94,   145,   242,
      98,    99,   100,    70,   310,    92,   101,    95,    42,   187,
     327,   101,    71,   325,    39,    94,   302,   156,   231,   102,
      42,   328,   101,   230,   199,    95,   267,   268,   188,    42,
     336,   168,   169,   103,    72,    43,   291,    73,   317,   170,
     319,   320,   131,   132,   133,   134,   295,    40,    74,    41,
     135,   137,   138,   139,   140,   141,   248,   250,   296,    65,
      66,   200,   201,    42,   334,    44,    45,    46,    47,    48,
      49,    50,    51,    75,    52,    53,    54,    55,   174,    76,
      57,   258,   259,   290,    77,    42,   118,    53,    54,    55,
      56,    42,    57,     5,    78,    58,    53,    54,    55,   175,
      79,    57,   275,   276,   218,   227,   308,    80,    44,    45,
      46,    47,    48,    49,    50,    51,    84,    52,   312,   313,
     176,   326,    81,    98,    99,   100,    82,    83,   264,   265,
      53,    54,    55,    56,    85,    57,    42,    86,    87,    88,
     279,   280,   281,    89,     5,   101,   190,   191,   192,   193,
     194,    43,    53,    54,    55,    90,    91,    57,    53,    54,
      55,   105,   106,    57,   107,    42,   219,   220,   221,   222,
     223,   224,   108,   109,   110,   321,    42,   322,   263,   263,
      43,    44,    45,    46,    47,    48,    49,    50,    51,   112,
      52,   174,   113,   114,   116,   322,   124,   126,   128,   130,
     115,   117,   136,    53,    54,    55,    56,   142,    57,   119,
      44,    45,    46,    47,    48,    49,    50,    51,   164,    52,
     123,    44,    45,    46,    47,    48,    49,    50,    51,   125,
      52,   143,    53,    54,    55,    56,   144,    57,    44,    45,
      46,    47,    48,    53,    54,    55,    56,   145,    57,    44,
      45,    46,    47,    48,   167,    98,    99,   100,    44,    45,
      46,    47,    48,    56,   127,   147,   150,   151,   120,   155,
     129,   154,   157,   160,    56,   158,   161,   101,   162,   120,
     163,   171,   172,    56,   181,   182,   183,   184,   120,   196,
      98,    99,   100,    44,    45,    46,    47,    48,   185,    44,
      45,    46,    47,    48,   197,   202,   203,   209,   212,   227,
     229,   233,   101,   234,   236,     2,   237,   238,    56,   239,
     241,   251,   243,   120,    56,     3,     4,   244,   246,   120,
       5,     6,     7,     8,     9,    10,    11,   254,   245,   247,
      12,    13,    14,    44,    45,    46,    47,    48,    15,    16,
     255,   261,   262,     5,   270,   272,   277,   282,   273,   285,
     287,   300,   293,    17,   298,   299,   301,   303,    56,   204,
     305,   307,   309,   311,   316,   271,   205,   324,   331,   329,
     235,   294,   253,   269,   335,   304,   333,   318
};

static const yytype_uint16 yycheck[] =
{
      84,    85,    86,    87,    88,    58,   156,   172,     5,    62,
     227,   111,   266,    23,    24,    35,    24,   182,   250,    44,
      77,   174,    43,    44,    62,    12,   292,    14,     9,   295,
     247,   241,    36,    24,    60,    61,    62,    45,    63,    60,
      61,    62,    63,     8,    82,    38,    43,    67,    39,   199,
      60,    61,    62,    77,   286,    52,    82,    77,     7,    24,
       5,    82,     9,   317,    51,    67,   276,   120,   233,    24,
       7,    16,    82,    22,   158,    77,   229,   230,    43,     7,
     334,   134,   135,    38,     9,    22,   251,     9,   305,   142,
     307,   308,    89,    90,    91,    77,   261,    12,     9,    14,
      82,    98,    99,   100,   101,   102,   206,   207,   261,    13,
      14,   164,   165,     7,   331,    52,    53,    54,    55,    56,
      57,    58,    59,     9,    61,    74,    75,    76,    22,    49,
      79,    79,    80,    61,     9,     7,    23,    74,    75,    76,
      77,     7,    79,    15,    77,    82,    74,    75,    76,    43,
      77,    79,    23,    24,     6,    40,    41,    14,    52,    53,
      54,    55,    56,    57,    58,    59,    22,    61,    74,    75,
      64,   321,    77,    60,    61,    62,    77,   174,   225,   226,
      74,    75,    76,    77,    22,    79,     7,    22,    22,    22,
     243,   244,   245,    22,    15,    82,    28,    29,    30,    31,
      32,    22,    74,    75,    76,    22,    22,    79,    74,    75,
      76,     9,     9,    79,    38,     7,    68,    69,    70,    71,
      72,    73,    77,    77,    42,   309,     7,   311,   225,   226,
      22,    52,    53,    54,    55,    56,    57,    58,    59,    50,
      61,    22,    22,    47,     9,   329,    85,    86,    87,    88,
      77,     9,    77,    74,    75,    76,    77,    77,    79,    23,
      52,    53,    54,    55,    56,    57,    58,    59,    23,    61,
      23,    52,    53,    54,    55,    56,    57,    58,    59,    23,
      61,    77,    74,    75,    76,    77,    37,    79,    52,    53,
      54,    55,    56,    74,    75,    76,    77,    39,    79,    52,
      53,    54,    55,    56,    24,    60,    61,    62,    52,    53,
      54,    55,    56,    77,    23,    77,    79,    77,    82,    47,
      23,    77,    23,    23,    77,    24,    23,    82,    23,    82,
      23,     9,    22,    77,     9,    68,    77,     9,    82,    22,
      60,    61,    62,    52,    53,    54,    55,    56,    36,    52,
      53,    54,    55,    56,    77,    74,    81,    24,    64,    40,
      22,    68,    82,    12,     7,     0,    23,    22,    77,    77,
      22,    24,    23,    82,    77,    10,    11,    23,    46,    82,
      15,    16,    17,    18,    19,    20,    21,     9,    77,    39,
      25,    26,    27,    52,    53,    54,    55,    56,    33,    34,
      23,    22,    43,    15,    77,     9,     9,    77,    74,    65,
       3,     9,    23,    48,    23,    23,    23,     9,    77,    24,
      47,    41,     4,     4,    23,   235,    45,    23,    66,    24,
     187,   253,   209,   233,   333,   281,   329,   306
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    86,     0,    10,    11,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    33,    34,    48,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   107,   114,   115,   118,   145,    12,    14,    51,
      12,    14,     7,    22,    52,    53,    54,    55,    56,    57,
      58,    59,    61,    74,    75,    76,    77,    79,    82,   111,
     119,   120,   122,   124,    77,    13,    14,     9,    36,    38,
      77,     9,     9,     9,     9,     9,    49,     9,    77,    77,
      14,    77,    77,   119,    22,    22,    22,    22,    22,    22,
      22,    22,   119,    35,    67,    77,   123,   123,    60,    61,
      62,    82,    24,    38,   123,     9,     9,    38,    77,    77,
      42,   116,    50,    22,    47,    77,     9,     9,    23,    23,
      82,   121,   124,    23,   121,    23,   121,    23,   121,    23,
     121,   119,   119,   119,    77,    82,    77,   119,   119,   119,
     119,   119,    77,    77,    37,    39,   134,    77,    24,   134,
      79,    77,   102,   106,    77,    47,   123,    23,    24,   128,
      23,    23,    23,    23,    23,    23,    24,    24,   123,   123,
     123,     9,    22,   109,    22,    43,    64,   119,   136,   139,
     143,     9,    68,    77,     9,    36,     8,    24,    43,   101,
      28,    29,    30,    31,    32,   105,    22,    77,   128,   124,
     123,   123,    74,    81,    24,    45,   129,   130,   111,    24,
     108,   118,    64,    43,    44,    63,   141,   142,     6,    68,
      69,    70,    71,    72,    73,   140,   144,    40,   137,    22,
      22,   111,   117,    68,    12,   102,     7,    23,    22,    77,
     103,    22,   128,    23,    23,    77,    46,    39,   134,   135,
     134,    24,   110,   109,     9,    23,    44,    63,    79,    80,
     113,    22,    43,   119,   136,   136,   139,   118,   118,   117,
      77,   101,     9,    74,   104,    23,    24,     9,   103,   123,
     123,   123,    77,   138,   139,    65,   133,     3,   125,   125,
      61,   111,   112,    23,   108,   111,   118,   137,    23,    23,
       9,    23,   103,     9,   129,    47,   131,    41,    41,     4,
     125,     4,    74,    75,   110,   110,    23,   139,   130,   139,
     139,   124,   124,   127,    23,   137,   128,     5,    16,    24,
     126,    66,   132,   127,   139,   126,   137
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    97,    98,    99,   100,   101,   101,   102,   102,
     102,   102,   103,   103,   104,   105,   105,   105,   105,   105,
     106,   107,   108,   108,   109,   110,   110,   111,   111,   111,
     111,   111,   112,   112,   112,   113,   113,   114,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   120,
     120,   120,   121,   121,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   123,   124,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   132,   132,   133,   133,   134,
     134,   135,   136,   136,   137,   137,   138,   138,   139,   139,
     139,   139,   139,   139,   140,   140,   140,   140,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   145
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
       1,     1,     1,     2,     2,     1,     1,     5,     5,     4,
       5,     1,     3,     9,     8,     8,     2,     3,     3,     3,
       3,     1,     1,     3,     2,     5,     5,     7,     7,     2,
       1,     3,     3,     2,     4,     4,     4,     4,     4,     3,
       3,     3,     3,     3,     0,     2,     1,     2,     4,     4,
       2,     0,     4,     0,     3,     1,     2,     2,     0,     3,
       0,     4,     4,     5,     3,     0,     3,     0,     5,     0,
       3,     2,     1,     3,     0,     3,     3,     3,     3,     3,
       3,     5,     6,     4,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     1,     2,     1,     2,     8
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
#line 247 "yacc_sql.y" /* yacc.c:1646  */
    {
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->ssql->sstr.selection = *(yyvsp[-1].select1);
		delete (yyvsp[-1].select1);
	  }
#line 1668 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 272 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1676 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 277 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1684 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 282 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1692 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 288 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1700 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 294 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1708 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 300 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1716 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 306 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string1));
    }
#line 1725 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 312 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1733 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 318 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string1));
    }
#line 1742 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 326 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), false);
			delete (yyvsp[-1].ids1);
		}
#line 1752 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 332 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), true);
			delete (yyvsp[-1].ids1);
		}
#line 1762 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 341 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string1));
		}
#line 1771 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 348 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_SHOW_INDEX;//"show_index";
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string1));
		}
#line 1780 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 355 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string1));
		}
#line 1790 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 363 "yacc_sql.y" /* yacc.c:1646  */
    {    }
#line 1796 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 368 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[-3].number1)), (yyvsp[-1].number1));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;

		}
#line 1811 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 379 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1831 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 395 "yacc_sql.y" /* yacc.c:1646  */
    {}
#line 1837 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 397 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->ssql->sstr.create_table.attribute_count-1].nullable = true;
		}
#line 1845 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 404 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ids1) = new IdList();
		(yyval.ids1)->push_front((yyvsp[-1].string1));
	}
#line 1854 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 409 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ids1) = (yyvsp[0].ids1);
		(yyval.ids1)->push_front((yyvsp[-2].string1));
	}
#line 1863 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 416 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number1) = atoi((yyvsp[0].string1));}
#line 1869 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 419 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=INTS; }
#line 1875 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 420 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=CHARS; }
#line 1881 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 421 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=FLOATS; }
#line 1887 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 422 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=DATES; }
#line 1893 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 423 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=TEXTS; }
#line 1899 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 427 "yacc_sql.y" /* yacc.c:1646  */
    {
		char *temp=(yyvsp[0].string1); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1908 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 436 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1924 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 452 "yacc_sql.y" /* yacc.c:1646  */
    {	/* do nothing here */	}
#line 1930 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 455 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[-1].values1)->push_front(*(yyvsp[-2].value1));
		inserts_row_init(&CONTEXT->ssql->sstr.insertion.rows[CONTEXT->ssql->sstr.insertion.row_num], *(yyvsp[-1].values1));
		(CONTEXT->ssql->sstr.insertion.row_num)++;

		delete (yyvsp[-2].value1);
		delete (yyvsp[-1].values1);
	}
#line 1943 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 466 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.values1) = new ValueList();
	}
#line 1951 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 469 "yacc_sql.y" /* yacc.c:1646  */
    { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
		(yyval.values1) = (yyvsp[0].values1);
		(yyval.values1)->push_front(*(yyvsp[-1].value1));

		delete (yyvsp[-1].value1);
	}
#line 1963 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 478 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), atoi((yyvsp[0].string1)), (yyvsp[0].string1));
		}
#line 1972 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 482 "yacc_sql.y" /* yacc.c:1646  */
    {
  		(yyval.value1) = new Value();
		value_init_float((yyval.value1), (float)(atof((yyvsp[0].string1))), (yyvsp[0].string1));
		}
#line 1981 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 486 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
		}
#line 1991 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 491 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.value1) = new Value();
		value_init_null((yyval.value1));
	}
#line 2000 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 495 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
		value_init_date((yyval.value1), (yyvsp[0].string1));
	}
#line 2010 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 503 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.value1) = (yyvsp[0].value1);
	}
#line 2018 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 506 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), -atoi((yyvsp[0].string1)), (yyvsp[0].string1));
	}
#line 2027 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 510 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.value1) = new Value();
		value_init_float((yyval.value1), -(float)(atof((yyvsp[0].string1))), (yyvsp[0].string1));
	}
#line 2036 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 517 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 2046 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 522 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 2056 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 531 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string1));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, *(yyvsp[-1].conditions1));

			delete (yyvsp[-1].conditions1);
    }
#line 2068 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 541 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string1), *(yyvsp[-1].conditions1));
			delete (yyvsp[-1].conditions1);
		}
#line 2078 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 550 "yacc_sql.y" /* yacc.c:1646  */
    {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2087 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 555 "yacc_sql.y" /* yacc.c:1646  */
    {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2096 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 562 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_value((yyval.updatevalue1), (yyvsp[0].value1));
		delete (yyvsp[0].value1);
	}
#line 2106 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 567 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_select((yyval.updatevalue1), (yyvsp[-1].select1));
		delete (yyvsp[-1].select1);
	}
#line 2116 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 576 "yacc_sql.y" /* yacc.c:1646  */
    {
			(yyval.select1) = new Selects();
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			Relation rel;
			relation_name_init(&rel, (yyvsp[-5].string1), (yyvsp[-4].string1));
			(yyvsp[-3].relations1)->push_back(rel);
			selects_append_relation((yyval.select1), *(yyvsp[-3].relations1));

			selects_append_select_exprs((yyval.select1), *(yyvsp[-7].selectexprs1));

            selects_append_joins((yyval.select1), JoinList());

			selects_append_conditions((yyval.select1), *(yyvsp[-2].conditions1));

			selects_append_ordercols((yyval.select1), *(yyvsp[0].ocol_list1));

			selects_append_groupby((yyval.select1), (yyvsp[-1].groupby1));

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-7].selectexprs1);
			delete (yyvsp[-2].conditions1);
			delete (yyvsp[-3].relations1);

	}
#line 2146 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 602 "yacc_sql.y" /* yacc.c:1646  */
    {
			(yyval.select1) = new Selects();
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			Relation rel;
			relation_name_init(&rel, (yyvsp[-4].string1), (yyvsp[-3].string1));
			(yyvsp[-2].relations1)->push_back(rel);
			selects_append_relation((yyval.select1), *(yyvsp[-2].relations1));

			selects_append_select_exprs((yyval.select1), *(yyvsp[-6].selectexprs1));

            selects_append_joins((yyval.select1), JoinList());

			selects_append_conditions((yyval.select1), *(yyvsp[-1].conditions1), true);

			selects_append_groupby((yyval.select1), nullptr);

			selects_append_ordercols((yyval.select1), *(yyvsp[0].ocol_list1));

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-6].selectexprs1);
			delete (yyvsp[-1].conditions1);
			delete (yyvsp[-2].relations1);

	}
#line 2176 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 627 "yacc_sql.y" /* yacc.c:1646  */
    {
		// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			(yyval.select1) = new Selects();
			Relation rel;
			relation_name_init(&rel, (yyvsp[-4].string1), (yyvsp[-3].string1));
			RelationList relation_list;
			relation_list.push_back(rel);
			selects_append_relation((yyval.select1), relation_list);

			selects_append_select_exprs((yyval.select1), *(yyvsp[-6].selectexprs1));

            selects_append_joins((yyval.select1), *(yyvsp[-2].joins1));

			selects_append_conditions((yyval.select1), *(yyvsp[-1].conditions1));

			selects_append_groupby((yyval.select1), nullptr);

			selects_append_ordercols((yyval.select1), *(yyvsp[0].ocol_list1));

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-6].selectexprs1);
			delete (yyvsp[-2].joins1);
			delete (yyvsp[-1].conditions1);
	}
#line 2206 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 652 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.select1) = new Selects();
		selects_append_relation((yyval.select1), RelationList());

		selects_append_select_exprs((yyval.select1), *(yyvsp[0].selectexprs1));

		selects_append_joins((yyval.select1), JoinList());

		selects_append_conditions((yyval.select1), ConditionList());

		selects_append_groupby((yyval.select1), nullptr);

		selects_append_ordercols((yyval.select1), OrderColList());
	}
#line 2225 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 670 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_ADD);
	}
#line 2234 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 674 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_SUB);
	}
#line 2243 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 678 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_MUL);
	}
#line 2252 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 682 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_DIV);
	}
#line 2261 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 686 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_attr_init((yyval.selectexpr1), (yyvsp[0].attr1));
	}
#line 2270 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 690 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_value_init((yyval.selectexpr1), (yyvsp[0].value1));
	}
#line 2279 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 694 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = (yyvsp[-1].selectexpr1);
		(yyval.selectexpr1)->is_brace = true;
	}
#line 2288 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 698 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), nullptr, (yyvsp[0].selectexpr1), ARITH_NEG);
	}
#line 2297 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 702 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		function_init_length((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].string1));
	}
#line 2306 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 706 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		function_init_round((yyval.selectexpr1), (yyvsp[-2].selectexpr1), -1, (yyvsp[0].string1));
	}
#line 2315 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 710 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexpr1) = new SelectExpr();
		function_init_round((yyval.selectexpr1), (yyvsp[-4].selectexpr1), atoi((yyvsp[-2].string1)), (yyvsp[0].string1));
	}
#line 2324 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 714 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].string1) = substr((yyvsp[-2].string1),1,strlen((yyvsp[-2].string1))-2);
		(yyval.selectexpr1) = new SelectExpr();
		function_init_format((yyval.selectexpr1), (yyvsp[-4].selectexpr1), (yyvsp[-2].string1), (yyvsp[0].string1));
	}
#line 2334 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 722 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2350 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 733 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexprs1) = new SelectExprList();
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2360 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 738 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.selectexprs1) = (yyvsp[-2].selectexprs1);
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2370 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 746 "yacc_sql.y" /* yacc.c:1646  */
    {  
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, NULL, "*", AGG_NONE, true);
			if ((yyvsp[-1].string1) != nullptr) {
				attr.alias = strdup((yyvsp[-1].string1));
			}
			(yyvsp[0].attrs1)->push_front(attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
		}
#line 2384 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 755 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].attrs1)->push_front(*(yyvsp[-1].attr1));
		// selects_append_attribute(&CONTEXT->ssql->sstr.selection, *$2);
		delete((yyvsp[-1].attr1));
		(yyval.attrs1) = (yyvsp[0].attrs1);
	}
#line 2395 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 764 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_update_aggregation((yyval.attr1), attr, AGG_MAX);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2410 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 774 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_update_aggregation((yyval.attr1), attr, AGG_MIN);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2425 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 784 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_update_aggregation((yyval.attr1), attr, AGG_SUM);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2440 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 794 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_update_aggregation((yyval.attr1), attr, AGG_COUNT);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2455 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 804 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		if ((yyvsp[-1].attrs1)->size() != 1) {
			relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
		} else {
			RelAttr attr = (*(yyvsp[-1].attrs1))[0];
			relation_attr_init_update_aggregation((yyval.attr1), attr, AGG_AVG);
		}
		delete (yyvsp[-1].attrs1);
	}
#line 2470 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 814 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2479 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 818 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2488 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 822 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2497 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 826 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2506 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 830 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2515 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 837 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.string1) = nullptr;
	}
#line 2523 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 840 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.string1) = (yyvsp[0].string1);
	}
#line 2531 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 843 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.string1) = (yyvsp[0].string1);
	}
#line 2539 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 849 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, (yyvsp[-1].string1), AGG_NONE,true);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2551 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 856 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), (yyvsp[-3].string1), (yyvsp[-1].string1), AGG_NONE,true);

		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2564 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 864 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), (yyvsp[-3].string1), "*", AGG_NONE,true);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2576 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 871 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = (yyvsp[-1].attr1);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2587 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 881 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ocol_list1) = new OrderColList;
	}
#line 2595 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 884 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ocol_list1) = (yyvsp[0].ocol_list1);
		(yyval.ocol_list1)->push_front(*(yyvsp[-1].ocol1));
	}
#line 2604 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 892 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ocol_list1) = new OrderColList;
	}
#line 2612 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 895 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ocol_list1) = (yyvsp[0].ocol_list1);
		(yyval.ocol_list1)->push_front(*(yyvsp[-1].ocol1));
	}
#line 2621 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 902 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ocol1) = (OrderCol *)malloc(sizeof(OrderCol));
		order_col_init((yyval.ocol1), (yyvsp[0].attr1), 1);
	}
#line 2630 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 906 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ocol1) = (OrderCol *)malloc(sizeof(OrderCol));
		order_col_init((yyval.ocol1), (yyvsp[-1].attr1), 1);
	}
#line 2639 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 910 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ocol1) = (OrderCol *)malloc(sizeof(OrderCol));
		order_col_init((yyval.ocol1), (yyvsp[-1].attr1), 0);
	}
#line 2648 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 916 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attrs1) = new AttrList();
	}
#line 2656 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 919 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attrs1) = (yyvsp[0].attrs1);
		(yyval.attrs1)->push_front(*(yyvsp[-1].attr1));
		delete (yyvsp[-1].attr1);
	}
#line 2666 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 927 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.relations1) = new RelationList();
	}
#line 2674 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 930 "yacc_sql.y" /* yacc.c:1646  */
    {	
		Relation rel;
		relation_name_init(&rel, (yyvsp[-2].string1), (yyvsp[-1].string1));
		(yyval.relations1) = (yyvsp[0].relations1);
		(yyval.relations1)->push_back(rel);
	}
#line 2685 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 939 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.joins1) = new JoinList();
		Join join;
		join_set_relation(&join, (yyvsp[-1].string1));
		join_append_conditions(&join, *(yyvsp[0].conditions1));
		(yyval.joins1)->push_back(join);

		delete (yyvsp[0].conditions1);
	}
#line 2699 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 948 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.joins1) = (yyvsp[0].joins1);
		Join join;
		join_set_relation(&join, (yyvsp[-2].string1));
		join_append_conditions(&join, *(yyvsp[-1].conditions1));
		(yyval.joins1)->push_front(join);

		delete (yyvsp[-1].conditions1);
	}
#line 2713 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 960 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));

		delete (yyvsp[-1].condition1);
	}
#line 2724 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 969 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2732 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 972 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2742 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 981 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.groupby1) = nullptr;
	}
#line 2750 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 984 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.groupby1) = new GroupBy();
		(yyvsp[-1].attrs1)->push_front(*(yyvsp[-2].attr1));
		delete (yyvsp[-2].attr1);
		group_init((yyval.groupby1), *(yyvsp[-1].attrs1), *(yyvsp[0].conditions1));
		delete (yyvsp[-1].attrs1);
		delete (yyvsp[0].conditions1);
	}
#line 2763 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 995 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2771 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 998 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2781 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1006 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
	}
#line 2789 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1011 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_expr((yyval.conditionexpr1), (yyvsp[0].selectexpr1));
	}
#line 2798 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1016 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_sq((yyval.conditionexpr1), (yyvsp[-1].select1));
	}
#line 2807 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1022 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2815 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1025 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2825 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1033 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
		(yyval.conditions1)->push_back(*(yyvsp[-2].condition1));
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[-2].condition1);
		delete (yyvsp[0].condition1);
	}
#line 2837 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1040 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[-2].conditions1);
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[0].condition1);
	}
#line 2847 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1048 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2858 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1055 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2875 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1068 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2886 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1074 "yacc_sql.y" /* yacc.c:1646  */
    {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, (yyvsp[-4].selectexpr1));

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2901 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1085 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2918 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1097 "yacc_sql.y" /* yacc.c:1646  */
    {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, nullptr);

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2933 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1110 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = EQUAL_TO; }
#line 2939 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1111 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LESS_THAN; }
#line 2945 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1112 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = GREAT_THAN; }
#line 2951 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1113 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LESS_EQUAL; }
#line 2957 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1114 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = GREAT_EQUAL; }
#line 2963 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1115 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_EQUAL; }
#line 2969 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1119 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = UNLIKE_SCH; }
#line 2975 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1120 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LIKE_SCH; }
#line 2981 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1124 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = IN_SQ; }
#line 2987 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1125 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_IN_SQ; }
#line 2993 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1129 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = EXISTS_SQ; }
#line 2999 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1130 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_EXISTS_SQ; }
#line 3005 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1133 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = IS_NULL; }
#line 3011 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1134 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = IS_NOT_NULL; }
#line 3017 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1139 "yacc_sql.y" /* yacc.c:1646  */
    {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string1), (yyvsp[-4].string1));
		}
#line 3026 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;


#line 3030 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 1144 "yacc_sql.y" /* yacc.c:1906  */

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
