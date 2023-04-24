// Copyright 2023 Bulgakov Daniil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bulgakov_Daniil_ComplexNumberTest, Can_Multiple_Sum) {
    // Arrange
    ComplexNumber a(1.0, 1.0);
    ComplexNumber expect(3.0, 3.0);

    // Act
    ComplexNumber result = a + a + a;

    // Assert
    ASSERT_EQ(expect.getIm(), result.getIm());
    ASSERT_EQ(expect.getRe(), result.getRe());
}

TEST(Bulgakov_Daniil_ComplexNumberTest, Test_Selfsubstruct_Zero) {
    // Arrange
    ComplexNumber a(1.0, 1.0);
    ComplexNumber expect(0.0, 0.0);

    // Act
    ComplexNumber result = a - a;

    // Assert
    ASSERT_EQ(expect.getIm(), result.getIm());
    ASSERT_EQ(expect.getRe(), result.getRe());
}

TEST(Bulgakov_Daniil_ComplexNumberTest, Test_Negative_Mult) {
    // Arrange
    ComplexNumber a(-1.0, -1.0);
    ComplexNumber b(-1.0, -1.0);
    ComplexNumber expect(0.0, 2.0);

    // Act
    ComplexNumber result = a * b;

    // Assert
    ASSERT_EQ(expect.getIm(), result.getIm());
    ASSERT_EQ(expect.getRe(), result.getRe());
}

TEST(Bulgakov_Daniil_ComplexNumberTest, Test_Division) {
    // Arrange
    ComplexNumber a(-1.0, 1.0);
    ComplexNumber b(-1.0, -2.0);
    ComplexNumber expect(-0.2, -0.6);

    // Act
    ComplexNumber result = a / b;

    // Assert
    ASSERT_NEAR(expect.getIm(), result.getIm(), 0.001);
    ASSERT_NEAR(expect.getRe(), result.getRe(), 0.001);
}
