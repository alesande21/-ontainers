#include <list>
#include <string>

#include "../Includes/Containers/s21_map.h"
#include "gtest/gtest.h"

TEST(map_test, basic_constr) {
  s21::Map<int, char> map_d;
  s21::Map<double, char> map_i;
  s21::Map<char, std::string> map_c;
  EXPECT_EQ(map_d.Size(), 0);
  EXPECT_EQ(map_i.Size(), 0);
  EXPECT_EQ(map_c.Size(), 0);
}

TEST(map_test, constr_with_indefinite_number_of_elements) {
  s21::Map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);
  auto it = map_1.Begin();
  EXPECT_EQ((*it).first, 1.1);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 2.2);
  EXPECT_EQ((*it).second, 'b');
  ++it;
  EXPECT_EQ((*it).first, 3.3);
  EXPECT_EQ((*it).second, 'c');
  ++it;
  EXPECT_EQ((*it).first, 4.4);
  EXPECT_EQ((*it).second, 'd');
  ++it;
  EXPECT_EQ((*it).first, 5.5);
  EXPECT_EQ((*it).second, 'e');

  it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, constr_with_indefinite_number_of_elements_string) {
  s21::Map<double, std::string> map_1(
      {{5, "apple"},  {3, "banana"},      {10, "orange"},  {2, "grape"},
       {7, "dog"},    {1, "cat"},         {8, "elephant"}, {4, "giraffe"},
       {2, "zebra"},  {6, "lion"},        {3, "cherry"},   {9, "peach"},
       {4, "pear"},   {11, "watermelon"}, {1, "turtle"},   {12, "frog"},
       {6, "spider"}, {15, "snake"},      {13, "koala"},   {16, "monkey"}});
  std::map<double, std::string> orignal_map_1(
      {{5, "apple"},  {3, "banana"},      {10, "orange"},  {2, "grape"},
       {7, "dog"},    {1, "cat"},         {8, "elephant"}, {4, "giraffe"},
       {2, "zebra"},  {6, "lion"},        {3, "cherry"},   {9, "peach"},
       {4, "pear"},   {11, "watermelon"}, {1, "turtle"},   {12, "frog"},
       {6, "spider"}, {15, "snake"},      {13, "koala"},   {16, "monkey"}});
  EXPECT_EQ(map_1.Size(), 15);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());
  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, copy_constr) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);
  s21::Map<double, char> map_2(map_1);

  EXPECT_EQ(map_1.Size(), 5);
  EXPECT_EQ(map_2.Size(), 5);

  auto it = map_1.Begin();
  auto it_2 = map_2.Begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, copy_operator_01) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);
  s21::Map<double, char> map_2(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  EXPECT_EQ(map_2.Size(), 5);

  map_1 = map_2;
  EXPECT_EQ(map_1.Size(), 5);
  EXPECT_EQ(map_2.Size(), 5);
  auto it = map_1.Begin();
  auto it_2 = map_2.Begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, copy_operator_02) {
  s21::Map<double, char> map_1;
  EXPECT_EQ(map_1.Size(), 0);
  s21::Map<double, char> map_2;
  EXPECT_EQ(map_2.Size(), 0);

  map_1 = map_2;
  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 0);
  auto it = map_1.Begin();
  auto it_2 = map_2.Begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, copy_operator_06) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {1.1, 'a'}, {2.2, 'b'}});
  s21::Map<double, char> map_2;

  EXPECT_EQ(map_1.Size(), 2);

  map_1 = map_2;
  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 0);
}

TEST(map_test, copy_operator_05) {
  s21::Map<double, char> map_1;
  s21::Map<double, char> map_2;

  EXPECT_EQ(map_1.Size(), 0);

  map_1 = map_2;
  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 0);
}

TEST(map_test, copy_operator_03) {
  s21::Map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  s21::Map<double, char> map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});

  EXPECT_EQ(map_1.Size(), 2);
  EXPECT_EQ(map_2.Size(), 3);

  map_1 = map_2;
  EXPECT_EQ(map_1.Size(), 3);
  EXPECT_EQ(map_2.Size(), 3);

  auto it = map_1.Begin();
  EXPECT_EQ((*it).first, 11);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 22);
  EXPECT_EQ((*it).second, 'b');
  ++it;
  EXPECT_EQ((*it).first, 33);
  EXPECT_EQ((*it).second, 'b');
  it = map_1.Begin();
  auto it_2 = map_2.Begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(map_test, copy_operator_04) {
  s21::Map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});

  EXPECT_EQ(map_1.Size(), 2);

  map_1 = map_1;
  EXPECT_EQ(map_1.Size(), 2);
}

