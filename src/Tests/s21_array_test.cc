#include "../Includes/Containers/s21_array.h"

#include <gtest/gtest.h>

#include <array>

TEST(array_test, fill_test) {
  std::array<int, 50> a;
  s21::Array<int, 50> ma;
  a.fill(156);
  ma.Fill(156);
  EXPECT_NO_THROW({
    for (int i = 0; i < 50; i++) {
      EXPECT_EQ(a.at(i), ma.At(i));
    }
  });
}

TEST(array_test, throw_test) {
  s21::Array<int, 2> ma;
  EXPECT_ANY_THROW({ ma.At(6); });
}

TEST(array_test, str_test) {
  std::array<std::string, 6> a;
  s21::Array<std::string, 6> ma;
  std::string texts[6] = {"hello",      "it's a",          "array test!",
                          "thanks for", "tests watching!", "last sentence"};
  for (int i = 0; i < 6; i++) {
    a[i] = texts[i];
    ma[i] = texts[i];
  }
  for (int i = 0; i < 6; i++) EXPECT_EQ(a[i], ma[i]);
}

TEST(array_test, size_test) {
  std::array<std::string, 156> a;
  s21::Array<std::string, 156> ma;
  EXPECT_EQ(a.size(), ma.Size());
}

TEST(array_test, operator_test) {
  std::array<int, 100> a;
  s21::Array<int, 100> ma;
  for (int i = 0; i < 100; i++) {
    a[i] = ma[i] = i;
    EXPECT_EQ(a[i], ma[i]);
  }
}

TEST(array_test, is_empty_test) {
  std::array<int, 0> a;
  s21::Array<int, 0> ma;

  std::array<int, 1> a2;
  s21::Array<int, 1> ma2;

  EXPECT_EQ(a.empty(), ma.Empty());
  EXPECT_EQ(a2.empty(), ma2.Empty());
}

TEST(array_test, move_test) {
  s21::Array<int, 4> a_f;
  a_f.Fill(5);

  s21::Array<int, 4> a_s(std::move(a_f));
  EXPECT_EQ(a_s[0], 5);
}

TEST(array_test, copy_test) {
  s21::Array<int, 4> a = {1, 2, 3, 4};
  s21::Array<int, 4> a_f = a;

  for (int i = 0; i < 4; i++) EXPECT_EQ(a[i], a_f[i]);
}

TEST(array_test, at_test) {
  srand(time(NULL));

  s21::Array<int, 10> a = {1, 2, 3, 4, 5, 6, 7, 8, 10};

  int value = rand() % 10;
  EXPECT_EQ(a[value], a.At(value));
}

TEST(array_test, at_test_2) {
  s21::Array<int, 10> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<int, 10> stda = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  EXPECT_EQ(a.At(3), stda.at(3));
}

TEST(array_test, at_test_throw) {
  s21::Array<int, 4> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  EXPECT_ANY_THROW({ a.At(250); });
}

TEST(array_test, move_operator) {
  s21::Array<int, 10> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  s21::Array<int, 10> a2;
  a2 = std::move(a);

  EXPECT_EQ(a2[5], 6);
  for (size_t i = 0; i < a.Size(); i++) EXPECT_EQ(a[i], 0);
}

TEST(array_test, move_constructor) {
  s21::Array<int, 10> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  s21::Array<int, 10> a2(std::move(a));

  EXPECT_EQ(a2[5], 6);

  for (size_t i = 0; i < a.Size(); i++) EXPECT_EQ(a[i], 0);
}

TEST(array_test, data_test) {
  s21::Array<int, 4> a = {1234567, 15, 20, 15};

  s21::Array<int, 4>::s21_iterator it = a.Data();
  EXPECT_EQ(*it, 1234567);
  it++;
  EXPECT_EQ(*it, 15);
  it++;
  EXPECT_EQ(*it, 20);
  it++;
  EXPECT_EQ(*it, 15);
}

TEST(array_test, struct_test) {
  struct hello_world {
    int x{};
    std::string s;
  };

  s21::Array<hello_world, 5> a;

  for (size_t i = 0; i < a.Size(); i++) {
    a[i].x = i;
    a[i].s = "Hello!";
  }

  for (size_t i = 0; i < a.Size(); i++) {
    EXPECT_EQ(a[i].x, i);
    EXPECT_STREQ(a[i].s.c_str(), "Hello!");
  }
}

TEST(array_test, front_back) {
  s21::Array<int, 4> a = {256, 0, 0, 512};

  EXPECT_EQ(a.Front(), 256);
  EXPECT_EQ(a.Back(), 512);
}

TEST(array_test, initialization_list_test) {
  s21::Array<int, 10> a{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  int counter = 1;
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(a[i], counter);
    counter *= 2;
  }
}
