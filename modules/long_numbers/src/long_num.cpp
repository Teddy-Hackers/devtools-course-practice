// Copyright 2023 Rezchikov Dmitrii

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
LongNumber LongNumber::operator-() const {
    LongNumber tmp(*this);
    tmp.changeSign();
    return tmp;
}
bool LongNumber::absLess(const LongNumber & rhs) const {
    if ( number.size() == rhs.number.size() ) {
        for ( size_t i = this->number.size() - 1; i >= 0; --i){
            if ( number[i] < rhs.number[i] ){
                return true;
            }
            else if ( number[i] > rhs.number[i] ) {
                return false;
            }
        }
        return false;
    }
    else{
        return this->number.size() < rhs.number.size();
    }
}
bool LongNumber::operator<(const LongNumber & rhs) const {
    if ( positive != rhs.positive ){
        return !positive && rhs.positive;
    }
    else if ( positive ) {
        return absLess( rhs );
    }
    else {
        return rhs.absLess(*this);
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
        tmp.number += (char)(1);
    }
    return tmp;
}
LongNumber LongNumber::operator+=(const LongNumber &rhs) {
    *this = *this + rhs;
    return *this;
}
LongNumber LongNumber::operator-(const LongNumber &rhs) const {
    if ( *this == rhs )
        return LongNumber("0");
    LongNumber tmp(*this);
    if ( tmp < rhs ){
        return -(rhs - tmp);
    }
    size_t minSize = std::min(number.size(), rhs.number.size());
    size_t maxSize = std::max(number.size(), rhs.number.size());
    uint8_t carry = 0;
    for ( size_t i = 0; i < minSize; ++i){
        if ( carry ) {
            if ( tmp.number[i] == 0 ){
                tmp.number[i] = 9;
            }
            else{
                tmp.number[i] -= 1;
                carry = 0;
            }
        }
        if ( tmp.number[i] < rhs.number[i] ) {
            tmp.number[i] += 10;
            carry = 1;
        }
        tmp.number[i] -= rhs.number[i];
    }
    for ( size_t i = minSize; i < maxSize; ++i){
        if ( carry ){
            if ( tmp.number[i] == 0 ){
                tmp.number[i] = 9;
            }
            else{
                tmp.number[i] -= 1;
                break;
            }
        }
        else{
            break;
        }
    }
    for ( auto it = tmp.number.rbegin(); it != tmp.number.rend(); ++it ){
        if ( *it != 0 ){
            tmp.number = tmp.number.substr(0, it.base() - tmp.number.begin());
            break;
        }
    }
    return tmp;
}
LongNumber LongNumber::operator-=(const LongNumber &rhs) {
    *this = *this - rhs;
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
    return (number == rhs.number) && (positive == rhs.positive);
}
bool LongNumber::operator!=(const LongNumber &rhs) const {
    return !(*this == rhs);
}

void LongNumber::changeSign() {
    positive = !positive;
}
std::string LongNumber::getStr() const
{
    std::string str = "";
    for ( auto it = number.rbegin(); it != number.rend(); ++it ) {
        str += (char)(*it + '0');
    }
    // std::reverse(str.begin(), str.end());
    if ( !positive ) {
        str = "-" + str;
    }
    return str;
}
std::ostream &operator<<(std::ostream &os, const LongNumber &n) {
    return os << n.getStr();
}

