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
typedef struct _Selects Selects;
typedef struct _Value Value;
typedef struct _Condition Condition;
typedef struct _Join Join;
typedef std::deque<RelAttr> AttrList;
typedef std::deque<Value> ValueList;
typedef std::deque<Condition> ConditionList;
typedef std::deque<Join> JoinList;
typedef std::deque<char *> IdList;
// typedef std::string String;

#line 161 "yacc_sql.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    CREATE = 259,
    DROP = 260,
    TABLE = 261,
    TABLES = 262,
    INDEX = 263,
    SELECT = 264,
    DESC = 265,
    SHOW = 266,
    SYNC = 267,
    INSERT = 268,
    DELETE = 269,
    UPDATE = 270,
    LBRACE = 271,
    RBRACE = 272,
    COMMA = 273,
    TRX_BEGIN = 274,
    TRX_COMMIT = 275,
    TRX_ROLLBACK = 276,
    INT_T = 277,
    STRING_T = 278,
    FLOAT_T = 279,
    HELP = 280,
    EXIT = 281,
    DOT = 282,
    INTO = 283,
    VALUES = 284,
    FROM = 285,
    WHERE = 286,
    AND = 287,
    SET = 288,
    NOT = 289,
    LIKE = 290,
    DATE_T = 291,
    INNER = 292,
    JOIN = 293,
    ON = 294,
    LOAD = 295,
    DATA = 296,
    INFILE = 297,
    UNIQUE = 298,
    MAX = 299,
    MIN = 300,
    SUM = 301,
    COUNT = 302,
    AVG = 303,
    EQ = 304,
    LT = 305,
    GT = 306,
    LE = 307,
    GE = 308,
    NE = 309,
    NUMBER = 310,
    FLOAT = 311,
    DATE_DATA = 312,
    ID = 313,
    PATH = 314,
    SSS = 315,
    LIKE_SSS = 316,
    STAR = 317,
    STRING_V = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 125 "yacc_sql.y" /* yacc.c:355  */

  RelAttr *attr1;
  Condition *condition1;
  Value *value1;
  Join *join1;
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

