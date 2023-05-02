// Copyright 2023 Prokofev Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Prokofev_Denis_ComplexNumberTest, Create) {
  double re = 1.6;
  double im = 2.4;
  ComplexNumber cn(re, im);
  EXPECT_EQ(re, cn.getRe());
  EXPECT_EQ(im, cn.getIm());
}

TEST(Prokofev_Denis_ComplexNumberTest, Set) {
  double re = 2.7;
  double im = 7.2;
  ComplexNumber cn;
  cn.setRe(re);
  cn.setIm(im);
  EXPECT_EQ(re, cn.getRe());
  EXPECT_EQ(im, cn.getIm());
}

TEST(Prokofev_Denis_ComplexNumberTest, Copy) {
  
  double re = 3.1;
  double im = 5.7;
  ComplexNumber cn1;
  cn1.setRe(re);
  cn1.setIm(im);
  ComplexNumber cn2=new ComplexNumber(cn1);
  EXPECT_EQ(re, cn2.getRe());
  EXPECT_EQ(im, cn2.getIm());
}

TEST(Prokofev_Denis_ComplexNumberTest, Diff) {
  double re1, re2, im1, im2;
  re1 = 3.0;
  im1 = 4.0;
  re2 = 1.0;
  im2 = 0.0;
  ComplexNumber cn1(re1, im1);
  ComplexNumber cn2(re2, im2);
  ComplexNumber cn_res = cn1 - cn2;
  resRe=cn_res.getRe();
  resIm=cn_res.getIm();
  EXPECT_DOUBLE_EQ(2.0, resRe);
  EXPECT_DOUBLE_EQ(4.0, resIm);
}
