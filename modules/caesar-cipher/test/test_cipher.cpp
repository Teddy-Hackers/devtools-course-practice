// Copyright 2023 Kolesov Maxim

#include <gtest/gtest.h>
#include "include/cipher.h"

TEST(CaesarCipher, assert_no_throw_in_default_constructor) {
  ASSERT_NO_THROW(CaesarCipher cc);
}

TEST(CaesarCipher, create_cipher_with_specific_kernel) {
  Kernel kernel;
  kernel.alphabet = "abc";
  kernel.shift = 7;

  CaesarCipher cipher(kernel);

  EXPECT_EQ(kernel, cipher.getKernel());
}

TEST(CaesarCipher, copy_cipher) {
  Kernel kernel;
  kernel.alphabet = "abc";
  kernel.shift = 7;
  CaesarCipher origin = CaesarCipher(kernel);

  CaesarCipher copy = CaesarCipher(origin);

  EXPECT_EQ(origin, copy);
}

TEST(CaesarCipher, move_cipher) {
  Kernel kernel;
  kernel.shift = 2;
  CaesarCipher origin(kernel);

  CaesarCipher mv = std::move(origin);

  EXPECT_EQ(kernel, mv.getKernel());
}

TEST(CaesarCipher, kernel_equal) {
  Kernel k, e;
  k.alphabet = "tes";
  k.shift = 6;
  k.foreignChars = false;
  e.alphabet = "tes";
  e.shift = 6;
  e.foreignChars = false;

  bool check = k == e;

  EXPECT_TRUE(check);
}

TEST(CaesarCipher, kernel_not_equal) {
  Kernel k, e;
  k.alphabet = "tes";
  k.shift = 6;
  e.alphabet = "tes";
  e.shift = 6;
  e.foreignChars = false;

  bool check = k != e;

  EXPECT_TRUE(check);
}

TEST(CaesarCipher, equal) {
  CaesarCipher c1, c2;

  bool check = c1 == c2;

  EXPECT_TRUE(check);
}

TEST(CaesarCipher, not_equal) {
  Kernel k;
  k.shift = 42;
  CaesarCipher c1, c2(k);

  bool check = c1 != c2;

  EXPECT_TRUE(check);
}

TEST(CaesarCipher, remove_equal_characters_in_constructor) {
  Kernel k;
  k.alphabet = "test";

  CaesarCipher c(k);

  EXPECT_EQ(c.getKernel().alphabet, "tes");
}

TEST(CaesarCipher, get_kernel) {
  Kernel k;
  k.shift = 42;
  CaesarCipher c(k);

  const Kernel &get = c.getKernel();

  EXPECT_EQ(get, k);
}

TEST(CaesarCipher, encode) {
  CaesarCipher c;

  std::string result = c.encode("test");

  EXPECT_EQ(result, "yjxy");
}

TEST(CaesarCipher, encode_with_space) {
  CaesarCipher c;

  std::string result = c.encode("this is a test");

  EXPECT_EQ(result, "ymnx nx f yjxy");
}

TEST(CaesarCipher, encode_with_no_space) {
  Kernel k;
  k.foreignChars = false;
  CaesarCipher c(k);

  std::string result = c.encode("this is a test");

  EXPECT_EQ(result, "ymnxnxfyjxy");
}

TEST(CaesarCipher, decode) {
  CaesarCipher c;

  std::string result = c.decode("yjxy");

  EXPECT_EQ(result, "test");
}

TEST(CaesarCipher, decode_with_space) {
  CaesarCipher c;

  std::string result = c.decode("ymnx nx f yjxy");

  EXPECT_EQ(result, "this is a test");
}

TEST(CaesarCipher, decode_with_no_space) {
  Kernel k;
  k.foreignChars = false;
  CaesarCipher c(k);

  std::string result = c.decode("ymnx nx f yjxy");

  EXPECT_EQ(result, "thisisatest");
}
