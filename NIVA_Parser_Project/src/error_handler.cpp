#include "error_handler.h"

void ErrorHandler::reportError(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
}