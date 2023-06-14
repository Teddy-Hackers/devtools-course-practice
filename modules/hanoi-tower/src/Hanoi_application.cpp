// Copyright 2023 Antonova Anastasya

#include "../include/Hanoi_application.h"

std::string HanoiApplication::operator()(int argc, const char** argv) {
  if (!IsValid(argc, argv)) {
    std::cerr << validatorMessage << std::endl;
    return;
  }
  int n = atoi(argv[1]);
  int from_rod = atoi(argv[2]);
  int to_rod = atoi(argv[3]);
  int aux_rod = atoi(argv[4]);
  int result;
  try {
    result = tower_solve(n, from_rod, to_rod, aux_rod);
    std::cout << "Number of moves: " << result << std::endl;
  }
  catch (std::string str) {
    std::cerr << "Error: " << str << std::endl;
  }
}

bool HanoiApplication::IsValid(int argc, const char** argv) {
  if (argc != 5) {
    validatorMessage = "Invalid number of arguments";
    return false;
  }
  for (int i = 1; i <= 4; i++) {
    int value = atoi(argv[i]);
    if (value < 1 || value > 3) {
        validatorMessage =
        "'from rod'/'to rod'/'aux rod' - must be in the range from 1 to 3";
        return false;
    }
  }
  return true;
}

int HanoiApplication::counter = 1;
