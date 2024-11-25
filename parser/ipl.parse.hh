/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_USERS_SINGHOTTO_DOCUMENTS_IPL_PARSER_IPL_PARSE_HH_INCLUDED
# define YY_YY_USERS_SINGHOTTO_DOCUMENTS_IPL_PARSER_IPL_PARSE_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    FLOAT = 259,                   /* FLOAT  */
    ID = 260,                      /* ID  */
    STRING = 261,                  /* STRING  */
    VAR = 262,                     /* VAR  */
    PRINT = 263,                   /* PRINT  */
    FUNC = 264,                    /* FUNC  */
    FOR = 265,                     /* FOR  */
    WHILE = 266,                   /* WHILE  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    RETURN = 269,                  /* RETURN  */
    True = 270,                    /* True  */
    False = 271,                   /* False  */
    ADD = 272,                     /* ADD  */
    SUB = 273,                     /* SUB  */
    MUL = 274,                     /* MUL  */
    DIV = 275,                     /* DIV  */
    MOD = 276,                     /* MOD  */
    ASSIGN = 277,                  /* ASSIGN  */
    INCREASE = 278,                /* INCREASE  */
    DECREASE = 279,                /* DECREASE  */
    ADDASSIGN = 280,               /* ADDASSIGN  */
    SUBASSIGN = 281,               /* SUBASSIGN  */
    MULASSIGN = 282,               /* MULASSIGN  */
    DIVASSIGN = 283,               /* DIVASSIGN  */
    EQUAL = 284,                   /* EQUAL  */
    NOTEQUAL = 285,                /* NOTEQUAL  */
    LESS = 286,                    /* LESS  */
    GREATER = 287,                 /* GREATER  */
    LESSEQUAL = 288,               /* LESSEQUAL  */
    GREATEREQUAL = 289,            /* GREATEREQUAL  */
    AND = 290,                     /* AND  */
    OR = 291,                      /* OR  */
    LPAREN = 292,                  /* LPAREN  */
    RPAREN = 293,                  /* RPAREN  */
    LBRACE = 294,                  /* LBRACE  */
    RBRACE = 295,                  /* RBRACE  */
    SEMICOLON = 296,               /* SEMICOLON  */
    COMMA = 297                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "/Users/singhotto/Documents/IPL/parser/ipl.yy"

    int inum;       // For integer literals
    float fnum;     // For float literals
    std::string* str; // For identifiers and strings
    Node* node;     // For AST nodes
    Statement* stmt; // For AST statements
    Expr* expr;     // For expressions
    Value* val;     // For values
    std::vector<Id*>* args;
    StmtsVec* sBody;
    ExprVec* sExprList;
    IdVec* sIdList;
    Id* IDENTIFIER;

#line 121 "/Users/singhotto/Documents/IPL/parser/ipl.parse.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_USERS_SINGHOTTO_DOCUMENTS_IPL_PARSER_IPL_PARSE_HH_INCLUDED  */
