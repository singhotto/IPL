#ifndef PARSER_HH
#define PARSER_HH

#include "Lexer.hh"
#include <iostream>

class Parser {
public:
    Parser(Lexer* lexer);
    void parse();  // This method will initiate the parsing process.
};

#endif // PARSER_HH
