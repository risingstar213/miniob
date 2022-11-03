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

#line 189 "yacc_sql.tab.c"

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
    AS = 319,
    EQ = 320,
    LT = 321,
    GT = 322,
    LE = 323,
    GE = 324,
    NE = 325,
    NUMBER = 326,
    FLOAT = 327,
    DATE_DATA = 328,
    ID = 329,
    PATH = 330,
    SSS = 331,
    LIKE_SSS = 332,
    STAR = 333,
    STRING_V = 334,
    UNARYMINUS = 335
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 152 "yacc_sql.y"

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

#line 310 "yacc_sql.tab.c"

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
#define YYLAST   391

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  315

#define YYUNDEFTOK  2
#define YYMAXUTOK   335


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
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   237,   237,   239,   243,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   268,   273,   278,   284,   290,   296,   302,   308,
     314,   321,   327,   336,   343,   350,   357,   359,   363,   374,
     390,   392,   399,   404,   412,   415,   416,   417,   418,   419,
     422,   431,   445,   447,   451,   462,   465,   474,   478,   482,
     487,   491,   499,   502,   509,   514,   522,   532,   541,   546,
     554,   559,   567,   593,   619,   648,   652,   656,   660,   664,
     668,   672,   676,   683,   694,   699,   707,   716,   725,   735,
     745,   755,   765,   775,   779,   783,   787,   791,   798,   801,
     804,   810,   817,   825,   832,   842,   845,   853,   856,   863,
     867,   871,   877,   880,   888,   891,   900,   909,   921,   930,
     933,   942,   945,   956,   959,   967,   972,   976,   983,   986,
     994,  1001,  1008,  1015,  1028,  1035,  1045,  1058,  1071,  1072,
    1073,  1074,  1075,  1076,  1080,  1081,  1085,  1086,  1090,  1091,
    1094,  1095,  1099
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
  "HAVING", "AS", "EQ", "LT", "GT", "LE", "GE", "NE", "NUMBER", "FLOAT",
  "DATE_DATA", "ID", "PATH", "SSS", "LIKE_SSS", "STAR", "STRING_V",
  "UNARYMINUS", "$accept", "commands", "command", "exit", "help", "sync",
  "begin", "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "drop_index", "show_index", "create_table",
  "attr_def_list", "attr_def", "id_list", "number", "type", "ID_get",
  "insert", "row_list", "row", "value_list", "value", "insert_value",
  "like_value", "delete", "update", "update_list", "update_value",
  "select", "select_arith_expr", "select_expr_list", "select_attr",
  "aggregtion_attr", "alias", "rel_attr", "order", "order_col_list",
  "order_col", "attr_list", "rel_list", "join_list", "join_condition_list",
  "having", "groupby", "where", "or_where", "condition_expr",
  "and_condition_list", "or_condition_list", "condition", "comOp",
  "like_comOp", "in_comOp", "exist_comOp", "is_null_comOp", "load_data", YY_NULLPTR
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335
};
# endif

