//  Copyright 2023 Shaposhnikova Ekaterina

#ifndef MODULES_COMB_GEN_COMB_GEN_H_
#define MODULES_COMB_GEN_COMB_GEN_H_

#include <iostream>
#include <vector>
using namespace std;


class CombGen {
private:
  vector<int> VecIn;
  
  int N;
  int K;
  int Count;

public:
  vector <vector<int>> VecOut;
  vector<int> getVecIn() {
    return VecIn;
  }
  void setVecIn(vector<int> vec) {
    VecIn = vec;
  }

  vector<vector<int>> getVecOut() {
    return VecOut;
  }
  void setVecOut(vector<vector<int>> vec) {
    VecOut = vec;
  }

  int getCount() {
    return Count;
  }
  void setCount(int count) {
    Count = count;
  }

  int getN() {
    return N;
  }
  void setN(int n) {
    N = n;
  }

  int getK() {
    return K;
  }

  void setK(int k) {
    K = k;
  }

  int factorial(int i)
  {
    if (i == 0) return 1;
    else return i * factorial(i - 1);
  }

  CombGen(int n, int k) {
    K = k;
    N = n;
    Count = 0;
  }
  
  vector<int> NextComb(vector<int> combination);
  void CombGenerate();
};

#endif  //  MODULES_COMB_GEN_COMB_GEN_H_
