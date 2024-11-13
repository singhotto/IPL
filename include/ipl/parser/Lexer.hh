#ifndef LEXER_HH
#define LEXER_HH

#include <iostream>
#include <string>
#include <FlexLexer.h>

class Lexer : public yyFlexLexer {
public:
    Lexer(std::istream* in) : yyFlexLexer(in) {}
    int yylex();
};

#endif // LEXER_HH