#define YYPACT_NINF (-235)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -235,   322,  -235,     3,    10,    48,   -17,    16,    50,    31,
      69,    36,   109,   120,   136,   152,   158,    87,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,   159,  -235,    96,   114,   179,
     121,   122,  -235,   127,   175,   180,   182,   183,   184,   127,
    -235,  -235,  -235,     8,  -235,    63,  -235,    93,    55,    63,
    -235,   199,   203,   181,  -235,   139,   165,   198,  -235,  -235,
    -235,  -235,  -235,   191,  -235,   224,   174,   176,   216,   239,
      -9,   205,   214,   222,   249,   257,  -235,   -47,   188,  -235,
    -235,  -235,   127,   127,   127,   127,   127,   189,  -235,  -235,
    -235,   190,   212,   226,   197,    41,   206,   207,   210,   238,
    -235,  -235,  -235,  -235,    63,   250,   262,  -235,   264,  -235,
     266,  -235,   267,  -235,   268,    63,    63,  -235,    -7,    -7,
    -235,  -235,    93,    63,   284,   272,   101,   288,   230,   225,
     289,   270,  -235,    13,   286,   285,   234,   262,  -235,   -14,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,    -1,  -235,   171,
     295,    59,   259,  -235,   -25,   186,   281,   302,  -235,   118,
     260,  -235,   314,  -235,   207,   321,   306,  -235,  -235,  -235,
    -235,  -235,   308,   271,   312,  -235,   262,   276,   290,   305,
     226,   327,   272,   337,   329,  -235,   -24,  -235,  -235,    62,
     331,   311,  -235,  -235,  -235,  -235,  -235,  -235,   162,   162,
     101,  -235,   342,   342,  -235,  -235,   118,   287,    13,  -235,
     349,   291,   124,   350,   271,  -235,    63,   292,   101,   298,
     360,   360,    70,   341,   295,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,   151,  -235,    93,  -235,  -235,   281,   344,   345,
    -235,   356,  -235,  -235,  -235,   346,  -235,   271,  -235,   362,
     348,   326,   333,   146,   371,   360,   372,  -235,  -235,   307,
    -235,   327,  -235,  -235,   327,   354,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,   101,   334,   101,   101,   -14,  -235,
     -14,  -235,  -235,   357,  -235,   281,  -235,  -235,  -235,   262,
     100,   358,  -235,  -235,   318,  -235,  -235,   -14,  -235,   101,
    -235,   358,   281,  -235,  -235
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
      29,     0,     0,   123,     0,   123,     0,     0,     0,     0,
      28,    33,    81,    93,    98,     0,   112,    94,     0,    95,
       0,    96,     0,    97,     0,    98,    98,    99,    75,    76,
      78,    77,    85,    98,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    36,     0,     0,     0,   112,    88,     0,
      87,    89,    90,    91,    92,   102,   103,   114,    34,     0,
      52,     0,     0,   148,   126,     0,   128,     0,    66,     0,
       0,    67,     0,    41,     0,     0,     0,    45,    46,    47,
      48,    49,    39,     0,     0,    86,   112,     0,     0,   123,
     123,    55,     0,     0,     0,   149,     0,   145,   146,     0,
       0,   150,   138,   139,   140,   141,   142,   143,     0,     0,
       0,   124,     0,     0,    70,    68,     0,     0,    36,    40,
       0,     0,     0,     0,     0,   113,    98,     0,     0,   121,
     105,   105,     0,     0,    52,    51,   127,   144,   147,    65,
      64,   133,     0,   151,   126,   132,   134,   128,     0,     0,
      69,     0,    37,    35,    44,     0,    42,     0,    31,     0,
     114,     0,   125,   128,     0,   105,     0,    73,    74,     0,
      62,    55,    54,    53,    55,     0,   129,   137,    71,   152,
      38,    43,    32,   115,     0,   116,     0,     0,     0,    72,
       0,    63,    56,     0,   135,   128,   117,   131,   130,   112,
     109,   107,   136,   118,   119,   110,   111,     0,   106,     0,
     122,   107,   128,   108,   120
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,   166,   209,  -199,  -235,
    -235,  -235,  -235,   153,   193,  -186,  -143,  -235,  -235,  -235,
    -235,  -235,   170,  -150,     2,  -235,   147,  -235,   -50,   -81,
    -219,    77,    82,  -139,   130,   106,  -235,  -235,  -235,   -99,
    -235,   -44,  -234,  -235,  -200,  -235,  -235,  -235,  -235,  -235,
    -235
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   176,   143,   223,   255,
     182,   144,    32,   193,   160,   233,    56,   271,   241,    33,
      34,   105,   215,    35,   164,    58,   115,    59,    90,    60,
     267,   308,   301,   150,   189,   190,   285,   310,   265,   137,
     230,   165,   211,   262,   166,   208,   199,   200,   167,   209,
      36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,   116,   116,   116,   116,    91,   140,    57,   185,    98,
     247,   194,   268,   276,   112,    37,   191,    38,   196,   197,
     237,   173,    40,   187,    41,   259,   214,   125,   263,    62,
      63,   126,    92,    93,    94,   198,   238,   174,    44,    45,
      46,    47,    48,    87,   188,    80,   289,   225,    92,    93,
      94,    86,    94,    95,    39,    42,   175,    61,   281,    64,
      53,   303,   248,   249,   147,   139,    42,    65,   186,    95,
      43,    95,    88,   214,     5,   155,   156,    42,   314,    96,
     136,    43,    89,   157,   295,   292,   297,   298,   293,   270,
     229,   231,   275,    97,   128,   129,   130,   131,   132,   274,
      44,    45,    46,    47,    48,   305,    49,    66,    42,   312,
      67,    44,    45,    46,    47,    48,   306,    49,    68,    50,
      51,    52,    53,   161,    54,    42,    55,    88,   269,    69,
      50,    51,    52,    53,    42,    54,    73,    89,   239,   240,
     213,    50,    51,    52,   162,    70,    54,   256,   257,    43,
      92,    93,    94,    44,    45,    46,    47,    48,    42,    49,
     304,    71,   163,    80,   245,   246,     5,    72,    74,    42,
      75,    95,    50,    51,    52,    53,   260,    54,    42,    44,
      45,    46,    47,    48,   161,    49,   210,   287,    76,    50,
      51,    52,   201,    77,    54,    78,    79,    81,    50,    51,
      52,    53,    82,    54,    83,    84,    85,   299,    99,   300,
     244,   244,   100,   102,    44,    45,    46,    47,    48,   101,
      49,   108,    50,    51,    52,   110,   300,    54,   113,   118,
     120,   122,   124,    50,    51,    52,    53,   117,    54,   103,
     104,   106,    50,    51,    52,   119,   107,    54,   111,   135,
     109,   202,   203,   204,   205,   206,   207,    44,    45,    46,
      47,    48,   127,   133,   134,   136,    44,    45,    46,    47,
      48,   138,   121,   148,    44,    45,    46,    47,    48,    53,
     123,   142,   141,   114,   145,   146,   149,   151,    53,   152,
     153,   154,   114,   158,   159,   169,    53,   168,   171,   170,
     114,    44,    45,    46,    47,    48,   172,   183,   184,    44,
      45,    46,    47,    48,   177,   178,   179,   180,   181,   192,
     195,   210,     2,    53,   212,   216,   217,   114,   219,   220,
     221,    53,     3,     4,   224,   114,   227,     5,     6,     7,
       8,     9,    10,    11,   228,   222,   235,    12,    13,    14,
     226,   232,   236,   242,   243,    15,    16,     5,   253,   258,
     264,   251,   254,   266,   272,   279,   261,   277,   278,   280,
      17,   282,   187,   284,   286,   288,   290,   294,   291,   188,
     302,   309,   307,   218,   252,   234,   250,   273,   313,   311,
     283,   296
};

