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
"="          { return ASSIGN; }
","          { return COMMA; }
";"          { return SEMICOLON; }

"++"          { return INCREASE; }
"--"          { return DECREASE; }
"+="          { return ADDASSIGN; }
"-="          { return SUBASSIGN; }
"*="          { return MULASSIGN; }
"/="          { return DIVASSIGN; }

"=="          { return EQUAL; }
"!="          { return NOTEQUAL; }
"<"           { return LESS; }
">"           { return GREATER; }
"<="          { return LESSEQUAL; }
">="          { return GREATEREQUAL; }

"&&"          { return AND; }
"||"          { return OR; }

"var"         { return VAR; }
"print"       { return PRINT; }
"function"        { return FUNC; }
"for"         { return FOR;}
"while"       { return WHILE;}
"if"          { return IF; }
"else"        { return ELSE; }
"return"      { return RETURN; }
"true"        { return True; }
"false"       { return False; }

{ID}          { yylval.str = new std::string(yytext); return ID; }
{INT}         { yylval.inum = atoi(yytext); return INTEGER; }
{FLOAT}       { yylval.fnum = atof(yytext); return FLOAT; }
{STRING}      { yylval.str = new std::string(yytext); return STRING; }

"\n"          { /* ignore new line */ }

"//".*        { /* ignore comments */ }
[ \t]         { /* ignore whitespace */ }
.             {
                auto msg = std::string("Unknown character: ") + *yytext;
                yyerror(msg.c_str());
              }

%%

