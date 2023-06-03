// Copyright 2023 Bochkarev Vladimir

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "../include/HuffmanAlgorithm_application.h"

//#include "include/complex_calculator.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
