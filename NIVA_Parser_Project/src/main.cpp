#include "tokenizer.h"
#include "parser.h"
#include "validator.h"
#include "error_handler.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        ErrorHandler::reportError("Usage: ./niva_parser <filename>");
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        ErrorHandler::reportError("Failed to open file.");
        return 1;
    }

    std::string input((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    Tokenizer tokenizer(input);
    std::vector<Token> tokens = tokenizer.tokenize();

    Parser parser(tokens);
    if (!Validator::validate(parser)) {
        ErrorHandler::reportError("Parsing failed.");
        return 1;
    }

    std::cout << "Parsing successful!" << std::endl;
    return 0;
}