%{
#include "main.hh"
#include "main.parse.hh"
#include <iostream>
#include <string>
#include <memory>

// Declare external lexer functions
extern int yylex();
extern int yyparse();
extern void yyerror(const char* s);

Interpreter& eval = Interpreter::getInstance();
%}

%union {
    int inum;       // For integer literals
    float fnum;     // For float literals
    std::string* str; // For identifiers and strings
    Node* node;     // For AST nodes
    Statement* stmt; // For AST statements
    Expr* expr;     // For expressions
    Value* val;     // For values
    std::vector<Id*>* args;
    std::vector<Statement*>* body;
    Id* IDENTIFIER;
}

// Token declarations
%token <inum> INTEGER
%token <fnum> FLOAT
%token <str> ID
%token <str> STRING

%token VAR PRINT FUNC FOR WHILE IF ELSE RETURN True False
%token ADD SUB MUL DIV MOD ASSIGN 
%token INCREASE DECREASE ADDASSIGN SUBASSIGN
%token EQUAL NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL
%token AND OR LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA EOL

// Non-terminal declarations
%type <node> program stmt_list
%type <stmt> stmt
%type <expr> expr
%type <IDENTIFIER> IDENTIFIER

%left ADD SUB
%left MUL DIV MOD

%%
program:
      program EOL
    | program stmt_list EOL
    | stmt EOL { eval.visit($1); }
    ;

stmt_list:
    stmt_list stmt { eval.visit($2); }
    | stmt { eval.visit($1); }
    ;

stmt:
    VAR IDENTIFIER ASSIGN expr SEMICOLON {
        $$ = IPLFactory::createDefVar(U(Id, $2), U(Expr, $4));
    }
    | PRINT LPAREN expr RPAREN SEMICOLON {
        $$ = IPLFactory::createPrintExpr(U(Expr, $3));
    }
    | RETURN expr SEMICOLON {
        $$ = IPLFactory::createReturnStmt(U(Expr, $2));
    }
    ;

IDENTIFIER:
    ID { $$ = IPLFactory::createId(*$1); delete $1; }
    ;

expr:
    expr ADD expr { $$ = IPLFactory::createAddExpr(U(Expr, $1), U(Expr, $3)); }
    | expr SUB expr { $$ = IPLFactory::createSubtExpr(U(Expr, $1), U(Expr, $3)); }
    | expr MUL expr { $$ = IPLFactory::createMulExpr(U(Expr, $1), U(Expr, $3)); }
    | expr DIV expr { $$ = IPLFactory::createDivExpr(U(Expr, $1), U(Expr, $3)); }
    | expr MOD expr { $$ = IPLFactory::createModExpr(U(Expr, $1), U(Expr, $3)); }
    | LPAREN expr RPAREN { $$ = $2; }
    | expr EQUAL expr { $$ = IPLFactory::createEqual(U(Expr, $1), U(Expr, $3)); }
    | expr NOTEQUAL expr { $$ = IPLFactory::createNotEqual(U(Expr, $1), U(Expr, $3)); }
    | expr LESS expr { $$ = IPLFactory::createLess(U(Expr, $1), U(Expr, $3)); }
    | expr GREATER expr { $$ = IPLFactory::createGreater(U(Expr, $1), U(Expr, $3)); }
    | expr LESSEQUAL expr { $$ = IPLFactory::createLessEqual(U(Expr, $1), U(Expr, $3)); }
    | expr GREATEREQUAL expr { $$ = IPLFactory::createGreaterEqual(U(Expr, $1), U(Expr, $3)); }
    | expr AND expr { $$ = IPLFactory::createAnd(U(Expr, $1), U(Expr, $3)); }
    | expr OR expr { $$ = IPLFactory::createOr(U(Expr, $1), U(Expr, $3)); }
    | INTEGER { $$ = IPLFactory::createInt($1); }
    | FLOAT { $$ = IPLFactory::createFloat($1); }
    | STRING { $$ = IPLFactory::createString(*$1); }
    | IDENTIFIER { $$ = $1; }
    ;

%%


int main(){
    return yyparse();
}