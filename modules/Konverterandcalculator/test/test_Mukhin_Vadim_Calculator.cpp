// Copyright 2023 Mukhin Vadim

#include <gtest/gtest.h>

#include "include/Calculator.h"
#include "include/Converter.h"

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM) {
    std::string num1 = "10";
    int base1 = 10;
    std::string num2 = "1";
    int base2 = 10;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "11");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_DIFF) {
    std::string num1 = "10";
    int base1 = 10;
    std::string num2 = "1";
    int base2 = 10;
    std::string diff = subtract(num1, base1, num2, base2);
    EXPECT_EQ(diff, "9");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_PRODUCT) {
    std::string num1 = "10";
    int base1 = 10;
    std::string num2 = "1";
    int base2 = 10;
    std::string product = multiply(num1, base1, num2, base2);
    EXPECT_EQ(product, "10");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_DIV) {
    std::string num1 = "10";
    int base1 = 10;
    std::string num2 = "1";
    int base2 = 10;
    std::string quotient = divide(num1, base1, num2, base2);
    EXPECT_EQ(quotient, "10");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER) {
    std::string num = "101001";
    int base1 = 2;
    int base2 = 10;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "41");
}
