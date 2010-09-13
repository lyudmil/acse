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
     LBRACE = 258,
     RBRACE = 259,
     LPAR = 260,
     RPAR = 261,
     LSQUARE = 262,
     RSQUARE = 263,
     SEMI = 264,
     COLON = 265,
     PLUS = 266,
     MINUS = 267,
     MUL_OP = 268,
     DIV_OP = 269,
     MOD_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     NOT_OP = 273,
     ASSIGN = 274,
     LT = 275,
     GT = 276,
     SHL_OP = 277,
     SHR_OP = 278,
     EQ = 279,
     NOTEQ = 280,
     LTEQ = 281,
     GTEQ = 282,
     ANDAND = 283,
     OROR = 284,
     COMMA = 285,
     FOR = 286,
     RETURN = 287,
     READ = 288,
     WRITE = 289,
     DO = 290,
     WHILE = 291,
     IF = 292,
     ELSE = 293,
     TYPE = 294,
     IDENTIFIER = 295,
     NUMBER = 296,
     NOT = 297
   };
#endif
/* Tokens.  */
#define LBRACE 258
#define RBRACE 259
#define LPAR 260
#define RPAR 261
#define LSQUARE 262
#define RSQUARE 263
#define SEMI 264
#define COLON 265
#define PLUS 266
#define MINUS 267
#define MUL_OP 268
#define DIV_OP 269
#define MOD_OP 270
#define AND_OP 271
#define OR_OP 272
#define NOT_OP 273
#define ASSIGN 274
#define LT 275
#define GT 276
#define SHL_OP 277
#define SHR_OP 278
#define EQ 279
#define NOTEQ 280
#define LTEQ 281
#define GTEQ 282
#define ANDAND 283
#define OROR 284
#define COMMA 285
#define FOR 286
#define RETURN 287
#define READ 288
#define WRITE 289
#define DO 290
#define WHILE 291
#define IF 292
#define ELSE 293
#define TYPE 294
#define IDENTIFIER 295
#define NUMBER 296
#define NOT 297




/* Copy the first part of user declarations.  */
#line 1 "Acse.y"

/*
 * Andrea Di Biagio
 * Politecnico di Milano, 2007
 * 
 * Acse.y
 * Formal Languages & Compilers Machine, 2007/2008
 * 
 */

/*************************************************************************

                   Compiler for the language LANCE

***************************************************************************/

#include <stdio.h>       
#include <stdlib.h>
#include <assert.h>
#include <malloc/malloc.h>
#include "axe_struct.h"
#include "axe_engine.h"
#include "symbol_table.h"
#include "axe_errors.h"
#include "collections.h"
#include "axe_expressions.h"
#include "axe_gencode.h"
#include "axe_utils.h"
#include "axe_array.h"
#include "axe_cflow_graph.h"
#include "cflow_constants.h"
#include "axe_transform.h"
#include "axe_reg_alloc.h"
#include "reg_alloc_constants.h"
#include "axe_io_manager.h"
#ifndef NDEBUG
#  include "axe_debug.h"
#endif



/* global variables */
int line_num;        /* this variable will keep track of the
                      * source code line number. Every time that a newline
                      * is encountered while parsing the input file, this
                      * value is increased by 1. This value is then used
                      * for error tracking: if the parser returns an error
                      * or a warning, this value is used in order to notify
                      * in which line of code the error has been found */
int num_error;       /* the number of errors found in the code. This value
                      * is increased by 1 every time a new error is found
                      * in the code. */
int num_warning;     /* As for the `num_error' global variable, this one
                      * keeps track of all the warning messages displayed */

/* errorcode is defined inside "axe_engine.c" */
extern int errorcode;   /* this variable is used to test if an error is found
                         * while parsing the input file. It also is set
                         * to notify if the compiler internal state is invalid.
                         * When the parsing process is started, the value
                         * of `errorcode' is set to the value of the macro
                         * `AXE_OK' defined in "axe_constants.h".
                         * As long as everything (the parsed source code and
                         * the internal state of the compiler) is correct,
                         * the value of `errorcode' is set to `AXE_OK'.
                         * When an error occurs (because the input file contains
                         * one or more syntax errors or because something went
                         * wrong in the machine internal state), the errorcode
                         * is set to a value that is different from `AXE_OK'. */
                         

