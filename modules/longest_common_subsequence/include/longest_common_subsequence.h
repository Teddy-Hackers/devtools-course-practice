// Copyright 2023 Yurin Evgeny

#ifndef MODULES_LONGEST_SUBSEQUENCE_INCLUDE_LONGEST_COMMON_SUBSEQUENCE_H_
#define MODULES_LONGEST_SUBSEQUENCE_INCLUDE_LONGEST_COMMON_SUBSEQUENCE_H_

#include <algorithm>
#include <vector>

std::vector<int> get_longest_common_subsequence(int firstLength, std::vector<int> firstSequence, int secondLength,
                                                std::vector<int> secondSequence);

#endif  // MODULES_LONGEST_SUBSEQUENCE_INCLUDE_LONGEST_COMMON_SUBSEQUENCE_H_
