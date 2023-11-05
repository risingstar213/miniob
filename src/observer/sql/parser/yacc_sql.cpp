/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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


#line 115 "yacc_sql.cpp"

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

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_INDEX = 8,                      /* INDEX  */
  YYSYMBOL_VIEW = 9,                       /* VIEW  */
  YYSYMBOL_CALC = 10,                      /* CALC  */
  YYSYMBOL_SELECT = 11,                    /* SELECT  */
  YYSYMBOL_DESC = 12,                      /* DESC  */
  YYSYMBOL_SHOW = 13,                      /* SHOW  */
  YYSYMBOL_SYNC = 14,                      /* SYNC  */
  YYSYMBOL_INSERT = 15,                    /* INSERT  */
  YYSYMBOL_DELETE = 16,                    /* DELETE  */
  YYSYMBOL_UPDATE = 17,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 21,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 22,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 23,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 24,                     /* INT_T  */
  YYSYMBOL_STRING_T = 25,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 26,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 27,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 28,                    /* TEXT_T  */
  YYSYMBOL_HELP = 29,                      /* HELP  */
  YYSYMBOL_EXIT = 30,                      /* EXIT  */
  YYSYMBOL_DOT = 31,                       /* DOT  */
  YYSYMBOL_INTO = 32,                      /* INTO  */
  YYSYMBOL_VALUES = 33,                    /* VALUES  */
  YYSYMBOL_FROM = 34,                      /* FROM  */
  YYSYMBOL_WHERE = 35,                     /* WHERE  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_SET = 38,                       /* SET  */
  YYSYMBOL_ON = 39,                        /* ON  */
  YYSYMBOL_LOAD = 40,                      /* LOAD  */
  YYSYMBOL_DATA = 41,                      /* DATA  */
  YYSYMBOL_INFILE = 42,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 43,                   /* EXPLAIN  */
  YYSYMBOL_EQ = 44,                        /* EQ  */
  YYSYMBOL_LT = 45,                        /* LT  */
  YYSYMBOL_GT = 46,                        /* GT  */
  YYSYMBOL_LE = 47,                        /* LE  */
  YYSYMBOL_GE = 48,                        /* GE  */
  YYSYMBOL_NE = 49,                        /* NE  */
  YYSYMBOL_NOT = 50,                       /* NOT  */
  YYSYMBOL_LIKE = 51,                      /* LIKE  */
  YYSYMBOL_INNER = 52,                     /* INNER  */
  YYSYMBOL_JOIN = 53,                      /* JOIN  */
  YYSYMBOL_UNIQUE = 54,                    /* UNIQUE  */
  YYSYMBOL_MAX = 55,                       /* MAX  */
  YYSYMBOL_MIN = 56,                       /* MIN  */
  YYSYMBOL_SUM = 57,                       /* SUM  */
  YYSYMBOL_COUNT = 58,                     /* COUNT  */
  YYSYMBOL_AVG = 59,                       /* AVG  */
  YYSYMBOL_LENGTH = 60,                    /* LENGTH  */
  YYSYMBOL_ROUND = 61,                     /* ROUND  */
  YYSYMBOL_DATE_FORMAT = 62,               /* DATE_FORMAT  */
  YYSYMBOL_IN = 63,                        /* IN  */
  YYSYMBOL_EXISTS = 64,                    /* EXISTS  */
  YYSYMBOL_GROUP = 65,                     /* GROUP  */
  YYSYMBOL_HAVING = 66,                    /* HAVING  */
  YYSYMBOL_AS = 67,                        /* AS  */
  YYSYMBOL_ORDER = 68,                     /* ORDER  */
  YYSYMBOL_BY = 69,                        /* BY  */
  YYSYMBOL_ASC = 70,                       /* ASC  */
  YYSYMBOL_IS = 71,                        /* IS  */
  YYSYMBOL_NULL_LITERAL = 72,              /* NULL_LITERAL  */
  YYSYMBOL_NULLABLE = 73,                  /* NULLABLE  */
  YYSYMBOL_NUMBER = 74,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 75,                     /* FLOAT  */
  YYSYMBOL_DATE = 76,                      /* DATE  */
  YYSYMBOL_ID = 77,                        /* ID  */
  YYSYMBOL_SSS = 78,                       /* SSS  */
  YYSYMBOL_79_ = 79,                       /* '+'  */
  YYSYMBOL_80_ = 80,                       /* '-'  */
  YYSYMBOL_81_ = 81,                       /* '*'  */
  YYSYMBOL_82_ = 82,                       /* '/'  */
  YYSYMBOL_UMINUS = 83,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_commands = 85,                  /* commands  */
  YYSYMBOL_command_wrapper = 86,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 87,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 88,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 89,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 90,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 91,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 92,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 93,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 94,          /* show_tables_stmt  */
  YYSYMBOL_show_index_stmt = 95,           /* show_index_stmt  */
  YYSYMBOL_desc_table_stmt = 96,           /* desc_table_stmt  */
  YYSYMBOL_is_unique = 97,                 /* is_unique  */
  YYSYMBOL_id_list = 98,                   /* id_list  */
  YYSYMBOL_create_index_stmt = 99,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 100,          /* drop_index_stmt  */
  YYSYMBOL_create_table_select = 101,      /* create_table_select  */
  YYSYMBOL_create_table_stmt = 102,        /* create_table_stmt  */
  YYSYMBOL_create_view_stmt = 103,         /* create_view_stmt  */
  YYSYMBOL_attr_def_list = 104,            /* attr_def_list  */
  YYSYMBOL_is_nullable = 105,              /* is_nullable  */
  YYSYMBOL_attr_def = 106,                 /* attr_def  */
  YYSYMBOL_number = 107,                   /* number  */
  YYSYMBOL_type = 108,                     /* type  */
  YYSYMBOL_alias = 109,                    /* alias  */
  YYSYMBOL_insert_stmt = 110,              /* insert_stmt  */
  YYSYMBOL_value_list_cell = 111,          /* value_list_cell  */
  YYSYMBOL_value_list = 112,               /* value_list  */
  YYSYMBOL_value = 113,                    /* value  */
  YYSYMBOL_delete_stmt = 114,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 115,              /* update_stmt  */
  YYSYMBOL_select_stmt = 116,              /* select_stmt  */
  YYSYMBOL_select = 117,                   /* select  */
  YYSYMBOL_calc_stmt = 118,                /* calc_stmt  */
  YYSYMBOL_expression_list = 119,          /* expression_list  */
  YYSYMBOL_expression = 120,               /* expression  */
  YYSYMBOL_select_attr = 121,              /* select_attr  */
  YYSYMBOL_rel_attr = 122,                 /* rel_attr  */
  YYSYMBOL_dyn_node = 123,                 /* dyn_node  */
  YYSYMBOL_relation = 124,                 /* relation  */
  YYSYMBOL_attr_list = 125,                /* attr_list  */
  YYSYMBOL_rel_list = 126,                 /* rel_list  */
  YYSYMBOL_where = 127,                    /* where  */
  YYSYMBOL_or_where = 128,                 /* or_where  */
  YYSYMBOL_condition_list = 129,           /* condition_list  */
  YYSYMBOL_or_condition_list = 130,        /* or_condition_list  */
  YYSYMBOL_condition = 131,                /* condition  */
  YYSYMBOL_comp_op = 132,                  /* comp_op  */
  YYSYMBOL_join_conditions = 133,          /* join_conditions  */
  YYSYMBOL_join_list = 134,                /* join_list  */
  YYSYMBOL_having = 135,                   /* having  */
  YYSYMBOL_groupby = 136,                  /* groupby  */
  YYSYMBOL_orderby = 137,                  /* orderby  */
  YYSYMBOL_orderby_list = 138,             /* orderby_list  */
  YYSYMBOL_orderby_col = 139,              /* orderby_col  */
  YYSYMBOL_insert_row_list = 140,          /* insert_row_list  */
  YYSYMBOL_update_list = 141,              /* update_list  */
  YYSYMBOL_update_pair = 142,              /* update_pair  */
  YYSYMBOL_load_data_stmt = 143,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 144,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 145,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 146             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   433

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  331

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   334


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    81,    79,     2,    80,     2,    82,     2,     2,
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
      75,    76,    77,    78,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   243,   243,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   276,   282,   287,   293,   299,
     305,   311,   318,   324,   333,   341,   344,   350,   356,   364,
     379,   390,   393,   398,   415,   434,   446,   465,   477,   480,
     492,   495,   498,   501,   507,   516,   533,   536,   537,   538,
     539,   540,   544,   547,   550,   556,   571,   574,   578,   584,
     590,   601,   605,   609,   615,   621,   628,   640,   657,   664,
     700,   737,   744,   756,   766,   782,   789,   796,   803,   810,
     816,   822,   830,   835,   842,   849,   858,   891,   901,   909,
     914,   921,   930,   935,   941,   947,   953,   960,   966,   975,
     988,   991,  1005,  1008,  1021,  1024,  1030,  1035,  1040,  1048,
    1055,  1064,  1074,  1084,  1094,  1103,  1111,  1119,  1129,  1139,
    1146,  1153,  1160,  1167,  1175,  1186,  1187,  1188,  1189,  1190,
    1191,  1195,  1198,  1204,  1207,  1220,  1223,  1231,  1234,  1246,
    1249,  1257,  1260,  1268,  1273,  1278,  1286,  1293,  1303,  1309,
    1318,  1326,  1337,  1350,  1358,  1369
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "VIEW", "CALC", "SELECT", "DESC",
  "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE",
  "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES",
  "FROM", "WHERE", "AND", "OR", "SET", "ON", "LOAD", "DATA", "INFILE",
  "EXPLAIN", "EQ", "LT", "GT", "LE", "GE", "NE", "NOT", "LIKE", "INNER",
  "JOIN", "UNIQUE", "MAX", "MIN", "SUM", "COUNT", "AVG", "LENGTH", "ROUND",
  "DATE_FORMAT", "IN", "EXISTS", "GROUP", "HAVING", "AS", "ORDER", "BY",
  "ASC", "IS", "NULL_LITERAL", "NULLABLE", "NUMBER", "FLOAT", "DATE", "ID",
  "SSS", "'+'", "'-'", "'*'", "'/'", "UMINUS", "$accept", "commands",
  "command_wrapper", "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt",
  "commit_stmt", "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "show_index_stmt", "desc_table_stmt", "is_unique", "id_list",
  "create_index_stmt", "drop_index_stmt", "create_table_select",
  "create_table_stmt", "create_view_stmt", "attr_def_list", "is_nullable",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-226)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-99)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     370,    13,    42,   257,   183,   -32,    31,  -226,    19,    39,
     -24,  -226,  -226,  -226,  -226,  -226,     2,    27,   370,    55,
      92,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,    43,    51,  -226,   124,    66,    68,
     257,   133,   142,   144,   146,   164,   166,   172,   174,  -226,
    -226,  -226,  -226,   125,  -226,   257,  -226,  -226,    54,  -226,
    -226,  -226,   173,   176,  -226,  -226,   177,   136,   137,   179,
     171,   182,  -226,  -226,  -226,  -226,     5,    26,   141,  -226,
     186,    28,   155,   155,   155,   -46,   155,   257,   257,   257,
     -45,  -226,   156,  -226,   257,   257,   257,   257,   201,   158,
     159,   193,   199,   175,     7,   130,   178,   183,   185,   238,
    -226,  -226,   185,  -226,   211,   194,  -226,   253,   254,   258,
     259,   262,   263,    33,     1,    -5,  -226,  -226,  -226,    36,
      36,  -226,  -226,   257,   -37,   256,  -226,   265,   230,  -226,
     249,  -226,   175,  -226,  -226,   267,  -226,    34,   277,  -226,
     277,   223,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,   224,   225,  -226,  -226,   158,   268,    72,  -226,   111,
     237,   291,   149,  -226,   294,    83,  -226,   330,  -226,  -226,
    -226,  -226,  -226,    52,   185,   320,   326,   329,   337,   338,
     256,   305,   324,    -9,  -226,   107,  -226,   341,   343,   238,
    -226,  -226,  -226,  -226,  -226,  -226,   -22,   257,   344,   -26,
     266,   230,   238,  -226,   286,   290,   300,  -226,  -226,  -226,
     277,    32,    32,   289,  -226,  -226,  -226,   299,   230,   312,
     312,  -226,  -226,   358,    72,   221,   238,   360,   257,   371,
      59,    14,   316,  -226,   111,    59,  -226,   375,  -226,  -226,
     376,  -226,  -226,  -226,  -226,   377,   379,   351,  -226,   138,
     327,   333,   333,   265,  -226,   293,   383,  -226,    59,    14,
     157,   384,  -226,   385,  -226,   -16,   289,  -226,   230,   268,
     230,   155,   336,  -226,  -226,  -226,   111,    59,  -226,   161,
     387,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,   372,
     391,   155,   388,  -226,  -226,   155,   346,    21,   394,  -226,
     391,   230,  -226,  -226,  -226,   155,  -226,  -226,  -226,   394,
    -226
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    28,    29,    30,    26,    25,     0,     0,     0,     0,
       0,    24,    23,    16,    17,    18,    19,    10,    11,    13,
      12,    14,    15,     8,     9,     5,     7,     6,     4,    78,
       3,    20,    21,    22,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      71,    72,    73,    99,    74,     0,    91,    81,    62,   102,
      92,    97,    82,     0,    34,    32,     0,     0,     0,     0,
       0,     0,   163,     1,   165,     2,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,    63,     0,     0,     0,     0,    83,     0,
       0,     0,   114,     0,   114,     0,     0,     0,     0,     0,
      45,    42,     0,    47,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,    64,    85,
      86,    87,    88,     0,    62,   112,    33,     0,     0,    76,
       0,   158,     0,    77,   164,     0,    98,     0,    48,    41,
      48,     0,    40,   103,   104,   108,   106,   105,   107,    93,
      94,     0,     0,    84,   109,     0,   143,     0,    65,     0,
       0,     0,     0,   115,   117,     0,   159,     0,    57,    58,
      59,    60,    61,    50,     0,     0,     0,     0,     0,     0,
     112,     0,   114,     0,    69,     0,    66,     0,     0,     0,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,   160,     0,     0,     0,    53,    52,    55,
      48,    43,     0,     0,    95,    96,   113,     0,     0,   147,
     147,    67,    68,   156,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   132,     0,   121,   118,     0,   162,    56,
       0,    51,    49,    44,    46,    37,     0,   141,   116,   117,
       0,   149,   149,     0,    70,     0,     0,   129,   134,     0,
       0,     0,   131,     0,   161,    50,     0,    39,     0,   143,
       0,     0,     0,    79,    80,   157,     0,   122,   130,     0,
       0,   127,   125,   123,    54,    38,   142,   144,   120,   119,
     110,     0,     0,   128,   126,     0,   145,   153,   151,   124,
     110,     0,   148,   155,   154,     0,   150,   111,   146,   151,
     152
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -226,  -226,   397,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,   131,  -226,  -226,   -78,  -226,  -226,
    -146,   134,  -109,  -226,  -226,   272,  -226,  -157,  -225,  -114,
    -226,  -226,  -226,     0,  -226,     6,    -1,  -226,   -88,  -226,
     243,   100,   222,  -102,  -226,  -210,   135,  -221,   181,  -226,
     132,  -226,   184,   151,    98,   103,   160,  -226,   278,  -226,
    -226,  -226,  -226
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    47,   266,    31,    32,   120,    33,    34,
     195,   229,   158,   260,   193,   108,    35,   204,   205,    66,
      36,    37,    38,   121,    40,    67,   182,    73,    69,    70,
     145,   316,   176,   149,   240,   183,   268,   184,   220,   289,
     202,   322,   271,   293,   326,   318,   178,   114,   151,    41,
      42,    43,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   154,    68,    68,   127,   128,   129,   131,   132,   123,
      72,   256,   153,   160,   196,   172,   117,   269,    39,    44,
     170,   171,    45,   118,   252,   117,   280,   152,   223,   248,
     102,    63,   136,   323,   226,   130,   137,   117,    75,    76,
     103,   249,   148,   117,   122,    74,   253,   126,    48,    91,
      49,    77,   169,    79,   299,    83,   227,   228,   188,   189,
     190,   191,   192,   206,   101,   241,   242,    46,    81,   309,
     225,   206,   119,    78,   104,   105,   106,   107,   306,    80,
     104,   105,   106,   107,   262,   230,    59,   274,    60,    61,
      62,   324,    64,   119,   203,    84,   133,   134,   135,   119,
     239,   222,   226,   139,   140,   141,   142,   104,   105,   106,
     107,   328,   104,   105,   106,   107,    68,   106,   107,   159,
      86,   102,   117,   156,   227,   228,   243,   244,    87,    50,
     206,   103,    88,   104,   105,   106,   107,   206,   104,   105,
     106,   107,    68,    89,    59,    90,    60,    61,    62,   173,
      64,    92,   203,   263,   264,    59,   100,    60,    61,    62,
      93,    64,    94,   203,    95,   206,    51,    52,    53,    54,
      55,    56,    57,    58,   221,   290,   301,   244,    91,   207,
     313,   244,    96,    59,    97,    60,    61,    62,    63,    64,
      98,    65,    99,   210,   211,   212,   213,   214,   215,   216,
     217,    50,    59,   310,    60,    61,    62,   -98,    64,   247,
     109,   110,   218,   111,   112,   115,   250,   113,   124,   255,
     219,   143,   257,   317,   116,   125,   147,   320,   104,   105,
     106,   107,    63,   138,   148,   144,   146,   317,    51,    52,
      53,    54,    55,    56,    57,    58,   276,   278,   179,   117,
     161,   281,   150,    91,   283,    59,   155,    60,    61,    62,
      63,    64,   157,    65,    71,   210,   211,   212,   213,   214,
     215,   162,   163,   164,   297,    50,   175,   165,   166,   300,
     180,   167,   168,   177,   254,    51,    52,    53,    54,    55,
      56,    57,    58,   185,   181,    91,   312,   194,   198,   187,
     197,   208,    59,   199,    60,    61,    62,    63,    64,   209,
      65,   296,    51,    52,    53,    54,    55,    56,    57,    58,
     201,    51,    52,    53,    54,    55,    56,    57,    58,    59,
     221,    60,    61,    62,    63,    64,   224,    65,    59,   231,
      60,    61,    62,    63,    64,   232,    65,   233,    51,    52,
      53,    54,    55,    56,    57,    58,   234,   235,   237,   238,
     245,   246,   251,   258,   259,    59,   265,    60,    61,    62,
      63,    64,   261,    65,     1,     2,   267,   270,   273,   277,
       3,     4,     5,     6,     7,     8,     9,    10,   282,   279,
     288,    11,    12,    13,   284,   285,   291,   286,   287,    14,
      15,   292,   298,   302,   303,   311,   314,   319,    16,   290,
      17,   315,   321,    18,   325,    82,   174,   305,   200,   304,
     327,   307,   236,   294,   272,   308,   275,   330,   329,     0,
     186,     0,     0,   295
};

