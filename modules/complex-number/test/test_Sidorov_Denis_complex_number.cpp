// Copyright 2023 Sidorov Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sidorov_Denis_ComplexNumberTest, TEST_SUM) {
  ComplexNumber a(1600.0, 25.0), b(800.0, 11.0), expected(2400.0, 36.0);
  ComplexNumber result = a + b;
  ASSERT_EQ(expected, result);
}

TEST(Sidorov_Denis_ComplexNumberTest, TEST_Sum) {
  ComplexNumber z1(50.0, 0.0);
  ComplexNumber z2(0.0, 50.0);
  ComplexNumber expression = z1 + z2;
  EXPECT_EQ(expression, ComplexNumber(50.0, 50.0));
}

TEST(Sidorov_Denis_ComplexNumberTest, TEST_Sum) {
  ComplexNumber a(6.0, 8.0), b(2.0, 6.0), expected(8.0, 14.0);
  ComplexNumber result = a + b;
  ASSERT_EQ(result, expected);
}
