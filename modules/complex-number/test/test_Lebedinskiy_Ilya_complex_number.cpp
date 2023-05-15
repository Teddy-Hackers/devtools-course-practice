// Copyright 2023 Lebedinskiy Ilya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Lebedinskiy_Ilya_ComplexNumberTest, Can_Sum) {
	double re1 = 5.0;
	double im1 = 1.0;
	double re2 = 4.0;
	double im2 = 6.0;
	ComplexNumber a(re1, im1);
	ComplexNumber b(re2, im2);
	ComplexNumber z = a + b;
	EXPECT_EQ(9, z.getRe());
	EXPECT_EQ(7, z.getIm());
}

TEST(Lebedinskiy_Ilya_ComplexNumberTest, Can_Min) {
	double re1 = 10.0;
	double im1 = 7.0;
	double re2 = 5.0;
	double im2 = 1.0;
	ComplexNumber a(re1, im1);
	ComplexNumber b(re2, im2);
	ComplexNumber z = a - b;
	EXPECT_EQ(5, z.getRe());
	EXPECT_EQ(6, z.getIm());
}

TEST(Lebedinskiy_Ilya_ComplexNumberTest, Can_Num) {
	double re = 15.0;
	double im = 7.0;
	ComplexNumber z(re, im);
	EXPECT_EQ(z.getRe(), 15.0);
	EXPECT_EQ(z.getIm(), 7.0);
}

TEST(Lebedinskiy_Ilya_ComplexNumberTest, Can_Copy) {
	double re = 9.0;
	double im = 5.0;
	ComplexNumber z1(re, im);
	ComplexNumber z2(z1);
	EXPECT_EQ(z1.getRe(), z2.getRe());
	EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Lebedinskiy_Ilya_ComplexNumberTest, Can_Multiply) {
	double re1 = 4.0;
	double im1 = 2.0;
	double re2 = 6.0;
	double im2 = 1.0;
	ComplexNumber c1(re1, im1);
	ComplexNumber c2(re2, im2);
	ComplexNumber res = c2 * c1;
	EXPECT_DOUBLE_EQ(22.0, res.getRe());
	EXPECT_DOUBLE_EQ(16.0, res.getIm());
}

TEST(Lebedinskiy_Ilya_ComplexNumberTest, Can_Compare) {
	double re1 = 2.0;
	double im1 = 0.1;
	double re2 = 2.0;
	double im2 = 0.1;
	ComplexNumber z1(re1, im1);
	ComplexNumber z2(re2, im2);
	EXPECT_TRUE(z1 == z2);
}
