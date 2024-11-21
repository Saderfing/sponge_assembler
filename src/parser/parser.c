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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 12 "src/parser/parser.y"

#include "parser.h"
#include "../error_handling/error_handling.h"

extern int yylex();

int yydebug = 1;
u32 line = 1;
u32 programAddress = 0;
Inst curInst = NOP;
RegisterCode curReg;

#line 81 "src/parser/parser.c"




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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DATA = 3,                       /* DATA  */
  YYSYMBOL_TEXT = 4,                       /* TEXT  */
  YYSYMBOL_START = 5,                      /* START  */
  YYSYMBOL_BYTE_TYPE = 6,                  /* BYTE_TYPE  */
  YYSYMBOL_HWRD_TYPE = 7,                  /* HWRD_TYPE  */
  YYSYMBOL_WORD_TYPE = 8,                  /* WORD_TYPE  */
  YYSYMBOL_DOUB_TYPE = 9,                  /* DOUB_TYPE  */
  YYSYMBOL_BYTE_DECLARATION = 10,          /* BYTE_DECLARATION  */
  YYSYMBOL_HWORD_DECLARATION = 11,         /* HWORD_DECLARATION  */
  YYSYMBOL_WORD_DECLARATION = 12,          /* WORD_DECLARATION  */
  YYSYMBOL_DOUBLE_DECLARATION = 13,        /* DOUBLE_DECLARATION  */
  YYSYMBOL_AL_COND = 14,                   /* AL_COND  */
  YYSYMBOL_NE_COND = 15,                   /* NE_COND  */
  YYSYMBOL_CS_COND = 16,                   /* CS_COND  */
  YYSYMBOL_CC_COND = 17,                   /* CC_COND  */
  YYSYMBOL_VS_COND = 18,                   /* VS_COND  */
  YYSYMBOL_VC_COND = 19,                   /* VC_COND  */
  YYSYMBOL_HI_COND = 20,                   /* HI_COND  */
  YYSYMBOL_LS_COND = 21,                   /* LS_COND  */
  YYSYMBOL_GE_COND = 22,                   /* GE_COND  */
  YYSYMBOL_LT_COND = 23,                   /* LT_COND  */
  YYSYMBOL_GT_COND = 24,                   /* GT_COND  */
  YYSYMBOL_LE_COND = 25,                   /* LE_COND  */
  YYSYMBOL_EQ_COND = 26,                   /* EQ_COND  */
  YYSYMBOL_INST_MOV = 27,                  /* INST_MOV  */
  YYSYMBOL_INST_MVN = 28,                  /* INST_MVN  */
  YYSYMBOL_INST_AND = 29,                  /* INST_AND  */
  YYSYMBOL_INST_ORR = 30,                  /* INST_ORR  */
  YYSYMBOL_INST_XOR = 31,                  /* INST_XOR  */
  YYSYMBOL_INST_ADD = 32,                  /* INST_ADD  */
  YYSYMBOL_INST_SUB = 33,                  /* INST_SUB  */
  YYSYMBOL_INST_MUL = 34,                  /* INST_MUL  */
  YYSYMBOL_INST_DIV = 35,                  /* INST_DIV  */
  YYSYMBOL_INST_REM = 36,                  /* INST_REM  */
  YYSYMBOL_INST_LSL = 37,                  /* INST_LSL  */
  YYSYMBOL_INST_LSR = 38,                  /* INST_LSR  */
  YYSYMBOL_INST_PSH = 39,                  /* INST_PSH  */
  YYSYMBOL_INST_POP = 40,                  /* INST_POP  */
  YYSYMBOL_INST_LDR = 41,                  /* INST_LDR  */
  YYSYMBOL_INST_STR = 42,                  /* INST_STR  */
  YYSYMBOL_INST_CMP = 43,                  /* INST_CMP  */
  YYSYMBOL_INST_JMP = 44,                  /* INST_JMP  */
  YYSYMBOL_INST_PRR = 45,                  /* INST_PRR  */
  YYSYMBOL_INST_PRM = 46,                  /* INST_PRM  */
  YYSYMBOL_IDENTIFIER = 47,                /* IDENTIFIER  */
  YYSYMBOL_DECLARATION = 48,               /* DECLARATION  */
  YYSYMBOL_IV = 49,                        /* IV  */
  YYSYMBOL_REG0 = 50,                      /* REG0  */
  YYSYMBOL_REG1 = 51,                      /* REG1  */
  YYSYMBOL_REG2 = 52,                      /* REG2  */
  YYSYMBOL_REG3 = 53,                      /* REG3  */
  YYSYMBOL_REG4 = 54,                      /* REG4  */
  YYSYMBOL_REG5 = 55,                      /* REG5  */
  YYSYMBOL_REG6 = 56,                      /* REG6  */
  YYSYMBOL_REG7 = 57,                      /* REG7  */
  YYSYMBOL_REG8 = 58,                      /* REG8  */
  YYSYMBOL_REG9 = 59,                      /* REG9  */
  YYSYMBOL_REG10 = 60,                     /* REG10  */
  YYSYMBOL_REG11 = 61,                     /* REG11  */
  YYSYMBOL_REG12 = 62,                     /* REG12  */
  YYSYMBOL_REG13 = 63,                     /* REG13  */
  YYSYMBOL_REG14 = 64,                     /* REG14  */
  YYSYMBOL_REG15 = 65,                     /* REG15  */
  YYSYMBOL_SEP = 66,                       /* SEP  */
  YYSYMBOL_EL = 67,                        /* EL  */
  YYSYMBOL_END_OF_FILE = 68,               /* END_OF_FILE  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_program = 70,                   /* program  */
  YYSYMBOL_text = 71,                      /* text  */
  YYSYMBOL_start = 72,                     /* start  */
  YYSYMBOL_text_content = 73,              /* text_content  */
  YYSYMBOL_instruction = 74,               /* instruction  */
  YYSYMBOL_load = 75,                      /* load  */
  YYSYMBOL_jump = 76,                      /* jump  */
  YYSYMBOL_una_inst = 77,                  /* una_inst  */
  YYSYMBOL_bin_inst = 78,                  /* bin_inst  */
  YYSYMBOL_ter_inst = 79,                  /* ter_inst  */
  YYSYMBOL_small_iv = 80,                  /* small_iv  */
  YYSYMBOL_large_iv = 81,                  /* large_iv  */
  YYSYMBOL_el = 82,                        /* el  */
  YYSYMBOL_sep = 83,                       /* sep  */
  YYSYMBOL_inst_code_una = 84,             /* inst_code_una  */
  YYSYMBOL_inst_code_bin = 85,             /* inst_code_bin  */
  YYSYMBOL_inst_code_ter = 86,             /* inst_code_ter  */
  YYSYMBOL_datatype = 87,                  /* datatype  */
  YYSYMBOL_condition = 88,                 /* condition  */
  YYSYMBOL_dr = 89,                        /* dr  */
  YYSYMBOL_fr = 90,                        /* fr  */
  YYSYMBOL_sr = 91,                        /* sr  */
  YYSYMBOL_data = 92                       /* data  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    57,    58,    59,    63,    64,    68,    71,
      72,    73,    78,    79,    80,    81,    82,    86,    90,    91,
      92,    96,    97,   101,   102,   106,   107,   111,   115,   119,
     120,   123,   124,   128,   129,   130,   131,   135,   136,   137,
     138,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   154,   155,   156,   157,   158,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   235
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DATA", "TEXT",
  "START", "BYTE_TYPE", "HWRD_TYPE", "WORD_TYPE", "DOUB_TYPE",
  "BYTE_DECLARATION", "HWORD_DECLARATION", "WORD_DECLARATION",
  "DOUBLE_DECLARATION", "AL_COND", "NE_COND", "CS_COND", "CC_COND",
  "VS_COND", "VC_COND", "HI_COND", "LS_COND", "GE_COND", "LT_COND",
  "GT_COND", "LE_COND", "EQ_COND", "INST_MOV", "INST_MVN", "INST_AND",
  "INST_ORR", "INST_XOR", "INST_ADD", "INST_SUB", "INST_MUL", "INST_DIV",
  "INST_REM", "INST_LSL", "INST_LSR", "INST_PSH", "INST_POP", "INST_LDR",
  "INST_STR", "INST_CMP", "INST_JMP", "INST_PRR", "INST_PRM", "IDENTIFIER",
  "DECLARATION", "IV", "REG0", "REG1", "REG2", "REG3", "REG4", "REG5",
  "REG6", "REG7", "REG8", "REG9", "REG10", "REG11", "REG12", "REG13",
  "REG14", "REG15", "SEP", "EL", "END_OF_FILE", "$accept", "program",
  "text", "start", "text_content", "instruction", "load", "jump",
  "una_inst", "bin_inst", "ter_inst", "small_iv", "large_iv", "el", "sep",
  "inst_code_una", "inst_code_bin", "inst_code_ter", "datatype",
  "condition", "dr", "fr", "sr", "data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-10)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,   -49,    -4,     5,    -1,    47,     6,     3,   -40,   -49,
     -49,   -49,   -49,    31,   -49,   -20,     3,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   176,   -49,   -49,   176,   -49,   -49,     2,    -2,
     -49,   -49,   -49,   -49,   -49,   176,   176,   176,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   111,   111,    -2,    -2,     3,   111,   111,   111,
     -49,   -49,   -49,   -49,    31,    31,     3,   -49,   -49,    31,
      31,    31,   108,    23,   -49,    51,   108,   108,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,    31,   -49,   -49,   -49,   -49,   -49,
     -49,    31,    31,   124,    75,   124,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,    31,    92,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   118,     0,     0,     2,     3,     0,    31,     0,     1,
       4,     5,     8,    31,     6,     0,    31,    32,    38,    39,
      42,    47,    50,    41,    49,    46,    43,    48,    44,    45,
      35,    36,    56,    40,    37,    56,    34,    33,     0,    29,
      16,    15,    12,    13,    14,    56,    56,    56,     7,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    51,    51,    29,    29,    31,    51,    51,    51,
      52,    53,    54,    55,    31,    31,    31,    30,    10,    31,
      31,    31,     0,     0,    11,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    31,    20,    28,    19,    18,    22,
      21,    31,    31,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    17,    27,    24,    23,    31,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    26,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,    50,   -49,   -12,    33,   -49,   -49,   -49,   -49,
     -49,   -48,    36,    -5,   -13,   -49,   -49,   -49,   -11,   168,
       7,   -19,   -49,   118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     8,    14,    39,    40,    41,    42,    43,
      44,   134,   107,    66,    15,    45,    46,    47,    74,    62,
     104,   132,   155,     5
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,     6,     1,    -9,    48,     9,    -9,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    16,    38,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     1,
       2,     2,    75,    12,    78,    11,    79,    80,    81,    76,
      77,    82,    83,     7,    84,    65,    85,    86,    87,    13,
     105,    64,   106,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   154,
     108,   113,   110,   111,   112,   135,   136,    13,   114,   115,
     106,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    70,    71,    72,
      73,   109,    10,   137,   133,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   133,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69
};

static const yytype_int16 yycheck[] =
{
      13,     5,     3,     0,    16,     0,     3,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    67,    48,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     3,
       4,     4,    63,    47,    66,     5,    67,    68,    69,    64,
      65,    74,    75,    67,    76,    67,    79,    80,    81,    66,
      47,    38,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   137,
      83,   104,    85,    86,    87,   114,   115,    66,   111,   112,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     6,     7,     8,
       9,    85,     4,   136,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    70,    71,    92,     5,    67,    72,     0,
      92,    71,    47,    66,    73,    83,    67,    83,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    48,    74,
      75,    76,    77,    78,    79,    84,    85,    86,    73,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    88,    88,    74,    67,    82,    88,    88,    88,
       6,     7,     8,     9,    87,    87,    82,    82,    73,    87,
      87,    87,    83,    83,    73,    83,    83,    83,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    89,    47,    49,    81,    89,    81,
      89,    89,    89,    83,    83,    83,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    90,    49,    80,    90,    90,    83,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    80,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    71,    71,    72,    73,
      73,    73,    74,    74,    74,    74,    74,    75,    76,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    81,    82,
      82,    83,    83,    84,    84,    84,    84,    85,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     4,     2,     0,
       4,     5,     1,     1,     1,     1,     1,     7,     5,     5,
       5,     5,     5,     7,     7,     9,     9,     1,     1,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
        yyerror (is, symboleTable, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, is, symboleTable); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, InstStream * is, HashMap * symboleTable)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (is);
  YY_USE (symboleTable);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, InstStream * is, HashMap * symboleTable)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, is, symboleTable);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, InstStream * is, HashMap * symboleTable)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], is, symboleTable);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, is, symboleTable); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, InstStream * is, HashMap * symboleTable)
{
  YY_USE (yyvaluep);
  YY_USE (is);
  YY_USE (symboleTable);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (InstStream * is, HashMap * symboleTable)
{
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
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
  case 6: /* text: TEXT EL text_content  */
