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


#line 114 "yacc_sql.cpp"

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
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_YACC_SQL_HPP_INCLUDED
# define YY_YY_YACC_SQL_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

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
    CALC = 264,
    SELECT = 265,
    DESC = 266,
    SHOW = 267,
    SYNC = 268,
    INSERT = 269,
    DELETE = 270,
    UPDATE = 271,
    LBRACE = 272,
    RBRACE = 273,
    COMMA = 274,
    TRX_BEGIN = 275,
    TRX_COMMIT = 276,
    TRX_ROLLBACK = 277,
    INT_T = 278,
    STRING_T = 279,
    FLOAT_T = 280,
    DATE_T = 281,
    HELP = 282,
    EXIT = 283,
    DOT = 284,
    INTO = 285,
    VALUES = 286,
    FROM = 287,
    WHERE = 288,
    AND = 289,
    OR = 290,
    SET = 291,
    ON = 292,
    LOAD = 293,
    DATA = 294,
    INFILE = 295,
    EXPLAIN = 296,
    EQ = 297,
    LT = 298,
    GT = 299,
    LE = 300,
    GE = 301,
    NE = 302,
    NOT = 303,
    LIKE = 304,
    INNER = 305,
    JOIN = 306,
    UNIQUE = 307,
    MAX = 308,
    MIN = 309,
    SUM = 310,
    COUNT = 311,
    AVG = 312,
    LENGTH = 313,
    ROUND = 314,
    DATE_FORMAT = 315,
    IN = 316,
    EXISTS = 317,
    GROUP = 318,
    HAVING = 319,
    AS = 320,
    ORDER = 321,
    BY = 322,
    ASC = 323,
    IS = 324,
    NULL_LITERAL = 325,
    NULLABLE = 326,
    NUMBER = 327,
    FLOAT = 328,
    DATE = 329,
    ID = 330,
    SSS = 331,
    UMINUS = 332
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 132 "yacc_sql.y"

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

#line 277 "yacc_sql.cpp"

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

#define YYUNDEFTOK  2
#define YYMAXUTOK   332


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
       2,     2,    79,    77,     2,    78,     2,    80,     2,     2,
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
      75,    76,    81
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   239,   239,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   271,   277,   282,   288,   294,   300,
     306,   313,   319,   328,   336,   339,   345,   351,   359,   374,
     384,   404,   407,   419,   422,   425,   428,   434,   443,   458,
     461,   462,   463,   464,   468,   471,   474,   480,   495,   498,
     502,   508,   514,   525,   529,   533,   538,   543,   550,   562,
     579,   586,   622,   659,   670,   680,   696,   703,   710,   717,
     724,   730,   736,   744,   771,   781,   789,   794,   801,   810,
     815,   821,   827,   833,   840,   846,   855,   868,   871,   885,
     888,   901,   904,   910,   915,   920,   928,   935,   944,   954,
     964,   974,   983,   991,   999,  1009,  1019,  1026,  1033,  1040,
    1047,  1055,  1066,  1067,  1068,  1069,  1070,  1071,  1075,  1078,
    1084,  1087,  1100,  1103,  1111,  1114,  1126,  1129,  1137,  1140,
    1148,  1153,  1158,  1166,  1173,  1183,  1189,  1198,  1206,  1217,
    1230,  1238,  1248,  1249
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "CREATE", "DROP", "TABLE",
  "TABLES", "INDEX", "CALC", "SELECT", "DESC", "SHOW", "SYNC", "INSERT",
  "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "OR",
  "SET", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN", "EQ", "LT", "GT", "LE",
  "GE", "NE", "NOT", "LIKE", "INNER", "JOIN", "UNIQUE", "MAX", "MIN",
  "SUM", "COUNT", "AVG", "LENGTH", "ROUND", "DATE_FORMAT", "IN", "EXISTS",
  "GROUP", "HAVING", "AS", "ORDER", "BY", "ASC", "IS", "NULL_LITERAL",
  "NULLABLE", "NUMBER", "FLOAT", "DATE", "ID", "SSS", "'+'", "'-'", "'*'",
  "'/'", "UMINUS", "$accept", "commands", "command_wrapper", "exit_stmt",
  "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "show_index_stmt",
  "desc_table_stmt", "is_unique", "id_list", "create_index_stmt",
  "drop_index_stmt", "create_table_stmt", "attr_def_list", "is_nullable",
  "attr_def", "number", "type", "alias", "insert_stmt", "value_list_cell",
  "value_list", "value", "delete_stmt", "update_stmt", "select_stmt",
  "select", "calc_stmt", "expression_list", "expression", "select_attr",
  "rel_attr", "dyn_node", "relation", "attr_list", "rel_list", "where",
  "or_where", "condition_list", "or_condition_list", "condition",
  "comp_op", "join_conditions", "join_list", "having", "groupby",
  "orderby", "orderby_list", "orderby_col", "insert_row_list",
  "update_list", "update_pair", "load_data_stmt", "explain_stmt",
  "set_variable_stmt", "opt_semicolon", YY_NULLPTR
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
     325,   326,   327,   328,   329,   330,   331,    43,    45,    42,
      47,   332
};
# endif

