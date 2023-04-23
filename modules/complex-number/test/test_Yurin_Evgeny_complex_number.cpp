// Copyright 2023 Yurin Evgeny

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Yurin_Evgeny_ComplexNumberTest, Test_Summ) {
  ComplexNumber first(1337.0, 42.0);
  ComplexNumber second(3.0, 8.0);
  ComplexNumber expectedResult = ComplexNumber(1400.0, 50.0);

  ComplexNumber result = a + b;

  ASSERT_EQ(expectedResult.getIm(), result.getIm());
  ASSERT_EQ(expectedResult.getRe(), result.getRe());
}

TEST(Yurin_Evgeny_ComplexNumberTest, Test_minus) {
  ComplexNumber first(1337.0, 42.0);
  ComplexNumber second(3.0, 8.0);
  ComplexNumber expectedResult = ComplexNumber(1334.0, 34.0);

  ComplexNumber result = a - b;

  ASSERT_EQ(expectedResult.getIm(), result.getIm());
  ASSERT_EQ(expectedResult.getRe(), result.getRe());
}

TEST(Yurin_Evgeny_ComplexNumberTest, Test_Not_Equal) {
  ComplexNumber first(1.1, 2.1);
  ComplexNumber second(1.0, 2.0);

  EXPECT_NE(first, second);
}

Test(Yurin_Evgeny_ComplexNumberTest, Test_Set) {
  ComplexNumber number;
  double expectedRe = 5.0;
  double expectedIm = 4.0;

  number.setIm(4.0);
  number.setRe(5.0);

  EXPECT_EQ(expectedRe, number.getRe());
  EXPECT_EQ(expectedIm, number.getIm());
}
