#include "parser.h"

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

bool Parser::match(TokenType type) {
    if (pos < tokens.size() && tokens[pos].type == type) {
        pos++;
        return true;
    }
    return false;
}

bool Parser::parse() {
    if (!match(TokenType::BEGIN)) return false;
    while (pos < tokens.size() && tokens[pos].type == TokenType::IDENTIFIER) {
        pos++;
    }
    return match(TokenType::END);
}