TEST(map_test, move_constr) {
  s21::Map<double, char> map_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);
  s21::Map<double, char> map_2(std::move(map_1));

  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 5);

  std::map<double, char> orignal_list_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});

  auto it = map_2.Begin();
  EXPECT_DOUBLE_EQ((*it).first, 0.4);
  EXPECT_EQ((*it).second, 'o');
  ++it;
  EXPECT_DOUBLE_EQ((*it).first, 0.5);
  EXPECT_EQ((*it).second, 'e');
  ++it;
  EXPECT_DOUBLE_EQ((*it).first, 1.5);
  EXPECT_EQ((*it).second, 's');
  ++it;
  EXPECT_DOUBLE_EQ((*it).first, 2.9);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_DOUBLE_EQ((*it).first, 3.5);
  EXPECT_EQ((*it).second, 'c');

  it = map_2.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != map_2.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, move_constr_empty) {
  s21::Map<double, char> map_1;
  EXPECT_EQ(map_1.Size(), 0);
  s21::Map<double, char> map_2(std::move(map_1));

  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 0);
}

TEST(map_test, constr_move_to_yourself) {
  s21::Map<double, char> map_1(std::move(map_1));
  EXPECT_EQ(map_1.Size(), 0);
}

TEST(map_test, move_operator) {
  s21::Map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.Size(), 2);
  s21::Map<double, char> map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});
  EXPECT_EQ(map_2.Size(), 3);

  map_1 = std::move(map_2);

  EXPECT_EQ(map_1.Size(), 3);
  EXPECT_EQ(map_2.Size(), 0);

  auto it = map_1.Begin();
  EXPECT_EQ((*it).first, 11);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 22);
  EXPECT_EQ((*it).second, 'b');
  ++it;
  EXPECT_EQ((*it).first, 33);
  EXPECT_EQ((*it).second, 'b');
}

TEST(map_test, move_operator_02) {
  s21::Map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.Size(), 2);
  s21::Map<double, char> map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});
  EXPECT_EQ(map_2.Size(), 3);

  map_2 = std::move(map_1);

  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 2);

  auto it = map_2.Begin();
  EXPECT_EQ((*it).first, 1.1);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 2.2);
  EXPECT_EQ((*it).second, 'b');
}

TEST(map_test, move_operator_05) {
  s21::Map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.Size(), 2);
  s21::Map<double, char> map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});
  EXPECT_EQ(map_2.Size(), 3);

  std::map<double, char> original_map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.Size(), 2);
  std::map<double, char> original_map_2({{11, 'a'}, {22, 'b'}, {33, 'b'}});
  map_2 = std::move(map_1);
  original_map_2 = std::move(original_map_1);

  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 2);
  EXPECT_EQ(map_1.Size(), original_map_1.size());
  EXPECT_EQ(map_2.Size(), original_map_2.size());

  auto it = map_2.Begin();
  EXPECT_EQ((*it).first, 1.1);
  EXPECT_EQ((*it).second, 'a');
  ++it;
  EXPECT_EQ((*it).first, 2.2);
  EXPECT_EQ((*it).second, 'b');
  it = map_2.Begin();
  auto it_2 = original_map_2.begin();
  for (; it != map_2.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, move_operator_to_yourself) {
  s21::Map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.Size(), 2);
  map_1 = std::move(map_1);
  EXPECT_EQ(map_1.Size(), 0);
}

TEST(map_test, move_operator_03) {
  s21::Map<double, char> map_1;
  EXPECT_EQ(map_1.Size(), 0);
  s21::Map<double, char> map_2;
  EXPECT_EQ(map_2.Size(), 0);

  map_2 = std::move(map_1);

  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 0);
}

TEST(map_test, move_operator_04) {
  s21::Map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}});
  EXPECT_EQ(map_1.Size(), 2);
  s21::Map<double, char> map_2;
  EXPECT_EQ(map_2.Size(), 0);

  map_1 = std::move(map_2);

  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 0);
}

