// Copyright 2023 Eremin Aleksandr

#include <gtest/gtest.h>

#include "include/Polynom.h"

#include "include/Monom.h"


TEST(Polynom, can_create_Polynom_no_value) {
    ASSERT_NO_THROW(Polynom p);
}

TEST(Polynom, can_create_Polynom_with_start_parameters) {
    ASSERT_NO_THROW(Polynom p("2x^5y^4z+3x^2"));
}

TEST(Polynom, can_split_into_lexem_number) {
    Polynom P;
    ASSERT_NO_THROW(P.lexem("52"));
}

TEST(Polynom, can_split_into_lexem_parameter) {
    Polynom P;
    ASSERT_NO_THROW(P.lexem("-81.5y"));
}

TEST(Polynom, can_split_into_lexem_polynom) {
    Polynom P;
    ASSERT_NO_THROW(P.lexem("2xz^5y + 5z^2-2xy*5"));
}

TEST(Polynom, can_split_into_lexem_polynom_2) {
    Polynom P;
    ASSERT_NO_THROW(P.lexem("2xz^5y+5z^2 -2xy*5 + 9.2"));
}

TEST(Polynom, searches_for_invalid_characters) {
    Polynom P;
    ASSERT_ANY_THROW(P.parser("5x @ + # 1"));
}

TEST(Polynom, parser_and_lexem_no_throw_recognizes_repetitions_of_signs) {
    Polynom P;
    Polynom Q("-2xz^5y+5x^2");
    ASSERT_NO_THROW(P.parser("-2xz^5y++5x^2"));
    ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_recording_test_1) {
    Polynom P;
    Polynom Q("2xy+5x^2z");
    ASSERT_NO_THROW(P.parser("2xy--5x^2z"));
    ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_recording_test_2) {
    Polynom P;
    Polynom Q("2xyz-5x^2z");
    ASSERT_NO_THROW(P.parser("2xyz-+5x^2z"));
    ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_recording_test_3) {
    Polynom P;
    Polynom Q("2xyz^3+5x^2-5x^6zy^2");
    ASSERT_NO_THROW(P.parser("+2xyz^3+5x^2+-5x^6zy^2"));
    ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_recording_test_on_big_polynomials) {
    Polynom P;
    Polynom Q("2xy^5z+5x^2z-5x^6yz");
    ASSERT_NO_THROW(P.parser("-5xyz+2xy^5z+5x^2z+-5x^6yz+5xyz"));
    ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_throw_recognizes_multiplication) {
    Polynom P;
    Polynom Q("2x^3y^2z+5");
    ASSERT_NO_THROW(P.parser("2xx^2yyz+5"));
    ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_no_recording_test_on_big_polynomials_2) {
    Polynom P;
    Polynom Q("2x^2zzy2yx+5xxy5yzz");
    ASSERT_NO_THROW(P.parser("4x^3y^2z^2+25x^2y^2z^2"));
    ASSERT_EQ(Q, P);
}

TEST(Polynom, parser_and_lexem_degree_is_not_a_number) {
    Polynom P;
    ASSERT_ANY_THROW(P.parser("2x^yz"));
}

TEST(Polynom, parser_and_lexem_unidentified_characters) {
    Polynom P;
    ASSERT_ANY_THROW(P.parser("2x^2 &+5x"));
}

TEST(Polynom, parser_and_lexem_unidentified_characters_many) {
    Polynom P;
    ASSERT_ANY_THROW(P.parser("2x^5+/3x^4 -2.6 x^3+x^2$$+x- 8.6"));
}

TEST(Polynom, equality_operator_test_compares_the_same) {
    Polynom P("2x^2yz^3+5x^3z^5y");
    Polynom Q("5yz^5x^3+2x^2z^3y");
    ASSERT_EQ(Q, P);
}

TEST(Polynom, equality_operator_test_compares_different) {
    Polynom P("2xy+5zx^2+10");
    Polynom Q("2xy+5zx^3");
    ASSERT_NE(Q, P);
}

TEST(Polynom, function_cancellation_zero) {
    Polynom P;
    ASSERT_NO_THROW(P.cancellation(););
}

TEST(Polynom, function_cancellation_no_throw) {
    Polynom P("-2x^2yyz+5x^2+z+z+zy+yz");
    ASSERT_NO_THROW(P.cancellation(););
}

TEST(Polynom, function_cancellation_correctly) {
    Polynom P("x^2yz+zyx^2+1+1+1+1+xy+yx+xy+x^3yz^5");
    P.cancellation();
    Polynom Q("x^3yz^5+2x^2zy+3xy+4");
    ASSERT_EQ(Q, P);
}

TEST(Polynom, addition_operation_no_throw) {
    Polynom P("2xyz+5xy+5");
    Polynom Q("3zxy+2+x");
    ASSERT_NO_THROW(P + Q);
}

