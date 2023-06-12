#include "../include/long_num.h"

LongNumber::LongNumber(const LongNumber &src) {
    number = src.number;
}
LongNumber::LongNumber() {}
LongNumber::LongNumber(std::string src) {
    number = src;
    std::reverse(number.begin(), number.end());
}
const LongNumber LongNumber::operator+(const LongNumber &rhs) {
    size_t minSize = std::min(number.size(), rhs.number.size());
    size_t maxSize = std::max(number.size(), rhs.number.size());
    uint8_t carry = 0;
    for ( size_t i = 0; i < minSize; ++i){
        number[i] += rhs.number[i] + carry;
        carry = 0;
        if ( number[i] >= 10 ){
            number[i] -= 10;
            carry = 1;
        }
    }
    for ( size_t i = minSize; i < maxSize; ++i){
        number[i] += carry;
        carry = 0;
        if ( number[i] >= 10 ){
            number[i] -= 10;
            carry = 1;
        }
        else{
            break;
        }
    }
    if ( carry ){
        number += "1";
    }
    return *this;
}
LongNumber LongNumber::operator+=(const LongNumber &rhs) {
    return *this;
}
const LongNumber LongNumber::operator-(const LongNumber &rhs) {
    return LongNumber();
}
LongNumber LongNumber::operator-=(const LongNumber &rhs) {
    return *this;
}
const LongNumber LongNumber::operator*(const LongNumber &rhs) {
    return LongNumber();
}
LongNumber LongNumber::operator*=(const LongNumber &rhs) {
    return *this;
}
const LongNumber LongNumber::operator/(const LongNumber &rhs) {
    return LongNumber();
}
LongNumber LongNumber::operator/=(const LongNumber &rhs) {
    return *this;
}
const bool LongNumber::operator==(const LongNumber &rhs) {
    return false;
}
const bool LongNumber::operator!=(const LongNumber &rhs) {
    return false;
}
LongNumber LongNumber::operator=(LongNumber &&other) {
    return *this;
}

void LongNumber::print() {
    for ( auto it = number.rbegin(); it != number.rend(); ++it ){
        std::cout << *it + '0';
    }
    std::cout << "\n";
}