extern int cflow_errorcode;   /* As for `errorcode' this value is used to
                        * test if an error occurs during the creation process of
                        * a control flow graph. More informations can be found
                        * analyzing the file `axe_cflow_graph.h'. */
                     
/* program informations */
t_program_infos *program;  /* The singleton instance of `program'.
                            * An instance of `t_program_infos' holds in its
                            * internal structure, all the useful informations
                            * about a program. For example: the assembly
                            * (code and directives); the symbol table;
                            * the label manager (see axe_labels.h) etc. */
t_cflow_Graph *graph;      /* An instance of a control flow graph. This instance
                            * will be generated starting from `program' and will
                            * be used during the register allocation process */

t_reg_allocator *RA;       /* Register allocator. It implements the "Linear scan"
                            * algorythm */

t_io_infos *file_infos;    /* input and output files used by the compiler */



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
#line 101 "Acse.y"
{            
   int intval;
   char *svalue;
   t_axe_expression expr;
   t_axe_declaration *decl;
   t_list *list;
   t_axe_label *label;
   t_while_statement while_stmt;
}
/* Line 193 of yacc.c.  */
#line 284 "Acse.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 297 "Acse.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   396

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    14,    18,    20,    24,
      29,    31,    33,    37,    40,    42,    45,    47,    50,    52,
      54,    56,    59,    62,    64,    66,    73,    77,    79,    80,
      85,    86,    87,    95,    96,    97,   105,   106,   114,   116,
     121,   126,   128,   130,   135,   138,   141,   143,   147,   151,
     155,   159,   163,   167,   171,   175,   179,   183,   187,   191,
     195,   199,   203,   207,   211
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    50,    -1,    45,    46,    -1,    -1,
      39,    47,     9,    -1,    47,    30,    48,    -1,    48,    -1,
      40,    19,    41,    -1,    40,     7,    41,     8,    -1,    40,
      -1,    51,    -1,     3,    50,     4,    -1,    50,    51,    -1,
      51,    -1,    54,     9,    -1,    52,    -1,    53,     9,    -1,
       9,    -1,    55,    -1,    60,    -1,    63,     9,    -1,    65,
       9,    -1,    66,    -1,    67,    -1,    40,     7,    68,     8,
      19,    68,    -1,    40,    19,    68,    -1,    57,    -1,    -1,
      57,    38,    56,    49,    -1,    -1,    -1,    37,    58,     5,
      68,     6,    59,    49,    -1,    -1,    -1,    36,    61,     5,
      68,     6,    62,    49,    -1,    -1,    35,    64,    49,    36,
       5,    68,     6,    -1,    32,    -1,    33,     5,    40,     6,
      -1,    34,     5,    68,     6,    -1,    41,    -1,    40,    -1,
      40,     7,    68,     8,    -1,    18,    41,    -1,    18,    40,
      -1,    54,    -1,    68,    16,    68,    -1,    68,    17,    68,
      -1,    68,    11,    68,    -1,    68,    12,    68,    -1,    68,
      13,    68,    -1,    68,    14,    68,    -1,    68,    20,    68,
      -1,    68,    21,    68,    -1,    68,    24,    68,    -1,    68,
      25,    68,    -1,    68,    26,    68,    -1,    68,    27,    68,
      -1,    68,    22,    68,    -1,    68,    23,    68,    -1,    68,
      28,    68,    -1,    68,    29,    68,    -1,     5,    68,     6,
      -1,    12,    68,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   168,   168,   181,   182,   185,   192,   196,   203,   212,
     221,   234,   235,   239,   240,   245,   246,   247,   248,   251,
     252,   253,   254,   257,   258,   261,   279,   315,   321,   320,
     340,   346,   339,   360,   369,   359,   396,   395,   417,   424,
     444,   463,   464,   477,   490,   495,   517,   520,   523,   526,
     529,   532,   535,   538,   541,   544,   547,   550,   553,   556,
     557,   558,   559,   560,   561
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LBRACE", "RBRACE", "LPAR", "RPAR",
  "LSQUARE", "RSQUARE", "SEMI", "COLON", "PLUS", "MINUS", "MUL_OP",
  "DIV_OP", "MOD_OP", "AND_OP", "OR_OP", "NOT_OP", "ASSIGN", "LT", "GT",
  "SHL_OP", "SHR_OP", "EQ", "NOTEQ", "LTEQ", "GTEQ", "ANDAND", "OROR",
  "COMMA", "FOR", "RETURN", "READ", "WRITE", "DO", "WHILE", "IF", "ELSE",
  "TYPE", "IDENTIFIER", "NUMBER", "NOT", "$accept", "program",
  "var_declarations", "var_declaration", "declaration_list", "declaration",
  "code_block", "statements", "statement", "control_statement",
  "read_write_statement", "assign_statement", "if_statement", "@1",
  "if_stmt", "@2", "@3", "while_statement", "@4", "@5",
  "do_while_statement", "@6", "return_statement", "read_statement",
  "write_statement", "exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    47,    48,    48,
      48,    49,    49,    50,    50,    51,    51,    51,    51,    52,
      52,    52,    52,    53,    53,    54,    54,    55,    56,    55,
      58,    59,    57,    61,    62,    60,    64,    63,    65,    66,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     3,     3,     1,     3,     4,
       1,     1,     3,     2,     1,     2,     1,     2,     1,     1,
       1,     2,     2,     1,     1,     6,     3,     1,     0,     4,
       0,     0,     7,     0,     0,     7,     0,     7,     1,     4,
       4,     1,     1,     4,     2,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    18,    38,     0,     0,    36,    33,
      30,     0,     0,     3,     2,    14,    16,     0,     0,    19,
      27,    20,     0,     0,    23,    24,     0,     0,     0,     0,
       0,    10,     0,     7,     0,     0,    13,    17,    15,    28,
      21,    22,     0,     0,     0,     0,    42,    41,    46,     0,
       0,     0,    11,     0,     0,     0,     0,     5,     0,     0,
      26,     0,    39,     0,    64,    45,    44,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     6,     0,    29,    63,     0,    49,    50,    51,    52,
      47,    48,    53,    54,    59,    60,    55,    56,    57,    58,
      61,    62,    12,     0,    34,    31,     9,     0,    43,     0,
       0,     0,    25,    37,    35,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    13,    32,    33,    51,    14,    52,    16,
      17,    48,    19,    61,    20,    30,   121,    21,    29,   120,
      22,    28,    23,    24,    25,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
     -43,     8,    98,   -43,   -43,   -43,    -3,    11,   -43,   -43,
     -43,   -31,    -4,   -43,   107,   -43,   -43,     9,    12,   -43,
     -21,   -43,    26,    31,   -43,   -43,   -11,     2,    21,    36,
      39,     3,    -5,   -43,     2,     2,   -43,   -43,   -43,   -43,
     -43,   -43,    44,     2,     2,   -35,     4,   -43,   -43,   139,
     107,    15,   -43,     2,     2,    40,    41,   -43,   -31,   257,
     298,    21,   -43,   163,    25,   -43,   -43,     2,   -43,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    88,    47,   187,   211,    37,
     -43,   -43,    61,   -43,   -43,   279,    25,    25,   -43,   -43,
     369,   352,    76,    76,    20,    20,    82,    82,    76,    76,
     335,   317,   -43,     2,   -43,   -43,   -43,     2,    61,   235,
      21,    21,   298,   -43,   -43,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -43,   -43,   -43,    27,   -42,    50,    -1,   -43,
     -43,    -2,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,    -7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      18,    15,    26,    34,    57,    65,    66,    43,     3,    31,
      55,    67,    18,    36,    44,    35,    27,    39,    37,    93,
      45,    38,    56,    35,    50,    58,    18,    59,    60,    42,
       4,    69,    70,    71,    72,    40,    63,    64,    71,    72,
      41,    53,    46,    47,    54,   116,    87,    88,    18,    15,
      62,    86,   113,     5,     6,     7,     8,     9,    10,    18,
      95,    12,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   124,   125,
     117,    89,    90,    18,    36,    91,     0,    69,    70,    71,
      72,     0,   112,    69,    70,    71,    72,     4,    77,    78,
      85,     0,    75,    76,    77,    78,   119,     4,    81,    82,
     122,     0,     0,     0,     0,     0,     4,     0,    18,    18,
       5,     6,     7,     8,     9,    10,     0,     0,    12,     0,
       5,     6,     7,     8,     9,    10,     0,    11,    12,     5,
       6,     7,     8,     9,    10,    68,     0,    12,     0,     0,
      69,    70,    71,    72,     0,    73,    74,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    94,
       0,     0,     0,     0,    69,    70,    71,    72,     0,    73,
      74,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,   114,     0,     0,     0,     0,    69,    70,
      71,    72,     0,    73,    74,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   115,     0,     0,
       0,     0,    69,    70,    71,    72,     0,    73,    74,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,   123,     0,     0,     0,     0,    69,    70,    71,    72,
       0,    73,    74,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    92,     0,     0,    69,    70,
      71,    72,     0,    73,    74,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   118,     0,     0,
      69,    70,    71,    72,     0,    73,    74,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    69,
      70,    71,    72,     0,    73,    74,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    69,    70,
      71,    72,     0,    73,    74,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    69,    70,    71,    72,
       0,    73,    74,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    69,    70,    71,    72,     0,    73,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      69,    70,    71,    72,     0,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82
};

