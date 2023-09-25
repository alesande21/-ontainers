#include <set>
#include <string>

#include "../Includes/Containers/s21_multiset.h"
#include "gtest/gtest.h"

TEST(multiset_test, basic_constr) {
  s21::Multiset<int> tree_d;
  s21::Multiset<double> tree_i;
  s21::Multiset<char> tree_c;
  EXPECT_EQ(tree_d.Size(), 0);
  EXPECT_EQ(tree_i.Size(), 0);
  EXPECT_EQ(tree_c.Size(), 0);
}

TEST(multiset_test, constr_with_indefinite_number_of_elements) {
  s21::Multiset<double> multiset_1({1.1, 2.2, 3.3, 3.3, 4.4, 5.5, 1.1});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 3.3, 4.4, 5.5, 1.1});
  EXPECT_EQ(multiset_1.Size(), 7);
  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, constr_with_indefinite_number_of_elements_string) {
  s21::Multiset<char> multiset_1({'t', 'w', 't', 'r'});
  std::multiset<char> orignal_multiset_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(multiset_1.Size(), 4);
  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_constr) {
  s21::Multiset<char> multiset_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(multiset_1.Size(), 4);
  s21::Multiset<char> multiset_2(multiset_1);

  EXPECT_EQ(multiset_1.Size(), 4);
  EXPECT_EQ(multiset_2.Size(), 4);

  auto it = multiset_1.Begin();
  auto it_2 = multiset_2.Begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_constr_01) {
  s21::Multiset<char> multiset_1;
  EXPECT_EQ(multiset_1.Size(), 0);
  s21::Multiset<char> multiset_2(multiset_1);

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);

  auto it = multiset_1.Begin();
  auto it_2 = multiset_2.Begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_operator_01) {
  s21::Multiset<char> multiset_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(multiset_1.Size(), 4);
  s21::Multiset<char> multiset_2({'J', 'P', 'M', 'J', 'P', 'M'});
  EXPECT_EQ(multiset_2.Size(), 6);

  multiset_1 = multiset_2;
  EXPECT_EQ(multiset_1.Size(), 6);
  EXPECT_EQ(multiset_2.Size(), 6);
  auto it = multiset_1.Begin();
  auto it_2 = multiset_2.Begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_operator_02) {
  s21::Multiset<int> multiset_1({1, 2, 1});
  s21::Multiset<int> multiset_2;

  std::multiset<int> orignal_multiset_1({1, 2, 1});
  std::multiset<int> orignal_multiset_2;

  EXPECT_EQ(multiset_1.Size(), 3);

  multiset_1 = multiset_2;
  orignal_multiset_1 = orignal_multiset_2;
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);
}

TEST(multiset_test, copy_operator_06) {
  s21::Multiset<int> multiset_1({1, 2, 1});

  std::multiset<int> orignal_multiset_1({1, 2, 1});

  EXPECT_EQ(multiset_1.Size(), 3);

  multiset_1 = multiset_1;
  orignal_multiset_1 = orignal_multiset_1;

  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_1.Size(), 3);
  EXPECT_EQ(orignal_multiset_1.size(), 3);
}

TEST(multiset_test, copy_operator_05) {
  s21::Multiset<int> multiset_1;
  s21::Multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.Size(), 0);

  multiset_1 = multiset_2;
  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);
}

TEST(multiset_test, copy_operator_03) {
  s21::Multiset<int> multiset_1({1, 2, 2});
  s21::Multiset<int> multiset_2({11, 22, 33, 11});

  EXPECT_EQ(multiset_1.Size(), 3);
  EXPECT_EQ(multiset_2.Size(), 4);

  multiset_1 = multiset_2;
  EXPECT_EQ(multiset_1.Size(), 4);
  EXPECT_EQ(multiset_2.Size(), 4);

  auto it = multiset_1.Begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
  it = multiset_1.Begin();
  auto it_2 = multiset_2.Begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, copy_operator_04) {
  s21::Multiset<int> multiset_1({1, 2, 1});
  std::multiset<int> orignal_multiset_1({1, 2, 1});
  EXPECT_EQ(multiset_1.Size(), 3);

  multiset_1 = multiset_1;
  orignal_multiset_1 = orignal_multiset_1;
  EXPECT_EQ(multiset_1.Size(), 3);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
}