static const yytype_int16 yycheck[] =
{
       0,   115,     3,     4,    92,    93,    94,    95,    96,    87,
       4,   221,   114,   122,   160,    20,    11,   238,    18,     6,
      19,    20,     9,    18,    50,    11,   251,    20,   185,    51,
      67,    77,    77,    12,    50,    81,    81,    11,     7,     8,
      77,    63,    35,    11,    18,    77,    72,    19,     6,    50,
       8,    32,    19,    77,   279,     0,    72,    73,    24,    25,
      26,    27,    28,   177,    65,    74,    75,    54,    41,   290,
      18,   185,    67,    34,    79,    80,    81,    82,   288,    77,
      79,    80,    81,    82,   230,   194,    72,   244,    74,    75,
      76,    70,    78,    67,    80,     3,    97,    98,    99,    67,
     202,    18,    50,   104,   105,   106,   107,    79,    80,    81,
      82,   321,    79,    80,    81,    82,   117,    81,    82,   119,
      77,    67,    11,   117,    72,    73,    19,    20,    77,    18,
     244,    77,     8,    79,    80,    81,    82,   251,    79,    80,
      81,    82,   143,    77,    72,    77,    74,    75,    76,   143,
      78,    18,    80,   231,   232,    72,    31,    74,    75,    76,
      18,    78,    18,    80,    18,   279,    55,    56,    57,    58,
      59,    60,    61,    62,    36,    37,    19,    20,   179,   179,
      19,    20,    18,    72,    18,    74,    75,    76,    77,    78,
      18,    80,    18,    44,    45,    46,    47,    48,    49,    50,
      51,    18,    72,   291,    74,    75,    76,    34,    78,   209,
      34,    34,    63,    77,    77,    44,   217,    38,    77,   220,
      71,    20,   222,   311,    42,    39,    33,   315,    79,    80,
      81,    82,    77,    77,    35,    77,    77,   325,    55,    56,
      57,    58,    59,    60,    61,    62,   246,   248,    18,    11,
      39,   251,    77,   254,   254,    72,    78,    74,    75,    76,
      77,    78,    77,    80,    81,    44,    45,    46,    47,    48,
      49,    77,    19,    19,   275,    18,    20,    19,    19,   279,
      50,    19,    19,    18,    18,    55,    56,    57,    58,    59,
      60,    61,    62,    44,    64,   296,   296,    20,    74,    32,
      77,    64,    72,    78,    74,    75,    76,    77,    78,    18,
      80,    18,    55,    56,    57,    58,    59,    60,    61,    62,
      52,    55,    56,    57,    58,    59,    60,    61,    62,    72,
      36,    74,    75,    76,    77,    78,     6,    80,    72,    19,
      74,    75,    76,    77,    78,    19,    80,    18,    55,    56,
      57,    58,    59,    60,    61,    62,    19,    19,    53,    35,
      19,    18,    18,    77,    74,    72,    77,    74,    75,    76,
      77,    78,    72,    80,     4,     5,    77,    65,    20,    19,
      10,    11,    12,    13,    14,    15,    16,    17,    72,    18,
      39,    21,    22,    23,    19,    19,    69,    20,    19,    29,
      30,    68,    19,    19,    19,    69,    19,    19,    38,    37,
      40,    20,    66,    43,    20,    18,   144,   286,   175,   285,
     320,   289,   200,   272,   240,   290,   245,   329,   325,    -1,
     152,    -1,    -1,   273
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    10,    11,    12,    13,    14,    15,    16,
      17,    21,    22,    23,    29,    30,    38,    40,    43,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    99,   100,   102,   103,   110,   114,   115,   116,   117,
     118,   143,   144,   145,     6,     9,    54,    97,     6,     8,
      18,    55,    56,    57,    58,    59,    60,    61,    62,    72,
      74,    75,    76,    77,    78,    80,   113,   119,   120,   122,
     123,    81,   119,   121,    77,     7,     8,    32,    34,    77,
      77,    41,    86,     0,     3,   146,    77,    77,     8,    77,
      77,   120,    18,    18,    18,    18,    18,    18,    18,    18,
      31,   120,    67,    77,    79,    80,    81,    82,   109,    34,
      34,    77,    77,    38,   141,    44,    42,    11,    18,    67,
     101,   117,    18,   101,    77,    39,    19,   122,   122,   122,
      81,   122,   122,   120,   120,   120,    77,    81,    77,   120,
     120,   120,   120,    20,    77,   124,    77,    33,    35,   127,
      77,   142,    20,   127,   113,    78,   119,    77,   106,   117,
     106,    39,    77,    19,    19,    19,    19,    19,    19,    19,
      19,    20,    20,   119,   109,    20,   126,    18,   140,    18,
      50,    64,   120,   129,   131,    44,   142,    32,    24,    25,
      26,    27,    28,   108,    20,   104,   104,    77,    74,    78,
     124,    52,   134,    80,   111,   112,   113,   117,    64,    18,
      44,    45,    46,    47,    48,    49,    50,    51,    63,    71,
     132,    36,    18,   111,     6,    18,    50,    72,    73,   105,
     106,    19,    19,    18,    19,    19,   126,    53,    35,   127,
     128,    74,    75,    19,    20,    19,    18,   117,    51,    63,
     120,    18,    50,    72,    18,   120,   129,   117,    77,    74,
     107,    72,   104,   101,   101,    77,    98,    77,   130,   131,
      65,   136,   136,    20,   111,   132,   117,    19,   120,    18,
     112,   117,    72,   117,    19,    19,    20,    19,    39,   133,
      37,    69,    68,   137,   137,   140,    18,   120,    19,   112,
     117,    19,    19,    19,   105,    98,   129,   134,   130,   131,
     122,    69,   117,    19,    19,    20,   125,   122,   139,    19,
     122,    66,   135,    12,    70,    20,   138,   125,   129,   139,
     138
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    97,    98,    98,    99,
     100,   101,   101,   102,   102,   102,   103,   103,   104,   104,
     105,   105,   105,   105,   106,   106,   107,   108,   108,   108,
     108,   108,   109,   109,   109,   110,   111,   111,   111,   112,
     112,   113,   113,   113,   113,   113,   114,   115,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   122,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   124,
     125,   125,   126,   126,   127,   127,   128,   129,   129,   130,
     130,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   132,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   139,   140,   140,   141,   141,
     142,   142,   143,   144,   145,   146
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     4,     2,     0,     1,     1,     3,     9,
       5,     2,     1,     7,     8,     4,     8,     4,     0,     3,
       0,     2,     1,     1,     6,     3,     1,     1,     1,     1,
       1,     1,     0,     1,     2,     5,     1,     2,     2,     1,
       3,     1,     1,     1,     1,     1,     4,     4,     1,     9,
       9,     2,     2,     2,     4,     3,     3,     3,     3,     3,
       2,     1,     1,     4,     4,     6,     6,     1,     1,     1,
       3,     3,     1,     4,     4,     4,     4,     4,     4,     2,
       0,     3,     0,     3,     0,     2,     2,     1,     3,     3,
       3,     3,     5,     5,     7,     5,     6,     5,     6,     4,
       5,     4,     3,     3,     4,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     5,     0,     2,     0,     5,     0,
       4,     0,     3,     1,     2,     2,     3,     5,     2,     3,
       3,     5,     7,     2,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
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
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 244 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1914 "yacc_sql.cpp"
    break;

  case 25: /* exit_stmt: EXIT  */
#line 276 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1923 "yacc_sql.cpp"
    break;

  case 26: /* help_stmt: HELP  */
#line 282 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1931 "yacc_sql.cpp"
    break;

  case 27: /* sync_stmt: SYNC  */
#line 287 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1939 "yacc_sql.cpp"
    break;

  case 28: /* begin_stmt: TRX_BEGIN  */
#line 293 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1947 "yacc_sql.cpp"
    break;

  case 29: /* commit_stmt: TRX_COMMIT  */
#line 299 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1955 "yacc_sql.cpp"
    break;

  case 30: /* rollback_stmt: TRX_ROLLBACK  */
#line 305 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1963 "yacc_sql.cpp"
    break;

  case 31: /* drop_table_stmt: DROP TABLE ID  */
#line 311 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1973 "yacc_sql.cpp"
    break;

  case 32: /* show_tables_stmt: SHOW TABLES  */
#line 318 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1981 "yacc_sql.cpp"
    break;

  case 33: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 325 "yacc_sql.y"
                {
			(yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
			(yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
		}
#line 1991 "yacc_sql.cpp"
    break;

  case 34: /* desc_table_stmt: DESC ID  */
#line 333 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2001 "yacc_sql.cpp"
    break;

  case 35: /* is_unique: %empty  */
#line 341 "yacc_sql.y"
              {
    (yyval.bools) = false;
  }
#line 2009 "yacc_sql.cpp"
    break;

  case 36: /* is_unique: UNIQUE  */
#line 344 "yacc_sql.y"
           {
    (yyval.bools) = true;
  }
#line 2017 "yacc_sql.cpp"
    break;

  case 37: /* id_list: ID  */
#line 350 "yacc_sql.y"
     {
    (yyval.id_list) = new std::deque<std::string>();
    std::string attribute_name = (yyvsp[0].string);
    free((yyvsp[0].string));
    (yyval.id_list)->emplace_back(attribute_name);
  }
#line 2028 "yacc_sql.cpp"
    break;

  case 38: /* id_list: ID COMMA id_list  */
#line 356 "yacc_sql.y"
                     {
    (yyval.id_list) = (yyvsp[0].id_list);
    std::string attribute_name = (yyvsp[-2].string);
    free((yyvsp[-2].string));
    (yyval.id_list)->emplace_front(attribute_name);
  }
#line 2039 "yacc_sql.cpp"
    break;

  case 39: /* create_index_stmt: CREATE is_unique INDEX ID ON ID LBRACE id_list RBRACE  */
#line 365 "yacc_sql.y"
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
#line 2055 "yacc_sql.cpp"
    break;

  case 40: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 380 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2067 "yacc_sql.cpp"
    break;

  case 41: /* create_table_select: AS select  */
#line 390 "yacc_sql.y"
            {
    (yyval.select) = (yyvsp[0].select);
  }
#line 2075 "yacc_sql.cpp"
    break;

  case 42: /* create_table_select: select  */
#line 393 "yacc_sql.y"
           {
    (yyval.select) = (yyvsp[0].select);
  }
#line 2083 "yacc_sql.cpp"
    break;

  case 43: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 399 "yacc_sql.y"
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
#line 2104 "yacc_sql.cpp"
    break;

  case 44: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE create_table_select  */
#line 416 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::deque<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_front(std::move(*(yyvsp[-3].attr_info)));
      // std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);
      delete (yyvsp[-2].attr_infos);

      create_table.as_select = std::unique_ptr<SelectSqlNode>((yyvsp[0].select));
    }
#line 2127 "yacc_sql.cpp"
    break;

  case 45: /* create_table_stmt: CREATE TABLE ID create_table_select  */
#line 435 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));

      create_table.as_select = std::unique_ptr<SelectSqlNode>((yyvsp[0].select));
    }
#line 2140 "yacc_sql.cpp"
    break;

  case 46: /* create_view_stmt: CREATE VIEW ID LBRACE attr_def attr_def_list RBRACE create_table_select  */
#line 447 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_VIEW);
      CreateViewSqlNode &create_view = (yyval.sql_node)->create_view;
      create_view.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::deque<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_view.attr_infos.swap(*src_attrs);
      }
      create_view.attr_infos.emplace_front(std::move(*(yyvsp[-3].attr_info)));
      // std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);
      delete (yyvsp[-2].attr_infos);

      create_view.as_select = std::unique_ptr<SelectSqlNode>((yyvsp[0].select));
    }