#line 254 "yacc_sql.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 270 "yacc_sql.tab.c" /* yacc.c:358  */

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
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   173,   173,   175,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   200,   205,   210,   216,   222,   228,   234,   240,
     246,   253,   259,   268,   275,   282,   289,   291,   295,   306,
     323,   328,   336,   339,   340,   341,   342,   345,   354,   368,
     370,   374,   385,   388,   397,   401,   405,   410,   418,   423,
     431,   441,   452,   469,   488,   494,   500,   506,   515,   525,
     535,   545,   555,   565,   569,   573,   577,   581,   588,   591,
     600,   609,   616,   618,   624,   633,   645,   654,   657,   664,
     667,   674,   696,   718,   737,   760,   782,   804,   822,   843,
     868,   869,   870,   871,   872,   873,   877,   878,   882
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "CREATE", "DROP", "TABLE",
  "TABLES", "INDEX", "SELECT", "DESC", "SHOW", "SYNC", "INSERT", "DELETE",
  "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT",
  "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "HELP", "EXIT", "DOT",
  "INTO", "VALUES", "FROM", "WHERE", "AND", "SET", "NOT", "LIKE", "DATE_T",
  "INNER", "JOIN", "ON", "LOAD", "DATA", "INFILE", "UNIQUE", "MAX", "MIN",
  "SUM", "COUNT", "AVG", "EQ", "LT", "GT", "LE", "GE", "NE", "NUMBER",
  "FLOAT", "DATE_DATA", "ID", "PATH", "SSS", "LIKE_SSS", "STAR",
  "STRING_V", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "drop_index", "show_index", "create_table",
  "attr_def_list", "attr_def", "id_list", "number", "type", "ID_get",
  "insert", "row_list", "row", "value_list", "value", "like_value",
  "delete", "update", "select", "select_attr", "aggration_attr",
  "attr_list", "rel_list", "join_list", "join_condition_list", "where",
  "condition_list", "condition", "comOp", "like_comOp", "load_data", YY_NULLPTR
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
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF -187

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-187)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -187,   107,  -187,     7,    11,   113,   -42,    15,    17,     2,
      10,   -15,    43,    45,    48,    56,    59,    35,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,    22,    24,    27,
      36,    42,    68,    77,    85,    87,    92,    -6,    96,    75,
      96,   112,   120,    80,  -187,    66,    67,    97,  -187,  -187,
    -187,  -187,  -187,    93,   115,    95,   105,   142,   143,   -13,
      19,    25,    44,    51,   118,    90,  -187,  -187,    91,  -187,
    -187,  -187,   114,   121,   139,   116,   127,   135,   141,   147,
    -187,  -187,  -187,   156,  -187,   187,  -187,   195,  -187,   196,
    -187,   197,    26,    96,    96,     0,   212,   200,   122,   214,
     169,   191,  -187,   202,   145,   205,   206,  -187,  -187,  -187,
    -187,  -187,   165,  -187,  -187,  -187,   166,   188,   139,   139,
    -187,   146,   207,  -187,  -187,  -187,   102,  -187,    89,   198,
    -187,   146,   221,   135,   211,  -187,  -187,  -187,  -187,   213,
     173,   173,    96,   215,   174,   231,   232,   218,   200,   234,
     180,   204,  -187,  -187,  -187,  -187,  -187,  -187,  -187,   128,
      14,   134,   122,  -187,   139,   182,   202,   238,   189,    61,
     239,   240,  -187,  -187,   208,  -187,  -187,   146,   228,   207,
    -187,   -25,  -187,  -187,  -187,  -187,  -187,  -187,   219,  -187,
     198,   245,   246,  -187,  -187,  -187,   233,  -187,   173,  -187,
    -187,   122,   216,   218,  -187,  -187,   140,    14,   193,  -187,
    -187,  -187,  -187,  -187,   198,  -187,  -187,   225,  -187,  -187,
    -187,  -187,   199,  -187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,    21,
      20,    15,    16,    17,    18,     9,    10,    11,    12,    13,
      14,     8,     5,     7,     6,     4,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    78,     0,
      78,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    64,     0,    67,
      30,    29,     0,     0,    87,     0,     0,     0,     0,     0,
      28,    33,    73,     0,    74,     0,    75,     0,    76,     0,
      77,     0,    78,    78,    78,    82,     0,     0,     0,     0,
       0,     0,    47,    36,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    79,    81,    66,     0,     0,    87,    87,
      34,     0,    49,    54,    55,    57,     0,    56,     0,    89,
      60,     0,     0,     0,     0,    43,    44,    45,    46,    39,
       0,     0,    78,    82,     0,     0,     0,    52,     0,     0,
       0,     0,   107,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,    88,    87,     0,    36,     0,     0,     0,
       0,     0,    80,    83,     0,    62,    63,     0,     0,    49,
      48,     0,   106,    93,    91,    59,    58,    98,    94,    92,
      89,     0,     0,    37,    35,    42,     0,    40,     0,    31,
      32,     0,    84,    52,    51,    50,     0,     0,     0,    90,
      61,   108,    38,    41,    89,    85,    53,     0,    95,    99,
      96,    86,     0,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,    78,   117,  -148,  -187,
    -187,  -187,  -187,    69,    98,    46,  -130,    38,  -187,  -187,
    -187,   138,   190,   -48,   108,    50,  -187,  -122,  -186,  -164,
    -133,    72,  -187
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   144,   113,   180,   206,
     149,   114,    32,   159,   132,   188,   138,   197,    33,    34,
      35,    49,    50,    76,   128,   129,   212,   109,   173,   139,
     169,   170,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      77,   157,    79,   181,    92,   171,   155,   156,   200,   161,
     162,   174,    74,    37,   219,    38,    51,    40,   126,    41,
      54,    75,    52,    53,   163,   164,   165,   166,   167,   168,
      55,    42,    43,    44,    45,    46,    94,   127,   231,   194,
      56,   199,    96,    57,    74,    47,    58,   224,    59,    48,
      39,    60,   201,   122,   123,   124,   125,   213,   216,    61,
     223,    98,    62,    42,    43,    44,    45,    46,   100,    42,
      43,    44,    45,    46,   195,   196,    63,    47,   207,   208,
      64,    48,    65,    47,    69,    66,   228,    48,    42,    43,
      44,    45,    46,    70,    67,    42,    43,    44,    45,    46,
      68,    71,    47,    72,   182,    78,    48,     2,    73,    47,
      82,     3,     4,    48,    74,    80,     5,     6,     7,     8,
       9,    10,    11,    81,    83,    84,    12,    13,    14,   160,
      85,    87,    15,    16,    88,    86,   161,   162,   163,   164,
     165,   166,   167,   168,    89,    90,    91,    17,   104,   105,
     107,   163,   164,   165,   166,   167,   168,    42,    43,    44,
      45,    46,    42,    43,    44,    45,    46,   145,   146,   147,
     108,    47,   106,   117,   110,    48,   102,   133,   134,   135,
     136,   148,   137,   133,   134,   135,   193,   111,   137,   133,
     134,   135,   198,   112,   137,   133,   134,   135,   227,   115,
     137,   133,   134,   135,   118,   116,   137,    93,    95,    97,
      99,   101,   119,   120,   121,   130,   131,   140,   141,   142,
     143,   150,   151,   152,   153,   158,   154,   175,   177,   178,
     172,   179,   184,   126,   185,   186,   187,   190,   191,   192,
     202,   204,   209,   210,   205,   214,   218,   211,   220,   221,
     222,   230,   232,   127,   203,   229,   189,   233,   215,   226,
     176,   183,   225,   217,   103
};

