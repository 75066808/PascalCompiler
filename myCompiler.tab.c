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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "myCompiler.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>
	#include "mySyntaxTree.hpp"
	int yylex(void);
	void yyerror(char *);
	extern int yylineno;
	Node *root;

#line 76 "myCompiler.tab.c" /* yacc.c:339  */

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
    GE = 258,
    GT = 259,
    LE = 260,
    LT = 261,
    EQUAL = 262,
    UNEQUAL = 263,
    PLUS = 264,
    MINUS = 265,
    OR = 266,
    MUL = 267,
    DIV = 268,
    MOD = 269,
    AND = 270,
    NOT = 271,
    ASSIGN = 272,
    ID = 273,
    LP = 274,
    RP = 275,
    DOT = 276,
    COMMA = 277,
    LB = 278,
    RB = 279,
    SEMI = 280,
    COLON = 281,
    SYS_TYPE = 282,
    INTEGER = 283,
    CHAR = 284,
    BOOLEAN = 285,
    REAL = 286,
    STRING = 287,
    NAME = 288,
    SYS_FUNCT = 289,
    SYS_PROC = 290,
    TYPE_INTEGER = 291,
    TYPE_REAL = 292,
    TYPE_CHAR = 293,
    TYPE_BOOLEAN = 294,
    TYPE_STRING = 295,
    READ = 296,
    IF = 297,
    THEN = 298,
    ELSE = 299,
    REPEAT = 300,
    UNTIL = 301,
    WHILE = 302,
    DO = 303,
    FOR = 304,
    TO = 305,
    DOWNTO = 306,
    CASE = 307,
    OF = 308,
    GOTO = 309,
    BEGINNING = 310,
    END = 311,
    PROGRAM = 312,
    CONST = 313,
    TYPE = 314,
    ARRAY = 315,
    RECORD = 316,
    VAR = 317,
    FUNCTION = 318,
    PROCEDURE = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "myCompiler.y" /* yacc.c:355  */

	int intNum;
	float floatNum;
	char strValue[256];
	Node *node;