#line 2163 "yacc_sql.cpp"
    break;

  case 47: /* create_view_stmt: CREATE VIEW ID create_table_select  */
#line 466 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_VIEW);
      CreateViewSqlNode &create_view = (yyval.sql_node)->create_view;
      create_view.relation_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));

      create_view.as_select = std::unique_ptr<SelectSqlNode>((yyvsp[0].select));
    }
#line 2176 "yacc_sql.cpp"
    break;

  case 48: /* attr_def_list: %empty  */
#line 477 "yacc_sql.y"
    {
      (yyval.attr_infos) = new std::deque<AttrInfoSqlNode>;
    }
#line 2184 "yacc_sql.cpp"
    break;

  case 49: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 481 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::deque<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_front(std::move(*(yyvsp[-1].attr_info)));
      delete (yyvsp[-1].attr_info);
    }
#line 2198 "yacc_sql.cpp"
    break;

  case 50: /* is_nullable: %empty  */
#line 492 "yacc_sql.y"
              {
    (yyval.number) = -1;
  }
#line 2206 "yacc_sql.cpp"
    break;

  case 51: /* is_nullable: NOT NULL_LITERAL  */
#line 495 "yacc_sql.y"
                     {
    (yyval.number) = 0;
  }
#line 2214 "yacc_sql.cpp"
    break;

  case 52: /* is_nullable: NULLABLE  */
