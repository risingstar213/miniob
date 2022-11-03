/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


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


#line 119 "yacc_sql.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 187 "yacc_sql.tab.c"

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

#line 305 "yacc_sql.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void *scanner);

#endif /* !YY_YY_YACC_SQL_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  302

#define YYUNDEFTOK  2
#define YYMAXUTOK   334


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      75,    76,    77,    78,    79
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   231,   231,   233,   237,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   262,   267,   272,   278,   284,   290,   296,   302,
     308,   315,   321,   330,   337,   344,   351,   353,   357,   368,
     384,   386,   393,   398,   406,   409,   410,   411,   412,   413,
     416,   425,   439,   441,   445,   456,   459,   468,   472,   476,
     481,   485,   493,   496,   503,   508,   516,   526,   535,   540,
     548,   553,   561,   585,   607,   632,   636,   640,   644,   648,
     652,   656,   660,   667,   675,   680,   688,   694,   703,   713,
     723,   733,   743,   753,   757,   761,   765,   769,   776,   780,
     784,   791,   794,   802,   805,   812,   816,   820,   826,   829,
     837,   840,   847,   856,   868,   877,   880,   889,   892,   903,
     906,   914,   919,   923,   930,   933,   941,   948,   955,   962,
     975,   982,   992,  1005,  1018,  1019,  1020,  1021,  1022,  1023,
    1027,  1028,  1032,  1033,  1037,  1038,  1041,  1042,  1046
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
  "COUNT", "AVG", "ADD_OP", "SUB_OP", "DIV_OP", "IN", "EXISTS", "GROUP",
  "HAVING", "EQ", "LT", "GT", "LE", "GE", "NE", "NUMBER", "FLOAT",
  "DATE_DATA", "ID", "PATH", "SSS", "LIKE_SSS", "STAR", "STRING_V",
  "UNARYMINUS", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "drop_index", "show_index", "create_table",
  "attr_def_list", "attr_def", "id_list", "number", "type", "ID_get",
  "insert", "row_list", "row", "value_list", "value", "insert_value",
  "like_value", "delete", "update", "update_list", "update_value",
  "select", "select_arith_expr", "select_expr_list", "select_attr",
  "aggregtion_attr", "rel_attr", "order", "order_col_list", "order_col",
  "attr_list", "rel_list", "join_list", "join_condition_list", "having",
  "groupby", "where", "or_where", "condition_expr", "and_condition_list",
  "or_condition_list", "condition", "comOp", "like_comOp", "in_comOp",
  "exist_comOp", "is_null_comOp", "load_data", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334
};
# endif

