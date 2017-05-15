
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "ecomp.y"

#include <stdio.h>
#include <string.h>
#include "ecomp.tab.h"

#if 1
#define keyhit(d) {int x; printf("hit enter to continue  (%d)",d); getchar();}
#else
#define keyhit ; 
#endif

#define pause {int x; printf("enter 0 to continue "); scanf("%d", &x); }

char *yytext;
FILE *yyin;
FILE *outfile;
int yy_flex_debug;
//int nest;

int istack[10];
int istackptr=0;
int ijump=0;
int wstack[10];
int wstackptr=0;
int wjump=0;
int estack[10];
int estackptr=0;
int ejump=0;

int thisIsNot =0;


typedef struct 
{ char idop[11];
  int type;
} PARSE;

PARSE parse[500];
PARSE parsecopy[20];
int copysindex;
int ifstck[10];

#define GMAX 30
#define SMAX 20
#define INITMAX 100

#define GLOBALVAR 0
#define SUBVAR    1
#define REGISTER   2 
int checkvartype;

char glovars[GMAX][11];
//char locvars[GMAX][11];
char initialized[INITMAX];
int  initializedindex = 0; 
char  countinitialized = 0; 
char subvars[SMAX][11];
unsigned int nglob;

int yylex(void);
void yyerror(char *);

char storage[11];
char *gid[11];
char assID[11];
char prevID[11];
char optype[3];
int assIDon = 1;
int i,j,k;

int  sindex = 0;
int  pindex = 0;
int  memloc = 0;
int psub =1;
int loadcount =0;
int smemloc = 0;

int symloc=0;

int showparse( int beg)
{ int i;
        for (i=beg; i<sindex; i++)
        {  printf("############## parse[%d].idop= %s, (type)%d\n",
                                i, parse[i].idop, parse[i].type);
        }
        printf("end show\n");
}

int termcopy(int beg)
{ int i, j;
         printf("termcopy: storage loc calc here\n");
         //fprintf(outfile,"storage loc calc here\n");
         j = 0;        
         strcpy(parsecopy[j].idop, parse[beg].idop);
         parsecopy[j].type = parse[beg].type;
 
printf("%s  ->   %s\n", parse[beg].idop, parsecopy[beg].idop);

         if(parse[beg+1].idop[0] == '[')
         { i= beg+1; j++;
           do { /* append parse[i].idop to tgt */
             strcpy(parsecopy[j].idop, parse[i].idop);
printf("%s  ->   %s\n", parse[i].idop, parsecopy[j].idop);
             parsecopy[j].type = parse[beg].type;
             j++;
           } while (parse[i++].idop[0] != ']');
         }
         copysindex = j;
}

int printinitialized()
{ int i;

   fprintf(outfile, ".IDATA\n");
   for(i=0; initialized[i]; i++)
   { if(initialized[i] == -1)
     { fprintf(outfile, "\n");
       //printf("\n");
     }
     else
     { fprintf(outfile, "%c", initialized[i]);
       // printf("%c", initialized[i]);
     }
   } 
}

int showterm( int beg)
{ int i;
//fprintf(outfile, "sindex=%d\n", sindex);
        for (i=beg; i<sindex; i++)
        {  fprintf(outfile, "  %s",  parse[i].idop);
           printf("    %s",  parse[i].idop);
           if( ((i+1)<sindex) && (parse[i+1].idop[0] == '['))
           { i= i+1;
             do { /* append parse[i].idop to tgt */
               fprintf(outfile, "%s",  parse[i].idop);
               printf("%s",  parse[i].idop);
             } while (parse[i++].idop[0] != ']');
             i--;
           }
        }
        fprintf(outfile, "\n");
}

int declr_alloc(int loc)
{ int i;
printf("declr_alloc called from %d\n", loc);
//showparse(0);
//showterm(0);
//keyhit(445);
//printf("END of showparse showterm\n");

  if( parse[0].type != ID )
  {  printf("declare Identifier err: %s\n", parse[0].idop ); 
  
  } 
  printf("declr_alloc():   loc:%d\n",  memloc);

  if( parse[1].type != (char)LBRCT )
  {   
      return;
  }
  else
  {    printf("declr_alloc():  %s", parse[2].idop);
      return;
  }
}



/* Line 189 of yacc.c  */
#line 244 "ecomp.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SUBRTN = 258,
     NUMBER = 259,
     ID = 260,
     IF = 261,
     ELSE = 262,
     WHILE = 263,
     EQ = 264,
     PLUS = 265,
     MINUS = 266,
     MUL = 267,
     DIV = 268,
     END = 269,
     PROCESS = 270,
     RP = 271,
     LP = 272,
     RB = 273,
     LB = 274,
     RBRCT = 275,
     LBRCT = 276,
     AND = 277,
     OR = 278,
     NOT = 279,
     LE_OP = 280,
     GE_OP = 281,
     LT_OP = 282,
     GT_OP = 283,
     EQ_OP = 284,
     NE_OP = 285,
     HALT = 286,
     OPEN = 287,
     READ = 288,
     WRITE = 289,
     CLOSE = 290,
     SEEK = 291,
     SEMICOL = 292,
     COMMA = 293,
     LOCK = 294,
     UNLOCK = 295,
     DBLQT = 296,
     CHARSTR = 297,
     ARRAY = 298,
     LPREC = 299,
     RPREC = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 172 "ecomp.y"
int intval;
 char *sptr;