TEST(multiset_test, move_constr) {
  s21::Multiset<int> multiset_1({5, 3, 1, 2, 2, 5});
  EXPECT_EQ(multiset_1.Size(), 6);
  s21::Multiset<int> multiset_2(std::move(multiset_1));

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 6);

  std::multiset<int> orignal_multiset_1({5, 3, 1, 2, 2, 5});

  auto it = multiset_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);
  ++it;
  EXPECT_EQ(*it, 5);

  it = multiset_2.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_2.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, constr_move_to_yourself) {
  s21::Multiset<char> multiset_1(std::move(multiset_1));
  EXPECT_EQ(multiset_1.Size(), 0);
}

TEST(multiset_test, move_operator) {
  s21::Multiset<int> multiset_1({1, 2, 2});
  EXPECT_EQ(multiset_1.Size(), 3);
  s21::Multiset<int> multiset_2({11, 22, 33, 11});
  EXPECT_EQ(multiset_2.Size(), 4);

  multiset_1 = std::move(multiset_2);

  EXPECT_EQ(multiset_1.Size(), 4);
  EXPECT_EQ(multiset_2.Size(), 0);

  auto it = multiset_1.Begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
}

TEST(multiset_test, move_operator_05) {
  s21::Multiset<int> multiset_1({5, 3, 1, 2, 2, 2});
  s21::Multiset<int> multiset_2({11, 22, 33, 11});

  EXPECT_EQ(multiset_1.Size(), 6);
  EXPECT_EQ(multiset_2.Size(), 4);

  std::multiset<int> orignal_multiset_1({5, 3, 1, 2, 2, 2});
  std::multiset<int> orignal_multiset_2({11, 22, 33, 11});

  multiset_2 = std::move(multiset_1);
  orignal_multiset_2 = std::move(orignal_multiset_1);

  s21::Multiset<int>::iterator it = multiset_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);

  it = multiset_2.Begin();
  auto it_2 = orignal_multiset_2.begin();
  for (; it != multiset_2.End() && it_2 != orignal_multiset_2.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }

  EXPECT_EQ(multiset_2.Size(), orignal_multiset_2.size());
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
}

TEST(multiset_test, move_operator_02) {
  s21::Multiset<int> multiset_1({1, 2, 1});
  EXPECT_EQ(multiset_1.Size(), 3);
  s21::Multiset<int> multiset_2({11, 22, 33, 11});
  EXPECT_EQ(multiset_2.Size(), 4);

  multiset_2 = std::move(multiset_1);

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 3);

  auto it = multiset_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(multiset_test, move_operator_to_yourself) {
  s21::Multiset<int> multiset_1({1, 2, 1});
  std::multiset<int> orignal_multiset_1({1, 2, 1});
  EXPECT_EQ(multiset_1.Size(), 3);

  multiset_1 = std::move(multiset_1);

  orignal_multiset_1 = std::move(orignal_multiset_1);

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(orignal_multiset_1.size(), 0);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
}

TEST(multiset_test, move_operator_03) {
  s21::Multiset<int> multiset_1;
  EXPECT_EQ(multiset_1.Size(), 0);
  s21::Multiset<int> multiset_2;
  EXPECT_EQ(multiset_2.Size(), 0);

  multiset_2 = std::move(multiset_1);

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);
}

TEST(multiset_test, move_operator_04) {
  s21::Multiset<int> multiset_1({1, 2});
  EXPECT_EQ(multiset_1.Size(), 2);
  s21::Multiset<int> multiset_2;
  EXPECT_EQ(multiset_2.Size(), 0);

  multiset_1 = std::move(multiset_2);

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);
}

TEST(multiset_test, test_empty) {
  s21::Multiset<int> multiset_1({2, 4, 6, 8});
  s21::Multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.Empty(), false);
  EXPECT_EQ(multiset_2.Empty(), true);
}

TEST(multiset_test, test_size) {
  s21::Multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 5.5});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 5.5});
  EXPECT_EQ(multiset_1.Size(), 7);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
}

TEST(multiset_test, test_max_size) {
  s21::Multiset<double> multiset_1;
  std::multiset<double> orignal_multiset_1;
  EXPECT_EQ(multiset_1.MaxSize(), orignal_multiset_1.max_size());
}

TEST(multiset_test, test_clear) {
  s21::Multiset<int> multiset_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  s21::Multiset<int> multiset_2({1});
  s21::Multiset<int> multiset_3;
  EXPECT_EQ(multiset_1.Size(), 12);
  EXPECT_EQ(multiset_2.Size(), 1);
  EXPECT_EQ(multiset_3.Size(), 0);

  multiset_1.Clear();
  multiset_2.Clear();
  multiset_3.Clear();

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);
  EXPECT_EQ(multiset_3.Size(), 0);
}

