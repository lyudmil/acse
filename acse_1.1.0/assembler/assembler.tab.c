/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OPCODE3 = 258,
     OPCODE2 = 259,
     OPCODEI = 260,
     CCODE = 261,
     HALT = 262,
     NOP = 263,
     _WORD = 264,
     _SPACE = 265,
     REG = 266,
     LPAR = 267,
     RPAR = 268,
     COLON = 269,
     MINUS = 270,
     BEGIN_IMMEDIATE = 271,
     BEGIN_COMMENT = 272,
     END_COMMENT = 273,
     COMMENT = 274,
     ETI = 275,
     IMM = 276
   };
#endif
/* Tokens.  */
#define OPCODE3 258
#define OPCODE2 259
#define OPCODEI 260
#define CCODE 261
#define HALT 262
#define NOP 263
#define _WORD 264
#define _SPACE 265
#define REG 266
#define LPAR 267
#define RPAR 268
#define COLON 269
#define MINUS 270
#define BEGIN_IMMEDIATE 271
#define BEGIN_COMMENT 272
#define END_COMMENT 273
#define COMMENT 274
#define ETI 275
#define IMM 276




/* Copy the first part of user declarations.  */
#line 1 "assembler.y"

/*
 * Andrea Di Biagio
 * Politecnico di Milano, 2007
 * 
 * assembler.y
 * Formal Languages & Compilers Machine, 2007/2008
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include "asm_struct.h"
#include "asm_engine.h"

/* Variables declared for error tracking */
int line_num;
int num_error;

/* other global variables */
t_translation_infos *infos;

/* functions declared into assembler.y */
char * AsmErrorToString(int errorcode);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "assembler.y"
{
	char *svalue;
	int immediate;
	int opcode;
	t_asm_address *address;
	t_asm_data *dataVal;
   t_asm_instruction *instr;
   t_asm_label *label;
   t_asm_register *reg;
}
/* Line 193 of yacc.c.  */
#line 177 "assembler.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 190 "assembler.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   82

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  22
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  31
/* YYNRULES -- Number of states.  */
#define YYNSTATES  56

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    15,    17,    20,    24,
      26,    29,    34,    39,    43,    46,    48,    50,    53,    56,
      58,    61,    63,    66,    69,    72,    74,    78,    81,    85,
      87,    89
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      23,     0,    -1,    23,    27,    24,    -1,    27,    24,    -1,
      24,    -1,    24,    25,    -1,    25,    -1,    26,    34,    -1,
      29,    26,    34,    -1,    26,    -1,    29,    26,    -1,     3,
      31,    11,    31,    -1,     4,    11,    11,    32,    -1,     5,
      11,    33,    -1,     6,    33,    -1,     7,    -1,     8,    -1,
      27,    28,    -1,    28,    34,    -1,    28,    -1,    29,    30,
      -1,    30,    -1,    20,    14,    -1,     9,    21,    -1,    10,
      21,    -1,    11,    -1,    12,    11,    13,    -1,    16,    21,
      -1,    16,    15,    21,    -1,    20,    -1,    21,    -1,    17,
      19,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    76,    77,    80,    81,    84,    85,    89,
      90,    96,   134,   174,   212,   236,   260,   286,   287,   288,
     291,   305,   318,   361,   375,   391,   405,   421,   422,   425,
     473,   486
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPCODE3", "OPCODE2", "OPCODEI", "CCODE",
  "HALT", "NOP", "_WORD", "_SPACE", "REG", "LPAR", "RPAR", "COLON",
  "MINUS", "BEGIN_IMMEDIATE", "BEGIN_COMMENT", "END_COMMENT", "COMMENT",
  "ETI", "IMM", "$accept", "asm", "instruction_segm", "instruction",
  "instr", "data_segm", "data_def", "label_decl", "data_value", "register",
  "immediate", "address", "comment", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    22,    23,    23,    23,    24,    24,    25,    25,    25,
      25,    26,    26,    26,    26,    26,    26,    27,    27,    27,
      28,    28,    29,    30,    30,    31,    31,    32,    32,    33,
      33,    34
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     2,     1,     2,     3,     1,
       2,     4,     4,     3,     2,     1,     1,     2,     2,     1,
       2,     1,     2,     2,     2,     1,     3,     2,     3,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    15,    16,     0,     0,     0,
       0,     4,     6,     9,     0,    19,     0,    21,    25,     0,
       0,     0,     0,    29,    30,    14,    23,    24,    22,     1,
       0,     0,     5,     0,     0,     7,     3,    17,    18,    10,
      20,     0,     0,     0,    13,     2,     0,     8,    26,    11,
       0,    12,    31,     0,    27,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    20,
      51,    25,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -12
