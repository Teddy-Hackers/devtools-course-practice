// Copyright 2017 Kruglikova Valeriia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kruglikova_Valeriia_ComplexNumberTest, zero_multipication) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(5., 3.);

    // Assert
    EXPECT_EQ(z1, z1*z2);
}

TEST(Kruglikova_Valeriia_ComplexNumberTest, one_multipication) {
    // Arrange
    double re = 1.0;
    double im = 0.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(5., 3.);

    // Assert
    EXPECT_EQ(z2, z1 * z2);
}

TEST(Kruglikova_Valeriia_ComplexNumberTest, power_square) {
    // Arrange
    double re = 1.0;
    double im = 2.0;
    
    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, 0);
    ComplexNumber z3(0, im);
    ComplexNumber z4(0, 0);
    ComplexNumber z1res(-3., 4.);
    ComplexNumber z2res(1., 0);
    ComplexNumber z3res(0., -4.);
    ComplexNumber z4res(0., 0.);
    // Assert
    EXPECT_EQ(z1res, z1 * z1);
    EXPECT_EQ(z2res, z2 * z2);
    EXPECT_EQ(z3res, z3 * z3);
    EXPECT_EQ(z4res, z4 * z4);
}

TEST(Kruglikova_Valeriia_ComplexNumberTest, getter_setter) {
    // Arrange
    double re = 1.0;
    double im = 0.0;

    // Act
    ComplexNumber z1;
    z1.setIm(im);
    z1.setRe(re);
    // Assert
    EXPECT_EQ(z1.getRe(), re);
    EXPECT_EQ(z1.getIm(), im);

}