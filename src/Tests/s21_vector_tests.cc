#include <gtest/gtest.h>

#include <vector>

#include "../Includes/Containers/s21_vector.h"

TEST(Vector_Test, test1) {
  EXPECT_ANY_THROW({
    s21::Vector<int> v = s21::Vector<int>();
    v.At(-2) = 1;
  });
}

TEST(Vector_Test, test2) {
  EXPECT_NO_THROW({
    s21::Vector<char> v = s21::Vector<char>();
    v(2) = 'a';
    EXPECT_EQ(v(2), 'a');
  });
}

TEST(Vector_Test, construct_test1) {
  EXPECT_NO_THROW({
    s21::Vector<char> v = s21::Vector<char>();
    EXPECT_EQ(v.Size(), 0);
  });
}

TEST(Vector_Test, construct_test2) {
  EXPECT_NO_THROW({
    s21::Vector<char> v = s21::Vector<char>();
    for (size_t i = 0; i < 5; ++i) {
      v.PushBack(i + 1);
    }
    s21::Vector<char> v2 = s21::Vector<char>(v);
    EXPECT_EQ(v.Size(), v2.Size());
    EXPECT_EQ(v.Capacity(), v2.Capacity());
    for (size_t i = 0; i < v2.Size(); ++i) {
      EXPECT_EQ(v(i), v2(i));
    }
  });
}

TEST(Vector_Test, size_test) {
  EXPECT_NO_THROW({
    s21::Vector<int> v = s21::Vector<int>();
    for (size_t i = 0; i < 5; ++i) {
      v.PushBack(i + 1);
    }
    EXPECT_EQ(v.Size(), 5);
  });
}

TEST(Vector_Test, is_empty_test1) {
  EXPECT_NO_THROW({
    s21::Vector<int> v = s21::Vector<int>();
    EXPECT_TRUE(v.Empty());
    v.PushBack(1);
    EXPECT_FALSE(v.Empty());
  });
}

TEST(Vector_Test, clear_test1) {
  EXPECT_NO_THROW({
    s21::Vector<int> v = s21::Vector<int>();
    for (size_t i = 0; i < 5; ++i) {
      v.PushBack(i + 1);
    }
    v.Clear();
    EXPECT_TRUE(v.Empty());
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Capacity(), 5);
    for (size_t i = 0; i < v.Capacity(); ++i) {
      EXPECT_EQ(v(i), 0);
    }
  });
}

TEST(Vector_Test, top_test1) {
  EXPECT_NO_THROW({
    s21::Vector<int> v = s21::Vector<int>();
    EXPECT_EQ(v.Back(), 0);
    for (size_t i = 0; i < 5; ++i) {
      v.PushBack(i + 1);
    }
    EXPECT_EQ(v.Back(), 5);
  });
}

TEST(Vector_Test, push_back_test1) {
  EXPECT_NO_THROW({
    s21::Vector<int> v = s21::Vector<int>();
    for (size_t i = 0; i < 4000; ++i) {
      v.PushBack(i + 1);
    }
    for (size_t i = 0; i < 4000; ++i) {
      EXPECT_EQ(v(i), i + 1);
    }
  });
}

TEST(Vector_Test, push_back_test2) {
  std::string str[5] = {"array", "string", "hello", "s21", "school"};
  s21::Vector<std::string> v = s21::Vector<std::string>();
  EXPECT_NO_THROW({
    for (int i = 0; i < 5; ++i) {
      v.PushBack(str[i]);
    }
    EXPECT_EQ(v(0), "array");
    EXPECT_EQ(v(1), "string");
    EXPECT_EQ(v(2), "hello");
    EXPECT_EQ(v(3), "s21");
    EXPECT_EQ(v(4), "school");
  });
}

TEST(Vector_Test, push_front_test1) {
  EXPECT_NO_THROW({
    s21::Vector<int> v = s21::Vector<int>();
    for (size_t i = 0; i < 4000; ++i) {
      v.PushFront(i + 1);
    }
    for (size_t i = 0; i < 4000; ++i) {
      EXPECT_EQ(v(i), 4000 - i);
    }
  });
}

