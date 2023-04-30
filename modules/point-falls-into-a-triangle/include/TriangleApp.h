// Copyright 2023 Kandrin Alexey

#pragma once

#include "include/triangle.h"
#include <memory>

#include <string>

class TriangleApp {
 public:
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
};