static const yytype_int16 yycheck[] =
{
      81,    82,    83,    84,    85,    55,   105,     5,   147,    59,
     210,   161,   231,   247,    23,    12,   159,    14,    43,    44,
      44,     8,    12,    24,    14,   224,   169,    74,   228,    13,
      14,    78,    57,    58,    59,    60,    60,    24,    52,    53,
      54,    55,    56,    35,    45,    43,   265,   186,    57,    58,
      59,    49,    59,    78,    51,     7,    43,    74,   257,     9,
      74,   295,   212,   213,   114,    24,     7,    36,   149,    78,
      22,    78,    64,   216,    15,   125,   126,     7,   312,    24,
      39,    22,    74,   133,   284,   271,   286,   287,   274,   232,
     189,   190,   242,    38,    92,    93,    94,    95,    96,   242,
      52,    53,    54,    55,    56,     5,    58,    38,     7,   309,
      74,    52,    53,    54,    55,    56,    16,    58,     9,    71,
      72,    73,    74,    22,    76,     7,    78,    64,    58,     9,
      71,    72,    73,    74,     7,    76,    49,    74,    76,    77,
      22,    71,    72,    73,    43,     9,    76,    23,    24,    22,
      57,    58,    59,    52,    53,    54,    55,    56,     7,    58,
     299,     9,    61,   161,   208,   209,    15,     9,     9,     7,
      74,    78,    71,    72,    73,    74,   226,    76,     7,    52,
      53,    54,    55,    56,    22,    58,    40,    41,    74,    71,
      72,    73,     6,    14,    76,    74,    74,    22,    71,    72,
      73,    74,    22,    76,    22,    22,    22,   288,     9,   290,
     208,   209,     9,    74,    52,    53,    54,    55,    56,    38,
      58,    47,    71,    72,    73,     9,   307,    76,    23,    82,
      83,    84,    85,    71,    72,    73,    74,    23,    76,    74,
      42,    50,    71,    72,    73,    23,    22,    76,     9,    37,
      74,    65,    66,    67,    68,    69,    70,    52,    53,    54,
      55,    56,    74,    74,    74,    39,    52,    53,    54,    55,
      56,    74,    23,    23,    52,    53,    54,    55,    56,    74,
      23,    74,    76,    78,    74,    47,    24,    23,    74,    23,
      23,    23,    78,     9,    22,    65,    74,     9,     9,    74,
      78,    52,    53,    54,    55,    56,    36,    22,    74,    52,
      53,    54,    55,    56,    28,    29,    30,    31,    32,    24,
      61,    40,     0,    74,    22,    65,    12,    78,     7,    23,
      22,    74,    10,    11,    22,    78,    46,    15,    16,    17,
      18,    19,    20,    21,    39,    74,     9,    25,    26,    27,
      74,    24,    23,    22,    43,    33,    34,    15,     9,     9,
      62,    74,    71,     3,    23,     9,    74,    23,    23,    23,
      48,     9,    24,    47,    41,     4,     4,    23,    71,    45,
      23,    63,    24,   174,   218,   192,   216,   234,   311,   307,
     260,   285
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    82,     0,    10,    11,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    33,    34,    48,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   103,   110,   111,   114,   141,    12,    14,    51,
      12,    14,     7,    22,    52,    53,    54,    55,    56,    58,
      71,    72,    73,    74,    76,    78,   107,   115,   116,   118,
     120,    74,    13,    14,     9,    36,    38,    74,     9,     9,
       9,     9,     9,    49,     9,    74,    74,    14,    74,    74,
     115,    22,    22,    22,    22,    22,   115,    35,    64,    74,
     119,   119,    57,    58,    59,    78,    24,    38,   119,     9,
       9,    38,    74,    74,    42,   112,    50,    22,    47,    74,
       9,     9,    23,    23,    78,   117,   120,    23,   117,    23,
     117,    23,   117,    23,   117,    74,    78,    74,   115,   115,
     115,   115,   115,    74,    74,    37,    39,   130,    74,    24,
     130,    76,    74,    98,   102,    74,    47,   119,    23,    24,
     124,    23,    23,    23,    23,   119,   119,   119,     9,    22,
     105,    22,    43,    61,   115,   132,   135,   139,     9,    65,
      74,     9,    36,     8,    24,    43,    97,    28,    29,    30,
      31,    32,   101,    22,    74,   124,   120,    24,    45,   125,
     126,   107,    24,   104,   114,    61,    43,    44,    60,   137,
     138,     6,    65,    66,    67,    68,    69,    70,   136,   140,
      40,   133,    22,    22,   107,   113,    65,    12,    98,     7,
      23,    22,    74,    99,    22,   124,    74,    46,    39,   130,
     131,   130,    24,   106,   105,     9,    23,    44,    60,    76,
      77,   109,    22,    43,   115,   132,   132,   135,   114,   114,
     113,    74,    97,     9,    71,   100,    23,    24,     9,    99,
     119,    74,   134,   135,    62,   129,     3,   121,   121,    58,
     107,   108,    23,   104,   107,   114,   133,    23,    23,     9,
      23,    99,     9,   125,    47,   127,    41,    41,     4,   121,
       4,    71,   106,   106,    23,   135,   126,   135,   135,   120,
     120,   123,    23,   133,   124,     5,    16,    24,   122,    63,
     128,   123,   135,   122,   133
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    93,    94,    95,    96,    97,    97,    98,    98,
      98,    98,    99,    99,   100,   101,   101,   101,   101,   101,
     102,   103,   104,   104,   105,   106,   106,   107,   107,   107,
     107,   107,   108,   108,   109,   109,   110,   111,   112,   112,
     113,   113,   114,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   116,   116,   116,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   120,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   124,   124,   125,   125,   126,   126,   127,   128,
     128,   129,   129,   130,   130,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   135,   135,   135,   135,   136,   136,
     136,   136,   136,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   141
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
       1,     3,     9,     8,     8,     3,     3,     3,     3,     1,
       1,     3,     2,     2,     1,     3,     3,     2,     4,     4,
       4,     4,     4,     3,     3,     3,     3,     3,     0,     2,
       1,     2,     4,     4,     2,     0,     4,     0,     3,     1,
       2,     2,     0,     3,     0,     4,     4,     5,     3,     0,
       3,     0,     5,     0,     3,     2,     1,     3,     0,     3,
       3,     3,     3,     3,     3,     5,     6,     4,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     1,     2,
       1,     2,     8
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
#line 243 "yacc_sql.y"
                           {
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		CONTEXT->ssql->sstr.selection = *(yyvsp[-1].select1);
		delete (yyvsp[-1].select1);
	  }
#line 1745 "yacc_sql.tab.c"
    break;

  case 22:
#line 268 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    }
#line 1753 "yacc_sql.tab.c"
    break;

  case 23:
#line 273 "yacc_sql.y"
                   {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    }
#line 1761 "yacc_sql.tab.c"
    break;

  case 24:
#line 278 "yacc_sql.y"
                   {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
#line 1769 "yacc_sql.tab.c"
    break;

  case 25:
#line 284 "yacc_sql.y"
                        {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
#line 1777 "yacc_sql.tab.c"
    break;

  case 26:
#line 290 "yacc_sql.y"
                         {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
#line 1785 "yacc_sql.tab.c"
    break;

  case 27:
#line 296 "yacc_sql.y"
                           {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
#line 1793 "yacc_sql.tab.c"
    break;

  case 28:
#line 302 "yacc_sql.y"
                            {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string1));
    }
#line 1802 "yacc_sql.tab.c"
    break;

  case 29:
#line 308 "yacc_sql.y"
                          {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
#line 1810 "yacc_sql.tab.c"
    break;

  case 30:
#line 314 "yacc_sql.y"
                      {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string1));
    }
#line 1819 "yacc_sql.tab.c"
    break;

  case 31:
#line 322 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), false);
			delete (yyvsp[-1].ids1);
		}
#line 1829 "yacc_sql.tab.c"
    break;

  case 32:
#line 328 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-5].string1), (yyvsp[-3].string1), *(yyvsp[-1].ids1), true);
			delete (yyvsp[-1].ids1);
		}
