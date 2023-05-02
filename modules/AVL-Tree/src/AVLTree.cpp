// Copyright 2023 Ermolaev Danila

#include "include/AVLTree.h"
#include <iostream>

template <typename TData>
bool AVLTree<TData>::contains(const TData& value) const {
  return containRecurse(root, value);
}

