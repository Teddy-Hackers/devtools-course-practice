// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/bigInt.h"

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

TEST(BigIntTest, DivisionTest) {
    BigInt a("12345678901234567890");
    BigInt b("99999");
    BigInt c("123456789012345");

    EXPECT_EQ(a / b, c);
    EXPECT_EQ(a % b, BigInt("999908"));
}

TEST(BigIntTest, GreaterThanOperatorTest) {
    BigInt a("123");
    BigInt b("45");
    BigInt c("-123");

    EXPECT_TRUE(b > a);
    EXPECT_FALSE(a > b);
    EXPECT_FALSE(c > a);
    EXPECT_TRUE(a > c);
    EXPECT_FALSE(c > b);
}

TEST(BigIntTest, GreaterThanOrEqualToOperatorTest) {
    BigInt a("123");
    BigInt b("123");
    BigInt c("-123");

    EXPECT_TRUE(b >= a);
    EXPECT_FALSE(a >= b);
    EXPECT_TRUE(a >= c);
    EXPECT_FALSE(c >= a);
    EXPECT_TRUE(b >= b);
}

TEST(BigIntTest, LessThanOperatorTest) {
    BigInt a("123");
    BigInt b("45");
    BigInt c("-123");

    EXPECT_TRUE(b < a);
    EXPECT_FALSE(a < b);
    EXPECT_TRUE(c < a);
    EXPECT_FALSE(a < c);
    EXPECT_FALSE(c < c);
}

TEST(BigIntTest, LessThanOrEqualToOperatorTest) {
    BigInt a("123");
    BigInt b("123");
    BigInt c("-123");

    EXPECT_TRUE(b <= a);
    EXPECT_FALSE(a <= b);
    EXPECT_TRUE(c <= a);
    EXPECT_FALSE(a <= c);
    EXPECT_TRUE(b <= b);
}

TEST(BigIntTest, EqualityOperatorTest) {
    BigInt a("123");
    BigInt b("-123");
    BigInt c("456");
    BigInt d("123");

    EXPECT_TRUE(a == d);
    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == c);
    EXPECT_FALSE(a == c);
}

TEST(BigIntTest, NotEqualityOperatorTest) {
    BigInt a("123");
    BigInt b("-123");
    BigInt c("456");
    BigInt d("123");

    EXPECT_FALSE(a != d);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != c);
    EXPECT_TRUE(a != c);
}