#line 185 "myCompiler.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 202 "myCompiler.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    45,    48,    59,    68,    78,    81,    82,
      85,    89,    92,    93,    96,    97,   100,   105,   106,   107,
     110,   111,   112,   113,   114,   120,   128,   136,   137,   138,
     139,   140,   143,   146,   151,   152,   155,   158,   162,   165,
     166,   169,   170,   173,   176,   177,   178,   179,   180,   183,
     189,   192,   198,   201,   202,   205,   206,   209,   210,   213,
     216,   219,   222,   223,   226,   227,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   241,   244,   249,   254,   262,
     266,   271,   276,   282,   290,   299,   300,   303,   311,   319,
     330,   331,   334,   342,   343,   346,   351,   359,   365,   366,
     369,   374,   379,   384,   389,   394,   399,   402,   407,   412,
     417,   420,   425,   430,   435,   440,   443,   444,   445,   446,
     450,   451,   455,   459,   460,   461,   467,   468,   471,   475,
     479,   483,   487
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GE", "GT", "LE", "LT", "EQUAL",
  "UNEQUAL", "PLUS", "MINUS", "OR", "MUL", "DIV", "MOD", "AND", "NOT",
  "ASSIGN", "ID", "LP", "RP", "DOT", "COMMA", "LB", "RB", "SEMI", "COLON",
  "SYS_TYPE", "INTEGER", "CHAR", "BOOLEAN", "REAL", "STRING", "NAME",
  "SYS_FUNCT", "SYS_PROC", "TYPE_INTEGER", "TYPE_REAL", "TYPE_CHAR",
  "TYPE_BOOLEAN", "TYPE_STRING", "READ", "IF", "THEN", "ELSE", "REPEAT",
  "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO", "CASE", "OF", "GOTO",
  "BEGINNING", "END", "PROGRAM", "CONST", "TYPE", "ARRAY", "RECORD", "VAR",
  "FUNCTION", "PROCEDURE", "$accept", "program", "program_head", "routine",
  "routine_head", "sub_routine", "label_part", "const_part",
  "const_expr_list", "type_part", "type_decl_list", "type_definition",
  "type_decl", "simple_type_decl", "sys_type", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "stmt_list", "stmt", "non_label_stmt", "compound_stmt",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", "const_value", YY_NULLPTR
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
     315,   316,   317,   318,   319
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
     -40,   -15,    32,  -187,     8,  -187,    53,    11,    18,  -187,
    -187,  -187,  -187,  -187,    42,    23,    71,    80,    68,    81,
      55,    95,   171,   103,   118,   236,  -187,   236,   105,   236,
     114,  -187,   121,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,   195,   146,   154,    81,  -187,   134,   -57,
     238,   236,   236,   135,   236,   236,   236,   236,   236,   236,
    -187,  -187,  -187,  -187,  -187,    69,   156,    54,    31,   304,
    -187,  -187,   187,    41,   159,    16,  -187,  -187,   157,   195,
     126,  -187,  -187,    72,   134,  -187,   150,   162,   -57,  -187,
     164,  -187,   173,  -187,   303,   303,    73,   184,   291,   127,
     303,   189,  -187,  -187,   255,   236,   180,   236,   236,   236,
     236,   236,   236,   236,   236,   202,   236,   236,   236,   236,
     236,   236,   236,   236,   202,   236,   294,  -187,   194,   195,
     134,   196,  -187,  -187,  -187,  -187,  -187,   198,   134,   213,
    -187,  -187,  -187,  -187,   224,   207,   126,  -187,   229,   229,
    -187,  -187,  -187,  -187,  -187,   236,   236,   233,  -187,   236,
    -187,  -187,   130,  -187,   297,   177,    31,    31,    31,    31,
      31,    31,   209,   304,   304,   304,  -187,  -187,  -187,  -187,
     303,  -187,    22,   246,   175,  -187,   248,  -187,   256,   192,
     257,   141,   -25,  -187,    89,  -187,   260,  -187,   251,     1,
     258,  -187,    11,   261,   263,   303,   303,   236,   303,  -187,
    -187,  -187,   202,  -187,  -187,  -187,   236,   202,  -187,  -187,
     202,   268,  -187,   249,   267,  -187,  -187,   126,   195,  -187,
     134,   290,    45,  -187,   287,   288,   141,  -187,  -187,  -187,
     303,  -187,    48,   295,   309,   100,  -187,   282,   311,  -187,
     290,  -187,     1,   141,   141,  -187,   202,  -187,  -187,   195,
    -187,   126,  -187,  -187,  -187,  -187,  -187,  -187,  -187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     9,     3,
       2,    63,     4,    61,     0,    13,     0,     0,     8,     0,
      40,     0,    79,    81,     0,     0,    63,     0,     0,     0,
       0,    75,     0,    65,    74,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,     0,    12,    15,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   130,   132,   129,   131,   116,   118,     0,   106,   110,
     115,   120,     0,     0,     0,     0,    97,    62,     0,     0,
       0,    14,    38,     0,    39,    42,     0,     0,     5,    46,
       0,    47,     0,    64,    76,   127,     0,     0,     0,     0,
      99,     0,   122,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,    21,    27,    28,    30,    29,    31,     0,     0,     0,
      17,    20,    18,    19,     0,     0,     0,    41,    54,    54,
      44,    45,     7,     7,    80,     0,     0,     0,    82,     0,
      83,   123,     0,   125,     0,     0,   100,   101,   102,   103,
     104,   105,    86,   107,   108,   109,   111,   112,   113,   114,
      87,    88,     0,     0,     0,    94,     0,    10,     0,     0,
       0,     0,     0,    35,     0,    16,     0,    37,     0,     0,
       0,    52,     0,     0,     0,   126,    78,     0,    98,   117,
     124,   119,     0,    84,    90,    91,     0,     0,    92,    93,
       0,     0,    22,     0,     0,    33,    34,     0,     0,    43,
       0,    60,     0,    56,     0,     0,     0,     6,    49,    51,
      77,    85,     0,     0,     0,     0,    26,     0,     0,    23,
      59,    53,     0,     0,     0,    50,     0,    96,    95,     0,
      24,     0,    36,    55,    57,    58,    89,    25,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -187,   334,   185,  -187,  -187,  -187,  -187,
    -187,   293,  -142,  -186,  -187,  -187,  -187,  -187,   148,  -128,
    -187,  -187,   259,  -187,   253,  -187,   254,  -187,   197,  -187,
      92,  -187,  -187,   143,   321,  -112,   298,    -6,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,   165,  -187,
    -187,   -16,   219,    17,   -42,   -24,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   202,   203,     8,    15,    18,    20,
      46,    47,   139,   140,   141,   142,   143,   192,   193,    83,
      49,    84,    85,    88,    89,    90,    91,    92,   200,   232,
     233,   234,   235,    12,    16,    32,    33,    34,    35,    36,
      37,   213,    38,    39,    40,   216,    41,   184,   185,    42,
      99,    95,    68,    69,    70,    96,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      78,    13,   189,   172,   198,   224,    86,    87,    82,    67,
     194,    73,   181,    75,   101,   102,   103,     1,     4,   109,
     110,   111,   112,   113,   114,   109,   110,   111,   112,   113,
     114,   225,     5,     9,    82,    94,   128,   144,    98,   100,
     116,   117,   118,   104,   109,   110,   111,   112,   113,   114,
     255,   109,   110,   111,   112,   113,   114,   109,   110,   111,
     112,   113,   114,   230,   194,   251,    11,   264,   265,   126,
     252,   231,   214,   215,    10,    17,    14,   176,   177,   178,
     179,   162,    19,   186,   165,   248,   188,    43,   105,   124,
     106,   164,   107,   154,   145,   155,   256,   115,   146,    21,
     241,    44,   250,   144,    22,   243,    23,   180,   244,   182,
     259,   145,    24,    25,    45,   227,    26,    48,    27,   268,
      28,    50,    55,    29,   231,    30,    11,    31,    60,    61,
      62,    63,    64,   173,   174,   175,   129,    56,    74,   205,
     206,   186,    76,   208,   266,   130,    77,   158,   144,   159,
     209,   129,   155,    79,    60,    61,    62,    63,    64,   131,
     130,    80,   132,   133,   134,   135,   136,    82,    97,    60,
      61,    62,    63,    64,   131,   108,   125,   132,   133,   134,
     135,   136,   127,   148,   144,   249,   137,   138,    51,   152,
      52,   240,    53,   144,    54,   149,    13,   211,   153,   155,
     242,   156,   260,    60,    61,    62,    63,    64,   183,   160,
     144,   144,   222,   163,   145,    21,   267,   190,   144,   187,
      22,   191,    23,    60,    61,    62,    63,    64,    24,    25,
      21,   218,    26,   123,    27,    22,    28,    23,   195,    29,
     197,    30,    11,    24,    25,   196,    57,    26,   199,    27,
     207,    28,    58,   212,    29,    59,    30,    11,   109,   110,
     111,   112,   113,   114,    60,    61,    62,    63,    64,    65,
      66,    22,   217,    23,   220,   161,   229,   221,   223,    24,
      25,   228,   246,    26,   236,    27,   238,    28,   239,   245,
      29,   247,    30,    11,   109,   110,   111,   112,   113,   114,
     109,   110,   111,   112,   113,   114,   109,   110,   111,   112,
     113,   114,   145,   253,   254,   157,   119,   120,   121,   122,
     257,   210,    60,    61,    62,    63,    64,   183,   166,   167,
     168,   169,   170,   171,   258,   261,   262,     7,   204,    81,
     226,   150,   151,   147,   263,   237,   201,    72,    93,   219
};

