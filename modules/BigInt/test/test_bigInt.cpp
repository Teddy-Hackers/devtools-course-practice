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

TEST(BigIntTest, GreaterThanTest) {
    BigInt a("123456");
    BigInt b("123456789");

    EXPECT_FALSE(a > b);
    EXPECT_TRUE(b > a);
    EXPECT_FALSE(a > a);
}

TEST(BigIntTest, GreaterThanOrEqualToTest) {
    BigInt a("123456");
    BigInt b("123456789");

    EXPECT_FALSE(a >= b);
    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a >= a);
}

TEST(BigIntTest, LessThanTest) {
    BigInt a("123456");
    BigInt b("123456789");

    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
    EXPECT_FALSE(a < a);
}

TEST(BigIntTest, LessThanOrEqualToTest) {
    BigInt a("123456");
    BigInt b("123456789");

    EXPECT_TRUE(a <= b);
    EXPECT_FALSE(b <= a);
    EXPECT_TRUE(a <= a);
}
