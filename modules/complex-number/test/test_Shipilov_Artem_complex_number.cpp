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