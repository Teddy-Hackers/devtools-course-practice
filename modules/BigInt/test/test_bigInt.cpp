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