TEST(map_test, test_size) {
  s21::Map<double, char> map_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());
}

TEST(map_test, test_max_size) {
  s21::Map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.MaxSize(), orignal_map_1.max_size());
}

TEST(map_test, test_max_size_02) {
  s21::Map<float, char> map_1;
  std::map<float, char> orignal_map_1;
  EXPECT_EQ(map_1.MaxSize(), orignal_map_1.max_size());
}

TEST(map_test, test_max_size_03) {
  s21::Map<int, char> map_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  std::map<int, char> orignal_map_1(
      {{1.5, 's'}, {2.9, 'a'}, {3.5, 'c'}, {0.4, 'o'}, {0.5, 'e'}});
  EXPECT_EQ(map_1.MaxSize(), orignal_map_1.max_size());
}

TEST(map_test, test_merge) {
  s21::Map<int, char> map_1({{1, 'a'}, {3, 'b'}, {5, 'b'}});
  s21::Map<int, char> map_2({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  EXPECT_EQ(map_1.Size(), 3);
  EXPECT_EQ(map_2.Size(), 4);

  std::map<int, char> orignal_map_1(
      {{1, 'a'}, {3, 'b'}, {5, 'b'}, {2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  map_1.Merge(map_2);

  EXPECT_EQ(map_1.Size(), 7);
  EXPECT_EQ(map_2.Size(), 0);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_merge_02) {
  s21::Map<int, char> map_1({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});
  s21::Map<int, char> map_2({{1, 'a'}, {3, 'b'}, {5, 'b'}});

  EXPECT_EQ(map_1.Size(), 4);
  EXPECT_EQ(map_2.Size(), 3);

  std::map<int, char> orignal_map_1(
      {{1, 'a'}, {3, 'b'}, {5, 'b'}, {2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  map_1.Merge(map_2);

  EXPECT_EQ(map_1.Size(), 7);
  EXPECT_EQ(map_2.Size(), 0);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_merge_03) {
  s21::Map<int, char> map_1;
  s21::Map<int, char> map_2({{1, 'a'}, {3, 'b'}, {5, 'b'}});

  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_2.Size(), 3);

  std::map<int, char> orignal_map_1({{1, 'a'}, {3, 'b'}, {5, 'b'}});

  //  EXPECT_EQ(orignal_map_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  map_1.Merge(map_2);

  EXPECT_EQ(map_1.Size(), 3);
  EXPECT_EQ(map_2.Size(), 0);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_merge_04) {
  s21::Map<int, char> map_1({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});
  s21::Map<int, char> map_2;

  EXPECT_EQ(map_1.Size(), 4);
  EXPECT_EQ(map_2.Size(), 0);

  std::map<int, char> orignal_map_1({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  map_1.Merge(map_2);

  EXPECT_EQ(map_1.Size(), 4);
  EXPECT_EQ(map_2.Size(), 0);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_empty) {
  s21::Map<int, char> map_1({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});
  s21::Map<int, char> map_2;

  EXPECT_EQ(map_1.Empty(), false);
  EXPECT_EQ(map_2.Empty(), true);
}

TEST(map_test, test_insert) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);

  auto res_test_1 = map_1.Insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.2);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_02) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);

  auto res_test_1 = map_1.Insert({3.3, 'b'});
  EXPECT_EQ(res_test_1.second, false);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.3);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'c');

  auto res_orignal_set_1 = orignal_map_1.insert({3.3, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_03) {
  s21::Map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.Size(), 0);

  auto res_test_1 = map_1.Insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.2);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_04) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);

  auto res_test_1 = map_1.Insert(3.2, 'b');
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.2);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_05) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);

  auto res_test_1 = map_1.Insert(3.3, 'b');
  EXPECT_EQ(res_test_1.second, false);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.3);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'c');

  auto res_orignal_set_1 = orignal_map_1.insert({3.3, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_06) {
  s21::Map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.Size(), 0);

  auto res_test_1 = map_1.Insert(3.2, 'b');
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.2);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.2, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_or_assign) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'b'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);

  auto res_test_1 = map_1.InsertOrAssign(3.3, 'b');
  EXPECT_EQ(res_test_1.second, false);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.3);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_or_assign_02) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);

  auto res_test_1 = map_1.InsertOrAssign(3.4, 'b');
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.4);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.4, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_insert_or_assign_03) {
  s21::Map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.Size(), 0);

  auto res_test_1 = map_1.InsertOrAssign(3.4, 'b');
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first, 3.4);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().second, 'b');

  auto res_orignal_set_1 = orignal_map_1.insert({3.4, 'b'});
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*().first,
                   res_orignal_set_1.first.operator*().first);
  EXPECT_EQ(res_test_1.first.operator*().second,
            res_orignal_set_1.first.operator*().second);

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