static const yytype_uint8 yycheck[] =
{
      48,   131,    50,   151,    17,   138,   128,   129,   172,    34,
      35,   141,    18,     6,   200,     8,    58,     6,    18,     8,
       3,    27,     7,     8,    49,    50,    51,    52,    53,    54,
      28,    44,    45,    46,    47,    48,    17,    37,   224,   169,
      30,   171,    17,    58,    18,    58,     3,   211,     3,    62,
      43,     3,   174,    27,   102,   103,   104,   187,   191,     3,
     208,    17,     3,    44,    45,    46,    47,    48,    17,    44,
      45,    46,    47,    48,    60,    61,    41,    58,    17,    18,
      58,    62,    58,    58,    16,    58,   216,    62,    44,    45,
      46,    47,    48,    16,    58,    44,    45,    46,    47,    48,
      58,    16,    58,    16,   152,    30,    62,     0,    16,    58,
      30,     4,     5,    62,    18,     3,     9,    10,    11,    12,
      13,    14,    15,     3,    58,    58,    19,    20,    21,    27,
      33,    16,    25,    26,    39,    42,    34,    35,    49,    50,
      51,    52,    53,    54,    39,     3,     3,    40,    58,    58,
      29,    49,    50,    51,    52,    53,    54,    44,    45,    46,
      47,    48,    44,    45,    46,    47,    48,    22,    23,    24,
      31,    58,    58,    17,    58,    62,    58,    55,    56,    57,
      58,    36,    60,    55,    56,    57,    58,    60,    60,    55,
      56,    57,    58,    58,    60,    55,    56,    57,    58,    58,
      60,    55,    56,    57,    17,    58,    60,    69,    70,    71,
      72,    73,    17,    17,    17,     3,    16,     3,    49,    28,
      18,    16,    16,    58,    58,    18,    38,     6,    17,    16,
      32,    58,    58,    18,     3,     3,    18,     3,    58,    35,
      58,     3,     3,     3,    55,    17,    27,    39,     3,     3,
      17,    58,    27,    37,   176,   217,   158,    58,   189,   213,
     143,   153,   212,   191,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,     0,     4,     5,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    25,    26,    40,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    86,    92,    93,    94,   106,     6,     8,    43,
       6,     8,    44,    45,    46,    47,    48,    58,    62,    95,
      96,    58,     7,     8,     3,    28,    30,    58,     3,     3,
       3,     3,     3,    41,    58,    58,    58,    58,    58,    16,
      16,    16,    16,    16,    18,    27,    97,    97,    30,    97,
       3,     3,    30,    58,    58,    33,    42,    16,    39,    39,
       3,     3,    17,    95,    17,    95,    17,    95,    17,    95,
      17,    95,    58,    96,    58,    58,    58,    29,    31,   101,
      58,    60,    58,    81,    85,    58,    58,    17,    17,    17,
      17,    17,    27,    97,    97,    97,    18,    37,    98,    99,
       3,    16,    88,    55,    56,    57,    58,    60,    90,   103,
       3,    49,    28,    18,    80,    22,    23,    24,    36,    84,
      16,    16,    58,    58,    38,   101,   101,    90,    18,    87,
      27,    34,    35,    49,    50,    51,    52,    53,    54,   104,
     105,   104,    32,   102,    90,     6,    81,    17,    16,    58,
      82,    82,    97,    98,    58,     3,     3,    18,    89,    88,
       3,    58,    35,    58,    90,    60,    61,    91,    58,    90,
     103,   101,    58,    80,     3,    55,    83,    17,    18,     3,
       3,    39,   100,    90,    17,    87,   104,   105,    27,   102,
       3,     3,    17,    82,   103,    99,    89,    58,    90,    91,
      58,   102,    27,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    76,    77,    78,    79,    80,    80,    81,    81,
      82,    82,    83,    84,    84,    84,    84,    85,    86,    87,
      87,    88,    89,    89,    90,    90,    90,    90,    91,    91,
      92,    93,    94,    94,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    97,
      97,    97,    98,    98,    99,    99,   100,   101,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   104,   104,   104,   104,   105,   105,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     8,     8,     4,     5,     8,     0,     3,     5,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     7,     0,
       3,     4,     0,     3,     1,     1,     1,     1,     1,     1,
       5,     8,     7,     7,     2,     2,     4,     2,     4,     4,
       4,     4,     4,     3,     3,     3,     3,     3,     0,     3,
       5,     3,     0,     3,     4,     5,     3,     0,     3,     0,
       3,     3,     3,     3,     3,     5,     5,     7,     3,     5,
       1,     1,     1,     1,     1,     1,     2,     1,     8
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
        case 22:
#line 200 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1528 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 205 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1536 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 210 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1544 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 216 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1552 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 222 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1560 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 228 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1568 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 234 "yacc_sql.y" /* yacc.c:1646  */
    {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string1));
    }