#define YYPACT_NINF (-231)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -231,   294,  -231,     4,    15,    45,   -56,   111,    27,    17,
      37,    14,    68,    86,    93,    95,    99,    62,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,   110,  -231,    71,    73,   135,
      80,    83,  -231,   143,   139,   151,   154,   159,   161,   143,
    -231,  -231,  -231,   149,  -231,  -231,  -231,   -26,    88,  -231,
    -231,   176,   183,   155,  -231,   121,   129,   169,  -231,  -231,
    -231,  -231,  -231,   167,  -231,   197,   178,   162,   227,   228,
     -12,   177,   204,   211,   219,   245,  -231,   179,   143,   143,
     143,   143,   143,   180,  -231,  -231,   182,   191,   210,   188,
      -2,   187,   196,   203,   223,  -231,  -231,  -231,  -231,   254,
     256,   254,  -231,   257,  -231,   259,  -231,   260,  -231,   262,
    -231,   -33,   -33,  -231,  -231,   -26,   -11,   242,   264,    87,
     278,   225,   217,   282,   266,  -231,    11,   216,   271,   222,
      81,  -231,  -231,  -231,  -231,  -231,  -231,  -231,   230,   261,
     267,   210,  -231,    57,   284,   116,   255,  -231,   -19,   141,
     277,   307,  -231,     1,   268,  -231,   318,  -231,   196,   324,
     310,  -231,  -231,  -231,  -231,  -231,   312,   263,   313,   254,
     314,   270,    87,   275,  -231,   336,   316,   264,   332,   321,
    -231,   -32,  -231,  -231,    76,   323,   303,  -231,  -231,  -231,
    -231,  -231,  -231,   168,   168,    87,  -231,   333,   333,  -231,
    -231,     1,   274,    11,  -231,   340,   280,   140,   342,   263,
    -231,  -231,   305,   315,   126,   349,   336,   350,  -231,     8,
     334,   284,  -231,  -231,  -231,  -231,  -231,  -231,  -231,    35,
    -231,   -26,  -231,  -231,   277,   335,   337,  -231,   346,  -231,
    -231,  -231,   338,  -231,   263,  -231,   353,    87,   319,    87,
      87,    81,  -231,    81,   289,  -231,   316,  -231,  -231,   316,
     343,  -231,  -231,  -231,  -231,  -231,  -231,  -231,   277,  -231,
    -231,  -231,   254,    65,   339,  -231,  -231,   344,  -231,  -231,
     302,  -231,  -231,    81,  -231,  -231,    87,  -231,   339,   277,
    -231,  -231
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
      57,    58,    61,    98,    59,    83,    80,    84,     0,   100,
      79,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,    23,    22,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,    30,    29,     0,     0,   119,     0,
     119,     0,     0,     0,     0,    28,    33,    81,    93,   108,
       0,   108,    94,     0,    95,     0,    96,     0,    97,     0,
      99,    75,    76,    78,    77,    85,   110,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    36,     0,     0,     0,
       0,    86,    88,    87,    89,    90,    91,    92,     0,     0,
     119,   119,    34,     0,    52,     0,     0,   144,   122,     0,
     124,     0,    66,     0,     0,    67,     0,    41,     0,     0,
       0,    45,    46,    47,    48,    49,    39,     0,     0,   108,
     110,     0,     0,   117,    73,   101,    55,     0,     0,     0,
     145,     0,   141,   142,     0,     0,   146,   134,   135,   136,
     137,   138,   139,     0,     0,     0,   120,     0,     0,    70,
      68,     0,     0,    36,    40,     0,     0,     0,     0,     0,
     109,   111,     0,   121,   124,     0,   101,     0,    74,     0,
       0,    52,    51,   123,   140,   143,    65,    64,   129,     0,
     147,   122,   128,   130,   124,     0,     0,    69,     0,    37,
      35,    44,     0,    42,     0,    31,     0,     0,   112,     0,
       0,     0,    72,     0,     0,    62,    55,    54,    53,    55,
       0,   125,   133,    71,   148,    38,    43,    32,   124,   113,
     127,   126,   108,   105,   103,    63,    56,     0,   131,   114,
     115,   106,   107,     0,   102,   132,     0,   118,   103,   124,
     104,   116
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,   156,   200,  -198,  -231,
    -231,  -231,  -231,   142,   184,  -209,  -143,  -231,  -231,  -231,
    -231,  -231,   163,  -146,     0,  -231,   241,  -231,   -81,   144,
      74,    82,  -105,   198,   118,  -231,  -231,  -231,   -37,  -231,
     -25,  -230,  -231,  -175,  -231,  -231,  -231,  -231,  -231,  -231
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   170,   136,   218,   252,
     176,   137,    32,   188,   154,   230,    56,   266,   238,    33,
      34,   100,   210,    35,   158,    58,   110,    59,    60,   228,
     294,   284,   141,   150,   151,   258,   297,   226,   130,   184,
     159,   206,   223,   160,   203,   194,   195,   161,   204,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     111,   111,   111,   111,   111,    57,   143,   224,    42,   189,
     186,   107,   234,   148,   271,    42,    37,    61,    38,   167,
     209,   256,   132,   208,   191,   192,    90,    40,   235,    41,
     244,    88,    89,    90,   149,   168,    64,   129,    88,    89,
      90,   193,    42,    80,    91,    88,    89,    90,   289,    86,
       5,    91,    42,    65,   169,    39,   276,   286,    91,   179,
     287,   245,   246,   133,    42,    91,   264,    43,   209,   301,
     291,    50,    51,    52,   220,    66,    54,    68,    50,    51,
      52,   292,   278,    54,   280,   281,   265,    67,   121,   122,
     123,   124,   125,   270,    42,    69,   269,    44,    45,    46,
      47,    48,    70,    49,    71,    50,    51,    52,    72,   155,
      54,    73,    92,   183,   185,    50,    51,    52,    53,    74,
      54,   299,    55,    42,    62,    63,    93,    50,    51,    52,
     156,     5,    54,    44,    45,    46,    47,    48,    43,    44,
      45,    46,    47,    48,    75,    49,    76,   196,   157,    77,
      42,   236,   237,    78,    53,    80,    79,    50,    51,    52,
      53,    81,    54,   253,   254,    43,   205,   260,    44,    45,
      46,    47,    48,    82,    49,    42,    83,   290,   242,   243,
     282,    84,   283,    85,    87,    94,    50,    51,    52,    53,
     155,    54,    95,    96,    97,    44,    45,    46,    47,    48,
     108,    49,    98,   241,   241,   197,   198,   199,   200,   201,
     202,    99,   283,    50,    51,    52,    53,   101,    54,   102,
      44,    45,    46,    47,    48,   103,    49,   112,   128,    44,
      45,    46,    47,    48,   114,   104,   105,   106,    50,    51,
      52,    53,   116,    54,   171,   172,   173,   174,   175,   129,
      53,   152,   120,   126,   109,   127,    44,    45,    46,    47,
      48,   131,   134,    44,    45,    46,    47,    48,   118,   135,
     139,    44,    45,    46,    47,    48,   138,    53,   140,   142,
     144,   109,   145,   146,    53,   147,   153,   162,   109,   163,
     164,   165,    53,   177,     2,   178,   109,    44,    45,    46,
      47,    48,   166,   180,     3,     4,   182,   181,   187,     5,
       6,     7,     8,     9,    10,    11,   190,   205,    53,    12,
      13,    14,   109,   113,   115,   117,   119,    15,    16,   207,
     212,   214,   211,   215,   216,   219,   217,   225,   148,   227,
     229,   232,    17,   222,   233,   239,   240,   248,     5,   250,
     251,   255,   257,   261,   263,   274,   259,   267,   272,   285,
     273,   275,   277,   293,   149,   296,   288,   295,   213,   249,
     262,   231,   300,   268,   247,   298,   279,     0,   221
};

