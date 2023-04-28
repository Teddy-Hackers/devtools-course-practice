// Copyright 2023 Korobeynikova Alice

#include <gtest/gtest.h>

#include "include/triangle.h"

TEST(Default, ParametrizedConstructor) {
  const Point p[3] = {Point{0, 0}, Point{0, 1}, Point{1, 0}};
  Triangle t(p[0], p[1], p[2]);
  auto points = t.GetPoints();
  for (size_t i = 0; i < 3; ++i) {
    ASSERT_EQ(points[i], p[i]);
  }  
}

TEST(Default, TriangleConsistsPoint) {
  const Point p[3] = {{0, 0}, {0, 1}, {1, 0}};
  Triangle t(p[0], p[1], p[2]);
  Point p_inside_t{0.2, 0.2};
  ASSERT_TRUE(t.Consist(p_inside_t));
}

TEST(Default, TriangleDoesNotConsistPoint) {
  const Point p[3] = {{0, 0}, {0, 1}, {1, 0}};
  Triangle t(p[0], p[1], p[2]);
  Point p_not_inside_t{-0.5, 0.5};
  ASSERT_FALSE(t.Consist(p_not_inside_t));
}
