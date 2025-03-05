#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"
#include <vector>

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    bool parse();
    
private:
    std::vector<Token> tokens;
    size_t pos;

    bool match(TokenType type);
};

#endif