#line 498 "yacc_sql.y"
             {
    (yyval.number) = 1;
  }
#line 2222 "yacc_sql.cpp"
    break;

  case 53: /* is_nullable: NULL_LITERAL  */
#line 501 "yacc_sql.y"
                 {
    (yyval.number) = 1;
  }
#line 2230 "yacc_sql.cpp"
    break;

  case 54: /* attr_def: ID type LBRACE number RBRACE is_nullable  */
#line 508 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->unsolved = (yyvsp[0].number);
      free((yyvsp[-5].string));
    }
#line 2243 "yacc_sql.cpp"
    break;

  case 55: /* attr_def: ID type is_nullable  */
#line 517 "yacc_sql.y"
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
#line 2262 "yacc_sql.cpp"
    break;

  case 56: /* number: NUMBER  */
#line 533 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2268 "yacc_sql.cpp"
    break;

  case 57: /* type: INT_T  */
#line 536 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2274 "yacc_sql.cpp"
    break;

  case 58: /* type: STRING_T  */
#line 537 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2280 "yacc_sql.cpp"
    break;

  case 59: /* type: FLOAT_T  */
#line 538 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2286 "yacc_sql.cpp"
    break;

  case 60: /* type: DATE_T  */
#line 539 "yacc_sql.y"
               { (yyval.number)=DATES; }