static const yytype_int8 yypact[] =
{
      11,    22,     0,    26,    23,   -12,   -12,    18,    21,    47,
       3,     2,   -12,    48,    11,    48,    44,   -12,   -12,    55,
      56,    57,    23,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
      11,    53,   -12,    52,    45,   -12,     2,   -12,   -12,    48,
     -12,    58,    22,    54,   -12,     2,    51,   -12,   -12,   -12,
      17,   -12,   -12,    59,   -12,   -12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -12,   -12,    15,    -9,     8,    62,    16,   -10,     9,    31,
     -12,    60,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      31,    33,    32,    29,    38,     1,     2,     3,     4,     5,
       6,    21,     7,     8,     1,     2,     3,     4,     5,     6,
       7,     8,     9,     9,    39,    40,    33,    32,    47,    36,
      37,     9,    53,    18,    19,    33,    32,    22,    54,    26,
      40,    39,    27,    23,    24,    45,    37,     1,     2,     3,
       4,     5,     6,     7,     8,     1,     2,     3,     4,     5,
       6,    28,     7,     8,    46,    34,    41,    42,    43,    52,
      50,    48,    30,    49,     0,     0,     0,     0,     0,     0,
      55,     0,    44
};

static const yytype_int8 yycheck[] =
{
      10,    11,    11,     0,    15,     3,     4,     5,     6,     7,
       8,    11,     9,    10,     3,     4,     5,     6,     7,     8,
       9,    10,    20,    20,    16,    16,    36,    36,    39,    14,
      14,    20,    15,    11,    12,    45,    45,    11,    21,    21,
      31,    33,    21,    20,    21,    30,    30,     3,     4,     5,
       6,     7,     8,     9,    10,     3,     4,     5,     6,     7,
       8,    14,     9,    10,    19,    17,    11,    11,    11,    18,
      16,    13,    10,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    20,
      23,    24,    25,    26,    27,    28,    29,    30,    11,    12,
      31,    11,    11,    20,    21,    33,    21,    21,    14,     0,
      27,    29,    25,    29,    17,    34,    24,    28,    34,    26,
      30,    11,    11,    11,    33,    24,    19,    34,    13,    31,
      16,    32,    18,    15,    21,    21
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 75 "assembler.y"
    { /* DOES NOTHING */;}
    break;

  case 3:
#line 76 "assembler.y"
    { /* DOES NOTHING */;}
    break;

  case 4:
#line 77 "assembler.y"
    { /* DOES NOTHING */;}
    break;

  case 5:
#line 80 "assembler.y"
    { line_num++; ;}
    break;

  case 6:
#line 81 "assembler.y"
    { line_num++; ;}
    break;

  case 7:
#line 84 "assembler.y"
    { /* DOES NOTHING */;}
    break;

  case 8:
#line 85 "assembler.y"
    {
               /* assign the label to the current instruction */
               (yyvsp[(1) - (3)].label)->data = (void *) (yyvsp[(2) - (3)].instr);
            ;}
    break;

  case 9:
#line 89 "assembler.y"
    { /* DOES NOTHING */;}
    break;

  case 10:
#line 90 "assembler.y"
    {
               /* assign the label to the current instruction */
               (yyvsp[(1) - (2)].label)->data = (void *) (yyvsp[(2) - (2)].instr);
            ;}
    break;

  case 11:
#line 96 "assembler.y"
    {
         t_asm_register *reg;
         int asm_errorcode;
         
         /* alloc memory for a register info. */
         reg = allocRegister((yyvsp[(3) - (4)].immediate), 0);
   
         /* register shouldn't be a NULL pointer */
         if (reg == NULL)
         {
            /* an out of memory occurred */
            yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
            /* stop the parser */
            YYABORT;
         }

         /* initialize an instruction with three operands' */
         (yyval.instr) = init_opcode3((yyvsp[(1) - (4)].opcode), (yyvsp[(2) - (4)].reg), reg, (yyvsp[(4) - (4)].reg));
         
         /* $$ shouldn't be a NULL pointer */
         if ((yyval.instr) == NULL)
         {
            /* an out of memory occurred */
            yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
            /* stop the parser */
            YYABORT;
         }

         /* add the newly created instruction to the code segment */
         asm_errorcode = addInstruction(infos, (yyval.instr));
         if (asm_errorcode != ASM_OK)
         {
               /* an error occurred */
               yyerror(AsmErrorToString(asm_errorcode));
         }
      ;}
    break;

  case 12:
#line 134 "assembler.y"
    {
         t_asm_register *register_1;
         t_asm_register *register_2;
         int asm_errorcode;
         
         /* alloc memory for a register info. */
         register_1 = allocRegister((yyvsp[(2) - (4)].immediate), 0);
         register_2 = allocRegister((yyvsp[(3) - (4)].immediate), 0);
   
         /* registers shouldn't be a NULL pointer */
         if (register_1 == NULL || register_2 == NULL)
         {
            /* an out of memory occurred */
            yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
            /* stop the parser */
            YYABORT;
         }

         /* initialize an instruction with two operands' */
         (yyval.instr) = init_opcode2((yyvsp[(1) - (4)].opcode), register_1, register_2, (yyvsp[(4) - (4)].immediate));
         
         /* $$ shouldn't be a NULL pointer */
         if ((yyval.instr) == NULL)
         {
            /* an out of memory occurred */
            yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
            /* stop the parser */
            YYABORT;
         }

         /* add the newly created instruction to the code segment */
         asm_errorcode = addInstruction(infos, (yyval.instr));
         if (asm_errorcode != ASM_OK)
         {
               /* an error occurred */
               yyerror(AsmErrorToString(asm_errorcode));
         }
      ;}
    break;

  case 13:
#line 174 "assembler.y"
    {
         t_asm_register *reg;
         int asm_errorcode;
         
         /* alloc memory for a register info. */
         reg = allocRegister((yyvsp[(2) - (3)].immediate), 0);
   
         /* register shouldn't be a NULL pointer */
         if (reg == NULL)
         {
            /* an out of memory occurred */
            yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
            /* stop the parser */
            YYABORT;
         }

         /* initialize an instruction with a single operand' */
         (yyval.instr) = init_opcodeI((yyvsp[(1) - (3)].opcode), reg, (yyvsp[(3) - (3)].address));
         
         /* $$ shouldn't be a NULL pointer */
         if ((yyval.instr) == NULL)
         {
            /* an out of memory occurred */
            yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
            /* stop the parser */
            YYABORT;
         }

         /* add the newly created instruction to the code segment */
         asm_errorcode = addInstruction(infos, (yyval.instr));
         if (asm_errorcode != ASM_OK)
         {
               /* an error occurred */
               yyerror(AsmErrorToString(asm_errorcode));
         }
      ;}
    break;

  case 14:
#line 212 "assembler.y"
    {
         int asm_errorcode;
         
         /* initialize a branch instruction */
         (yyval.instr) = init_ccode((yyvsp[(1) - (2)].opcode), (yyvsp[(2) - (2)].address));
         
         /* $$ shouldn't be a NULL pointer */
         if ((yyval.instr) == NULL)
         {
            /* an out of memory occurred */
            yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
            /* stop the parser */
            YYABORT;
         }

         /* add the newly created instruction to the code segment */
         asm_errorcode = addInstruction(infos, (yyval.instr));
         if (asm_errorcode != ASM_OK)
         {
               /* an error occurred */
               yyerror(AsmErrorToString(asm_errorcode));
         }
      ;}
    break;

  case 15:
#line 236 "assembler.y"
    {
         int asm_errorcode;
         
         /* initialize a HALT instruction */
         (yyval.instr) = init_halt();

         /* $$ shouldn't be a NULL pointer */
         if ((yyval.instr) == NULL)
         {
            /* an out of memory occurred */
            yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
            /* stop the parser */
            YYABORT;
         }

         /* add the newly created instruction to the code segment */
         asm_errorcode = addInstruction(infos, (yyval.instr));
         if (asm_errorcode != ASM_OK)
         {
               /* an error occurred */
               yyerror(AsmErrorToString(asm_errorcode));
         }
      ;}
    break;

  case 16:
#line 260 "assembler.y"
    {
         int asm_errorcode;
         
         /* initialize a NOP instruction */
         (yyval.instr) = init_nop();

         /* $$ shouldn't be a NULL pointer */
         if ((yyval.instr) == NULL)
         {
            /* an out of memory occurred */
            yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
            /* stop the parser */
            YYABORT;
         }

         /* add the newly created instruction to the code segment */
         asm_errorcode = addInstruction(infos, (yyval.instr));
         if (asm_errorcode != ASM_OK)
         {
               /* an error occurred */
               yyerror(AsmErrorToString(asm_errorcode));
         }
      ;}
    break;

  case 17:
#line 286 "assembler.y"
    { line_num++; ;}
    break;

  case 18:
#line 287 "assembler.y"
    { line_num++; ;}
    break;

  case 19:
#line 288 "assembler.y"
    { line_num++; ;}
    break;

  case 20:
#line 291 "assembler.y"
    {
                  int asm_errorcode;

                  /* insert data into the data segment */
                  asm_errorcode = addData(infos, (yyvsp[(2) - (2)].dataVal));
                  if (asm_errorcode != ASM_OK)
                  {
                     /* an error occurred */
                     yyerror(AsmErrorToString(asm_errorcode));
                  }

                  /* assign the label to the current block of data */
                  (yyvsp[(1) - (2)].label)->data = (void *) (yyvsp[(2) - (2)].dataVal);
         ;}
    break;

  case 21:
#line 305 "assembler.y"
    {
                  int asm_errorcode;

                  /* insert data into the data segment */
                  asm_errorcode = addData(infos, (yyvsp[(1) - (1)].dataVal));
                  if (asm_errorcode != ASM_OK)
                  {
                     /* an error occurred */
                     yyerror(AsmErrorToString(asm_errorcode));
                  }
         ;}
    break;

  case 22:
#line 318 "assembler.y"
    {
            int asm_errorcode;
            
            /* look for the requested label */
            (yyval.label) = findLabel(infos, (yyvsp[(1) - (2)].svalue), &asm_errorcode);
            if (asm_errorcode != ASM_OK)
            {
               /* an error occurred */
               yyerror(AsmErrorToString(asm_errorcode));
            }
            
            if ((yyval.label) == NULL)
            {
               t_asm_label *label;
            
               /* label was never defined before */
               label = allocLabel((yyvsp[(1) - (2)].svalue), NULL);

               /* label shouldn't be a NULL pointer */
               if (label == NULL)
               {
                  /* an out of memory occurred */
                  yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
                  /* stop the parser */
                  YYABORT;
               }

               /* insert the new label */
               asm_errorcode = insertLabel(infos, label);

               /* set the $$ value */
               (yyval.label) = label;
            }
            else
               free((yyvsp[(1) - (2)].svalue));

            /* notify if an error occurred */
            if (asm_errorcode != ASM_OK)
               yyerror(AsmErrorToString(asm_errorcode));
         ;}
    break;

  case 23:
#line 361 "assembler.y"
    {
               /* create an instance of `t_asm_data' */
               (yyval.dataVal) = allocData(ASM_WORD, (yyvsp[(2) - (2)].immediate));

               /* $$ shouldn't be a NULL pointer */
               if ((yyval.dataVal) == NULL)
               {
                  /* an out of memory occurred */
                  yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
                  /* stop the parser */
                  YYABORT;
               }
           ;}
    break;

  case 24:
#line 375 "assembler.y"
    {
               /* create an instance of `t_asm_data' */
               (yyval.dataVal) = allocData(ASM_SPACE, (yyvsp[(2) - (2)].immediate));

               /* $$ shouldn't be a NULL pointer */
               if ((yyval.dataVal) == NULL)
               {
                  /* an out of memory occurred */
                  yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
                  /* stop the parser */
                  YYABORT;
               }
           ;}
    break;

  case 25:
#line 391 "assembler.y"
    {
               /* alloc memory for a register info. */
               (yyval.reg) = allocRegister((yyvsp[(1) - (1)].immediate), 0);
   
               /* $$ shouldn't be a NULL pointer */
               if ((yyval.reg) == NULL)
               {
                  /* an out of memory occurred */
                  yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
                  /* stop the parser */
                  YYABORT;
               }
         ;}
    break;

  case 26:
#line 405 "assembler.y"
    {
               /* alloc memory for a register info. */
               (yyval.reg) = allocRegister((yyvsp[(2) - (3)].immediate), 1);
   
               /* label shouldn't be a NULL pointer */
               if ((yyval.reg) == NULL)
               {
                  /* an out of memory occurred */
                  yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
                  /* stop the parser */
                  YYABORT;
               }
         ;}
    break;

  case 27:
#line 421 "assembler.y"
    { (yyval.immediate) = (yyvsp[(2) - (2)].immediate); ;}
    break;

  case 28:
#line 422 "assembler.y"
    {(yyval.immediate) = - (yyvsp[(3) - (3)].immediate); ;}
    break;

  case 29:
#line 425 "assembler.y"
    {
            int asm_errorcode;
            t_asm_label *label_found;
            
            /* look for the requested label */
            label_found = findLabel(infos, (yyvsp[(1) - (1)].svalue), &asm_errorcode);
            if (asm_errorcode != ASM_OK)
            {
               /* an error occurred */
               yyerror(AsmErrorToString(asm_errorcode));
            }
            
            if (label_found == NULL)
            {
               /* label was never defined before */
               label_found = allocLabel((yyvsp[(1) - (1)].svalue), NULL);

               /* label shouldn't be a NULL pointer */
               if (label_found == NULL)
               {
                  /* an out of memory occurred */
                  yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
                  /* stop the parser */
                  YYABORT;
               }

               /* insert the new label */
               asm_errorcode = insertLabel(infos, label_found);

               /* notify if an error occurred */
               if (asm_errorcode != ASM_OK)
                  yyerror(AsmErrorToString(asm_errorcode));
            }
            else
               free((yyvsp[(1) - (1)].svalue));

            /* set the $$ value */
            (yyval.address) = allocAddress(0, label_found);
            if ((yyval.address) == NULL)
            {
                  /* an out of memory occurred */
                  yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
                  /* stop the parser */
                  YYABORT;
            }
         ;}
    break;

  case 30:
#line 473 "assembler.y"
    {
            (yyval.address) = allocAddress((yyvsp[(1) - (1)].immediate), NULL);
            if ((yyval.address) == NULL)
            {
                  /* an out of memory occurred */
                  yyerror(AsmErrorToString(ASM_OUT_OF_MEMORY));
               
                  /* stop the parser */
                  YYABORT;
            }
         ;}
    break;

  case 31:
#line 486 "assembler.y"
    { (yyval.svalue) = (yyvsp[(2) - (3)].svalue); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1941 "assembler.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 490 "assembler.y"

		 
int yyerror(const char* errmsg)
{
	fprintf(stdout, "line %d , error: %s \n", line_num, errmsg);
	num_error++;
	return 0;
}

int main (int argc, char **argv)
{
   int errorcode;
   char *filename;
   FILE *input_file;
	extern FILE *yyin;

   argc--;
   argv++;
	
   if (argc > 0)
   {
      input_file = fopen(argv[0], "r");
      if (input_file == NULL)
      {
         fprintf( stdout, "File not found : %s.\n", argv[0]);
         exit(-1);
      }
      yyin = input_file;
   }
   else
      yyin = stdin;
	
   if (argc <= 1)
      filename = "output.o";
   else
      filename = argv[1];
	
#ifndef NDEBUG
   fprintf(stdout, "Initializing the assembler data structures.\n");
#endif
   /* initialize the translation infos */
   infos = initStructures(&errorcode);

   /* test if an error occurred */
   if (errorcode != ASM_OK)
   {
         fprintf( stdout, "An error occurred while initializing the assembler.\n"
                  "%s. \n", AsmErrorToString(errorcode));

         /* we can't start the parsing procedure since a critical error occurred */
         abort();
   }

   /* initialize the global variables */
   line_num = 1;
   num_error = 0;
   
#ifndef NDEBUG
   if (argc > 0)
      fprintf(stdout, "Starting the parsing process. "
                        "Input file : %s.\n", argv[0]);
   else
      fprintf(stdout, "Starting the parsing process. "
                        "Input file : standard input.\n");
#endif
   /* start the parsing procedure */
   yyparse();

#ifndef NDEBUG
   fprintf(stdout, "Parsing complete. \n");
#endif
	
   /* test if the parsing job found some errors */
   if (num_error == 0)
   {
#ifndef NDEBUG
      fprintf(stdout, "Output will be written on file : %s. \n", filename);
#endif
      errorcode = asm_writeObjectFile(infos, filename);
      if (errorcode != ASM_OK)
      {
         fprintf( stdout, "An error occurred while writing the object file.\n"
                  "%s. \n", AsmErrorToString(errorcode));
      }
#ifndef NDEBUG
      else
         fprintf(stdout, "Output written on file \"%s\".\n", filename);
#endif
   }
   else {
      fprintf(stdout, "\nInput file contains some error(s). No object file written\n");
      fprintf(stdout, "**%d errors found \n\n", num_error);
   }

#ifndef NDEBUG
   fprintf(stdout, "Finalizing the data structures. \n");
#endif

   /* shutdown the asm engine */
   if (infos != NULL)
   {
         errorcode = finalizeStructures(infos);
         if (errorcode != ASM_OK)
         {
            fprintf(stdout, "SHUTDOWN:: error while finalizing "
                  "the data structures. \n%s. \n", AsmErrorToString(errorcode));
         }
   }

#ifndef NDEBUG
   fprintf(stdout, "Done. \n");
#endif
   
   return 0;
}

char * AsmErrorToString(int errorcode)
{
   switch(errorcode)
   {
      case ASM_NOT_INITIALIZED_INFO : return "global infos not initialized";
      case ASM_UNDEFINED_INSTRUCTION : return "invalid instruction found";
      case ASM_INVALID_LABEL_FOUND : return "invalid label found";
      case ASM_LABEL_ALREADY_PRESENT : return "label already defined";
      case ASM_UNDEFINED_DATA : return "invalid data found";
      case ASM_INVALID_DATA_FORMAT : return "invalid data format";
      case ASM_FOPEN_ERROR : return "fopen failed";
      case ASM_INVALID_INPUT_FILE : return "invalid file pointer";
      case ASM_FWRITE_ERROR : return "fwrite failed";
      case ASM_FCLOSE_ERROR : return "fclose failed";
      case ASM_CODE_NOT_PRESENT : return "code segment is empty";
      case ASM_OUT_OF_MEMORY : return "out of memory";
      case ASM_INVALID_OPCODE : return "invalid opcode found";
      case ASM_UNKNOWN_ERROR : return "unknown error found";
      default : return "<invalid errorcode>";
   }
}