#line 1577 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 240 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1585 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 246 "yacc_sql.y" /* yacc.c:1646  */
    {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string1));
    }
#line 1594 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 254 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), false);
			delete (yyvsp[-1].ids1);
		}
#line 1604 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 260 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), true);
			delete (yyvsp[-1].ids1);
		}
#line 1614 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 269 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string1));
		}
#line 1623 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 276 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_SHOW_INDEX;//"show_index";
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string1));
		}
#line 1632 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 283 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string1));
		}
#line 1642 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 291 "yacc_sql.y" /* yacc.c:1646  */
    {    }
#line 1648 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 296 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[-3].number1)), (yyvsp[-1].number1));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;

		}
#line 1663 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 307 "yacc_sql.y" /* yacc.c:1646  */
    {
			AttrInfo attribute;
			if ((yyvsp[0].number1) != DATES) {
				attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[0].number1)), 4);
			} else {
				attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[0].number1)), 12);
			}
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
		}
#line 1681 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 324 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ids1) = new IdList();
		(yyval.ids1)->push_front((yyvsp[-1].string1));
	}
#line 1690 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 329 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.ids1) = (yyvsp[0].ids1);
		(yyval.ids1)->push_front((yyvsp[-2].string1));
	}
#line 1699 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 336 "yacc_sql.y" /* yacc.c:1646  */
    {(yyval.number1) = atoi((yyvsp[0].string1));}
#line 1705 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 339 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=INTS; }
#line 1711 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 340 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=CHARS; }
#line 1717 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 341 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=FLOATS; }
#line 1723 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 342 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.number1)=DATES; }
#line 1729 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 346 "yacc_sql.y" /* yacc.c:1646  */
    {
		char *temp=(yyvsp[0].string1); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1738 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 355 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1754 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 371 "yacc_sql.y" /* yacc.c:1646  */
    {	/* do nothing here */	}
#line 1760 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 374 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[-1].values1)->push_front(*(yyvsp[-2].value1));
		inserts_row_init(&CONTEXT->ssql->sstr.insertion.rows[CONTEXT->ssql->sstr.insertion.row_num], *(yyvsp[-1].values1));
		(CONTEXT->ssql->sstr.insertion.row_num)++;

		delete (yyvsp[-2].value1);
		delete (yyvsp[-1].values1);
	}
#line 1773 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 385 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.values1) = new ValueList();
	}
#line 1781 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 388 "yacc_sql.y" /* yacc.c:1646  */
    { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
		(yyval.values1) = (yyvsp[0].values1);
		(yyval.values1)->push_front(*(yyvsp[-1].value1));

		delete (yyvsp[-1].value1);
	}