TEST(multiset_test, test_insert) {
  s21::Multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  EXPECT_EQ(multiset_1.Size(), 7);

  auto res_test_1 = multiset_1.Insert(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 3.2);

  auto res_orignal_multiset_1 = orignal_multiset_1.insert(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), res_orignal_multiset_1.operator*());

  EXPECT_EQ(multiset_1.Size(), 8);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_insert_02) {
  s21::Multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  EXPECT_EQ(multiset_1.Size(), 7);

  auto res_test_1 = multiset_1.Insert(3.3);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 3.3);

  auto res_orignal_multiset_1 = orignal_multiset_1.insert(3.3);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), res_orignal_multiset_1.operator*());

  EXPECT_EQ(multiset_1.Size(), 8);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_insert_03) {
  s21::Multiset<double> multiset_1;
  std::multiset<double> orignal_multiset_1;
  EXPECT_EQ(multiset_1.Size(), 0);

  auto res_test_1 = multiset_1.Insert(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 3.2);

  auto res_orignal_multiset_1 = orignal_multiset_1.insert(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), res_orignal_multiset_1.operator*());

  EXPECT_EQ(multiset_1.Size(), 1);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_erase) {
  s21::Multiset<int> multiset_1(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 1, 4, 5, 9, 9, 2, 3});
  std::multiset<int> orignal_multiset_1(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 1, 4, 5, 9, 9, 2, 3});

  EXPECT_EQ(multiset_1.Size(), 20);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Insert(9);
  auto it_2 = orignal_multiset_1.insert(9);
  EXPECT_EQ(multiset_1.Size(), 21);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  multiset_1.Erase(it);
  orignal_multiset_1.erase(it_2);
  EXPECT_EQ(multiset_1.Size(), 20);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(multiset_1.IsBalanced(), true);
}

TEST(multiset_test, test_erase_01) {
  s21::Multiset<int> multiset_1(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 1, 4, 5, 9, 9, 2, 3});
  std::multiset<int> orignal_multiset_1(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 1, 4, 5, 9, 9, 2, 3});

  EXPECT_EQ(multiset_1.Size(), 20);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();
  multiset_1.Advance(it, 5);
  auto it_2 = orignal_multiset_1.begin();
  std::advance(it_2, 5);
  EXPECT_DOUBLE_EQ(*it, *it_2);

  multiset_1.Erase(it);
  orignal_multiset_1.erase(it_2);
  EXPECT_EQ(multiset_1.Size(), 19);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(multiset_1.IsBalanced(), true);

  it = multiset_1.Begin();
  multiset_1.Advance(it, 6);
  it_2 = orignal_multiset_1.begin();
  std::advance(it_2, 6);
  EXPECT_DOUBLE_EQ(*it, *it_2);

  multiset_1.Erase(it);
  orignal_multiset_1.erase(it_2);
  EXPECT_EQ(multiset_1.Size(), 18);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(multiset_1.IsBalanced(), true);
}

TEST(multiset_test, test_erase_03) {
  s21::Multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();

  multiset_1.Erase(it);
  EXPECT_EQ(multiset_1.Size(), 0);

  EXPECT_EQ(multiset_1.IsBalanced(), true);
}

TEST(multiset_test, test_swap) {
  s21::Multiset<int> multiset_1({1, 3, 5});
  s21::Multiset<int> multiset_2({2, 4, 6, 8});

  EXPECT_EQ(multiset_1.Size(), 3);
  EXPECT_EQ(multiset_2.Size(), 4);

  std::multiset<int> orignal_multiset_1({1, 3, 5});
  std::multiset<int> orignal_multiset_2({2, 4, 6, 8});

  multiset_1.Swap(multiset_2);
  orignal_multiset_1.swap(orignal_multiset_2);

  EXPECT_EQ(multiset_1.Size(), 4);
  EXPECT_EQ(multiset_2.Size(), 3);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_2.Size(), orignal_multiset_2.size());

  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it), (*it_2));
    ++it_2;
  }

  auto it_3 = multiset_2.Begin();
  auto it_4 = orignal_multiset_2.begin();
  for (; it_3 != multiset_2.End(); ++it_3) {
    EXPECT_DOUBLE_EQ((*it_3), (*it_4));
    ++it_4;
  }
}

TEST(multiset_test, test_swap_yourself) {
  s21::Multiset<int> set_1({1, 3, 5});

  EXPECT_EQ(set_1.Size(), 3);

  std::multiset<int> orignal_multiset_1({1, 3, 5});

  set_1.Swap(set_1);
  orignal_multiset_1.swap(orignal_multiset_1);

  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_1.Size(), orignal_multiset_1.size());

  s21::Multiset<int>::iterator it = set_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it), (*it_2));
    ++it_2;
  }
}

