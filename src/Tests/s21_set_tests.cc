#include <string>

#include "../Includes/Containers/s21_set.h"
#include "gtest/gtest.h"

TEST(set_test, basic_constr) {
  s21::Set<int> tree_d;
  s21::Set<double> tree_i;
  s21::Set<char> tree_c;
  EXPECT_EQ(tree_d.Size(), 0);
  EXPECT_EQ(tree_i.Size(), 0);
  EXPECT_EQ(tree_c.Size(), 0);
}

TEST(set_test, constr_with_indefinite_number_of_elements) {
  s21::Set<double> set_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1});
  EXPECT_EQ(set_1.Size(), 5);
  auto it = set_1.Begin();
  double res = 1.1;
  for (; it != set_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, res);
    res = res + 1.1;
  }
  it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, constr_with_indefinite_number_of_elements_string) {
  s21::Set<char> set_1({'t', 'w', 't', 'r'});
  std::set<char> orignal_set_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(set_1.Size(), 3);

  auto it = set_1.Begin();
  EXPECT_EQ(*it, 'r');
  ++it;
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'w');

  it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

// TEST(set_test, constr_copy_to_yourself) {
//   s21::Set<char> set_1(set_1);
//   std::set<char> orignal_set_1(orignal_set_1);
//   EXPECT_EQ(set_1.Size(), orignal_set_1.size());

//   auto it = set_1.Begin();
//   auto it_2 = orignal_set_1.begin();
//   for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
//     EXPECT_EQ(*it, *it_2);
//     ++it_2;
//   }
// }

TEST(set_test, copy_constr) {
  s21::Set<char> set_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(set_1.Size(), 3);
  s21::Set<char> set_2(set_1);

  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_2.Size(), 3);

  auto it = set_1.Begin();
  auto it_2 = set_2.Begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, copy_operator_01) {
  s21::Set<char> set_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(set_1.Size(), 3);
  s21::Set<char> set_2({'J', 'P', 'M', 'J', 'P', 'M'});
  EXPECT_EQ(set_2.Size(), 3);

  set_1 = set_2;
  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_2.Size(), 3);
  auto it = set_1.Begin();
  auto it_2 = set_2.Begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, copy_operator_02) {
  s21::Set<int> set_1({1, 2, 1});
  s21::Set<int> set_2;

  std::set<int> orignal_set_1({1, 2, 1});
  std::set<int> orignal_set_2;

  EXPECT_EQ(set_1.Size(), 2);

  set_1 = set_2;
  orignal_set_1 = orignal_set_2;
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());
  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);
}

TEST(set_test, copy_operator_06) {
  s21::Set<int> set_1({1, 2, 1});

  std::set<int> orignal_set_1({1, 2, 1});

  EXPECT_EQ(set_1.Size(), 2);

  set_1 = set_1;
  orignal_set_1 = orignal_set_1;

  EXPECT_EQ(set_1.Size(), orignal_set_1.size());
  EXPECT_EQ(set_1.Size(), 2);
  EXPECT_EQ(orignal_set_1.size(), 2);
}

TEST(set_test, copy_operator_05) {
  s21::Set<int> set_1;
  s21::Set<int> set_2;

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);

  set_1 = set_2;
  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);
}

TEST(set_test, copy_operator_03) {
  s21::Set<int> set_1({1, 2, 1});
  s21::Set<int> set_2({11, 22, 33, 22});

  EXPECT_EQ(set_1.Size(), 2);
  EXPECT_EQ(set_2.Size(), 3);

  set_1 = set_2;
  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_2.Size(), 3);

  auto it = set_1.Begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
  it = set_1.Begin();
  auto it_2 = set_2.Begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, copy_operator_04) {  // NEW
  s21::Set<int> set_1({1, 2, 1});
  std::set<int> orignal_set_1({1, 2, 1});

  EXPECT_EQ(set_1.Size(), 2);

  set_1 = set_1;
  orignal_set_1 = orignal_set_1;
  EXPECT_EQ(set_1.Size(), 2);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());
}

