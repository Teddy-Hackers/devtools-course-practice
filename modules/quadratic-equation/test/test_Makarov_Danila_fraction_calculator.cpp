// Copyright 2023 Popov Andrey

#include <gtest/gtest.h>

#include <tuple>

#include "include/quadratic_equation.h"

TEST(Popov_A_quadratic_equation, Discriminant_positive) {
  Quadratic_equation z1;
  float D_more_zero = z1.solution(1, 3, -4);

  EXPECT_EQ(D_more_zero, -4, 1);
}

TEST(Popov_A_quadratic_equation, Discriminant_zero) {
  Quadratic_equation z1;
  float D_more_zero = z1.solution(1, -4, 4);

  EXPECT_EQ(D_more_zero, 2);
}

TEST(Popov_A_quadratic_equation, Discriminant_negative) {
  Quadratic_equation z1;
  float D_more_zero = z1.solution(1, -5, 9);

  EXPECT_EQ(D_more_zero, -1);
}