#line 1793 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 397 "yacc_sql.y" /* yacc.c:1646  */
    {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), atoi((yyvsp[0].string1)), (yyvsp[0].string1));
		}
#line 1802 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 401 "yacc_sql.y" /* yacc.c:1646  */
    {
  		(yyval.value1) = new Value();
		value_init_float((yyval.value1), (float)(atof((yyvsp[0].string1))), (yyvsp[0].string1));
		}
#line 1811 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 405 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
		}
#line 1821 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 410 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
		value_init_date((yyval.value1), (yyvsp[0].string1));
	}
#line 1831 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 418 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 1841 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 423 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 1851 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 432 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string1));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, *(yyvsp[-1].conditions1));

			delete (yyvsp[-1].conditions1);
    }
#line 1863 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 442 "yacc_sql.y" /* yacc.c:1646  */
    {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = (yyvsp[-2].value1);
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string1), (yyvsp[-4].string1), value, *(yyvsp[-1].conditions1));

			delete (yyvsp[-2].value1);
			delete (yyvsp[-1].conditions1);
		}
#line 1876 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 453 "yacc_sql.y" /* yacc.c:1646  */
    {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string1));

			selects_append_attribute(&CONTEXT->ssql->sstr.selection, *(yyvsp[-5].attrs1));

            selects_append_joins(&CONTEXT->ssql->sstr.selection, JoinList());

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, *(yyvsp[-1].conditions1));

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-5].attrs1);
			delete (yyvsp[-1].conditions1);

	}
#line 1897 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 469 "yacc_sql.y" /* yacc.c:1646  */
    {
		// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-3].string1));

			selects_append_attribute(&CONTEXT->ssql->sstr.selection, *(yyvsp[-5].attrs1));

            selects_append_joins(&CONTEXT->ssql->sstr.selection, *(yyvsp[-2].joins1));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, *(yyvsp[-1].conditions1));

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-5].attrs1);
			delete (yyvsp[-2].joins1);
			delete (yyvsp[-1].conditions1);
	}
#line 1918 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 488 "yacc_sql.y" /* yacc.c:1646  */
    {  
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, NULL, "*", AGG_NONE, true);
			(yyvsp[0].attrs1)->push_front(attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
		}
#line 1929 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 494 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, NULL, (yyvsp[-1].string1), AGG_NONE, true);
			(yyvsp[0].attrs1)->push_front(attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
		}
#line 1940 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 500 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, (yyvsp[-3].string1), (yyvsp[-1].string1), AGG_NONE, true);
			(yyvsp[0].attrs1)->push_front(attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
		}
#line 1951 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 506 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyvsp[0].attrs1)->push_front(*(yyvsp[-1].attr1));
		selects_append_attribute(&CONTEXT->ssql->sstr.selection, *(yyvsp[0].attrs1));
		delete((yyvsp[-1].attr1));
		(yyval.attrs1) = (yyvsp[0].attrs1);
	}
#line 1962 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 515 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1977 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 525 "yacc_sql.y" /* yacc.c:1646  */
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
#line 1992 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 535 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2007 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 545 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2022 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 555 "yacc_sql.y" /* yacc.c:1646  */
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
#line 2037 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 565 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2046 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 569 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2055 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 573 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2064 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 577 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2073 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 581 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2082 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 588 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attrs1) = new AttrList();
	}
#line 2090 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 591 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, NULL, (yyvsp[-1].string1), AGG_NONE,true);
			// selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
			(yyval.attrs1)->push_front(attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
#line 2104 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 600 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, (yyvsp[-3].string1), (yyvsp[-1].string1), AGG_NONE,true);
			// selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
			(yyval.attrs1)->push_front(attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	}
#line 2118 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 609 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.attrs1) = (yyvsp[0].attrs1);
		(yyval.attrs1)->push_front(*(yyvsp[-1].attr1));
		delete (yyvsp[-1].attr1);
	}
#line 2128 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 618 "yacc_sql.y" /* yacc.c:1646  */
    {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string1));
		  }
#line 2136 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 624 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.joins1) = new JoinList();
		Join join;
		join_set_relation(&join, (yyvsp[-1].string1));
		join_append_conditions(&join, *(yyvsp[0].conditions1));
		(yyval.joins1)->push_back(join);

		delete (yyvsp[0].conditions1);
	}