TEST(multiset_test, test_merge) {
  s21::Multiset<int> multiset_1({1, 3, 5, 5, 1});
  s21::Multiset<int> multiset_2({2, 4, 6, 8, 4, 2});

  EXPECT_EQ(multiset_1.Size(), 5);
  EXPECT_EQ(multiset_2.Size(), 6);

  std::multiset<int> orignal_multiset_1({1, 3, 5, 5, 1, 2, 4, 6, 8, 4, 2});
  //  std::multiset<int> orignal_multiset_1({1, 3, 5});
  //  std::multiset<int> orignal_multiset_2({2, 4, 6, 8});
  //  std::merge(orignal_multiset_2.begin(), orignal_multiset_2.end(),
  //  orignal_multiset_1);

  multiset_1.Merge(multiset_2);

  EXPECT_EQ(multiset_1.Size(), 11);
  EXPECT_EQ(multiset_2.Size(), 0);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_02) {
  s21::Multiset<int> multiset_1({2, 4, 6, 8, 4, 2});
  s21::Multiset<int> multiset_2({1, 3, 5, 5, 1});

  EXPECT_EQ(multiset_1.Size(), 6);
  EXPECT_EQ(multiset_2.Size(), 5);

  std::multiset<int> orignal_multiset_1({1, 3, 5, 5, 1, 2, 4, 6, 8, 4, 2});

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.Merge(multiset_2);

  EXPECT_EQ(multiset_1.Size(), 11);
  EXPECT_EQ(multiset_2.Size(), 0);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_03) {
  s21::Multiset<int> multiset_1;
  s21::Multiset<int> multiset_2({1, 3, 5, 5, 1});

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 5);

  std::multiset<int> orignal_multiset_1({1, 3, 5, 5, 1});

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.Merge(multiset_2);

  EXPECT_EQ(multiset_1.Size(), 5);
  EXPECT_EQ(multiset_2.Size(), 0);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_04) {
  s21::Multiset<int> multiset_1({2, 4, 6, 8, 4, 2});
  s21::Multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.Size(), 6);
  EXPECT_EQ(multiset_2.Size(), 0);

  std::multiset<int> orignal_multiset_1({2, 4, 6, 8, 4, 2});

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.Merge(multiset_2);

  EXPECT_EQ(multiset_1.Size(), 6);
  EXPECT_EQ(multiset_2.Size(), 0);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_05) {
  s21::Multiset<int> multiset_1;
  s21::Multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);

  std::multiset<int> orignal_multiset_1;

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.Merge(multiset_2);

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_merge_06) {
  s21::Multiset<int> multiset_1;
  s21::Multiset<int> multiset_2;

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);

  std::multiset<int> orignal_multiset_1;

  //  EXPECT_EQ(orignal_multiset_1.size(), 3);
  //  EXPECT_EQ(orignal_multiset_2.size(), 4);

  multiset_1.Merge(multiset_1);
  multiset_2.Merge(multiset_2);

  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_2.Size(), 0);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_contains) {
  s21::Multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 3.3});
  s21::Multiset<double> multiset_2;
  EXPECT_EQ(multiset_1.Size(), 6);

  auto res_test_1 = multiset_1.Contains(3.3);
  EXPECT_EQ(res_test_1, true);
  res_test_1 = multiset_1.Contains(3.2);
  EXPECT_EQ(res_test_1, false);
  auto res_test_2 = multiset_2.Contains(3.3);
  EXPECT_EQ(res_test_2, false);
}

TEST(multiset_test, test_find) {
  s21::Multiset<double> multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 4.4, 1.1});
  std::multiset<double> orignal_multiset_1({1.1, 2.2, 3.3, 4.4, 5.5, 4.4, 1.1});
  EXPECT_EQ(multiset_1.Size(), 7);

  auto res_test_1 = multiset_1.Find(4.4);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 4.4);
  auto orig_test_1 = orignal_multiset_1.find(4.4);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.Find(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 0);
}

TEST(multiset_test, test_find_02) {
  s21::Multiset<double> multiset_1;
  EXPECT_EQ(multiset_1.Size(), 0);

  auto res_test_1 = multiset_1.Find(4.4);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 0);
}

