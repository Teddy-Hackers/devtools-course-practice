// Copyright 2023 Prokofev Denis

#include "include/lex.h"

class Lex {
    std::string s;
    Type t;
    int val;
 public:
    Lex() {}
    Lex(std::string _s, Type _t, int _val) {
        s = _s;
        t = _t;
        val = _val;
    }
    Type getType() { return t; }
    int getVal() { return val; }
    std::string getS() { return s; }
};