TEST(set_test, move_constr) {
  s21::Set<int> set_1({5, 3, 1, 2, 2, 2});
  EXPECT_EQ(set_1.Size(), 4);
  s21::Set<int> set_2(std::move(set_1));

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 4);

  std::set<int> orignal_set_1({5, 3, 1, 2});
  std::set<int> orignal_set_2(std::move(orignal_set_1));

  s21::Set<int>::iterator it = set_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);

  it = set_2.Begin();
  auto it_2 = orignal_set_2.begin();
  for (; it != set_2.End() && it_2 != orignal_set_2.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }

  EXPECT_EQ(set_2.Size(), orignal_set_2.size());
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());
}

TEST(set_test, constr_move_to_yourself) {
  s21::Set<char> set_1(std::move(set_1));
  EXPECT_EQ(set_1.Size(), 0);
}

TEST(set_test, move_operator) {
  s21::Set<int> set_1({1, 2, 2});
  EXPECT_EQ(set_1.Size(), 2);
  s21::Set<int> set_2({11, 22, 33, 33});
  EXPECT_EQ(set_2.Size(), 3);

  set_1 = std::move(set_2);

  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_2.Size(), 0);

  auto it = set_1.Begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
}

TEST(set_test, move_operator_05) {
  s21::Set<int> set_1({5, 3, 1, 2, 2, 2});
  s21::Set<int> set_2({11, 22, 33, 11});

  EXPECT_EQ(set_1.Size(), 4);
  EXPECT_EQ(set_2.Size(), 3);

  std::set<int> orignal_set_1({5, 3, 1, 2});
  std::set<int> orignal_set_2({11, 22, 33, 11});

  set_2 = std::move(set_1);
  orignal_set_2 = std::move(orignal_set_1);

  s21::Set<int>::iterator it = set_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);

  it = set_2.Begin();
  auto it_2 = orignal_set_2.begin();
  for (; it != set_2.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }

  EXPECT_EQ(set_2.Size(), orignal_set_2.size());
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());
}

TEST(set_test, move_operator_02) {
  s21::Set<int> set_1({1, 2});
  EXPECT_EQ(set_1.Size(), 2);
  s21::Set<int> set_2({11, 22, 33});
  EXPECT_EQ(set_2.Size(), 3);

  set_2 = std::move(set_1);

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 2);

  auto it = set_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(set_test, move_operator_to_yourself) {
  s21::Set<int> set_1({1, 2, 1});
  std::set<int> orignal_set_1({1, 2, 1});
  EXPECT_EQ(set_1.Size(), 2);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  set_1 = std::move(set_1);
  orignal_set_1 = std::move(orignal_set_1);

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(orignal_set_1.size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());
}

TEST(set_test, move_operator_03) {
  s21::Set<int> set_1;
  EXPECT_EQ(set_1.Size(), 0);
  s21::Set<int> set_2;
  EXPECT_EQ(set_2.Size(), 0);

  set_2 = std::move(set_1);

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);
}

TEST(set_test, move_operator_04) {
  s21::Set<int> set_1({1, 2});
  EXPECT_EQ(set_1.Size(), 2);
  s21::Set<int> set_2;
  EXPECT_EQ(set_2.Size(), 0);

  set_1 = std::move(set_2);

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);
}

TEST(set_test, test_empty) {
  s21::Set<int> set_1({2, 4, 6, 8});
  s21::Set<int> set_2;

  EXPECT_EQ(set_1.Empty(), false);
  EXPECT_EQ(set_2.Empty(), true);
}

TEST(set_test, test_size) {
  s21::Set<double> set_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2});
  EXPECT_EQ(set_1.Size(), 5);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());
}

TEST(set_test, test_max_size) {
  s21::Set<double> set_1;
  std::set<double> orignal_set_1;
  EXPECT_EQ(set_1.MaxSize(), orignal_set_1.max_size());
}

TEST(set_test, test_clear) {
  s21::Set<int> set_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  s21::Set<int> set_2({1});
  s21::Set<int> tree_3;
  EXPECT_EQ(set_1.Size(), 12);
  EXPECT_EQ(set_2.Size(), 1);
  EXPECT_EQ(tree_3.Size(), 0);

  set_1.Clear();
  set_2.Clear();
  tree_3.Clear();

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);
  EXPECT_EQ(tree_3.Size(), 0);
}