TEST(Vector_Test, push_front_test2) {
  std::string str[5] = {"array", "string", "hello", "s21", "school"};
  s21::Vector<std::string> v = s21::Vector<std::string>();
  EXPECT_NO_THROW({
    for (int i = 0; i < 5; ++i) {
      v.PushFront(str[i]);
      EXPECT_EQ(v(0), str[i]);
    }
  });
}

TEST(Vector_Test, pop_back_test1) {
  std::string str[5] = {"array", "string", "hello", "s21", "school"};
  s21::Vector<std::string> v = s21::Vector<std::string>();
  EXPECT_ANY_THROW({
    for (int i = 0; i < 5; ++i) {
      v.PushFront(str[i]);
    }
    v.PopBack();
    EXPECT_EQ(v.At(4), str[4]);
  });
}

TEST(Vector_Test, insert_test) {
  s21::Vector<int> v1 = {1, 2, 3};
  std::vector<int> v2 = {1, 2, 3};
  EXPECT_NO_THROW({
    auto it1 = v1.Begin();
    auto it2 = v2.begin();
    it1 = v1.Insert(it1, 1);
    it2 = v2.insert(it2, 1);
    ++it1;
    ++it2;
    it1 = v1.Insert(it1, 2);
    it2 = v2.insert(it2, 2);
    ++it1;
    ++it2;
    v1.Insert(it1, 3);
    v2.insert(it2, 3);
    EXPECT_EQ(v1.Size(), v2.size());
    for (size_t i = 0; i < v1.Size(); i++) {
      EXPECT_EQ(v1.At(i), v2.at(i));
    }
  });
}

TEST(Vector_Test, erase_test) {
  s21::Vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  EXPECT_NO_THROW({
    auto it1 = v1.Begin();
    auto it2 = v2.begin();
    ++it1;
    ++it2;
    v1.Erase(it1);
    v2.erase(it2);
    EXPECT_EQ(v1.Size(), v2.size());
    for (size_t i = 0; i < v1.Size(); i++) {
      EXPECT_EQ(v1.At(i), v2.at(i));
    }
  });
}

TEST(Vector_Test, max_size_test) {
  s21::Vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  EXPECT_NO_THROW({ EXPECT_EQ(v1.MaxSize(), v2.max_size()); });
}

TEST(Vector_Test, shrink_to_fit_test) {
  s21::Vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  EXPECT_NO_THROW({
    v1.ShrinkToFit();
    v2.shrink_to_fit();
    EXPECT_EQ(v1.Size(), v1.Capacity());
    EXPECT_EQ(v1.Size(), v2.size());
  });
}

TEST(Vector_Test, swap_test) {
  s21::Vector<int> v1 = {1, 2, 3, 4, 5};
  s21::Vector<int> v2 = std::move(v1);
  EXPECT_NO_THROW({
    EXPECT_EQ(v2.Size(), 5);
    EXPECT_EQ(v2.Capacity(), 12);
    EXPECT_EQ(v1.Size(), 0);
    EXPECT_EQ(v1.Capacity(), 0);
    for (size_t i = 0; i < v2.Size(); ++i) {
      EXPECT_EQ(v2(i), i + 1);
    }
  });
}

TEST(Vector_Test, emplace_back_test) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_NO_THROW({
    v.EmplaceBack(6, 7, 8, 9, 10);
    EXPECT_EQ(v.Size(), 10);
    for (size_t i = 0; i < v.Size(); ++i) {
      EXPECT_EQ(v(i), i + 1);
    }
  });
}

TEST(Vector_Test, emplace_test) {
  s21::Vector<int> v = {1, 2, 3};
  EXPECT_NO_THROW({
    auto it = v.Begin();
    ++it;
    ++it;
    ++it;
    v.Emplace(it, 4, 5, 6, 7, 8);
    EXPECT_EQ(v.Size(), 8);
    for (size_t i = 0; i < v.Size(); ++i) {
      EXPECT_EQ(v.At(i), i + 1);
    }
  });
}
