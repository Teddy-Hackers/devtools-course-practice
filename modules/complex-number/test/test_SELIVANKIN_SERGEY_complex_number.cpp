// Copyright 2023 Selivankin Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Selivankin_Sergey_ComplexNumberTest, Test_Equal) {
    // Arrange
    double re = 0.0;
    double im = 0.0;
    ComplexNumber a(re, im);
    ComplexNumber b(re, im);

    // Act
    bool isEqual = a == b;

    // Assert
    EXPECT_TRUE(isEqual);
}

TEST(Selivankin_Sergey_ComplexNumberTest, Test_Not_Equal) {
    // Arrange
    double re = 0.0;
    double im = 0.0;
    ComplexNumber a(re, im);
    ComplexNumber b(re, im);

    // Act
    bool isEqual = a != b;

    // Assert
    EXPECT_FALSE(isEqual);
}

TEST(Selivankin_Sergey_ComplexNumberTest, Test_Sum) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(4.0, 3.0);
    ComplexNumber expected(5.0, 5.0);

    // Act
    ComplexNumber result = a + b;

    // Assert
    ASSERT_EQ(expected, result);
}