TEST(multiset_test, test_count) {
  s21::Multiset<int> multiset_1({1, 1, 3, 4, 5, 6, 7, 8, 4, 10, 4, 12});
  std::multiset<int> orignal_multiset_1({1, 1, 3, 4, 5, 6, 7, 8, 4, 10, 4, 12});
  EXPECT_EQ(multiset_1.Size(), 12);

  auto res_test_1 = multiset_1.Count(4);
  EXPECT_EQ(res_test_1, 3);
  auto orig_test_1 = orignal_multiset_1.count(4);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.Count(1);
  EXPECT_EQ(res_test_1, 2);
  orig_test_1 = orignal_multiset_1.count(1);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.Count(50);
  EXPECT_EQ(res_test_1, 0);
  orig_test_1 = orignal_multiset_1.count(50);
  EXPECT_EQ(res_test_1, orig_test_1);
}

TEST(multiset_test, test_count_02) {
  s21::Multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;
  EXPECT_EQ(multiset_1.Size(), 0);

  auto res_test_1 = multiset_1.Count(4);
  EXPECT_EQ(res_test_1, 0);
  auto orig_test_1 = orignal_multiset_1.count(4);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.Count(1);
  EXPECT_EQ(res_test_1, 0);
  orig_test_1 = orignal_multiset_1.count(1);
  EXPECT_EQ(res_test_1, orig_test_1);

  res_test_1 = multiset_1.Count(0);
  EXPECT_EQ(res_test_1, 0);
  orig_test_1 = orignal_multiset_1.count(0);
  EXPECT_EQ(res_test_1, orig_test_1);
}

TEST(multiset_test, test_equal_range) {
  s21::Multiset<int> multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  std::multiset<int> orignal_multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  EXPECT_EQ(multiset_1.Size(), 8);

  auto res_test_1 = multiset_1.EqualRange(4);
  EXPECT_EQ(res_test_1.first.operator*(), 5);
  EXPECT_EQ(res_test_1.second.operator*(), 5);
  auto orig_test_1 = orignal_multiset_1.equal_range(4);
  EXPECT_EQ(res_test_1.first.operator*(), orig_test_1.first.operator*());
  EXPECT_EQ(res_test_1.second.operator*(), orig_test_1.second.operator*());

  res_test_1 = multiset_1.EqualRange(11);
  EXPECT_EQ(res_test_1.first.operator*(), 11);
  EXPECT_EQ(res_test_1.second.operator*(), 15);
  orig_test_1 = orignal_multiset_1.equal_range(11);
  EXPECT_EQ(res_test_1.first.operator*(), orig_test_1.first.operator*());
  EXPECT_EQ(res_test_1.second.operator*(), orig_test_1.second.operator*());

  res_test_1 = multiset_1.EqualRange(15);
  EXPECT_EQ(res_test_1.first.operator*(), 15);
  EXPECT_EQ(res_test_1.second.operator*(), 0);
  orig_test_1 = orignal_multiset_1.equal_range(15);
  EXPECT_EQ(res_test_1.first.operator*(), orig_test_1.first.operator*());
  //    EXPECT_EQ(res_test_1.second.operator*(),
  //    orig_test_1.second.operator*());

  res_test_1 = multiset_1.EqualRange(100);
  EXPECT_EQ(res_test_1.first.operator*(), 0);
  EXPECT_EQ(res_test_1.second.operator*(), 0);
  //    orig_test_1 = orignal_multiset_1.equal_range(100);
  //    EXPECT_EQ(res_test_1.first.operator*(), orig_test_1.first.operator*());
  //    EXPECT_EQ(res_test_1.second.operator*(),
  //    orig_test_1.second.operator*());
}

TEST(multiset_test, test_lower_bound) {
  s21::Multiset<int> multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  std::multiset<int> orignal_multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  EXPECT_EQ(multiset_1.Size(), 8);

  auto res_test_1 = multiset_1.LowerBound(4);
  EXPECT_EQ(res_test_1.operator*(), 5);
  auto orig_test_1 = orignal_multiset_1.lower_bound(4);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.LowerBound(11);
  EXPECT_EQ(res_test_1.operator*(), 11);
  orig_test_1 = orignal_multiset_1.lower_bound(11);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.LowerBound(16);
  EXPECT_EQ(res_test_1.operator*(), 0);
  //    orig_test_1 = orignal_multiset_1.lower_bound(16);
  //    EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());
}

TEST(multiset_test, test_lower_bound_02) {
  s21::Multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;
  EXPECT_EQ(multiset_1.Size(), 0);

  auto res_test_1 = multiset_1.LowerBound(4);
  EXPECT_EQ(res_test_1.operator*(), 0);
  auto orig_test_1 = orignal_multiset_1.lower_bound(4);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.LowerBound(11);
  EXPECT_EQ(res_test_1.operator*(), 0);
  orig_test_1 = orignal_multiset_1.lower_bound(11);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.LowerBound(16);
  EXPECT_EQ(res_test_1.operator*(), 0);
  orig_test_1 = orignal_multiset_1.lower_bound(16);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());
}

