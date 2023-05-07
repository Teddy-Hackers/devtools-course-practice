// Copyright 2023 Eremin Aleksandr

#ifndef MODULES_POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_CALCULATOR_H_
#define MODULES_POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_CALCULATOR_H_

#include "Monom.h"

#include "List.h"
#include <ctype.h>
#include <string>

// The "Polynomial" class
class polynomial_calculator {
 private:
    int pos = 0;
    List < Monom > monoms;

 public:
    polynomial_calculator();
    explicit polynomial_calculator(const std::string& polynomStr);
    Lexema lexem(const std::string& polynomStr);

    void parser(const std::string& polynomStr);
    void cancellation();

    bool operator == (const polynomial_calculator& _Polynom) const;
    bool operator != (const polynomial_calculator& _Polynom) const;

    polynomial_calculator operator +
        (const polynomial_calculator& _Polynom) const;
    polynomial_calculator operator -
        (const polynomial_calculator& _polynom) const;
    polynomial_calculator operator *
        (const polynomial_calculator& _Polynom) const;

    polynomial_calculator operator +
        (const double& _Num) const;
    polynomial_calculator operator -
        (const double& _Num) const;
    polynomial_calculator operator *
        (const double& _Num) const;
};
#endif  // MODULES_POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOMIAL_CALCULATOR_H_
