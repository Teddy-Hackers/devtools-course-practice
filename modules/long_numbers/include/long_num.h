// Copyright 2023 Rezchikov Dmitrii

#ifndef MODULES_LONG_NUMBERS_INCLUDE_LONG_NUM_H_
#define MODULES_LONG_NUMBERS_INCLUDE_LONG_NUM_H_

#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>


class LongNumber{
 private:
    std::string number;
    bool positive = true;
    std::string getStr() const;


 public:
    LongNumber(const LongNumber & src);
    LongNumber();
    LongNumber(std::string src);
    LongNumber operator-() const;
    bool absLess(const LongNumber & rhs) const;
    bool operator<(const LongNumber & rhs) const;
    LongNumber operator+(const LongNumber & rhs) const;
    LongNumber operator+=(const LongNumber & rhs);
    LongNumber operator-(const LongNumber & rhs) const;
    LongNumber operator-=(const LongNumber & rhs);
    LongNumber operator*(const LongNumber & rhs) const;
    LongNumber operator*=(const LongNumber & rhs);
    LongNumber operator/(const LongNumber & rhs) const;
    LongNumber operator/=(const LongNumber & rhs);
    bool operator==(const LongNumber & rhs) const;
    bool operator!=(const LongNumber & rhs) const;
    friend std::ostream& operator<<(std::ostream & os, const LongNumber & n);
    void changeSign();
};

#endif // MODULES_LONG_NUMBERS_INCLUDE_LONG_NUM_H_