static const yytype_uint16 yycheck[] =
{
      43,     7,   130,   115,   146,   191,    63,    64,    33,    25,
     138,    27,   124,    29,    56,    57,    58,    57,    33,     3,
       4,     5,     6,     7,     8,     3,     4,     5,     6,     7,
       8,    56,     0,    25,    33,    51,    79,    80,    54,    55,
       9,    10,    11,    59,     3,     4,     5,     6,     7,     8,
     236,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    62,   192,    20,    55,   253,   254,    53,
      25,   199,    50,    51,    21,    33,    58,   119,   120,   121,
     122,   105,    59,   126,   108,   227,   129,     7,    19,    48,
      21,   107,    23,    20,    22,    22,    48,    43,    26,    28,
     212,    33,   230,   146,    33,   217,    35,   123,   220,   125,
      10,    22,    41,    42,    33,    26,    45,    62,    47,   261,
      49,    26,    19,    52,   252,    54,    55,    56,    28,    29,
      30,    31,    32,   116,   117,   118,    10,    19,    33,   155,
     156,   184,    28,   159,   256,    19,    25,    20,   191,    22,
      20,    10,    22,     7,    28,    29,    30,    31,    32,    33,
      19,     7,    36,    37,    38,    39,    40,    33,    33,    28,
      29,    30,    31,    32,    33,    19,    17,    36,    37,    38,
      39,    40,    25,    33,   227,   228,    60,    61,    17,    25,
      19,   207,    21,   236,    23,    33,   202,    20,    25,    22,
     216,    17,   245,    28,    29,    30,    31,    32,    33,    20,
     253,   254,    20,    33,    22,    28,   259,    21,   261,    25,
      33,    23,    35,    28,    29,    30,    31,    32,    41,    42,
      28,    56,    45,    46,    47,    33,    49,    35,    25,    52,
      33,    54,    55,    41,    42,    21,    10,    45,    19,    47,
      17,    49,    16,    44,    52,    19,    54,    55,     3,     4,
       5,     6,     7,     8,    28,    29,    30,    31,    32,    33,
      34,    33,    26,    35,    26,    20,    25,    21,    21,    41,
      42,    21,    33,    45,    26,    47,    25,    49,    25,    21,
      52,    24,    54,    55,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,    22,    26,    26,    24,    12,    13,    14,    15,
      25,    24,    28,    29,    30,    31,    32,    33,   109,   110,
     111,   112,   113,   114,    25,    53,    25,     3,   153,    46,
     192,    88,    88,    84,   252,   202,   149,    26,    50,   184
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    66,    67,    33,     0,    68,    69,    71,    25,
      21,    55,    98,   102,    58,    72,    99,    33,    73,    59,
      74,    28,    33,    35,    41,    42,    45,    47,    49,    52,
      54,    56,   100,   101,   102,   103,   104,   105,   107,   108,
     109,   111,   114,     7,    33,    33,    75,    76,    62,    85,
      26,    17,    19,    21,    23,    19,    19,    10,    16,    19,
      28,    29,    30,    31,    32,    33,    34,   116,   117,   118,
     119,   121,    99,   116,    33,   116,    28,    25,   121,     7,
       7,    76,    33,    84,    86,    87,    63,    64,    88,    89,
      90,    91,    92,   101,   116,   116,   120,    33,   116,   115,
     116,   119,   119,   119,   116,    19,    21,    23,    19,     3,
       4,     5,     6,     7,     8,    43,     9,    10,    11,    12,
      13,    14,    15,    46,    48,    17,    53,    25,   121,    10,
      19,    33,    36,    37,    38,    39,    40,    60,    61,    77,
      78,    79,    80,    81,   121,    22,    26,    87,    33,    33,
      89,    91,    25,    25,    20,    22,    17,    24,    20,    22,
      20,    20,   120,    33,   116,   120,   117,   117,   117,   117,
     117,   117,   100,   118,   118,   118,   119,   119,   119,   119,
     116,   100,   116,    33,   112,   113,   121,    25,   121,    84,
      21,    23,    82,    83,    84,    25,    21,    33,    77,    19,
      93,    93,    69,    70,    70,   116,   116,    17,   116,    20,
      24,    20,    44,   106,    50,    51,   110,    26,    56,   113,
      26,    21,    20,    21,    78,    56,    83,    26,    21,    25,
      62,    84,    94,    95,    96,    97,    26,    98,    25,    25,
     116,   100,   116,   100,   100,    21,    33,    24,    77,   121,
      84,    20,    25,    26,    26,    78,    48,    25,    25,    10,
     121,    53,    25,    95,    78,    78,   100,   121,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    68,    69,    70,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    80,    81,    82,    82,    83,    84,    84,    85,
      85,    86,    86,    87,    88,    88,    88,    88,    88,    89,
      90,    91,    92,    93,    93,    94,    94,    95,    95,    96,
      97,    98,    99,    99,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   103,   103,   103,   104,
     104,   104,   104,   104,   105,   106,   106,   107,   108,   109,
     110,   110,   111,   112,   112,   113,   113,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   118,   118,   118,   118,   118,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   120,   120,   121,   121,
     121,   121,   121
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     5,     2,     0,     2,     0,
       5,     4,     2,     0,     2,     1,     4,     1,     1,     1,
       1,     1,     3,     4,     5,     6,     4,     1,     1,     1,
       1,     1,     6,     3,     2,     1,     4,     3,     1,     2,
       0,     2,     1,     4,     2,     2,     1,     1,     0,     4,
       5,     4,     3,     3,     0,     3,     1,     3,     3,     2,
       1,     1,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     6,     5,     1,
       4,     1,     4,     4,     5,     2,     0,     4,     4,     8,
       1,     1,     5,     2,     1,     4,     4,     2,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     1,     4,     1,     4,
       1,     2,     2,     3,     4,     3,     3,     1,     1,     1,
       1,     1,     1
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
        case 2:
#line 38 "myCompiler.y" /* yacc.c:1646  */
    { 
		root = newSubHead(PROC, (yyvsp[-2].node)->name, NULL, NULL); 
		addChild(root, (yyvsp[-1].node)); 
        lineTrans(root, (yyvsp[-2].node));
	}
#line 1497 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 45 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newIdenExp(BASIC_ID, (yyvsp[-1].strValue), NULL); }
#line 1503 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 48 "myCompiler.y" /* yacc.c:1646  */
    { 
        (yyval.node) = newRoutine((yyvsp[-1].node), (yyvsp[0].node)); 
        if((yyvsp[-1].node) != NULL){
            lineTrans((yyval.node), (yyvsp[-1].node));
        }
        else if((yyvsp[0].node) != NULL){
            lineTrans((yyval.node), (yyvsp[0].node));
        }
    }
#line 1517 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "myCompiler.y" /* yacc.c:1646  */
    { 
        Node *tmp;
        tmp = addSibling((yyvsp[-1].node), (yyvsp[0].node));
        tmp = addSibling((yyvsp[-2].node), tmp);
        tmp =  addSibling((yyvsp[-3].node), tmp);
        (yyval.node) = addSibling((yyvsp[-4].node), tmp); 
    }
#line 1529 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 68 "myCompiler.y" /* yacc.c:1646  */
    { 
        (yyval.node) = newRoutine((yyvsp[-1].node), (yyvsp[0].node)); 
        if((yyvsp[-1].node) != NULL){
            lineTrans((yyval.node), (yyvsp[-1].node));
        }
        else if((yyvsp[0].node) != NULL){
            lineTrans((yyval.node), (yyvsp[0].node));
        }
    }
#line 1543 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 78 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1549 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1555 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1561 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 85 "myCompiler.y" /* yacc.c:1646  */
    { 
        Node *tmp = newConst((yyvsp[-3].strValue), (yyvsp[-1].node));
        (yyval.node) = addSibling((yyvsp[-4].node), tmp); 
    }
#line 1570 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newConst((yyvsp[-3].strValue), (yyvsp[-1].node)); }
#line 1576 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 92 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1582 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1588 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 96 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1594 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 97 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1600 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 100 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newTypeDef((yyvsp[-3].strValue), (yyvsp[-1].node)); 
	}