#line 1839 "yacc_sql.tab.c"
    break;

  case 33:
#line 337 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string1));
		}
#line 1848 "yacc_sql.tab.c"
    break;

  case 34:
#line 344 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_SHOW_INDEX;//"show_index";
			show_index_init(&CONTEXT->ssql->sstr.show_index, (yyvsp[-1].string1));
		}
#line 1857 "yacc_sql.tab.c"
    break;

  case 35:
#line 351 "yacc_sql.y"
                {
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string1));
		}
#line 1867 "yacc_sql.tab.c"
    break;

  case 37:
#line 359 "yacc_sql.y"
                                   {    }
#line 1873 "yacc_sql.tab.c"
    break;

  case 38:
#line 364 "yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, AttrType((yyvsp[-3].number1)), (yyvsp[-1].number1));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;

		}
#line 1888 "yacc_sql.tab.c"
    break;

  case 39:
#line 375 "yacc_sql.y"
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
#line 1908 "yacc_sql.tab.c"
    break;

  case 40:
#line 391 "yacc_sql.y"
                {}
#line 1914 "yacc_sql.tab.c"
    break;

  case 41:
#line 393 "yacc_sql.y"
                {
			CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->ssql->sstr.create_table.attribute_count-1].nullable = true;
		}
#line 1922 "yacc_sql.tab.c"
    break;

  case 42:
#line 400 "yacc_sql.y"
        {
		(yyval.ids1) = new IdList();
		(yyval.ids1)->push_front((yyvsp[-1].string1));
	}
#line 1931 "yacc_sql.tab.c"
    break;

  case 43:
#line 405 "yacc_sql.y"
        {
		(yyval.ids1) = (yyvsp[0].ids1);
		(yyval.ids1)->push_front((yyvsp[-2].string1));
	}
#line 1940 "yacc_sql.tab.c"
    break;

  case 44:
#line 412 "yacc_sql.y"
                       {(yyval.number1) = atoi((yyvsp[0].string1));}
#line 1946 "yacc_sql.tab.c"
    break;

  case 45:
#line 415 "yacc_sql.y"
              { (yyval.number1)=INTS; }
#line 1952 "yacc_sql.tab.c"
    break;

  case 46:
#line 416 "yacc_sql.y"
                  { (yyval.number1)=CHARS; }
#line 1958 "yacc_sql.tab.c"
    break;

  case 47:
#line 417 "yacc_sql.y"
                 { (yyval.number1)=FLOATS; }
#line 1964 "yacc_sql.tab.c"
    break;

  case 48:
#line 418 "yacc_sql.y"
                    { (yyval.number1)=DATES; }
#line 1970 "yacc_sql.tab.c"
    break;

  case 49:
#line 419 "yacc_sql.y"
                    { (yyval.number1)=TEXTS; }
#line 1976 "yacc_sql.tab.c"
    break;

  case 50:
