// Copyright 2023 Shokurov Daniil

#ifndef MODULES_LONGEST_INCREASING_SUBSEQUENCE_INCLUDE_LONGEST_INC_SUBSEQ_APPLICATION_H_
#define MODULES_LONGEST_INCREASING_SUBSEQUENCE_INCLUDE_LONGEST_INC_SUBSEQ_APPLICATION_H_

#include <string>

/** @defgroup complex-number Complex Numbers Algebra
  @{
    This module contains:
        - A definition of complex number as a class
        - Calculator class which performs the calculations
  @}
*/

//! @addtogroup complex-number
//! @{

/**
 * @brief Class for complex numbers algebra
 */
class Application {
 public:
  Application();

  /**
   * @brief Functor override
   * @param[in] argc Nuber of comand line arguments
   * @param[in] argv Command line arguments
   * @return Output expression
   */
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;
};

//! @}

#endif  // MODULES_LONGEST_INCREASING_SUBSEQUENCE_INCLUDE_LONGEST_INC_SUBSEQ_APPLICATION_H_
