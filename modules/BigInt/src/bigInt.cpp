// Copyright 2023 Antonova Anastasya

#include <string>

#include "include/bigInt.h"

BigInt::BigInt() : is_negative(false), digits("0") {}


BigInt::BigInt(const std::string& s) {
  // Определяем знак числа
  if (s[0] == '-') {
    is_negative = true;
    digits = s.substr(1);
  } else {
    is_negative = false;
    digits = s;
  }

  digits.erase(0, std::min(digits.find_first_not_of('0'), digits.size() - 1));
}

BigInt::BigInt(int n) {
  if (n >= 0) {
    is_negative = false;
    digits = std::to_string(n);
  } else {
    is_negative = true;
    digits = std::to_string(-n);
  }
}


BigInt::BigInt(const BigInt& other) {
  is_negative = other.is_negative;
  digits = other.digits;
}

BigInt& BigInt::operator=(const BigInt& other) {
  if (this != &other) {
    is_negative = other.is_negative;
    digits = other.digits;
  }
  return *this;
}

BigInt operator+(const BigInt& a, const BigInt& b) {
  std::string result;
  int carry = 0;
  int da, db, s;

  // Для удобства предполагаем, что a - это число с большей длиной
  if (a.digits.length() < b.digits.length()) {
    return b + a;
  }

  for (int i = 0; i < b.digits.length(); i++) {
    da = a.digits[a.digits.length() - i - 1] - '0';
    db = b.digits[b.digits.length() - i - 1] - '0';
    s = da + db + carry;

    carry = s / 10;
    s %= 10;

    result.insert(0, std::to_string(s));
  }

  for (int i = b.digits.length(); i < a.digits.length(); i++) {
    da = a.digits[a.digits.length() - i - 1] - '0';
    s = da + carry;

    carry = s / 10;
    s %= 10;

    result.insert(0, std::to_string(s));
  }

  if (carry != 0) {
    result.insert(0, std::to_string(carry));
  }

  return BigInt(result);
}

BigInt operator-(const BigInt& a, const BigInt& b) {
  std::string result;
  bool subtract_one = false;

  // Для удобства предполагаем, что a - это число с большей длиной
  if (a < b) {
    return BigInt("-") + (b - a);
  }

  int carry = 0;
  int da, db, d;

  int i = 0;
  for (; i < b.digits.length(); i++) {
    da = a.digits[a.digits.length() - i - 1] - '0';
    db = b.digits[b.digits.length() - i - 1] - '0';
    d = da - db - carry;

    if (d < 0) {
        d += 10;
        carry = 1;
    } else {
        carry = 0;
    }

    result.insert(0, std::to_string(d));
  }

  for (; i < a.digits.length(); i++) {
    da = a.digits[a.digits.length() - i - 1] - '0';
    d = da - carry;

    if (d < 0) {
        d += 10;
        carry = 1;
    } else {
        carry = 0;
    }

    result.insert(0, std::to_string(d));
  }

    // Удаляем лидирующие нули
  while (result.length() > 1 && result.front() == '0') {
    result.erase(0, 1);
  }

  return BigInt(result);
}

BigInt operator*(const BigInt& a, const BigInt& b) {
  std::string result = BigInt::multiply(a.digits, b.digits);
  return BigInt((a.is_negative != b.is_negative) ? "-" + result : result);
}

BigInt operator/(const BigInt& a, const BigInt& b) {
  std::pair<std::string, std::string> result = BigInt::divide(a.digits, b.digits);
  return BigInt((a.is_negative != b.is_negative) ? "-" + result.first : result.first);
}

BigInt operator%(const BigInt& a, const BigInt& b) {
  std::pair<std::string, std::string> result = BigInt::divide(a.digits, b.digits);
  return BigInt(result.second);
}

bool operator>(const BigInt& a, const BigInt& b) {
  if (a.is_negative && !b.is_negative) return false;
  if (!a.is_negative && b.is_negative) return true;
  bool abs_compare = BigInt::compare_abs(a.digits, b.digits);
  return (a.is_negative) ? !abs_compare : abs_compare;
}

bool operator>=(const BigInt& a, const BigInt& b) {
  if (a.is_negative && !b.is_negative) return false;
  if (!a.is_negative && b.is_negative) return true;
  bool abs_compare = BigInt::compare_abs(a.digits, b.digits);
  return (a.is_negative) ? !abs_compare || a.digits == b.digits : abs_compare || a.digits == b.digits;
}

bool operator<(const BigInt& a, const BigInt& b) {
  if (a.is_negative && !b.is_negative) return true;
  if (!a.is_negative && b.is_negative) return false;
  bool abs_compare = BigInt::compare_abs(a.digits, b.digits);
  return (a.is_negative) ? abs_compare : !abs_compare;
}

