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

TEST(BinarySearch, cant_search_in_unsorted_array) {
    // Arrange
    std::vector<int> a = {1, 32, 3, 434, 544, 6};

    // Act & Assert
    ASSERT_ANY_THROW(new BinarySearch(a));
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
    std::vector<int> a = {1, 6, 66, 434, 544, 656566};
    BinarySearch binarySearch(a);
    int expected = -1;

    // Act
    int result = binarySearch.find(111);

    // Assert
    EXPECT_EQ(expected, result);
}

