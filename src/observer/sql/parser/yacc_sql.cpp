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
    TEXT_T = 282,
    HELP = 283,
    EXIT = 284,
    DOT = 285,
    INTO = 286,
    VALUES = 287,
    FROM = 288,
    WHERE = 289,
    AND = 290,
    OR = 291,
    SET = 292,
    ON = 293,
    LOAD = 294,
    DATA = 295,
    INFILE = 296,
    EXPLAIN = 297,
    EQ = 298,
    LT = 299,
    GT = 300,
    LE = 301,
    GE = 302,
    NE = 303,
    NOT = 304,
    LIKE = 305,
    INNER = 306,
    JOIN = 307,
    UNIQUE = 308,
    MAX = 309,
    MIN = 310,
    SUM = 311,
    COUNT = 312,
    AVG = 313,
    LENGTH = 314,
    ROUND = 315,
    DATE_FORMAT = 316,
    IN = 317,
    EXISTS = 318,
    GROUP = 319,
    HAVING = 320,
    AS = 321,
    ORDER = 322,
    BY = 323,
    ASC = 324,
    IS = 325,
    NULL_LITERAL = 326,
    NULLABLE = 327,
    NUMBER = 328,
    FLOAT = 329,
    DATE = 330,
    ID = 331,
    SSS = 332,
    UMINUS = 333
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "yacc_sql.y"

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

#line 278 "yacc_sql.cpp"

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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   440

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  317

#define YYUNDEFTOK  2
#define YYMAXUTOK   333


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
       2,     2,    80,    78,     2,    79,     2,    81,     2,     2,
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
      75,    76,    77,    82
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   240,   240,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   272,   278,   283,   289,   295,   301,
     307,   314,   320,   329,   337,   340,   346,   352,   360,   375,
     385,   405,   408,   420,   423,   426,   429,   435,   444,   461,
     464,   465,   466,   467,   468,   472,   475,   478,   484,   499,
     502,   506,   512,   518,   529,   533,   537,   542,   547,   554,
     566,   583,   590,   626,   663,   670,   682,   692,   708,   715,
     722,   729,   736,   742,   748,   756,   761,   768,   775,   784,
     816,   826,   834,   839,   846,   855,   860,   866,   872,   878,
     885,   891,   900,   913,   916,   930,   933,   946,   949,   955,
     960,   965,   973,   980,   989,   999,  1009,  1019,  1028,  1036,
    1044,  1054,  1064,  1071,  1078,  1085,  1092,  1100,  1111,  1112,
    1113,  1114,  1115,  1116,  1120,  1123,  1129,  1132,  1145,  1148,
    1156,  1159,  1171,  1174,  1182,  1185,  1193,  1198,  1203,  1211,
    1218,  1228,  1234,  1243,  1251,  1262,  1275,  1283,  1294
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
  "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE",
  "AND", "OR", "SET", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN", "EQ",
  "LT", "GT", "LE", "GE", "NE", "NOT", "LIKE", "INNER", "JOIN", "UNIQUE",
  "MAX", "MIN", "SUM", "COUNT", "AVG", "LENGTH", "ROUND", "DATE_FORMAT",
  "IN", "EXISTS", "GROUP", "HAVING", "AS", "ORDER", "BY", "ASC", "IS",
  "NULL_LITERAL", "NULLABLE", "NUMBER", "FLOAT", "DATE", "ID", "SSS",
  "'+'", "'-'", "'*'", "'/'", "UMINUS", "$accept", "commands",
  "command_wrapper", "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt",
  "commit_stmt", "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "show_index_stmt", "desc_table_stmt", "is_unique", "id_list",
  "create_index_stmt", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "is_nullable", "attr_def", "number", "type", "alias",
  "insert_stmt", "value_list_cell", "value_list", "value", "delete_stmt",
  "update_stmt", "select_stmt", "select", "calc_stmt", "expression_list",
  "expression", "select_attr", "rel_attr", "dyn_node", "relation",
  "attr_list", "rel_list", "where", "or_where", "condition_list",
  "or_condition_list", "condition", "comp_op", "join_conditions",
  "join_list", "having", "groupby", "orderby", "orderby_list",
  "orderby_col", "insert_row_list", "update_list", "update_pair",
  "load_data_stmt", "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
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
     325,   326,   327,   328,   329,   330,   331,   332,    43,    45,
      42,    47,   333
};
# endif

