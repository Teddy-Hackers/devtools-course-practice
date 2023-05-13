// Copyright 2023 Mukhin Vadim

#include <gtest/gtest.h>

#include "include/Calculator.h"
#include "include/Converter.h"

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM) {
    std::string num1 = "1010";
    int base1 = 2;
    std::string num2 = "FF";
    int base2 = 16;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "100001001");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_DIFF) {
    std::string num1 = "f";
    int base1 = 16;
    std::string num2 = "7";
    int base2 = 10;
    std::string diff = subtract(num1, base1, num2, base2);
    EXPECT_EQ(diff, "8");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_PRODUCT) {
    std::string num1 = "4";
    int base1 = 10;
    std::string num2 = "6";
    int base2 = 8;
    std::string product = multiply(num1, base1, num2, base2);
    EXPECT_EQ(product, "24");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_DIV) {
    std::string num1 = "f";
    int base1 = 8;
    std::string num2 = "10100";
    int base2 = 2;
    std::string quotient = divide(num1, base1, num2, base2);
    EXPECT_EQ(quotient, "3");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER) {
    std::string num = "101001";
    int base1 = 2;
    int base2 = 10;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "41");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER2) {
    std::string num = "10";
    int base1 = 10;
    int base2 = 8;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "12");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER3) {
    std::string num = "F";
    int base1 = 16;
    int base2 = 10;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "15");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER4) {
    std::string num = "a";
    int base1 = 16;
    int base2 = 10;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "10");
}
TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER5) {
    std::string num = "123456789";
    int base1 = 10;
    int base2 = 16;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "75BCD15");
}