TEST(set_test, test_insert) {
  s21::Set<double> set_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  EXPECT_EQ(set_1.Size(), 5);

  auto res_test_1 = set_1.Insert(3.2);
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(), 3.2);

  auto res_orignal_set_1 = orignal_set_1.insert(3.2);
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(),
                   res_orignal_set_1.first.operator*());

  auto it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, test_insert_02) {
  s21::Set<double> set_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5, 5.5, 1.1});
  EXPECT_EQ(set_1.Size(), 5);

  auto res_test_1 = set_1.Insert(3.3);
  EXPECT_EQ(res_test_1.second, false);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(), 3.3);

  auto res_orignal_set_1 = orignal_set_1.insert(3.3);
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(),
                   res_orignal_set_1.first.operator*());

  auto it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, test_insert_03) {
  s21::Set<double> set_1;
  std::set<double> orignal_set_1;
  EXPECT_EQ(set_1.Size(), 0);

  auto res_test_1 = set_1.Insert(3.2);
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(), 3.2);

  auto res_orignal_set_1 = orignal_set_1.insert(3.2);
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(),
                   res_orignal_set_1.first.operator*());

  auto it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, test_erase) {
  s21::Set<int> set_1;
  std::set<int> orignal_set_1;

  for (int i = 1; i < 21; i++) {
    set_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(set_1.Size(), 20);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto it = set_1.Insert(25).first;
  auto it_2 = orignal_set_1.insert(25).first;
  EXPECT_EQ(set_1.Size(), 21);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  set_1.Erase(it);
  orignal_set_1.erase(it_2);
  EXPECT_EQ(set_1.Size(), 20);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(set_1.IsBalanced(), true);
}

TEST(set_test, test_erase_01) {
  s21::Set<int> set_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  std::set<int> orignal_set_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

  EXPECT_EQ(set_1.Size(), 12);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto it = set_1.Begin();
  set_1.Advance(it, 4);
  auto it_2 = orignal_set_1.begin();
  std::advance(it_2, 4);
  EXPECT_DOUBLE_EQ(*it, *it_2);

  set_1.Erase(it);
  orignal_set_1.erase(it_2);
  EXPECT_EQ(set_1.Size(), 11);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(set_1.IsBalanced(), true);
}

TEST(set_test, test_erase_03) {
  s21::Set<int> set_1;
  std::set<int> orignal_set_1;

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto it = set_1.Begin();

  set_1.Erase(it);
  EXPECT_EQ(set_1.Size(), 0);

  EXPECT_EQ(set_1.IsBalanced(), true);
}

TEST(set_test, test_swap) {
  s21::Set<int> set_1({1, 3, 5});
  s21::Set<int> set_2({2, 4, 6, 8});

  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_2.Size(), 4);

  std::set<int> orignal_set_1({1, 3, 5});
  std::set<int> orignal_set_2({2, 4, 6, 8});

  set_1.Swap(set_2);
  orignal_set_1.swap(orignal_set_2);

  EXPECT_EQ(set_1.Size(), 4);
  EXPECT_EQ(set_2.Size(), 3);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());
  EXPECT_EQ(set_2.Size(), orignal_set_2.size());

  s21::Set<int>::iterator it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it), (*it_2));
    ++it_2;
  }

  s21::Set<int>::iterator it_3 = set_2.Begin();
  auto it_4 = orignal_set_2.begin();
  for (; it_3 != set_2.End(); ++it_3) {
    EXPECT_DOUBLE_EQ((*it_3), (*it_4));
    ++it_4;
  }
}

TEST(set_test, test_swap_yourself) {
  s21::Set<int> set_1({1, 3, 5});

  EXPECT_EQ(set_1.Size(), 3);

  std::set<int> orignal_set_1({1, 3, 5});

  set_1.Swap(set_1);
  orignal_set_1.swap(orignal_set_1);

  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  s21::Set<int>::iterator it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it), (*it_2));
    ++it_2;
  }
}

TEST(set_test, test_swap_yourself_02) {
  s21::Set<int> set_1;

  EXPECT_EQ(set_1.Size(), 0);

  std::set<int> orignal_set_1;

  set_1.Swap(set_1);
  orignal_set_1.swap(orignal_set_1);

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  s21::Set<int>::iterator it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it), (*it_2));
    ++it_2;
  }
}