#line 423 "yacc_sql.y"
        {
		char *temp=(yyvsp[0].string1); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1985 "yacc_sql.tab.c"
    break;

  case 51:
#line 432 "yacc_sql.y"
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
#line 2001 "yacc_sql.tab.c"
    break;

  case 53:
#line 448 "yacc_sql.y"
        {	/* do nothing here */	}
#line 2007 "yacc_sql.tab.c"
    break;

  case 54:
#line 451 "yacc_sql.y"
                                       {
		(yyvsp[-1].values1)->push_front(*(yyvsp[-2].value1));
		inserts_row_init(&CONTEXT->ssql->sstr.insertion.rows[CONTEXT->ssql->sstr.insertion.row_num], *(yyvsp[-1].values1));
		(CONTEXT->ssql->sstr.insertion.row_num)++;

		delete (yyvsp[-2].value1);
		delete (yyvsp[-1].values1);
	}
#line 2020 "yacc_sql.tab.c"
    break;

  case 55:
#line 462 "yacc_sql.y"
                {
		(yyval.values1) = new ValueList();
	}
#line 2028 "yacc_sql.tab.c"
    break;

  case 56:
#line 465 "yacc_sql.y"
                                     { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
		(yyval.values1) = (yyvsp[0].values1);
		(yyval.values1)->push_front(*(yyvsp[-1].value1));

		delete (yyvsp[-1].value1);
	}
#line 2040 "yacc_sql.tab.c"
    break;

  case 57:
#line 474 "yacc_sql.y"
          {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), atoi((yyvsp[0].string1)), (yyvsp[0].string1));
		}
#line 2049 "yacc_sql.tab.c"
    break;

  case 58:
#line 478 "yacc_sql.y"
          {
  		(yyval.value1) = new Value();
		value_init_float((yyval.value1), (float)(atof((yyvsp[0].string1))), (yyvsp[0].string1));
		}
#line 2058 "yacc_sql.tab.c"
    break;

  case 59:
#line 482 "yacc_sql.y"
         {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
		}
#line 2068 "yacc_sql.tab.c"
    break;

  case 60:
#line 487 "yacc_sql.y"
               {
		(yyval.value1) = new Value();
		value_init_null((yyval.value1));
	}
#line 2077 "yacc_sql.tab.c"
    break;

  case 61:
#line 491 "yacc_sql.y"
                   {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
		value_init_date((yyval.value1), (yyvsp[0].string1));
	}
#line 2087 "yacc_sql.tab.c"
    break;

  case 62:
#line 499 "yacc_sql.y"
              {
		(yyval.value1) = (yyvsp[0].value1);
	}
#line 2095 "yacc_sql.tab.c"
    break;

  case 63:
#line 502 "yacc_sql.y"
                        {	
  		(yyval.value1) = new Value();
		value_init_integer((yyval.value1), -atoi((yyvsp[0].string1)), (yyvsp[0].string1));
	}
#line 2104 "yacc_sql.tab.c"
    break;

  case 64:
#line 509 "yacc_sql.y"
                 {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 2114 "yacc_sql.tab.c"
    break;

  case 65:
#line 514 "yacc_sql.y"
             {
		(yyvsp[0].string1) = substr((yyvsp[0].string1),1,strlen((yyvsp[0].string1))-2);
		(yyval.value1) = new Value();
  		value_init_string((yyval.value1), (yyvsp[0].string1));
	}
#line 2124 "yacc_sql.tab.c"
    break;

  case 66:
#line 523 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string1));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, *(yyvsp[-1].conditions1));

			delete (yyvsp[-1].conditions1);
    }
#line 2136 "yacc_sql.tab.c"
    break;

  case 67:
#line 533 "yacc_sql.y"
                {
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-3].string1), *(yyvsp[-1].conditions1));
			delete (yyvsp[-1].conditions1);
		}
#line 2146 "yacc_sql.tab.c"
    break;

  case 68:
#line 542 "yacc_sql.y"
                {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2155 "yacc_sql.tab.c"
    break;

  case 69:
#line 547 "yacc_sql.y"
                {
			update_append_attribute(&CONTEXT->ssql->sstr.update, (yyvsp[-2].string1), (yyvsp[0].updatevalue1));
			delete (yyvsp[0].updatevalue1);
		}
#line 2164 "yacc_sql.tab.c"
    break;

  case 70:
#line 554 "yacc_sql.y"
              {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_value((yyval.updatevalue1), (yyvsp[0].value1));
		delete (yyvsp[0].value1);
	}
#line 2174 "yacc_sql.tab.c"
    break;

  case 71:
#line 559 "yacc_sql.y"
                               {
		(yyval.updatevalue1) = new UpdateValue();
		updatevalue_init_select((yyval.updatevalue1), (yyvsp[-1].select1));
		delete (yyvsp[-1].select1);
	}
#line 2184 "yacc_sql.tab.c"
    break;

  case 72:
#line 568 "yacc_sql.y"
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
#line 2214 "yacc_sql.tab.c"
    break;

  case 73:
#line 594 "yacc_sql.y"
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
#line 2244 "yacc_sql.tab.c"
    break;

  case 74:
#line 619 "yacc_sql.y"
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
#line 2274 "yacc_sql.tab.c"
    break;

  case 75:
#line 648 "yacc_sql.y"
                                                   {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_ADD);
	}
#line 2283 "yacc_sql.tab.c"
    break;

  case 76:
#line 652 "yacc_sql.y"
                                                     {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_SUB);
	}
#line 2292 "yacc_sql.tab.c"
    break;

  case 77:
#line 656 "yacc_sql.y"
                                                   {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_MUL);
	}
#line 2301 "yacc_sql.tab.c"
    break;

  case 78:
#line 660 "yacc_sql.y"
                                                     {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), (yyvsp[-2].selectexpr1), (yyvsp[0].selectexpr1), ARITH_DIV);
	}
#line 2310 "yacc_sql.tab.c"
    break;

  case 79:
#line 664 "yacc_sql.y"
                   {
		(yyval.selectexpr1) = new SelectExpr();
		select_attr_init((yyval.selectexpr1), (yyvsp[0].attr1));
	}