// TEST(map_test, test_at) {
//     s21::Map<double, char> map_1({{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4,
//     'd'}, {5.5, 'e'}}); s21::Map<double, char> map_2; EXPECT_EQ(map_1.Size(),
//     5);
//
//     auto res_test_1 = map_1.At(3.3);
//     EXPECT_EQ(res_test_1, 'c');
//     EXPECT_THROW(map_1.At(3.2), std::out_of_range);
//     EXPECT_THROW(map_2.At(3.3), std::out_of_range);
// }

TEST(map_test, test_operator_sq) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);

  EXPECT_EQ(map_1[4.4], 'd');
  EXPECT_EQ(orignal_map_1[4.4], map_1[4.4]);

  map_1[4.4] = 'a';
  orignal_map_1[4.4] = 'a';

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_operator_sq_02) {
  s21::Map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.Size(), 0);

  EXPECT_EQ(orignal_map_1[4.4], map_1[4.4]);

  map_1[4.4] = 'a';
  orignal_map_1[4.4] = 'a';

  EXPECT_EQ(map_1[4.4], 'a');
  EXPECT_EQ(orignal_map_1[4.4], map_1[4.4]);

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_contains) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  s21::Map<double, char> map_2;
  EXPECT_EQ(map_1.Size(), 5);

  auto res_test_1 = map_1.Contains(3.3);
  EXPECT_EQ(res_test_1, true);
  res_test_1 = map_1.Contains(3.2);
  EXPECT_EQ(res_test_1, false);

  auto res_test_2 = map_2.Contains(3.3);
  EXPECT_EQ(res_test_2, false);
}

TEST(map_test, test_clear_full) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  EXPECT_EQ(map_1.Size(), 5);

  map_1.Clear();
  orignal_map_1.clear();
  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

TEST(map_test, test_clear_empty) {
  s21::Map<double, char> map_1;
  std::map<double, char> orignal_map_1;
  EXPECT_EQ(map_1.Size(), 0);

  map_1.Clear();
  orignal_map_1.clear();
  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
}

struct President {
  std::string name{};
  std::string country{};
  int year{};

  President(){};

  President(std::string p_name, std::string p_country, int p_year)
      : name(std::move(p_name)), country(std::move(p_country)), year(p_year) {}
  President(President&& other)
      : name(std::move(other.name)),
        country(std::move(other.country)),
        year(other.year) {}
  President(const President& other) = default;
  President& operator=(const President& other) = default;
  bool operator<(const President& other) const { return year < other.year; }
};