TEST(multiset_test, test_upper_bound) {
  s21::Multiset<int> multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  std::multiset<int> orignal_multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  EXPECT_EQ(multiset_1.Size(), 8);

  auto res_test_1 = multiset_1.UpperBound(4);
  EXPECT_EQ(res_test_1.operator*(), 5);
  auto orig_test_1 = orignal_multiset_1.upper_bound(4);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.UpperBound(11);
  EXPECT_EQ(res_test_1.operator*(), 15);
  orig_test_1 = orignal_multiset_1.upper_bound(11);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.UpperBound(15);
  EXPECT_EQ(res_test_1.operator*(), 0);
  //    orig_test_1 = orignal_multiset_1.upper_bound(15);
  //    EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());
}

TEST(multiset_test, test_upper_bound_02) {
  s21::Multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;
  EXPECT_EQ(multiset_1.Size(), 0);

  auto res_test_1 = multiset_1.UpperBound(4);
  EXPECT_EQ(res_test_1.operator*(), 0);
  auto orig_test_1 = orignal_multiset_1.upper_bound(4);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.UpperBound(11);
  EXPECT_EQ(res_test_1.operator*(), 0);
  orig_test_1 = orignal_multiset_1.upper_bound(11);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());

  res_test_1 = multiset_1.UpperBound(16);
  EXPECT_EQ(res_test_1.operator*(), 0);
  orig_test_1 = orignal_multiset_1.upper_bound(16);
  EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());
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
  bool operator<=(const President& other) const { return year <= other.year; }
};

TEST(multiset_test, test_emplace) {
  s21::Multiset<President> multiset_1;
  std::multiset<President> orignal_multiset_1;
  EXPECT_EQ(multiset_1.Size(), 0);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  multiset_1.Emplace("Nelson Mandela", "South Africa", 1994);
  orignal_multiset_1.emplace("Nelson Mandela", "South Africa", 1994);

  EXPECT_EQ(multiset_1.Size(), 1);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  s21::Multiset<President> list_2;
  std::multiset<President> orignal_list_2;
  EXPECT_EQ(list_2.Size(), 0);
  EXPECT_EQ(list_2.Size(), orignal_list_2.size());

  list_2.Emplace(President("Franklin Delano Roosevelt", "the USA", 1936));
  orignal_list_2.emplace(
      President("Franklin Delano Roosevelt", "the USA", 1936));

  EXPECT_EQ(list_2.Size(), 1);
  EXPECT_EQ(list_2.Size(), orignal_list_2.size());

  auto it_re = list_2.Begin();
  auto it_re_2 = orignal_list_2.begin();
  for (; it_re != list_2.End() && it_re_2 != orignal_list_2.end(); ++it_re) {
    EXPECT_EQ((*it_re).name, (*it_re_2).name);
    EXPECT_EQ((*it_re).country, (*it_re_2).country);
    EXPECT_EQ((*it_re).year, (*it_re_2).year);
    ++it_re_2;
  }

  // front

  EXPECT_EQ(multiset_1.Size(), 1);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  multiset_1.Emplace("Lionel Messi", "Barcelona", 2010);
  orignal_multiset_1.emplace("Lionel Messi", "Barcelona", 2010);

  EXPECT_EQ(multiset_1.Size(), 2);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  EXPECT_EQ(multiset_1.Size(), 2);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  multiset_1.Emplace("Franklin Delano Roosevelt", "the USA", 1936);
  orignal_multiset_1.emplace("Franklin Delano Roosevelt", "the USA", 1936);

  EXPECT_EQ(multiset_1.Size(), 3);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End() && it_2 != orignal_multiset_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  EXPECT_EQ(multiset_1.Size(), 3);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  ++it;
  ++it_2;

  auto vec = multiset_1.Emplace("Cristiano Ronaldo", "Real Madrid", 2016);
  auto vec_2 =
      orignal_multiset_1.emplace("Cristiano Ronaldo", "Real Madrid", 2016);

  auto itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2).year);

  EXPECT_EQ(multiset_1.Size(), 4);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End() && it_2 != orignal_multiset_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = multiset_1.Emplace("Cristiano", "Real", 2016);
  vec_2 = orignal_multiset_1.emplace("Cristiano", "Real", 2016);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2).year);

  EXPECT_EQ(multiset_1.Size(), 5);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End() && it_2 != orignal_multiset_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = multiset_1.Emplace("Luka Modrić", "Real Madrid", 2018);
  vec_2 = orignal_multiset_1.emplace("Luka Modrić", "Real Madrid", 2018);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2).year);

  EXPECT_EQ(multiset_1.Size(), 6);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End() && it_2 != orignal_multiset_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = multiset_1.Emplace("Karim Benzema", "Real Madrid", 2022);
  vec_2 = orignal_multiset_1.emplace("Karim Benzema", "Real Madrid", 2022);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2).year);

  EXPECT_EQ(multiset_1.Size(), 7);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End() && it_2 != orignal_multiset_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = multiset_1.Emplace("Kevin De Bruyne", "Manchester City", 2022);
  vec_2 =
      orignal_multiset_1.emplace("Kevin De Bruyne", "Manchester City", 2022);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2).year);

  EXPECT_EQ(multiset_1.Size(), 8);
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End() && it_2 != orignal_multiset_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }
}

