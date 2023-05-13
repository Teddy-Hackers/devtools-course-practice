// Copyright 2023 Mukhin Vadim
#include <iostream>
#include <string>
#include <cmath>

std::string add(std::string num1, int base1, std::string num2, int base2) {
    // Преобразуем числа из их систем счисления в десятичную систему
    int decimal1 = 0, decimal2 = 0;
    for (std::string::size_type i = 0; i < num1.length(); i++) {
        int digit = 0;
        if (num1[i] >= '0' && num1[i] <= '9') {
            digit = num1[i] - '0';
        } else if (num1[i] >= 'A' && num1[i] <= 'F') {
            digit = num1[i] - 'A' + 10;
        } else if (num1[i] >= 'a' && num1[i] <= 'f') {
            digit = num1[i] - 'a' + 10;
        }
        decimal1 += digit * pow(base1, num1.length() - 1 - i);
    }
    for (std::string::size_type i = 0; i < num2.length(); i++) {
        int digit = 0;
        if (num2[i] >= '0' && num2[i] <= '9') {
            digit = num2[i] - '0';
        } else if (num2[i] >= 'A' && num2[i] <= 'F') {
            digit = num2[i] - 'A' + 10;
        } else if (num2[i] >= 'a' && num2[i] <= 'f') {
            digit = num2[i] - 'a' + 10;
        }
        decimal2 += digit * pow(base2, num2.length() - 1 - i);
    }

    // Складываем числа в десятичной системе счисления
    int sumDecimal = decimal1 + decimal2;

    
    int base = std::max(base1, base2);
    std::string sum = "";
    while (sumDecimal > 0) {
        int digit = sumDecimal % base;
        char c = digit < 10 ? digit + '0' : digit - 10 + 'A';
        sum = c + sum;
        sumDecimal /= base;
    }

    // Если результат сложения пустой, то возвращаем "0"
    if (sum.empty()) {
        return "0";
    }

    return sum;
}

std::string subtract(std::string num1, int base1, std::string num2, int base2) {
    int decimal1 = 0, decimal2 = 0;

    if (base1 == 10) {
        decimal1 = stoi(num1);
    } else {
        for (int i = num1.length() - 1; i >= 0; i--) {
            int digit;
            if (num1[i] >= '0' && num1[i] <= '9')
            digit = num1[i] - '0';
            else if (num1[i] >= 'A' && num1[i] <= 'F')
            digit = num1[i] - 'A' + 10;
            else if (num1[i] >= 'a' && num1[i] <= 'f')
            digit = num1[i] - 'a' + 10;
            decimal1 += digit * pow(base1, num1.length() - 1 - i);
        }
    }

    if (base2 == 10) {
        decimal2 = stoi(num2);
    } else {
        for (int i = num2.length() - 1; i >= 0; i--) {
            int digit;
            if (num2[i] >= '0' && num2[i] <= '9')
            digit = num2[i] - '0';
            else if (num2[i] >= 'A' && num2[i] <= 'F')
            digit = num2[i] - 'A' + 10;
            else if (num2[i] >= 'a' && num2[i] <= 'f')
            digit = num2[i] - 'a' + 10;
            decimal2 += digit * pow(base2, num2.length() - 1 - i);
        }
    }

    int diffDecimal = decimal1 - decimal2;

    std::string diff = "";

    while (diffDecimal > 0) {
        int digit = diffDecimal % base1;
        char c;
        if (digit >= 0 && digit <= 9) c = digit + '0';
        else
        c = digit - 10 + 'A';

        diff = c + diff;
        diffDecimal /= base1;
    }

    return diff;
}

std::string multiply(std::string num1, int base1, std::string num2, int base2) {
    int decimal1 = 0, decimal2 = 0;

    if (base1 == 10) {
        decimal1 = stoi(num1);
    } else {
        for (int i = num1.length() - 1; i >= 0; i--) {
            int digit;
            if (num1[i] >= '0' && num1[i] <= '9')
            digit = num1[i] - '0';
            else if (num1[i] >= 'A' && num1[i] <= 'F')
            digit = num1[i] - 'A' + 10;
            else if (num1[i] >= 'a' && num1[i] <= 'f')
            digit = num1[i] - 'a' + 10;
            decimal1 += digit * pow(base1, num1.length() - 1 - i);
        }
    }

    if (base2 == 10) {
        decimal2 = stoi(num2);
    } else {
        for (int i = num2.length() - 1; i >= 0; i--) {
            int digit;
            if (num2[i] >= '0' && num2[i] <= '9')
            digit = num2[i] - '0';
            else if (num2[i] >= 'A' && num2[i] <= 'F')
            digit = num2[i] - 'A' + 10;
            else if (num2[i] >= 'a' && num2[i] <= 'f')
            digit = num2[i] - 'a' + 10;
            decimal2 += digit * pow(base2, num2.length() - 1 - i);
        }
    }

    int productDecimal = decimal1 * decimal2;

    std::string product = "";

    while (productDecimal > 0) {
        int digit = productDecimal % base1;
        char c;
        if (digit >= 0 && digit <= 9) c = digit + '0';
        else
        c = digit - 10 + 'A';

        product = c + product;
        productDecimal /= base1;
    }

    return product;
}

std::string divide(std::string num1, int base1, std::string num2, int base2) {
    int decimal1 = 0, decimal2 = 0;

    if (base1 == 10) {
        decimal1 = stoi(num1);
    } else {
        for (int i = num1.length() - 1; i >= 0; i--) {
            int digit;
            if (num1[i] >= '0' && num1[i] <= '9')
            digit = num1[i] - '0';
            else if (num1[i] >= 'A' && num1[i] <= 'F')
            digit = num1[i] - 'A' + 10;
            else if (num1[i] >= 'a' && num1[i] <= 'f')
            digit = num1[i] - 'a' + 10;
            decimal1 += digit * pow(base1, num1.length() - 1 - i);
        }
    }

    if (base2 == 10) {
        decimal2 = stoi(num2);
    } else {
        for (int i = num2.length() - 1; i >= 0; i--) {
            int digit;
            if (num2[i] >= '0' && num2[i] <= '9')
            digit = num2[i] - '0';
            else if (num2[i] >= 'A' && num2[i] <= 'F')
            digit = num2[i] - 'A' + 10;
            else if (num2[i] >= 'a' && num2[i] <= 'f')
            digit = num2[i] - 'a' + 10;
            decimal2 += digit * pow(base2, num2.length() - 1 - i);
        }
    }

    int quotientDecimal = decimal1 / decimal2;

    std::string quotient = "";

    while (quotientDecimal > 0) {
        int digit = quotientDecimal % base1;
        char c;
        if (digit >= 0 && digit <= 9) c = digit + '0';
        else
        c = digit - 10 + 'A';

        quotient = c + quotient;
        quotientDecimal /= base1;
    }
    return quotient;
}