TEST(map_test, test_emplace) {
  s21::Map<President, President> map_1;
  std::map<President, President> orignal_map_1;
  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  map_1.Emplace(President("Nelson Mandela", "South Africa", 1994),
                President("Vladimir Lenin", "Soviet Union", 1917));
  orignal_map_1.emplace(President("Nelson Mandela", "South Africa", 1994),
                        President("Vladimir Lenin", "Soviet Union", 1917));

  EXPECT_EQ(map_1.Size(), 1);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_EQ((*it).first.name, (*it_2).first.name);
    EXPECT_EQ((*it).first.country, (*it_2).first.country);
    EXPECT_EQ((*it).first.year, (*it_2).first.year);
    EXPECT_EQ((*it).second.name, (*it_2).second.name);
    EXPECT_EQ((*it).second.country, (*it_2).second.country);
    EXPECT_EQ((*it).second.year, (*it_2).second.year);
    ++it_2;
  }

  s21::Map<President, President> list_2;
  std::map<President, President> orignal_list_2;
  EXPECT_EQ(list_2.Size(), 0);
  EXPECT_EQ(list_2.Size(), orignal_list_2.size());

  list_2.Emplace(President("Franklin Delano Roosevelt", "the USA", 1936),
                 President("Joseph Stalin", "Soviet Union", 1924));
  orignal_list_2.emplace(
      President("Franklin Delano Roosevelt", "the USA", 1936),
      President("Joseph Stalin", "Soviet Union", 1924));

  EXPECT_EQ(list_2.Size(), 1);
  EXPECT_EQ(list_2.Size(), orignal_list_2.size());

  auto it_re = list_2.Begin();
  auto it_re_2 = orignal_list_2.begin();
  for (; it_re != list_2.End() && it_re_2 != orignal_list_2.end(); ++it_re) {
    EXPECT_EQ((*it_re).first.name, (*it_re_2).first.name);
    EXPECT_EQ((*it_re).first.country, (*it_re_2).first.country);
    EXPECT_EQ((*it_re).first.year, (*it_re_2).first.year);
    EXPECT_EQ((*it_re).second.name, (*it_re_2).second.name);
    EXPECT_EQ((*it_re).second.country, (*it_re_2).second.country);
    EXPECT_EQ((*it_re).second.year, (*it_re_2).second.year);
    ++it_re_2;
  }

  // front

  EXPECT_EQ(map_1.Size(), 1);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  map_1.Emplace(President("Lionel Messi", "Barcelona", 2010),
                President("Joseph Stalin", "Soviet Union", 1924));
  orignal_map_1.emplace(President("Lionel Messi", "Barcelona", 2010),
                        President("Joseph Stalin", "Soviet Union", 1924));

  EXPECT_EQ(map_1.Size(), 2);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_EQ((*it).first.name, (*it_2).first.name);
    EXPECT_EQ((*it).first.country, (*it_2).first.country);
    EXPECT_EQ((*it).first.year, (*it_2).first.year);
    EXPECT_EQ((*it).second.name, (*it_2).second.name);
    EXPECT_EQ((*it).second.country, (*it_2).second.country);
    EXPECT_EQ((*it).second.year, (*it_2).second.year);
    ++it_2;
  }

  EXPECT_EQ(map_1.Size(), 2);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  map_1.Emplace(President("Franklin Delano Roosevelt", "the USA", 1936),
                President("Georgy Malenkov", "Soviet Union", 1953));
  orignal_map_1.emplace(President("Franklin Delano Roosevelt", "the USA", 1936),
                        President("Georgy Malenkov", "Soviet Union", 1953));

  EXPECT_EQ(map_1.Size(), 3);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End() && it_2 != orignal_map_1.end(); ++it) {
    EXPECT_EQ((*it).first.name, (*it_2).first.name);
    EXPECT_EQ((*it).first.country, (*it_2).first.country);
    EXPECT_EQ((*it).first.year, (*it_2).first.year);
    EXPECT_EQ((*it).second.name, (*it_2).second.name);
    EXPECT_EQ((*it).second.country, (*it_2).second.country);
    EXPECT_EQ((*it).second.year, (*it_2).second.year);
    ++it_2;
  }

  EXPECT_EQ(map_1.Size(), 3);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  ++it;
  ++it_2;

  auto vec = map_1.Emplace(President("Cristiano Ronaldo", "Real Madrid", 2016),
                           President("Georgy Malenkov", "Soviet Union", 1953));
  auto vec_2 =
      orignal_map_1.emplace(President("Cristiano Ronaldo", "Real Madrid", 2016),
                            President("Georgy Malenkov", "Soviet Union", 1953));

  auto itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).first.name, (*vec_2.first).first.name);
  EXPECT_EQ((*itr_vec->first).first.country, (*vec_2.first).first.country);
  EXPECT_EQ((*itr_vec->first).first.year, (*vec_2.first).first.year);
  EXPECT_EQ((*itr_vec->first).second.name, (*vec_2.first).second.name);
  EXPECT_EQ((*itr_vec->first).second.country, (*vec_2.first).second.country);
  EXPECT_EQ((*itr_vec->first).second.year, (*vec_2.first).second.year);

  EXPECT_EQ(map_1.Size(), 4);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End() && it_2 != orignal_map_1.end(); ++it) {
    EXPECT_EQ((*it).first.name, (*it_2).first.name);
    EXPECT_EQ((*it).first.country, (*it_2).first.country);
    EXPECT_EQ((*it).first.year, (*it_2).first.year);
    EXPECT_EQ((*it).second.name, (*it_2).second.name);
    EXPECT_EQ((*it).second.country, (*it_2).second.country);
    EXPECT_EQ((*it).second.year, (*it_2).second.year);
    ++it_2;
  }

  vec = map_1.Emplace(President("Cristiano", "Real", 2016),
                      President("Lionel Messi", "Paris Saint-Germain", 2021));
  vec_2 = orignal_map_1.emplace(
      President("Cristiano", "Real", 2016),
      President("Lionel Messi", "Paris Saint-Germain", 2021));

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, false);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).first.name, (*vec_2.first).first.name);
  EXPECT_EQ((*itr_vec->first).first.country, (*vec_2.first).first.country);
  EXPECT_EQ((*itr_vec->first).first.year, (*vec_2.first).first.year);
  EXPECT_EQ((*itr_vec->first).second.name, (*vec_2.first).second.name);
  EXPECT_EQ((*itr_vec->first).second.country, (*vec_2.first).second.country);
  EXPECT_EQ((*itr_vec->first).second.year, (*vec_2.first).second.year);

  EXPECT_EQ(map_1.Size(), 4);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End() && it_2 != orignal_map_1.end(); ++it) {
    EXPECT_EQ((*it).first.name, (*it_2).first.name);
    EXPECT_EQ((*it).first.country, (*it_2).first.country);
    EXPECT_EQ((*it).first.year, (*it_2).first.year);
    EXPECT_EQ((*it).second.name, (*it_2).second.name);
    EXPECT_EQ((*it).second.country, (*it_2).second.country);
    EXPECT_EQ((*it).second.year, (*it_2).second.year);
    ++it_2;
  }

  vec = map_1.Emplace(President("Luka Modrić", "Real Madrid", 2018),
                      President("Lionel Messi", "Paris Saint-Germain", 2021));
  vec_2 = orignal_map_1.emplace(
      President("Luka Modrić", "Real Madrid", 2018),
      President("Lionel Messi", "Paris Saint-Germain", 2021));

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).first.name, (*vec_2.first).first.name);
  EXPECT_EQ((*itr_vec->first).first.country, (*vec_2.first).first.country);
  EXPECT_EQ((*itr_vec->first).first.year, (*vec_2.first).first.year);
  EXPECT_EQ((*itr_vec->first).second.name, (*vec_2.first).second.name);
  EXPECT_EQ((*itr_vec->first).second.country, (*vec_2.first).second.country);
  EXPECT_EQ((*itr_vec->first).second.year, (*vec_2.first).second.year);

  EXPECT_EQ(map_1.Size(), 5);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End() && it_2 != orignal_map_1.end(); ++it) {
    EXPECT_EQ((*it).first.name, (*it_2).first.name);
    EXPECT_EQ((*it).first.country, (*it_2).first.country);
    EXPECT_EQ((*it).first.year, (*it_2).first.year);
    EXPECT_EQ((*it).second.name, (*it_2).second.name);
    EXPECT_EQ((*it).second.country, (*it_2).second.country);
    EXPECT_EQ((*it).second.year, (*it_2).second.year);
    ++it_2;
  }

  vec = map_1.Emplace(President("Karim Benzema", "Real Madrid", 2022),
                      President("Lionel Messi", "Paris Saint-Germain", 2021));
  vec_2 = orignal_map_1.emplace(
      President("Karim Benzema", "Real Madrid", 2022),
      President("Lionel Messi", "Paris Saint-Germain", 2021));

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).first.name, (*vec_2.first).first.name);
  EXPECT_EQ((*itr_vec->first).first.country, (*vec_2.first).first.country);
  EXPECT_EQ((*itr_vec->first).first.year, (*vec_2.first).first.year);
  EXPECT_EQ((*itr_vec->first).second.name, (*vec_2.first).second.name);
  EXPECT_EQ((*itr_vec->first).second.country, (*vec_2.first).second.country);
  EXPECT_EQ((*itr_vec->first).second.year, (*vec_2.first).second.year);

  EXPECT_EQ(map_1.Size(), 6);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End() && it_2 != orignal_map_1.end(); ++it) {
    EXPECT_EQ((*it).first.name, (*it_2).first.name);
    EXPECT_EQ((*it).first.country, (*it_2).first.country);
    EXPECT_EQ((*it).first.year, (*it_2).first.year);
    EXPECT_EQ((*it).second.name, (*it_2).second.name);
    EXPECT_EQ((*it).second.country, (*it_2).second.country);
    EXPECT_EQ((*it).second.year, (*it_2).second.year);
    ++it_2;
  }

  vec = map_1.Emplace(President("Kevin De Bruyne", "Manchester City", 2022),
                      President("Lionel Messi", "Paris Saint-Germain", 2021));
  vec_2 = orignal_map_1.emplace(
      President("Kevin De Bruyne", "Manchester City", 2022),
      President("Lionel Messi", "Paris Saint-Germain", 2021));

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, false);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).first.name, (*vec_2.first).first.name);
  EXPECT_EQ((*itr_vec->first).first.country, (*vec_2.first).first.country);
  EXPECT_EQ((*itr_vec->first).first.year, (*vec_2.first).first.year);
  EXPECT_EQ((*itr_vec->first).second.name, (*vec_2.first).second.name);
  EXPECT_EQ((*itr_vec->first).second.country, (*vec_2.first).second.country);
  EXPECT_EQ((*itr_vec->first).second.year, (*vec_2.first).second.year);

  EXPECT_EQ(map_1.Size(), 6);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End() && it_2 != orignal_map_1.end(); ++it) {
    EXPECT_EQ((*it).first.name, (*it_2).first.name);
    EXPECT_EQ((*it).first.country, (*it_2).first.country);
    EXPECT_EQ((*it).first.year, (*it_2).first.year);
    EXPECT_EQ((*it).second.name, (*it_2).second.name);
    EXPECT_EQ((*it).second.country, (*it_2).second.country);
    EXPECT_EQ((*it).second.year, (*it_2).second.year);
    ++it_2;
  }
}