#define YYPACT_NINF (-226)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     358,     9,    59,   227,   161,   -39,    15,  -226,    28,    21,
      -8,  -226,  -226,  -226,  -226,  -226,    57,    82,   358,   136,
     157,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,    86,  -226,   162,   103,   104,   227,   164,
     165,   166,   167,   168,   169,   170,   171,  -226,  -226,  -226,
    -226,   159,  -226,   227,  -226,  -226,   -23,  -226,  -226,  -226,
     160,   163,  -226,  -226,   173,   116,   118,   172,   152,   182,
    -226,  -226,  -226,  -226,   181,   123,  -226,   174,     7,   124,
     124,   124,   -10,   124,   227,   227,   227,    35,  -226,   125,
    -226,   227,   227,   227,   227,   184,   128,   131,   176,   179,
     149,     1,   -27,   150,   153,   188,   154,  -226,   210,   213,
     224,   228,   229,   238,    16,    -1,    -7,  -226,  -226,  -226,
      23,    23,  -226,  -226,   227,   -40,   226,  -226,   242,   194,
    -226,   217,  -226,   149,  -226,  -226,   230,     4,   243,   187,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,   191,
     189,  -226,  -226,   128,   223,    55,  -226,    92,   212,   259,
     359,  -226,   245,    46,  -226,   271,  -226,  -226,  -226,  -226,
    -226,    34,   153,   260,   272,   273,   274,   226,   241,   256,
      71,  -226,   140,  -226,   161,   276,   278,   286,  -226,  -226,
    -226,  -226,  -226,  -226,   -29,   227,   280,   -33,   255,   194,
     286,  -226,   231,   232,   237,  -226,  -226,  -226,   243,  -226,
     244,  -226,  -226,  -226,   246,   194,   253,   253,  -226,  -226,
     299,    55,  -226,    95,   286,   301,   227,   304,    76,    39,
     252,  -226,    92,    76,  -226,   306,  -226,  -226,   307,  -226,
    -226,   308,   315,   297,  -226,   137,   277,   279,   279,   242,
    -226,   282,   326,  -226,    76,    39,   156,   329,  -226,   330,
    -226,   -30,   244,  -226,   194,   223,   194,   124,   281,  -226,
    -226,  -226,    92,    76,  -226,   158,   332,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,   316,   335,   124,   333,  -226,
    -226,   124,   295,    13,   345,  -226,   335,   194,  -226,  -226,
    -226,   124,  -226,  -226,  -226,   345,  -226
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
       0,    23,    22,    15,    16,    17,    18,     9,    10,    12,
      11,    13,    14,     8,     5,     7,     6,     4,    71,     3,
      19,    20,    21,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    64,    65,
      66,    92,    67,     0,    84,    74,    55,    95,    85,    90,
      75,     0,    33,    31,     0,     0,     0,     0,     0,     0,
     156,     1,   158,     2,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
      56,     0,     0,     0,     0,    76,     0,     0,     0,   107,
       0,   107,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    57,
      78,    79,    80,    81,     0,    55,   105,    32,     0,     0,
      69,     0,   151,     0,    70,   157,     0,     0,    41,     0,
      39,    96,    97,   101,    99,    98,   100,    86,    87,     0,
       0,    77,   102,     0,   136,     0,    58,     0,     0,     0,
       0,   108,   110,     0,   152,     0,    50,    51,    52,    53,
      54,    43,     0,     0,     0,     0,     0,   105,     0,   107,
       0,    62,     0,    59,     0,     0,     0,     0,   128,   129,
     130,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,   153,     0,     0,     0,    46,    45,    48,    41,    40,
       0,    88,    89,   106,     0,     0,   140,   140,    60,    61,
     149,     0,    91,     0,     0,     0,     0,     0,   126,     0,
       0,   125,     0,   114,   111,     0,   155,    49,     0,    44,
      42,    36,     0,   134,   109,   110,     0,   142,   142,     0,
      63,     0,     0,   122,   127,     0,     0,     0,   124,     0,
     154,    43,     0,    38,     0,   136,     0,     0,     0,    72,
      73,   150,     0,   115,   123,     0,     0,   120,   118,   116,
      47,    37,   135,   137,   113,   112,   103,     0,     0,   121,
     119,     0,   138,   146,   144,   117,   103,     0,   141,   148,
     147,     0,   143,   104,   139,   144,   145
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -226,  -226,   347,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,    94,  -226,  -226,  -226,   175,   105,
     193,  -226,  -226,   247,  -226,  -141,  -225,  -104,  -226,  -226,
    -226,  -158,  -226,     3,    -3,  -226,   -87,  -226,   214,    75,
     196,  -100,  -226,  -199,   108,  -212,   155,  -226,   110,  -226,
     183,   132,    74,    80,   133,  -226,   251,  -226,  -226,  -226,
    -226
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    45,   252,    31,    32,    33,   183,   217,
     148,   248,   181,   105,    34,   191,   192,    64,    35,    36,
      37,    38,    39,    65,   170,    71,    67,    68,   136,   302,
     164,   140,   227,   171,   254,   172,   208,   275,   189,   308,
     257,   279,   312,   304,   166,   111,   142,    40,    41,    42,
      83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    66,   118,   119,   120,   122,   123,    70,   145,   195,
     244,   144,   160,   255,   266,    43,   240,   158,   159,   214,
     143,   236,    73,    74,   309,   117,    99,   176,   177,   178,
     179,   180,   211,   237,   157,   139,   100,    72,   241,   235,
     285,   215,   216,    99,    57,    88,    58,    59,    60,   194,
      62,   213,   245,   100,    76,   101,   102,   103,   104,    75,
      98,   193,    44,   210,   295,    46,    61,    47,    77,   193,
     121,   101,   102,   103,   104,   292,   262,   101,   102,   103,
     104,   267,   310,   214,   269,   101,   102,   103,   104,   226,
     260,   124,   125,   126,   101,   102,   103,   104,   130,   131,
     132,   133,   194,   103,   104,   215,   216,   286,   314,    48,
      57,   127,    58,    59,    60,   128,    62,    57,   190,    58,
      59,    60,    79,    62,   298,   190,    57,   193,    58,    59,
      60,    66,    62,    78,   190,   193,    81,   161,   198,   199,
     200,   201,   202,   203,   228,   229,    49,    50,    51,    52,
      53,    54,    55,    56,   101,   102,   103,   104,   230,   231,
      82,   193,    84,    57,    88,    58,    59,    60,    61,    62,
      85,    63,   209,   276,   287,   231,   299,   231,    48,    86,
      87,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     296,    66,   108,   -91,   109,   112,   106,   232,   114,   115,
      61,   129,   238,   134,   135,   243,   107,   137,   138,   110,
     303,   167,   116,   139,   306,    49,    50,    51,    52,    53,
      54,    55,    56,   113,   303,   141,   149,   146,   151,   147,
     150,   152,    57,   264,    58,    59,    60,    61,    62,    88,
      63,    69,   153,   168,    48,   163,   154,   155,    49,    50,
      51,    52,    53,    54,    55,    56,   156,   169,   283,   165,
     173,   175,   182,   184,   185,    57,   186,    58,    59,    60,
      61,    62,   242,    63,   188,   196,   197,   212,   219,    88,
     209,    49,    50,    51,    52,    53,    54,    55,    56,   220,
     225,   221,   222,   224,   233,   234,   194,   239,    57,   282,
      58,    59,    60,    61,    62,   247,    63,   246,   249,    49,
      50,    51,    52,    53,    54,    55,    56,   256,   259,   263,
     251,   265,   253,   268,   270,   271,    57,   272,    58,    59,
      60,    61,    62,   273,    63,   274,    49,    50,    51,    52,
      53,    54,    55,    56,   284,   277,   278,   288,   289,   297,
     300,   305,   276,    57,   301,    58,    59,    60,    61,    62,
     307,    63,     1,     2,   311,    80,   291,     3,     4,     5,
       6,     7,     8,     9,    10,   218,   290,   187,    11,    12,
      13,   313,   162,   223,   294,   293,    14,    15,   261,   316,
     280,   315,   281,   250,   174,    16,     0,    17,     0,     0,
      18,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,     0,     0,     0,   207,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104
};