/*
 *  other test
 */
TEST(multiset_test, test_medium_del) {
  s21::Multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;

  for (int i = 100; i < 200; i++) {
    multiset_1.Insert(i);
    orignal_multiset_1.insert(i);
  }
  EXPECT_EQ(multiset_1.IsBalanced(), true);
  for (int i = 160; i > 40; i--) {
    multiset_1.Insert(i);
    orignal_multiset_1.insert(i);
  }
  EXPECT_EQ(multiset_1.IsBalanced(), true);
  for (int i = 80; i > 0; i--) {
    multiset_1.Insert(i);
    orignal_multiset_1.insert(i);
  }
  EXPECT_EQ(multiset_1.IsBalanced(), true);
  for (int i = 150; i < 300; i++) {
    multiset_1.Insert(i);
    orignal_multiset_1.insert(i);
  }
  EXPECT_EQ(multiset_1.IsBalanced(), true);
  for (int i = 41; i < 200; i++) {
    multiset_1.Insert(i);
    orignal_multiset_1.insert(i);
  }
  EXPECT_EQ(multiset_1.IsBalanced(), true);
  for (int i = 300; i > 81; i--) {
    multiset_1.Insert(i);
    orignal_multiset_1.insert(i);
  }
  EXPECT_EQ(multiset_1.IsBalanced(), true);
  for (int i = 221; i < 300; i++) {
    multiset_1.Insert(i);
    orignal_multiset_1.insert(i);
  }
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_1.IsBalanced(), true);
  auto it = multiset_1.Begin();
  auto it_2 = orignal_multiset_1.begin();
  for (int i = 200; i > 50; --i) {
    it = multiset_1.Find(i);
    it_2 = orignal_multiset_1.find(i);
    multiset_1.Erase(it);
    orignal_multiset_1.erase(it_2);
  }
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_1.IsBalanced(), true);
  for (int i = 2; i < 50; ++i) {
    it = multiset_1.Find(i);
    it_2 = orignal_multiset_1.find(i);
    multiset_1.Erase(it);
    orignal_multiset_1.erase(it_2);
  }
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_1.IsBalanced(), true);
  for (int i = 250; i > 50; --i) {
    it = multiset_1.Find(i);
    it_2 = orignal_multiset_1.find(i);
    multiset_1.Erase(it);
    orignal_multiset_1.erase(it_2);
  }
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
  EXPECT_EQ(multiset_1.IsBalanced(), true);

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(multiset_test, test_const_iter) {
  s21::Multiset<int> multiset_1({50, 20, 75, 10, 11});
  std::multiset<int> orignal_multiset_1({50, 20, 75, 10, 11});

  s21::Multiset<int>::const_iterator it = multiset_1.Cbegin();
  std::multiset<int>::const_iterator it_2 = orignal_multiset_1.cbegin();
  EXPECT_EQ(*it, *it_2);
}

TEST(multiset_test, test_const_iter_empty) {
  s21::Multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;

  s21::Multiset<int>::const_iterator it = multiset_1.Cbegin();
  std::multiset<int>::const_iterator it_2 = orignal_multiset_1.cbegin();
  EXPECT_EQ(*it, *it_2);
}

