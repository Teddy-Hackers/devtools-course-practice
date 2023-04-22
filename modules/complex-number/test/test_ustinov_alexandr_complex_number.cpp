// Copyright 2023 Ustinov Alexandr

#include <gtest/gtest.h>
#include <random>
#include "include/complex_number.h"

TEST(Ustinov_ComplexNumberTest, Equality1) {
    ComplexNumber z1(3.0, 1.0),
                  z2(3.0, 1.0);

    bool eq = (z1 == z2);

    EXPECT_EQ(eq, true);
}

TEST(Ustinov_ComplexNumberTest, Equality2) {
    ComplexNumber z1(1.0, 1.0),
                  z2(1.0, -1.0);

    bool eq = (z1 == z2);

    EXPECT_EQ(eq, false);
}

TEST(Ustinov_ComplexNumberTest, Addition1) {
    ComplexNumber z1(1.0, 0.0);
    ComplexNumber z2(0.0, 1.0);

    ComplexNumber z1_plus_z2 = z1 + z2;

    EXPECT_EQ(z1_plus_z2, ComplexNumber(1.0, 1.0));
}

TEST(Ustinov_ComplexNumberTest, Addition2) {
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(3.0, 5.0);

    ComplexNumber z1_plus_z2 = z1 + z2;

    EXPECT_EQ(z1_plus_z2, ComplexNumber(5.0, 8.0));
}

TEST(Ustinov_ComplexNumberTest, Addition3) {
    ComplexNumber z1(0.0, 1.0);
    ComplexNumber z2(0.0, -1.0);

    ComplexNumber z1_plus_z2 = z1 + z2;

    EXPECT_EQ(z1_plus_z2, ComplexNumber(0.0, 0.0));
}

TEST(Ustinov_ComplexNumberTest, Subtraction1) {
    ComplexNumber z1(1.0, 0.0);
    ComplexNumber z2(0.0, 1.0);

    ComplexNumber z1_minus_z2 = z1 - z2;

    EXPECT_EQ(z1_minus_z2, ComplexNumber(1.0, -1.0));
}

TEST(Ustinov_ComplexNumberTest, Subtraction2) {
    ComplexNumber z1(3.0, 1.0);
    ComplexNumber z2(1.0, 3.0);

    ComplexNumber z1_minus_z2 = z1 - z2;

    EXPECT_EQ(z1_minus_z2, ComplexNumber(2.0, -2.0));
}

TEST(Ustinov_ComplexNumberTest, Subtraction3) {
    ComplexNumber z1(0.0, 1.0);
    ComplexNumber z2(0.0, 1.0);

    ComplexNumber z1_minus_z2 = z1 - z2;

    EXPECT_EQ(z1_minus_z2, ComplexNumber(0.0, 0.0));
}

TEST(Ustinov_ComplexNumberTest, Subtraction4) {
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(0.0, -0.0);

    ComplexNumber z1_minus_z2 = z1 - z2;

    EXPECT_EQ(z1_minus_z2, ComplexNumber(0.0, 0.0));
}

TEST(Ustinov_ComplexNumberTest, Multiplication1) {
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(0.0, 0.0);

    ComplexNumber z1_times_z2 = z1 * z2;

    EXPECT_EQ(z1_times_z2, ComplexNumber(0.0, 0.0));
}

TEST(Ustinov_ComplexNumberTest, Multiplication2) {
    ComplexNumber z1(3.0, 0.0);
    ComplexNumber z2(5.0, 0.0);

    ComplexNumber z1_times_z2 = z1 * z2;

    EXPECT_EQ(z1_times_z2, ComplexNumber(15.0, 0.0));
}

TEST(Ustinov_ComplexNumberTest, Multiplication3) {
    ComplexNumber z1(0.0, 2.0);
    ComplexNumber z2(0.0, 1.0);

    ComplexNumber z1_times_z2 = z1 * z2;

    EXPECT_EQ(z1_times_z2, ComplexNumber(-2.0, 0.0));
}

TEST(Ustinov_ComplexNumberTest, Multiplication4) {
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(1.0, 1.0);

    ComplexNumber z1_times_z2 = z1 * z2;

    EXPECT_EQ(z1_times_z2, ComplexNumber(0.0, 2.0));
}

TEST(Ustinov_ComplexNumberTest, Multiplication5) {
    ComplexNumber z1(3.0, 2.0);
    ComplexNumber z2(0.0, 0.0);

    ComplexNumber z1_times_z2 = z1 * z2;

    EXPECT_EQ(z1_times_z2, ComplexNumber(0.0, 0.0));
}

TEST(Ustinov_ComplexNumberTest, Division1) {
    ComplexNumber z1(5.0, 8.0);
    ComplexNumber z2(1.0, 0.0);

    ComplexNumber z1_div_by_z2 = z1 / z2;

    EXPECT_EQ(z1_div_by_z2, ComplexNumber(5.0, 8.0));
}

TEST(Ustinov_ComplexNumberTest, Division2) {
    ComplexNumber z1(5.0, 8.0);
    ComplexNumber z2(0.0, 1.0);

    ComplexNumber z1_div_by_z2 = z1 / z2;

    EXPECT_EQ(z1_div_by_z2, ComplexNumber(8.0, -5.0));
}

TEST(Ustinov_ComplexNumberTest, Division3) {
    ComplexNumber z1(1.0, 0.0);
    ComplexNumber z2(1.0, 1.0);

    ComplexNumber z1_div_by_z2 = z1 / z2;

    EXPECT_EQ(z1_div_by_z2, ComplexNumber(0.5, -0.5));
}
