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
    EXPECT_EQ(sum, "109");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM9) {
    std::string num1 = "1f";
    int base1 = 16;
    std::string num2 = "FF";
    int base2 = 16;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "11E");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM10) {
    std::string num1 = "0";
    int base1 = 16;
    std::string num2 = "0";
    int base2 = 16;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "0");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM2) {
    std::string num1 = "1010";
    int base1 = 2;
    std::string num2 = "11";
    int base2 = 2;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "1101");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM3) {
    std::string num1 = "102";
    int base1 = 10;
    std::string num2 = "1";
    int base2 = 10;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "103");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM4) {
    std::string num1 = "1010";
    int base1 = 2;
    std::string num2 = "11";
    int base2 = 10;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "21");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM5) {
    std::string num1 = "110000";
    int base1 = 10;
    std::string num2 = "1F";
    int base2 = 16;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "1ADCF");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_DIFF) {
    std::string num1 = "f";
    int base1 = 16;
    std::string num2 = "8";
    int base2 = 10;
    std::string diff = subtract(num1, base1, num2, base2);
    EXPECT_EQ(diff, "7");
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
    std::string num1 = "15";
    int base1 = 8;
    std::string num2 = "10";
    int base2 = 2;
    std::string quotient = divide(num1, base1, num2, base2);
    EXPECT_EQ(quotient, "6");
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
TEST(Mukhin_Vadim_Konverter_and_calculator, TestAdd) {
    // Проверяем сложение чисел в системе счисления 10
    std::string num1 = "123";
    std::string num2 = "456";
    int base1 = 10;
    int base2 = 10;
    std::string expected = "579";
    std::string result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в системе счисления 2
    num1 = "1010";
    num2 = "1101";
    base1 = 2;
    base2 = 2;
    expected = "10111";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);
}
TEST(AddTest, TestAdd) {
    // Проверяем сложение чисел в системе счисления 10
    std::string num1 = "123";
    std::string num2 = "456";
    int base1 = 10;
    int base2 = 10;
    std::string expected = "579";
    std::string result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в системе счисления 2
    num1 = "1010";
    num2 = "1101";
    base1 = 2;
    base2 = 2;
    expected = "10111";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в системе счисления 16
    num1 = "FF";
    num2 = "1A";
    base1 = 16;
    base2 = 16;
    expected = "119";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в системе счисления 8
    num1 = "77";
    num2 = "12";
    base1 = 8;
    base2 = 8;
    expected = "111";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в разных системах счисления
    num1 = "5";
    num2 = "10";
    base1 = 16;
    base2 = 10;
    expected = "F";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в разных системах счисления
    num1 = "101";
    num2 = "11";
    base1 = 2;
    base2 = 8;
    expected = "16";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в разных системах счисления
    num1 = "1111";
    num2 = "1111";
    base1 = 2;
    base2 = 16;
    expected = "1120";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);
}
TEST(Mukhin_Vadim_Konverter_and_calculator, TES) {
    std::string result1 = add("123", 10, "456", 10);
    assert(result1 == "579");
    std::string result2 = add("ABCD", 16, "123", 16);
    assert(result2 == "ACF0");
    std::string result3 = add("123", 10, "0", 10);
    assert(result3 == "123");
    std::string result4 = add("0", 10, "456", 10);
    assert(result4 == "456");
    std::string result5 = add("ABC", 16, "1010", 2);
    assert(result5 == "AC6");
    std::string result6 = add("10", 2, "7", 8);
    assert(result6 == "11"); 
    std::string result7 = add("123", 10, "12345", 10);
    assert(result7 == "12468");
    std::string result8 = add("0", 10, "0", 10);
    assert(result8 == "0");
}