#define YYPACT_NINF (-206)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     319,     7,    17,   174,    80,   -59,    25,  -206,    13,    19,
     -34,  -206,  -206,  -206,  -206,  -206,    -2,    39,   319,    86,
      93,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,    28,  -206,   103,    41,    43,   174,   102,
     104,   106,   108,   114,  -206,  -206,  -206,  -206,   109,  -206,
     174,  -206,  -206,    99,  -206,  -206,  -206,  -206,   112,  -206,
    -206,   115,    73,    74,   121,   118,   132,  -206,  -206,  -206,
    -206,   144,   100,  -206,   147,    11,   111,   111,   111,   -51,
     111,   -45,  -206,   117,  -206,   174,   174,   174,   174,   168,
     119,   120,   158,   165,   125,     3,    69,   123,   131,   153,
     133,  -206,   191,   193,   194,   196,   197,   198,  -206,  -206,
    -206,   -30,   -30,  -206,  -206,   174,   -44,   206,  -206,   219,
     148,  -206,   195,  -206,   125,  -206,  -206,   209,   157,   221,
     166,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
     119,   192,   -18,  -206,     9,   183,   234,   242,  -206,   224,
      54,  -206,   254,  -206,  -206,  -206,  -206,    92,   131,   243,
     245,   206,   212,   231,   -26,  -206,    57,  -206,   247,   249,
     257,  -206,  -206,  -206,  -206,  -206,  -206,   -22,   174,   251,
     -28,   200,   148,   257,  -206,   202,   199,   222,  -206,  -206,
    -206,   221,  -206,   218,  -206,   220,   148,   244,   244,  -206,
    -206,   250,   -18,   124,   257,   276,   174,   280,   155,    34,
     235,  -206,     9,   155,  -206,   288,  -206,  -206,   290,  -206,
    -206,   291,   294,   272,  -206,    64,   246,   248,   248,   219,
    -206,   226,   297,  -206,   155,    34,    83,   298,  -206,   299,
    -206,   -33,   218,  -206,   148,   192,   148,   111,   258,  -206,
    -206,  -206,     9,   155,  -206,    96,   300,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,   292,   307,   111,   318,  -206,
    -206,   111,   273,     0,   323,  -206,   307,   148,  -206,  -206,
    -206,   111,  -206,  -206,  -206,   323,  -206
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
     152,    23,    22,    15,    16,    17,    18,     9,    10,    12,
      11,    13,    14,     8,     5,     7,     6,     4,    70,     3,
      19,    20,    21,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    63,    64,    65,    86,    66,
       0,    82,    73,    54,    89,    83,    84,    85,     0,    33,
      31,     0,     0,     0,     0,     0,     0,   150,     1,   153,
       2,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,    55,     0,     0,     0,     0,    74,
       0,     0,     0,   101,     0,   101,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,    87,    88,
      56,    76,    77,    78,    79,     0,    54,    99,    32,     0,
       0,    68,     0,   145,     0,    69,   151,     0,     0,    41,
       0,    39,    90,    91,    95,    93,    92,    94,    75,    96,
       0,   130,     0,    57,     0,     0,     0,     0,   102,   104,
       0,   146,     0,    50,    51,    52,    53,    43,     0,     0,
       0,    99,     0,   101,     0,    61,     0,    58,     0,     0,
       0,   122,   123,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,   147,     0,     0,     0,    46,    45,
      48,    41,    40,     0,   100,     0,     0,   134,   134,    59,
      60,   143,     0,     0,     0,     0,     0,     0,   120,     0,
       0,   119,     0,   108,   105,     0,   149,    49,     0,    44,
      42,    36,     0,   128,   103,   104,     0,   136,   136,     0,
      62,     0,     0,   116,   121,     0,     0,     0,   118,     0,
     148,    43,     0,    38,     0,   130,     0,     0,     0,    71,
      72,   144,     0,   109,   117,     0,     0,   114,   112,   110,
      47,    37,   129,   131,   107,   106,    97,     0,     0,   115,
     113,     0,   132,   140,   138,   111,    97,     0,   135,   142,
     141,     0,   137,    98,   133,   138,   139
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,   320,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,    91,  -206,  -206,  -206,   143,    94,
     180,  -206,  -206,   223,  -206,  -142,  -205,   -99,  -206,  -206,
    -206,  -145,  -206,     4,    -3,  -206,   -84,  -206,   201,    66,
     179,   -93,  -206,  -182,    97,  -189,   141,  -206,   101,  -206,
     150,   126,    67,    68,   122,  -206,   229,  -206,  -206,  -206,
    -206
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    45,   232,    31,    32,    33,   169,   200,
     139,   228,   167,    99,    34,   175,   176,    61,    35,    36,
      37,    38,    39,    62,   157,    68,    64,    65,   127,   282,
     151,   131,   208,   158,   234,   159,   191,   255,   173,   288,
     237,   259,   292,   284,   153,   105,   133,    40,    41,    42,
      80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    63,   112,   113,   114,   116,   117,   136,    67,   178,
     224,   289,   135,    43,   246,   197,    69,   235,   194,     4,
     220,    93,   134,    46,    58,    47,    48,   216,   115,   111,
     118,    94,    70,    71,   119,   215,   130,   198,   199,   217,
     265,    74,   221,    72,     4,    85,   209,   210,   225,    97,
      98,    73,    54,   177,    55,    56,    57,    92,    59,    44,
     174,   177,    49,    50,    51,    52,    53,   275,   290,   242,
     240,   193,   272,    75,   247,   211,   212,   249,    76,    54,
     207,    55,    56,    57,    58,    59,    78,    60,    95,    96,
      97,    98,   121,   122,   123,   124,    79,    48,   192,   256,
     266,   267,   212,    81,    54,   294,    55,    56,    57,   196,
      59,    82,   174,   177,   279,   212,    83,   278,    84,    86,
     177,    87,    63,    88,    54,    89,    55,    56,    57,   148,
      59,    90,   174,    49,    50,    51,    52,    53,    91,    54,
     197,    55,    56,    57,   100,    59,   177,   101,   102,   103,
      54,    85,    55,    56,    57,    58,    59,   104,    60,    66,
     106,   108,   198,   199,    93,   154,   181,   182,   183,   184,
     185,   186,   107,   276,    94,   109,    95,    96,    97,    98,
     163,   164,   165,   166,   110,   218,    58,   125,   223,   129,
     140,    48,   120,   283,   126,   128,   155,   286,   130,   137,
     132,    49,    50,    51,    52,    53,   138,   283,   141,   142,
     156,   143,   144,   244,   145,   146,   147,   222,    54,    85,
      55,    56,    57,    58,    59,   150,    60,    49,    50,    51,
      52,    53,    95,    96,    97,    98,   152,   160,   263,   162,
     168,   170,   172,   262,    54,   179,    55,    56,    57,    58,
      59,   180,    60,    49,    50,    51,    52,    53,   192,    85,
     195,   202,   203,   205,   206,   213,   214,     4,   219,   239,
      54,   227,    55,    56,    57,    58,    59,   226,    60,    49,
      50,    51,    52,    53,   181,   182,   183,   184,   185,   186,
     187,   188,   229,   231,   243,   233,    54,   245,    55,    56,
      57,    58,    59,   189,    60,   248,   250,   236,   251,   254,
     252,   190,   253,   257,   258,   264,   268,   269,   280,    95,
      96,    97,    98,     1,     2,   277,   281,   256,     3,     4,
       5,     6,     7,     8,     9,    10,   285,   287,    77,    11,
      12,    13,   291,   271,   230,   270,    14,    15,   201,   149,
     204,   171,   293,   274,   241,    16,   273,    17,   238,   295,
      18,   261,   296,   161,   260
};

