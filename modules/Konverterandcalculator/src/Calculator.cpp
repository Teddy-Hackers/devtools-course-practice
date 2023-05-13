// Copyright 2023 Mukhin Vadim
#include <iostream>
#include <String>
#include <cmath>

std::String add(std::String num1, int base1, std::String num2, int base2) {
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

    int sumDecimal = decimal1 + decimal2;

    std::String sum = "";

    while (sumDecimal > 0) {
        int digit = sumDecimal % base1;
        char c;
        if (digit >= 0 && digit <= 9) c = digit + '0';
        else
        c = digit - 10 + 'A';

        sum = c + sum;
        sumDecimal /= base1;
    }

    return sum;
}

std::String subtract(std::String num1, int base1, std::String num2, int base2) {
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

    std::String diff = "";

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

std::String multiply(std::String num1, int base1, std::String num2, int base2) {
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

    std::String product = "";

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

std::String divide(std::String num1, int base1, std::String num2, int base2) {
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

    std::String quotient = "";

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
