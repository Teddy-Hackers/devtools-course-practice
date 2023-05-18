// Copyright 2023 Frank Maksim

#include <gtest/gtest.h>

#include "include/Converter.h"
TEST(RomanNumeralConverterTest, CanConvertArabicToRoman) {
  EXPECT_EQ("I", toRoman(1));
  EXPECT_EQ("IV", toRoman(4));
  EXPECT_EQ("V", toRoman(5));
  EXPECT_EQ("IX", toRoman(9));
  EXPECT_EQ("X", toRoman(10));
  EXPECT_EQ("XL", toRoman(40));
  EXPECT_EQ("L", toRoman(50));
  EXPECT_EQ("XC", toRoman(90));
  EXPECT_EQ("C", toRoman(100));
  EXPECT_EQ("CD", toRoman(400));
  EXPECT_EQ("D", toRoman(500));
  EXPECT_EQ("CM", toRoman(900));
  EXPECT_EQ("M", toRoman(1000));
}

TEST(RomanNumeralConverterTest, CanConvertRomanToArabic) {
  EXPECT_EQ(1, toArabic("I"));
  EXPECT_EQ(4, toArabic("IV"));
  EXPECT_EQ(5, toArabic("V"));
  EXPECT_EQ(9, toArabic("IX"));
  EXPECT_EQ(10, toArabic("X"));
  EXPECT_EQ(40, toArabic("XL"));
  EXPECT_EQ(50, toArabic("L"));
  EXPECT_EQ(90, toArabic("XC"));
  EXPECT_EQ(100, toArabic("C"));
  EXPECT_EQ(400, toArabic("CD"));
  EXPECT_EQ(500, toArabic("D"));
  EXPECT_EQ(900, toArabic("CM"));
  EXPECT_EQ(1000, toArabic("M"));
}