static const yytype_int16 yycheck[] =
{
      81,    82,    83,    84,    85,     5,   111,   182,     7,   155,
     153,    23,    44,    24,   244,     7,    12,    73,    14,     8,
     163,   219,    24,    22,    43,    44,    59,    12,    60,    14,
     205,    57,    58,    59,    45,    24,     9,    39,    57,    58,
      59,    60,     7,    43,    77,    57,    58,    59,   278,    49,
      15,    77,     7,    36,    43,    51,   254,   266,    77,   140,
     269,   207,   208,   100,     7,    77,    58,    22,   211,   299,
       5,    70,    71,    72,   179,    38,    75,     9,    70,    71,
      72,    16,   257,    75,   259,   260,   229,    73,    88,    89,
      90,    91,    92,   239,     7,     9,   239,    52,    53,    54,
      55,    56,     9,    58,     9,    70,    71,    72,     9,    22,
      75,    49,    24,   150,   151,    70,    71,    72,    73,     9,
      75,   296,    77,     7,    13,    14,    38,    70,    71,    72,
      43,    15,    75,    52,    53,    54,    55,    56,    22,    52,
      53,    54,    55,    56,    73,    58,    73,     6,    61,    14,
       7,    75,    76,    73,    73,   155,    73,    70,    71,    72,
      73,    22,    75,    23,    24,    22,    40,    41,    52,    53,
      54,    55,    56,    22,    58,     7,    22,   282,   203,   204,
     261,    22,   263,    22,    35,     9,    70,    71,    72,    73,
      22,    75,     9,    38,    73,    52,    53,    54,    55,    56,
      23,    58,    73,   203,   204,    64,    65,    66,    67,    68,
      69,    42,   293,    70,    71,    72,    73,    50,    75,    22,
      52,    53,    54,    55,    56,    47,    58,    23,    37,    52,
      53,    54,    55,    56,    23,    73,     9,     9,    70,    71,
      72,    73,    23,    75,    28,    29,    30,    31,    32,    39,
      73,     9,    73,    73,    77,    73,    52,    53,    54,    55,
      56,    73,    75,    52,    53,    54,    55,    56,    23,    73,
      47,    52,    53,    54,    55,    56,    73,    73,    24,    23,
      23,    77,    23,    23,    73,    23,    22,     9,    77,    64,
      73,     9,    73,    22,     0,    73,    77,    52,    53,    54,
      55,    56,    36,    73,    10,    11,    39,    46,    24,    15,
      16,    17,    18,    19,    20,    21,    61,    40,    73,    25,
      26,    27,    77,    82,    83,    84,    85,    33,    34,    22,
      12,     7,    64,    23,    22,    22,    73,    62,    24,     3,
      24,     9,    48,    73,    23,    22,    43,    73,    15,     9,
      70,     9,    47,     4,     4,     9,    41,    23,    23,    70,
      23,    23,     9,    24,    45,    63,    23,    23,   168,   213,
     226,   187,   298,   231,   211,   293,   258,    -1,   180
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    81,     0,    10,    11,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    33,    34,    48,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   102,   109,   110,   113,   139,    12,    14,    51,
      12,    14,     7,    22,    52,    53,    54,    55,    56,    58,
      70,    71,    72,    73,    75,    77,   106,   114,   115,   117,
     118,    73,    13,    14,     9,    36,    38,    73,     9,     9,
       9,     9,     9,    49,     9,    73,    73,    14,    73,    73,
     114,    22,    22,    22,    22,    22,   114,    35,    57,    58,
      59,    77,    24,    38,     9,     9,    38,    73,    73,    42,
     111,    50,    22,    47,    73,     9,     9,    23,    23,    77,
     116,   118,    23,   116,    23,   116,    23,   116,    23,   116,
      73,   114,   114,   114,   114,   114,    73,    73,    37,    39,
     128,    73,    24,   128,    75,    73,    97,   101,    73,    47,
      24,   122,    23,   122,    23,    23,    23,    23,    24,    45,
     123,   124,     9,    22,   104,    22,    43,    61,   114,   130,
     133,   137,     9,    64,    73,     9,    36,     8,    24,    43,
      96,    28,    29,    30,    31,    32,   100,    22,    73,   118,
      73,    46,    39,   128,   129,   128,   106,    24,   103,   113,
      61,    43,    44,    60,   135,   136,     6,    64,    65,    66,
      67,    68,    69,   134,   138,    40,   131,    22,    22,   106,
     112,    64,    12,    97,     7,    23,    22,    73,    98,    22,
     122,   123,    73,   132,   133,    62,   127,     3,   119,    24,
     105,   104,     9,    23,    44,    60,    75,    76,   108,    22,
      43,   114,   130,   130,   133,   113,   113,   112,    73,    96,
       9,    70,    99,    23,    24,     9,    98,    47,   125,    41,
      41,     4,   119,     4,    58,   106,   107,    23,   103,   106,
     113,   131,    23,    23,     9,    23,    98,     9,   133,   124,
     133,   133,   118,   118,   121,    70,   105,   105,    23,   131,
     122,     5,    16,    24,   120,    23,    63,   126,   121,   133,
     120,   131
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    92,    93,    94,    95,    96,    96,    97,    97,
      97,    97,    98,    98,    99,   100,   100,   100,   100,   100,
     101,   102,   103,   103,   104,   105,   105,   106,   106,   106,
     106,   106,   107,   107,   108,   108,   109,   110,   111,   111,
     112,   112,   113,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   115,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   122,   122,
     123,   123,   124,   124,   125,   126,   126,   127,   127,   128,
     128,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     133,   133,   133,   133,   134,   134,   134,   134,   134,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     8,     9,     4,     5,     8,     0,     3,     5,     2,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     7,     0,     3,     4,     0,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     5,     5,     4,     5,
       1,     3,     8,     6,     7,     3,     3,     3,     3,     1,
       1,     3,     2,     1,     1,     3,     2,     2,     4,     4,
       4,     4,     4,     3,     3,     3,     3,     3,     1,     3,
       1,     0,     4,     0,     3,     1,     2,     2,     0,     3,
       0,     3,     4,     5,     3,     0,     3,     0,     5,     0,
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

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, void *scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 237 "yacc_sql.y"
                           {
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->ssql->sstr.selection = *(yyvsp[-1].select1);
		delete (yyvsp[-1].select1);
	  }
#line 1727 "yacc_sql.tab.c"
    break;

  case 22:
#line 262 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1735 "yacc_sql.tab.c"
    break;

  case 23:
#line 267 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1743 "yacc_sql.tab.c"
    break;

  case 24:
#line 272 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1751 "yacc_sql.tab.c"
    break;

  case 25:
#line 278 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1759 "yacc_sql.tab.c"
    break;

  case 26:
#line 284 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1767 "yacc_sql.tab.c"
    break;

  case 27:
#line 290 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1775 "yacc_sql.tab.c"
    break;

  case 28:
#line 296 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string1));
    }
