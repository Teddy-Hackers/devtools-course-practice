// Copyright 2023 Kolesov Maxim

#pragma once

#include <string>

class SearchApplication {
 public:
  SearchApplication();

  std::string operator()(int argc, const char **argv);
 private:
  void help(const char *appName, const char *message = "");

  int parseInt(const char *value);

  void validateArguments(int argc, const char **argv);

  std::string m_message;
};