static const yytype_int16 yycheck[] =
{
       3,     4,    89,    90,    91,    92,    93,     4,   112,   167,
     209,   111,    19,   225,   239,     6,    49,    18,    19,    49,
      19,    50,     7,     8,    11,    18,    66,    23,    24,    25,
      26,    27,   173,    62,    18,    34,    76,    76,    71,   197,
     265,    71,    72,    66,    71,    48,    73,    74,    75,    10,
      77,    17,   210,    76,    33,    78,    79,    80,    81,    31,
      63,   165,    53,    17,   276,     6,    76,     8,    76,   173,
      80,    78,    79,    80,    81,   274,   234,    78,    79,    80,
      81,   239,    69,    49,   242,    78,    79,    80,    81,   189,
     231,    94,    95,    96,    78,    79,    80,    81,   101,   102,
     103,   104,    10,    80,    81,    71,    72,   265,   307,    17,
      71,    76,    73,    74,    75,    80,    77,    71,    79,    73,
      74,    75,    40,    77,   282,    79,    71,   231,    73,    74,
      75,   134,    77,    76,    79,   239,     0,   134,    43,    44,
      45,    46,    47,    48,    73,    74,    54,    55,    56,    57,
      58,    59,    60,    61,    78,    79,    80,    81,    18,    19,
       3,   265,    76,    71,   167,    73,    74,    75,    76,    77,
       8,    79,    35,    36,    18,    19,    18,    19,    17,    76,
      76,    17,    17,    17,    17,    17,    17,    17,    17,    30,
     277,   194,    76,    33,    76,    43,    33,   194,    17,    76,
      76,    76,   205,    19,    76,   208,    33,    76,    32,    37,
     297,    17,    38,    34,   301,    54,    55,    56,    57,    58,
      59,    60,    61,    41,   311,    76,    38,    77,    18,    76,
      76,    18,    71,   236,    73,    74,    75,    76,    77,   242,
      79,    80,    18,    49,    17,    19,    18,    18,    54,    55,
      56,    57,    58,    59,    60,    61,    18,    63,   261,    17,
      43,    31,    19,    76,    73,    71,    77,    73,    74,    75,
      76,    77,    17,    79,    51,    63,    17,     6,    18,   282,
      35,    54,    55,    56,    57,    58,    59,    60,    61,    17,
      34,    18,    18,    52,    18,    17,    10,    17,    71,    17,
      73,    74,    75,    76,    77,    73,    79,    76,    71,    54,
      55,    56,    57,    58,    59,    60,    61,    64,    19,    18,
      76,    17,    76,    71,    18,    18,    71,    19,    73,    74,
      75,    76,    77,    18,    79,    38,    54,    55,    56,    57,
      58,    59,    60,    61,    18,    68,    67,    18,    18,    68,
      18,    18,    36,    71,    19,    73,    74,    75,    76,    77,
      65,    79,     4,     5,    19,    18,   272,     9,    10,    11,
      12,    13,    14,    15,    16,   182,   271,   163,    20,    21,
      22,   306,   135,   187,   276,   275,    28,    29,   233,   315,
     258,   311,   259,   218,   143,    37,    -1,    39,    -1,    -1,
      42,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     9,    10,    11,    12,    13,    14,    15,
      16,    20,    21,    22,    28,    29,    37,    39,    42,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    98,    99,   100,   107,   111,   112,   113,   114,   115,
     140,   141,   142,     6,    53,    96,     6,     8,    17,    54,
      55,    56,    57,    58,    59,    60,    61,    71,    73,    74,
      75,    76,    77,    79,   110,   116,   117,   119,   120,    80,
     116,   118,    76,     7,     8,    31,    33,    76,    76,    40,
      85,     0,     3,   143,    76,     8,    76,    76,   117,    17,
      17,    17,    17,    17,    17,    17,    17,    30,   117,    66,
      76,    78,    79,    80,    81,   106,    33,    33,    76,    76,
      37,   138,    43,    41,    17,    76,    38,    18,   119,   119,
     119,    80,   119,   119,   117,   117,   117,    76,    80,    76,
     117,   117,   117,   117,    19,    76,   121,    76,    32,    34,
     124,    76,   139,    19,   124,   110,    77,    76,   103,    38,
      76,    18,    18,    18,    18,    18,    18,    18,    18,    19,
      19,   116,   106,    19,   123,    17,   137,    17,    49,    63,
     117,   126,   128,    43,   139,    31,    23,    24,    25,    26,
      27,   105,    19,   101,    76,    73,    77,   121,    51,   131,
      79,   108,   109,   110,    10,   114,    63,    17,    43,    44,
      45,    46,    47,    48,    49,    50,    62,    70,   129,    35,
      17,   108,     6,    17,    49,    71,    72,   102,   103,    18,
      17,    18,    18,   123,    52,    34,   124,   125,    73,    74,
      18,    19,   116,    18,    17,   114,    50,    62,   117,    17,
      49,    71,    17,   117,   126,   114,    76,    73,   104,    71,
     101,    76,    97,    76,   127,   128,    64,   133,   133,    19,
     108,   129,   114,    18,   117,    17,   109,   114,    71,   114,
      18,    18,    19,    18,    38,   130,    36,    68,    67,   134,
     134,   137,    17,   117,    18,   109,   114,    18,    18,    18,
     102,    97,   126,   131,   127,   128,   119,    68,   114,    18,
      18,    19,   122,   119,   136,    18,   119,    65,   132,    11,
      69,    19,   135,   122,   126,   136,   135
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    96,    97,    97,    98,    99,
     100,   101,   101,   102,   102,   102,   102,   103,   103,   104,
     105,   105,   105,   105,   105,   106,   106,   106,   107,   108,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   111,
     112,   113,   114,   114,   115,   115,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     118,   118,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   121,   122,   122,   123,   123,   124,   124,   125,
     126,   126,   127,   127,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   129,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   141,   142,   143
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     4,     2,     0,     1,     1,     3,     9,     5,
       7,     0,     3,     0,     2,     1,     1,     6,     3,     1,
       1,     1,     1,     1,     1,     0,     1,     2,     5,     1,
       2,     2,     1,     3,     1,     1,     1,     1,     1,     4,
       4,     1,     9,     9,     2,     2,     2,     4,     3,     3,
       3,     3,     3,     2,     1,     1,     4,     4,     6,     6,
       1,     1,     1,     3,     3,     1,     4,     4,     4,     4,
       4,     4,     2,     0,     3,     0,     3,     0,     2,     2,
       1,     3,     3,     3,     3,     5,     5,     7,     5,     6,
       5,     6,     4,     5,     4,     3,     3,     4,     1,     1,
       1,     1,     1,     1,     0,     2,     0,     5,     0,     2,
       0,     5,     0,     4,     0,     3,     1,     2,     2,     3,
       5,     2,     3,     3,     5,     7,     2,     4,     1
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
#line 241 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1842 "yacc_sql.cpp"
    break;

  case 24:
#line 272 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1851 "yacc_sql.cpp"
    break;

  case 25:
#line 278 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1859 "yacc_sql.cpp"
    break;

  case 26:
#line 283 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1867 "yacc_sql.cpp"
    break;

  case 27:
#line 289 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1875 "yacc_sql.cpp"
    break;

  case 28:
#line 295 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1883 "yacc_sql.cpp"
    break;

  case 29:
#line 301 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1891 "yacc_sql.cpp"
    break;

  case 30:
#line 307 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1901 "yacc_sql.cpp"
    break;

  case 31:
#line 314 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1909 "yacc_sql.cpp"
    break;

  case 32:
#line 321 "yacc_sql.y"
                {
			(yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
			(yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
		}
#line 1919 "yacc_sql.cpp"
    break;

  case 33:
#line 329 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1929 "yacc_sql.cpp"
    break;

  case 34:
#line 337 "yacc_sql.y"
              {
    (yyval.bools) = false;
  }
#line 1937 "yacc_sql.cpp"
    break;

  case 35:
#line 340 "yacc_sql.y"
           {
    (yyval.bools) = true;
  }
#line 1945 "yacc_sql.cpp"
    break;

  case 36:
#line 346 "yacc_sql.y"
     {
    (yyval.id_list) = new std::deque<std::string>();
    std::string attribute_name = (yyvsp[0].string);
    free((yyvsp[0].string));
    (yyval.id_list)->emplace_back(attribute_name);
  }
#line 1956 "yacc_sql.cpp"
    break;

  case 37:
#line 352 "yacc_sql.y"
                     {
    (yyval.id_list) = (yyvsp[0].id_list);
    std::string attribute_name = (yyvsp[-2].string);
    free((yyvsp[-2].string));
    (yyval.id_list)->emplace_front(attribute_name);
  }
#line 1967 "yacc_sql.cpp"
    break;

  case 38:
#line 361 "yacc_sql.y"
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
#line 1983 "yacc_sql.cpp"
    break;

  case 39:
#line 376 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1995 "yacc_sql.cpp"
    break;

  case 40:
#line 386 "yacc_sql.y"
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
#line 2016 "yacc_sql.cpp"
    break;

  case 41:
#line 405 "yacc_sql.y"
    {
      (yyval.attr_infos) = new std::deque<AttrInfoSqlNode>;
    }
#line 2024 "yacc_sql.cpp"
    break;

  case 42:
#line 409 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::deque<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_front(std::move(*(yyvsp[-1].attr_info)));
      delete (yyvsp[-1].attr_info);
    }
#line 2038 "yacc_sql.cpp"
    break;

  case 43:
#line 420 "yacc_sql.y"
              {
    (yyval.number) = -1;
  }
#line 2046 "yacc_sql.cpp"
    break;

  case 44:
#line 423 "yacc_sql.y"
                     {
    (yyval.number) = 0;
  }
#line 2054 "yacc_sql.cpp"
    break;

  case 45:
#line 426 "yacc_sql.y"
             {
    (yyval.number) = 1;
  }
#line 2062 "yacc_sql.cpp"
    break;

  case 46:
#line 429 "yacc_sql.y"
                 {
    (yyval.number) = 1;
  }
#line 2070 "yacc_sql.cpp"
    break;

  case 47:
#line 436 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->unsolved = (yyvsp[0].number);
      free((yyvsp[-5].string));
    }
#line 2083 "yacc_sql.cpp"
    break;

  case 48:
#line 445 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      if ((AttrType)(yyvsp[-1].number) == AttrType::DATES) {
        (yyval.attr_info)->length = 12;
      } else if ((AttrType)(yyvsp[-1].number) == AttrType::TEXTS) {
        (yyval.attr_info)->length = 50;
      } else {
        (yyval.attr_info)->length = 4;
      }
      (yyval.attr_info)->unsolved = (yyvsp[0].number);
      free((yyvsp[-2].string));
    }
