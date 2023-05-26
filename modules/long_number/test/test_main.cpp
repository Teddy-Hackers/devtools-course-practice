// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>
#include <iostream>
#include "include/longNumber.h"

int main(int argc, const char* argv[]) {
  longNumber longN;
  auto output = longN(argc, argv);
  std::cout << output << std::endl;
  return 0;
}