#line 63 "src/parser/parser.y"
                                        {line++;}
#line 1298 "src/parser/parser.c"
    break;

  case 7: /* text: TEXT start EL text_content  */
#line 64 "src/parser/parser.y"
                                    {line++;}
#line 1304 "src/parser/parser.c"
    break;

  case 12: /* instruction: una_inst  */
#line 78 "src/parser/parser.y"
                        {appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
#line 1310 "src/parser/parser.c"
    break;

  case 13: /* instruction: bin_inst  */
#line 79 "src/parser/parser.y"
                        {appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
#line 1316 "src/parser/parser.c"
    break;

  case 14: /* instruction: ter_inst  */
#line 80 "src/parser/parser.y"
                        {appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
#line 1322 "src/parser/parser.c"
    break;

  case 15: /* instruction: jump  */
#line 81 "src/parser/parser.y"
                        {appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
#line 1328 "src/parser/parser.c"
    break;

  case 16: /* instruction: load  */
#line 82 "src/parser/parser.y"
                        {appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
#line 1334 "src/parser/parser.c"
    break;

  case 17: /* load: INST_LDR condition datatype sep dr sep fr  */
#line 86 "src/parser/parser.y"
                                                  {curInst = setInstructionCode(curInst, LDR);}
#line 1340 "src/parser/parser.c"
    break;

  case 18: /* jump: INST_JMP condition datatype sep dr  */
#line 90 "src/parser/parser.y"
                                                                        {curInst = setInstructionCode(curInst, JMP);}
#line 1346 "src/parser/parser.c"
    break;

  case 19: /* jump: INST_JMP condition datatype sep large_iv  */
#line 91 "src/parser/parser.y"
                                                                {curInst = setInstructionCode(curInst, JMP);}
#line 1352 "src/parser/parser.c"
    break;

  case 20: /* jump: INST_JMP condition datatype sep IDENTIFIER  */
#line 92 "src/parser/parser.y"
                                                                {curInst = setInstructionCode(curInst, JMP);}
#line 1358 "src/parser/parser.c"
    break;

  case 27: /* small_iv: IV  */
#line 111 "src/parser/parser.y"
                                {curInst = setAsImmediate(curInst, true); curInst = setSmallIV(curInst, (yyvsp[0].iv));}
#line 1364 "src/parser/parser.c"
    break;

  case 28: /* large_iv: IV  */
#line 115 "src/parser/parser.y"
                                {curInst = setAsImmediate(curInst, true); curInst = setLargeIV(curInst, (yyvsp[0].iv));}
#line 1370 "src/parser/parser.c"
    break;

  case 30: /* el: EL el  */
#line 120 "src/parser/parser.y"
                                        {line++;}
#line 1376 "src/parser/parser.c"
    break;

  case 33: /* inst_code_una: INST_PRM  */
#line 128 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, PRM);}
#line 1382 "src/parser/parser.c"
    break;

  case 34: /* inst_code_una: INST_PRR  */
#line 129 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, PRR);}
#line 1388 "src/parser/parser.c"
    break;

  case 35: /* inst_code_una: INST_PSH  */
#line 130 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, PSH);}
#line 1394 "src/parser/parser.c"
    break;

  case 36: /* inst_code_una: INST_POP  */
#line 131 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, POP);}
#line 1400 "src/parser/parser.c"
    break;

  case 37: /* inst_code_bin: INST_CMP  */
#line 135 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, CMP);}
#line 1406 "src/parser/parser.c"
    break;

  case 38: /* inst_code_bin: INST_MOV  */
#line 136 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, MOV);}
#line 1412 "src/parser/parser.c"
    break;

  case 39: /* inst_code_bin: INST_MVN  */
#line 137 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, MVN);}
#line 1418 "src/parser/parser.c"
    break;

  case 40: /* inst_code_bin: INST_STR  */
#line 138 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, STR);}
#line 1424 "src/parser/parser.c"
    break;

  case 41: /* inst_code_ter: INST_ADD  */
#line 142 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, ADD);}
#line 1430 "src/parser/parser.c"
    break;

  case 42: /* inst_code_ter: INST_AND  */
#line 143 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, AND);}
#line 1436 "src/parser/parser.c"
    break;

  case 43: /* inst_code_ter: INST_DIV  */
#line 144 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, DIV);}
#line 1442 "src/parser/parser.c"
    break;

  case 44: /* inst_code_ter: INST_LSL  */
#line 145 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, LSL);}
#line 1448 "src/parser/parser.c"
    break;

  case 45: /* inst_code_ter: INST_LSR  */
#line 146 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, LSR);}
#line 1454 "src/parser/parser.c"
    break;

  case 46: /* inst_code_ter: INST_MUL  */
#line 147 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, MUL);}
#line 1460 "src/parser/parser.c"
    break;

  case 47: /* inst_code_ter: INST_ORR  */
#line 148 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, ORR);}
#line 1466 "src/parser/parser.c"
    break;

  case 48: /* inst_code_ter: INST_REM  */
#line 149 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, REM);}
#line 1472 "src/parser/parser.c"
    break;

  case 49: /* inst_code_ter: INST_SUB  */
#line 150 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, SUB);}
#line 1478 "src/parser/parser.c"
    break;

  case 50: /* inst_code_ter: INST_XOR  */
#line 151 "src/parser/parser.y"
                                {curInst = setInstructionCode(curInst, XOR);}
#line 1484 "src/parser/parser.c"
    break;

  case 51: /* datatype: %empty  */
#line 154 "src/parser/parser.y"
                                        {curInst = setTypeCode(curInst, W);}
#line 1490 "src/parser/parser.c"
    break;

  case 52: /* datatype: BYTE_TYPE  */
#line 155 "src/parser/parser.y"
                                        {curInst = setTypeCode(curInst, B);}
#line 1496 "src/parser/parser.c"
    break;

  case 53: /* datatype: HWRD_TYPE  */
#line 156 "src/parser/parser.y"
                                        {curInst = setTypeCode(curInst, H);}
#line 1502 "src/parser/parser.c"
    break;

  case 54: /* datatype: WORD_TYPE  */
#line 157 "src/parser/parser.y"
                                        {curInst = setTypeCode(curInst, W);}
#line 1508 "src/parser/parser.c"
    break;

  case 55: /* datatype: DOUB_TYPE  */
#line 158 "src/parser/parser.y"
                                        {curInst = setTypeCode(curInst, D);}
#line 1514 "src/parser/parser.c"
    break;

  case 56: /* condition: %empty  */
#line 161 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, AL);}
#line 1520 "src/parser/parser.c"
    break;

  case 57: /* condition: AL_COND  */
#line 162 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, AL);}
#line 1526 "src/parser/parser.c"
    break;

  case 58: /* condition: NE_COND  */
#line 163 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, NE);}
#line 1532 "src/parser/parser.c"
    break;

  case 59: /* condition: CS_COND  */
#line 164 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, CS);}
#line 1538 "src/parser/parser.c"
    break;

  case 60: /* condition: CC_COND  */
#line 165 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, CC);}
#line 1544 "src/parser/parser.c"
    break;

  case 61: /* condition: VS_COND  */
#line 166 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, VS);}
#line 1550 "src/parser/parser.c"
    break;

  case 62: /* condition: VC_COND  */
#line 167 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, VC);}
#line 1556 "src/parser/parser.c"
    break;

  case 63: /* condition: HI_COND  */
#line 168 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, HI);}
#line 1562 "src/parser/parser.c"
    break;

  case 64: /* condition: LS_COND  */
#line 169 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, LS);}
#line 1568 "src/parser/parser.c"
    break;

  case 65: /* condition: GE_COND  */
#line 170 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, GE);}
#line 1574 "src/parser/parser.c"
    break;

  case 66: /* condition: LT_COND  */
#line 171 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, LT);}
#line 1580 "src/parser/parser.c"
    break;

  case 67: /* condition: GT_COND  */
#line 172 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, GT);}
#line 1586 "src/parser/parser.c"
    break;

  case 68: /* condition: LE_COND  */
#line 173 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, LE);}
#line 1592 "src/parser/parser.c"
    break;

  case 69: /* condition: EQ_COND  */
#line 174 "src/parser/parser.y"
                                        {curInst = setConditionCode(curInst, EQ);}
#line 1598 "src/parser/parser.c"
    break;

  case 70: /* dr: REG0  */
#line 178 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R0);}
#line 1604 "src/parser/parser.c"
    break;

  case 71: /* dr: REG1  */
#line 179 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R1);}
#line 1610 "src/parser/parser.c"
    break;

  case 72: /* dr: REG2  */
#line 180 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R2);}
#line 1616 "src/parser/parser.c"
    break;

  case 73: /* dr: REG3  */
#line 181 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R3);}
#line 1622 "src/parser/parser.c"
    break;

  case 74: /* dr: REG4  */
#line 182 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R4);}
#line 1628 "src/parser/parser.c"
    break;

  case 75: /* dr: REG5  */
#line 183 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R5);}
#line 1634 "src/parser/parser.c"
    break;

  case 76: /* dr: REG6  */
#line 184 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R6);}
#line 1640 "src/parser/parser.c"
    break;

  case 77: /* dr: REG7  */
#line 185 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R7);}
#line 1646 "src/parser/parser.c"
    break;

  case 78: /* dr: REG8  */
#line 186 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R8);}
#line 1652 "src/parser/parser.c"
    break;

  case 79: /* dr: REG9  */
#line 187 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R9);}
#line 1658 "src/parser/parser.c"
    break;

  case 80: /* dr: REG10  */
#line 188 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R10);}
#line 1664 "src/parser/parser.c"
    break;

  case 81: /* dr: REG11  */
#line 189 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R11);}
#line 1670 "src/parser/parser.c"
    break;

  case 82: /* dr: REG12  */
#line 190 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R12);}
#line 1676 "src/parser/parser.c"
    break;

  case 83: /* dr: REG13  */
#line 191 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R13);}
#line 1682 "src/parser/parser.c"
    break;

  case 84: /* dr: REG14  */
#line 192 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R14);}
#line 1688 "src/parser/parser.c"
    break;

  case 85: /* dr: REG15  */
#line 193 "src/parser/parser.y"
                                        {curInst = setDestRegister(curInst, R15);}
#line 1694 "src/parser/parser.c"
    break;

  case 86: /* fr: REG0  */
#line 197 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R0);}
#line 1700 "src/parser/parser.c"
    break;

  case 87: /* fr: REG1  */
#line 198 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R1);}
#line 1706 "src/parser/parser.c"
    break;

  case 88: /* fr: REG2  */
#line 199 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R2);}
#line 1712 "src/parser/parser.c"
    break;

  case 89: /* fr: REG3  */
#line 200 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R3);}
#line 1718 "src/parser/parser.c"
    break;

  case 90: /* fr: REG4  */
#line 201 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R4);}
#line 1724 "src/parser/parser.c"
    break;

  case 91: /* fr: REG5  */
#line 202 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R5);}
#line 1730 "src/parser/parser.c"
    break;

  case 92: /* fr: REG6  */
#line 203 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R6);}
#line 1736 "src/parser/parser.c"
    break;

  case 93: /* fr: REG7  */
#line 204 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R7);}
#line 1742 "src/parser/parser.c"
    break;

  case 94: /* fr: REG8  */
#line 205 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R8);}
#line 1748 "src/parser/parser.c"
    break;

  case 95: /* fr: REG9  */
#line 206 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R9);}
#line 1754 "src/parser/parser.c"
    break;

  case 96: /* fr: REG10  */
#line 207 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R10);}
#line 1760 "src/parser/parser.c"
    break;

  case 97: /* fr: REG11  */
#line 208 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R11);}
#line 1766 "src/parser/parser.c"
    break;

  case 98: /* fr: REG12  */
#line 209 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R12);}
#line 1772 "src/parser/parser.c"
    break;

  case 99: /* fr: REG13  */
#line 210 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R13);}
#line 1778 "src/parser/parser.c"
    break;

  case 100: /* fr: REG14  */
#line 211 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R14);}
#line 1784 "src/parser/parser.c"
    break;

  case 101: /* fr: REG15  */
#line 212 "src/parser/parser.y"
                                        {curInst = setFirstRegister(curInst, R15);}
#line 1790 "src/parser/parser.c"
    break;

  case 102: /* sr: REG0  */
#line 216 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R0);}
#line 1796 "src/parser/parser.c"
    break;

  case 103: /* sr: REG1  */
#line 217 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R1);}
#line 1802 "src/parser/parser.c"
    break;

  case 104: /* sr: REG2  */
#line 218 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R2);}
#line 1808 "src/parser/parser.c"
    break;

  case 105: /* sr: REG3  */
#line 219 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R3);}
#line 1814 "src/parser/parser.c"
    break;

  case 106: /* sr: REG4  */
#line 220 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R4);}
#line 1820 "src/parser/parser.c"
    break;

  case 107: /* sr: REG5  */
#line 221 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R5);}
#line 1826 "src/parser/parser.c"
    break;

  case 108: /* sr: REG6  */
#line 222 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R6);}
#line 1832 "src/parser/parser.c"
    break;

  case 109: /* sr: REG7  */
#line 223 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R7);}
#line 1838 "src/parser/parser.c"
    break;

  case 110: /* sr: REG8  */
#line 224 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R8);}
#line 1844 "src/parser/parser.c"
    break;

  case 111: /* sr: REG9  */
#line 225 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R9);}
#line 1850 "src/parser/parser.c"
    break;

  case 112: /* sr: REG10  */
#line 226 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R10);}
#line 1856 "src/parser/parser.c"
    break;

  case 113: /* sr: REG11  */
#line 227 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R11);}
#line 1862 "src/parser/parser.c"
    break;

  case 114: /* sr: REG12  */
#line 228 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R12);}
#line 1868 "src/parser/parser.c"
    break;

  case 115: /* sr: REG13  */
#line 229 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R13);}
#line 1874 "src/parser/parser.c"
    break;

  case 116: /* sr: REG14  */
#line 230 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R14);}
#line 1880 "src/parser/parser.c"
    break;

  case 117: /* sr: REG15  */
#line 231 "src/parser/parser.y"
                                        {curInst = setSecondRegister(curInst, R15);}
#line 1886 "src/parser/parser.c"
    break;

  case 118: /* data: DATA  */
#line 235 "src/parser/parser.y"
                                                {printf("data");}
#line 1892 "src/parser/parser.c"
    break;


#line 1896 "src/parser/parser.c"

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
      yyerror (is, symboleTable, YY_("syntax error"));
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
                      yytoken, &yylval, is, symboleTable);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, is, symboleTable);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (is, symboleTable, YY_("memory exhausted"));
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
                  yytoken, &yylval, is, symboleTable);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, is, symboleTable);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 240 "src/parser/parser.y"


int yyerror(InstStream *is, HashMap *symboleTable, const char *s){
	resetInstStream(is);
	printf("Line : %d | Instruction : %d\n", line, programAddress);

	return 0;
}

int yywarp(){
	return 1;
}