#line 2102 "yacc_sql.cpp"
    break;

  case 49:
#line 461 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2108 "yacc_sql.cpp"
    break;

  case 50:
#line 464 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2114 "yacc_sql.cpp"
    break;

  case 51:
#line 465 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2120 "yacc_sql.cpp"
    break;

  case 52:
#line 466 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2126 "yacc_sql.cpp"
    break;

  case 53:
#line 467 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2132 "yacc_sql.cpp"
    break;

  case 54:
#line 468 "yacc_sql.y"
               { (yyval.number)=TEXTS; }
#line 2138 "yacc_sql.cpp"
    break;

  case 55:
#line 472 "yacc_sql.y"
              {
    (yyval.string) = nullptr;
  }
#line 2146 "yacc_sql.cpp"
    break;

  case 56:
#line 475 "yacc_sql.y"
       {
    (yyval.string) = (yyvsp[0].string);
  }
#line 2154 "yacc_sql.cpp"
    break;

  case 57:
#line 478 "yacc_sql.y"
          {
    (yyval.string) = (yyvsp[0].string);
  }
#line 2162 "yacc_sql.cpp"
    break;

  case 58:
#line 485 "yacc_sql.y"
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
#line 2178 "yacc_sql.cpp"
    break;

  case 59:
#line 499 "yacc_sql.y"
        {
    (yyval.value) = (yyvsp[0].value);
  }
