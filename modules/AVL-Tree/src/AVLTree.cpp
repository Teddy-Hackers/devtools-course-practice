// Copyright 2023 Ermolaev Danila

#pragma once
#include "include/AVLTree.h"
#include <iostream>

template <typename TData, typename TKey>
inline void AVLTree<TData, TKey>::printTree(BalanceNode<TData, TKey>* node,
                                            Trunk* prev, bool isLeft) {
  if (node != nullptr) {
    std::string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);
    printTree((BalanceNode<TData, TKey>*)(node->Right), trunk, true);
    if (!prev) {
      trunk->str = "---";
    } else if (isLeft) {
      trunk->str = ".---";
      prev_str = "   |";
    } else {
      trunk->str = "`---";
      prev->str = prev_str;
    }
    ShowTrunks(trunk);
    std::cout << node->GetKey() << "[" << *(node->GetData()) << "]"
              << std::endl;
    if (prev) {
      prev->str = prev_str;
    }
    trunk->str = "   |";
    printTree((BalanceNode<TData, TKey>*)(node->Left), trunk, false);
  }
}

template <typename TData, typename TKey>
void AVLTree<TData, TKey>::Insert(TKey k, TData d) {
  try {
    if (this->Find(k) != nullptr) {
      throw "Re - inserting an element, cannot complete Insert AVLTree";
    }
    Insert((BalanceNode<TData, TKey>*)this->Root, k, d);
  } catch (const char* exception) {
    std::cerr << "Error: " << exception << '\n';
  }
}
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::Insert(BalanceNode<TData, TKey>* N1, TKey k,
                                 TData d) {
  if (N1 == nullptr) {
    N1 = new BalanceNode<TData, TKey>(k, d);
    return 1;
  }
  if (k < N1->GetKey()) {
    if (N1->Left == nullptr) {
      N1->Left = new BalanceNode<TData, TKey>(k, d, N1);
      return LBalance(N1);
    }
    if (Insert((BalanceNode<TData, TKey>*)(N1->Left), k, d) == 1) {
      return LBalance(N1);
    }
  }
  if (k > N1->GetKey()) {
    if (N1->Right == nullptr) {
      N1->Right = new BalanceNode<TData, TKey>(k, d, N1);
      return RBalance(N1);
    }
    if (Insert((BalanceNode<TData, TKey>*)(N1->Right), k, d) == 1) {
      return RBalance(N1);
    }
  }
}
template <typename TData, typename TKey>
void AVLTree<TData, TKey>::Delete(TKey k) {
  try {
    if (this->Find(k) == nullptr) {
      throw "Deleting a non-existing element,cannot complete Delete AVLTree";
    }
    Delete((BalanceNode<TData, TKey>*)this->Root, k);
  } catch (const char* exception) {
    std::cerr << "Error: " << exception << '\n';
  }
}
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::Delete(BalanceNode<TData, TKey>* N1, TKey k) {
  if (k < N1->GetKey()) {
    if (Delete((BalanceNode<TData, TKey>*)N1->Left, k) == 0)
      return RBalance(N1);
  }
  if (k > N1->GetKey()) {
    if (Delete((BalanceNode<TData, TKey>*)N1->Right, k) == 0)
      return LBalance(N1);
  }
  if (k == N1->GetKey()) {
    int h = 0;
    BalanceNode<TData, TKey>* p1 =
        (BalanceNode<TData, TKey>*)this->FindNext(N1);
    if (N1->Right != nullptr && N1->Left != nullptr) {
      h = LBalance(p1);
    }
    BinaryTree<TData, TKey>::Delete(N1->GetKey());
    return h;
  }
}
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::LBalance(BalanceNode<TData, TKey>* N1) {
  switch (N1->balance) {
    case 1:
      N1->balance = 0;
      break;
    case 0:
      N1->balance = -1;
      break;
    case -1:
      BalanceNode<TData, TKey>* p1;
      BalanceNode<TData, TKey>* p2;
      BalanceNode<TData, TKey>* p3;
      p1 = (BalanceNode<TData, TKey>*)(N1->Left);
      p3 = (BalanceNode<TData, TKey>*)(N1->Parent);
      if (p1->balance == -1) {
        if (p1->Right != nullptr) {
          p1->Right->Parent = N1;
        }
        N1->Left = p1->Right;

        if (N1 != nullptr) {
          N1->Parent = p1;
        }
        p1->Right = N1;
        N1->balance = 0;
        (*p1).Parent = p3;
        N1 = p1;
      } else {
        p2 = (BalanceNode<TData, TKey>*)(p1->Right);

        if (p2->Left != nullptr) {
          p2->Left->Parent = p1;
        }
        p1->Right = p2->Left;

        if (p1 != nullptr) {
          (*p1).Parent = p2;
        }
        p2->Left = p1;

        if (p2->Right != nullptr) {
          p2->Right->Parent = N1;
        }
        N1->Left = p2->Right;

        if (N1 != nullptr) {
          (*N1).Parent = p2;
        }
        p2->Right = N1;
        if (p2->balance == -1)
          N1->balance = 1;
        else
          N1->balance = 0;
        if (p2->balance == 1)
          N1->balance = -1;
        else
          p1->balance = 0;
        (*p2).Parent = p3;
        N1 = p2;
      }
      N1->balance = 0;
  }
  return abs(N1->balance);
}
template <typename TData, typename TKey>
int AVLTree<TData, TKey>::RBalance(BalanceNode<TData, TKey>* N1) {
  switch (N1->balance) {
    case -1:
      N1->balance = 0;
      break;
    case 0:
      N1->balance = 1;
      break;
    case 1:
      BalanceNode<TData, TKey>* p1;
      BalanceNode<TData, TKey>* p2;
      BalanceNode<TData, TKey>* p3 = (BalanceNode<TData, TKey>*)N1->Parent;
      p1 = (BalanceNode<TData, TKey>*)(N1->Right);
      if (p1->balance == 1) {
        if (p1->Left != nullptr) {
          p1->Left->Parent = N1;
        }
        N1->Right = p1->Left;

        if (N1 != nullptr) {
          (*N1).Parent = p1;
        }
        p1->Left = N1;
        N1->balance = 0;
        N1 = p1;
        (*p1).Parent = p3;
      } else {
        p2 = (BalanceNode<TData, TKey>*)(p1->Left);

        if (p2->Right != nullptr) {
          p2->Right->Parent = p1;
        }
        p1->Left = p2->Right;

        if (p1 != nullptr) {
          p1->Parent = p2;
        }
        p2->Right = p1;

        if (p2->Left != nullptr) {
          p2->Left->Parent = N1;
        }
        N1->Right = p2->Left;

        if (N1 != nullptr) {
          (*N1).Parent = p2;
        }
        p2->Left = N1;
        if (p2->balance == 1)
          N1->balance = -1;
        else
          N1->balance = 0;
        if (p2->balance == -1)
          N1->balance = 1;
        else
          p1->balance = 0;
        (*p2).Parent = p3;
        N1 = p2;
      }
      N1->balance = 0;
  }
  return abs(N1->balance);;
}