#line 2292 "yacc_sql.cpp"
    break;

  case 61: /* type: TEXT_T  */
#line 540 "yacc_sql.y"
               { (yyval.number)=TEXTS; }
#line 2298 "yacc_sql.cpp"
    break;

  case 62: /* alias: %empty  */
#line 544 "yacc_sql.y"
              {
    (yyval.string) = nullptr;
  }
#line 2306 "yacc_sql.cpp"
    break;

  case 63: /* alias: ID  */
#line 547 "yacc_sql.y"
       {
    (yyval.string) = (yyvsp[0].string);
  }
#line 2314 "yacc_sql.cpp"
    break;

  case 64: /* alias: AS ID  */
#line 550 "yacc_sql.y"
          {
    (yyval.string) = (yyvsp[0].string);
  }
#line 2322 "yacc_sql.cpp"
    break;

  case 65: /* insert_stmt: INSERT INTO ID VALUES insert_row_list  */
#line 557 "yacc_sql.y"
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
#line 2338 "yacc_sql.cpp"
    break;

  case 66: /* value_list_cell: value  */
#line 571 "yacc_sql.y"
        {
    (yyval.value) = (yyvsp[0].value);
  }
#line 2346 "yacc_sql.cpp"
    break;

  case 67: /* value_list_cell: '-' NUMBER  */
#line 574 "yacc_sql.y"
               {
    (yyval.value) = new Value(-(int)(yyvsp[0].number));
    // @$ = @1;
  }
#line 2355 "yacc_sql.cpp"
    break;

  case 68: /* value_list_cell: '-' FLOAT  */
#line 578 "yacc_sql.y"
              {
    (yyval.value) = new Value(-(float)(yyvsp[0].floats));
    // @$ = @1;
  }
#line 2364 "yacc_sql.cpp"
    break;

  case 69: /* value_list: value_list_cell  */
#line 585 "yacc_sql.y"
    {
      (yyval.value_list) = new std::deque<Value>;
      (yyval.value_list)->emplace_back(std::move(*(yyvsp[0].value)));
      delete (yyvsp[0].value);
    }
#line 2374 "yacc_sql.cpp"
    break;

  case 70: /* value_list: value_list COMMA value_list_cell  */
#line 590 "yacc_sql.y"
                                        { 
      if ((yyvsp[-2].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[-2].value_list);
      } else {
        (yyval.value_list) = new std::deque<Value>;
      }
      (yyval.value_list)->emplace_back(std::move(*(yyvsp[0].value)));
      delete (yyvsp[0].value);
    }
#line 2388 "yacc_sql.cpp"
    break;

  case 71: /* value: NUMBER  */
#line 601 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2397 "yacc_sql.cpp"
    break;

  case 72: /* value: FLOAT  */
#line 605 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2406 "yacc_sql.cpp"
    break;

  case 73: /* value: DATE  */
#line 609 "yacc_sql.y"
          {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp, true, true);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2417 "yacc_sql.cpp"
    break;

  case 74: /* value: SSS  */
#line 615 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2428 "yacc_sql.cpp"
    break;

  case 75: /* value: NULL_LITERAL  */
#line 621 "yacc_sql.y"
                  {
      (yyval.value) = new Value(0);
      (yyval.value)->set_null(true);
    }
#line 2437 "yacc_sql.cpp"
    break;

  case 76: /* delete_stmt: DELETE FROM ID where  */
#line 629 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2451 "yacc_sql.cpp"
    break;

  case 77: /* update_stmt: UPDATE ID update_list where  */
#line 641 "yacc_sql.y"
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
#line 2469 "yacc_sql.cpp"
    break;

  case 78: /* select_stmt: select  */
#line 657 "yacc_sql.y"
           {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      (yyval.sql_node)->selection = std::move(*(yyvsp[0].select));
      delete (yyvsp[0].select);
    }
#line 2479 "yacc_sql.cpp"
    break;

  case 79: /* select: SELECT select_attr FROM relation rel_list join_list where groupby orderby  */
#line 665 "yacc_sql.y"
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
#line 2519 "yacc_sql.cpp"
    break;

  case 80: /* select: SELECT select_attr FROM relation rel_list join_list or_where groupby orderby  */
#line 700 "yacc_sql.y"
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
#line 2559 "yacc_sql.cpp"
    break;

  case 81: /* calc_stmt: CALC expression_list  */
#line 738 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      // std::reverse($2->begin(), $2->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2570 "yacc_sql.cpp"
    break;

  case 82: /* calc_stmt: SELECT expression_list  */
#line 745 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      // std::reverse($2->begin(), $2->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      (yyval.sql_node)->calc.is_select = true;
      delete (yyvsp[0].expression_list);
    }
#line 2582 "yacc_sql.cpp"
    break;

  case 83: /* expression_list: expression alias  */
#line 757 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::deque<ExprSqlNode>;
      if ((yyvsp[0].string) != nullptr) {
        (yyvsp[-1].expression)->alias = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
      (yyval.expression_list)->emplace_back(std::move(*(yyvsp[-1].expression)));
      delete (yyvsp[-1].expression);
    }
