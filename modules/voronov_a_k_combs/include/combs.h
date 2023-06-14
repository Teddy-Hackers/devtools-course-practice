// Copyright 2023 Voronov Alexandr

#ifndef MODULES_VORONOV_A_K_COMBS_INCLUDE_COMBS_H_
#define MODULES_VORONOV_A_K_COMBS_INCLUDE_COMBS_H_
#include <vector>
#include <stdexcept>

class combs {
    int a;
    int b;
    std::vector<int> v;
 public:
    combs();
    combs(int a, int b);
    bool setter();
    int getter();
    ~combs();
};

#endif  // MODULES_VORONOV_A_K_COMBS_INCLUDE_COMBS_H_