#line 2150 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 633 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.joins1) = (yyvsp[0].joins1);
		Join join;
		join_set_relation(&join, (yyvsp[-2].string1));
		join_append_conditions(&join, *(yyvsp[-1].conditions1));
		(yyval.joins1)->push_front(join);

		delete (yyvsp[-1].conditions1);
	}
#line 2164 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 645 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));

		delete (yyvsp[-1].condition1);
	}
#line 2175 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 654 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2183 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 657 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2193 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 664 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = new ConditionList();
	}
#line 2201 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 667 "yacc_sql.y" /* yacc.c:1646  */
    {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2211 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 675 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string1));

			Value *right_value = (yyvsp[0].value1);

			(yyval.condition1) = new Condition();
			condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), 1, &left_attr, NULL, 0, NULL, right_value);

			delete (yyvsp[0].value1);
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
#line 2237 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 697 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = (yyvsp[-2].value1);
			Value *right_value = (yyvsp[0].value1);

			(yyval.condition1) = new Condition();
			condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), 0, NULL, left_value, 0, NULL, right_value);

			delete (yyvsp[-2].value1);
			delete (yyvsp[0].value1);
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 2263 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 719 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string1));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string1));

			(yyval.condition1) = new Condition();
			condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), 1, &left_attr, NULL, 1, &right_attr, NULL);
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
#line 2286 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 738 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = (yyvsp[-2].value1);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string1));

			(yyval.condition1) = new Condition();
			condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), 0, NULL, left_value, 1, &right_attr, NULL);

			delete (yyvsp[-2].value1);

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
#line 2313 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 761 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string1), (yyvsp[-2].string1));
			Value *right_value = (yyvsp[0].value1);

			(yyval.condition1) = new Condition();
			condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), 1, &left_attr, NULL, 0, NULL, right_value);

			delete (yyvsp[0].value1);

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
#line 2339 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 783 "yacc_sql.y" /* yacc.c:1646  */
    {
			Value *left_value = (yyvsp[-4].value1);

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string1), (yyvsp[0].string1));

			(yyval.condition1) = new Condition();
			condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), 0, NULL, left_value, 1, &right_attr, NULL);

			delete (yyvsp[-4].value1);
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;//属性值
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;//属性
			// $$->right_attr.relation_name = $3;
			// $$->right_attr.attribute_name = $5;
									
    }
#line 2365 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 805 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string1), (yyvsp[-4].string1));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string1), (yyvsp[0].string1));

			(yyval.condition1) = new Condition();
			condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), 1, &left_attr, NULL, 1, &right_attr, NULL);
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
#line 2387 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 823 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string1));

			Value *right_value = (yyvsp[0].value1);

			(yyval.condition1) = new Condition();
			condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), 1, &left_attr, NULL, 0, NULL, right_value);

			delete (yyvsp[0].value1);
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
#line 2412 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 844 "yacc_sql.y" /* yacc.c:1646  */
    {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string1), (yyvsp[-2].string1));
			Value *right_value = (yyvsp[0].value1);

			(yyval.condition1) = new Condition();
			condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), 1, &left_attr, NULL, 0, NULL, right_value);

			delete (yyvsp[0].value1);

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
#line 2438 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 868 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = EQUAL_TO; }
#line 2444 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 869 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LESS_THAN; }
#line 2450 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 870 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = GREAT_THAN; }
#line 2456 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 871 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LESS_EQUAL; }
#line 2462 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 872 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = GREAT_EQUAL; }
#line 2468 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 873 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = NOT_EQUAL; }
#line 2474 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 877 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = UNLIKE_SCH; }
#line 2480 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 878 "yacc_sql.y" /* yacc.c:1646  */
    { (yyval.comp1) = LIKE_SCH; }
#line 2486 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 883 "yacc_sql.y" /* yacc.c:1646  */
    {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string1), (yyvsp[-4].string1));
		}
#line 2495 "yacc_sql.tab.c" /* yacc.c:1646  */
    break;


#line 2499 "yacc_sql.tab.c" /* yacc.c:1646  */
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
#line 888 "yacc_sql.y" /* yacc.c:1906  */

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