#line 2596 "yacc_sql.cpp"
    break;

  case 84: /* expression_list: expression alias COMMA expression_list  */
#line 767 "yacc_sql.y"
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
#line 2614 "yacc_sql.cpp"
    break;

  case 85: /* expression: expression '+' expression  */
#line 782 "yacc_sql.y"
                              {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_ADD;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2626 "yacc_sql.cpp"
    break;

  case 86: /* expression: expression '-' expression  */
#line 789 "yacc_sql.y"
                                {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_SUB;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2638 "yacc_sql.cpp"
    break;

  case 87: /* expression: expression '*' expression  */
#line 796 "yacc_sql.y"
                                {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_MUL;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2650 "yacc_sql.cpp"
    break;

  case 88: /* expression: expression '/' expression  */
#line 803 "yacc_sql.y"
                                {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_DIV;
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2662 "yacc_sql.cpp"
    break;

  case 89: /* expression: LBRACE expression RBRACE  */
#line 810 "yacc_sql.y"
                               {
      // $$ = $2;
      // $$->set_name(token_name(sql_string, &@$));
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->has_brace = true;
    }
#line 2673 "yacc_sql.cpp"
    break;

  case 90: /* expression: '-' expression  */
#line 816 "yacc_sql.y"
                                  {
      // $$ = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, $2, nullptr, sql_string, &@$);
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_NEGATIVE;
      (yyval.expression)->right = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
    }
#line 2684 "yacc_sql.cpp"
    break;

  case 91: /* expression: value  */
#line 822 "yacc_sql.y"
            {
      // $$ = new ValueExpr(std::move(*$1);
      // $$->set_name(token_name(sql_string, &@$));
      // delete $1;
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_VAL;
      (yyval.expression)->value = std::unique_ptr<Value>((yyvsp[0].value));
    }
#line 2697 "yacc_sql.cpp"
    break;

  case 92: /* expression: dyn_node  */
#line 830 "yacc_sql.y"
               {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->type = ExprNodeType::E_DYN;
      (yyval.expression)->attr = std::unique_ptr<DynNodeSqlNode>((yyvsp[0].dyn_node));
    }
#line 2707 "yacc_sql.cpp"
    break;

  case 93: /* expression: LENGTH LBRACE expression RBRACE  */
#line 835 "yacc_sql.y"
                                      {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-1].expression));
      FunctionSqlNode func;
      func.funcType = F_LENGTH;
      (yyval.expression)->func = std::make_unique<FunctionSqlNode>(func);
    }
#line 2719 "yacc_sql.cpp"
    break;

  case 94: /* expression: ROUND LBRACE expression RBRACE  */
#line 842 "yacc_sql.y"
                                     {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-1].expression));
      FunctionSqlNode func;
      func.funcType = F_ROUND;
      (yyval.expression)->func = std::make_unique<FunctionSqlNode>(func);
    }
#line 2731 "yacc_sql.cpp"
    break;

  case 95: /* expression: ROUND LBRACE expression COMMA NUMBER RBRACE  */
#line 849 "yacc_sql.y"
                                                  {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      FunctionSqlNode func;
      func.funcType = F_ROUND;
      func.round_has = true;
      func.round_number = (yyvsp[-1].number);
      (yyval.expression)->func = std::make_unique<FunctionSqlNode>(func);
    }
#line 2745 "yacc_sql.cpp"
    break;

  case 96: /* expression: DATE_FORMAT LBRACE expression COMMA SSS RBRACE  */
#line 858 "yacc_sql.y"
                                                     {
      (yyval.expression) = new ExprSqlNode();
      (yyval.expression)->left = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      FunctionSqlNode func;
      func.funcType = F_FORMAT;
      char *tmp = common::substr((yyvsp[-1].string),1,strlen((yyvsp[-1].string))-2);
      func.format = tmp;
      free(tmp);
      free((yyvsp[-1].string));
      (yyval.expression)->func = std::make_unique<FunctionSqlNode>(func);
    }
#line 2761 "yacc_sql.cpp"
    break;

  case 97: /* select_attr: '*'  */
#line 891 "yacc_sql.y"
      {
    (yyval.expression_list) = new std::deque<ExprSqlNode>();
    ExprSqlNode expr;
    expr.type = ExprNodeType::E_DYN;
    expr.attr = std::unique_ptr<DynNodeSqlNode>(new DynNodeSqlNode);

    expr.attr->node.attribute_name = "*";
    
    (yyval.expression_list)->push_back(std::move(expr));
  }
#line 2776 "yacc_sql.cpp"
    break;

  case 98: /* select_attr: expression_list  */
#line 901 "yacc_sql.y"
                    {
    (yyval.expression_list) = (yyvsp[0].expression_list);
    // $2->push_front(std::move(*$1);
    // delete $1;
  }
#line 2786 "yacc_sql.cpp"
    break;

  case 99: /* rel_attr: ID  */
#line 909 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2796 "yacc_sql.cpp"
    break;

  case 100: /* rel_attr: ID DOT ID  */
#line 914 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2808 "yacc_sql.cpp"
    break;

  case 101: /* rel_attr: ID DOT '*'  */
#line 921 "yacc_sql.y"
                 {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = "*";
      free((yyvsp[-2].string));
    }
#line 2819 "yacc_sql.cpp"
    break;

  case 102: /* dyn_node: rel_attr  */
#line 930 "yacc_sql.y"
           {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->node = std::move(*(yyvsp[0].rel_attr));
    delete (yyvsp[0].rel_attr);
  }
#line 2829 "yacc_sql.cpp"
    break;

  case 103: /* dyn_node: MAX LBRACE rel_attr RBRACE  */
#line 935 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_MAX;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2840 "yacc_sql.cpp"
    break;

  case 104: /* dyn_node: MIN LBRACE rel_attr RBRACE  */
#line 941 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_MIN;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2851 "yacc_sql.cpp"
    break;

  case 105: /* dyn_node: COUNT LBRACE rel_attr RBRACE  */
#line 947 "yacc_sql.y"
                                 {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_COUNT;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2862 "yacc_sql.cpp"
    break;

  case 106: /* dyn_node: COUNT LBRACE '*' RBRACE  */
#line 953 "yacc_sql.y"
                            {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_COUNT;
    (yyval.dyn_node)->node.attribute_name = '*';
    // $$->node = std::move(*$3);
    // delete $3;
  }
#line 2874 "yacc_sql.cpp"
    break;

  case 107: /* dyn_node: AVG LBRACE rel_attr RBRACE  */
#line 960 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_AVG;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2885 "yacc_sql.cpp"
    break;

  case 108: /* dyn_node: SUM LBRACE rel_attr RBRACE  */
#line 966 "yacc_sql.y"
                               {
    (yyval.dyn_node) = new DynNodeSqlNode();
    (yyval.dyn_node)->aggType = AggregationType::A_SUM;
    (yyval.dyn_node)->node = std::move(*(yyvsp[-1].rel_attr));
    delete (yyvsp[-1].rel_attr);
  }
#line 2896 "yacc_sql.cpp"
    break;

  case 109: /* relation: ID alias  */
#line 975 "yacc_sql.y"
           {
    (yyval.relation) = new RelSqlNode;
    (yyval.relation)->relation = (yyvsp[-1].string);
    free((yyvsp[-1].string));
    if ((yyvsp[0].string) != nullptr) {
      (yyval.relation)->alias    = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
  }
#line 2910 "yacc_sql.cpp"
    break;

  case 110: /* attr_list: %empty  */
#line 988 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = new std::deque<RelAttrSqlNode>;
    }
#line 2918 "yacc_sql.cpp"
    break;

  case 111: /* attr_list: COMMA rel_attr attr_list  */
#line 991 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::deque<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_front(std::move(*(yyvsp[-1].rel_attr)));
      delete (yyvsp[-1].rel_attr);
    }