#line 2319 "yacc_sql.tab.c"
    break;

  case 80:
#line 668 "yacc_sql.y"
                {
		(yyval.selectexpr1) = new SelectExpr();
		select_value_init((yyval.selectexpr1), (yyvsp[0].value1));
	}
#line 2328 "yacc_sql.tab.c"
    break;

  case 81:
#line 672 "yacc_sql.y"
                                          {
		(yyval.selectexpr1) = (yyvsp[-1].selectexpr1);
		(yyval.selectexpr1)->is_brace = true;
	}
#line 2337 "yacc_sql.tab.c"
    break;

  case 82:
#line 676 "yacc_sql.y"
                                                    {
		(yyval.selectexpr1) = new SelectExpr();
		select_subexpr_init((yyval.selectexpr1), nullptr, (yyvsp[0].selectexpr1), ARITH_NEG);
	}
#line 2346 "yacc_sql.tab.c"
    break;

  case 83:
#line 683 "yacc_sql.y"
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
#line 2362 "yacc_sql.tab.c"
    break;

  case 84:
#line 694 "yacc_sql.y"
                            {
		(yyval.selectexprs1) = new SelectExprList();
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2372 "yacc_sql.tab.c"
    break;

  case 85:
#line 699 "yacc_sql.y"
                                                   {
		(yyval.selectexprs1) = (yyvsp[-2].selectexprs1);
		(yyval.selectexprs1)->push_back(*(yyvsp[0].selectexpr1));
		delete (yyvsp[0].selectexpr1);
	}
#line 2382 "yacc_sql.tab.c"
    break;

  case 86:
#line 707 "yacc_sql.y"
                         {  
			RelAttr attr;
			relation_attr_init_with_aggregation(&attr, NULL, "*", AGG_NONE, true);
			if ((yyvsp[-1].string1) != nullptr) {
				attr.alias = strdup((yyvsp[-1].string1));
			}
			(yyvsp[0].attrs1)->push_front(attr);
			(yyval.attrs1) = (yyvsp[0].attrs1);
		}
#line 2396 "yacc_sql.tab.c"
    break;

  case 87:
#line 716 "yacc_sql.y"
                             {
		(yyvsp[0].attrs1)->push_front(*(yyvsp[-1].attr1));
		// selects_append_attribute(&CONTEXT->ssql->sstr.selection, *$2);
		delete((yyvsp[-1].attr1));
		(yyval.attrs1) = (yyvsp[0].attrs1);
	}
#line 2407 "yacc_sql.tab.c"
    break;

  case 88:
#line 725 "yacc_sql.y"
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
#line 2422 "yacc_sql.tab.c"
    break;

  case 89:
#line 735 "yacc_sql.y"
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
#line 2437 "yacc_sql.tab.c"
    break;

  case 90:
#line 745 "yacc_sql.y"
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
#line 2452 "yacc_sql.tab.c"
    break;

  case 91:
#line 755 "yacc_sql.y"
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
#line 2467 "yacc_sql.tab.c"
    break;

  case 92:
#line 765 "yacc_sql.y"
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
#line 2482 "yacc_sql.tab.c"
    break;

  case 93:
#line 775 "yacc_sql.y"
                            {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2491 "yacc_sql.tab.c"
    break;

  case 94:
#line 779 "yacc_sql.y"
                            {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2500 "yacc_sql.tab.c"
    break;

  case 95:
#line 783 "yacc_sql.y"
                            {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2509 "yacc_sql.tab.c"
    break;

  case 96:
#line 787 "yacc_sql.y"
                              {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2518 "yacc_sql.tab.c"
    break;

  case 97:
#line 791 "yacc_sql.y"
                            {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, NULL, AGG_NONE, false);
	}
#line 2527 "yacc_sql.tab.c"
    break;

  case 98:
#line 798 "yacc_sql.y"
                    {
		(yyval.string1) = nullptr;
	}
#line 2535 "yacc_sql.tab.c"
    break;

  case 99:
#line 801 "yacc_sql.y"
                {
		(yyval.string1) = (yyvsp[0].string1);
	}
#line 2543 "yacc_sql.tab.c"
    break;

  case 100:
#line 804 "yacc_sql.y"
             {
		(yyval.string1) = (yyvsp[0].string1);
	}
#line 2551 "yacc_sql.tab.c"
    break;

  case 101:
#line 810 "yacc_sql.y"
                 {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), NULL, (yyvsp[-1].string1), AGG_NONE,true);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2563 "yacc_sql.tab.c"
    break;

  case 102:
#line 817 "yacc_sql.y"
                          {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), (yyvsp[-3].string1), (yyvsp[-1].string1), AGG_NONE,true);

		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2576 "yacc_sql.tab.c"
    break;

  case 103:
#line 825 "yacc_sql.y"
                            {
		(yyval.attr1) = new RelAttr();
		relation_attr_init_with_aggregation((yyval.attr1), (yyvsp[-3].string1), "*", AGG_NONE,true);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2588 "yacc_sql.tab.c"
    break;

  case 104:
#line 832 "yacc_sql.y"
                                {
		(yyval.attr1) = (yyvsp[-1].attr1);
		if ((yyvsp[0].string1) != nullptr) {
			(yyval.attr1)->alias = strdup((yyvsp[0].string1));
		}
	}
#line 2599 "yacc_sql.tab.c"
    break;

  case 105:
#line 842 "yacc_sql.y"
        {
		(yyval.ocol_list1) = new OrderColList;
	}
#line 2607 "yacc_sql.tab.c"
    break;

  case 106:
#line 845 "yacc_sql.y"
                                            {
		(yyval.ocol_list1) = (yyvsp[0].ocol_list1);
		(yyval.ocol_list1)->push_front(*(yyvsp[-1].ocol1));
	}
#line 2616 "yacc_sql.tab.c"
    break;

  case 107:
#line 853 "yacc_sql.y"
        {
		(yyval.ocol_list1) = new OrderColList;
	}
#line 2624 "yacc_sql.tab.c"
    break;

  case 108:
#line 856 "yacc_sql.y"
                                         {
		(yyval.ocol_list1) = (yyvsp[0].ocol_list1);
		(yyval.ocol_list1)->push_front(*(yyvsp[-1].ocol1));
	}
#line 2633 "yacc_sql.tab.c"
    break;

  case 109:
#line 863 "yacc_sql.y"
                 {
		(yyval.ocol1) = (OrderCol *)malloc(sizeof(OrderCol));
		order_col_init((yyval.ocol1), (yyvsp[0].attr1), 1);
	}
#line 2642 "yacc_sql.tab.c"
    break;

  case 110:
#line 867 "yacc_sql.y"
                       {
		(yyval.ocol1) = (OrderCol *)malloc(sizeof(OrderCol));
		order_col_init((yyval.ocol1), (yyvsp[-1].attr1), 1);
	}
#line 2651 "yacc_sql.tab.c"
    break;

  case 111:
#line 871 "yacc_sql.y"
                        {
		(yyval.ocol1) = (OrderCol *)malloc(sizeof(OrderCol));
		order_col_init((yyval.ocol1), (yyvsp[-1].attr1), 0);
	}
#line 2660 "yacc_sql.tab.c"
    break;

  case 112:
#line 877 "yacc_sql.y"
                {
		(yyval.attrs1) = new AttrList();
	}
#line 2668 "yacc_sql.tab.c"
    break;

  case 113:
#line 880 "yacc_sql.y"
                                   {
		(yyval.attrs1) = (yyvsp[0].attrs1);
		(yyval.attrs1)->push_front(*(yyvsp[-1].attr1));
		delete (yyvsp[-1].attr1);
	}
#line 2678 "yacc_sql.tab.c"
    break;

  case 114:
#line 888 "yacc_sql.y"
                {
		(yyval.relations1) = new RelationList();
	}
#line 2686 "yacc_sql.tab.c"
    break;

  case 115:
#line 891 "yacc_sql.y"
                              {	
		Relation rel;
		relation_name_init(&rel, (yyvsp[-2].string1), (yyvsp[-1].string1));
		(yyval.relations1) = (yyvsp[0].relations1);
		(yyval.relations1)->push_back(rel);
	}
#line 2697 "yacc_sql.tab.c"
    break;

  case 116:
#line 900 "yacc_sql.y"
                                          {
		(yyval.joins1) = new JoinList();
		Join join;
		join_set_relation(&join, (yyvsp[-1].string1));
		join_append_conditions(&join, *(yyvsp[0].conditions1));
		(yyval.joins1)->push_back(join);

		delete (yyvsp[0].conditions1);
	}
#line 2711 "yacc_sql.tab.c"
    break;

  case 117:
#line 909 "yacc_sql.y"
                                                      {
		(yyval.joins1) = (yyvsp[0].joins1);
		Join join;
		join_set_relation(&join, (yyvsp[-2].string1));
		join_append_conditions(&join, *(yyvsp[-1].conditions1));
		(yyval.joins1)->push_front(join);

		delete (yyvsp[-1].conditions1);
	}
#line 2725 "yacc_sql.tab.c"
    break;

  case 118:
#line 921 "yacc_sql.y"
                                        {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));

		delete (yyvsp[-1].condition1);
	}
#line 2736 "yacc_sql.tab.c"
    break;

  case 119:
#line 930 "yacc_sql.y"
                   {
		(yyval.conditions1) = new ConditionList();
	}
#line 2744 "yacc_sql.tab.c"
    break;

  case 120:
#line 933 "yacc_sql.y"
                                              {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2754 "yacc_sql.tab.c"
    break;

  case 121:
#line 942 "yacc_sql.y"
                   {
		(yyval.groupby1) = nullptr;
	}
#line 2762 "yacc_sql.tab.c"
    break;

  case 122:
#line 945 "yacc_sql.y"
                                             {
		(yyval.groupby1) = new GroupBy();
		(yyvsp[-1].attrs1)->push_front(*(yyvsp[-2].attr1));
		delete (yyvsp[-2].attr1);
		group_init((yyval.groupby1), *(yyvsp[-1].attrs1), *(yyvsp[0].conditions1));
		delete (yyvsp[-1].attrs1);
		delete (yyvsp[0].conditions1);
	}
#line 2775 "yacc_sql.tab.c"
    break;

  case 123:
#line 956 "yacc_sql.y"
                {
		(yyval.conditions1) = new ConditionList();
	}
#line 2783 "yacc_sql.tab.c"
    break;

  case 124:
#line 959 "yacc_sql.y"
                                         {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2793 "yacc_sql.tab.c"
    break;

  case 125:
#line 967 "yacc_sql.y"
                                {
		(yyval.conditions1) = (yyvsp[0].conditions1);
	}
#line 2801 "yacc_sql.tab.c"
    break;

  case 126:
#line 972 "yacc_sql.y"
                          {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_expr((yyval.conditionexpr1), (yyvsp[0].selectexpr1));
	}
#line 2810 "yacc_sql.tab.c"
    break;

  case 127:
#line 977 "yacc_sql.y"
        {
		(yyval.conditionexpr1) = new ConditionExpr();
		condition_expr_init_sq((yyval.conditionexpr1), (yyvsp[-1].select1));
	}
#line 2819 "yacc_sql.tab.c"
    break;

  case 128:
#line 983 "yacc_sql.y"
                {
		(yyval.conditions1) = new ConditionList();
	}
#line 2827 "yacc_sql.tab.c"
    break;

  case 129:
#line 986 "yacc_sql.y"
                                       {
		(yyval.conditions1) = (yyvsp[0].conditions1);
		(yyval.conditions1)->push_front(*(yyvsp[-1].condition1));
		delete (yyvsp[-1].condition1);
	}
#line 2837 "yacc_sql.tab.c"
    break;

  case 130:
#line 994 "yacc_sql.y"
                               {
		(yyval.conditions1) = new ConditionList();
		(yyval.conditions1)->push_back(*(yyvsp[-2].condition1));
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[-2].condition1);
		delete (yyvsp[0].condition1);
	}
#line 2849 "yacc_sql.tab.c"
    break;

  case 131:
#line 1001 "yacc_sql.y"
                                         {
		(yyval.conditions1) = (yyvsp[-2].conditions1);
		(yyval.conditions1)->push_back(*(yyvsp[0].condition1));
		delete (yyvsp[0].condition1);
	}
#line 2859 "yacc_sql.tab.c"
    break;

  case 132:
#line 1009 "yacc_sql.y"
        {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2870 "yacc_sql.tab.c"
    break;

  case 133:
#line 1016 "yacc_sql.y"
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
#line 2887 "yacc_sql.tab.c"
    break;

  case 134:
#line 1029 "yacc_sql.y"
        {
		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-1].comp1)), (yyvsp[-2].conditionexpr1), (yyvsp[0].conditionexpr1));
		delete (yyvsp[-2].conditionexpr1);
		delete (yyvsp[0].conditionexpr1);
	}