/* Line 214 of yacc.c  */
#line 331 "ecomp.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 343 "ecomp.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    16,    18,    21,
      23,    27,    29,    31,    36,    40,    43,    48,    52,    56,
      59,    63,    66,    71,    73,    77,    80,    82,    85,    87,
      91,    93,    95,    97,    99,   101,   103,   105,   107,   109,
     111,   113,   116,   121,   124,   130,   136,   142,   148,   151,
     155,   158,   161,   165,   167,   171,   176,   178,   181,   187,
     190,   194,   196,   198,   206,   214,   216,   220,   224,   229,
     234,   237,   240,   244,   247,   249,   251,   253,   257,   261,
     265,   269,   273,   277,   281,   285,   287,   290,   294,   298,
     301,   303,   305
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    54,    -1,    49,    54,    -1,
      48,    54,    -1,    49,    50,    -1,    50,    -1,    51,    37,
      -1,    52,    -1,    51,    38,    52,    -1,    94,    -1,    53,
      -1,    94,    21,    91,    20,    -1,    59,    61,    18,    -1,
      59,    18,    -1,    60,    19,    61,    18,    -1,    60,    19,
      18,    -1,     3,    55,    54,    -1,    57,    56,    -1,    19,
      61,    18,    -1,    19,    18,    -1,    58,    17,    75,    16,
      -1,     5,    -1,    60,    19,    37,    -1,    15,    94,    -1,
      62,    -1,    61,    62,    -1,    78,    -1,    78,     7,    81,
      -1,    71,    -1,    88,    -1,    85,    -1,    87,    -1,    66,
      -1,    63,    -1,    67,    -1,    68,    -1,    69,    -1,    72,
      -1,    70,    -1,    64,    65,    -1,    89,    32,    17,    75,
      -1,    16,    37,    -1,    36,    17,    75,    16,    37,    -1,
      33,    17,    75,    16,    37,    -1,    34,    17,    75,    16,
      37,    -1,    35,    17,    75,    16,    37,    -1,    75,    37,
      -1,    76,    19,    80,    -1,    73,    74,    -1,    94,    17,
      -1,    75,    16,    37,    -1,    94,    -1,    75,    38,    94,
      -1,    77,    17,    83,    16,    -1,     8,    -1,    79,    80,
      -1,     6,    17,    83,    16,    19,    -1,    61,    18,    -1,
      82,    61,    18,    -1,    19,    -1,    84,    -1,    17,    83,
      16,    23,    17,    83,    16,    -1,    17,    83,    16,    22,
      17,    83,    16,    -1,    91,    -1,    91,    22,    91,    -1,
      91,    23,    91,    -1,    24,    17,    83,    16,    -1,    86,
      61,    40,    37,    -1,    39,    37,    -1,    31,    37,    -1,
      89,    90,    37,    -1,    52,     9,    -1,    91,    -1,    92,
      -1,    93,    -1,    92,    10,    93,    -1,    92,    11,    93,
      -1,    92,    26,    93,    -1,    92,    28,    93,    -1,    92,
      25,    93,    -1,    92,    27,    93,    -1,    92,    29,    93,
      -1,    92,    30,    93,    -1,    52,    -1,    11,    52,    -1,
      93,    13,    52,    -1,    93,    12,    52,    -1,    95,    41,
      -1,     5,    -1,     4,    -1,    41,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   224,   224,   230,   233,   236,   243,   244,   248,   280,
     283,   289,   291,   297,   305,   307,   309,   311,   313,   317,
     321,   322,   325,   345,   352,   371,   384,   387,   393,   398,
     403,   406,   409,   412,   415,   418,   421,   424,   427,   430,
     432,   436,   438,   479,   485,   512,   528,   547,   569,   590,
     600,   633,   647,   657,   661,   668,   685,   692,   699,   719,
     725,   732,   746,   752,   761,   772,   777,   783,   788,   796,
     803,   810,   818,   873,   885,   894,   899,   904,   909,   914,
     919,   924,   929,   934,   939,   946,   949,   953,   957,   963,
     972,   979,   988
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SUBRTN", "NUMBER", "ID", "IF", "ELSE",
  "WHILE", "EQ", "PLUS", "MINUS", "MUL", "DIV", "END", "PROCESS", "RP",
  "LP", "RB", "LB", "RBRCT", "LBRCT", "AND", "OR", "NOT", "LE_OP", "GE_OP",
  "LT_OP", "GT_OP", "EQ_OP", "NE_OP", "HALT", "OPEN", "READ", "WRITE",
  "CLOSE", "SEEK", "SEMICOL", "COMMA", "LOCK", "UNLOCK", "DBLQT",
  "CHARSTR", "ARRAY", "LPREC", "RPREC", "$accept", "program", "programx",
  "varlistend", "varlists", "varlist", "declr", "arrayterm", "program0",
  "subroutines", "subbody", "subnidarglist", "subname", "process0",
  "process1", "statements", "statement", "openstatement", "openfirst",
  "opensecond", "seekstatement", "readstatement", "writestatement",
  "closestatement", "locdeclare", "whilestatement", "subroutine",
  "subrtnid", "subrest", "arglist", "whilepart", "whilehead",
  "ifstatement", "ifpart", "rest", "elsestatement", "elsepart", "cond",
  "andcond", "lockstatement", "lockhead", "haltstatement", "assignment",
  "declrEQ", "assexpr", "expr", "expr0", "mulexpr", "term", "dblqtid", 0
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
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    53,    54,    54,    54,    54,    54,    55,
      56,    56,    57,    58,    59,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    83,    83,    84,    84,    84,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    93,    94,
      94,    94,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     1,     2,     1,
       3,     1,     1,     4,     3,     2,     4,     3,     3,     2,
       3,     2,     4,     1,     3,     2,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     2,     5,     5,     5,     5,     2,     3,
       2,     2,     3,     1,     3,     4,     1,     2,     5,     2,
       3,     1,     1,     7,     7,     1,     3,     3,     4,     4,
       2,     2,     3,     2,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     3,     3,     2,
       1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    91,    90,     0,     0,     0,     2,     0,     7,
       0,     9,    12,     3,     0,     0,    11,     0,    23,     0,
       0,     0,    25,    92,     1,     5,     6,     4,     8,     0,
       0,    56,    15,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    35,     0,    34,    36,    37,    38,    40,    30,
      39,     0,     0,     0,     0,    28,     0,    32,     0,    33,
      31,     0,    53,     0,     0,    89,    18,     0,    19,     0,
      10,     0,    71,     0,     0,     0,     0,    70,    73,    14,
      27,     0,    41,    50,     0,    53,    48,     0,     0,     0,
       0,     0,    57,     0,     0,     0,    85,     0,    74,    75,
      76,    51,    17,    24,     0,     0,    21,     0,     0,     0,
       0,     0,    62,    65,     0,     0,     0,     0,    43,     0,
      54,    49,     0,    61,    29,     0,    59,     0,    86,     0,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    13,    20,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    55,     0,    69,    42,    77,
      78,    81,    79,    82,    80,    83,    84,    88,    87,     0,
       0,    58,    66,    67,    45,    46,    47,    44,    60,     0,
       0,    68,     0,     0,     0,     0,    64,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    96,    12,    13,    19,
      68,    20,    21,    14,    15,    91,    41,    42,    43,    82,
      44,    45,    46,    47,    48,    49,    50,    51,    83,    52,
      53,    54,    55,    56,    92,   124,   125,   111,   112,    57,
      58,    59,    60,    61,    97,   113,    99,   100,    16,    17
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -86
static const yytype_int16 yypact[] =
{
       2,    16,   -86,   -86,    -3,    21,    32,    50,     2,   -86,
      -7,   -86,   -86,   -86,   161,    35,    30,    18,   -86,    50,
      51,    66,   -86,   -86,   -86,   -86,   -86,   -86,   -86,    -3,
      67,   -86,   -86,    52,    91,    92,    94,    95,    78,   107,
     180,   -86,   -86,   105,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,    -3,    -2,   103,   106,   119,   313,   -86,   313,   -86,
     -86,     5,    93,   141,    23,   -86,   -86,   199,   -86,    -3,
     -86,   127,   -86,    -3,    -3,    -3,    -3,   -86,   -86,   -86,
     -86,    90,   -86,   -86,    -5,   -86,   -86,    -3,   313,   127,
     110,   218,   -86,   237,    -3,   113,   -86,    96,   -86,   312,
      64,   -86,   -86,   -86,   256,   115,   -86,   275,     3,   127,
     120,   125,   -86,    56,     4,     6,     7,     9,   -86,    99,
     -86,   -86,   126,   -86,   -86,   313,   -86,   111,   -86,    -3,
     -86,    23,    23,    23,    23,    23,    23,    23,    23,    -3,
      -3,   -86,   -86,   -86,   -86,   134,   127,   124,    23,    23,
     116,   117,   121,   123,   -86,   -86,   294,   -86,   114,    64,
      64,    64,    64,    64,    64,    64,    64,   -86,   -86,    58,
     145,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   140,
     147,   -86,   127,   127,   146,   154,   -86,   -86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,   -86,   -86,   163,   -86,     0,   -86,    41,   -86,
     -86,   -86,   -86,   -86,   -86,    38,   -22,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,    44,
     -86,   -86,   -86,   -86,   101,   -86,   -86,   -85,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -49,   -86,   224,    -1,   -86
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -12
static const yytype_int16 yytable[] =
{
      11,     2,     3,    22,   122,     1,     2,     3,    11,     2,
       3,   119,    98,    62,    39,   105,    94,     4,    80,   144,
     150,    18,   151,   152,   145,   153,    23,     2,     3,    70,
      28,    29,    24,    87,    94,    86,    87,    95,     5,    62,
      39,    87,    87,     5,    87,    87,     5,    87,    25,    27,
      85,    64,    40,     1,    63,    62,    39,    62,    39,    65,
      66,   170,    62,    39,     5,     4,    62,    39,    85,    80,
      67,    80,    85,    85,    85,    85,   139,   140,   148,   149,
     179,   180,    80,    69,    71,    80,   120,    62,    39,    72,
      62,    39,    62,    39,   128,    84,    93,   184,   185,   172,
     173,   104,   -11,    62,    39,   107,    62,    39,    73,    74,
     101,    75,    76,   108,    64,    77,    78,   114,   115,   116,
     117,    81,    88,    89,    62,    39,    90,   118,    85,   123,
     129,     2,     3,   130,    80,   142,   154,   146,    94,   167,
     168,   147,   155,   171,   109,     2,     3,    30,   157,    31,
     169,   110,    87,   174,   175,    62,    39,   182,   176,   102,
     177,   181,   186,   156,   183,     2,     3,    30,     5,    31,
     187,    26,    33,   158,    34,    35,    36,    37,   103,    32,
      38,     0,     5,     0,     2,     3,    30,     0,    31,   121,
       0,     0,    33,     0,    34,    35,    36,    37,    79,     0,
      38,     0,     5,     2,     3,    30,     0,    31,     0,     0,
       0,    33,     0,    34,    35,    36,    37,   106,     0,    38,
       0,     5,     2,     3,    30,     0,    31,     0,     0,     0,
      33,     0,    34,    35,    36,    37,   126,     0,    38,     0,
       5,     2,     3,    30,     0,    31,     0,     0,     0,    33,
       0,    34,    35,    36,    37,     0,     0,    38,     0,     5,
       2,     3,    30,     0,    31,     0,     0,     0,    33,     0,
      34,    35,    36,    37,   141,     0,    38,   127,     5,     2,
       3,    30,     0,    31,     0,     0,     0,    33,     0,    34,
      35,    36,    37,   143,     0,    38,     0,     5,     2,     3,
      30,     0,    31,     0,     0,     0,    33,     0,    34,    35,
      36,    37,   178,     0,    38,     0,     5,     2,     3,    30,
       0,    31,   131,   132,     0,    33,     0,    34,    35,    36,
      37,     0,     0,    38,     0,     5,     0,   133,   134,   135,
     136,   137,   138,     0,    33,     0,    34,    35,    36,    37,
       0,     0,    38,     0,     5,   159,   160,   161,   162,   163,
     164,   165,   166
};

static const yytype_int16 yycheck[] =
{
       0,     4,     5,     4,    89,     3,     4,     5,     8,     4,
       5,    16,    61,    14,    14,    64,    11,    15,    40,    16,
      16,     5,    16,    16,   109,    16,     5,     4,     5,    29,
      37,    38,     0,    38,    11,    37,    38,    32,    41,    40,
      40,    38,    38,    41,    38,    38,    41,    38,     7,     8,
      51,    21,    14,     3,    19,    56,    56,    58,    58,    41,
      19,   146,    63,    63,    41,    15,    67,    67,    69,    91,
      19,    93,    73,    74,    75,    76,    12,    13,    22,    23,
      22,    23,   104,    17,    17,   107,    87,    88,    88,    37,
      91,    91,    93,    93,    94,    51,    58,   182,   183,   148,
     149,    63,     9,   104,   104,    67,   107,   107,    17,    17,
      17,    17,    17,    69,    21,    37,     9,    73,    74,    75,
      76,    16,    19,    17,   125,   125,     7,    37,   129,    19,
      17,     4,     5,    37,   156,    20,    37,    17,    11,   139,
     140,    16,    16,    19,    17,     4,     5,     6,    37,     8,
      16,    24,    38,    37,    37,   156,   156,    17,    37,    18,
      37,    16,    16,   125,    17,     4,     5,     6,    41,     8,
      16,     8,    31,   129,    33,    34,    35,    36,    37,    18,
      39,    -1,    41,    -1,     4,     5,     6,    -1,     8,    88,
      -1,    -1,    31,    -1,    33,    34,    35,    36,    18,    -1,
      39,    -1,    41,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    31,    -1,    33,    34,    35,    36,    18,    -1,    39,
      -1,    41,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      31,    -1,    33,    34,    35,    36,    18,    -1,    39,    -1,
      41,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    31,
      -1,    33,    34,    35,    36,    -1,    -1,    39,    -1,    41,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    31,    -1,
      33,    34,    35,    36,    18,    -1,    39,    40,    41,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    31,    -1,    33,
      34,    35,    36,    18,    -1,    39,    -1,    41,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    31,    -1,    33,    34,
      35,    36,    18,    -1,    39,    -1,    41,     4,     5,     6,
      -1,     8,    10,    11,    -1,    31,    -1,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    41,    -1,    25,    26,    27,
      28,    29,    30,    -1,    31,    -1,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    41,   131,   132,   133,   134,   135,
     136,   137,   138
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    15,    41,    47,    48,    49,    50,
      51,    52,    53,    54,    59,    60,    94,    95,     5,    55,
      57,    58,    94,     5,     0,    54,    50,    54,    37,    38,
       6,     8,    18,    31,    33,    34,    35,    36,    39,    52,
      61,    62,    63,    64,    66,    67,    68,    69,    70,    71,
      72,    73,    75,    76,    77,    78,    79,    85,    86,    87,
      88,    89,    94,    19,    21,    41,    54,    19,    56,    17,
      52,    17,    37,    17,    17,    17,    17,    37,     9,    18,
      62,    16,    65,    74,    75,    94,    37,    38,    19,    17,
       7,    61,    80,    61,    11,    32,    52,    90,    91,    92,
      93,    17,    18,    37,    61,    91,    18,    61,    75,    17,
      24,    83,    84,    91,    75,    75,    75,    75,    37,    16,
      94,    80,    83,    19,    81,    82,    18,    40,    52,    17,
      37,    10,    11,    25,    26,    27,    28,    29,    30,    12,
      13,    18,    20,    18,    16,    83,    17,    16,    22,    23,
      16,    16,    16,    16,    37,    16,    61,    37,    75,    93,
      93,    93,    93,    93,    93,    93,    93,    52,    52,    16,
      83,    19,    91,    91,    37,    37,    37,    37,    18,    22,
      23,    16,    17,    17,    83,    83,    16,    16
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 225 "ecomp.y"
    {
          printinitialized();
          printf("DONE\n");
         ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 231 "ecomp.y"
    { printf("END PARSING 1\n"); 
         ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 234 "ecomp.y"
    { fprintf(outfile, "\n"); printf("END PARSING 2\n");
         ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 237 "ecomp.y"
    { fprintf(outfile, "\n"); printf("END PARSING 3\n");
         ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 249 "ecomp.y"
    { int i,j;
                j=0;
                fprintf(outfile,".DATA\n");
                for (i=0; i<sindex; i++)
                {
                   if( parse[i].type == ID)
                   { strcpy(glovars[j++], parse[i].idop);
                     fprintf(outfile,"%s", parse[i].idop);
                     //checkvar( parse[i].idop, 0 );
                   }
                   else if( parse[i].type == COMMA || parse[i].type == SEMICOL)
                   { continue;
                   }
                   if(parse[i+1].idop[0] == '[')
                   { fprintf(outfile, ",");
                     fprintf(outfile, "%s",  parse[i+2].idop);
                     if(parse[i+3].idop[0] != ']')
                         fprintf(outfile,"err var name array?\n");
                     i=i+3;
                   }
                   fprintf(outfile,"\n");
                }
                nglob=j;
                fprintf(outfile,"\n");
                //for(i=0; i<nglob; i++) fprintf(outfile, "(%s)\n", glovars[i]);
                //showterm(0);
                //fprintf(outfile, "varlistend\n");
                sindex=0;
              ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 281 "ecomp.y"
    { //fprintf(outfile, "global ID=%s $$ ALLOCATE\n", yylval.sptr); 
              ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 284 "ecomp.y"
    { //fprintf(outfile, "global IDs=%s $$ ALLOCATE\n", yylval.sptr ); 
              ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 289 "ecomp.y"
    { declr_alloc(4);
               ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 292 "ecomp.y"
    { declr_alloc(5);
               ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 298 "ecomp.y"
    { printf("term [exp]\n");
                 //showterm(0);
                printf("TERM [ EXPR ]  code?\n");
               ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 306 "ecomp.y"
    { fprintf(outfile, "END\n");  sindex=0;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 308 "ecomp.y"
    { fprintf(outfile, "END\n");  sindex=0;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 310 "ecomp.y"
    { fprintf(outfile, "END\n");  sindex=0; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 312 "ecomp.y"
    { fprintf(outfile, "END\n");  sindex=0; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 314 "ecomp.y"
    { sindex=0;  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 318 "ecomp.y"
    { fprintf(outfile, "RET\n\n");  sindex=0;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 326 "ecomp.y"
    {
             smemloc=0;
             /*printf("arglist\n");
             for (i=0; i<sindex; i++)
             { if(parse[i].type == ID )
               { strcpy(subvars[smemloc++], parse[i].idop);
                 printf("arg sym %s\n", parse[i].idop);
                   { int i;
                     for(i=0; i<smemloc; i++)
                     { printf("subnidarglist: %s\n", subvars[i]);
                     }
                   }
               }
             }
             //sindex = 0;
             */
          ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 346 "ecomp.y"
    {
               printf("subroutine declared %s\n", yylval.sptr);
               fprintf(outfile,"%s:\n", yylval.sptr);
          ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 353 "ecomp.y"
    { // process1 LB  varlist SEMICOL 
                // activate the above if local variables are wanted

                showparse(0);
                if( parse[0].type != ID )
                { printf("declare Process Identifier err\n"); 
                }  
                fprintf(outfile, ".TEXT-%d\n", pindex);
                pindex++;
                showterm(0);
 
               //sindex = 0;
                psub = 0;
                printf("process0 term  code?? psub=%d\n",psub);
              ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 372 "ecomp.y"
    {
                fprintf(outfile, "PROC ");
                showterm(0);
                sindex = 0;
                psub = 0;
                printf("process1  code?? psub=%d\n",psub);
                //fprintf(outfile, "process ID end sindex=%d\n", sindex);
              ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 385 "ecomp.y"
    { printf("statement  code??\n");
              ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 388 "ecomp.y"
    { printf("statements statement code??\n");
              ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 394 "ecomp.y"
    { printf("---statement:= ifstatement end\n"); 
                istackptr--;
                fprintf(outfile, "I%d:\n", istack[istackptr]);
              ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 399 "ecomp.y"
    { printf("---statement:= ifstatement elsestatement end\n"); 
                estackptr--;
                fprintf(outfile, "E%d:\n", estack[estackptr]);
              ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 404 "ecomp.y"
    { printf("---statement:= ifstatement\n"); 
              ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 407 "ecomp.y"
    { printf("===statement:= assignment\n");
              ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 410 "ecomp.y"
    { printf("===lock statement:\n");
              ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 413 "ecomp.y"
    { printf("===halt statement:\n");
              ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 416 "ecomp.y"
    { printf("===open statement:\n");
              ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 419 "ecomp.y"
    { printf("===open statement:\n");
              ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 422 "ecomp.y"
    { printf("===read statement:\n");
              ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 425 "ecomp.y"
    { printf("===write statement:\n");
              ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 428 "ecomp.y"
    { printf("===close statement:\n");
              ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 431 "ecomp.y"
    { printf("=== subroutine statement:\n"); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 433 "ecomp.y"
    { printf("=== locdeclare:\n"); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 440 "ecomp.y"
    { int i;
                char label[10];

                showparse(0);
                fprintf(outfile,"LA L%d\n", countinitialized);
                fprintf(stderr,"LA L%d\n", countinitialized);
                sprintf( label, "%d", countinitialized);
                initialized[initializedindex++]='L';
                for(i=0; label[i]; i++)
                initialized[initializedindex++]=label[i];
                initialized[initializedindex++]=':';
                
                for(i=0; parse[2].idop[i]; i++)
                initialized[initializedindex++]=parse[2].idop[i];
                initialized[initializedindex++]=-1;

                countinitialized++;

                if(parse[5].type == NUMBER)
                { fprintf(outfile, "LOADI  %s\n",  parse[5].idop);
                  fprintf(stderr, "LOADI %s\n",  parse[5].idop);
                }
                else
                { printf("open(): syntax error\n");
                  keyhit(9);
                }

                sindex=0;

                fprintf(outfile, "OPEN\n");
                fprintf(stderr, "OPEN\n");

                {  checkvar( parsecopy[0].idop , 47);
                   fprintf(outfile, "POPD %s\n", parsecopy[0].idop);
                   fprintf(outfile, "POP\n");
                   fprintf(outfile, "POP\n");
                }
              ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 480 "ecomp.y"
    { sindex=0; 
              ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 486 "ecomp.y"
    { int i, lcount;
                showparse(0);
printf("seek()\n");
                for (i=lcount=0; i<sindex; i++)
                { if(parse[i].type == ID)
                   { fprintf(outfile, "LOAD %s\n",  parse[i].idop);
                     fprintf(stderr, "LOAD %s\n",  parse[i].idop);
                     checkvar( parse[i].idop,  10 );
                     lcount++;
                   }
                   else if(parse[i].type == NUMBER)
                   { fprintf(outfile, "LOADI %s\n",  parse[i].idop);
                     fprintf(stderr, "LOADI %s\n",  parse[i].idop);
                     lcount++;
                   }

                }

                fprintf(outfile, "SEEK\n");
                for(i=0; i<lcount; i++) 
                   fprintf(outfile, "POP\n");
                sindex=0;
              ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 513 "ecomp.y"
    { int i, lcount;
                showparse(0);

                checkvar( parse[1].idop,  10 );
                fprintf(outfile, "LOAD  %s\n",  parse[1].idop);
                fprintf(outfile, "READ\n");
                checkvar( parse[3].idop,  10 );
                fprintf(outfile, "POPD %s\n",  parse[3].idop);
                fprintf(outfile, "POP\n");
                sindex=0;
//keyhit(99);
              ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 529 "ecomp.y"
    { int i, lcount;
                showparse(0);
                for (i=lcount=0; i<sindex; i++)
                { if(parse[i].type == ID)
                   { fprintf(outfile, "LOAD %s\n",  parse[i].idop);
                     fprintf(stderr, "LOAD %s\n",  parse[i].idop);
                     checkvar( parse[i].idop,  10 );
                     lcount++;
                   }
                }
                fprintf(outfile, "WRITE\n");
                for(i=0; i<lcount; i++)
                     fprintf(outfile, "POP\n");
                sindex=0;
              ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 548 "ecomp.y"
    {int i,lcount;
                 showparse(0); 
                for (i=lcount=0; i<sindex; i++)
                { if(parse[i].type == ID)
                   { fprintf(outfile, "LOAD %s\n",  parse[i].idop);
                     fprintf(stderr, "LOAD %s\n",  parse[i].idop);
                     checkvar( parse[i].idop,  10 );
                     lcount++;
                   }
                }
                sindex=0;
                fprintf(outfile, "CLOSE\n");
                for(i=0; i<lcount; i++)
                     fprintf(outfile, "POP\n");
              ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 570 "ecomp.y"
    {int i;
               showparse(0);

             for (i=0; i<sindex; i++)
             { if(parse[i].type == ID )
               { strcpy(subvars[smemloc++], parse[i].idop);
                 printf("arg sym %s\n", parse[i].idop);
                   { int i;
                     for(i=0; i<smemloc; i++)
                     { printf("locdelare: %s\n", subvars[i]);
                     }
                   }
               }
             }
              sindex=0;
             
             ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 591 "ecomp.y"
    { printf("whilestatement\n"); 
                wstackptr--;
                fprintf(outfile, "J H%d\n", wstack[wstackptr]);
                //fprintf(outfile, "whilestatement JUMP here on while() false\n"); 
                fprintf(outfile, "W%d:\n", wstack[wstackptr]);
              ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 601 "ecomp.y"
    {int i;
                printf("SUBROUTINE sindex=%d\n", sindex);
     showparse(0);
                if( sindex==0 ) i= 0;
                else i=sindex-1;
                loadcount=0;
printf(" i=%d\n", i);
                  printf("SETFP\n"); 
                  fprintf(outfile, "SETFP\n"); 
                while (i>0)
                { 
                  if(parse[i].type == ID || parse[i].type==NUMBER )
                  {  printf("LOAD %s\n",  parse[i].idop); 
                     fprintf(outfile, "LOAD %s\n",  parse[i].idop); 
                     loadcount++;
                  } 
                  i--;
                }

                 printf("CALL %s\n",  parse[i].idop); 
                 fprintf(outfile, "CALL %s\n",  parse[i].idop); 
                 for(loadcount; loadcount; loadcount--)
                  { printf("POP\n"); 
                    fprintf(outfile, "POP\n"); 
                  }
                sindex = 0; loadcount=0;
printf("------> sindex=%d\n", sindex);
                printf("SUBROUTINE END HERE sindex=%d\n", sindex);
              ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 634 "ecomp.y"
    {

              printf( " SUBRTNID: psub=%d\n", psub);
              showparse(0);

              if (psub == 1)
              { printf("%s:\n",  parse[i].idop); 
                fprintf(outfile, "%s:\n",  parse[i].idop); 
              }
          ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 648 "ecomp.y"
    {
              printf( " SUBrest:\n");
              showparse(0);
              // sindex=0; /*ko2*/
printf("subrest------> sindex=%d\n", sindex);
              printf( " SUBrest end sindex=%d:\n", sindex);
            ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 658 "ecomp.y"
    {
          printf("%s", yylval.sptr);
         ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 662 "ecomp.y"
    {
          printf("%s", yylval.sptr);
         ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 669 "ecomp.y"
    { //fprintf(outfile, "while cond := WHILE LP LB RB\n"); 
                printf("GEN_CODE while head\n");
                showparse(0);
                fprintf(outfile, "H%d:\n", wjump);
                logic(0, sindex);
                sindex = 0;

                fprintf(outfile, "JFALSE W%d\n", wjump);
                printf("JFALSE W%d\n", wjump);
                wstack[wstackptr]=wjump;
                wstackptr++;
                wjump++;
              ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 686 "ecomp.y"
    {
                //fprintf(outfile, "whilehead label:\n");
              ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 693 "ecomp.y"
    { //fprintf(outfile, "ifstatement done label ##   if false JUMP here\n");
                printf("ifstatement done label ##   if false JUMP here\n");
              ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 700 "ecomp.y"
    { //fprintf(outfile, "if cond := IF LP LB RB\n"); 
                printf("if cond := IF LP LB RB\n"); 
//showparse(0);
//keyhit(111);
               //nest=0;
                logic(0, sindex);
                //fprintf(outfile, "IF LP cond RP  code??\n");
                printf("if cond := JUMPonFalse ##\n"); 
                sindex = 0;

                fprintf(outfile, "JFALSE I%d\n", ijump);
                printf("JFALSE I%d\n", ijump);
                istack[istackptr]=ijump;
                istackptr++;
                ijump++;
              ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 720 "ecomp.y"
    {  //fprintf(outfile, "   end of rest RB:  if false JUMP here\n");
             ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 726 "ecomp.y"
    { //fprintf(outfile, "if clause end JUMP here to skip else clause\n");
             ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 733 "ecomp.y"
    { //fprintf(outfile, " true clause, JUMP over else clause\n");
                fprintf(outfile, "J E%d\n", ejump);
                printf("J E%d\n", ejump);
                estack[estackptr]=ejump;
                estackptr++;
                ejump++;

                istackptr--;
                fprintf(outfile, "I%d:\n", istack[istackptr]);
             ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 747 "ecomp.y"
    { printf("cond:= andcond ---------------\n"); 
  //showparse(0);
  //keyhit(444);
                printf("andcond  code? ---------------\n");
              ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 753 "ecomp.y"
    { printf("cond:= cond OR andcond==============\n"); 
              //sprintf( parse[sindex].idop, "%s", "OR");
              //parse[sindex].type = OR;
              //sindex++;
              //  showparse(0);
                printf("cond OR andcond code? =============\n");
              ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 762 "ecomp.y"
    { printf("cond:= cond OR andcond==============\n"); 
              //sprintf( parse[sindex].idop, "%s", "OR");
              //parse[sindex].type = OR;
              //sindex++;
               // showparse(0);
                printf("cond OR andcond code? =============\n");
              ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 773 "ecomp.y"
    { printf("andcond:= expr   expr process\n");
                //showparse(0);
                printf("expr  code??\n");
              ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 778 "ecomp.y"
    { printf("andcond:= expr AND expr\n");
                // showparse(0);
                printf("expr AND expr code??\n");
              ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 784 "ecomp.y"
    { printf("andcond:= expr AND expr\n");
                // showparse(0);
                printf("expr AND expr code??\n");
              ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 789 "ecomp.y"
    {
                showparse(0);
                thisIsNot = 1;
              ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 797 "ecomp.y"
    { fprintf(outfile, "UNLOCK\n");
               sindex = 0;
             ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 804 "ecomp.y"
    { fprintf(outfile, "LOCK\n");
               sindex = 0;
             ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 811 "ecomp.y"
    { fprintf(outfile, "HALT\n");
               sindex = 0;
             ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 819 "ecomp.y"
    { printf("assignment:= var =\n");
                printf("declr EQ assexpr  code??\n");
printf("assignment------> sindex=%d\n", sindex);
//showparse(0);
//keyhit(0);

                if(parsecopy[1].idop[0] == '[' && copysindex>1 )
                { checkvar( parsecopy[0].idop,  1);
                  fprintf(outfile, "LA   %s\n", parsecopy[0].idop);
                  fprintf(stderr, "LA   %s\n", parsecopy[0].idop);
                  if(parse[2].type == ID)
                  { 
                   if(psub)
                    fprintf(outfile,"LDFP %d\n",symloc);
                   else
                    fprintf(outfile, "LOAD %s\n",  parsecopy[2].idop);

                   fprintf(stderr, "LOAD %s\n",  parsecopy[2].idop);
                   printf("LOAD %s\n",  parsecopy[2].idop);
                   checkvar( parsecopy[2].idop, 3 );
                  }
                  else if(parse[2].type == NUMBER)
                  { fprintf(outfile, "LOADI %s\n",  parsecopy[2].idop);
                    fprintf(stderr, "LOADI %s\n",  parsecopy[2].idop);
                  }
                  if(parse[3].idop[0] != ']') 
                  { fprintf(outfile, "ERR; index in assignment\n");
                    fprintf(stderr, "ERR; index in assignment\n");
                  }
                  fprintf(outfile, "ADD\n");
                  fprintf(outfile, "ST\n");
                  //i=i+3;
                }
                else
                {  
                    checkvar( parsecopy[0].idop , 45);
       // printf("checkvartype=%d symloc=%d\n", checkvartype, symloc);
       //              keyhit(776);
                   if(checkvartype==REGISTER) 
                   {  fprintf(outfile, "STOR %s\n", parsecopy[0].idop);
                   }
                   else if(checkvartype==SUBVAR) 
                   {  fprintf(outfile, "STFP %d\n", symloc);
                   }
                   else
                   {  fprintf(outfile, "STOR %s\n", parsecopy[0].idop);
                   }
                }
printf("assignment END------> sindex=%d\n", sindex);
 
              ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 874 "ecomp.y"
    { printf("declrEQ:= declr EQ\n");
printf("declrEQ------> sindex=%d\n", sindex);
                //printf("GEN_CODE  calc store location\n");
                //fprintf(outfile, "GEN_CODE store rval to location\n");
                termcopy(0);
                showparse(0);
                sindex=0;
printf("declrEQ------> sindex=%d\n", sindex);
              ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 886 "ecomp.y"
    { printf("assexpr:= expr POSTFIX here!!!\n");
                showparse(0);
                gen_expr(0);
                sindex=0;
printf("assexpr------> sindex=%d\n", sindex);
              ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 895 "ecomp.y"
    { printf(" expr:= expr0\n");
              ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 900 "ecomp.y"
    { printf("expr:= mulexpr\n");
                // showparse(0);
                printf("mulexpr  code??\n");
              ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 905 "ecomp.y"
    { printf("expr:= expr PLUS mulexpr\n");
                // showparse(0);
                printf("expr PLUS mulexpr  code??\n");
              ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 910 "ecomp.y"
    { printf("expr:= expr MINUS mulexpr\n"); 
                // showparse(0);
                printf("expr MINUS mulexpr  code??\n");
              ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 915 "ecomp.y"
    { printf("expr:= expr GE_OP mulexpr\n"); 
                // showparse(0);
                printf("expr GE_OP mulexpr  code??\n");
              ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 920 "ecomp.y"
    { printf("expr:= expr GT_OP mulexpr\n"); 
                // showparse(0);
                printf("expr GT_OP mulexpr  code??\n");
              ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 925 "ecomp.y"
    { printf("expr:= expr LE_OP mulexpr\n"); 
                // showparse(0);
                printf("expr LE_OP mulexpr  code??\n");
              ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 930 "ecomp.y"
    { //printf("expr:= expr LT_OP mulexpr\n"); 
                // showparse(0);
                printf("expr LT_OP mulexpr  code??\n");
              ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 935 "ecomp.y"
    { printf("expr:= expr EQ_OP mulexpr\n"); 
                // showparse(0);
                printf("MINUS mulexpr  code??\n");
              ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 940 "ecomp.y"
    { printf("expr:= expr NE_OP mulexpr\n"); 
                // showparse(0);
                printf("MINUS mulexpr  code??\n");
              ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 947 "ecomp.y"
    { printf("mulexpr:= term\n");
              ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 950 "ecomp.y"
    { //printf("mulexpr:= MINUS term\n"); 
                // showparse(0);
              ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 954 "ecomp.y"
    { //printf("mulexpr:= mulexpr DIV term\n"); 
                // showparse(0);
              ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 958 "ecomp.y"
    { //printf("mulexpr:= mulexpr MUL term\n"); 
                // showparse(0);
              ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 964 "ecomp.y"
    { //fprintf(outfile, "term:= ID   %s  %d\n", yylval.sptr, sindex);  
printf("termDBLQT------> %s sindex=%d\n", yylval.sptr, sindex);
             // sprintf( parse[sindex].idop, "%s", yylval.sptr);
             // parse[sindex].type = ID;
             // sindex++;
            ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 973 "ecomp.y"
    { //fprintf(outfile, "term:= ID   %s  %d\n", yylval.sptr, sindex);  
printf("termID------> %s sindex=%d\n", yylval.sptr, sindex);
              sprintf( parse[sindex].idop, "%s", yylval.sptr);
              parse[sindex].type = ID;
              sindex++;
            ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 980 "ecomp.y"
    { //fprintf(outfile, "term:= NUMBER   %s  %d\n", yylval.sptr, sindex);  
printf("termNUMBER------> sindex=%d\n", sindex);
              sprintf( parse[sindex].idop, "%s", yylval.sptr);
              parse[sindex].type = NUMBER;
              sindex++;
            ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 989 "ecomp.y"
    {
printf("dblqt------> %s sindex=%d\n", yylval.sptr, sindex);
              sprintf( parse[sindex].idop, "%s", yylval.sptr);
              parse[sindex].type = ID;
              sindex++;
            ;}
    break;



/* Line 1455 of yacc.c  */
#line 2803 "ecomp.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 997 "ecomp.y"


void yyerror(char *s) {
 extern unsigned int linenumber;
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "line %d:  %s\n", linenumber+1, yytext);
    return;
}

main(int argc, char **argv )
{
    ++argv, --argc;  /* skip over program name */
    if ( argc == 2 )
    {        yyin = fopen( argv[0], "r" );
             outfile = fopen( argv[1], "w");
    }
    else
            yyin = stdin;


    yyparse();

    fclose(outfile);
    return 0;

}

int checkvar(char *var, int loc)
{ int i,j;

 printf("var=%s   called from %d\n", var,  loc);

  if( psub == 1)
  {
   for(i=0; i<smemloc; i++)
   {
    if ( *var == 'r' && (  *(var+1) >= '0' &&  *(var+1) <= '9')  )
    {
printf("register symloc= %d\n", symloc);
//keyhit(90);
     checkvartype=REGISTER;
     return (0);
    }
     j=strcmp(subvars[i], var);
     printf("%s [%d],   var=%s  comp_result=%d  called from %d\n", 
                subvars[i], i, var,  j, loc);
     if ( j == 0 )
       { symloc = i; 
         checkvartype=SUBVAR;
printf("SUBVAR var loc = %d\n", symloc);
//keyhit(91);
         return (0);
       }
   } /*** End for(i=0; i<smemloc; i++) ***/
  }

  for(i=0; i<nglob; i++)
  {
     j=strcmp(glovars[i], var);
    //fprintf(outfile, "%s %s  [%d] %d  loc=%d\n", glovars[i], var, i, j , loc);
     if ( j == 0 )
       { symloc = i; 
         checkvartype=GLOBALVAR;
         return (0);
       }
  }
  if ( *var == 'r' && (  *(var+1) >= '0' &&  *(var+1) <= '9')  )
  { checkvartype = REGISTER; 
   return (0);
  }

  fprintf(outfile, "var not declared :: %s\n", var);
  fprintf(stderr, "var not declared :: %s\n", var);
  return (1);
}

int gen_expr(int beg)
{int i, stckptr;
 int stck[20];

//for(i=0; i<sindex; i++)
//  fprintf(outfile, "assignment %s     %d\n", parsecopy[i].idop,parsecopy[i].type);


 showparse(0);

 i = beg;
 stckptr = 0;
   while( parse[i].type != SEMICOL )
   {
    if( parse[i].type == ID )
     {   
printf("-->parse[%d].idop = %s\n", i, parse[i].idop);
         checkvar( parse[i].idop , 7);
         if(parse[i+1].idop[0] == '[' && sindex > i)
         //if(parse[i+1].idop[0] == '[' )
         {
           fprintf(outfile, "LA   %s\n", parse[i].idop);
           fprintf(stderr, "LA   %s\n", parse[i].idop);
           if(parse[i+2].type == ID)
           { 
             fprintf(stderr, "LOAD %s\n",  parse[i+2].idop);
             printf("LOAD %s dbg776\n",  parse[i+2].idop);
              if(psub)
                fprintf(outfile, "LDFP %d\n", symloc);
              else
                { fprintf(outfile, "LOAD %s\n",  parse[i+2].idop);
                printf("LOAD %s   dbg777\n",  parse[i+2].idop);
         //keyhit(7777);
                }
             checkvar( parse[i+2].idop ,  8);
             i=i+2;
           }
           else if(parse[i+2].type == NUMBER)
           { fprintf(outfile, "LOADI %s\n",  parse[i+2].idop);
             fprintf(stderr, "LOADI %s\n",  parse[i+2].idop);
           i=i+2;
           }
           if(parse[i+1].idop[0] != ']') 
           { fprintf(outfile, "ERR; index\n");
             fprintf(stderr, "ERR; index\n");

printf("-->parse[%d].idop = %s\n", i, parse[i].idop);
showparse(0);
keyhit(81);

           i=i+3;
           }
           fprintf(outfile, "ADD\n");
           fprintf(outfile, "LD\n");
         }
         else
         {
 printf("register type\n");
           if( checkvartype==REGISTER )
            fprintf(outfile,"LOAD %s\n", parse[i].idop);
           else if(psub  && (checkvartype==SUBVAR))
            fprintf(outfile,"LDFP %d\n",symloc);
           else
            { fprintf(outfile,"LOAD %s\n",  parse[i].idop);
         //printf("LOAD 88 %s\n",  parse[i].idop);
            }
         }
     }
    else if( parse[i].type == NUMBER )
     {  fprintf(outfile, "LOADI %s\n", parse[i].idop);
     }
    else if( (parse[i].type == PLUS) || (parse[i].type == MINUS) )
     {
        if (stckptr == 0 && i != 0) 
          {  stck[stckptr++] = parse[i].type;
          }
        else if(( stck[stckptr-1] == MUL) || stck[stckptr-1] == DIV)
          { fprintf(outfile, "MUL DIV---\n");
            stck[stckptr-1] = parse[i].type;
          }
        else if (i == 0 )  /* unary + - */
          {  fprintf(outfile, "LOADI 0\n");
             stck[stckptr++] = parse[i].type;
          }
        else
          { //stck[--stckptr]=str[i];
            if( stck[stckptr-1] == PLUS )
               { fprintf(outfile, "ADD\n");
               }
            else if (stck[stckptr-1] == MINUS )
               { fprintf(outfile, "SUB\n");
               }
            stck[ stckptr-1] = parse[i].type;
          }
     }
    else   /*   it is '*' ||  '/'    */
     {    if( stckptr ==0  )
          {  stck[stckptr++] = parse[i].type;
          }
          else if( stck[stckptr-1] == PLUS || stck[stckptr-1] == MINUS )
          {  stck[stckptr++] = parse[i].type;
          }
          else
          { if( stck[stckptr-1] == MUL) fprintf(outfile, "MUL..\n");
            if( stck[stckptr-1] == DIV) fprintf(outfile, "DIV..\n");
            stck[stckptr-1] = parse[i].type;
          }
     }
     i++;

   }
  printf(" stckptr=%d\n", stckptr);
  for (i=0; i<stckptr; i++)
  { printf("%d\n", stck[i]);
  }
  printf("\n");
   while ( --stckptr >= 0 )
   { if (stck[stckptr] == PLUS)  fprintf(outfile, "ADD\n");
     else if (stck[stckptr] == MUL)   fprintf(outfile, "MUL\n");
     else if (stck[stckptr] == MINUS) fprintf(outfile, "SUB\n");
     else if (stck[stckptr] == DIV)   fprintf(outfile, "DIV\n");
   }
}

int showstck(int *stck, int end)
{ int i;
  printf("show stack ------------------------------------\n");
  for(i=0; i< end; i++)
  { printf("%d\n", *(stck+i));
  }
  printf("end stack----------------------------------------\n");
}


int logic(int beg, int end)
{int i, j, k, stckptr; int stck[20];

 i=stckptr = 0;
 for (i=beg; i<sindex; )
 {  printf("i=%d  %s, (type)%d\n", i, parse[i].idop, parse[i].type);
    if( (parse[i].type == AND) || (parse[i].type ==  OR) || 
     (parse[i].type ==  NOT) || (parse[i].type ==  LP)   ) 
    {  stck[stckptr++] = parse[i].type;
showstck(stck,stckptr);
//keyhit(909);
    }
    else if( parse[i].type == ID  )
    {  checkvar( parse[i].idop, 9 );
         if(parse[i+1].idop[0] == '[' && sindex > i)
         // if(parse[i+1].idop[0] == '[' )
         { fprintf(outfile, "LA   %s\n", parse[i].idop);
           fprintf(stderr, "LA   %s\n", parse[i].idop);
           if(parse[i+2].type == ID)
           { fprintf(outfile, "LOAD %s\n",  parse[i+2].idop);
             fprintf(stderr, "LOAD %s\n",  parse[i+2].idop);
             checkvar( parse[i+2].idop,  10 );
           }
           else if(parse[i+2].type == NUMBER)
           { fprintf(outfile, "LOADI %s\n",  parse[i+2].idop);
             fprintf(stderr, "LOADI %s\n",  parse[i+2].idop);
           }
           if(parse[i+3].idop[0] != ']') 
           { fprintf(outfile, "ERR; index in logic\n");
             fprintf(stderr, "ERR; index in logic\n");
           }
           fprintf(outfile, "ADD\n");
           fprintf(outfile, "LD\n");
           i=i+3;
         }
         else
         {
           fprintf(outfile, "LOAD %s\n", parse[i].idop);
         }
    }
    else if( parse[i].type == NUMBER )
    { fprintf(outfile, "LOADI %s\n", parse[i].idop);
    }
    else if( (parse[i].type == LE_OP) || (parse[i].type ==  GE_OP) || 
     (parse[i].type ==  LT_OP) || (parse[i].type ==  GT_OP) ||
     (parse[i].type ==  EQ_OP) || (parse[i].type ==  NE_OP)   ) 
    { stck[stckptr++] = parse[i].type;
showstck(stck,stckptr);
    }
    else if( parse[i].type ==  RP ) 
    {
printf("RP hit\n");
       do{
showstck(stck,stckptr);
          stckptr--;
printf("stck[%d]=%d\n", stckptr, stck[stckptr]);
//keyhit(98);

          if( stck[stckptr]== LP || stckptr==0 )
          { break;
          }
          else if(stck[stckptr] == LE_OP )
          { fprintf(outfile, "LE\n");
          printf("LE\n");
          }
          else if(stck[stckptr] ==  GE_OP)  
          { fprintf(outfile, "GE\n");
          printf("GE lable\n");
          }
          else if(stck[stckptr] ==  LT_OP) 
          { fprintf(outfile, "LT\n");
          printf("LT\n");
          }
          else if(stck[stckptr] ==  GT_OP) 
          { fprintf(outfile, "GT\n");
          printf("GT\n");
          }
          else if(stck[stckptr] ==  EQ_OP) 
          { fprintf(outfile, "EQ\n");
          printf("EQ\n");
          }
          else if(stck[stckptr] ==  NE_OP) 
          { fprintf(outfile, "NE\n");
          printf("NE\n");
//keyhit(91);
          }
          else if( stck[stckptr]== AND )
          { fprintf(outfile, "AND\n");
          printf("AND\n");
          }
          else if( stck[stckptr]== OR )
          { fprintf(outfile, "OR\n");
           printf("OR\n");
          }
          else if( stck[stckptr]== NOT )
          { fprintf(outfile, "NOT\n");
           printf("NOT\n");
              //  if (thisIsNot ==1 ) fprintf(outfile, "NOT\n");
            thisIsNot =0;
          }
          else
          { printf("error\n");
          }
             
       } while (1);
showstck(stck,stckptr);
//keyhit(92);
    }
  i++;
 }
}