#line 2186 "yacc_sql.cpp"
    break;

  case 60:
#line 502 "yacc_sql.y"
               {
    (yyval.value) = new Value(-(int)(yyvsp[0].number));
    // @$ = @1;
  }
#line 2195 "yacc_sql.cpp"
    break;

  case 61:
#line 506 "yacc_sql.y"
              {
    (yyval.value) = new Value(-(float)(yyvsp[0].floats));
    // @$ = @1;
  }
#line 2204 "yacc_sql.cpp"
    break;

  case 62:
#line 513 "yacc_sql.y"
    {
      (yyval.value_list) = new std::deque<Value>;
      (yyval.value_list)->emplace_back(std::move(*(yyvsp[0].value)));
      delete (yyvsp[0].value);
    }
#line 2214 "yacc_sql.cpp"
    break;

  case 63:
#line 518 "yacc_sql.y"
                                        { 
      if ((yyvsp[-2].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[-2].value_list);
      } else {
        (yyval.value_list) = new std::deque<Value>;
      }
      (yyval.value_list)->emplace_back(std::move(*(yyvsp[0].value)));
      delete (yyvsp[0].value);
    }
#line 2228 "yacc_sql.cpp"
    break;

  case 64:
#line 529 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2237 "yacc_sql.cpp"
    break;

  case 65:
#line 533 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2246 "yacc_sql.cpp"
    break;

  case 66:
#line 537 "yacc_sql.y"
          {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp, true, true);
      free(tmp);
    }
#line 2256 "yacc_sql.cpp"
    break;

  case 67:
#line 542 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2266 "yacc_sql.cpp"
    break;

  case 68:
#line 547 "yacc_sql.y"
                  {
      (yyval.value) = new Value(0);
      (yyval.value)->set_null(true);
    }
#line 2275 "yacc_sql.cpp"
    break;

  case 69:
#line 555 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2289 "yacc_sql.cpp"
    break;

  case 70:
#line 567 "yacc_sql.y"
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
#line 2307 "yacc_sql.cpp"
    break;

  case 71:
#line 583 "yacc_sql.y"
           {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      (yyval.sql_node)->selection = std::move(*(yyvsp[0].select));
      delete (yyvsp[0].select);
    }
#line 2317 "yacc_sql.cpp"
    break;

  case 72:
#line 591 "yacc_sql.y"
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
#line 2357 "yacc_sql.cpp"
    break;

  case 73:
#line 626 "yacc_sql.y"
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
#line 2397 "yacc_sql.cpp"
    break;

  case 74:
#line 664 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      // std::reverse($2->begin(), $2->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2408 "yacc_sql.cpp"
    break;

  case 75:
#line 671 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      // std::reverse($2->begin(), $2->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      (yyval.sql_node)->calc.is_select = true;
      delete (yyvsp[0].expression_list);
    }
#line 2420 "yacc_sql.cpp"
    break;

  case 76:
#line 683 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::deque<ExprSqlNode>;
      if ((yyvsp[0].string) != nullptr) {
        (yyvsp[-1].expression)->alias = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
      (yyval.expression_list)->emplace_back(std::move(*(yyvsp[-1].expression)));
      delete (yyvsp[-1].expression);
    }
#line 2434 "yacc_sql.cpp"
    break;

  case 77:
#line 693 "yacc_sql.y"
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
#line 2452 "yacc_sql.cpp"
    break;

  case 78:
