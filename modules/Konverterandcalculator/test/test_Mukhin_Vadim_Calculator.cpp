// Copyright 2023 Mukhin Vadim

#include <gtest/gtest.h>

#include "include/Calculator.h"
#include "include/Converter.h"

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM) {
    std::String num1 = "10";
    int base1 = 10;
    std::String num2 = "1";
    int base2 = 10;
    // slovo
    std::String sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "11");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_DIFF) {
    std::String num1 = "10";
    int base1 = 10;
    std::String num2 = "1";
    int base2 = 10;
    std::String diff = subtract(num1, base1, num2, base2);
    EXPECT_EQ(diff, "9");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_PRODUCT) {
    std::String num1 = "10";
    int base1 = 10;
    std::String num2 = "1";
    int base2 = 10;
    std::String product = multiply(num1, base1, num2, base2);
    EXPECT_EQ(product, "10");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_DIV) {
    std::String num1 = "10";
    int base1 = 10;
    std::String num2 = "1";
    int base2 = 10;
    std::String quotient = divide(num1, base1, num2, base2);
    EXPECT_EQ(quotient, "10");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER) {
    std::String num = "101001";
    int base1 = 2;
    int base2 = 10;
    std::String result = convert(num, base1, base2);
    EXPECT_EQ(result, "41");
}
