// Copyright 2023 Selivankin Sergey

#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

//! @addtogroup binary-search
//! @{

/**
 * @brief A class which represents a binary search
 *
 * Binary search is a search algorithm that finds the position of
 * a target value within a sorted array.
 * Binary search runs in logarithmic time.
 */
class BinarySearch {
 public:
    BinarySearch() = default;

    /**
     * @brief Constructor
     * @param[in] numbers is a vector of numbers
     */
    explicit BinarySearch(const std::vector<int>& numbers);

    /**
    * @brief setter
    * @param[in] numbers is a vector of numbers
    */
    void setNumbers(const std::vector<int>& _numbers);

    /**
    * @brief find
    * @param[in] target is a number for search in numbers
    */
    int find(const int& target);

 private:
    std::vector<int> numbers;
    /**
    * @brief check if vector numbers is sorted
    */
    static bool checkSort(const std::vector<int> &_numbers);
};

//! @}