static const yytype_int16 yycheck[] =
{
       3,     4,    86,    87,    88,    89,    90,   106,     4,   154,
     192,    11,   105,     6,   219,    48,    75,   206,   160,    10,
      48,    65,    19,     6,    75,     8,    17,    49,    79,    18,
      75,    75,     7,     8,    79,   180,    33,    70,    71,    61,
     245,    75,    70,    30,    10,    48,    72,    73,   193,    79,
      80,    32,    70,   152,    72,    73,    74,    60,    76,    52,
      78,   160,    53,    54,    55,    56,    57,   256,    68,   214,
     212,    17,   254,    75,   219,    18,    19,   222,    39,    70,
     173,    72,    73,    74,    75,    76,     0,    78,    77,    78,
      79,    80,    95,    96,    97,    98,     3,    17,    34,    35,
     245,    18,    19,    75,    70,   287,    72,    73,    74,    17,
      76,     8,    78,   212,    18,    19,    75,   262,    75,    17,
     219,    17,   125,    17,    70,    17,    72,    73,    74,   125,
      76,    17,    78,    53,    54,    55,    56,    57,    29,    70,
      48,    72,    73,    74,    32,    76,   245,    32,    75,    75,
      70,   154,    72,    73,    74,    75,    76,    36,    78,    79,
      42,    17,    70,    71,    65,    17,    42,    43,    44,    45,
      46,    47,    40,   257,    75,    75,    77,    78,    79,    80,
      23,    24,    25,    26,    37,   188,    75,    19,   191,    31,
      37,    17,    75,   277,    75,    75,    48,   281,    33,    76,
      75,    53,    54,    55,    56,    57,    75,   291,    75,    18,
      62,    18,    18,   216,    18,    18,    18,    17,    70,   222,
      72,    73,    74,    75,    76,    19,    78,    53,    54,    55,
      56,    57,    77,    78,    79,    80,    17,    42,   241,    30,
      19,    75,    50,    17,    70,    62,    72,    73,    74,    75,
      76,    17,    78,    53,    54,    55,    56,    57,    34,   262,
       6,    18,    17,    51,    33,    18,    17,    10,    17,    19,
      70,    72,    72,    73,    74,    75,    76,    75,    78,    53,
      54,    55,    56,    57,    42,    43,    44,    45,    46,    47,
      48,    49,    70,    75,    18,    75,    70,    17,    72,    73,
      74,    75,    76,    61,    78,    70,    18,    63,    18,    37,
      19,    69,    18,    67,    66,    18,    18,    18,    18,    77,
      78,    79,    80,     4,     5,    67,    19,    35,     9,    10,
      11,    12,    13,    14,    15,    16,    18,    64,    18,    20,
      21,    22,    19,   252,   201,   251,    27,    28,   168,   126,
     171,   150,   286,   256,   213,    36,   255,    38,   208,   291,
      41,   239,   295,   134,   238
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     9,    10,    11,    12,    13,    14,    15,
      16,    20,    21,    22,    27,    28,    36,    38,    41,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    97,    98,    99,   106,   110,   111,   112,   113,   114,
     139,   140,   141,     6,    52,    95,     6,     8,    17,    53,
      54,    55,    56,    57,    70,    72,    73,    74,    75,    76,
      78,   109,   115,   116,   118,   119,    79,   115,   117,    75,
       7,     8,    30,    32,    75,    75,    39,    84,     0,     3,
     142,    75,     8,    75,    75,   116,    17,    17,    17,    17,
      17,    29,   116,    65,    75,    77,    78,    79,    80,   105,
      32,    32,    75,    75,    36,   137,    42,    40,    17,    75,
      37,    18,   118,   118,   118,    79,   118,   118,    75,    79,
      75,   116,   116,   116,   116,    19,    75,   120,    75,    31,
      33,   123,    75,   138,    19,   123,   109,    76,    75,   102,
      37,    75,    18,    18,    18,    18,    18,    18,   115,   105,
      19,   122,    17,   136,    17,    48,    62,   116,   125,   127,
      42,   138,    30,    23,    24,    25,    26,   104,    19,   100,
      75,   120,    50,   130,    78,   107,   108,   109,   113,    62,
      17,    42,    43,    44,    45,    46,    47,    48,    49,    61,
      69,   128,    34,    17,   107,     6,    17,    48,    70,    71,
     101,   102,    18,    17,   122,    51,    33,   123,   124,    72,
      73,    18,    19,    18,    17,   113,    49,    61,   116,    17,
      48,    70,    17,   116,   125,   113,    75,    72,   103,    70,
     100,    75,    96,    75,   126,   127,    63,   132,   132,    19,
     107,   128,   113,    18,   116,    17,   108,   113,    70,   113,
      18,    18,    19,    18,    37,   129,    35,    67,    66,   133,
     133,   136,    17,   116,    18,   108,   113,    18,    18,    18,
     101,    96,   125,   130,   126,   127,   118,    67,   113,    18,
      18,    19,   121,   118,   135,    18,   118,    64,   131,    11,
      68,    19,   134,   121,   125,   135,   134
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    95,    96,    96,    97,    98,
      99,   100,   100,   101,   101,   101,   101,   102,   102,   103,
     104,   104,   104,   104,   105,   105,   105,   106,   107,   107,
     107,   108,   108,   109,   109,   109,   109,   109,   110,   111,
     112,   113,   113,   114,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   117,   117,   118,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   120,   121,   121,   122,
     122,   123,   123,   124,   125,   125,   126,   126,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     140,   141,   142,   142
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     4,     2,     0,     1,     1,     3,     9,     5,
       7,     0,     3,     0,     2,     1,     1,     6,     3,     1,
       1,     1,     1,     1,     0,     1,     2,     5,     1,     2,
       2,     1,     3,     1,     1,     1,     1,     1,     4,     4,
       1,     9,     9,     2,     2,     4,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     3,     3,     1,
       4,     4,     4,     4,     4,     4,     2,     0,     3,     0,
       3,     0,     2,     2,     1,     3,     3,     3,     3,     5,
       5,     7,     5,     6,     5,     6,     4,     5,     4,     3,
       3,     4,     1,     1,     1,     1,     1,     1,     0,     2,
       0,     5,     0,     2,     0,     5,     0,     4,     0,     3,
       1,     2,     2,     3,     5,     2,     3,     3,     5,     7,
       2,     4,     0,     1
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
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (sql_string);
  YYUSE (sql_result);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, sql_string, sql_result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (sql_string);
  YYUSE (sql_result);
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
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 240 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1819 "yacc_sql.cpp"
    break;

  case 24:
#line 271 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1828 "yacc_sql.cpp"
    break;

  case 25:
#line 277 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1836 "yacc_sql.cpp"
    break;

  case 26:
#line 282 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1844 "yacc_sql.cpp"
    break;

  case 27:
#line 288 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1852 "yacc_sql.cpp"
    break;

  case 28:
#line 294 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1860 "yacc_sql.cpp"
    break;

  case 29:
#line 300 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1868 "yacc_sql.cpp"
    break;

  case 30:
#line 306 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1878 "yacc_sql.cpp"
    break;

  case 31:
#line 313 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1886 "yacc_sql.cpp"
    break;

  case 32:
#line 320 "yacc_sql.y"
                {
			(yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
			(yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
		}
#line 1896 "yacc_sql.cpp"
    break;

  case 33:
#line 328 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1906 "yacc_sql.cpp"
    break;

  case 34:
#line 336 "yacc_sql.y"
              {
    (yyval.bools) = false;
  }
#line 1914 "yacc_sql.cpp"
    break;

  case 35:
#line 339 "yacc_sql.y"
           {
    (yyval.bools) = true;
  }
#line 1922 "yacc_sql.cpp"
    break;

  case 36:
#line 345 "yacc_sql.y"
     {
    (yyval.id_list) = new std::deque<std::string>();
    std::string attribute_name = (yyvsp[0].string);
    free((yyvsp[0].string));
    (yyval.id_list)->emplace_back(attribute_name);
  }
#line 1933 "yacc_sql.cpp"
    break;

  case 37:
#line 351 "yacc_sql.y"
                     {
    (yyval.id_list) = (yyvsp[0].id_list);
    std::string attribute_name = (yyvsp[-2].string);
    free((yyvsp[-2].string));
    (yyval.id_list)->emplace_front(attribute_name);
  }
#line 1944 "yacc_sql.cpp"
    break;

  case 38:
#line 360 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_names = std::move(*(yyvsp[-1].id_list));
      create_index.is_unique = (yyvsp[-7].bools);
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      delete (yyvsp[-1].id_list);
    }
#line 1960 "yacc_sql.cpp"
    break;

  case 39:
#line 375 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1972 "yacc_sql.cpp"
    break;

  case 40:
#line 385 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::deque<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_front(std::move(*(yyvsp[-2].attr_info)));
      // std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);
      delete (yyvsp[-1].attr_infos);
    }
#line 1993 "yacc_sql.cpp"
    break;

  case 41:
#line 404 "yacc_sql.y"
    {
      (yyval.attr_infos) = new std::deque<AttrInfoSqlNode>;
    }
#line 2001 "yacc_sql.cpp"
    break;

  case 42:
#line 408 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::deque<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_front(std::move(*(yyvsp[-1].attr_info)));
      delete (yyvsp[-1].attr_info);
    }
