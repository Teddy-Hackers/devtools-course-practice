// Copyright 2023 Khairetdinov Timur
#pragma once

#include <vector>

class Graph {
    using Vector = std::vector<int>;
    using Matrix = std::vector<Vector>;
 public:
    Graph();
    explicit Graph(size_t);
    explicit Graph(Matrix&);
    size_t GetSize() const;
    void SetSize(size_t);
    void SetEdge(size_t, size_t, int);
    int GetDiameter();
 private:
    size_t graph_size_;
    Matrix weights_;
};