#line 708 "yacc_sql.y"
                              {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_ADD;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2464 "yacc_sql.cpp"
    break;

  case 79:
#line 715 "yacc_sql.y"
                                {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_SUB;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2476 "yacc_sql.cpp"
    break;

  case 80:
#line 722 "yacc_sql.y"
                                {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_MUL;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2488 "yacc_sql.cpp"
    break;

  case 81:
#line 729 "yacc_sql.y"
                                {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_DIV;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2500 "yacc_sql.cpp"
    break;

  case 82:
#line 736 "yacc_sql.y"
                               {
      // $$ = $2;
      // $$->set_name(token_name(sql_string, &@$));
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->has_brace = true;
    }
#line 2511 "yacc_sql.cpp"
    break;

  case 83:
#line 742 "yacc_sql.y"
                                  {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, $2, nullptr, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_NEGATIVE;
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2522 "yacc_sql.cpp"
    break;

  case 84:
#line 748 "yacc_sql.y"
            {
      // $$ = new ValueExpr(std::move(*$1);
      // $$->set_name(token_name(sql_string, &@$));
      // delete $1;
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_VAL;
      (yyval.expression)->value = std::unique_ptr<Value>((yyvsp[0].value));
    }
#line 2535 "yacc_sql.cpp"
    break;

  case 85:
#line 756 "yacc_sql.y"
               {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_DYN;
      (yyval.expression)->attr = std::unique_ptr<DynNodeSqlNode>((yyvsp[0].dyn_node));
    }
#line 2545 "yacc_sql.cpp"
    break;

  case 86:
#line 761 "yacc_sql.y"
                                      {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-1].expression));
      FunctionSqlNode func;
      func.funcType = F_LENGTH;
      (yyval.expression)->func = std::make_unique<FunctionSqlNode>(func);
    }
#line 2557 "yacc_sql.cpp"
    break;

  case 87:
#line 768 "yacc_sql.y"
                                     {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-1].expression));
      FunctionSqlNode func;
      func.funcType = F_ROUND;
      (yyval.expression)->func = std::make_unique<FunctionSqlNode>(func);
    }
#line 2569 "yacc_sql.cpp"
    break;

  case 88:
#line 775 "yacc_sql.y"
                                                  {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      FunctionSqlNode func;
      func.funcType = F_ROUND;
      func.round_has = true;
      func.round_number = (yyvsp[-1].number);
      (yyval.expression)->func = std::make_unique<FunctionSqlNode>(func);
    }
#line 2583 "yacc_sql.cpp"
    break;

  case 89:
#line 784 "yacc_sql.y"
                                                     {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      FunctionSqlNode func;
      func.funcType = F_FORMAT;
      char *tmp = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
      func.format = tmp;
      free(tmp);
      (yyval.expression)->func = std::make_unique<FunctionSqlNode>(func);
    }
#line 2598 "yacc_sql.cpp"
    break;

  case 90:
#line 816 "yacc_sql.y"
      {
    (yyval.expression_list) = new std::deque<ExprSqlNode>();
    ExprSqlNode expr;
    expr.type = ExprNodeType::E_DYN;
    expr.attr = std::unique_ptr<DynNodeSqlNode>(new DynNodeSqlNode);

    expr.attr->node.attribute_name = "*";
    
    (yyval.expression_list)->push_back(std::move(expr));
  }
#line 2613 "yacc_sql.cpp"
    break;

  case 91:
#line 826 "yacc_sql.y"
                    {
    (yyval.expression_list) = (yyvsp[0].expression_list);
    // $2->push_front(std::move(*$1);
    // delete $1;
  }
#line 2623 "yacc_sql.cpp"
    break;

  case 92:
#line 834 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2633 "yacc_sql.cpp"
    break;

  case 93:
#line 839 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2645 "yacc_sql.cpp"
    break;

  case 94:
#line 846 "yacc_sql.y"
                 {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = "*";
      free((yyvsp[-2].string));
    }
#line 2656 "yacc_sql.cpp"
    break;

  case 95:
#line 855 "yacc_sql.y"
           {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->node = std::move(*(yyvsp[0].rel_attr));
    delete (yyvsp[0].rel_attr);
  }
#line 2666 "yacc_sql.cpp"
    break;

  case 96:
#line 860 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_MAX;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2677 "yacc_sql.cpp"
    break;

  case 97:
#line 866 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_MIN;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2688 "yacc_sql.cpp"
    break;

  case 98:
#line 872 "yacc_sql.y"
                                 {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_COUNT;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2699 "yacc_sql.cpp"
    break;

  case 99:
#line 878 "yacc_sql.y"
                            {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_COUNT;
    (yyval.dyn_node)->node.attribute_name = '*';
    // $$->node = std::move(*$3);
    // delete $3;
  }
#line 2711 "yacc_sql.cpp"
    break;

  case 100:
#line 885 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_AVG;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2722 "yacc_sql.cpp"
    break;

  case 101:
#line 891 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_SUM;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2733 "yacc_sql.cpp"
    break;

  case 102:
#line 900 "yacc_sql.y"
           {
    (yyval.relation) = new RelSqlNode;
    (yyval.relation)->relation = (yyvsp[-1].string);
    free((yyvsp[-1].string));
    if ((yyvsp[0].string) != nullptr) {
      (yyval.relation)->alias    = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
  }
#line 2747 "yacc_sql.cpp"
    break;

  case 103:
#line 913 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = new std::deque<RelAttrSqlNode>;
    }
#line 2755 "yacc_sql.cpp"
    break;

  case 104:
#line 916 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::deque<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_front(std::move(*(yyvsp[-1].rel_attr)));
      delete (yyvsp[-1].rel_attr);
    }
#line 2770 "yacc_sql.cpp"
    break;

  case 105:
#line 930 "yacc_sql.y"
    {
      (yyval.relation_list) = new std::deque<RelSqlNode>;
    }
#line 2778 "yacc_sql.cpp"
    break;

  case 106:
#line 933 "yacc_sql.y"
                              {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::deque<RelSqlNode>;
      }

      (yyval.relation_list)->push_front(std::move(*(yyvsp[-1].relation)));
      delete (yyvsp[-1].relation);
    }
#line 2793 "yacc_sql.cpp"
    break;

  case 107:
#line 946 "yacc_sql.y"
    {
      (yyval.condition_list) = new std::deque<ConditionSqlNode>();
    }
#line 2801 "yacc_sql.cpp"
    break;

  case 108:
#line 949 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2809 "yacc_sql.cpp"
    break;

  case 109:
#line 955 "yacc_sql.y"
                          {
		(yyval.condition_list) = (yyvsp[0].condition_list);
  }
#line 2817 "yacc_sql.cpp"
    break;

  case 110:
