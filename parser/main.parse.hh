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

#ifndef YY_YY_PARSER_MAIN_PARSE_HH_INCLUDED
# define YY_YY_PARSER_MAIN_PARSE_HH_INCLUDED
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
    VAR = 261,                     /* VAR  */
    PRINT = 262,                   /* PRINT  */
    FUNC = 263,                    /* FUNC  */
    FOR = 264,                     /* FOR  */
    WHILE = 265,                   /* WHILE  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    RETURN = 268,                  /* RETURN  */
    ADD = 269,                     /* ADD  */
    SUB = 270,                     /* SUB  */
    MUL = 271,                     /* MUL  */
    DIV = 272,                     /* DIV  */
    MOD = 273,                     /* MOD  */
    ASSIGN = 274,                  /* ASSIGN  */
    INCREASE = 275,                /* INCREASE  */
    DECREASE = 276,                /* DECREASE  */
    ADDASSIGN = 277,               /* ADDASSIGN  */
    SUBASSIGN = 278,               /* SUBASSIGN  */
    EQUAL = 279,                   /* EQUAL  */
    NOTEQUAL = 280,                /* NOTEQUAL  */
    LESS = 281,                    /* LESS  */
    GREATER = 282,                 /* GREATER  */
    LESSEQUAL = 283,               /* LESSEQUAL  */
    GREATEREQUAL = 284,            /* GREATEREQUAL  */
    AND = 285,                     /* AND  */
    OR = 286,                      /* OR  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    LBRACE = 289,                  /* LBRACE  */
    RBRACE = 290,                  /* RBRACE  */
    SEMICOLON = 291,               /* SEMICOLON  */
    EOL = 292                      /* EOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "parser/main.yy"

    int inum;       // For integer literals
    float fnum;     // For float literals
    std::string* str; // For identifiers and strings
    Node* node;     // For AST nodes
    Statement* stmt;     // For AST nodes
    Expr* expr;     // For expressions
    Value* val;
    std::vector<Id*>* args;
    std::vector<Statement*>* body;
    Id* IDENTIFIER;

#line 114 "parser/main.parse.hh"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_MAIN_PARSE_HH_INCLUDED  */
