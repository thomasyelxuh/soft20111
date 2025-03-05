#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

enum class TokenType {
    BEGIN, END, IDENTIFIER, NUMBER, UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

class Tokenizer {
public:
    explicit Tokenizer(const std::string& input);
    std::vector<Token> tokenize();

private:
    std::string input;
    size_t pos;
    
    char peek();
    char advance();
    void skipWhitespace();
    Token getNextToken();
};

#endif