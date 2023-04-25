// Copyright 2023 Selivankin Sergey

#include <gtest/gtest.h>
#include "include/binary_search.h"

TEST(BinarySearch, can_search_in_sorted_array) {
    // Arrange
    std::vector<int> a = {1, 2, 3, 4, 5, 6};
    BinarySearch binarySearch(a);
    int expected = 1;

    // Act
    int result = binarySearch.find(a[expected]);

    // Assert
    EXPECT_EQ(expected, result);
}

TEST(BinarySearch, can_search_in_unsorted_array) {
    // Arrange
    std::vector<int> a = {1, 32, 3, 434, 544, 6};
    BinarySearch binarySearch(a);
    int expected = 2;

    // Act
    int result = binarySearch.find(a[expected]);

    // Assert
    EXPECT_EQ(expected, result);
}

TEST(BinarySearch, search_in_null_array_return_negative_number) {
    // Arrange
    BinarySearch binarySearch;
    int expected = -1;

    // Act
    int result = binarySearch.find(111);

    // Assert
    EXPECT_EQ(expected, result);
}

TEST(BinarySearch, search_for_non_existent_return_negative_number) {
    // Arrange
    std::vector<int> a = {1, 32, 3, 434, 544, 6};
    BinarySearch binarySearch;
    int expected = -1;

    // Act
    int result = binarySearch.find(111);

    // Assert
    EXPECT_EQ(expected, result);
}

TEST(BinarySearch, test_findIn) {
    // Arrange
    std::vector<int> a = {1, 32, 3, 434, 544, 6};
    BinarySearch binarySearch;
    int expected = 4;

    // Act
    int result = binarySearch.findIn(a[expected], a);

    // Assert
    EXPECT_EQ(expected, result);
}
