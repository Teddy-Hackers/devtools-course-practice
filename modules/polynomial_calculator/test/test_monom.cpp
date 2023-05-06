// Copyright 2023 Eremin Aleksandr

#include <gtest/gtest.h>

#include "include/Polynom.h"

#include "include/Monom.h"

TEST(Monom, can_create_monom_no_value) {
	ASSERT_NO_THROW(Monom M);
}

TEST(Monom, can_create_monom_with_value) {
	ASSERT_NO_THROW(Monom M(2, 1, 2, 3));
}

TEST(Monom, can_create_monom_with_value_other) {
	ASSERT_NO_THROW(Monom M(-5.6, 9, 2, 5));
}

TEST(Monom, can_not_create_monom_with_negative_degree) {
	ASSERT_ANY_THROW(Monom M(-5.6, 9, -2, 5));
}

TEST(Monom, can_create_monom_copy_monom) {
	Monom M;
	ASSERT_NO_THROW(Monom Mon(M));
}

TEST(Monom, returns_the_coefficient_correctly) {
	Monom M(25, 5, 5, 10);
	double coeff = M.coeff();
	ASSERT_EQ(25, coeff);
}

TEST(Monom, returns_the_degree_sum_correctly) {
	Monom M(10, 9, 5, 10);
	double coeff = M.degree();
	ASSERT_EQ(24, coeff);
}

TEST(Monom, compares_coefficients_correctly) {
	Monom M(-85, 9, 99, 10);
	Monom M2(2.5, 9, 99, 10);
	ASSERT_EQ(1, M2.degreeEq(M));
}

TEST(Monom, can_compare_monomes_equal) {
	Monom M(2.5, 1, 2, 3);
	Monom Mon(2.5, 1, 2, 3);
	ASSERT_EQ(M, Mon);
}

TEST(Monom, can_compare_monomes_not_equal) {
	Monom M(0.5, 1, 2, 5);
	Monom Mon(2.5, 1, 2, 3);
	ASSERT_NE(M, Mon);
}

TEST(Monom, copy_constructor_correctly) {
	Monom M(1.2, 5, 9, 2);
	Monom Mon(M);
	ASSERT_EQ(M, Mon);
}

TEST(Monom, can_assign_a_monom_to_monom) {
	Monom M(1.2, 5, 9, 2);
	Monom Mon(0, 0, 0, 0);
	Mon = M;
	ASSERT_EQ(M, Mon);
}

TEST(Monom, addition_monom_no_throw) {
	Monom M1(-6.6, 6, 1, 2);
	Monom M2(0.9, 6, 1, 2);
	ASSERT_NO_THROW(M1 + M2);
}

TEST(Monom, addition_monom_any_throw) {
	Monom M1(-6.6, 5, 1, 2);
	Monom M2(0.9, 6, 1, 2);
	ASSERT_ANY_THROW(M1 + M2);
}

TEST(Monom, addition_monom_correctly) {
	Monom M1(0.2, 2, 5, 1);
	Monom M2(5, 2, 5, 1);
	Monom Res(5.2, 2, 5, 1);
	ASSERT_EQ(Res, M1 + M2);
}

TEST(Monom, subtraction_monom_no_throw) {
	Monom M1(2, 5, 1, 2);
	Monom M2(-5.5, 5, 1, 2);
	ASSERT_NO_THROW(M1 - M2);
}

TEST(Monom, subtraction_monom_any_throw) {
	Monom M1(2, 5, 5, 8);
	Monom M2(-5.5, 6, 1, 2);
	ASSERT_ANY_THROW(M1 - M2);
}

TEST(Monom, subtraction_monom_correct) {
	Monom M1(5, 1, 2, 3);
	Monom M2(9, 1, 2, 3);
	Monom Res(-4, 1, 2, 3);
	ASSERT_EQ(Res, M1 - M2);
}

TEST(Monom, multiplication_monom_no_throw) {
	Monom M1(-2, 1, 2, 3);
	Monom M2(3.6, 3, 2, 1);
	ASSERT_NO_THROW(M1 * M2);
}

TEST(Monom, multiplication_monom_correct) {
	Monom M1(-5.2, 1, 10, 3);
	Monom M2(5, 3, 2, 1);
	Monom Res(-26, 4, 12, 4);
	ASSERT_EQ(Res, M1 * M2);
}

TEST(Monom, addition_monom_a_constant_no_throw) {
	Monom M1(-5.2, 0, 0, 0);
	ASSERT_NO_THROW(M1 + 5.0);
}

TEST(Monom, addition_monom_a_constant_any_throw) {
	Monom M1(-5.2, 0, 1, 0);
	ASSERT_ANY_THROW(M1 + 5.0);
}

TEST(Monom, multiplication_monom_a_constant_no_throw) {
	Monom M1(-5.2, 1, 2, 3);
	ASSERT_NO_THROW(M1 * 5.0);
}

TEST(Monom, subtraction_monom_a_constant_no_throw) {
	Monom M1(-5.2, 0, 0, 0);
	ASSERT_NO_THROW(M1 - 5.0);
}

TEST(Monom, subtraction_monom_a_constant_any_throw) {
	Monom M1(-5.2, 1, 0, 0);
	ASSERT_ANY_THROW(M1 - 5.0);
}

TEST(Monom, can_create_Lexema) {
	ASSERT_NO_THROW(Lexema lexem1(LEX_VAR, LEX_NULL, "z"));
}