bool operator<=(const BigInt& a, const BigInt& b) {
  if (a.is_negative && !b.is_negative) return true;
  if (!a.is_negative && b.is_negative) return false;
  bool abs_compare = BigInt::compare_abs(a.digits, b.digits);
  return (a.is_negative) ? abs_compare || a.digits == b.digits : !abs_compare || a.digits == b.digits;
}

bool operator==(const BigInt& a, const BigInt& b) {
  return (a.is_negative == b.is_negative && a.digits == b.digits);
}

bool operator!=(const BigInt& a, const BigInt& b) {
  return !(a == b);
}

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& out, const BigInt& n) {
  if (n.is_negative && n.digits != "0") {
    out << "-";
  }
  out << n.digits;
  return out;
}

bool BigInt::compare_abs(const std::string& a, const std::string& b) {
  // Сравниваем длины
  if (a.length() != b.length()) {
    return a.length() < b.length();
  }

  // Сравниваем цифры поразрядно
  for (size_t i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) {
        return a[i] < b[i];
    }
  }

  return false;
}

std::string BigInt::add_abs(const std::string& a, const std::string& b) {
  // Складываем числа (по цифрам)
  std::string result;
  int carry = 0;
  int na = a.length(), nb = b.length();
  for (int i = 0; i < std::max(na, nb); i++) {
    int da = (i < na) ? (a[na - i - 1] - '0') : 0;
    int db = (i < nb) ? (b[nb - i - 1] - '0') : 0;
    int s = da + db + carry;
    carry = s / 10;
    result.insert(0, std::to_string(s % 10));
  }
  if (carry > 0) {
    result.insert(0, std::to_string(carry));
  }

  return result;
}

std::string BigInt::subtract_abs(const std::string& a, const std::string& b) {
  // Вычитаем числа (по цифрам)
  std::string result;
  int borrow = 0;
  int na = a.length(), nb = b.length();
  for (int i = 0; i < na; i++) {
    int da = a[na - i - 1] - '0';
    int db = (i < nb) ? (b[nb - i - 1] - '0') : 0;
    int d = da - db - borrow;
    borrow = (d < 0) ? 1 : 0;
    if (d < 0) {
        d += 10;
    }
      result.insert(0, std::to_string(d));
  }

  // Удаляем незначащие нули
  result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

  return result;
}

std::string BigInt::multiply_int(const std::string& a, int b) {
  // Умножаем число на цифру (по цифрам)
  std::string result;
  int carry = 0;
  int na = a.length();
  for (int i = 0; i < na; i++) {
    int d = (a[na - i - 1] - '0') * b + carry;
    carry = d / 10;
    result.insert(0, std::to_string(d % 10));
  }
  if (carry > 0) {
    result.insert(0, std::to_string(carry));
  }

  return result;
}

std::pair<std::string, int> BigInt::divide_int(const std::string& a, int b) {
  // Делим число на цифру (по цифрам)
  std::string result;
  int remainder = 0;
  int na = a.length();
  for (int i = na - 1; i >= 0; i--) {
    int d = (a[i] - '0') + remainder * 10;
    int q = d / b;
    remainder = d % b;
    result.insert(0, std::to_string(q));
  }

  // Удаляем незначащие нули
  result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

  return std::make_pair(result, remainder);
}

std::string BigInt::multiply(const std::string& a, const std::string& b) {
  std::string result(a.length() + b.length(), '0');

  for (int i = a.length() - 1; i >= 0; i--) {
    int carry = 0;
    for (int j = b.length() - 1; j >= 0; j--) {
        int tmp = (result[i + j + 1] - '0') + (a[i] - '0') * (b[j] - '0') + carry;
        result[i + j + 1] = tmp % 10 + '0';
        carry = tmp / 10;
    }
    result[i] += carry;
  }

    // Удаляем незначащие нули
  result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));

  return result.back() == '0' ? "0" : result;
}

std::pair<std::string, std::string> BigInt::divide(const std::string& a,
  const std::string& b) {
  if (compare_abs(a, b)) {
    return std::make_pair("0", a);
  }

  std::string quotient;
  std::string remainder = a.substr(0, b.length() - 1);

  int i = b.length() - 1;
  while (i < a.length()) {
    remainder += a[i];
    i++;
    if (remainder == "0") {
        quotient.append("0");
        continue;
    }
    int count = 0;
    while (compare_abs(remainder, b)) {
        remainder = subtract_abs(remainder, b);
        count++;
    }
    quotient.append(std::to_string(count));
  }

  // Удаляем незначащие нули
  quotient.erase(0, std::min(quotient.find_first_not_of('0'), quotient.size() - 1));
  remainder.erase(0, std::min(remainder.find_first_not_of('0'), remainder.size() - 1));

  return std::make_pair(quotient, remainder);
}