TEST(set_test, test_merge) {
  s21::Set<int> set_1({1, 3, 5});
  s21::Set<int> set_2({2, 4, 6, 8});

  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_2.Size(), 4);

  std::set<int> orignal_set_1({1, 3, 5, 2, 4, 6, 8});

  set_1.Merge(set_2);

  EXPECT_EQ(set_1.Size(), 7);
  EXPECT_EQ(set_2.Size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, test_merge_02) {
  s21::Set<int> set_1({2, 4, 6, 8, 8});
  s21::Set<int> set_2({1, 3, 5, 1});

  EXPECT_EQ(set_1.Size(), 4);
  EXPECT_EQ(set_2.Size(), 3);

  std::set<int> orignal_set_1({1, 3, 5, 2, 4, 6, 8, 1, 8});

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  set_1.Merge(set_2);

  EXPECT_EQ(set_1.Size(), 7);
  EXPECT_EQ(set_2.Size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, test_merge_03) {
  s21::Set<int> set_1;
  s21::Set<int> set_2({1, 3, 5});

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 3);

  std::set<int> orignal_set_1({1, 3, 5});

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  set_1.Merge(set_2);

  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_2.Size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, test_merge_04) {
  s21::Set<int> set_1({2, 4, 6, 8});
  s21::Set<int> set_2;

  EXPECT_EQ(set_1.Size(), 4);
  EXPECT_EQ(set_2.Size(), 0);

  std::set<int> orignal_set_1({2, 4, 6, 8});

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  set_1.Merge(set_2);

  EXPECT_EQ(set_1.Size(), 4);
  EXPECT_EQ(set_2.Size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, test_merge_05) {
  s21::Set<int> set_1;
  s21::Set<int> set_2;

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);

  std::set<int> orignal_set_1;

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  set_1.Merge(set_2);

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  s21::Set<int>::iterator it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, test_merge_06) {
  s21::Set<int> set_1;
  s21::Set<int> set_2;

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);

  std::set<int> orignal_set_1;

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  set_1.Merge(set_1);
  set_2.Merge(set_2);

  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_2.Size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  s21::Set<int>::iterator it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(set_test, test_contains) {
  s21::Set<double> set_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2});
  EXPECT_EQ(set_1.Size(), 5);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto res_test_1 = set_1.Contains(3.3);
  EXPECT_EQ(res_test_1, true);
  res_test_1 = set_1.Contains(3.2);
  EXPECT_EQ(res_test_1, false);
}

TEST(set_test, test_find) {
  s21::Set<double> set_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2});
  EXPECT_EQ(set_1.Size(), 5);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto res_test_1 = set_1.Find(3.3);
  EXPECT_EQ(res_test_1.operator*(), 3.3);
  res_test_1 = set_1.Find(3.2);
  EXPECT_DOUBLE_EQ(res_test_1.operator*(), 0);
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

TEST(set_test, test_emplace) {
  s21::Set<President> set_1;
  std::set<President> orignal_set_1;
  EXPECT_EQ(set_1.Size(), 0);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  set_1.Emplace("Nelson Mandela", "South Africa", 1994);
  orignal_set_1.emplace("Nelson Mandela", "South Africa", 1994);

  EXPECT_EQ(set_1.Size(), 1);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  auto it = set_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  s21::Set<President> list_2;
  std::set<President> orignal_list_2;
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

  EXPECT_EQ(set_1.Size(), 1);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  set_1.Emplace("Lionel Messi", "Barcelona", 2010);
  orignal_set_1.emplace("Lionel Messi", "Barcelona", 2010);

  EXPECT_EQ(set_1.Size(), 2);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  EXPECT_EQ(set_1.Size(), 2);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  set_1.Emplace("Franklin Delano Roosevelt", "the USA", 1936);
  orignal_set_1.emplace("Franklin Delano Roosevelt", "the USA", 1936);

  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  EXPECT_EQ(set_1.Size(), 3);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  ++it;
  ++it_2;

  auto vec = set_1.Emplace("Cristiano Ronaldo", "Real Madrid", 2016);
  auto vec_2 = orignal_set_1.emplace("Cristiano Ronaldo", "Real Madrid", 2016);

  auto itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(set_1.Size(), 4);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = set_1.Emplace("Cristiano", "Real", 2016);
  vec_2 = orignal_set_1.emplace("Cristiano", "Real", 2016);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, false);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(set_1.Size(), 4);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = set_1.Emplace("Luka Modrić", "Real Madrid", 2018);
  vec_2 = orignal_set_1.emplace("Luka Modrić", "Real Madrid", 2018);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(set_1.Size(), 5);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = set_1.Emplace("Karim Benzema", "Real Madrid", 2022);
  vec_2 = orignal_set_1.emplace("Karim Benzema", "Real Madrid", 2022);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(set_1.Size(), 6);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = set_1.Emplace("Kevin De Bruyne", "Manchester City", 2022);
  vec_2 = orignal_set_1.emplace("Kevin De Bruyne", "Manchester City", 2022);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, false);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(set_1.Size(), 6);
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }
}