#line 1608 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 105 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1614 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 106 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1620 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 107 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1626 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 110 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1632 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newSelfDefineType((yyvsp[0].strValue)); }
#line 1638 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 112 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newType(ENUME, (yyvsp[-1].node), NULL); }
#line 1644 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 113 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newType(ENUME, (yyvsp[-3].node), (yyvsp[0].node)); }
#line 1650 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 114 "myCompiler.y" /* yacc.c:1646  */
    { 
		Node *p;
		p = newOpExp(NEG_OP); 
        addChild(p, (yyvsp[-3].node));
		(yyval.node) = newType(ENUME, p, (yyvsp[0].node)); 
	}
#line 1661 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 120 "myCompiler.y" /* yacc.c:1646  */
    { 
		Node *p, *q;
		p = newOpExp(NEG_OP); 
        addChild(p, (yyvsp[-4].node));
		q = newOpExp(NEG_OP); 
        addChild(q, (yyvsp[0].node));
		(yyval.node) = newType(ENUME, p, q); 
	}
#line 1674 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 128 "myCompiler.y" /* yacc.c:1646  */
    { 
        Node *p, *q;
        p = newIdenExp(BASIC_ID, (yyvsp[-3].strValue), NULL);
        q = newIdenExp(BASIC_ID, (yyvsp[0].strValue), NULL);
        (yyval.node) = newType(ENUME, p, q); 
    }