#line 2015 "yacc_sql.cpp"
    break;

  case 43:
#line 419 "yacc_sql.y"
              {
    (yyval.number) = -1;
  }
#line 2023 "yacc_sql.cpp"
    break;

  case 44:
#line 422 "yacc_sql.y"
                     {
    (yyval.number) = 0;
  }
#line 2031 "yacc_sql.cpp"
    break;

  case 45:
#line 425 "yacc_sql.y"
             {
    (yyval.number) = 1;
  }
#line 2039 "yacc_sql.cpp"
    break;

  case 46:
#line 428 "yacc_sql.y"
                 {
    (yyval.number) = 1;
  }
#line 2047 "yacc_sql.cpp"
    break;

  case 47:
#line 435 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->unsolved = (yyvsp[0].number);
      free((yyvsp[-5].string));
    }
#line 2060 "yacc_sql.cpp"
    break;

  case 48:
#line 444 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      if ((AttrType)(yyvsp[-1].number) == AttrType::DATES) {
        (yyval.attr_info)->length = 12;
      } else {
        (yyval.attr_info)->length = 4;
      }
      (yyval.attr_info)->unsolved = (yyvsp[0].number);
      free((yyvsp[-2].string));
    }
#line 2077 "yacc_sql.cpp"
    break;

  case 49:
#line 458 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2083 "yacc_sql.cpp"
    break;

  case 50:
#line 461 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2089 "yacc_sql.cpp"
    break;

  case 51:
#line 462 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2095 "yacc_sql.cpp"
    break;

  case 52:
#line 463 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2101 "yacc_sql.cpp"
    break;

  case 53:
#line 464 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2107 "yacc_sql.cpp"
    break;

  case 54:
#line 468 "yacc_sql.y"
              {
    (yyval.string) = nullptr;
  }
#line 2115 "yacc_sql.cpp"
    break;

  case 55:
#line 471 "yacc_sql.y"
       {
    (yyval.string) = (yyvsp[0].string);
  }
#line 2123 "yacc_sql.cpp"
    break;

  case 56:
#line 474 "yacc_sql.y"
          {
    (yyval.string) = (yyvsp[0].string);
  }
#line 2131 "yacc_sql.cpp"
    break;

  case 57:
#line 481 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-2].string);
      if ((yyvsp[0].insert_row_list) != nullptr) {
        (yyval.sql_node)->insertion.rows.swap(*(yyvsp[0].insert_row_list));
        delete (yyvsp[0].insert_row_list);
      }
      // $$->insertion.values.emplace_front(std::move(*$6);
      // std::reverse($$->insertion.values.begin(), $$->insertion.values.end());
      free((yyvsp[-2].string));
    }
