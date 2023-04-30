// Copyright 2023 Shokurov Daniil

#include "../include/euler_function.h"
#include "../../../3rdparty/gtest/gtest.h"

TEST(Shokurov_Daniil_EulerFunctionTest, throw_if_not_positive_number) {
    //Assert
    EXPECT_ANY_THROW(euler_function(0));
}

TEST(Shokurov_Daniil_EulerFunctionTest, number_is_one_test) {
    //Arrange
    int expected, actual;
    //Act
    expected = 1;
    actual = euler_function(1);
    //Assert
    EXPECT_EQ(expected, actual);
}

TEST(Shokurov_Daniil_EulerFunctionTest, simple_numbers_test1) {
    //Arrange
    std::vector<int> simple_numbers{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 53, 83, 89, 113, 131, 173, 179, 191, 233, 239 };

    for (int i = 0; i < simple_numbers.size(); ++i) {
        //Act
        int simple_number = simple_numbers[i];
        int expected = simple_number - 1; //fi(p) = p - 1
        int actual = euler_function(simple_number);
        //Assert
        ASSERT_EQ(expected, actual);
    }
}

TEST(Shokurov_Daniil_EulerFunctionTest, simple_numbers_test2) {
    //Arrange
    std::vector<int> simple_numbers{ 1801, 1951, 2269, 2437, 2791, 3169, 3571, 4219, 4447, 5167, 5419, 6211 };

    for (int i = 0; i < simple_numbers.size(); ++i) {
        //Act
        int simple_number = simple_numbers[i];
        int expected = simple_number - 1; //fi(p) = p - 1
        int actual = euler_function(simple_number);
        //Assert
        ASSERT_EQ(expected, actual);
    }
}

TEST(Shokurov_Daniil_EulerFunctionTest, simple_numbers_test3) {
    //Arrange
    std::vector<int> simple_numbers{ 37633, 43201, 47629, 60493, 63949, 65713, 69313, 73009, 76801, 84673, 106033 };

    for (int i = 0; i < simple_numbers.size(); ++i) {
        //Act
        int simple_number = simple_numbers[i];
        int expected = simple_number - 1; //fi(p) = p - 1
        int actual = euler_function(simple_number);
        //Assert
        ASSERT_EQ(expected, actual);
    }
}

TEST(Shokurov_Daniil_EulerFunctionTest, degree_of_simple_number_test1) {
    //Arrange
    std::vector<int> simple_numbers{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    for (int i = 0; i < simple_numbers.size(); ++i) {
        //Act
        int degree_of_simple_number = pow(simple_numbers[i], 2); //a = p1^2
        int expected = pow(simple_numbers[i], 2) - simple_numbers[i]; //fi(a) = fi(p1^2) = (p1^2-p1)
        int actual = euler_function(degree_of_simple_number);
        //Assert
        ASSERT_EQ(expected, actual);
    }
}

TEST(Shokurov_Daniil_EulerFunctionTest, degree_of_simple_number_test2) {
    //Arrange
    std::vector<int> simple_numbers{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

    for (int i = 0; i < simple_numbers.size(); ++i) {
        //Act
        int degree_of_simple_number = pow(simple_numbers[i], 3);//a = p1^3
        int expected = pow(simple_numbers[i], 3) - pow(simple_numbers[i], 2); //fi(a) = fi(p1^3) = p^3 - p^2
        int actual = euler_function(degree_of_simple_number);
        //Assert
        ASSERT_EQ(expected, actual);
    }
}

TEST(Shokurov_Daniil_EulerFunctionTest, composite_numbers_test1) {
    //Arrange
    std::vector<int> simple_numbers1{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    std::vector<int> simple_numbers2{ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

    for (int i = 0; i < simple_numbers1.size(); ++i) {
        //Act
        int composite_number = simple_numbers1[i] * simple_numbers2[i]; //a = p1*p2
        int expected = (simple_numbers1[i] - 1) * (simple_numbers2[i] - 1); //fi(a) = fi(p1*p2) = (p1-1)*(p2-1)
        int actual = euler_function(composite_number);
        //Assert
        ASSERT_EQ(expected, actual);
    }
}

TEST(Shokurov_Daniil_EulerFunctionTest, composite_numbers_test2) {
    //Arrange
    std::vector<int> simple_numbers1{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    std::vector<int> simple_numbers2{ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 2 };

    for (int i = 0; i < simple_numbers1.size(); ++i) {
        //Act
        int composite_number = simple_numbers1[i] * pow(simple_numbers2[i], 2); //a = p1*p2^2
        int expected = (simple_numbers1[i] - 1) * (pow(simple_numbers2[i], 2) - simple_numbers2[i]); //fi(a) = fi(p1*p2^2) = (p1-1)*(p2^2-p2)
        int actual = euler_function(composite_number);
        //Assert
        ASSERT_EQ(expected, actual);
    }
}

TEST(Shokurov_Daniil_EulerFunctionTest, composite_numbers_test3) {
    //Arrange
    std::vector<int> simple_numbers1{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    std::vector<int> simple_numbers2{ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 2 };

    for (int i = 0; i < simple_numbers1.size(); ++i) {
        //Act
        int composite_number = pow(simple_numbers1[i], 3) * pow(simple_numbers2[i], 2); //a = p1^3*p2^2
        int expected = (pow(simple_numbers1[i], 3) - pow(simple_numbers1[i], 2)) * (pow(simple_numbers2[i], 2) - simple_numbers2[i]); //fi(a) = fi(p1^3*p2^2) = (p1^3-p1^2)*(p2^2-p2)
        int actual = euler_function(composite_number);
        //Assert
        ASSERT_EQ(expected, actual);
    }
}

TEST(Shokurov_Daniil_EulerFunctionTest, composite_numbers_test4) {
    //Arrange
    std::vector<int> simple_numbers1{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    std::vector<int> simple_numbers2{ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 2 };
    std::vector<int> simple_numbers3{ 5, 7, 11, 13, 17, 19, 23, 29, 31, 2, 3 };

    for (int i = 0; i < simple_numbers1.size(); ++i) {
        //Act
        int composite_number = simple_numbers1[i] * simple_numbers2[i] * simple_numbers3[i]; //a = p1*p2*p3
        int expected = (simple_numbers1[i] - 1) * (simple_numbers2[i] - 1) * (simple_numbers3[i] - 1); //fi(a) = fi(p1*p2*p3) = (p1-1)*(p2-1)*(p3-1)
        int actual = euler_function(composite_number);
        //Assert
        ASSERT_EQ(expected, actual);
    }
}