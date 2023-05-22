// Copyright 2023 Prokofev Denis

#ifndef  MODULES_REV_POL_NOT_INCLUDE_LEX_H_
#define  MODULES_REV_POL_NOT_INCLUDE_LEX_H_

#include <string>

enum Type {
    operation, val
};
enum State {
    q0, q1
};

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

#endif  //  MODULES_REV_POL_NOT_INCLUDE_LEX_H_
