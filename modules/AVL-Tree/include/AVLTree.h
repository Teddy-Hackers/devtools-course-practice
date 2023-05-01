// Copyright 2023 Ermolaev Danila

#pragma once
#include "BinaryTree.h"
#include <iostream>
#include <string>

template <typename TData, typename TKey>
class BalanceNode : public TreeNode<TData, TKey> {
 public:
  int balance;

  BalanceNode(TKey k = {}, TData d = {}, TreeNode<TData, TKey>* P = nullptr,
              TreeNode<TData, TKey>* R = nullptr,
              TreeNode<TData, TKey>* L = nullptr, int bal = 0)
      : TreeNode<TData, TKey>(k, d, P, L, R), balance(bal) {}
};

template <typename TData, typename TKey>
class AVLTree : public BinaryTree<TData, TKey> {
 protected:
  int Insert(BalanceNode<TData, TKey>* N1, TKey k, TData d);
  int Delete(BalanceNode<TData, TKey>* N1, TKey k);
  int LBalance(BalanceNode<TData, TKey>* N1);
  int RBalance(BalanceNode<TData, TKey>* N1);

 public:
  AVLTree() : BinaryTree<TData, TKey>() {}

  void printTree(BalanceNode<TData, TKey>* node, Trunk* prev, bool isLeft);

  void Insert(TKey k, TData d);
  void Delete(TKey k);
};

