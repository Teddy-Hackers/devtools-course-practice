  //Francuzov Maksim
#include <iostream>
#include <map>
#include <string>

#include "include/Converter.h"

string toRoman(int number) {
  const int arabicValues[] = {1000, 900, 500, 400, 100, 90, 50,
                              40,   10,  9,   5,   4,   1};
  const string romanValues[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                "XL", "X",  "IX", "V",  "IV", "I"};
  string result = "";
  for (int i = 0; i < 13; i++) {
    while (number >= arabicValues[i]) {
      result += romanValues[i];
      number -= arabicValues[i];
    }
  }
  return result;
}

int toArabic(string roman) {
  map<char, int> romanValues = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
                                {'X', 10},   {'V', 5},   {'I', 1}};
  int result = 0;
  for (auto i = 0u; i < roman.length(); i++) {
    if (i > 0 && romanValues[roman[i]] > romanValues[roman[i - 1]]) {
      result += romanValues[roman[i]] - 2 * romanValues[roman[i - 1]];
    } else {
      result += romanValues[roman[i]];
    }
  }
  return result;
}

string checkInputType(string input) {
  for (char &c : input) {
    if (!isdigit(c) && c != 'I' && c != 'V' && c != 'X' && c != 'L' &&
        c != 'C' && c != 'D' && c != 'M') {
      return "Invalid input";
    }
  }
  if (isdigit(input[0])) {
    return "Arabic";
  } else {
    return "Roman";
  }
}
