#include "tokenizer.h"
#include <cctype>

Tokenizer::Tokenizer(const std::string& input) : input(input), pos(0) {}

std::vector<Token> Tokenizer::tokenize() {
    std::vector<Token> tokens;
    while (pos < input.length()) {
        skipWhitespace();
        if (pos >= input.length()) break;
        tokens.push_back(getNextToken());
    }
    return tokens;
}

char Tokenizer::peek() {
    return pos < input.length() ? input[pos] : '\0';
}

char Tokenizer::advance() {
    return input[pos++];
}

void Tokenizer::skipWhitespace() {
    while (pos < input.length() && isspace(input[pos])) {
        pos++;
    }
}

Token Tokenizer::getNextToken() {
    if (input.compare(pos, 5, "BEGIN") == 0) {
        pos += 5;
        return {TokenType::BEGIN, "BEGIN"};
    }
    if (input.compare(pos, 3, "END") == 0) {
        pos += 3;
        return {TokenType::END, "END"};
    }
    if (isalpha(peek())) {
        std::string value;
        while (isalnum(peek())) value += advance();
        return {TokenType::IDENTIFIER, value};
    }
    if (isdigit(peek())) {
        std::string value;
        while (isdigit(peek())) value += advance();
        return {TokenType::NUMBER, value};
    }
    return {TokenType::UNKNOWN, std::string(1, advance())};
}