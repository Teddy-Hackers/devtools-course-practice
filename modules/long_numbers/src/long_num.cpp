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
LongNumber LongNumber::operator-(){
    positive = !positive;
    return *this;
}
bool LongNumber::operator<(const LongNumber & rhs) const {
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
        // std::cout << "looking at " << (char)(*it + '0') << "\n";
        if ( *it != 0 ){
            // std::cout << "num is " << (int)(it.base() - tmp.number.begin());
            tmp.number = tmp.number.substr(0, it.base() - tmp.number.begin());
            // tmp.print();
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
    return number == rhs.number;
}
bool LongNumber::operator!=(const LongNumber &rhs) const {
    return !(*this == rhs);
}

void LongNumber::print() const {
    for ( auto it = number.rbegin(); it != number.rend(); ++it ){
        std::cout << (char)(*it + '0');
    }
    std::cout << "\n";
}