#line 2147 "yacc_sql.cpp"
    break;

  case 58:
#line 495 "yacc_sql.y"
        {
    (yyval.value) = (yyvsp[0].value);
  }
#line 2155 "yacc_sql.cpp"
    break;

  case 59:
#line 498 "yacc_sql.y"
               {
    (yyval.value) = new Value(-(int)(yyvsp[0].number));
    // @$ = @1;
  }
#line 2164 "yacc_sql.cpp"
    break;

  case 60:
#line 502 "yacc_sql.y"
              {
    (yyval.value) = new Value(-(float)(yyvsp[0].floats));
    // @$ = @1;
  }
#line 2173 "yacc_sql.cpp"
    break;

  case 61:
#line 509 "yacc_sql.y"
    {
      (yyval.value_list) = new std::deque<Value>;
      (yyval.value_list)->emplace_back(std::move(*(yyvsp[0].value)));
      delete (yyvsp[0].value);
    }
#line 2183 "yacc_sql.cpp"
    break;

  case 62:
#line 514 "yacc_sql.y"
                                        { 
      if ((yyvsp[-2].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[-2].value_list);
      } else {
        (yyval.value_list) = new std::deque<Value>;
      }
      (yyval.value_list)->emplace_back(std::move(*(yyvsp[0].value)));
      delete (yyvsp[0].value);
    }
#line 2197 "yacc_sql.cpp"
    break;

  case 63:
#line 525 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2206 "yacc_sql.cpp"
    break;

  case 64:
#line 529 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2215 "yacc_sql.cpp"
    break;

  case 65:
#line 533 "yacc_sql.y"
          {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp, true, true);
      free(tmp);
    }
#line 2225 "yacc_sql.cpp"
    break;

  case 66:
#line 538 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2235 "yacc_sql.cpp"
    break;

  case 67:
#line 543 "yacc_sql.y"
                  {
      (yyval.value) = new Value(0);
      (yyval.value)->set_null(true);
    }
#line 2244 "yacc_sql.cpp"
    break;

  case 68:
#line 551 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2258 "yacc_sql.cpp"
    break;

  case 69:
#line 563 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-2].string);
      if ((yyvsp[-1].update_pair_list) != nullptr) {
        (yyval.sql_node)->update.attr_values.swap(*(yyvsp[-1].update_pair_list));
        delete (yyvsp[-1].update_pair_list);
      }
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-2].string));
    }
#line 2276 "yacc_sql.cpp"
    break;

  case 70:
#line 579 "yacc_sql.y"
           {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      (yyval.sql_node)->selection = std::move(*(yyvsp[0].select));
      delete (yyvsp[0].select);
    }
#line 2286 "yacc_sql.cpp"
    break;

  case 71:
#line 587 "yacc_sql.y"
    {
      (yyval.select) = new SelectSqlNode;
      (yyval.select)->condtion_is_or = false;
      if ((yyvsp[-7].expression_list) != nullptr) {
        (yyval.select)->select_exprs.swap(*(yyvsp[-7].expression_list));
        delete (yyvsp[-7].expression_list);
      }
      if ((yyvsp[-4].relation_list) != nullptr) {
        (yyval.select)->relations.swap(*(yyvsp[-4].relation_list));
        delete (yyvsp[-4].relation_list);
      }
      (yyval.select)->relations.push_front(std::move(*(yyvsp[-5].relation)));
      // std::reverse($$->selection.relations.begin(), $$->selection.relations.end());
      delete (yyvsp[-5].relation);
      if ((yyvsp[-3].join_list) != nullptr) {
        (yyval.select)->joins.swap(*(yyvsp[-3].join_list));
        delete (yyvsp[-3].join_list);
      }

      if ((yyvsp[-2].condition_list) != nullptr) {
        (yyval.select)->conditions.swap(*(yyvsp[-2].condition_list));
        delete (yyvsp[-2].condition_list);
      }

      if ((yyvsp[-1].groupby) != nullptr) {
        (yyval.select)->group_by = std::move(*(yyvsp[-1].groupby));
        delete (yyvsp[-1].groupby);
      }

      if ((yyvsp[0].orderby_list) != nullptr) {
        (yyval.select)->order_bys.swap(*(yyvsp[0].orderby_list));
        delete (yyvsp[0].orderby_list);
      }

    }
#line 2326 "yacc_sql.cpp"
    break;

  case 72:
#line 622 "yacc_sql.y"
                                                                                   {
      (yyval.select) = new SelectSqlNode;
      (yyval.select)->condtion_is_or = true;
      if ((yyvsp[-7].expression_list) != nullptr) {
        (yyval.select)->select_exprs.swap(*(yyvsp[-7].expression_list));
        delete (yyvsp[-7].expression_list);
      }
      if ((yyvsp[-4].relation_list) != nullptr) {
        (yyval.select)->relations.swap(*(yyvsp[-4].relation_list));
        delete (yyvsp[-4].relation_list);
      }
      (yyval.select)->relations.push_front(std::move(*(yyvsp[-5].relation)));
      delete (yyvsp[-5].relation);
      // std::reverse($$->selection.relations.begin(), $$->selection.relations.end());

      if ((yyvsp[-3].join_list) != nullptr) {
        (yyval.select)->joins.swap(*(yyvsp[-3].join_list));
        delete (yyvsp[-3].join_list);
      }

      if ((yyvsp[-2].condition_list) != nullptr) {
        (yyval.select)->conditions.swap(*(yyvsp[-2].condition_list));
        delete (yyvsp[-2].condition_list);
      }

      if ((yyvsp[-1].groupby) != nullptr) {
        (yyval.select)->group_by = std::move(*(yyvsp[-1].groupby));
        delete (yyvsp[-1].groupby);
      }

      if ((yyvsp[0].orderby_list) != nullptr) {
        (yyval.select)->order_bys.swap(*(yyvsp[0].orderby_list));
        delete (yyvsp[0].orderby_list);
      }
    }
#line 2366 "yacc_sql.cpp"
    break;

  case 73:
