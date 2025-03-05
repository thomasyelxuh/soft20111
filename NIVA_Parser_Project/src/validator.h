#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "parser.h"

class Validator {
public:
    static bool validate(const Parser& parser);
};

#endif