#line 1685 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 136 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newType(INTEGE, NULL, NULL); }
#line 1691 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 137 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newType(REA, NULL, NULL); }
#line 1697 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 138 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newType(BOOLEA, NULL, NULL); }
#line 1703 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 139 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newType(CHARA, NULL, NULL); }
#line 1709 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 140 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newType(STR, NULL, NULL); }
#line 1715 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 143 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newType(ARRA, (yyvsp[-3].node), (yyvsp[0].node)); }
#line 1721 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 146 "myCompiler.y" /* yacc.c:1646  */
    { 
        (yyval.node) = newType(RECOR, (yyvsp[-1].node), NULL); 
    }
#line 1729 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 151 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1735 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 152 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1741 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 155 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newVar((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1747 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 158 "myCompiler.y" /* yacc.c:1646  */
    { 
        Node *p = newIdenExp(BASIC_ID, (yyvsp[0].strValue), NULL);
        (yyval.node) = addSibling((yyvsp[-2].node), p); 
    }
#line 1756 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 162 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newIdenExp(BASIC_ID, (yyvsp[0].strValue), NULL); }
#line 1762 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 165 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1768 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 166 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1774 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 169 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1780 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 170 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1786 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 173 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newVar((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1792 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 176 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1798 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 177 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1804 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 178 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1810 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 179 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1816 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 180 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1822 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 183 "myCompiler.y" /* yacc.c:1646  */
    { 
        addChild((yyvsp[-3].node), (yyvsp[-1].node));
        (yyval.node) = (yyvsp[-3].node);
    }
