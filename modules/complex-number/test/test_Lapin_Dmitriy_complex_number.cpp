// Copyright 2023 Lapin Dmitriy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Lapin_Dmitriy_ComplexNumberTest, summation_correct) {
    // Act
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber z3(5.0, 7.0);
    // Assert
    EXPECT_EQ(z3, z1 + z2);
}

TEST(Lapin_Dmitriy_ComplexNumberTest, multiply_correct) {
    // Act
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber z3(-6.0, 17.0);
    // Assert
    EXPECT_EQ(z3, z1 * z2);
}

TEST(Lapin_Dmitriy_ComplexNumberTest, division_correct) {
    // Act
    ComplexNumber z1(6.0, 8.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber z3(2.0, 0.0);
    // Assert
    EXPECT_EQ(z3, z1 / z2);
}