TEST(Polynom, addition_operation_correctly) {
    Polynom P("2.3xyz+2x-3z+5.1x^2z");
    Polynom Q("3.1zxy+5+5,5x^2z");
    Polynom Res("5.4xyz+10,6x^2z+2x-3z+5");
    ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, addition_operation_if_one_polynom_is_zero) {
    Polynom P("2xyz");
    Polynom Q("2x-2x");
    Q.cancellation();
    Polynom Res("2xyz");
    ASSERT_EQ(Res, P + Q);
}

TEST(Polynom, minus_operation_no_throw) {
    Polynom P("2xyz");
    Polynom Q("3zxy");
    ASSERT_NO_THROW(P - Q);
}

TEST(Polynom, minus_operation_correctly) {
    Polynom P("5.6xyz+4+1+x");
    Polynom Q("0.1xyz+6-x^2");
    Polynom Res("5.5xyz-1+x+x^2");
    ASSERT_EQ(Res, P - Q);
}

TEST(Polynom, minus_operation_zero_1) {
    Polynom P("2xy^2");
    Polynom Q("2xy-2xy");
    Q.cancellation();
    Polynom Res("2xy^2");
    ASSERT_EQ(Res, P - Q);
}

TEST(Polynom, minus_operation_if_one_polynom_is_zero) {
    Polynom P("2xy^2");
    Polynom Q("2xy-2xy");
    Q.cancellation();
    Polynom Res("-2xy^2");
    ASSERT_EQ(Res, Q - P);
}

TEST(Polynom, minus_operation_if_one_polynom_is_zero_2) {
    Polynom P("2xy^2");
    Polynom Q("0");
    Q.cancellation();
    Polynom Res("-2xy^2");
    ASSERT_EQ(Res, Q - P);
}

TEST(Polynom, multi_operation_no_throw) {
    Polynom P("2xyz-5");
    Polynom Q("3zxy+x^2");
    ASSERT_NO_THROW(P * Q);
}

TEST(Polynom, multi_operation_correctly) {
    Polynom P("5.5xyz+4+1+x");
    Polynom Q("xyz+6-x^2");
    Polynom Res("5,5x^2y^2z^2+38xyz-5.5x^3yz+30-5x^2+x^2yz+6x-x^3");
    ASSERT_EQ(Res, P * Q);
}

TEST(Polynom, multi_operation_if_one_polynom_is_zero) {
    Polynom P("2xy^2");
    Polynom Q("0");
    Q.cancellation();
    Polynom Res("0");
    ASSERT_EQ(Res, Q * P);
}

TEST(Polynom, addition_const_operation_no_throw) {
    Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    ASSERT_NO_THROW(P + 5);
}

TEST(Polynom, addition_const_operation_correctly) {
    Polynom P("2xyz");
    Polynom Res("2xyz+5");
    ASSERT_EQ(Res, P + 5);
}

TEST(Polynom, addition_zero_and_polynom_correctly) {
    Polynom P("2xyz");
    Polynom Res("2xyz");
    ASSERT_EQ(Res, P + 0);
}

TEST(Polynom, minus_const_operation_no_throw) {
    Polynom P("15xyz^2+5");
    ASSERT_NO_THROW(P - 5);
}

TEST(Polynom, minus_const_operation_correctly) {
    Polynom P("5.5xyz+4+1+2+3+x");
    Polynom Res("5.5xyz+x+5");
    ASSERT_EQ(Res, P - 5);
}

TEST(Polynom, minus_zero_and_polynom_correctly) {
    Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    Polynom Res("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    ASSERT_EQ(Res, P - 0);
}

TEST(Polynom, multi_const_operation_no_throw) {
    Polynom P("25x^2zy+5xyz+5z+x");
    ASSERT_NO_THROW(P * 5);
}

TEST(Polynom, multi_const_operation_correctly) {
    Polynom P("5x^2zy+5xyz-2z+x");
    Polynom Res("25x^2zy+25xyz-10z+5x");
    ASSERT_EQ(Res, P * 5);
}

TEST(Polynom, multi_negative_const_operation_correctly) {
    Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    Polynom Res("-6x^5y^2z^5+10x^4y^3z^3-14x^3y^5z");
    ASSERT_EQ(Res, P * (-2));
}

TEST(Polynom, multi_zero_and_polynom_correctly) {
    Polynom P("3x^5y^2z^5-5x^4y^3z^3+7x^3y^5z");
    Polynom Res("0");
    ASSERT_EQ(Res, P * (0));
}

TEST(Polynom, cout) {
    Polynom P("5+15+5xy-1x^2yz-z-xyz+1x^1y^3z+7x^3y^5z+5+9");
}
