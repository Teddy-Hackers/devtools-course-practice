#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>


class LongNumber{
 private:
    std::string number;
    bool positive = true;



 public:
    LongNumber(const LongNumber & src);
    LongNumber();
    LongNumber(std::string src);
    LongNumber operator-();
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
    void print() const;



};