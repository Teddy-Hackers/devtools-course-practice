// Copyright 2023 Kolesov Maxim

#pragma once

#include <string>

class SearchApplication {
 public:
  SearchApplication() = default;

  SearchApplication(const SearchApplication &sa) = delete;
  SearchApplication(SearchApplication &&sa) = delete;

  std::string operator()(int argc, const char **argv);
 private:
  void help(const char *appName);

  bool validateArguments(int argc, const char **argv);

  std::string m_message;
};
