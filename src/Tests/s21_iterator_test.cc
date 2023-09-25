#include <gtest/gtest.h>

#include "../Includes/Containers/s21_array.h"

TEST(iterator_test, operator_pp) {
  s21::Array<int, 10> a = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  int temp_value = 1;
  for (auto it = a.Begin(); it != a.End(); it++) {
    EXPECT_EQ(*it, temp_value);
    temp_value *= 2;
  }
}

TEST(iterator_test, operator_mm) {
  s21::Array<int, 10> a = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  int temp_value = 512;
  auto it = a.End();
  it--;
  for (; it != a.Begin(); it--) {
    EXPECT_EQ(*it, temp_value);
    temp_value /= 2;
  }
}

TEST(iterator_test, not_equal) {
  s21::Array<int, 10> a = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  auto it_beg = a.Begin();
  auto it_end = a.End();
  it_end--;
  EXPECT_FALSE(it_beg == it_end);
}

TEST(iterator_test, equal) {
  s21::Array<int, 10> a = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  auto it_beg_f = a.Begin();
  auto it_beg_s = a.Begin();

  for (int i = 0; i < 3; i++) {
    it_beg_f++;
    ++it_beg_s;
  }

  EXPECT_TRUE(it_beg_s == it_beg_f);
}

TEST(iterator_test, copy) {
  s21::Array<int, 10> a = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  auto it_beg_f = a.Begin();
  for (int i = 0; i < 3; i++) it_beg_f++;

  auto it2 = it_beg_f;

  EXPECT_EQ(*it2, *it_beg_f);
}

TEST(iterator_test, begin_test) {
  s21::Array<int, 10> a = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  auto it = a.Begin();

  EXPECT_EQ(*it, 1);
}

TEST(iterator_test, end_test) {
  s21::Array<int, 10> a = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  auto it = a.End();
  it--;

  EXPECT_EQ(*it, 512);
}
