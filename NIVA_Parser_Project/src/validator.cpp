#include "validator.h"

bool Validator::validate(const Parser& parser) {
    return parser.parse();
}