TEST(set_test, test_iter_end) {
  s21::Set<int> set_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Set<int>::iterator it = set_1.End();
  std::set<int>::iterator it_2 = orignal_set_1.end();
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(set_test, test_iter_end_empty) {
  s21::Set<int> set_1;
  std::set<int> orignal_set_1;

  s21::Set<int>::iterator it = set_1.End();
  std::set<int>::iterator it_2 = orignal_set_1.end();
  EXPECT_EQ(*it, *it_2);

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  --it;
  it--;
  it = set_1.End();
  ++it;
  it++;
}

TEST(set_test, test_const_iter_end_empty) {
  s21::Set<int> set_1;
  std::set<int> orignal_set_1;

  s21::Set<int>::const_iterator it = set_1.Cend();
  std::set<int>::const_iterator it_2 = orignal_set_1.cend();
  EXPECT_EQ(*it, *it_2);

  it = set_1.Cbegin();
  --it;
  it--;
  it = set_1.Cend();
  ++it;
  it++;
}

TEST(set_test, test_const_iter_end_pref) {
  s21::Set<int> set_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Set<int>::const_iterator it = set_1.Cend();
  std::set<int>::const_iterator it_2 = orignal_set_1.end();
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(set_test, test_const_iter_begin_pref) {
  s21::Set<int> set_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Set<int>::const_iterator it = set_1.Cbegin();
  std::set<int>::const_iterator it_2 = orignal_set_1.cbegin();
  ++it;
  ++it_2;
  EXPECT_EQ(*it, *it_2);
  ++it;
  ++it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(set_test, test_const_iter_end_post) {
  s21::Set<int> set_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Set<int>::const_iterator it = set_1.Cend();
  std::set<int>::const_iterator it_2 = orignal_set_1.end();
  it--;
  it_2--;
  EXPECT_EQ(*it, *it_2);
  it--;
  it_2--;
  EXPECT_EQ(*it, *it_2);
}

TEST(set_test, test_const_iter_begin_post) {
  s21::Set<int> set_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Set<int>::const_iterator it = set_1.Cbegin();
  std::set<int>::const_iterator it_2 = orignal_set_1.cbegin();
  it++;
  it_2++;
  EXPECT_EQ(*it, *it_2);
  it++;
  it_2++;
  EXPECT_EQ(*it, *it_2);
}

TEST(set_test, test_iter_plus) {
  s21::Set<int> set_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Set<int>::iterator it = set_1.Begin();
  std::set<int>::iterator it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end();) {
    EXPECT_EQ(*it, *it_2);
    ++it;
    ++it_2;
  }
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != set_1.End() && it_2 != orignal_set_1.end();) {
    EXPECT_EQ(*it, *it_2);
    it++;
    it_2++;
  }
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());
}

TEST(set_test, test_iter_minus) {
  s21::Set<int> set_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Set<int>::iterator it = set_1.End();
  std::set<int>::iterator it_2 = orignal_set_1.end();
  for (; it != set_1.Begin() && it_2 != orignal_set_1.begin();) {
    --it;
    --it_2;
    EXPECT_EQ(*it, *it_2);
  }
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.End();
  it_2 = orignal_set_1.end();
  for (; it != set_1.Begin() && it_2 != orignal_set_1.begin();) {
    it--;
    it_2--;
    EXPECT_EQ(*it, *it_2);
  }
  EXPECT_EQ(set_1.Size(), orignal_set_1.size());

  it = set_1.Begin();
  it_2 = orignal_set_1.begin();
  --it;
  --it_2;
  it--;
  it_2--;
  it = set_1.End();
  it_2 = orignal_set_1.end();
  ++it;
  ++it_2;
  it++;
  it_2++;
}
