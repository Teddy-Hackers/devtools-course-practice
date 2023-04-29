// Copyright 2023 Artem Shipilov

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shipilov_Artem_ComplexNumberTest, Assignment_Of_Complex_Numbers) {
    // Arrange
    double a_re = 1.5;
    double a_im = 1.5;
    
    // Act
    ComplexNumber z(a_re, a_im);
    ComplexNumber result = z;
    
    // Assert
    EXPECT_EQ(z.getRe(), result.getRe());
    EXPECT_EQ(z.getIm(), result.getIm());
}

TEST(Shipilov_Artem_ComplexNumberTest, test) {
    // Arrange
    double a1_re = 1.11;
    double a1_im = 1.11;
    double a2_re = 1.11;
    double a2_im = 1.11;
    
    // Act
    ComplexNumber z1(a1_re, a1_im);
    ComplexNumber z2(a2_re, a2_im);
    
    // Assert
    ASSERT_TRUE(z1 == z2);
}

TEST(Shipilov_Artem_ComplexNumberTest, Multiplicationand_Division_Of_Complex_Numbers) {
    // Arrange
    double a1_re = 1.5;
    double a1_im = 1.5;
    double a2_re = -1.5;
    double a2_im = 4.5;
    double answer_re = -9.0;
    double answer_im = 9.0;
    
    // Act
    ComplexNumber z1(a1_re, a1_im);
    ComplexNumber z2(a2_re, a2_im);
    ComplexNumber result1 = z1 + z2;
    ComplexNumber result2 = result1 * z1;
    
    // Assert
    EXPECT_EQ(answer_re, result2.getRe());
    EXPECT_EQ(answer_im, result2.getIm());
}