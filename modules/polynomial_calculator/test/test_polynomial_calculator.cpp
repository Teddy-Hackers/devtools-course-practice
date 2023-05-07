// Copyright 2023 Eremin Aleksandr

#include <gtest/gtest.h>

#include "include/polynomial_calculator.h"

#include "include/Monom.h"


TEST(polynomial_calculator, polynomial_calculator_can_Run) {
    ASSERT_NO_THROW(polynomial_calculator p);
}

TEST(polynomial_calculator, can_create_Polynom_with_start_parameters) {
    ASSERT_NO_THROW(polynomial_calculator p("2x^5y^4z+3x^2"));
}

TEST(polynomial_calculator, can_split_into_lexem_number) {
    polynomial_calculator P;
    ASSERT_NO_THROW(P.lexem("52"));
}

TEST(polynomial_calculator, can_split_into_lexem_parameter) {
    polynomial_calculator P;
    ASSERT_NO_THROW(P.lexem("-81.5y"));
}

TEST(polynomial_calculator, can_split_into_lexem_polynom) {
    polynomial_calculator P;
    ASSERT_NO_THROW(P.lexem("2xz^5y + 5z^2-2xy*5"));
}

TEST(polynomial_calculator, can_split_into_lexem_polynom_2) {
    polynomial_calculator P;
    ASSERT_NO_THROW(P.lexem("2xz^5y+5z^2 -2xy*5 + 9.2"));
}

TEST(polynomial_calculator, searches_for_invalid_characters) {
    polynomial_calculator P;
    ASSERT_ANY_THROW(P.parser("5x @ + # 1"));
}

TEST(polynomial_calculator, parser_and_lexem_no_throw_
recognizes_repetitions_of_signs) {
    polynomial_calculator P;
    polynomial_calculator Q("-2xz^5y+5x^2");
    ASSERT_NO_THROW(P.parser("-2xz^5y++5x^2"));
    ASSERT_EQ(Q, P);
}

TEST(polynomial_calculator, parser_and_lexem_no_throw_recording_test_1) {
    polynomial_calculator P;
    polynomial_calculator Q("2xy+5x^2z");
    ASSERT_NO_THROW(P.parser("2xy--5x^2z"));
    ASSERT_EQ(Q, P);
}

TEST(polynomial_calculator, parser_and_lexem_no_throw_recording_test_2) {
    polynomial_calculator P;
    polynomial_calculator Q("2xyz-5x^2z");
    ASSERT_NO_THROW(P.parser("2xyz-+5x^2z"));
    ASSERT_EQ(Q, P);
}

TEST(polynomial_calculator, parser_and_lexem_no_throw_recording_test_3) {
    polynomial_calculator P;
    polynomial_calculator Q("2xyz^3+5x^2-5x^6zy^2");
    ASSERT_NO_THROW(P.parser("+2xyz^3+5x^2+-5x^6zy^2"));
    ASSERT_EQ(Q, P);
}

TEST(polynomial_calculator, parser_and_lexem_no_throw_
    recording_test_on_big_polynomials) {
    polynomial_calculator P;
    polynomial_calculator Q("2xy^5z+5x^2z-5x^6yz");
    ASSERT_NO_THROW(P.parser("-5xyz+2xy^5z+5x^2z+-5x^6yz+5xyz"));
    ASSERT_EQ(Q, P);
}

TEST(polynomial_calculator, parser_and_lexem_no_throw
    _recognizes_multiplication) {
    polynomial_calculator P;
    polynomial_calculator Q("2x^3y^2z+5");
    ASSERT_NO_THROW(P.parser("2xx^2yyz+5"));
    ASSERT_EQ(Q, P);
}

TEST(polynomial_calculator, parser_and_lexem_no_recording
    _test_on_big_polynomials_2) {
    polynomial_calculator P;
    polynomial_calculator Q("2x^2zzy2yx+5xxy5yzz");
    ASSERT_NO_THROW(P.parser("4x^3y^2z^2+25x^2y^2z^2"));
    ASSERT_EQ(Q, P);
}

TEST(polynomial_calculator, polynomial_calculator_can
    _Detect_Wrong_Operation_Format) {
    polynomial_calculator P;
    ASSERT_ANY_THROW(P.parser("2x^yz"));
}

TEST(polynomial_calculator, parser_and_lexem
    _unidentified_characters) {
    polynomial_calculator P;
    ASSERT_ANY_THROW(P.parser("2x^2 &+5x"));
}

TEST(polynomial_calculator, polynomial_calculator_can
    _Detect_Wrong_Number_Format) {
    polynomial_calculator P;
    ASSERT_ANY_THROW(P.parser("2x^5+/3x^4 -2.6 x^3+x^2$$+x- 8.6"));
}

TEST(polynomial_calculator, equality_operator_test
    _compares_the_same) {
    polynomial_calculator P("2x^2yz^3+5x^3z^5y");
    polynomial_calculator Q("5yz^5x^3+2x^2z^3y");
    ASSERT_EQ(Q, P);
}

TEST(polynomial_calculator, equality_operator_test
    _compares_different) {
    polynomial_calculator P("2xy+5zx^2+10");
    polynomial_calculator Q("2xy+5zx^3");
    ASSERT_NE(Q, P);
}

TEST(polynomial_calculator, function_cancellation_zero) {
    polynomial_calculator P;
    ASSERT_NO_THROW(P.cancellation(););
}

TEST(polynomial_calculator, function_cancellation_no_throw) {
    polynomial_calculator P("-2x^2yyz+5x^2+z+z+zy+yz");
    ASSERT_NO_THROW(P.cancellation(););
}

