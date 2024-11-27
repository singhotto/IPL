%{
#include "ipl.hh"
#include "ipl.parse.hh"
#include <iostream>
#include <string>
#include <memory>

// Declare external lexer functions
extern int yylex();
extern int yyparse();
extern int yyerror(const char* s);
extern int yylineno;

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
    StmtsVec* sBody;
    ExprVec* sExprList;
    IdVec* sIdList;
    Id* IDENTIFIER;
}

// Token declarations
%token <inum> INTEGER
%token <fnum> FLOAT
%token <str> ID
%token <str> STRING

%token VAR PRINT FUNC FOR WHILE IF ELSE RETURN TRUE FALSE
%token ADD SUB MUL DIV MOD ASSIGN 
%token INCREASE DECREASE ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN
%token EQUAL NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL
%token AND OR LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA

// Non-terminal declarations
%type <node> program
%type <stmt> stmt_no_semicolon stmt_semicolon var_decl var_assign func_decl
%type <expr> expr func_call
%type <IDENTIFIER> IDENTIFIER
%type <sBody> body
%type <sExprList> expr_list
%type <sIdList> func_args

%right ASSIGN 
%left OR
%left AND
%nonassoc EQUAL NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL
%left ADD SUB
%left MUL DIV MOD


%%
program:
    /*blank*/
    | body { 
        Block* b = new Block(*$1);
        eval.visit(b); 
        delete b;
    }
    ;

body:
    /*blank*/  { $$ = new StmtsVec(); }
    | stmt_semicolon { $$ = new StmtsVec(); $$->push_back($1); }
    | body stmt_semicolon { $1->push_back($2); }
    | stmt_no_semicolon { $$ = new StmtsVec(); $$->push_back($1); }
    | body stmt_no_semicolon { $1->push_back($2); }
    ;

stmt_no_semicolon:
    func_decl
    | IF LPAREN expr RPAREN LBRACE body RBRACE {
        $$ = IPLFactory::createIfcond(U(Expr, $3), *$6);
        delete $6;
    }
    | IF LPAREN expr RPAREN LBRACE body RBRACE ELSE LBRACE body RBRACE {
        $$ = IPLFactory::createIfelse(U(Expr, $3), *$6, *$10);
        delete $6;
        delete $10;
    }
    | FOR LPAREN stmt_semicolon expr SEMICOLON var_assign RPAREN LBRACE body RBRACE {
        $$ = IPLFactory::createForLoop(U(Statement, $3), U(Expr, $4), U(Statement, $6), *$9);
        delete $9;
    }
    | WHILE LPAREN expr RPAREN LBRACE body RBRACE {
        $$ = IPLFactory::createWhile(U(Expr, $3), *$6);
        delete $6;
    }
    ;

stmt_semicolon:
    var_decl SEMICOLON | var_assign SEMICOLON | func_call SEMICOLON
    | PRINT LPAREN expr_list RPAREN SEMICOLON {
        $$ = IPLFactory::createPrintExpr(*$3);
        delete $3;
    }
    | RETURN expr SEMICOLON {
        $$ = IPLFactory::createReturnStmt(U(Expr, $2));
    }
    ;

func_decl:
    FUNC IDENTIFIER LPAREN func_args RPAREN LBRACE body RBRACE {
        $$ = IPLFactory::createDefFunc(U(Id, $2), *$4, *$7);
        delete $4;
        delete $7;
    }
    ;

func_call:
    | IDENTIFIER LPAREN expr_list RPAREN {
        $$ = IPLFactory::createCallFunc(U(Id, $1), *$3);
        delete $3;
    }
    ;

func_args:
    /*blank*/  { $$ = new IdVec(); }
    | IDENTIFIER { $$ = new IdVec(); $$->push_back($1); }
    | func_args COMMA IDENTIFIER { $$->push_back($3); }
    ;


var_decl: 
    VAR IDENTIFIER {
        $$ = IPLFactory::createDefVar(U(Id, $2));
    }
    | VAR IDENTIFIER ASSIGN expr {
        $$ = IPLFactory::createDefVar(U(Id, $2), U(Expr, $4));
    }
    | VAR IDENTIFIER ASSIGN func_call {
        $$ = IPLFactory::createDefVar(U(Id, $2), U(Expr, $4));
    }
    ;
    
var_assign:
    IDENTIFIER ASSIGN expr {
        $$ = IPLFactory::createAssign(U(Id, $1), U(Expr, $3));
    }
    | IDENTIFIER ASSIGN func_call {
        $$ = IPLFactory::createAssign(U(Id, $1), U(Expr, $3));
    }
    | IDENTIFIER INCREASE {
        $$ = IPLFactory::createIncrease(U(Id, $1));
    }
    | IDENTIFIER DECREASE {
        $$ = IPLFactory::createDecrease(U(Id, $1));
    }
    | IDENTIFIER ADDASSIGN expr {
        $$ = IPLFactory::createAddAssign(U(Id, $1), U(Expr, $3));
    }
    | IDENTIFIER SUBASSIGN expr {
        $$ = IPLFactory::createSubAssign(U(Id, $1), U(Expr, $3));
    }
    | IDENTIFIER MULASSIGN expr {
        $$ = IPLFactory::createMulAssign(U(Id, $1), U(Expr, $3));
    }
    | IDENTIFIER DIVASSIGN expr {
        $$ = IPLFactory::createDivAssign(U(Id, $1), U(Expr, $3));
    }
    ;

IDENTIFIER:
    ID { $$ = IPLFactory::createId(*$1); delete $1; }
    ;

expr_list:
    /*blank*/ { $$ = new ExprVec(); }
    | expr { $$ = new ExprVec(); $$->push_back($1); }
    | expr_list COMMA expr { $$->push_back($3); }

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
    | INTEGER { $$ = IPLFactory::createFloat($1); }
    | FLOAT { $$ = IPLFactory::createFloat($1); }
    | STRING { $$ = IPLFactory::createString(*$1); }
    | IDENTIFIER { $$ = $1; }
    ;

%%