// Copyright 2023 Antonova Anastasya

#include <string>

#include "include/long_number.h"

std::string longNumber::runningLongNumber()(int argc, const char** argv) {
  if ((argc != 3) || (!argChecking(argc, argv))) {
    return "Invalid input! ";
  }
      
  return compareOrCount();
}


std::string longNumber::compareOrCount() {
    
  if (chosenSign == 0) {
    BigInt countResponse = first - second;
    return countResponse.BigIntToString();
  }

  else if (chosenSign == 1) {
    BigInt countResponse = first + second;
    return countResponse.BigIntToString();
   }
  else if (chosenSign == 2) {
    BigInt countResponse = first / second;
    return countResponse.BigIntToString();
  }
  else if (chosenSign == 3) {
    BigInt countResponse = first * second;
    return countResponse.BigIntToString();
  }
  else if (chosenSign == 4) {
    BigInt countResponse = first % second;
    return countResponse.BigIntToString();
  }    
  else if (chosenSign == 5) {
  bool compareResponse = first < second;
  if (compareResponse)
  return "It's true!";
  else
  return "It's false!";
  }
  else if (chosenSign == 6) {
  bool compareResponse = first > second;
  if (compareResponse)
  return "It's true!";
  else
  return "It's false!";
  }
  else if (chosenSign == 7) {
  bool compareResponse = first <= second;
  if (compareResponse)
  return "It's true!";
  else
  return "It's false!";
  }
  else if (chosenSign == 8) {
  bool compareResponse = first >= second;
  if (compareResponse)
  return "It's true!";
  else
  return "It's false!";
  }
  else if (chosenSign == 9) {
  bool compareResponse = first != second;
  if (compareResponse)
  return "It's true!";
  else
  return "It's false!";
  }
  else if (chosenSign == 10) {
  bool compareResponse = first == second;
  if (compareResponse)
  return "It's true!";
  else
  return "It's false!";
  }
}

bool longNumber::argChecking(int argc, const char** argv) {

first = BigInt(argv[1]);
second = BigInt(argv[3]);

for (int i = 0; i < sizeof sign / sizeof sign[0]; ++i) {
  if (sign[i] == argv[2]) {
    chosenSign = i;
    return true;
   }
  }
}