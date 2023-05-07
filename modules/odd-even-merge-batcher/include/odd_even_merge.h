// Copyright 2023 Nikolaev Alexander

#ifndef MODULES_ODD_EVEN_MERGE_BATCHER_INCLUDE_ODD_EVEN_MERGE_H_
#define MODULES_ODD_EVEN_MERGE_BATCHER_INCLUDE_ODD_EVEN_MERGE_H_

#include <vector>
#include <random>


//! @addtogroup odd-even-merge
//! @{

/**
* @brief OddEvenMergeBatcherSort
* @param[in] array is a vector of numbers
*/
void OddEvenMergeBatcherSort(std::vector<int>* array);

/**
* @brief getRandomArray
* @param[in] sizeArray is a size of array
*/
std::vector<int> getRandomArray(const int sizeArray);

//! @}

#endif  // MODULES_ODD_EVEN_MERGE_BATCHER_INCLUDE_ODD_EVEN_MERGE_H_