TEST(polynomial_calculator, function_cancellation_correctly) {
    polynomial_calculator P("x^2yz+zyx^2+1+1+1+1+xy+yx+xy+x^3yz^5");
    P.cancellation();
    polynomial_calculator Q("x^3yz^5+2x^2zy+3xy+4");
    ASSERT_EQ(Q, P);
}

TEST(polynomial_calculator, addition_operation_no_throw) {
    polynomial_calculator P("2xyz+5xy+5");
    polynomial_calculator Q("3zxy+2+x");
    ASSERT_NO_THROW(P + Q);
}

TEST(polynomial_calculator, addition_operation_correctly) {
    polynomial_calculator P("2.3xyz+2x-3z+5.1x^2z");
    polynomial_calculator Q("3.1zxy+5+5,5x^2z");
    polynomial_calculator Res("5.4xyz+10,6x^2z+2x-3z+5");
    ASSERT_EQ(Res, P + Q);
}

TEST(polynomial_calculator, addition_operation
    _if_one_polynom_is_zero) {
    polynomial_calculator P("2xyz");
    polynomial_calculator Q("2x-2x");
    Q.cancellation();
    polynomial_calculator Res("2xyz");
    ASSERT_EQ(Res, P + Q);
}

TEST(polynomial_calculator, minus_operation_no_throw) {
    polynomial_calculator P("2xyz");
    polynomial_calculator Q("3zxy");
    ASSERT_NO_THROW(P - Q);
}

TEST(polynomial_calculator, minus_operation_correctly) {
    polynomial_calculator P("5.6xyz+4+1+x");
    polynomial_calculator Q("0.1xyz+6-x^2");
    polynomial_calculator Res("5.5xyz-1+x+x^2");
    ASSERT_EQ(Res, P - Q);
}

TEST(polynomial_calculator, minus_operation_zero_1) {
    polynomial_calculator P("2xy^2");
    polynomial_calculator Q("2xy-2xy");
    Q.cancellation();
    polynomial_calculator Res("2xy^2");
    ASSERT_EQ(Res, P - Q);
}

TEST(polynomial_calculator, minus_operation_if_
    one_polynom_is_zero) {
    polynomial_calculator P("2xy^2");
    polynomial_calculator Q("2xy-2xy");
    Q.cancellation();
    polynomial_calculator Res("-2xy^2");
    ASSERT_EQ(Res, Q - P);
}

TEST(polynomial_calculator, minus_operation_if_
    one_polynom_is_zero_2) {
    polynomial_calculator P("2xy^2");
    polynomial_calculator Q("0");
    Q.cancellation();
    polynomial_calculator Res("-2xy^2");
    ASSERT_EQ(Res, Q - P);
}

TEST(polynomial_calculator, multi_operation_no_throw) {
    polynomial_calculator P("2xyz-5");
    polynomial_calculator Q("3zxy+x^2");
    ASSERT_NO_THROW(P * Q);
}

TEST(polynomial_calculator, multi_operation_correctly) {
    polynomial_calculator P("5.5xyz+4+1+x");
    polynomial_calculator Q("xyz+6-x^2");
    polynomial_calculator Res("5,5x^2y^2z^2+38xyz-5.5x^3yz+30-5x^2+x^2yz+6x-x^3");
    ASSERT_EQ(Res, P * Q);
}

TEST(polynomial_calculator, multi_operation_if_
    one_polynom_is_zero) {
    polynomial_calculator P("2xy^2");
    polynomial_calculator Q("0");
    Q.cancellation();
    polynomial_calculator Res("0");
    ASSERT_EQ(Res, Q * P);
}

TEST(polynomial_calculator, addition_const_operation_no_throw) {
    polynomial_calculator P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    ASSERT_NO_THROW(P + 5);
}

TEST(polynomial_calculator, addition_const_operation_correctly) {
    polynomial_calculator P("2xyz");
    polynomial_calculator Res("2xyz+5");
    ASSERT_EQ(Res, P + 5);
}

TEST(polynomial_calculator, addition_zero_and_polynom_correctly) {
    polynomial_calculator P("2xyz");
    polynomial_calculator Res("2xyz");
    ASSERT_EQ(Res, P + 0);
}

TEST(polynomial_calculator, minus_const_operation_no_throw) {
    polynomial_calculator P("15xyz^2+5");
    ASSERT_NO_THROW(P - 5);
}

TEST(polynomial_calculator, minus_const_operation_correctly) {
    polynomial_calculator P("5.5xyz+4+1+2+3+x");
    polynomial_calculator Res("5.5xyz+x+5");
    ASSERT_EQ(Res, P - 5);
}

TEST(polynomial_calculator, minus_zero_and_polynom_correctly) {
    polynomial_calculator P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    polynomial_calculator Res("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    ASSERT_EQ(Res, P - 0);
}

TEST(polynomial_calculator, multi_const_operation_no_throw) {
    polynomial_calculator P("25x^2zy+5xyz+5z+x");
    ASSERT_NO_THROW(P * 5);
}

TEST(polynomial_calculator, multi_const_operation_correctly) {
    polynomial_calculator P("5x^2zy+5xyz-2z+x");
    polynomial_calculator Res("25x^2zy+25xyz-10z+5x");
    ASSERT_EQ(Res, P * 5);
}

TEST(polynomial_calculator, multi_negative_const_operation_correctly) {
    polynomial_calculator P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    polynomial_calculator Res("-6x^5y^2z^5+10x^4y^3z^3-14x^3y^5z");
    ASSERT_EQ(Res, P * (-2));
}

TEST(polynomial_calculator, multi_zero_and_polynom_correctly) {
    polynomial_calculator P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    polynomial_calculator Res("0");
    ASSERT_EQ(Res, P * (0));
}

TEST(Polynom, cout) {
    polynomial_calculator P("5+15+5xy-1x^2yz-z-xyz+1x^1y^3z+7x^3y^5z+5+9");
}
