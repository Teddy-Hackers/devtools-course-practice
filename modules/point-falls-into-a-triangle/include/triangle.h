// Copyright 2023 Korobeynikova Alice

#pragma once
#include <array>
#include <cmath>
#include <limits>

struct Point {
  double x = 0, y = 0;
  bool operator==(const Point& p2) const;
};

class Triangle {
  Point p1, p2, p3;

 public:
  Triangle(const Point& p1, const Point& p2, const Point& p3);
  std::array<Point, 3> GetPoints() const;
  bool Consist(const Point& p) const;
};