#line 660 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      // std::reverse($2->begin(), $2->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2377 "yacc_sql.cpp"
    break;

  case 74:
#line 671 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::deque<ExprSqlNode>;
      if ((yyvsp[0].string) != nullptr) {
        (yyvsp[-1].expression)->alias = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
      (yyval.expression_list)->emplace_back(std::move(*(yyvsp[-1].expression)));
      delete (yyvsp[-1].expression);
    }
#line 2391 "yacc_sql.cpp"
    break;

  case 75:
#line 681 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::deque<ExprSqlNode>;
      }
      if ((yyvsp[-2].string) != nullptr) {
        (yyvsp[-3].expression)->alias = (yyvsp[-2].string);
        free((yyvsp[-2].string));
      }
      (yyval.expression_list)->emplace_front(std::move(*(yyvsp[-3].expression)));
      delete (yyvsp[-3].expression);
    }
#line 2409 "yacc_sql.cpp"
    break;

  case 76:
#line 696 "yacc_sql.y"
                              {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_ADD;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2421 "yacc_sql.cpp"
    break;

  case 77:
#line 703 "yacc_sql.y"
                                {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_SUB;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2433 "yacc_sql.cpp"
    break;

  case 78:
#line 710 "yacc_sql.y"
                                {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_MUL;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2445 "yacc_sql.cpp"
    break;

  case 79:
#line 717 "yacc_sql.y"
                                {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_DIV;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2457 "yacc_sql.cpp"
    break;

  case 80:
#line 724 "yacc_sql.y"
                               {
      // $$ = $2;
      // $$->set_name(token_name(sql_string, &@$));
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->has_brace = true;
    }
#line 2468 "yacc_sql.cpp"
    break;

  case 81:
#line 730 "yacc_sql.y"
                                  {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, $2, nullptr, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_NEGATIVE;
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2479 "yacc_sql.cpp"
    break;

  case 82:
#line 736 "yacc_sql.y"
            {
      // $$ = new ValueExpr(std::move(*$1);
      // $$->set_name(token_name(sql_string, &@$));
      // delete $1;
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_VAL;
      (yyval.expression)->value = std::unique_ptr<Value>((yyvsp[0].value));
    }
#line 2492 "yacc_sql.cpp"
    break;

  case 83:
#line 744 "yacc_sql.y"
               {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_DYN;
      (yyval.expression)->attr = std::unique_ptr<DynNodeSqlNode>((yyvsp[0].dyn_node));
    }
#line 2502 "yacc_sql.cpp"
    break;

  case 84:
#line 771 "yacc_sql.y"
      {
    (yyval.expression_list) = new std::deque<ExprSqlNode>();
    ExprSqlNode expr;
    expr.type = ExprNodeType::E_DYN;
    expr.attr = std::unique_ptr<DynNodeSqlNode>(new DynNodeSqlNode);

    expr.attr->node.attribute_name = "*";
    
    (yyval.expression_list)->push_back(std::move(expr));
  }
#line 2517 "yacc_sql.cpp"
    break;

  case 85:
#line 781 "yacc_sql.y"
                    {
    (yyval.expression_list) = (yyvsp[0].expression_list);
    // $2->push_front(std::move(*$1);
    // delete $1;
  }
#line 2527 "yacc_sql.cpp"
    break;

  case 86:
#line 789 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2537 "yacc_sql.cpp"
    break;

  case 87:
#line 794 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2549 "yacc_sql.cpp"
    break;

  case 88:
#line 801 "yacc_sql.y"
                 {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = "*";
      free((yyvsp[-2].string));
    }
#line 2560 "yacc_sql.cpp"
    break;

  case 89:
#line 810 "yacc_sql.y"
           {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->node = std::move(*(yyvsp[0].rel_attr));
    delete (yyvsp[0].rel_attr);
  }
#line 2570 "yacc_sql.cpp"
    break;

  case 90:
#line 815 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_MAX;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2581 "yacc_sql.cpp"
    break;

  case 91:
#line 821 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_MIN;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2592 "yacc_sql.cpp"
    break;

  case 92:
#line 827 "yacc_sql.y"
                                 {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_COUNT;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2603 "yacc_sql.cpp"
    break;

  case 93:
#line 833 "yacc_sql.y"
                            {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_COUNT;
    (yyval.dyn_node)->node.attribute_name = '*';
    // $$->node = std::move(*$3);
    // delete $3;
  }
#line 2615 "yacc_sql.cpp"
    break;

  case 94:
#line 840 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_AVG;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2626 "yacc_sql.cpp"
    break;

  case 95:
#line 846 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_SUM;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2637 "yacc_sql.cpp"
    break;

  case 96:
#line 855 "yacc_sql.y"
           {
    (yyval.relation) = new RelSqlNode;
    (yyval.relation)->relation = (yyvsp[-1].string);
    free((yyvsp[-1].string));
    if ((yyvsp[0].string) != nullptr) {
      (yyval.relation)->alias    = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
  }
#line 2651 "yacc_sql.cpp"
    break;

  case 97:
#line 868 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = new std::deque<RelAttrSqlNode>;
    }
#line 2659 "yacc_sql.cpp"
    break;

  case 98:
#line 871 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::deque<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_front(std::move(*(yyvsp[-1].rel_attr)));
      delete (yyvsp[-1].rel_attr);
    }
#line 2674 "yacc_sql.cpp"
    break;

  case 99:
#line 885 "yacc_sql.y"
    {
      (yyval.relation_list) = new std::deque<RelSqlNode>;
    }
#line 2682 "yacc_sql.cpp"
    break;

  case 100:
#line 888 "yacc_sql.y"
                              {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::deque<RelSqlNode>;
      }

      (yyval.relation_list)->push_front(std::move(*(yyvsp[-1].relation)));
      delete (yyvsp[-1].relation);
    }
#line 2697 "yacc_sql.cpp"
    break;

  case 101:
#line 901 "yacc_sql.y"
    {
      (yyval.condition_list) = new std::deque<ConditionSqlNode>();
    }
#line 2705 "yacc_sql.cpp"
    break;

  case 102:
#line 904 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2713 "yacc_sql.cpp"
    break;

  case 103:
#line 910 "yacc_sql.y"
                          {
		(yyval.condition_list) = (yyvsp[0].condition_list);
  }
#line 2721 "yacc_sql.cpp"
    break;

  case 104:
#line 915 "yacc_sql.y"
              {
      (yyval.condition_list) = new std::deque<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(std::move(std::move(*(yyvsp[0].condition))));
      delete (yyvsp[0].condition);
    }
#line 2731 "yacc_sql.cpp"
    break;

  case 105:
#line 920 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_front(std::move(std::move(*(yyvsp[-2].condition))));
      delete (yyvsp[-2].condition);
    }
#line 2741 "yacc_sql.cpp"
    break;

  case 106:
#line 928 "yacc_sql.y"
                         {
    (yyval.condition_list) = new std::deque<ConditionSqlNode>();
		(yyval.condition_list)->push_back(std::move(*(yyvsp[-2].condition)));
		(yyval.condition_list)->push_back(std::move(*(yyvsp[0].condition)));
		delete (yyvsp[-2].condition);
		delete (yyvsp[0].condition);
  }
#line 2753 "yacc_sql.cpp"
    break;

  case 107:
#line 935 "yacc_sql.y"
                                   {
    (yyval.condition_list) = (yyvsp[0].condition_list);
		(yyval.condition_list)->push_front(std::move(*(yyvsp[-2].condition)));
		delete (yyvsp[-2].condition);
  }
#line 2763 "yacc_sql.cpp"
    break;

  case 108:
#line 945 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op = (yyvsp[-1].comp);

    }
#line 2777 "yacc_sql.cpp"
    break;

  case 109:
#line 955 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = true;
      (yyval.condition)->left_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-3].select));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op= (yyvsp[-1].comp);

    }
