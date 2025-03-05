#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    BEGIN,      // Represents "BEGIN" keyword
    END,        // Represents "END" keyword
    IDENTIFIER, // Represents variable names or user-defined symbols
    NUMBER,     // Represents numeric values
    UNKNOWN     // Represents an unrecognized token
};

struct Token {
    TokenType type;   // The type of the token
    std::string value; // The actual string value of the token
};

#endif // TOKEN_H