#line 1831 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 189 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newSubHead(FUNC, (yyvsp[-3].strValue), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1837 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 192 "myCompiler.y" /* yacc.c:1646  */
    { 
        addChild((yyvsp[-3].node), (yyvsp[-1].node));
        (yyval.node) = (yyvsp[-3].node);
    }
#line 1846 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 198 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newSubHead(PROC, (yyvsp[-1].strValue), (yyvsp[0].node), NULL); }
#line 1852 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 201 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1858 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 202 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1864 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 205 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1870 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 206 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1876 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 209 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newParam((yyvsp[-2].node), (yyvsp[0].node), PARAM_VAR); }
#line 1882 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 210 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newParam((yyvsp[-2].node), (yyvsp[0].node), PARAM_VAL); }
#line 1888 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 213 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1894 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 216 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1900 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 219 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1906 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 222 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1912 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 223 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1918 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 226 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = makeLabel((yyvsp[0].node), (yyvsp[-2].intNum)); }
#line 1924 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 227 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1930 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 230 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1936 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 231 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1942 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 232 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1948 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 233 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1954 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 234 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1960 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 235 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1966 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 236 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1972 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 237 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1978 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 238 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1984 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 241 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1990 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 244 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newStmt(ASSIGN_STMT); 
		addChild((yyval.node), newIdenExp(BASIC_ID, (yyvsp[-2].strValue), NULL));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2000 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 249 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(ASSIGN_STMT);
		addChild((yyval.node), newIdenExp(ARRAY_ID, (yyvsp[-5].strValue), (yyvsp[-3].node)));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2010 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 254 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(ASSIGN_STMT);
        Node *p = newIdenExp(BASIC_ID, (yyvsp[-2].strValue), NULL);
        addChild((yyval.node), newIdenExp(RECORD_ID, (yyvsp[-4].strValue), p));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2021 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 262 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newStmt(PROC_STMT);
		strcpy((yyval.node)->name, (yyvsp[0].strValue));
	}
#line 2030 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 266 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(PROC_STMT);
		strcpy((yyval.node)->name, (yyvsp[-3].strValue));
        addChild((yyval.node), (yyvsp[-1].node));
	}
#line 2040 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 271 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(PROC_STMT);
		strcpy((yyval.node)->name, (yyvsp[0].strValue));
		(yyval.node)->system = 1;
	}
#line 2050 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 276 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(PROC_STMT);
		strcpy((yyval.node)->name, (yyvsp[-3].strValue));
		(yyval.node)->system = 1;
        addChild((yyval.node), (yyvsp[-1].node));
	}
#line 2061 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 282 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(PROC_STMT);
		strcpy((yyval.node)->name, "read");
		(yyval.node)->system = 1;
        addChild((yyval.node), (yyvsp[-1].node));
	}
#line 2072 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 290 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newStmt(IF_STMT);
		addChild((yyval.node), (yyvsp[-3].node));
		addChild((yyval.node), (yyvsp[-1].node));
		addChild((yyval.node), (yyvsp[0].node));
        lineAssign((yyval.node), (yyvsp[-4].intNum));
	}
#line 2084 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 299 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2090 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 300 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2096 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 303 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newStmt(REPEAT_STMT);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
        lineAssign((yyval.node), (yyvsp[-3].intNum));
	}
#line 2107 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 311 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(WHILE_STMT);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
        lineAssign((yyval.node), (yyvsp[-3].intNum));
	}
