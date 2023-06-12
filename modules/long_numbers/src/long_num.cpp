#include "../include/long_num.h"

LongNumber::LongNumber(const LongNumber &src) {
    number = src.number;
}
LongNumber::LongNumber() {}
LongNumber::LongNumber(std::string src) {
    number = src;
    std::reverse(number.begin(), number.end());
    for ( auto & c : number ) {
        c -= '0';
    }
}
LongNumber LongNumber::operator+(const LongNumber &rhs) const {
    LongNumber tmp(*this);
    size_t minSize = std::min(number.size(), rhs.number.size());
    size_t maxSize = std::max(number.size(), rhs.number.size());
    uint8_t carry = 0;
    for ( size_t i = 0; i < minSize; ++i){
        tmp.number[i] += rhs.number[i] + carry;
        carry = 0;
        if ( tmp.number[i] >= 10 ){
            tmp.number[i] -= 10;
            carry = 1;
        }
    }
    for ( size_t i = minSize; i < maxSize; ++i){
        tmp.number[i] += carry;
        carry = 0;
        if ( tmp.number[i] >= 10 ){
            tmp.number[i] -= 10;
            carry = 1;
        }
        else{
            break;
        }
    }
    if ( carry ){
        tmp.number += "1";
    }
    return tmp;
}
LongNumber LongNumber::operator+=(const LongNumber &rhs) {
    return *this;
}
LongNumber LongNumber::operator-(const LongNumber &rhs) const {
    return LongNumber();
}
LongNumber LongNumber::operator-=(const LongNumber &rhs) {
    return *this;
}
LongNumber LongNumber::operator*(const LongNumber &rhs) const {
    return LongNumber();
}
LongNumber LongNumber::operator*=(const LongNumber &rhs) {
    return *this;
}
LongNumber LongNumber::operator/(const LongNumber &rhs) const {
    return LongNumber();
}
LongNumber LongNumber::operator/=(const LongNumber &rhs) {
    return *this;
}
bool LongNumber::operator==(const LongNumber &rhs) const {
    return number == rhs.number;
}
bool LongNumber::operator!=(const LongNumber &rhs) const {
    return !(*this == rhs);
}

void LongNumber::print() {
    for ( auto it = number.rbegin(); it != number.rend(); ++it ){
        std::cout << *it + '0';
    }
    std::cout << "\n";
}

