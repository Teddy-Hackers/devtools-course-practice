// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/bigInt.h"

TEST(BigIntTest, DefaultConstructorTest) {
    BigInt x;
    EXPECT_FALSE(x.is_negative);
    EXPECT_EQ(x.digits, "0");
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

TEST(BigIntTest, GreaterThanOperatorTestFirst) {
    BigInt b("98765432109876543210987654321");
    BigInt c("-123456789012345678901234567890");

    EXPECT_FALSE(c > b);
}

TEST(BigIntTest, GreaterThanOperatorTestSecond) {
    BigInt a("123456789012345678901234567890");
    BigInt c("-123456789012345678901234567890");

    EXPECT_TRUE(a > c);
}

TEST(BigIntTest, GreaterThanOperatorTestThird) {
    BigInt a("123456789012345678901234567890");
    BigInt b("98765432109876543210987654321");

    EXPECT_TRUE(b > a);
}

TEST(BigIntTest, GreaterThanOperatorTest) {
    BigInt b("98765432109876543210987654321");
    BigInt c("-123456789012345678901234567890");

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

TEST(BigIntTest, LessThanOperatorTestFirst) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-12345678901234567890123456781");

    EXPECT_TRUE(b < a);
    EXPECT_FALSE(a < b);
}

TEST(BigIntTest, LessThanOperatorTestSecond) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-12345678901234567890123456781");

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

TEST(BigIntTest, AddAbsTest) {
    // Test 1: adding two single-digit numbers
    std::string a = "3";
    std::string b = "7";
    std::string expected = "10";
    EXPECT_EQ(BigInt::add_abs(a, b), expected);
}
