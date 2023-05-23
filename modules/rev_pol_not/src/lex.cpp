// Copyright 2023 Prokofev Denis

#include <string>
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
        if (_t == operation && _val != -1) throw "Error";
        if (_t == vall && _val == -1) throw "Error";
    }
    Type getType() { return t; }
    int getVal() { return vall; }
    std::string getS() { return s; }
};