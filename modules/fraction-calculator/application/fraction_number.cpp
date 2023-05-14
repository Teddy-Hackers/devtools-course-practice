// Copyright 2023 Mukhin Vadim

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/fraction_number_application.h"

#include "include/fraction_number.h"

int main(int argc, const char** argv) {
  Application app;
  std::string result = app(argc, argv);
  std::cout << result << std::endl;
  return 0;
}