#line 2898 "yacc_sql.tab.c"
    break;

  case 135:
#line 1035 "yacc_sql.y"
                                                           {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, (yyvsp[-4].selectexpr1));

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2913 "yacc_sql.tab.c"
    break;

  case 136:
#line 1046 "yacc_sql.y"
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
#line 2930 "yacc_sql.tab.c"
    break;

  case 137:
#line 1058 "yacc_sql.y"
                                           {
		ConditionExpr left_expr;
		condition_expr_init_expr(&left_expr, nullptr);

		ConditionExpr right_expr;
		condition_expr_init_sq(&right_expr, (yyvsp[-1].select1));

		(yyval.condition1) = new Condition();
		condition_init((yyval.condition1), CompOp((yyvsp[-3].comp1)), &left_expr, &right_expr);
	}
#line 2945 "yacc_sql.tab.c"
    break;

  case 138:
#line 1071 "yacc_sql.y"
             { (yyval.comp1) = EQUAL_TO; }
#line 2951 "yacc_sql.tab.c"
    break;

  case 139:
#line 1072 "yacc_sql.y"
         { (yyval.comp1) = LESS_THAN; }
#line 2957 "yacc_sql.tab.c"
    break;

  case 140:
#line 1073 "yacc_sql.y"
         { (yyval.comp1) = GREAT_THAN; }
