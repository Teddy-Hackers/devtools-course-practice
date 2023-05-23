// Copyright 2023 Prokofev Denis

#ifndef  MODULES_REV_POL_NOT_INCLUDE_LEX_H_
#define  MODULES_REV_POL_NOT_INCLUDE_LEX_H_

enum Type {
    operation, vall
};
enum State {
    q0, q1
};

class Lex {
 public:
    Lex() {}
    Lex(std::string _s, Type _t, int _val);
    Type getType();
    int getVal();
    std::string getS();
};

#endif  //  MODULES_REV_POL_NOT_INCLUDE_LEX_H_