TEST(map_test, test_swap) {
  s21::Map<int, char> map_1({{1, 'a'}, {3, 'b'}, {5, 'b'}});
  s21::Map<int, char> map_2({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  EXPECT_EQ(map_1.Size(), 3);
  EXPECT_EQ(map_2.Size(), 4);

  std::map<int, char> orignal_map_1({{1, 'a'}, {3, 'b'}, {5, 'b'}});
  std::map<int, char> orignal_map_2({{2, 'l'}, {4, 'o'}, {6, 'b'}, {8, 's'}});

  map_1.Swap(map_2);
  orignal_map_1.swap(orignal_map_2);

  EXPECT_EQ(map_1.Size(), 4);
  EXPECT_EQ(map_2.Size(), 3);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());
  EXPECT_EQ(map_2.Size(), orignal_map_2.size());

  auto it = map_1.Begin();
  auto it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }

  auto it_3 = map_2.Begin();
  auto it_4 = orignal_map_2.begin();
  for (; it_3 != map_2.End(); ++it_3) {
    EXPECT_DOUBLE_EQ((*it_3).first, (*it_4).first);
    EXPECT_EQ((*it_3).second, (*it_4).second);
    ++it_4;
  }
}

TEST(map_test, test_erase) {
  s21::Map<int, char> map_1;
  std::map<int, char> orignal_map_1;

  for (int i = 1; i < 21; i++) {
    map_1.Insert({i, 'a'});
    orignal_map_1.insert({i, 'a'});
  }
  EXPECT_EQ(map_1.Size(), 20);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Insert({25, 'b'}).first;
  auto it_2 = orignal_map_1.insert({25, 'b'}).first;
  EXPECT_EQ(map_1.Size(), 21);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  map_1.Erase(it);
  orignal_map_1.erase(it_2);
  EXPECT_EQ(map_1.Size(), 20);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
  EXPECT_EQ(map_1.IsBalanced(), true);
}

