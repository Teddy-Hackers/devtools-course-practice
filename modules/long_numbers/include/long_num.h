#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>


class LongNumber{
 private:
    std::string number;



 public:
    LongNumber(const LongNumber & src);
    LongNumber();
    LongNumber(std::string src);
    const LongNumber operator+(const LongNumber & rhs);
    LongNumber operator+=(const LongNumber & rhs);
    const LongNumber operator-(const LongNumber & rhs);
    LongNumber operator-=(const LongNumber & rhs);
    const LongNumber operator*(const LongNumber & rhs);
    LongNumber operator*=(const LongNumber & rhs);
    const LongNumber operator/(const LongNumber & rhs);
    LongNumber operator/=(const LongNumber & rhs);
    const bool operator==(const LongNumber & rhs);
    const bool operator!=(const LongNumber & rhs);
    LongNumber operator=(LongNumber && other);
    void print();



};