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
    Statement* stmt;     // For AST nodes
    Expr* expr;     // For expressions
    Value* val;
    std::vector<Id*>* args;
    std::vector<Statement*>* body;
    Id* IDENTIFIER;
}

// Token declarations
%token <inum> INTEGER
%token <fnum> FLOAT
%token <str> ID
%token <str> STRING


%token VAR PRINT FUNC FOR WHILE IF ELSE RETURN
%token ADD SUB MUL DIV MOD ASSIGN
%token INCREASE DECREASE ADDASSIGN SUBASSIGN
%token EQUAL NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL
%token AND OR LPAREN RPAREN LBRACE RBRACE SEMICOLON
%token EOL

// Non-terminal declarations
%type <node> program stmt_list 
%type <stmt> stmt 
%type <expr>  expr
%type <IDENTIFIER>  IDENTIFIER

%left ADD SUB
%left MUL DIV MOD

%%
program:
    
    | program EOL
    | program stmt_list EOL
    | stmt EOL { eval.visit($1); }
    ;

stmt_list:
    stmt_list stmt { eval.visit($2); }
    | stmt { eval.visit($1); }
;

stmt:
    VAR IDENTIFIER ASSIGN expr SEMICOLON {
        // Create a variable definition node
        $$ = IPLFactory::createDefVar(U(Id, $2), U(Expr, $4));
    }
    | PRINT LPAREN expr RPAREN SEMICOLON {
        // Create a print statement node 
        $$ = IPLFactory::createPrintExpr(U(Expr, $3));
    }
    | RETURN expr SEMICOLON {
        // Create a return statement node
        $$ = IPLFactory::createReturnStmt(U(Expr, $2));
    }
;

IDENTIFIER: 
    ID { $$ = IPLFactory::createId(*$1); delete $1; }
    ;

expr:
    expr ADD expr {
        // Create an addition expression node
        $$ = IPLFactory::createAddExpr(U(Expr, $1), U(Expr, $3));
    }
    | expr SUB expr {
        // Create a subtraction expression node
        $$ = IPLFactory::createSubtExpr(U(Expr, $1), U(Expr, $3));
    }
    | expr MUL expr {
        // Create a multiplication expression node
        $$ = IPLFactory::createMulExpr(U(Expr, $1), U(Expr, $3));
    }
    | expr DIV expr {
        // Create a division expression node
        $$ = IPLFactory::createDivExpr(U(Expr, $1), U(Expr, $3));
    }
    | expr MOD expr {
        // Create a modulus expression node
        $$ = IPLFactory::createModExpr(U(Expr, $1), U(Expr, $3));
    }
    | LPAREN expr RPAREN {
        // Parenthesized expression
        $$ = $2;
    }
    | INTEGER {
        // Create an integer literal node
        $$ = IPLFactory::createInt($1);
    }
    | FLOAT {
        // Create a float literal node
        $$ = IPLFactory::createFloat($1);
    }
    | STRING {
        // Create a string literal node
        $$ = IPLFactory::createString(*$1);
    }
    |  IDENTIFIER { 
        $<IDENTIFIER>$ = $1; 
    }
;

%%

// Main function
int main() {
    return yyparse();
}