#line 2933 "yacc_sql.cpp"
    break;

  case 112: /* rel_list: %empty  */
#line 1005 "yacc_sql.y"
    {
      (yyval.relation_list) = new std::deque<RelSqlNode>;
    }
#line 2941 "yacc_sql.cpp"
    break;

  case 113: /* rel_list: COMMA relation rel_list  */
#line 1008 "yacc_sql.y"
                              {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::deque<RelSqlNode>;
      }

      (yyval.relation_list)->push_front(std::move(*(yyvsp[-1].relation)));
      delete (yyvsp[-1].relation);
    }
#line 2956 "yacc_sql.cpp"
    break;

  case 114: /* where: %empty  */
#line 1021 "yacc_sql.y"
    {
      (yyval.condition_list) = new std::deque<ConditionSqlNode>();
    }
#line 2964 "yacc_sql.cpp"
    break;

  case 115: /* where: WHERE condition_list  */
#line 1024 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2972 "yacc_sql.cpp"
    break;

  case 116: /* or_where: WHERE or_condition_list  */
#line 1030 "yacc_sql.y"
                          {
		(yyval.condition_list) = (yyvsp[0].condition_list);
  }
#line 2980 "yacc_sql.cpp"
    break;

  case 117: /* condition_list: condition  */
#line 1035 "yacc_sql.y"
              {
      (yyval.condition_list) = new std::deque<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(std::move(std::move(*(yyvsp[0].condition))));
      delete (yyvsp[0].condition);
    }
#line 2990 "yacc_sql.cpp"
    break;

  case 118: /* condition_list: condition AND condition_list  */
#line 1040 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_front(std::move(std::move(*(yyvsp[-2].condition))));
      delete (yyvsp[-2].condition);
    }
#line 3000 "yacc_sql.cpp"
    break;

  case 119: /* or_condition_list: condition OR condition  */
#line 1048 "yacc_sql.y"
                         {
    (yyval.condition_list) = new std::deque<ConditionSqlNode>();
		(yyval.condition_list)->push_back(std::move(*(yyvsp[-2].condition)));
		(yyval.condition_list)->push_back(std::move(*(yyvsp[0].condition)));
		delete (yyvsp[-2].condition);
		delete (yyvsp[0].condition);
  }
#line 3012 "yacc_sql.cpp"
    break;

  case 120: /* or_condition_list: condition OR or_condition_list  */
#line 1055 "yacc_sql.y"
                                   {
    (yyval.condition_list) = (yyvsp[0].condition_list);
		(yyval.condition_list)->push_front(std::move(*(yyvsp[-2].condition)));
		delete (yyvsp[-2].condition);
  }
#line 3022 "yacc_sql.cpp"
    break;

  case 121: /* condition: expression comp_op expression  */
#line 1065 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op = (yyvsp[-1].comp);

    }
#line 3036 "yacc_sql.cpp"
    break;

  case 122: /* condition: LBRACE select RBRACE comp_op expression  */
#line 1075 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = true;
      (yyval.condition)->left_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-3].select));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op= (yyvsp[-1].comp);

    }
#line 3050 "yacc_sql.cpp"
    break;

  case 123: /* condition: expression comp_op LBRACE select RBRACE  */
#line 1085 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-4].expression));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = (yyvsp[-3].comp);

    }
#line 3064 "yacc_sql.cpp"
    break;

  case 124: /* condition: LBRACE select RBRACE comp_op LBRACE select RBRACE  */
#line 1094 "yacc_sql.y"
                                                        {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = true;
      (yyval.condition)->left_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-5].select));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = (yyvsp[-3].comp);

    }
#line 3078 "yacc_sql.cpp"
    break;

  case 125: /* condition: expression IN LBRACE select RBRACE  */
#line 1103 "yacc_sql.y"
                                         {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-4].expression));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::IN_SQ;
    }
#line 3091 "yacc_sql.cpp"
    break;

  case 126: /* condition: expression NOT IN LBRACE select RBRACE  */
#line 1111 "yacc_sql.y"
                                             {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-5].expression));
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::NOT_IN_SQ;
    }
#line 3104 "yacc_sql.cpp"
    break;

  case 127: /* condition: expression IN LBRACE value_list RBRACE  */
#line 1119 "yacc_sql.y"
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
#line 3119 "yacc_sql.cpp"
    break;

  case 128: /* condition: expression NOT IN LBRACE value_list RBRACE  */
#line 1129 "yacc_sql.y"
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
#line 3134 "yacc_sql.cpp"
    break;

  case 129: /* condition: EXISTS LBRACE select RBRACE  */
#line 1139 "yacc_sql.y"
                                  {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::EXISTS_SQ;
    }
#line 3146 "yacc_sql.cpp"
    break;

  case 130: /* condition: NOT EXISTS LBRACE select RBRACE  */
#line 1146 "yacc_sql.y"
                                      {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->right_is_subquery = true;
      (yyval.condition)->right_subquery = std::unique_ptr<SelectSqlNode>((yyvsp[-1].select));
      (yyval.condition)->op = CompOp::NOT_EXISTS_SQ;
    }
#line 3158 "yacc_sql.cpp"
    break;

  case 131: /* condition: expression IS NOT NULL_LITERAL  */
#line 1153 "yacc_sql.y"
                                     {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->op = CompOp::IS_NOT_NULL;
    }
#line 3170 "yacc_sql.cpp"
    break;

  case 132: /* condition: expression IS NULL_LITERAL  */
#line 1160 "yacc_sql.y"
                                 {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->op = CompOp::IS_NULL;
    }
#line 3182 "yacc_sql.cpp"
    break;

  case 133: /* condition: expression LIKE expression  */
#line 1167 "yacc_sql.y"
                                 {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-2].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op = LIKE_SCH;
    }
#line 3195 "yacc_sql.cpp"
    break;

  case 134: /* condition: expression NOT LIKE expression  */
#line 1175 "yacc_sql.y"
                                     {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_subquery = false;
      (yyval.condition)->left_expr = std::unique_ptr<ExprSqlNode>((yyvsp[-3].expression));
      (yyval.condition)->right_is_subquery = false;
      (yyval.condition)->right_expr = std::unique_ptr<ExprSqlNode>((yyvsp[0].expression));
      (yyval.condition)->op = NOT_LIKE_SCH;
    }
#line 3208 "yacc_sql.cpp"
    break;

  case 135: /* comp_op: EQ  */
#line 1186 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3214 "yacc_sql.cpp"
    break;

  case 136: /* comp_op: LT  */
#line 1187 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3220 "yacc_sql.cpp"
    break;

  case 137: /* comp_op: GT  */
#line 1188 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3226 "yacc_sql.cpp"
    break;

  case 138: /* comp_op: LE  */
#line 1189 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3232 "yacc_sql.cpp"
    break;

  case 139: /* comp_op: GE  */
#line 1190 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3238 "yacc_sql.cpp"
    break;

  case 140: /* comp_op: NE  */
#line 1191 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3244 "yacc_sql.cpp"
    break;

  case 141: /* join_conditions: %empty  */
#line 1195 "yacc_sql.y"
              {
    (yyval.condition_list) = new std::deque<ConditionSqlNode>;
  }
#line 3252 "yacc_sql.cpp"
    break;

  case 142: /* join_conditions: ON condition_list  */
#line 1198 "yacc_sql.y"
                      {
    (yyval.condition_list) = (yyvsp[0].condition_list);
  }
#line 3260 "yacc_sql.cpp"
    break;

  case 143: /* join_list: %empty  */
#line 1204 "yacc_sql.y"
             {
    (yyval.join_list) = new std::deque<JoinSqlNode>();
  }
#line 3268 "yacc_sql.cpp"
    break;

  case 144: /* join_list: INNER JOIN ID join_conditions join_list  */
