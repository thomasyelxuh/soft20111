#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <iostream>

class ErrorHandler {
public:
    static void reportError(const std::string& message);
};

#endif