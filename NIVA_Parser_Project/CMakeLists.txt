cmake_minimum_required(VERSION 3.10)

project(NIVA_Parser_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(niva_parser
    src/main.cpp
    src/tokenizer.cpp
    src/parser.cpp
    src/validator.cpp
    src/error_handler.cpp
)