#line 960 "yacc_sql.y"
              {
      (yyval.condition_list) = new std::deque<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(std::move(std::move(*(yyvsp[0].condition))));
      delete (yyvsp[0].condition);
    }
#line 2827 "yacc_sql.cpp"
    break;

  case 111:
#line 965 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_front(std::move(std::move(*(yyvsp[-2].condition))));
      delete (yyvsp[-2].condition);
    }
#line 2837 "yacc_sql.cpp"
    break;

  case 112:
#line 973 "yacc_sql.y"
                         {
    (yyval.condition_list) = new std::deque<ConditionSqlNode>();
		(yyval.condition_list)->push_back(std::move(*(yyvsp[-2].condition)));
		(yyval.condition_list)->push_back(std::move(*(yyvsp[0].condition)));
		delete (yyvsp[-2].condition);
		delete (yyvsp[0].condition);
  }
#line 2849 "yacc_sql.cpp"
    break;

  case 113:
#line 980 "yacc_sql.y"
                                   {
    (yyval.condition_list) = (yyvsp[0].condition_list);
		(yyval.condition_list)->push_front(std::move(*(yyvsp[-2].condition)));
		delete (yyvsp[-2].condition);
  }
#line 2859 "yacc_sql.cpp"
    break;

  case 114:
#line 990 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op = (yyvsp[-1].comp);

    }
#line 2873 "yacc_sql.cpp"
    break;

  case 115:
#line 1000 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = true;
      (yyval.condition)->left_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-3].select));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op= (yyvsp[-1].comp);

    }
#line 2887 "yacc_sql.cpp"
    break;

  case 116:
#line 1010 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-4].expression));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = (yyvsp[-3].comp);

    }
#line 2901 "yacc_sql.cpp"
    break;

  case 117:
#line 1019 "yacc_sql.y"
                                                        {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = true;
      (yyval.condition)->left_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-5].select));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = (yyvsp[-3].comp);

    }
#line 2915 "yacc_sql.cpp"
    break;

  case 118:
#line 1028 "yacc_sql.y"
                                         {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-4].expression));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::IN_SQ;
    }
#line 2928 "yacc_sql.cpp"
    break;

  case 119:
#line 1036 "yacc_sql.y"
                                             {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-5].expression));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::NOT_IN_SQ;
    }
#line 2941 "yacc_sql.cpp"
    break;

  case 120:
#line 1044 "yacc_sql.y"
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
#line 2956 "yacc_sql.cpp"
    break;

  case 121:
#line 1054 "yacc_sql.y"
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
#line 2971 "yacc_sql.cpp"
    break;

  case 122:
#line 1064 "yacc_sql.y"
                                  {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::EXISTS_SQ;
    }
#line 2983 "yacc_sql.cpp"
    break;

  case 123:
#line 1071 "yacc_sql.y"
                                      {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::NOT_EXISTS_SQ;
    }
#line 2995 "yacc_sql.cpp"
    break;

  case 124:
#line 1078 "yacc_sql.y"
                                     {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->op = CompOp::IS_NOT_NULL;
    }
#line 3007 "yacc_sql.cpp"
    break;

  case 125:
#line 1085 "yacc_sql.y"
                                 {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->op = CompOp::IS_NULL;
    }
#line 3019 "yacc_sql.cpp"
    break;

  case 126:
#line 1092 "yacc_sql.y"
                                 {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op = LIKE_SCH;
    }
#line 3032 "yacc_sql.cpp"
    break;

  case 127:
#line 1100 "yacc_sql.y"
                                     {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op = NOT_LIKE_SCH;
    }
#line 3045 "yacc_sql.cpp"
    break;

  case 128:
#line 1111 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3051 "yacc_sql.cpp"
    break;

  case 129:
#line 1112 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3057 "yacc_sql.cpp"
    break;

  case 130:
#line 1113 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3063 "yacc_sql.cpp"
    break;

  case 131:
#line 1114 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3069 "yacc_sql.cpp"
    break;

  case 132:
#line 1115 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3075 "yacc_sql.cpp"
    break;

  case 133:
#line 1116 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3081 "yacc_sql.cpp"
    break;

  case 134:
#line 1120 "yacc_sql.y"
              {
    (yyval.condition_list) = new std::deque<ConditionSqlNode>;
  }
#line 3089 "yacc_sql.cpp"
    break;

  case 135:
#line 1123 "yacc_sql.y"
                      {
    (yyval.condition_list) = (yyvsp[0].condition_list);
  }
#line 3097 "yacc_sql.cpp"
    break;

  case 136:
#line 1129 "yacc_sql.y"
             {
    (yyval.join_list) = new std::deque<JoinSqlNode>();
  }
#line 3105 "yacc_sql.cpp"
    break;

  case 137:
#line 1132 "yacc_sql.y"
                                                  {
		(yyval.join_list) = (yyvsp[0].join_list);
		JoinSqlNode join;
		join.relation = (yyvsp[-2].string);
		join.on_coditions = std::move(*(yyvsp[-1].condition_list));
		(yyval.join_list)->push_front(std::move(join));

    free((yyvsp[-2].string));
    delete (yyvsp[-1].condition_list);
	}
#line 3120 "yacc_sql.cpp"
    break;

  case 138:
#line 1145 "yacc_sql.y"
             {
		(yyval.condition_list) = new std::deque<ConditionSqlNode>;
	}
#line 3128 "yacc_sql.cpp"
    break;

  case 139:
#line 1148 "yacc_sql.y"
                                {
		(yyval.condition_list) = (yyvsp[0].condition_list);
		// $$->push_front(std::move(*$2);
		// delete $2;
	}
#line 3138 "yacc_sql.cpp"
    break;

  case 140:
#line 1156 "yacc_sql.y"
              {
    (yyval.groupby) = nullptr;
  }
#line 3146 "yacc_sql.cpp"
    break;

  case 141:
