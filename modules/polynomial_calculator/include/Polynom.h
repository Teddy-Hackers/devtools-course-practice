// Copyright 2023 Eremin Aleksandr

#ifndef MODULES_POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOM_H_
#define MODULES_POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOM_H_

#include "Monom.h"

#include "List.h"

#include <ctype.h>

// The "Polynomial" class
class Polynom {
private: int pos = 0;
       List < Monom > monoms;

public: Polynom();
      Polynom(const std::string& polynomStr);
      Lexema lexem(const std::string& polynomStr);

      void parser(const std::string& polynomStr);
      void cancellation();

      bool operator == (const Polynom& _Polynom) const;
      bool operator != (const Polynom& _Polynom) const;

      Polynom operator + (const Polynom& _Polynom) const;
      Polynom operator - (const Polynom& _polynom) const;
      Polynom operator * (const Polynom& _Polynom) const;

      Polynom operator + (const double& _Num) const;
      Polynom operator - (const double& _Num) const;
      Polynom operator * (const double& _Num) const;
};

#endif // MODULES_POLYNOMIAL_CALCULATOR_INCLUDE_POLYNOM_H_
