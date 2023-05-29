// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/bigInt.h"

TEST(BigIntTest, DefaultConstructorTest) {
    BigInt x;
    EXPECT_FALSE(x.is_negative);
    EXPECT_EQ(x.digits, "0");
}

TEST(BigIntTest, SingleParameterConstructorTest) {
    BigInt x(12345);
    BigInt y(-12345);

    EXPECT_FALSE(x.is_negative);
    EXPECT_EQ(x.digits, "12345");
    EXPECT_TRUE(y.is_negative);
    EXPECT_EQ(y.digits, "12345");
}

TEST(BigIntTest, CopyConstructorTest) {
    BigInt x(1234567891011121314151617);
    BigInt y(x);

    EXPECT_EQ(x.is_negative, y.is_negative);
    EXPECT_EQ(x.digits, y.digits);
}

TEST(BigIntTest, AssignmentOperatorTest) {.
    BigInt x(12345678901234567890);
    BigInt y;

    y = x;

    EXPECT_EQ(x.is_negative, y.is_negative);
    EXPECT_EQ(x.digits, y.digits);
}

TEST(BigIntConstructor, LargePositiveNumber) {
    BigInt a("123456789012345678901234567890");
    EXPECT_EQ(a.is_negative, false);
    EXPECT_EQ(a.digits, "123456789012345678901234567890");
}

TEST(BigIntConstructor, LargeNegativeNumber) {
    BigInt a("-123456789012345678901234567890");
    EXPECT_EQ(a.is_negative, true);
    EXPECT_EQ(a.digits, "123456789012345678901234567890");
}

TEST(BigIntTest, AdditionTest) {
    BigInt a("99999999999999999999");
    BigInt b("1");
    BigInt c("100000000000000000000");
    EXPECT_EQ(a + b, c);
}

TEST(BigIntTest, MultiplicationTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("199999999999999999998");
    EXPECT_EQ(a * b, c);
}

TEST(BigIntTest, GreaterThanOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("98765432109876543210987654321");
    BigInt c("-123456789012345678901234567890");

    EXPECT_FALSE(c > b);
    EXPECT_TRUE(a > c);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b > c);
}

TEST(BigIntTest, GreaterThanOrEqualToOperatorTest) {
    BigInt a("1364763897649287634876836487");
    BigInt b("1364763897649287634876836487");
    BigInt c("-1364763897649287634876836487");

    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a >= b);
    EXPECT_TRUE(a >= c);
    EXPECT_FALSE(c >= a);
    EXPECT_TRUE(b >= b);
}

TEST(BigIntTest, LessThanOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-12345678901234567890123456781");

    EXPECT_TRUE(b < a);
    EXPECT_FALSE(a < b);
}

TEST(BigIntTest, LessThanOrEqualToOperatorTest) {
    BigInt a("-123456789012345678901234567890");
    BigInt b("123456789012345678901234567890");

    EXPECT_TRUE(a <= b);
}

TEST(BigIntTest, EqualityOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-123456789012345678901234567890");
    BigInt c("123456789012345678901234567890");

    EXPECT_TRUE(a == a);
    EXPECT_TRUE(a == c);
    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == c);
}

TEST(BigIntTest, NotEqualityOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-123456789012345678901234567890");
    BigInt c("123456789012345678901234567890");

    EXPECT_FALSE(a != a);
    EXPECT_FALSE(a != c);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != c);
}
