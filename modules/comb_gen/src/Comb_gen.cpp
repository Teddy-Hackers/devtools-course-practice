//  Copyright 2023 Shaposhnikova Ekaterina

#include "include/Comb_gen.h"

vector<int> CombGen::NextComb(vector<int> comb) {
  int i;
  vector<int> combErr;
  auto iter = combErr.cbegin();
  combErr.insert(iter, this->K, -1);
  for (i = this->K - 1; i > -1 && comb[i] >= this->N - 1;) {
    i--;
  }
  if (i == -1) {
    return combErr;
  }
  comb[i]++;
  for (int j = i + 1; j < this->K; j++) {
    comb[j] = comb[i];
  }

  return comb;
}

void CombGen::CombGenerate() {
  vector<int> comb(this->K);
  vector<int> combErr;
  auto iter = combErr.cbegin();
  combErr.insert(iter, this->K, -1);
  for (int i = 0; i < comb.size(); i++) {
    comb[i] = 0;
  }
  while (comb != combErr) {
    vector<int> combCopy;
    for (int i = 0; i < comb.size(); i++) {
      combCopy.push_back(VecIn[comb[i]]);
    }
    VecOut.push_back(combCopy);
    Count++;
    comb = NextComb(comb);
  }
}
