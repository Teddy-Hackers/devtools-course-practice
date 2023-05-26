// Copyright 2023 Antonova Anastasya

#ifndef MODULES_LONG_NUMBER_INCLUDE_LONG_NUMBER_H_
#define MODULES_LONG_NUMBER_INCLUDE_LONG_NUMBER_H_

#include <string>
#include <cstdint>
#include "include/long_number.h"

class longNumber {

    BigInt first;
    BigInt second;

    int chosenSign = -10;

    const std::string sign[11] = { "-", "+", "/", "*", "%", "<", ">", "<=", ">=", "!=", "==" };

    bool argChecking(int argc, const char** argv);
    std::string compareOrCount();

public:
    std::string runningLongNumber()(int argc, const char** argv);

};

#endif  // MODULES_LONG_NUMBER_INCLUDE_LONG_NUMBER_H_