TEST(map_test, test_erase_01) {
  s21::Map<double, char> map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});
  std::map<double, char> orignal_map_1(
      {{1.1, 'a'}, {2.2, 'b'}, {3.3, 'c'}, {4.4, 'd'}, {5.5, 'e'}});

  EXPECT_EQ(map_1.Size(), 5);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Begin();
  map_1.Advance(it, 2);
  auto it_2 = orignal_map_1.begin();
  std::advance(it_2, 2);
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);

  map_1.Erase(it);
  orignal_map_1.erase(it_2);
  EXPECT_EQ(map_1.Size(), 4);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it_2;
  }
  EXPECT_EQ(map_1.IsBalanced(), true);
}

TEST(map_test, test_erase_03) {
  s21::Map<int, char> map_1;
  std::map<int, char> orignal_map_1;

  EXPECT_EQ(map_1.Size(), 0);
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  auto it = map_1.Begin();

  map_1.Erase(it);
  EXPECT_EQ(map_1.Size(), 0);

  EXPECT_EQ(map_1.IsBalanced(), true);
}

TEST(map_test, test_iter_end) {
  s21::Map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::Map<double, char>::iterator it = map_1.End();
  std::map<double, char>::iterator it_2 = orignal_map_1.end();
  --it;
  --it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_iter_end_empty) {
  s21::Map<double, char> map_1;

  s21::Map<double, char>::iterator it = map_1.End();
  --it;
  it = map_1.Begin();
  --it;
  it--;
  it = map_1.End();
  ++it;
  it++;
}