#line 1207 "yacc_sql.y"
                                                  {
		(yyval.join_list) = (yyvsp[0].join_list);
		JoinSqlNode join;
		join.relation = (yyvsp[-2].string);
		join.on_coditions = std::move(*(yyvsp[-1].condition_list));
		(yyval.join_list)->push_front(std::move(join));

    free((yyvsp[-2].string));
    delete (yyvsp[-1].condition_list);
	}
#line 3283 "yacc_sql.cpp"
    break;

  case 145: /* having: %empty  */
#line 1220 "yacc_sql.y"
             {
		(yyval.condition_list) = new std::deque<ConditionSqlNode>;
	}
#line 3291 "yacc_sql.cpp"
    break;

  case 146: /* having: HAVING condition_list  */
#line 1223 "yacc_sql.y"
                                {
		(yyval.condition_list) = (yyvsp[0].condition_list);
		// $$->push_front(std::move(*$2);
		// delete $2;
	}
#line 3301 "yacc_sql.cpp"
    break;

  case 147: /* groupby: %empty  */
#line 1231 "yacc_sql.y"
              {
    (yyval.groupby) = nullptr;
  }
#line 3309 "yacc_sql.cpp"
    break;

  case 148: /* groupby: GROUP BY rel_attr attr_list having  */
#line 1234 "yacc_sql.y"
                                       {
    (yyval.groupby) = new GroupBySqlNode();
    (yyvsp[-1].rel_attr_list)->push_front(std::move(*(yyvsp[-2].rel_attr)));
    delete (yyvsp[-2].rel_attr);
    (yyval.groupby)->by_attrs          = std::move(*(yyvsp[-1].rel_attr_list));
    (yyval.groupby)->having_conditions = std::move(*(yyvsp[0].condition_list));
    delete (yyvsp[-1].rel_attr_list);
    delete (yyvsp[0].condition_list);
  }
#line 3323 "yacc_sql.cpp"
    break;

  case 149: /* orderby: %empty  */
#line 1246 "yacc_sql.y"
                    {
		(yyval.orderby_list) = new std::deque<OrderBySqlNode>();
	}
#line 3331 "yacc_sql.cpp"
    break;

  case 150: /* orderby: ORDER BY orderby_col orderby_list  */
#line 1249 "yacc_sql.y"
                                            {
		(yyval.orderby_list) = (yyvsp[0].orderby_list);
		(yyval.orderby_list)->push_front(std::move(*(yyvsp[-1].orderby)));
    delete (yyvsp[-1].orderby);
	}
#line 3341 "yacc_sql.cpp"
    break;

  case 151: /* orderby_list: %empty  */
#line 1257 "yacc_sql.y"
              {
    (yyval.orderby_list) = new std::deque<OrderBySqlNode>();
  }
#line 3349 "yacc_sql.cpp"
    break;

  case 152: /* orderby_list: COMMA orderby_col orderby_list  */
#line 1260 "yacc_sql.y"
                                   {
    (yyval.orderby_list) = (yyvsp[0].orderby_list);
    (yyval.orderby_list)->push_front(std::move(*(yyvsp[-1].orderby)));
    delete (yyvsp[-1].orderby);
  }
#line 3359 "yacc_sql.cpp"
    break;

  case 153: /* orderby_col: rel_attr  */
#line 1268 "yacc_sql.y"
           {
    (yyval.orderby) = new OrderBySqlNode();
    (yyval.orderby)->by_attr = std::unique_ptr<RelAttrSqlNode>((yyvsp[0].rel_attr));
    (yyval.orderby)->is_asc  = true;
  }
#line 3369 "yacc_sql.cpp"
    break;

  case 154: /* orderby_col: rel_attr ASC  */
#line 1273 "yacc_sql.y"
                 {
    (yyval.orderby) = new OrderBySqlNode();
    (yyval.orderby)->by_attr = std::unique_ptr<RelAttrSqlNode>((yyvsp[-1].rel_attr));
    (yyval.orderby)->is_asc  = true;
  }
#line 3379 "yacc_sql.cpp"
    break;

  case 155: /* orderby_col: rel_attr DESC  */
#line 1278 "yacc_sql.y"
                  {
    (yyval.orderby) = new OrderBySqlNode();
    (yyval.orderby)->by_attr = std::unique_ptr<RelAttrSqlNode>((yyvsp[-1].rel_attr));
    (yyval.orderby)->is_asc  = false;
  }
#line 3389 "yacc_sql.cpp"
    break;

  case 156: /* insert_row_list: LBRACE value_list RBRACE  */
#line 1286 "yacc_sql.y"
                           {
    InsertRowNode row;
    row.values = std::move(*(yyvsp[-1].value_list));
    delete (yyvsp[-1].value_list);
    (yyval.insert_row_list) = new std::deque<InsertRowNode>();
    (yyval.insert_row_list)->push_back(std::move(row));
  }
#line 3401 "yacc_sql.cpp"
    break;

  case 157: /* insert_row_list: LBRACE value_list RBRACE COMMA insert_row_list  */
#line 1293 "yacc_sql.y"
                                                   {
    InsertRowNode row;
    row.values = std::move(*(yyvsp[-3].value_list));
    delete (yyvsp[-3].value_list);
    (yyval.insert_row_list) = (yyvsp[0].insert_row_list);
    (yyval.insert_row_list)->push_back(std::move(row));
  }
#line 3413 "yacc_sql.cpp"
    break;

  case 158: /* update_list: SET update_pair  */
#line 1304 "yacc_sql.y"
                {
			(yyval.update_pair_list) = new std::deque<UpdatePairSqlNode>;
      (yyval.update_pair_list)->push_back(std::move(*(yyvsp[0].update_pair)));
      delete (yyvsp[0].update_pair);
		}
#line 3423 "yacc_sql.cpp"
    break;

  case 159: /* update_list: update_list COMMA update_pair  */
#line 1310 "yacc_sql.y"
                {
			(yyval.update_pair_list) = (yyvsp[-2].update_pair_list);
      (yyval.update_pair_list)->push_back(std::move(std::move(*(yyvsp[0].update_pair))));
      delete (yyvsp[0].update_pair);
		}
#line 3433 "yacc_sql.cpp"
    break;

  case 160: /* update_pair: ID EQ value_list_cell  */
#line 1318 "yacc_sql.y"
                              {
		(yyval.update_pair) = new UpdatePairSqlNode();
    (yyval.update_pair)->attr.attribute_name = (yyvsp[-2].string);
		(yyval.update_pair)->is_select = false;
    (yyval.update_pair)->value = std::move(std::move(*(yyvsp[0].value)));
		delete (yyvsp[0].value);
    free((yyvsp[-2].string));
	}
#line 3446 "yacc_sql.cpp"
    break;

  case 161: /* update_pair: ID EQ LBRACE select RBRACE  */
#line 1326 "yacc_sql.y"
                                     {
		(yyval.update_pair) = new UpdatePairSqlNode();
    (yyval.update_pair)->attr.attribute_name = (yyvsp[-4].string);
		(yyval.update_pair)->is_select = true;
    (yyval.update_pair)->select_value = std::move(std::move(*(yyvsp[-1].select)));
		delete (yyvsp[-1].select);
    free((yyvsp[-4].string));
  }
#line 3459 "yacc_sql.cpp"
    break;

  case 162: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1338 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3473 "yacc_sql.cpp"
    break;

  case 163: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1351 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3482 "yacc_sql.cpp"
    break;

  case 164: /* set_variable_stmt: SET ID EQ value  */
#line 1359 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = std::move(std::move(*(yyvsp[0].value)));
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3494 "yacc_sql.cpp"
    break;


#line 3498 "yacc_sql.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1371 "yacc_sql.y"

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
