// Copyright 2023 Frantcuzov Maksim


#ifndef MODULES_AREAS_OF_FIGURES_INCLUDE_AREAS_APPLICATION_H_
#define MODULES_AREAS_OF_FIGURES_INCLUDE_AREAS_APPLICATION_H_

#include <string>

class CheckApplication {
public:
  std::string operator()(int argc, const char **argv);
  std::string printHelp(const std::string &programName);

private:
  bool argumentsIsValid(int argc, const char **argv);
  std::string Message;
};

#endif // MODULES_AREAS_OF_FIGURES_INCLUDE_AREAS_APPLICATION_H_