#line 2118 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 319 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(FOR_STMT);
		strcpy((yyval.node)->name, (yyvsp[-6].strValue));
		addChild((yyval.node), (yyvsp[-4].node));
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
		(yyval.node)->attr.intNum = (yyvsp[-3].intNum);
        lineAssign((yyval.node), (yyvsp[-7].intNum));
	}
#line 2132 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 330 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.intNum) = 1; }
#line 2138 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 331 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.intNum) = 0; }
#line 2144 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 334 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(CASE_STMT);
		addChild((yyval.node), (yyvsp[-3].node));
		addChild((yyval.node), (yyvsp[-1].node));
        lineAssign((yyval.node), (yyvsp[-4].intNum));
	}
#line 2155 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 342 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2161 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 343 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2167 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 346 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newStmt(CASE_EXP_STMT);
		addChild((yyval.node), (yyvsp[-3].node));
		addChild((yyval.node), (yyvsp[-1].node));
	}
#line 2177 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 351 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(CASE_EXP_STMT);
		Node *p = newIdenExp(BASIC_ID, (yyvsp[-3].strValue), NULL);
        addChild((yyval.node), p);
		addChild((yyval.node), (yyvsp[-1].node));
	}
#line 2188 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 359 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newStmt(GOTO_STMT);
		(yyval.node)->attr.intNum = (yyvsp[0].intNum);
	}
#line 2197 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 365 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2203 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 366 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2209 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 369 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(GE_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2219 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 374 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(GT_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2229 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 379 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(LE_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2239 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 384 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(LT_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2249 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 389 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(EQ_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2259 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 394 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(UEQ_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2269 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 399 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2275 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 402 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(PLUS_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2285 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 407 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(MINUS_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2295 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 412 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(OR_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2305 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 417 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2311 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 420 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newOpExp(MUL_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2321 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 425 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newOpExp(DIV_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2331 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 430 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newOpExp(MOD_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2341 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 435 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newOpExp(AND_OP);
		addChild((yyval.node), (yyvsp[-2].node));
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2351 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 440 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2357 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 443 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newIdenExp(BASIC_ID, (yyvsp[0].strValue), NULL); }
#line 2363 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 444 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newFuncExp((yyvsp[-3].strValue), (yyvsp[-1].node)); }
#line 2369 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 445 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2375 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 446 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newFuncExp((yyvsp[-3].strValue), (yyvsp[-1].node));
		(yyval.node)->system = 1;
	}
#line 2384 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 450 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2390 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 451 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(NOT_OP);
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2399 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 455 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newOpExp(NEG_OP);
		addChild((yyval.node), (yyvsp[0].node));
	}
#line 2408 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 459 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2414 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 460 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = newIdenExp(ARRAY_ID, (yyvsp[-3].strValue), (yyvsp[-1].node)); }
#line 2420 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 461 "myCompiler.y" /* yacc.c:1646  */
    { 
        Node *p = newIdenExp(BASIC_ID, (yyvsp[0].strValue), NULL);
        (yyval.node) = newIdenExp(RECORD_ID, (yyvsp[-2].strValue), p); 
    }
#line 2429 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 467 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = addSibling((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2435 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 468 "myCompiler.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2441 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 471 "myCompiler.y" /* yacc.c:1646  */
    { 
		(yyval.node) = newConstExp(INTEGE);
		(yyval.node)->attr.intNum = (yyvsp[0].intNum);
	}
#line 2450 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 475 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newConstExp(REA);
		(yyval.node)->attr.realNum = (yyvsp[0].floatNum);
	}
#line 2459 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 479 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newConstExp(CHARA);
		(yyval.node)->attr.intNum = (yyvsp[0].intNum);
	}
#line 2468 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 483 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newConstExp(STR);
		strSet((yyval.node)->attr.strVal, (yyvsp[0].strValue));
	}
#line 2477 "myCompiler.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 487 "myCompiler.y" /* yacc.c:1646  */
    {
		(yyval.node) = newConstExp(BOOLEA);
		(yyval.node)->attr.intNum = (yyvsp[0].intNum);
	}
#line 2486 "myCompiler.tab.c" /* yacc.c:1646  */
    break;


#line 2490 "myCompiler.tab.c" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 492 "myCompiler.y" /* yacc.c:1906  */


void yyerror(char *s){
	fprintf(stderr, "%s\n", s);
	printf("%d\n", yylineno);
}
