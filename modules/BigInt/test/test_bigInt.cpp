// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/bigInt.h"

TEST(BigIntConstructor, LargePositiveNumber) {
    BigInt a("123456789012345678901234567890");
    EXPECT_EQ(a.is_negative, false);
    EXPECT_EQ(a.digits, "123456789012345678901234567890");
}

TEST(BigIntTest, DefaultConstructorTest) {
    BigInt a;
    EXPECT_EQ(a.to_string(), "0");
}

TEST(BigIntTest, IntConstructorTest) {
    BigInt a(123);
    EXPECT_EQ(a.to_string(), "123");
}

TEST(BigIntTest, StringConstructorTest) {
    BigInt a("12345678901234567890");
    EXPECT_EQ(a.to_string(), "12345678901234567890");
}

TEST(BigIntTest, AdditionTest) {
    BigInt a("99999999999999999999");
    BigInt b("1");
    BigInt c("100000000000000000000");
    EXPECT_EQ(a + b, c);
}

TEST(BigIntTest, SubtractionTest) {
    BigInt a("100000000000000000000");
    BigInt b("1");
    BigInt c("99999999999999999999");
    EXPECT_EQ(a - b, c);
}

TEST(BigIntTest, MultiplicationTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("199999999999999999998");
    EXPECT_EQ(a * b, c);
}

TEST(BigIntTest, DivisionTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("50000000000000000000");
    EXPECT_EQ(a / b, c);
}

TEST(BigIntTest, ModulusTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("1");
    EXPECT_EQ(a % b, c);
}

TEST(BigIntTest, GreaterThanTest) {
    BigInt a("99999999999999999999");
    BigInt b("1");
    EXPECT_TRUE(a > b);
    EXPECT_FALSE(b > a);
}

TEST(BigIntTest, GreaterThanOrEqualToTest) {
    BigInt a("99999999999999999999");
    BigInt b("1");
    EXPECT_TRUE(a >= b);
    EXPECT_TRUE(a >= a);
    EXPECT_FALSE(b >= a);
}

TEST(BigIntTest, LessThanTest) {
    BigInt a("99999999999999999999");
    BigInt b("100000000000000000000");
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(b < a);
}

TEST(BigIntTest, ToStringTest) {
    BigInt a("-99999999999999999999");
    EXPECT_EQ(a.to_string(), "-99999999999999999999");
}

TEST(BigIntConstructor, LargeNegativeNumber) {
    BigInt a("-123456789012345678901234567890");
    EXPECT_EQ(a.is_negative, true);
    EXPECT_EQ(a.digits, "123456789012345678901234567890");
}

TEST(BigIntAdditionOperator, LargePositiveNumbers) {
    BigInt a("123456789012345678901234567890");
    BigInt b("987654321098765432109876543210");
    BigInt c = a + b;
    EXPECT_EQ(c.is_negative, false);
    EXPECT_EQ(c.digits, "1111111111111111111111111111100");
}

TEST(BigIntSubtractionOperator, LargePositiveNumbers) {
    BigInt a("987654321098765432109876543210");
    BigInt b("123456789012345678901234567890");
    BigInt c = a - b;
    EXPECT_EQ(c.is_negative, false);
    EXPECT_EQ(c.digits, "864197532086419753209641975320");
}

TEST(BigIntMultiplicationOperator, LargePositiveNumbers) {
    BigInt a("123456789012345678901234567890");
    BigInt b("987654321098765432109876543210");
    BigInt c = a * b;
    EXPECT_EQ(c.is_negative, false);
    EXPECT_EQ(c.digits,
    "121932631137021795533554550190627632733303376645344100");
}

TEST(BigIntDivisionOperator, LargePositiveNumbers) {
    BigInt a("123456789012345678901234567890");
    BigInt b("123");
    BigInt c = a / b;
    EXPECT_EQ(c.is_negative, false);
    EXPECT_EQ(c.digits, "1003713695366971753455448031");
}

TEST(BigIntModuloOperator, LargePositiveNumbers) {
    BigInt a("123456789012345678901234567890");
    BigInt b("123");
    BigInt c = a % b;
    EXPECT_EQ(c.is_negative, false);
    EXPECT_EQ(c.digits, "45");
}

TEST(BigIntGreaterOperator, LargePositiveNumbers) {
    BigInt a("123456789012345678901234567890");
    BigInt b("987654321098765432109876543210");
    EXPECT_EQ(a > b, false);
    EXPECT_EQ(b > a, true);
}