#line 1159 "yacc_sql.y"
                                       {
    (yyval.groupby) = new GroupBySqlNode();
    (yyvsp[-1].rel_attr_list)->push_front(std::move(*(yyvsp[-2].rel_attr)));
    delete (yyvsp[-2].rel_attr);
    (yyval.groupby)->by_attrs          = std::move(*(yyvsp[-1].rel_attr_list));
    (yyval.groupby)->having_conditions = std::move(*(yyvsp[0].condition_list));
    delete (yyvsp[-1].rel_attr_list);
    delete (yyvsp[0].condition_list);
  }
#line 3160 "yacc_sql.cpp"
    break;

  case 142:
#line 1171 "yacc_sql.y"
                    {
		(yyval.orderby_list) = new std::deque<OrderBySqlNode>();
	}
#line 3168 "yacc_sql.cpp"
    break;

  case 143:
#line 1174 "yacc_sql.y"
                                            {
		(yyval.orderby_list) = (yyvsp[0].orderby_list);
		(yyval.orderby_list)->push_front(std::move(*(yyvsp[-1].orderby)));
    delete (yyvsp[-1].orderby);
	}
#line 3178 "yacc_sql.cpp"
    break;

  case 144:
#line 1182 "yacc_sql.y"
              {
    (yyval.orderby_list) = new std::deque<OrderBySqlNode>();
  }
#line 3186 "yacc_sql.cpp"
    break;

  case 145:
#line 1185 "yacc_sql.y"
                                   {
    (yyval.orderby_list) = (yyvsp[0].orderby_list);
    (yyval.orderby_list)->push_front(std::move(*(yyvsp[-1].orderby)));
    delete (yyvsp[-1].orderby);
  }
#line 3196 "yacc_sql.cpp"
    break;

  case 146:
#line 1193 "yacc_sql.y"
           {
    (yyval.orderby) = new OrderBySqlNode();
    (yyval.orderby)->by_attr = std::unique_ptr<RelAttrSqlNode>((yyvsp[0].rel_attr));
    (yyval.orderby)->is_asc  = true;
  }
#line 3206 "yacc_sql.cpp"
    break;

  case 147:
#line 1198 "yacc_sql.y"
                 {
    (yyval.orderby) = new OrderBySqlNode();
    (yyval.orderby)->by_attr = std::unique_ptr<RelAttrSqlNode>((yyvsp[-1].rel_attr));
    (yyval.orderby)->is_asc  = true;
  }
#line 3216 "yacc_sql.cpp"
    break;

  case 148:
#line 1203 "yacc_sql.y"
                  {
    (yyval.orderby) = new OrderBySqlNode();
    (yyval.orderby)->by_attr = std::unique_ptr<RelAttrSqlNode>((yyvsp[-1].rel_attr));
    (yyval.orderby)->is_asc  = false;
  }
#line 3226 "yacc_sql.cpp"
    break;

  case 149:
#line 1211 "yacc_sql.y"
                           {
    InsertRowNode row;
    row.values = std::move(*(yyvsp[-1].value_list));
    delete (yyvsp[-1].value_list);
    (yyval.insert_row_list) = new std::deque<InsertRowNode>();
    (yyval.insert_row_list)->push_back(std::move(row));
  }
#line 3238 "yacc_sql.cpp"
    break;

  case 150:
#line 1218 "yacc_sql.y"
                                                   {
    InsertRowNode row;
    row.values = std::move(*(yyvsp[-3].value_list));
    delete (yyvsp[-3].value_list);
    (yyval.insert_row_list) = (yyvsp[0].insert_row_list);
    (yyval.insert_row_list)->push_back(std::move(row));
  }
#line 3250 "yacc_sql.cpp"
    break;

  case 151:
#line 1229 "yacc_sql.y"
                {
			(yyval.update_pair_list) = new std::deque<UpdatePairSqlNode>;
      (yyval.update_pair_list)->push_back(std::move(*(yyvsp[0].update_pair)));
      delete (yyvsp[0].update_pair);
		}
#line 3260 "yacc_sql.cpp"
    break;

  case 152:
#line 1235 "yacc_sql.y"
                {
			(yyval.update_pair_list) = (yyvsp[-2].update_pair_list);
      (yyval.update_pair_list)->push_back(std::move(std::move(*(yyvsp[0].update_pair))));
      delete (yyvsp[0].update_pair);
		}
#line 3270 "yacc_sql.cpp"
    break;

  case 153:
#line 1243 "yacc_sql.y"
                              {
		(yyval.update_pair) = new UpdatePairSqlNode();
    (yyval.update_pair)->attr.attribute_name = (yyvsp[-2].string);
		(yyval.update_pair)->is_select = false;
    (yyval.update_pair)->value = std::move(std::move(*(yyvsp[0].value)));
		delete (yyvsp[0].value);
    free((yyvsp[-2].string));
	}
#line 3283 "yacc_sql.cpp"
    break;

  case 154:
#line 1251 "yacc_sql.y"
                                     {
		(yyval.update_pair) = new UpdatePairSqlNode();
    (yyval.update_pair)->attr.attribute_name = (yyvsp[-4].string);
		(yyval.update_pair)->is_select = true;
    (yyval.update_pair)->select_value = std::move(std::move(*(yyvsp[-1].select)));
		delete (yyvsp[-1].select);
    free((yyvsp[-4].string));
  }
#line 3296 "yacc_sql.cpp"
    break;

  case 155:
#line 1263 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3310 "yacc_sql.cpp"
    break;

  case 156:
#line 1276 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3319 "yacc_sql.cpp"
    break;

  case 157:
#line 1284 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = std::move(std::move(*(yyvsp[0].value)));
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3331 "yacc_sql.cpp"
    break;


#line 3335 "yacc_sql.cpp"

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
#line 1296 "yacc_sql.y"

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
