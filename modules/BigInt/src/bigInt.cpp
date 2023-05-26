// Copyright 2023 Antonova Anastasya

#include <string>

#include "include/bigInt.h"

BigInt BigInt::operator+(const BigInt& other) {
  if (is_negative != other.is_negative) {
      if (is_negative) {
          return other - (-*this);
      }
      else {
          return *this - (-other);
      }
  }

  std::string result = add_abs(digits, other.digits);
  return BigInt(is_negative, result);
}

BigInt BigInt::operator-(const BigInt& other) {
  if (is_negative != other.is_negative) {
      return *this + (-other);
  }
  else if (*this == other) {
      return BigInt();
  }
  else if (compare_abs(digits, other.digits)) {
      std::string result = subtract_abs(other.digits, digits);
      return BigInt(!is_negative, result);
  }
  else {
      std::string result = subtract_abs(digits, other.digits);
      return BigInt(is_negative, result);
  }
}

BigInt BigInt::operator*(const BigInt& other) {
  std::string result = multiply(digits, other.digits);
  return BigInt(is_negative != other.is_negative, result);
}

BigInt BigInt::operator/(const BigInt& other) {
  if (other == BigInt()) {
      throw std::invalid_argument("Division by zero");
  }

  if (*this == BigInt()) {
      return BigInt();
  }

  if (compare_abs(digits, other.digits)) {
      return BigInt();
  }

  std::pair<std::string, std::string> result = divide(digits, other.digits);
  return BigInt(is_negative != other.is_negative, result.first);
}

BigInt BigInt::operator%(const BigInt& other) {
  if (other == BigInt()) {
      throw std::invalid_argument("Division by zero");
  }

  if (*this == BigInt()) {
      return BigInt();
  }

  if (compare_abs(digits, other.digits)) {
      return *this;
  }

  std::pair<std::string, std::string> result = divide(digits, other.digits);
  return BigInt(false, result.second);
}

bool BigInt::operator>(const BigInt& other) {
  if (is_negative != other.is_negative) {
      return is_negative < other.is_negative;
  }
  else if (is_negative) {
      return compare_abs(other.digits, digits);
  }
  else {
      return compare_abs(digits, other.digits);
  }
}

bool BigInt::operator>=(const BigInt& other) {
  return *this == other || *this > other;
}

bool BigInt::operator<(const BigInt& other) {
  return !(*this >= other);
}

bool BigInt::operator<=(const BigInt& other) {
  return *this == other || *this < other;
}

bool BigInt::operator==(const BigInt& other) {
  return is_negative == other.is_negative && digits == other.digits;
}

bool BigInt::operator!=(const BigInt& other) {
  return !(*this == other);
}


