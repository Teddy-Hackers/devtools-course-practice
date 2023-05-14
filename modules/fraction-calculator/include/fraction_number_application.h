// Copyright 2023 Mukhin Vadim

#ifndef MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_NUMBER_APPLICATION_H_
#define MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_NUMBER_APPLICATION_H_

#include <string>
class Application {
 public:
  Application::Application() : message_("");
  private : void Application::help(const char* appname, const char* message);
  bool Application::validateNumberOfArguments(int argc, const char** argv);
  FractionNumber parseFraction(const std::string& str);
  std::string Application::operator()(int argc, const char** argv);
}
#endif  // MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_NUMBER_APPLICATION_H_
