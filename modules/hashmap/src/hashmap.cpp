//  Copyright 2023 Shipilov Artem

#include "include/hashmap.h"

hashmap::hashmap(int size_, int step_) {
    if (size_ <= 0) throw "error";

    pRecs = new TabRecord * [size_];
    TabSize = size_;
    HashStep = step_;
    DataCount = 0;

    for (int i = 0; i < size_; i++) {
        pRecs[i] = nullptr;
    }

    CurrPos = DataCount;
    pMark = new TabRecord(std::string("deleted"));
}

hashmap::hashmap(const hashmap& Table_) {
    TabSize = Table_.TabSize;
    HashStep = Table_.HashStep;
    DataCount = Table_.DataCount;
    CurrPos = Table_.CurrPos;

    pRecs = new TabRecord * [Table_.TabSize];
    pMark = new TabRecord(std::string("deleted"));

    for (int i = 0; i < TabSize; i++) {
        if (Table_.pRecs[i] == nullptr || Table_.pRecs[i] == Table_.pMark) {
            pRecs[i] = nullptr;
        } else {
            pRecs[i] = new TabRecord(*(Table_.pRecs[i]));
        }
    }
}

int hashmap::HashFunc(const std::string key_) {
    int hashval = 0;
    int Len = key_.size();
    for (int i = 0; i < Len; i++) {
        hashval = (hashval << 3) + static_cast(key_[i]);
    }
    return hashval;
}

double* hashmap::FindRecord(const std::string key_) {
    Reset();
    FreePos = -1;
    double* pValue = nullptr;
    CurrPos = abs(HashFunc(key_) % TabSize);
    for (int i = 0; i < TabSize; i++) {
        if (pRecs[CurrPos] == nullptr) {
            break;
        } else {
            if (pRecs[CurrPos] == pMark) {
                if (FreePos == -1) FreePos = CurrPos;
            } else {
                if (pRecs[CurrPos]->GetKey() == key_) {
                    pValue = pRecs[CurrPos]->GetData();
                    break;
                }
                CurrPos = abs(GetNextPos(CurrPos));
            }
        }
    }
    return pValue;
}

void hashmap::InsRecord(const std::string key_, const double data_) {
    if (IsFull()) {
        throw "error";
    }

    if ((FindRecord(key_) == nullptr)) {
        if (FreePos != -1) CurrPos = FreePos;
        pRecs[CurrPos] = new TabRecord(key_, data_);
        DataCount++;
    } else {
        throw "error";
    }
}

void hashmap::DelRecord(const std::string key_) {
    if (IsEmpty()) throw "error";

    Reset();
    double* tmp = FindRecord(key_);
    if (tmp == nullptr) {
        throw "error";
    } else {
        delete pRecs[CurrPos];
        pRecs[CurrPos] = pMark;
        DataCount--;
    }
}

void hashmap::Reset() {
    CurrPos = 0;
    if (!IsTabEnded()) {
        while (CurrPos < TabSize) {
            if ((pRecs[CurrPos] != nullptr) && (pRecs[CurrPos] != pMark)) break;
            CurrPos++;
        }
    }
}

void hashmap::GoNext() {
    if (IsTabEnded()) throw "Error";
    while (++CurrPos < TabSize)
        if ((pRecs[CurrPos] != nullptr) && (pRecs[CurrPos] != pMark)) break;
}

std::string hashmap::GetKey(int mode) const {
    int pos = -1;
    if (IsEmpty()) {
        throw "Error";
    }
    switch (mode) {
    case 0:
        pos = 0;
        break;
    case 2:
        pos = DataCount - 1;
        break;
    default:
        pos = CurrPos;
        break;
    }
    return pRecs[pos]->GetKey();
}

double* hashmap::GetData(int mode) const {
    int pos = -1;
    if (IsEmpty()) {
        throw "Error";
    }
    switch (mode) {
    case 0:
        pos = 0;
        break;
    case 2:
        pos = DataCount - 1;
        break;
    default:
        pos = CurrPos;
        break;
    }
    return pRecs[pos]->GetData();
}