#line 1784 "yacc_sql.tab.c"
    break;

  case 29:
#line 302 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1792 "yacc_sql.tab.c"
    break;

  case 30:
#line 308 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string1));
    }
#line 1801 "yacc_sql.tab.c"
    break;

  case 31:
#line 316 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), false);
			delete (yyvsp[-1].ids1);
		}
#line 1811 "yacc_sql.tab.c"
    break;

  case 32:
#line 322 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), true);
			delete (yyvsp[-1].ids1);
		}
#line 1821 "yacc_sql.tab.c"
    break;

  case 33:
#line 331 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string1));
		}
#line 1830 "yacc_sql.tab.c"
    break;

  case 34:
#line 338 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_SHOW_INDEX;//"show_index";
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string1));
		}
#line 1839 "yacc_sql.tab.c"
    break;

  case 35:
#line 345 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string1));
		}
#line 1849 "yacc_sql.tab.c"
    break;

  case 37:
#line 353 "yacc_sql.y"
                                   {    }
#line 1855 "yacc_sql.tab.c"
    break;

  case 38:
#line 358 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[-3].number1)), (yyvsp[-1].number1));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;

		}
#line 1870 "yacc_sql.tab.c"
    break;

  case 39:
#line 369 "yacc_sql.y"
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
#line 1890 "yacc_sql.tab.c"
    break;

  case 40:
#line 385 "yacc_sql.y"
                {}
#line 1896 "yacc_sql.tab.c"
    break;

  case 41:
#line 387 "yacc_sql.y"
                {
			CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->ssql->sstr.create_table.attribute_count-1].nullable = true;
		}
#line 1904 "yacc_sql.tab.c"
    break;

  case 42:
#line 394 "yacc_sql.y"
        {
		(yyval.ids1) = new IdList();
		(yyval.ids1)->push_front((yyvsp[-1].string1));
	}
#line 1913 "yacc_sql.tab.c"
    break;

  case 43:
#line 399 "yacc_sql.y"
        {
		(yyval.ids1) = (yyvsp[0].ids1);
		(yyval.ids1)->push_front((yyvsp[-2].string1));
	}
#line 1922 "yacc_sql.tab.c"
    break;

  case 44:
#line 406 "yacc_sql.y"
                       {(yyval.number1) = atoi((yyvsp[0].string1));}
#line 1928 "yacc_sql.tab.c"
    break;

  case 45:
#line 409 "yacc_sql.y"
              { (yyval.number1)=INTS; }
#line 1934 "yacc_sql.tab.c"
    break;

  case 46:
#line 410 "yacc_sql.y"
                  { (yyval.number1)=CHARS; }
#line 1940 "yacc_sql.tab.c"
    break;

  case 47:
#line 411 "yacc_sql.y"
                 { (yyval.number1)=FLOATS; }
#line 1946 "yacc_sql.tab.c"
    break;

  case 48:
#line 412 "yacc_sql.y"
                    { (yyval.number1)=DATES; }
#line 1952 "yacc_sql.tab.c"
    break;

  case 49:
#line 413 "yacc_sql.y"
                    { (yyval.number1)=TEXTS; }
#line 1958 "yacc_sql.tab.c"
    break;

  case 50:
#line 417 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string1); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1967 "yacc_sql.tab.c"
    break;

  case 51:
#line 426 "yacc_sql.y"
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
#line 1983 "yacc_sql.tab.c"
    break;

  case 53:
#line 442 "yacc_sql.y"
        {	/* do nothing here */	}
#line 1989 "yacc_sql.tab.c"
    break;

  case 54:
#line 445 "yacc_sql.y"
                                       {
		(yyvsp[-1].values1)->push_front(*(yyvsp[-2].value1));
		inserts_row_init(&CONTEXT->ssql->sstr.insertion.rows[CONTEXT->ssql->sstr.insertion.row_num], *(yyvsp[-1].values1));
		(CONTEXT->ssql->sstr.insertion.row_num)++;

		delete (yyvsp[-2].value1);
		delete (yyvsp[-1].values1);
	}
#line 2002 "yacc_sql.tab.c"
    break;

  case 55:
#line 456 "yacc_sql.y"
                {
		(yyval.values1) = new ValueList();
	}
#line 2010 "yacc_sql.tab.c"
    break;

  case 56:
#line 459 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
		(yyval.values1) = (yyvsp[0].values1);
		(yyval.values1)->push_front(*(yyvsp[-1].value1));

		delete (yyvsp[-1].value1);
	}
#line 2022 "yacc_sql.tab.c"
    break;

  case 57:
#line 468 "yacc_sql.y"
          {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), atoi((yyvsp[0].string1)), (yyvsp[0].string1));
		}
#line 2031 "yacc_sql.tab.c"
    break;

  case 58:
#line 472 "yacc_sql.y"
          {
  		(yyval.value1) = new Value();
		value_init_float((yyval.value1), (float)(atof((yyvsp[0].string1))), (yyvsp[0].string1));
		}
#line 2040 "yacc_sql.tab.c"
    break;

  case 59:
#line 476 "yacc_sql.y"
         {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
		}
#line 2050 "yacc_sql.tab.c"
    break;

  case 60:
#line 481 "yacc_sql.y"
               {
		(yyval.value1) = new Value();
		value_init_null((yyval.value1));
	}
#line 2059 "yacc_sql.tab.c"
    break;

  case 61:
#line 485 "yacc_sql.y"
                   {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
		value_init_date((yyval.value1), (yyvsp[0].string1));
	}
#line 2069 "yacc_sql.tab.c"
    break;

  case 62:
#line 493 "yacc_sql.y"
              {
		(yyval.value1) = (yyvsp[0].value1);
	}
#line 2077 "yacc_sql.tab.c"
    break;

  case 63:
#line 496 "yacc_sql.y"
                        {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), -atoi((yyvsp[0].string1)), (yyvsp[0].string1));
	}
#line 2086 "yacc_sql.tab.c"
    break;

  case 64:
#line 503 "yacc_sql.y"
                 {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 2096 "yacc_sql.tab.c"
    break;

  case 65:
#line 508 "yacc_sql.y"
             {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 2106 "yacc_sql.tab.c"
    break;

  case 66:
#line 517 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string1));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, *(yyvsp[-1].conditions1));

			delete (yyvsp[-1].conditions1);
    }
#line 2118 "yacc_sql.tab.c"
    break;

  case 67:
#line 527 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string1), *(yyvsp[-1].conditions1));
			delete (yyvsp[-1].conditions1);
		}
#line 2128 "yacc_sql.tab.c"
    break;

  case 68:
#line 536 "yacc_sql.y"
                {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2137 "yacc_sql.tab.c"
    break;

  case 69:
#line 541 "yacc_sql.y"
                {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2146 "yacc_sql.tab.c"
    break;

  case 70:
#line 548 "yacc_sql.y"
              {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_value((yyval.updatevalue1), (yyvsp[0].value1));
		delete (yyvsp[0].value1);
	}
#line 2156 "yacc_sql.tab.c"
    break;

  case 71:
#line 553 "yacc_sql.y"
                               {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_select((yyval.updatevalue1), (yyvsp[-1].select1));
		delete (yyvsp[-1].select1);
	}
#line 2166 "yacc_sql.tab.c"
    break;

  case 72:
#line 562 "yacc_sql.y"
                {
			(yyval.select1) = new Selects();
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			(yyvsp[-3].ids1)->push_back((yyvsp[-4].string1));
			selects_append_relation((yyval.select1), *(yyvsp[-3].ids1));

			selects_append_select_exprs((yyval.select1), *(yyvsp[-6].selectexprs1));

            selects_append_joins((yyval.select1), JoinList());

			selects_append_conditions((yyval.select1), *(yyvsp[-2].conditions1));

			selects_append_ordercols((yyval.select1), *(yyvsp[0].ocol_list1));

			selects_append_groupby((yyval.select1), (yyvsp[-1].groupby1));

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-6].selectexprs1);
			delete (yyvsp[-2].conditions1);
			delete (yyvsp[-3].ids1);

	}
#line 2194 "yacc_sql.tab.c"
    break;

  case 73:
#line 586 "yacc_sql.y"
                {
			(yyval.select1) = new Selects();
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			(yyvsp[-1].ids1)->push_back((yyvsp[-2].string1));
			selects_append_relation((yyval.select1), *(yyvsp[-1].ids1));

			selects_append_select_exprs((yyval.select1), *(yyvsp[-4].selectexprs1));

            selects_append_joins((yyval.select1), JoinList());

			selects_append_conditions((yyval.select1), *(yyvsp[0].conditions1), true);

			selects_append_groupby((yyval.select1), nullptr);

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-4].selectexprs1);
			delete (yyvsp[0].conditions1);
			delete (yyvsp[-1].ids1);

	}
#line 2220 "yacc_sql.tab.c"
    break;

  case 74:
#line 607 "yacc_sql.y"
                                                                {
		// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			(yyval.select1) = new Selects();
			IdList relation_list;
			relation_list.push_back((yyvsp[-3].string1));
			selects_append_relation((yyval.select1), relation_list);

			selects_append_select_exprs((yyval.select1), *(yyvsp[-5].selectexprs1));

            selects_append_joins((yyval.select1), *(yyvsp[-2].joins1));

			selects_append_conditions((yyval.select1), *(yyvsp[-1].conditions1));

			selects_append_groupby((yyval.select1), nullptr);

			// CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			delete (yyvsp[-5].selectexprs1);
			delete (yyvsp[-2].joins1);
			delete (yyvsp[-1].conditions1);
	}
#line 2246 "yacc_sql.tab.c"
    break;

  case 75:
#line 632 "yacc_sql.y"
                                                   {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_ADD);
	}
#line 2255 "yacc_sql.tab.c"
    break;

  case 76:
#line 636 "yacc_sql.y"
                                                     {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_SUB);
	}
#line 2264 "yacc_sql.tab.c"
    break;

  case 77:
#line 640 "yacc_sql.y"
                                                   {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_MUL);
	}
#line 2273 "yacc_sql.tab.c"
    break;

  case 78:
#line 644 "yacc_sql.y"
                                                     {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_DIV);
	}
#line 2282 "yacc_sql.tab.c"
    break;

  case 79:
#line 648 "yacc_sql.y"
                   {
		(yyval.selectexpr1) = new SelectExpr();
		select_attr_init((yyval.selectexpr1), (yyvsp[0].attr1));
	}
#line 2291 "yacc_sql.tab.c"
    break;

  case 80:
#line 652 "yacc_sql.y"
                {
		(yyval.selectexpr1) = new SelectExpr();
		select_value_init((yyval.selectexpr1), (yyvsp[0].value1));
	}
#line 2300 "yacc_sql.tab.c"
    break;

  case 81:
#line 656 "yacc_sql.y"
                                          {
		(yyval.selectexpr1) = (yyvsp[-1].selectexpr1);
		(yyval.selectexpr1)->is_brace = true;
	}
#line 2309 "yacc_sql.tab.c"
    break;

  case 82:
#line 660 "yacc_sql.y"
                                                    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), nullptr, (yyvsp[0].selectexpr1), ARITH_NEG);
	}
#line 2318 "yacc_sql.tab.c"
    break;

  case 83:
#line 667 "yacc_sql.y"
             {
		RelAttr *attr = new RelAttr();
		relation_attr_init_with_aggregation(attr, NULL, "*", AGG_NONE, true);
		SelectExpr expr;
		select_attr_init(&expr, attr);
		(yyval.selectexprs1) = new SelectExprList();
		(yyval.selectexprs1)->push_back(expr);
	}
#line 2331 "yacc_sql.tab.c"
    break;

  case 84:
#line 675 "yacc_sql.y"
                            {
		(yyval.selectexprs1) = new SelectExprList();
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2341 "yacc_sql.tab.c"
    break;

  case 85:
#line 680 "yacc_sql.y"
                                                   {
		(yyval.selectexprs1) = (yyvsp[-2].selectexprs1);
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2351 "yacc_sql.tab.c"
    break;

  case 86:
#line 688 "yacc_sql.y"
                   {  
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, NULL, "*", AGG_NONE, true);
			(yyvsp[0].attrs1)->push_front(attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
		}
#line 2362 "yacc_sql.tab.c"
    break;

  case 87:
#line 694 "yacc_sql.y"
                             {
		(yyvsp[0].attrs1)->push_front(*(yyvsp[-1].attr1));
		// selects_append_attribute(&CONTEXT->ssql->sstr.selection, *$2);
		delete((yyvsp[-1].attr1));
		(yyval.attrs1) = (yyvsp[0].attrs1);
	}
#line 2373 "yacc_sql.tab.c"
    break;

  case 88:
#line 703 "yacc_sql.y"
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
#line 2388 "yacc_sql.tab.c"
    break;

  case 89:
#line 713 "yacc_sql.y"
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
#line 2403 "yacc_sql.tab.c"
    break;

  case 90:
#line 723 "yacc_sql.y"
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
#line 2418 "yacc_sql.tab.c"
    break;

  case 91:
#line 733 "yacc_sql.y"
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
#line 2433 "yacc_sql.tab.c"
    break;

  case 92:
#line 743 "yacc_sql.y"
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
#line 2448 "yacc_sql.tab.c"
    break;

  case 93:
#line 753 "yacc_sql.y"
                            {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2457 "yacc_sql.tab.c"
    break;

  case 94:
#line 757 "yacc_sql.y"
                            {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2466 "yacc_sql.tab.c"
    break;

  case 95:
#line 761 "yacc_sql.y"
                            {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2475 "yacc_sql.tab.c"
    break;

  case 96:
#line 765 "yacc_sql.y"
                              {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2484 "yacc_sql.tab.c"
    break;

  case 97:
#line 769 "yacc_sql.y"
                            {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2493 "yacc_sql.tab.c"
    break;

  case 98:
#line 776 "yacc_sql.y"
           {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, (yyvsp[0].string1), AGG_NONE,true);
	}
#line 2502 "yacc_sql.tab.c"
    break;

  case 99:
#line 780 "yacc_sql.y"
                    {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), (yyvsp[-2].string1), (yyvsp[0].string1), AGG_NONE,true);
	}
#line 2511 "yacc_sql.tab.c"
    break;

  case 100:
#line 784 "yacc_sql.y"
                          {
		(yyval.attr1) = (yyvsp[0].attr1);
	}
#line 2519 "yacc_sql.tab.c"
    break;

  case 101:
#line 791 "yacc_sql.y"
        {
		(yyval.ocol_list1) = new OrderColList;
	}
#line 2527 "yacc_sql.tab.c"
    break;

  case 102:
#line 794 "yacc_sql.y"
                                            {
		(yyval.ocol_list1) = (yyvsp[0].ocol_list1);
		(yyval.ocol_list1)->push_front(*(yyvsp[-1].ocol1));
	}
#line 2536 "yacc_sql.tab.c"
    break;

  case 103:
#line 802 "yacc_sql.y"
        {
		(yyval.ocol_list1) = new OrderColList;
	}
#line 2544 "yacc_sql.tab.c"
    break;

  case 104:
#line 805 "yacc_sql.y"
                                         {
		(yyval.ocol_list1) = (yyvsp[0].ocol_list1);
		(yyval.ocol_list1)->push_front(*(yyvsp[-1].ocol1));
	}
#line 2553 "yacc_sql.tab.c"
    break;

  case 105:
#line 812 "yacc_sql.y"
                 {
		(yyval.ocol1) = (OrderCol *)malloc(sizeof(OrderCol));
		order_col_init((yyval.ocol1), (yyvsp[0].attr1), 1);
	}
#line 2562 "yacc_sql.tab.c"
    break;

  case 106:
#line 816 "yacc_sql.y"
                       {
		(yyval.ocol1) = (OrderCol *)malloc(sizeof(OrderCol));
		order_col_init((yyval.ocol1), (yyvsp[-1].attr1), 1);
	}
#line 2571 "yacc_sql.tab.c"
    break;

  case 107:
#line 820 "yacc_sql.y"
                        {
		(yyval.ocol1) = (OrderCol *)malloc(sizeof(OrderCol));
		order_col_init((yyval.ocol1), (yyvsp[-1].attr1), 0);
	}
#line 2580 "yacc_sql.tab.c"
    break;

  case 108:
#line 826 "yacc_sql.y"
                {
		(yyval.attrs1) = new AttrList();
	}
#line 2588 "yacc_sql.tab.c"
    break;

  case 109:
#line 829 "yacc_sql.y"
                                   {
		(yyval.attrs1) = (yyvsp[0].attrs1);
		(yyval.attrs1)->push_front(*(yyvsp[-1].attr1));
		delete (yyvsp[-1].attr1);
	}
#line 2598 "yacc_sql.tab.c"
    break;

  case 110:
#line 837 "yacc_sql.y"
                {
		(yyval.ids1) = new IdList();
	}
#line 2606 "yacc_sql.tab.c"
    break;

  case 111:
#line 840 "yacc_sql.y"
                        {	
		(yyval.ids1) = (yyvsp[0].ids1);
		(yyval.ids1)->push_back((yyvsp[-1].string1));
	}
#line 2615 "yacc_sql.tab.c"
    break;

  case 112:
#line 847 "yacc_sql.y"
                                          {
		(yyval.joins1) = new JoinList();
		Join join;
		join_set_relation(&join, (yyvsp[-1].string1));
		join_append_conditions(&join, *(yyvsp[0].conditions1));
		(yyval.joins1)->push_back(join);

		delete (yyvsp[0].conditions1);
	}
#line 2629 "yacc_sql.tab.c"
    break;

  case 113:
#line 856 "yacc_sql.y"
                                                      {
		(yyval.joins1) = (yyvsp[0].joins1);
		Join join;
		join_set_relation(&join, (yyvsp[-2].string1));
		join_append_conditions(&join, *(yyvsp[-1].conditions1));
		(yyval.joins1)->push_front(join);

		delete (yyvsp[-1].conditions1);
	}
#line 2643 "yacc_sql.tab.c"
    break;

  case 114:
#line 868 "yacc_sql.y"
                                        {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));

		delete (yyvsp[-1].condition1);
	}
#line 2654 "yacc_sql.tab.c"
    break;

  case 115:
#line 877 "yacc_sql.y"
                   {
		(yyval.conditions1) = new ConditionList();
	}
#line 2662 "yacc_sql.tab.c"
    break;

  case 116:
#line 880 "yacc_sql.y"
                                              {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2672 "yacc_sql.tab.c"
    break;

  case 117:
#line 889 "yacc_sql.y"
                   {
		(yyval.groupby1) = nullptr;
	}
#line 2680 "yacc_sql.tab.c"
    break;

  case 118:
#line 892 "yacc_sql.y"
                                             {
		(yyval.groupby1) = new GroupBy();
		(yyvsp[-1].attrs1)->push_front(*(yyvsp[-2].attr1));
		delete (yyvsp[-2].attr1);
		group_init((yyval.groupby1), *(yyvsp[-1].attrs1), *(yyvsp[0].conditions1));
		delete (yyvsp[-1].attrs1);
		delete (yyvsp[0].conditions1);
	}
#line 2693 "yacc_sql.tab.c"
    break;

  case 119:
#line 903 "yacc_sql.y"
                {
		(yyval.conditions1) = new ConditionList();
	}
#line 2701 "yacc_sql.tab.c"
    break;

  case 120:
#line 906 "yacc_sql.y"
                                         {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2711 "yacc_sql.tab.c"
    break;

  case 121:
#line 914 "yacc_sql.y"
                                {
		(yyval.conditions1) = (yyvsp[0].conditions1);
	}
#line 2719 "yacc_sql.tab.c"
    break;

  case 122:
#line 919 "yacc_sql.y"
                          {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_expr((yyval.conditionexpr1), (yyvsp[0].selectexpr1));
	}
#line 2728 "yacc_sql.tab.c"
    break;

  case 123:
#line 924 "yacc_sql.y"
        {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_sq((yyval.conditionexpr1), (yyvsp[-1].select1));
	}
#line 2737 "yacc_sql.tab.c"
    break;

  case 124:
#line 930 "yacc_sql.y"
                {
		(yyval.conditions1) = new ConditionList();
	}
#line 2745 "yacc_sql.tab.c"
    break;

  case 125:
#line 933 "yacc_sql.y"
                                       {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2755 "yacc_sql.tab.c"
    break;

  case 126:
#line 941 "yacc_sql.y"
                               {
		(yyval.conditions1) = new ConditionList();
		(yyval.conditions1)->push_back(*(yyvsp[-2].condition1));
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[-2].condition1);
		delete (yyvsp[0].condition1);
	}
#line 2767 "yacc_sql.tab.c"
    break;

  case 127:
#line 948 "yacc_sql.y"
                                         {
		(yyval.conditions1) = (yyvsp[-2].conditions1);
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[0].condition1);
	}
#line 2777 "yacc_sql.tab.c"
    break;

  case 128:
#line 956 "yacc_sql.y"
        {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2788 "yacc_sql.tab.c"
    break;

  case 129:
#line 963 "yacc_sql.y"
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
#line 2805 "yacc_sql.tab.c"
    break;

  case 130:
#line 976 "yacc_sql.y"
        {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2816 "yacc_sql.tab.c"
    break;

  case 131:
#line 982 "yacc_sql.y"
                                                           {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, (yyvsp[-4].selectexpr1));

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2831 "yacc_sql.tab.c"
    break;

  case 132:
#line 993 "yacc_sql.y"
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
#line 2848 "yacc_sql.tab.c"
    break;

  case 133:
#line 1005 "yacc_sql.y"
                                           {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, nullptr);

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2863 "yacc_sql.tab.c"
    break;

  case 134:
#line 1018 "yacc_sql.y"
             { (yyval.comp1) = EQUAL_TO; }
#line 2869 "yacc_sql.tab.c"
    break;

  case 135:
#line 1019 "yacc_sql.y"
         { (yyval.comp1) = LESS_THAN; }
#line 2875 "yacc_sql.tab.c"
    break;

  case 136:
#line 1020 "yacc_sql.y"
         { (yyval.comp1) = GREAT_THAN; }
#line 2881 "yacc_sql.tab.c"
    break;

  case 137:
#line 1021 "yacc_sql.y"
         { (yyval.comp1) = LESS_EQUAL; }
#line 2887 "yacc_sql.tab.c"
    break;

  case 138:
#line 1022 "yacc_sql.y"
         { (yyval.comp1) = GREAT_EQUAL; }
#line 2893 "yacc_sql.tab.c"
    break;

  case 139:
#line 1023 "yacc_sql.y"
         { (yyval.comp1) = NOT_EQUAL; }
#line 2899 "yacc_sql.tab.c"
    break;

  case 140:
#line 1027 "yacc_sql.y"
                   { (yyval.comp1) = UNLIKE_SCH; }
#line 2905 "yacc_sql.tab.c"
    break;

  case 141:
#line 1028 "yacc_sql.y"
               { (yyval.comp1) = LIKE_SCH; }
#line 2911 "yacc_sql.tab.c"
    break;

  case 142:
#line 1032 "yacc_sql.y"
           { (yyval.comp1) = IN_SQ; }
#line 2917 "yacc_sql.tab.c"
    break;

  case 143:
#line 1033 "yacc_sql.y"
                 { (yyval.comp1) = NOT_IN_SQ; }
#line 2923 "yacc_sql.tab.c"
    break;

  case 144:
#line 1037 "yacc_sql.y"
               { (yyval.comp1) = EXISTS_SQ; }
#line 2929 "yacc_sql.tab.c"
    break;

  case 145:
#line 1038 "yacc_sql.y"
                     { (yyval.comp1) = NOT_EXISTS_SQ; }
#line 2935 "yacc_sql.tab.c"
    break;

  case 146:
#line 1041 "yacc_sql.y"
             { (yyval.comp1) = IS_NULL; }
#line 2941 "yacc_sql.tab.c"
    break;

  case 147:
#line 1042 "yacc_sql.y"
                 { (yyval.comp1) = IS_NOT_NULL; }
#line 2947 "yacc_sql.tab.c"
    break;

  case 148:
#line 1047 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string1), (yyvsp[-4].string1));
		}
#line 2956 "yacc_sql.tab.c"
    break;


#line 2960 "yacc_sql.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp, scanner);
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
#line 1052 "yacc_sql.y"

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