static const yytype_int8 yycheck[] =
{
       2,     2,     5,     7,     9,    40,    41,     5,     0,    40,
       7,     7,    14,    14,    12,    19,     5,    38,     9,    61,
      18,     9,    19,    19,     3,    30,    28,    34,    35,    40,
       9,    11,    12,    13,    14,     9,    43,    44,    13,    14,
       9,     5,    40,    41,     5,     8,    53,    54,    50,    50,
       6,    36,     5,    32,    33,    34,    35,    36,    37,    61,
      67,    40,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   120,   121,
      19,    41,    41,    85,    85,    58,    -1,    11,    12,    13,
      14,    -1,     4,    11,    12,    13,    14,     9,    22,    23,
      50,    -1,    20,    21,    22,    23,   113,     9,    26,    27,
     117,    -1,    -1,    -1,    -1,    -1,     9,    -1,   120,   121,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    -1,
      32,    33,    34,    35,    36,    37,    -1,    39,    40,    32,
      33,    34,    35,    36,    37,     6,    -1,    40,    -1,    -1,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     6,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     6,    -1,    -1,    -1,    -1,    11,    12,
      13,    14,    -1,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     6,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    -1,    16,    17,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     6,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      -1,    16,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     8,    -1,    -1,    11,    12,
      13,    14,    -1,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     8,    -1,    -1,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    11,
      12,    13,    14,    -1,    16,    17,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    11,    12,
      13,    14,    -1,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    11,    12,    13,    14,
      -1,    16,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,     9,    32,    33,    34,    35,    36,
      37,    39,    40,    46,    50,    51,    52,    53,    54,    55,
      57,    60,    63,    65,    66,    67,     5,     5,    64,    61,
      58,    40,    47,    48,     7,    19,    51,     9,     9,    38,
       9,     9,    40,     5,    12,    18,    40,    41,    54,    68,
       3,    49,    51,     5,     5,     7,    19,     9,    30,    68,
      68,    56,     6,    68,    68,    40,    41,     7,     6,    11,
      12,    13,    14,    16,    17,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    50,    36,    68,    68,    41,
      41,    48,     8,    49,     6,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,     4,     5,     6,     6,     8,    19,     8,    68,
      62,    59,    68,     6,    49,    49
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
#line 169 "Acse.y"
    {
            /* Notify the end of the program. Once called
             * the function `set_end_Program' - if necessary -
             * introduces a `HALT' instruction into the
             * list of instructions. */
            set_end_Program(program);

            /* return from yyparse() */
            YYACCEPT;
         ;}
    break;

  case 3:
#line 181 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 4:
#line 182 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 5:
#line 186 "Acse.y"
    {
                     /* update the program infos by adding new variables */
                     set_new_variables(program, (yyvsp[(1) - (3)].intval), (yyvsp[(2) - (3)].list));
                  ;}
    break;

  case 6:
#line 193 "Acse.y"
    {  /* add the new declaration to the list of declarations */
                     (yyval.list) = addElement((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].decl), -1);
                  ;}
    break;

  case 7:
#line 197 "Acse.y"
    {
                     /* add the new declaration to the list of declarations */
                     (yyval.list) = addElement(NULL, (yyvsp[(1) - (1)].decl), -1);
                  ;}
    break;

  case 8:
#line 204 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[(1) - (3)].svalue), 0, 0, (yyvsp[(3) - (3)].intval));

               /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 9:
#line 213 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[(1) - (4)].svalue), 1, (yyvsp[(3) - (4)].intval), 0);

                  /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 10:
#line 222 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[(1) - (1)].svalue), 0, 0, 0);
               
               /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 11:
#line 234 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 12:
#line 235 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 13:
#line 239 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 14:
#line 240 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 15:
#line 245 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 16:
#line 246 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 17:
#line 247 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 18:
#line 248 "Acse.y"
    { gen_nop_instruction(program); ;}
    break;

  case 19:
#line 251 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 20:
#line 252 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 21:
#line 253 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 22:
#line 254 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 23:
#line 257 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 24:
#line 258 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 25:
#line 262 "Acse.y"
    {
               /* Notify to `program' that the value $6
                * have to be assigned to the location
                * addressed by $1[$3]. Where $1 is obviously
                * the array/pointer identifier, $3 is an expression
                * that holds an integer value. That value will be
                * used as an index for the array $1 */
               storeArrayElement(program, (yyvsp[(1) - (6)].svalue), (yyvsp[(3) - (6)].expr), (yyvsp[(6) - (6)].expr));

               /* free the memory associated with the IDENTIFIER.
                * The use of the free instruction is required
                * because of the value associated with IDENTIFIER.
                * The value of IDENTIFIER is a string created
                * by a call to the function `strdup' (see Acse.lex) */
               free((yyvsp[(1) - (6)].svalue));
			   (yyval.expr) = create_expression((yyvsp[(6) - (6)].expr).value, REGISTER);
            ;}
    break;

  case 26:
#line 280 "Acse.y"
    {
               int location;
               t_axe_instruction *instr;

               /* in order to assign a value to a variable, we have to
                * know where the variable is located (i.e. in which register).
                * the function `get_symbol_location' is used in order
                * to retrieve the register location assigned to
                * a given identifier.
                * A symbol table keeps track of the location of every
                * declared variable.
                * `get_symbol_location' perform a query on the symbol table
                * in order to discover the correct location of
                * the variable with $1 as identifier */
               
               /* get the location of the symbol with the given ID. */
               location = get_symbol_location(program, (yyvsp[(1) - (3)].svalue), 0);

               /* update the value of location */
               if ((yyvsp[(3) - (3)].expr).expression_type == IMMEDIATE) {
					instr = gen_addi_instruction
	                     (program, location, REG_0, (yyvsp[(3) - (3)].expr).value);
					(yyval.expr) = create_expression((yyvsp[(3) - (3)].expr).value, IMMEDIATE);
			   }
               else {
			        instr = gen_add_instruction
	                        (program, location, REG_0, (yyvsp[(3) - (3)].expr).value, CG_DIRECT_ALL);

	               /* free the memory associated with the IDENTIFIER */
	               free((yyvsp[(1) - (3)].svalue));
				   (yyval.expr) = create_expression((yyvsp[(3) - (3)].expr).value, REGISTER);
			   }
            ;}
    break;

  case 27:
#line 316 "Acse.y"
    {
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[(1) - (1)].label));
               ;}
    break;

  case 28:
#line 321 "Acse.y"
    {
                  /* reserve a new label that points to the address where to jump if
                   * `exp' is verified */
                  (yyvsp[(2) - (2)].label) = newLabel(program);
   
                  /* exit from the if-else */
                  gen_bt_instruction (program, (yyvsp[(2) - (2)].label), 0);
   
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[(1) - (2)].label));
               ;}
    break;

  case 29:
#line 333 "Acse.y"
    {
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[(2) - (4)].label));
               ;}
    break;

  case 30:
#line 340 "Acse.y"
    {
                  /* the label that points to the address where to jump if
                   * `exp' is not verified */
                  (yyvsp[(1) - (1)].label) = newLabel(program);
               ;}
    break;

  case 31:
#line 346 "Acse.y"
    {
                     if ((yyvsp[(4) - (5)].expr).expression_type == IMMEDIATE)
                         gen_load_immediate(program, (yyvsp[(4) - (5)].expr).value);
                     else
                         gen_andb_instruction(program, (yyvsp[(4) - (5)].expr).value,
                             (yyvsp[(4) - (5)].expr).value, (yyvsp[(4) - (5)].expr).value, CG_DIRECT_ALL);

                     /* if `exp' returns FALSE, jump to the label $1 */
                     gen_beq_instruction (program, (yyvsp[(1) - (5)].label), 0);
               ;}
    break;

  case 32:
#line 356 "Acse.y"
    { (yyval.label) = (yyvsp[(1) - (7)].label); ;}
    break;

  case 33:
#line 360 "Acse.y"
    {
                     /* initialize the value of the non-terminal */
                     (yyvsp[(1) - (1)].while_stmt) = create_while_statement();

                     /* reserve and fix a new label */
                     (yyvsp[(1) - (1)].while_stmt).label_condition
                           = assignNewLabel(program);
                  ;}
    break;

  case 34:
#line 369 "Acse.y"
    {
                     if ((yyvsp[(4) - (5)].expr).expression_type == IMMEDIATE)
                        gen_load_immediate(program, (yyvsp[(4) - (5)].expr).value);
                     else
                         gen_andb_instruction(program, (yyvsp[(4) - (5)].expr).value,
                             (yyvsp[(4) - (5)].expr).value, (yyvsp[(4) - (5)].expr).value, CG_DIRECT_ALL);

                     /* reserve a new label. This new label will point
                      * to the first instruction after the while code
                      * block */
                     (yyvsp[(1) - (5)].while_stmt).label_end = newLabel(program);

                     /* if `exp' returns FALSE, jump to the label $1.label_end */
                     gen_beq_instruction (program, (yyvsp[(1) - (5)].while_stmt).label_end, 0);
                  ;}
    break;

  case 35:
#line 385 "Acse.y"
    {
                     /* jump to the beginning of the loop */
                     gen_bt_instruction
                           (program, (yyvsp[(1) - (7)].while_stmt).label_condition, 0);

                     /* fix the label `label_end' */
                     assignLabel(program, (yyvsp[(1) - (7)].while_stmt).label_end);
                  ;}
    break;

  case 36:
#line 396 "Acse.y"
    {
                        /* the label that points to the address where to jump if
                         * `exp' is not verified */
                        (yyvsp[(1) - (1)].label) = newLabel(program);
                        
                        /* fix the label */
                        assignLabel(program, (yyvsp[(1) - (1)].label));
                     ;}
    break;

  case 37:
#line 405 "Acse.y"
    {
                           if ((yyvsp[(6) - (7)].expr).expression_type == IMMEDIATE)
                               gen_load_immediate(program, (yyvsp[(6) - (7)].expr).value);
                           else
                               gen_andb_instruction(program, (yyvsp[(6) - (7)].expr).value,
                                   (yyvsp[(6) - (7)].expr).value, (yyvsp[(6) - (7)].expr).value, CG_DIRECT_ALL);

                           /* if `exp' returns TRUE, jump to the label $1 */
                           gen_bne_instruction (program, (yyvsp[(1) - (7)].label), 0);
                     ;}
    break;

  case 38:
#line 418 "Acse.y"
    {
               /* insert an HALT instruction */
               gen_halt_instruction(program);
            ;}
    break;

  case 39:
#line 425 "Acse.y"
    {
               int location;
               
               /* read from standard input an integer value and assign
                * it to a variable associated with the given identifier */
               /* get the location of the symbol with the given ID */
               
               /* lookup the symbol table and fetch the register location
                * associated with the IDENTIFIER $3. */
               location = get_symbol_location(program, (yyvsp[(3) - (4)].svalue), 0);

               /* insert a read instruction */
               gen_read_instruction (program, location);

               /* free the memory associated with the IDENTIFIER */
               free((yyvsp[(3) - (4)].svalue));
            ;}
    break;

  case 40:
#line 445 "Acse.y"
    {
   
               int location;

               if ((yyvsp[(3) - (4)].expr).expression_type == IMMEDIATE)
               {
                  /* load `immediate' into a new register. Returns the new register
                   * identifier or REG_INVALID if an error occurs */
                  location = gen_load_immediate(program, (yyvsp[(3) - (4)].expr).value);
               }
               else
                  location = (yyvsp[(3) - (4)].expr).value;

               /* write to standard output an integer value */
               gen_write_instruction (program, location);
            ;}
    break;

  case 41:
#line 463 "Acse.y"
    { (yyval.expr) = create_expression ((yyvsp[(1) - (1)].intval), IMMEDIATE); ;}
    break;

  case 42:
#line 464 "Acse.y"
    {
                     int location;
   
                     /* get the location of the symbol with the given ID */
                     location = get_symbol_location(program, (yyvsp[(1) - (1)].svalue), 0);
                     
                     /* return the register location of IDENTIFIER as
                      * a value for `exp' */
                     (yyval.expr) = create_expression (location, REGISTER);

                     /* free the memory associated with the IDENTIFIER */
                     free((yyvsp[(1) - (1)].svalue));
   ;}
    break;

  case 43:
#line 477 "Acse.y"
    {
                     int reg;
                     
                     /* load the value IDENTIFIER[exp]
                      * into `arrayElement' */
                     reg = loadArrayElement(program, (yyvsp[(1) - (4)].svalue), (yyvsp[(3) - (4)].expr));

                     /* create a new expression */
                     (yyval.expr) = create_expression (reg, REGISTER);

                     /* free the memory associated with the IDENTIFIER */
                     free((yyvsp[(1) - (4)].svalue));
   ;}
    break;

  case 44:
#line 490 "Acse.y"
    {  if ((yyvsp[(2) - (2)].intval) == 0)
                           (yyval.expr) = create_expression (1, IMMEDIATE);
                        else
                           (yyval.expr) = create_expression (0, IMMEDIATE);
   ;}
    break;

  case 45:
#line 495 "Acse.y"
    {
                           int identifier_location;
                           int output_register;
   
                           /* get the location of the symbol with the given ID */
                           identifier_location =
                                 get_symbol_location(program, (yyvsp[(2) - (2)].svalue), 0);

                           /* generate a NOT instruction. In order to do this,
                            * at first we have to ask for a free register where
                            * to store the result of the NOT instruction. */
                           output_register = getNewRegister(program);

                           /* Now we are able to generate a NOT instruction */
                           gen_notl_instruction (program, output_register
                                 , identifier_location);

                           (yyval.expr) = create_expression (output_register, REGISTER);

                           /* free the memory associated with the IDENTIFIER */
                           free((yyvsp[(2) - (2)].svalue));
   ;}
    break;

  case 46:
#line 517 "Acse.y"
    {
                          (yyval.expr) = create_expression((yyvsp[(1) - (1)].expr).value, REGISTER);
   ;}
    break;

  case 47:
#line 520 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), ANDB);
   ;}
    break;

  case 48:
#line 523 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), ORB);
   ;}
    break;

  case 49:
#line 526 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), ADD);
   ;}
    break;

  case 50:
#line 529 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), SUB);
   ;}
    break;

  case 51:
#line 532 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), MUL);
   ;}
    break;

  case 52:
#line 535 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), DIV);
   ;}
    break;

  case 53:
#line 538 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), _LT_);
   ;}
    break;

  case 54:
#line 541 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), _GT_);
   ;}
    break;

  case 55:
#line 544 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), _EQ_);
   ;}
    break;

  case 56:
#line 547 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), _NOTEQ_);
   ;}
    break;

  case 57:
#line 550 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), _LTEQ_);
   ;}
    break;

  case 58:
#line 553 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), _GTEQ_);
   ;}
    break;

  case 59:
#line 556 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), SHL); ;}
    break;

  case 60:
#line 557 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), SHR); ;}
    break;

  case 61:
#line 558 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), ANDL); ;}
    break;

  case 62:
#line 559 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr), ORL); ;}
    break;

  case 63:
#line 560 "Acse.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 64:
#line 561 "Acse.y"
    {
                        if ((yyvsp[(2) - (2)].expr).expression_type == IMMEDIATE)
                        {
                           (yyval.expr) = (yyvsp[(2) - (2)].expr);
                           (yyval.expr).value = - ((yyval.expr).value);
                        }
                        else
                        {
                           t_axe_expression exp_r0;

                           /* create an expression for regisrer REG_0 */
                           exp_r0.value = REG_0;
                           exp_r0.expression_type = REGISTER;
                           
                           (yyval.expr) = handle_bin_numeric_op
                                 (program, exp_r0, (yyvsp[(2) - (2)].expr), SUB);
                        }
                     ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2257 "Acse.tab.c"
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


#line 581 "Acse.y"

/*=========================================================================
                                  MAIN
=========================================================================*/
int main (int argc, char **argv)
{
   /* initialize all the compiler data structures and global variables */
   init_compiler(argc, argv);
   
   /* start the parsing procedure */
   yyparse();
   
#ifndef NDEBUG
   fprintf(stdout, "Parsing process completed. \n");
#endif

   /* test if the parsing process completed succesfully */
   checkConsistency();
   
#ifndef NDEBUG
   fprintf(stdout, "Creating a control flow graph. \n");
#endif

   /* create the control flow graph */
   graph = createFlowGraph(program->instructions);
   checkConsistency();

#ifndef NDEBUG
   assert(program != NULL);
   assert(program->sy_table != NULL);
   assert(file_infos != NULL);
   assert(file_infos->syTable_output != NULL);
   printSymbolTable(program->sy_table, file_infos->syTable_output);
   printGraphInfos(graph, file_infos->cfg_1, 0);
      
   fprintf(stdout, "Updating the basic blocks. \n");
#endif
      
   /* update the control flow graph by inserting load and stores inside
   * every basic block */
   graph = insertLoadAndStoreInstr(program, graph);

#ifndef NDEBUG
   fprintf(stdout, "Executing a liveness analysis on the intermediate code \n");
#endif
   performLivenessAnalysis(graph);
   checkConsistency();

#ifndef NDEBUG
   printGraphInfos(graph, file_infos->cfg_2, 1);
#endif
      
#ifndef NDEBUG
   fprintf(stdout, "Starting the register allocation process. \n");
#endif
   /* initialize the register allocator by using the control flow
    * informations stored into the control flow graph */
   RA = initializeRegAlloc(graph);
      
   /* execute the linear scan algorythm */
   execute_linear_scan(RA);
      
#ifndef NDEBUG
   printRegAllocInfos(RA, file_infos->reg_alloc_output);
#endif

#ifndef NDEBUG
   fprintf(stdout, "Updating the control flow informations. \n");
#endif
   /* apply changes to the program informations by using the informations
   * of the register allocation process */
   updateProgramInfos(program, graph, RA);

#ifndef NDEBUG
   fprintf(stdout, "Writing the assembly file... \n");
#endif
   writeAssembly(program, file_infos->output_file_name);
      
#ifndef NDEBUG
   fprintf(stdout, "Assembly written on file \"%s\".\n", file_infos->output_file_name);
#endif
   
   /* shutdown the compiler */
   shutdownCompiler(0);

   return 0;
}

/*=========================================================================
                                 YYERROR
=========================================================================*/
int yyerror(const char* errmsg)
{
   errorcode = AXE_SYNTAX_ERROR;
   
   return 0;
}