#line 2791 "yacc_sql.cpp"
    break;

  case 110:
#line 965 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-4].expression));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = (yyvsp[-3].comp);

    }
#line 2805 "yacc_sql.cpp"
    break;

  case 111:
#line 974 "yacc_sql.y"
                                                        {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = true;
      (yyval.condition)->left_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-5].select));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = (yyvsp[-3].comp);

    }
#line 2819 "yacc_sql.cpp"
    break;

  case 112:
#line 983 "yacc_sql.y"
                                         {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-4].expression));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::IN_SQ;
    }
#line 2832 "yacc_sql.cpp"
    break;

  case 113:
#line 991 "yacc_sql.y"
                                             {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-5].expression));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::NOT_IN_SQ;
    }
#line 2845 "yacc_sql.cpp"
    break;

  case 114:
#line 999 "yacc_sql.y"
                                             {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-4].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->value_list = std::move(*(yyvsp[-1].value_list));
      (yyval.condition)->right_is_list = true;
      (yyval.condition)->op = CompOp::IN_SQ;
      delete (yyvsp[-1].value_list);
    }
#line 2860 "yacc_sql.cpp"
    break;

  case 115:
#line 1009 "yacc_sql.y"
                                                 {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-5].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->value_list = std::move(*(yyvsp[-1].value_list));
      (yyval.condition)->right_is_list = true;
      (yyval.condition)->op = CompOp::NOT_IN_SQ;
      delete (yyvsp[-1].value_list);
    }
#line 2875 "yacc_sql.cpp"
    break;

  case 116:
#line 1019 "yacc_sql.y"
                                  {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::EXISTS_SQ;
    }
#line 2887 "yacc_sql.cpp"
    break;

  case 117:
#line 1026 "yacc_sql.y"
                                      {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::NOT_EXISTS_SQ;
    }
#line 2899 "yacc_sql.cpp"
    break;

  case 118:
#line 1033 "yacc_sql.y"
                                     {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->op = CompOp::IS_NOT_NULL;
    }
#line 2911 "yacc_sql.cpp"
    break;

  case 119:
#line 1040 "yacc_sql.y"
                                 {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->op = CompOp::IS_NULL;
    }
#line 2923 "yacc_sql.cpp"
    break;

  case 120:
#line 1047 "yacc_sql.y"
                                 {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op = LIKE_SCH;
    }
#line 2936 "yacc_sql.cpp"
    break;

  case 121:
#line 1055 "yacc_sql.y"
                                     {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op = NOT_LIKE_SCH;
    }
#line 2949 "yacc_sql.cpp"
    break;

  case 122:
#line 1066 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 2955 "yacc_sql.cpp"
    break;

  case 123:
#line 1067 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 2961 "yacc_sql.cpp"
    break;

  case 124:
#line 1068 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 2967 "yacc_sql.cpp"
    break;

  case 125:
#line 1069 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 2973 "yacc_sql.cpp"
    break;

  case 126:
#line 1070 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 2979 "yacc_sql.cpp"
    break;

  case 127:
#line 1071 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 2985 "yacc_sql.cpp"
    break;

  case 128:
#line 1075 "yacc_sql.y"
              {
    (yyval.condition_list) = new std::deque<ConditionSqlNode>;
  }
#line 2993 "yacc_sql.cpp"
    break;

  case 129:
#line 1078 "yacc_sql.y"
                      {
    (yyval.condition_list) = (yyvsp[0].condition_list);
  }
#line 3001 "yacc_sql.cpp"
    break;

  case 130:
#line 1084 "yacc_sql.y"
             {
    (yyval.join_list) = new std::deque<JoinSqlNode>();
  }
#line 3009 "yacc_sql.cpp"
    break;

  case 131:
#line 1087 "yacc_sql.y"
                                                  {
		(yyval.join_list) = (yyvsp[0].join_list);
		JoinSqlNode join;
		join.relation = (yyvsp[-2].string);
		join.on_coditions = std::move(*(yyvsp[-1].condition_list));
		(yyval.join_list)->push_front(std::move(join));

    free((yyvsp[-2].string));
    delete (yyvsp[-1].condition_list);
	}
#line 3024 "yacc_sql.cpp"
    break;

  case 132:
#line 1100 "yacc_sql.y"
             {
		(yyval.condition_list) = new std::deque<ConditionSqlNode>;
	}
#line 3032 "yacc_sql.cpp"
    break;

  case 133:
#line 1103 "yacc_sql.y"
                                {
		(yyval.condition_list) = (yyvsp[0].condition_list);
		// $$->push_front(std::move(*$2);
		// delete $2;
	}
