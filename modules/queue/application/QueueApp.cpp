// Copyright 2023 Sudomoykin Andrey

#include <iostream>
#include "include/QueueApplication.h"

int main(int argc, char** argv) {
  QueueApplication app;
  std::string output = app.executeCommand(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