TEST(map_test, test_const_iter_end_empty) {
  s21::Map<double, char> map_1;

  s21::Map<double, char>::const_iterator it = map_1.Cend();

  ++it;
  it = map_1.Cbegin();
  --it;
  it--;
  it = map_1.Cend();
  ++it;
  it++;
}

TEST(map_test, test_const_iter_end_pref) {
  s21::Map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::Map<double, char>::const_iterator it = map_1.Cend();
  std::map<double, char>::const_iterator it_2 = orignal_map_1.end();
  --it;
  --it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
  --it;
  --it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_const_iter_begin_pref) {
  s21::Map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::Map<double, char>::const_iterator it = map_1.Cbegin();
  std::map<double, char>::const_iterator it_2 = orignal_map_1.cbegin();
  ++it;
  ++it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
  ++it;
  ++it_2;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_const_iter_end_post) {
  s21::Map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::Map<double, char>::const_iterator it = map_1.Cend();
  std::map<double, char>::const_iterator it_2 = orignal_map_1.end();
  it--;
  it_2--;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
  it--;
  it_2--;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_const_iter_begin_post) {
  s21::Map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::Map<double, char>::const_iterator it = map_1.Cbegin();
  std::map<double, char>::const_iterator it_2 = orignal_map_1.cbegin();
  it++;
  it_2++;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
  it++;
  it_2++;
  EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
  EXPECT_EQ((*it).second, (*it_2).second);
}

TEST(map_test, test_iter_plus) {
  s21::Map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::Map<double, char>::iterator it = map_1.Begin();
  std::map<double, char>::iterator it_2 = orignal_map_1.begin();
  for (; it != map_1.End() && it_2 != orignal_map_1.end();) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    ++it;
    ++it_2;
  }
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  for (; it != map_1.End() && it_2 != orignal_map_1.end();) {
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
    it++;
    it_2++;
  }
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());
}

TEST(map_test, test_iter_minus) {
  s21::Map<double, char> map_1({{1.1, 'a'},
                                {2.2, 'b'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'},
                                {3.3, 'c'},
                                {4.4, 'd'},
                                {5.5, 'e'}});
  std::map<double, char> orignal_map_1({{1.1, 'a'},
                                        {2.2, 'b'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'},
                                        {3.3, 'c'},
                                        {4.4, 'd'},
                                        {5.5, 'e'}});

  s21::Map<double, char>::iterator it = map_1.End();
  std::map<double, char>::iterator it_2 = orignal_map_1.end();
  for (; it != map_1.Begin() && it_2 != orignal_map_1.begin();) {
    --it;
    --it_2;
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
  }
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.End();
  it_2 = orignal_map_1.end();
  for (; it != map_1.Begin() && it_2 != orignal_map_1.begin();) {
    it--;
    it_2--;
    EXPECT_DOUBLE_EQ((*it).first, (*it_2).first);
    EXPECT_EQ((*it).second, (*it_2).second);
  }
  EXPECT_EQ(map_1.Size(), orignal_map_1.size());

  it = map_1.Begin();
  it_2 = orignal_map_1.begin();
  --it;
  --it_2;
  it--;
  it_2--;
  it = map_1.End();
  it_2 = orignal_map_1.end();
  ++it;
  ++it_2;
  it++;
  it_2++;
}
