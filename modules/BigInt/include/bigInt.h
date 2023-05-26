// Copyright 2023 Antonova Anastasya

#ifndef MODULES_BIGINT_INCLUDE_BIGINT_H_
#define MODULES_BIGINT_INCLUDE_BIGINT_H_

#include <string>
#include <cstdint>
#include "include/bigInt.h"

#include <string>

class BigInt {
public:
  BigInt();
  BigInt(const std::string& s);
  BigInt(int n);
  BigInt(const BigInt& other);

  BigInt& operator=(const BigInt& other);

  friend BigInt operator+(const BigInt& a, const BigInt& b);
  friend BigInt operator-(const BigInt& a, const BigInt& b);
  friend BigInt operator*(const BigInt& a, const BigInt& b);
  friend BigInt operator/(const BigInt& a, const BigInt& b);
  friend BigInt operator%(const BigInt& a, const BigInt& b);

  friend bool operator>(const BigInt& a, const BigInt& b);
  friend bool operator>=(const BigInt& a, const BigInt& b);
  friend bool operator<(const BigInt& a, const BigInt& b);
  friend bool operator<=(const BigInt& a, const BigInt& b);
  friend bool operator==(const BigInt& a, const BigInt& b);
  friend bool operator!=(const BigInt& a, const BigInt& b);

  friend std::ostream& operator<<(std::ostream& out, const BigInt& n);

private:
  bool is_negative;
  std::string digits;

  static bool compare_abs(const std::string& a, const std::string& b);
  static std::string add_abs(const std::string& a, const std::string& b);
  static std::string subtract_abs(const std::string& a, const std::string& b);
  static std::string multiply_int(const std::string& a, int b);
  static std::pair<std::string, int> divide_int(const std::string& a, int b);
  static std::string multiply(const std::string& a, const std::string& b);
  static std::pair<std::string, std::string> divide(const std::string& a, const std::string& b);
};

#endif  // MODULES_BIGINT_INCLUDE_BIGINT_H_