#line 2963 "yacc_sql.tab.c"
    break;

  case 141:
#line 1074 "yacc_sql.y"
         { (yyval.comp1) = LESS_EQUAL; }
#line 2969 "yacc_sql.tab.c"
    break;

  case 142:
#line 1075 "yacc_sql.y"
         { (yyval.comp1) = GREAT_EQUAL; }
#line 2975 "yacc_sql.tab.c"
    break;

  case 143:
#line 1076 "yacc_sql.y"
         { (yyval.comp1) = NOT_EQUAL; }
#line 2981 "yacc_sql.tab.c"
    break;

  case 144:
#line 1080 "yacc_sql.y"
                   { (yyval.comp1) = UNLIKE_SCH; }
#line 2987 "yacc_sql.tab.c"
    break;

  case 145:
#line 1081 "yacc_sql.y"
               { (yyval.comp1) = LIKE_SCH; }
#line 2993 "yacc_sql.tab.c"
    break;

  case 146:
#line 1085 "yacc_sql.y"
           { (yyval.comp1) = IN_SQ; }
#line 2999 "yacc_sql.tab.c"
    break;

  case 147:
#line 1086 "yacc_sql.y"
                 { (yyval.comp1) = NOT_IN_SQ; }
#line 3005 "yacc_sql.tab.c"
    break;

  case 148:
#line 1090 "yacc_sql.y"
               { (yyval.comp1) = EXISTS_SQ; }
#line 3011 "yacc_sql.tab.c"
    break;

  case 149:
#line 1091 "yacc_sql.y"
                     { (yyval.comp1) = NOT_EXISTS_SQ; }
#line 3017 "yacc_sql.tab.c"
    break;

  case 150:
#line 1094 "yacc_sql.y"
             { (yyval.comp1) = IS_NULL; }
#line 3023 "yacc_sql.tab.c"
    break;

  case 151:
#line 1095 "yacc_sql.y"
                 { (yyval.comp1) = IS_NOT_NULL; }
#line 3029 "yacc_sql.tab.c"
    break;

  case 152:
#line 1100 "yacc_sql.y"
                {
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string1), (yyvsp[-4].string1));
		}
#line 3038 "yacc_sql.tab.c"
    break;


#line 3042 "yacc_sql.tab.c"

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
#line 1105 "yacc_sql.y"

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