#line 3042 "yacc_sql.cpp"
    break;

  case 134:
#line 1111 "yacc_sql.y"
              {
    (yyval.groupby) = nullptr;
  }
#line 3050 "yacc_sql.cpp"
    break;

  case 135:
#line 1114 "yacc_sql.y"
                                       {
    (yyval.groupby) = new GroupBySqlNode();
    (yyvsp[-1].rel_attr_list)->push_front(std::move(*(yyvsp[-2].rel_attr)));
    delete (yyvsp[-2].rel_attr);
    (yyval.groupby)->by_attrs          = std::move(*(yyvsp[-1].rel_attr_list));
    (yyval.groupby)->having_conditions = std::move(*(yyvsp[0].condition_list));
    delete (yyvsp[-1].rel_attr_list);
    delete (yyvsp[0].condition_list);
  }
#line 3064 "yacc_sql.cpp"
    break;

  case 136:
#line 1126 "yacc_sql.y"
                    {
		(yyval.orderby_list) = new std::deque<OrderBySqlNode>();
	}
#line 3072 "yacc_sql.cpp"
    break;

  case 137:
#line 1129 "yacc_sql.y"
                                            {
		(yyval.orderby_list) = (yyvsp[0].orderby_list);
		(yyval.orderby_list)->push_front(std::move(*(yyvsp[-1].orderby)));
    delete (yyvsp[-1].orderby);
	}
#line 3082 "yacc_sql.cpp"
    break;

  case 138:
#line 1137 "yacc_sql.y"
              {
    (yyval.orderby_list) = new std::deque<OrderBySqlNode>();
  }
#line 3090 "yacc_sql.cpp"
    break;

  case 139:
#line 1140 "yacc_sql.y"
                                   {
    (yyval.orderby_list) = (yyvsp[0].orderby_list);
    (yyval.orderby_list)->push_front(std::move(*(yyvsp[-1].orderby)));
    delete (yyvsp[-1].orderby);
  }
#line 3100 "yacc_sql.cpp"
    break;

  case 140:
#line 1148 "yacc_sql.y"
           {
    (yyval.orderby) = new OrderBySqlNode();
    (yyval.orderby)->by_attr = std::unique_ptr<RelAttrSqlNode>((yyvsp[0].rel_attr));
    (yyval.orderby)->is_asc  = true;
  }
#line 3110 "yacc_sql.cpp"
    break;

  case 141:
#line 1153 "yacc_sql.y"
                 {
    (yyval.orderby) = new OrderBySqlNode();
    (yyval.orderby)->by_attr = std::unique_ptr<RelAttrSqlNode>((yyvsp[-1].rel_attr));
    (yyval.orderby)->is_asc  = true;
  }
#line 3120 "yacc_sql.cpp"
    break;

  case 142:
#line 1158 "yacc_sql.y"
                  {
    (yyval.orderby) = new OrderBySqlNode();
    (yyval.orderby)->by_attr = std::unique_ptr<RelAttrSqlNode>((yyvsp[-1].rel_attr));
    (yyval.orderby)->is_asc  = false;
  }
#line 3130 "yacc_sql.cpp"
    break;

  case 143:
#line 1166 "yacc_sql.y"
                           {
    InsertRowNode row;
    row.values = std::move(*(yyvsp[-1].value_list));
    delete (yyvsp[-1].value_list);
    (yyval.insert_row_list) = new std::deque<InsertRowNode>();
    (yyval.insert_row_list)->push_back(std::move(row));
  }
#line 3142 "yacc_sql.cpp"
    break;

  case 144:
#line 1173 "yacc_sql.y"
                                                   {
    InsertRowNode row;
    row.values = std::move(*(yyvsp[-3].value_list));
    delete (yyvsp[-3].value_list);
    (yyval.insert_row_list) = (yyvsp[0].insert_row_list);
    (yyval.insert_row_list)->push_back(std::move(row));
  }
#line 3154 "yacc_sql.cpp"
    break;

  case 145:
#line 1184 "yacc_sql.y"
                {
			(yyval.update_pair_list) = new std::deque<UpdatePairSqlNode>;
      (yyval.update_pair_list)->push_back(std::move(*(yyvsp[0].update_pair)));
      delete (yyvsp[0].update_pair);
		}
#line 3164 "yacc_sql.cpp"
    break;

  case 146:
#line 1190 "yacc_sql.y"
                {
			(yyval.update_pair_list) = (yyvsp[-2].update_pair_list);
      (yyval.update_pair_list)->push_back(std::move(std::move(*(yyvsp[0].update_pair))));
      delete (yyvsp[0].update_pair);
		}
#line 3174 "yacc_sql.cpp"
    break;

  case 147:
#line 1198 "yacc_sql.y"
                              {
		(yyval.update_pair) = new UpdatePairSqlNode();
    (yyval.update_pair)->attr.attribute_name = (yyvsp[-2].string);
		(yyval.update_pair)->is_select = false;
    (yyval.update_pair)->value = std::move(std::move(*(yyvsp[0].value)));
		delete (yyvsp[0].value);
    free((yyvsp[-2].string));
	}
#line 3187 "yacc_sql.cpp"
    break;

  case 148:
#line 1206 "yacc_sql.y"
                                     {
		(yyval.update_pair) = new UpdatePairSqlNode();
    (yyval.update_pair)->attr.attribute_name = (yyvsp[-4].string);
		(yyval.update_pair)->is_select = true;
    (yyval.update_pair)->select_value = std::move(std::move(*(yyvsp[-1].select)));
		delete (yyvsp[-1].select);
    free((yyvsp[-4].string));
  }
#line 3200 "yacc_sql.cpp"
    break;

  case 149:
#line 1218 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3214 "yacc_sql.cpp"
    break;

  case 150:
#line 1231 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3223 "yacc_sql.cpp"
    break;

  case 151:
#line 1239 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = std::move(std::move(*(yyvsp[0].value)));
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3235 "yacc_sql.cpp"
    break;


#line 3239 "yacc_sql.cpp"

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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error"));
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
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp, sql_string, sql_result, scanner);
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
#line 1251 "yacc_sql.y"

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
