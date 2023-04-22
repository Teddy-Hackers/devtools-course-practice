// Copyright 2023 Ustinov Alexandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Ustinov, Sum1) {
    ComplexNumber z1(1.0, 0.0);
    ComplexNumber z2(0.0, 1.0);

    ComplexNumber z1_plus_z2 = z1 + z2;

    EXPECT_EQ(z1_plus_z2, ComplexNumber(1.0, 1.0));
}

TEST(Ustinov, Sum2) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(3.0, 5.0);

    ComplexNumber z1_plus_z2 = z1 + z2;

    EXPECT_EQ(z1_plus_z2, ComplexNumber(5.0, 8.0));
}

TEST(Ustinov, Sum3) {
    ComplexNumber z1(0.0, 1.0);
    ComplexNumber z2(0.0, -1.0);

    ComplexNumber z1_plus_z2 = z1 + z2;

    EXPECT_EQ(z1_plus_z2, ComplexNumber(0.0, 0.0));
}