TEST(multiset_test, test_iter_end) {
  s21::Multiset<int> multiset_1({50, 20, 75, 10, 11});
  std::multiset<int> orignal_multiset_1({50, 20, 75, 10, 11});

  s21::Multiset<int>::iterator it = multiset_1.End();
  std::multiset<int>::iterator it_2 = orignal_multiset_1.end();
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(multiset_test, test_iter_end_empty) {
  s21::Multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;

  s21::Multiset<int>::iterator it = multiset_1.End();
  std::multiset<int>::iterator it_2 = orignal_multiset_1.end();
  EXPECT_EQ(*it, *it_2);

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  --it;
  it--;
  it = multiset_1.End();
  ++it;
  it++;
}

TEST(multiset_test, test_const_iter_end_empty) {
  s21::Multiset<int> multiset_1;
  std::multiset<int> orignal_multiset_1;

  s21::Multiset<int>::const_iterator it = multiset_1.Cend();
  std::multiset<int>::const_iterator it_2 = orignal_multiset_1.cend();
  EXPECT_EQ(*it, *it_2);

  it = multiset_1.Cbegin();
  --it;
  it--;
  it = multiset_1.Cend();
  ++it;
  it++;
}

TEST(multiset_test, test_const_iter_end_pref) {
  s21::Multiset<int> multiset_1({50, 20, 75, 10, 11});
  std::multiset<int> orignal_multiset_1({50, 20, 75, 10, 11});

  s21::Multiset<int>::const_iterator it = multiset_1.Cend();
  std::multiset<int>::const_iterator it_2 = orignal_multiset_1.end();
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(multiset_test, test_const_iter_begin_pref) {
  s21::Multiset<int> multiset_1({50, 20, 75, 10, 11});
  std::multiset<int> orignal_multiset_1({50, 20, 75, 10, 11});

  s21::Multiset<int>::const_iterator it = multiset_1.Cbegin();
  std::multiset<int>::const_iterator it_2 = orignal_multiset_1.cbegin();
  ++it;
  ++it_2;
  EXPECT_EQ(*it, *it_2);
  ++it;
  ++it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(multiset_test, test_const_iter_end_post) {
  s21::Multiset<int> multiset_1({50, 20, 75, 10, 11});
  std::multiset<int> orignal_multiset_1({50, 20, 75, 10, 11});

  s21::Multiset<int>::const_iterator it = multiset_1.Cend();
  std::multiset<int>::const_iterator it_2 = orignal_multiset_1.end();
  it--;
  it_2--;
  EXPECT_EQ(*it, *it_2);
  it--;
  it_2--;
  EXPECT_EQ(*it, *it_2);
}

TEST(multiset_test, test_const_iter_begin_post) {
  s21::Multiset<int> multiset_1({50, 20, 75, 10, 11});
  std::multiset<int> orignal_multiset_1({50, 20, 75, 10, 11});

  s21::Multiset<int>::const_iterator it = multiset_1.Cbegin();
  std::multiset<int>::const_iterator it_2 = orignal_multiset_1.cbegin();
  it++;
  it_2++;
  EXPECT_EQ(*it, *it_2);
  it++;
  it_2++;
  EXPECT_EQ(*it, *it_2);
}

TEST(multiset_test, test_iter_plus) {
  s21::Multiset<int> multiset_1({50, 20, 75, 10, 11});
  std::multiset<int> orignal_multiset_1({50, 20, 75, 10, 11});

  s21::Multiset<int>::iterator it = multiset_1.Begin();
  std::multiset<int>::iterator it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End() && it_2 != orignal_multiset_1.end();) {
    EXPECT_EQ(*it, *it_2);
    ++it;
    ++it_2;
  }
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  for (; it != multiset_1.End() && it_2 != orignal_multiset_1.end();) {
    EXPECT_EQ(*it, *it_2);
    it++;
    it_2++;
  }
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());
}

TEST(multiset_test, test_iter_minus) {
  s21::Multiset<int> multiset_1({50, 20, 75, 10, 11});
  std::multiset<int> orignal_multiset_1({50, 20, 75, 10, 11});

  s21::Multiset<int>::iterator it = multiset_1.End();
  std::multiset<int>::iterator it_2 = orignal_multiset_1.end();
  for (; it != multiset_1.Begin() && it_2 != orignal_multiset_1.begin();) {
    --it;
    --it_2;
    EXPECT_EQ(*it, *it_2);
  }
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.End();
  it_2 = orignal_multiset_1.end();
  for (; it != multiset_1.Begin() && it_2 != orignal_multiset_1.begin();) {
    it--;
    it_2--;
    EXPECT_EQ(*it, *it_2);
  }
  EXPECT_EQ(multiset_1.Size(), orignal_multiset_1.size());

  it = multiset_1.Begin();
  it_2 = orignal_multiset_1.begin();
  --it;
  --it_2;
  it--;
  it_2--;
  it = multiset_1.End();
  it_2 = orignal_multiset_1.end();
  ++it;
  ++it_2;
  it++;
  it_2++;
}
