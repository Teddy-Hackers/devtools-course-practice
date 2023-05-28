// Copyright 2023 Frantcuzov Maksim

#include "include/check_segments_intersection_app.h"

int main(int argc, const char **argv) {
  CheckApplication app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
