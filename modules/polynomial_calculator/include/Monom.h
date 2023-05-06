// Copyright 2023 Eremin Aleksandr

#ifndef MODULES_POLYNOMIAL_CALCULATOR_INCLUDE_MONOM_H_
#define MODULES_POLYNOMIAL_CALCULATOR_INCLUDE_MONOM_H_
// Monome class or structure;

#include <iostream>
#include <string>

// Designations to increase the readability of the code;
enum State {
    START,
    NUMBER,
    END
};
// Lexem, numbers, operations, variables;
enum LexType {
    LEX_NULL,  // for unrecognized lexem;

    LEX_NUMBER,  // numbers;
    LEX_DELIM,  // separators consisting of non-alphabetic characters;
    LEX_VAR  // variable
};
// separators
enum LexDelims {
    LEX_DEL_NULL,  // for error;

    LEX_DEL_ADD,  // operation +;
    LEX_DEL_SUB,  // operation -, binary or unary;
    LEX_DEL_POW,  // exponentiation;
    LEX_DEL_EQUALS  // equal sign;
};

class Monom {
 private:
    double coefficient;
    int degreeX;
    int degreeY;
    int degreeZ;

 public:
    Monom() {
        coefficient = 0;
        degreeX = 0;
        degreeY = 0;
        degreeZ = 0;
    }
    Monom(double coeff, int degX, int degY, int degZ);
    Monom(const Monom& m);

    double coeff() {
        return coefficient;
    }
    int degree() {
        return degreeX + degreeY + degreeZ;
    }

    const Monom& operator = (const Monom& _monom);
    bool operator != (const Monom& _monom) const;
    bool operator == (const Monom& _monom) const;

    Monom operator + (const Monom& _monom) const;
    Monom operator - (const Monom& _monom) const;
    Monom operator * (const Monom& _monom) const;

    Monom operator + (const double& _Num) const;
    Monom operator - (const double& _Num) const;
    Monom operator * (const double& _Num) const;
    bool degreeEq(const Monom& _monom);
};

class Lexema {
 public:
    int type;  // lixem type (constant, separator, error);
    int index;  // the specific index of the lexem;
    double value;  // lexem value (for numeric constants);

    std::string buf;  // storage of the lexem itself;

    Lexema(int type = LEX_NULL, int index = LEX_NULL,
        const std::string& buf = "",
        double value = 0) : type(type),
        index(index),
        buf(buf),
        value(value) {}
};
#endif  // MODULES_POLYNOMIAL_CALCULATOR_INCLUDE_MONOM_H_
