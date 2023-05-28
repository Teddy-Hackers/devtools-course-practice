//  Copyright 2023 Kruglikova Valeriia


#include <gtest/gtest.h>
#include <string>
#include "include/matrix.h"

TEST(matrix, constructor) {
    matrix A;
    EXPECT_EQ(A.getMatrix(), nullptr);
}
TEST(matrix, constructor_rows_columns) {
    matrix A(2, 2);
    EXPECT_EQ(A.getColumns(), 2);
    EXPECT_EQ(A.getRows(), 2);
}
TEST(matrix, constructor_rows_columns_matrix) {
    double **a = new double*[2];
    for (int i = 0; i < 2; i++) {
        a[i] = new double[2];
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 2;
    a[1][1] = 5;
    matrix A(a, 2, 2);
    EXPECT_EQ(A.getMatrix(), a);
}
TEST(matrix, copy_matrix) {
    double** a = new double* [2];
    for (int i = 0; i < 2; i++) {
        a[i] = new double[2];
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 2;
    a[1][1] = 5;
    matrix A(a, 2, 2);
    matrix B(A);
    EXPECT_EQ(A, B);
}
TEST(matrix, arithmetic) {
    double** a, ** b;
    a = new double* [2];
    b = new double* [2];
    for (int i = 0; i < 2; i++) {
        a[i] = new double[2];
        b[i] = new double[2];
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 2;
    a[1][1] = 5;
    b[0][0] = 3;
    b[0][1] = 5;
    b[1][0] = 5;
    b[1][1] = 7;
    matrix A(a, 2, 2);
    matrix B(b, 2, 2);
    matrix C = A + B;
    matrix D = A - B;
    matrix E = A * B;
    matrix F = A * 3;
    matrix res(2, 2);
    res.getMatrix()[0][0] = 4;
    res.getMatrix()[0][1] = 7;
    res.getMatrix()[1][0] = 7;
    res.getMatrix()[1][1] = 12;
    EXPECT_EQ(C, res);
    res.getMatrix()[0][0] = -2;
    res.getMatrix()[0][1] = -3;
    res.getMatrix()[1][0] = -3;
    res.getMatrix()[1][1] = -2;
    EXPECT_EQ(D, res);
    res.getMatrix()[0][0] = 13;
    res.getMatrix()[0][1] = 19;
    res.getMatrix()[1][0] = 31;
    res.getMatrix()[1][1] = 45;
    EXPECT_EQ(E, res);
    res.getMatrix()[0][0] = 3;
    res.getMatrix()[0][1] = 6;
    res.getMatrix()[1][0] = 6;
    res.getMatrix()[1][1] = 15;
    EXPECT_EQ(F, res);
}
TEST(matrix, trans) {
    double** a = new double* [2];
    for (int i = 0; i < 2; i++) {
        a[i] = new double[2];
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 2;
    a[1][1] = 5;
    matrix A(a, 2, 2);
    matrix B(A);
    B.getMatrix()[0][0] = 1;
    B.getMatrix()[0][1] = 2;
    B.getMatrix()[1][0] = 2;
    B.getMatrix()[1][1] = 5;
    EXPECT_EQ(A, B);
}
TEST(matrix, reverse_matrix) {
    double** a = new double* [2];
    for (int i = 0; i < 2; i++) {
        a[i] = new double[2];
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 2;
    a[1][1] = 5;
    matrix A(a, 2, 2);
    matrix B(A);
    B.getMatrix()[0][0] = 1;
    B.getMatrix()[0][1] = -0.4;
    B.getMatrix()[1][0] = -0.4;
    B.getMatrix()[1][1] = 0.36;
    EXPECT_EQ(A, B);
}
TEST(matrix, bool_operations) {
    double** a = new double* [2];
    for (int i = 0; i < 2; i++) {
        a[i] = new double[2];
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 2;
    a[1][1] = 5;
    matrix A(a, 2, 2);
    matrix B = A;
    EXPECT_EQ(true, A == B);
    EXPECT_EQ(false, A != B);
}
TEST(matrix, determinant) {
    double** a = new double* [2];
    for (int i = 0; i < 2; i++) {
        a[i] = new double[2];
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 2;
    a[1][1] = 5;
    matrix A(a, 2, 2);
    EXPECT_EQ(1, A.determinant());
}