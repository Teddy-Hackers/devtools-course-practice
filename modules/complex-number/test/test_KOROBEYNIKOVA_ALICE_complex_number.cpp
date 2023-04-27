// Copyright 2023 Alice Korobeynikova

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Korobeynikova_Alice_ComplexNumberTest, ParametrizedConstructor) {
  double re = -7.5, im = 2;
  ComplexNumber number(re, im);
  ASSERT_EQ(number.getRe(), re);
  ASSERT_EQ(number.getIm(), im);
}

TEST(Korobeynikova_Alice_ComplexNumberTest, CopyConstructor) {
  double re = -7.5, im = 2;
  ComplexNumber number(ComplexNumber(re, im));
  ASSERT_EQ(number.getRe(), re);
  ASSERT_EQ(number.getIm(), im);
}

TEST(Korobeynikova_Alice_ComplexNumberTest, ComparisonOperator) {
  double re = -7.5, im = 2;
  ComplexNumber number1(re, im), number2(re, im);
  ASSERT_EQ(number1, number2);
}