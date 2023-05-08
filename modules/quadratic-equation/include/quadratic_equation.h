// Copyright 2023 Popov Andrey

//! @addtogroup quadratic-equation
//! @{

/**
 * @brief A class which represents a solving the quadratic equation
 *
 * The algorithm for solving the quadratic equation ax 2 + bx
 * + c = 0: calculate its discriminant value by the formula D =
 * b 2 −4ac; if the discriminant is negative, fix that there are no real roots
 */
class Quadratic_equation {
 private:
  /**
   * @brief Parameters of the quadratic equation
   */
  int x1, x2, a, b, c;
  /**
   * @brief Discriminant of the quadratic equation
   */
  float D = 0;

 public:
  Quadratic_equation();
  /**
   * @brief Solution calculation of the solution depending on the value of the
   * discriminant
   *
   * @param multipliers of equation
   */
  float solution(int a, int b, int c);
};

//! @}
