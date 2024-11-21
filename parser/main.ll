%{

#include "main.hh"
#include "main.parse.hh"
#include <string>

%}

%option noyywrap nodefault nounput yylineno

ID     [a-zA-Z_][a-zA-Z0-9_]*
DIGITS [0-9]+
FRAC   ({DIGITS}?"."{DIGITS})|({DIGITS}".")
EXP    [Ee][-+]?{DIGITS}
FLOAT  {FRAC}{EXP}?
INT    {DIGITS}
STRING \"(\\.|[^\"])*\"

%%

"("          { return LPAREN; }
")"          { return RPAREN; }
"{"          { return LBRACE; }
"}"          { return RBRACE; }
"+"          { return ADD; }
"-"          { return SUB; }
"*"          { return MUL; }
"/"          { return DIV; }
"%"          { return MOD; }
"="            { return ASSIGN; }
";"            { return SEMICOLON; }

"++"        { return INCREASE; }
"--"        { return DECREASE; }
"+="        { return ADDASSIGN; }
"-="        { return SUBASSIGN; }

"=="        { return EQUAL; }
"!="        { return NOTEQUAL; }
"<"         { return LESS; }
">"         { return GREATER; }
"<="         { return LESSEQUAL; }
">="         { return GREATEREQUAL; }

"&&"         { return AND; }
"||"         { return OR; }

"var"          { return VAR; }
"print"        { return PRINT; }
"func"        { return FUNC; }
"for"         { return FOR;}
"while"         { return WHILE;}
"if"          { return IF; }
"else"        { return ELSE; }
"return"      { return RETURN; }

{ID}          { yylval.str = new std::string(yytext); return ID; }
{INT}         { yylval.inum = atoi(yytext); return INTEGER; }
{FLOAT}       { yylval.fnum = atof(yytext); return FLOAT; }

"\n"          { return EOL; }

"//".*        { /* ignore comments */ }
[ \t]         { /* ignore whitespace */ }
.             {
                auto msg = std::string("Unknown character: ") + *yytext;
                yyerror(msg.c_str());
              }

%%

