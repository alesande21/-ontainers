#include <algorithm>

#include "../Includes/Containers/s21_tree.h"
#include "gtest/gtest.h"

TEST(tree_test, basic_constr) {
  s21::Tree<int> tree_d;
  s21::Tree<double> tree_i;
  s21::Tree<char> tree_c;
  EXPECT_EQ(tree_d.Size(), 0);
  EXPECT_EQ(tree_i.Size(), 0);
  EXPECT_EQ(tree_c.Size(), 0);
}

TEST(tree_test, constr_with_indefinite_number_of_elements) {
  s21::Tree<double> tree_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5, 1.1});
  EXPECT_EQ(tree_1.Size(), 5);
  auto it = tree_1.Begin();
  double res = 1.1;
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, res);
    res = res + 1.1;
  }
  it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, constr_with_indefinite_number_of_elements_string) {
  s21::Tree<char> tree_1({'t', 'w', 't', 'r'});
  std::set<char> orignal_set_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(tree_1.Size(), 3);

  auto it = tree_1.Begin();
  EXPECT_EQ(*it, 'r');
  ++it;
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'w');

  it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

// TEST(tree_test, constr_copy_to_yourself) {
//   s21::Tree<char> tree_1(tree_1);
//   std::set<char> orignal_set_1(orignal_set_1);
//   EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

//   auto it = tree_1.Begin();
//   auto it_2 = orignal_set_1.begin();
//   for (; it != tree_1.End(); ++it) {
//     EXPECT_EQ(*it, *it_2);
//     ++it_2;
//   }
// }

TEST(tree_test, copy_constr) {
  s21::Tree<char> tree_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(tree_1.Size(), 3);
  s21::Tree<char> tree_2(tree_1);

  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_2.Size(), 3);

  auto it = tree_1.Begin();
  auto it_2 = tree_2.Begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, copy_constr_01) {
  s21::Tree<char> tree_1;
  EXPECT_EQ(tree_1.Size(), 0);
  s21::Tree<char> tree_2(tree_1);

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);

  auto it = tree_1.Begin();
  auto it_2 = tree_2.Begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, copy_operator_01) {
  s21::Tree<char> tree_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(tree_1.Size(), 3);
  s21::Tree<char> tree_2({'J', 'P', 'M', 'J', 'P', 'M'});
  EXPECT_EQ(tree_2.Size(), 3);

  tree_1 = tree_2;
  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_2.Size(), 3);
  auto it = tree_1.Begin();
  auto it_2 = tree_2.Begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, copy_operator_02) {
  s21::Tree<int> tree_1({1, 2, 1});
  s21::Tree<int> tree_2;

  std::set<int> orignal_set_1({1, 2, 1});
  std::set<int> orignal_set_2;

  EXPECT_EQ(tree_1.Size(), 2);

  tree_1 = tree_2;
  orignal_set_1 = orignal_set_2;
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);
}

TEST(tree_test, copy_operator_06) {
  s21::Tree<int> tree_1({1, 2, 1});

  std::set<int> orignal_set_1({1, 2, 1});

  EXPECT_EQ(tree_1.Size(), 2);

  tree_1 = tree_1;
  orignal_set_1 = orignal_set_1;

  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  EXPECT_EQ(tree_1.Size(), 2);
  EXPECT_EQ(orignal_set_1.size(), 2);
}

TEST(tree_test, copy_operator_05) {
  s21::Tree<int> tree_1;
  s21::Tree<int> tree_2;

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);

  tree_1 = tree_2;
  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);
}

TEST(tree_test, copy_operator_03) {
  s21::Tree<int> tree_1({1, 2});
  s21::Tree<int> tree_2({11, 22, 33});

  EXPECT_EQ(tree_1.Size(), 2);
  EXPECT_EQ(tree_2.Size(), 3);

  tree_1 = tree_2;
  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_2.Size(), 3);

  s21::Tree<int>::iterator it = tree_1.Begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
  it = tree_1.Begin();
  s21::Tree<int>::iterator it_2 = tree_2.Begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, copy_operator_04) {
  s21::Tree<int> tree_1({1, 2, 1});
  std::set<int> orignal_set_1({1, 2, 1});

  EXPECT_EQ(tree_1.Size(), 2);

  tree_1 = tree_1;
  orignal_set_1 = orignal_set_1;
  EXPECT_EQ(tree_1.Size(), 2);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
}

TEST(tree_test, move_constr) {
  s21::Tree<int> tree_1({5, 3, 1, 2, 2, 2});
  EXPECT_EQ(tree_1.Size(), 4);
  s21::Tree<int> tree_2(std::move(tree_1));

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 4);

  std::set<int> orignal_list_1({5, 3, 1, 2});
  std::set<int> orignal_list_2(std::move(orignal_list_1));

  s21::Tree<int>::iterator it = tree_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);

  it = tree_2.Begin();
  auto it_2 = orignal_list_2.begin();
  for (; it != tree_2.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }

  EXPECT_EQ(tree_2.Size(), orignal_list_2.size());
  EXPECT_EQ(tree_1.Size(), orignal_list_1.size());
}

TEST(tree_test, constr_move_to_yourself) {
  s21::Tree<char> tree_1(std::move(tree_1));
  EXPECT_EQ(tree_1.Size(), 0);
}

TEST(tree_test, move_operator) {
  s21::Tree<int> tree_1({1, 2, 2});
  EXPECT_EQ(tree_1.Size(), 2);
  s21::Tree<int> tree_2({11, 22, 33, 11});
  EXPECT_EQ(tree_2.Size(), 3);

  tree_1 = std::move(tree_2);

  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_2.Size(), 0);

  auto it = tree_1.Begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
}

TEST(tree_test, move_operator_05) {
  s21::Tree<int> tree_1({5, 3, 1, 2, 2, 2});
  s21::Tree<int> tree_2({11, 22, 33, 11});

  EXPECT_EQ(tree_1.Size(), 4);
  EXPECT_EQ(tree_2.Size(), 3);

  std::set<int> orignal_list_1({5, 3, 1, 2});
  std::set<int> orignal_list_2({11, 22, 33, 11});

  tree_2 = std::move(tree_1);
  orignal_list_2 = std::move(orignal_list_1);

  s21::Tree<int>::iterator it = tree_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 5);

  it = tree_2.Begin();
  auto it_2 = orignal_list_2.begin();
  for (; it != tree_2.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }

  EXPECT_EQ(tree_2.Size(), orignal_list_2.size());
  EXPECT_EQ(tree_1.Size(), orignal_list_1.size());
}

TEST(tree_test, move_operator_02) {
  s21::Tree<int> tree_1({1, 2});
  EXPECT_EQ(tree_1.Size(), 2);
  s21::Tree<int> tree_2({11, 22, 33});
  EXPECT_EQ(tree_2.Size(), 3);

  tree_2 = std::move(tree_1);

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 2);

  auto it = tree_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(tree_test, move_operator_to_yourself) {
  s21::Tree<int> tree_1({1, 2, 1});
  std::set<int> orignal_set_1({1, 2, 1});
  EXPECT_EQ(tree_1.Size(), 2);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  tree_1 = std::move(tree_1);
  orignal_set_1 = std::move(orignal_set_1);

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(orignal_set_1.size(), 0);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
}

TEST(tree_test, move_operator_03) {
  s21::Tree<int> tree_1;
  EXPECT_EQ(tree_1.Size(), 0);
  s21::Tree<int> tree_2;
  EXPECT_EQ(tree_2.Size(), 0);

  tree_2 = std::move(tree_1);

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);
}

TEST(tree_test, move_operator_04) {
  s21::Tree<int> tree_1({1, 2});
  EXPECT_EQ(tree_1.Size(), 2);
  s21::Tree<int> tree_2;
  EXPECT_EQ(tree_2.Size(), 0);

  tree_1 = std::move(tree_2);

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);
}

TEST(tree_test, test_empty) {
  s21::Tree<int> tree_1({2, 4, 6, 8});
  s21::Tree<int> tree_2;

  EXPECT_EQ(tree_1.Empty(), false);
  EXPECT_EQ(tree_2.Empty(), true);
}

TEST(tree_test, test_size) {
  s21::Tree<double> tree_1({1.1, 2.2, 3.3, 4.4, 5.5});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5});
  EXPECT_EQ(tree_1.Size(), 5);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
}

TEST(tree_test, test_max_size) {
  s21::Tree<double> tree_1;
  std::set<double> orignal_set_1;
  EXPECT_EQ(tree_1.MaxSize(), orignal_set_1.max_size());
}

TEST(tree_test, test_clear) {
  s21::Tree<int> tree_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  s21::Tree<int> tree_2({1});
  s21::Tree<int> tree_3;
  EXPECT_EQ(tree_1.Size(), 12);
  EXPECT_EQ(tree_2.Size(), 1);
  EXPECT_EQ(tree_3.Size(), 0);

  tree_1.Clear();
  tree_2.Clear();
  tree_3.Clear();

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);
  EXPECT_EQ(tree_3.Size(), 0);
}

TEST(tree_test, test_insert) {
  s21::Tree<double> tree_1({1.1, 2.2, 3.3, 4.4, 5.5});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5});
  EXPECT_EQ(tree_1.Size(), 5);

  auto res_test_1 = tree_1.Insert(3.2);
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(), 3.2);

  auto res_orignal_set_1 = orignal_set_1.insert(3.2);
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(),
                   res_orignal_set_1.first.operator*());

  s21::Tree<double>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, test_insert_02) {
  s21::Tree<double> tree_1({1.1, 2.2, 3.3, 4.4, 5.5});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5});
  EXPECT_EQ(tree_1.Size(), 5);

  auto res_test_1 = tree_1.Insert(3.3);
  EXPECT_EQ(res_test_1.second, false);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(), 3.3);

  auto res_orignal_set_1 = orignal_set_1.insert(3.3);
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(),
                   res_orignal_set_1.first.operator*());

  s21::Tree<double>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, test_insert_03) {
  s21::Tree<double> tree_1;
  std::set<double> orignal_set_1;
  EXPECT_EQ(tree_1.Size(), 0);

  auto res_test_1 = tree_1.Insert(3.2);
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(), 3.2);

  auto res_orignal_set_1 = orignal_set_1.insert(3.2);
  EXPECT_EQ(res_test_1.second, res_orignal_set_1.second);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(),
                   res_orignal_set_1.first.operator*());

  s21::Tree<double>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, test_erase) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  for (int i = 1; i < 21; i++) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  auto it = tree_1.Insert(25).first;
  auto it_2 = orignal_set_1.insert(25).first;
  EXPECT_EQ(tree_1.Size(), 21);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  tree_1.Erase(it);
  orignal_set_1.erase(it_2);
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_erase_01) {
  s21::Tree<int> tree_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  std::set<int> orignal_set_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

  EXPECT_EQ(tree_1.Size(), 12);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  auto it = tree_1.Begin();
  tree_1.Advance(it, 4);
  auto it_2 = orignal_set_1.begin();
  std::advance(it_2, 4);
  EXPECT_DOUBLE_EQ(*it, *it_2);

  tree_1.Erase(it);
  orignal_set_1.erase(it_2);
  EXPECT_EQ(tree_1.Size(), 11);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);

  it = tree_1.Begin();
  tree_1.Advance(it, 6);
  it_2 = orignal_set_1.begin();
  std::advance(it_2, 6);
  EXPECT_DOUBLE_EQ(*it, *it_2);

  tree_1.Erase(it);
  orignal_set_1.erase(it_2);
  EXPECT_EQ(tree_1.Size(), 10);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_erase_03) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  auto it = tree_1.Begin();

  tree_1.Erase(it);
  EXPECT_EQ(tree_1.Size(), 0);

  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_swap) {
  s21::Tree<int> tree_1({1, 3, 5});
  s21::Tree<int> tree_2({2, 4, 6, 8});

  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_2.Size(), 4);

  std::set<int> orignal_set_1({1, 3, 5});
  std::set<int> orignal_set_2({2, 4, 6, 8});

  tree_1.Swap(tree_2);
  orignal_set_1.swap(orignal_set_2);

  EXPECT_EQ(tree_1.Size(), 4);
  EXPECT_EQ(tree_2.Size(), 3);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  EXPECT_EQ(tree_2.Size(), orignal_set_2.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it), (*it_2));
    ++it_2;
  }

  s21::Tree<int>::iterator it_3 = tree_2.Begin();
  auto it_4 = orignal_set_2.begin();
  for (; it_3 != tree_2.End(); ++it_3) {
    EXPECT_DOUBLE_EQ((*it_3), (*it_4));
    ++it_4;
  }
}

TEST(tree_test, test_swap_yourself) {
  s21::Tree<int> tree_1({1, 3, 5});

  EXPECT_EQ(tree_1.Size(), 3);

  std::set<int> orignal_set_1({1, 3, 5});

  tree_1.Swap(tree_1);
  orignal_set_1.swap(orignal_set_1);

  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ((*it), (*it_2));
    ++it_2;
  }
}

TEST(tree_test, test_merge) {
  s21::Tree<int> tree_1({1, 3, 5});
  s21::Tree<int> tree_2({2, 4, 6, 8});

  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_2.Size(), 4);

  std::set<int> orignal_set_1({1, 3, 5, 2, 4, 6, 8});

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  tree_1.Merge(tree_2);

  EXPECT_EQ(tree_1.Size(), 7);
  EXPECT_EQ(tree_2.Size(), 0);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, test_merge_02) {
  s21::Tree<int> tree_1({2, 4, 6, 8});
  s21::Tree<int> tree_2({1, 3, 5});

  EXPECT_EQ(tree_1.Size(), 4);
  EXPECT_EQ(tree_2.Size(), 3);

  std::set<int> orignal_set_1({1, 3, 5, 2, 4, 6, 8});

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  tree_1.Merge(tree_2);

  EXPECT_EQ(tree_1.Size(), 7);
  EXPECT_EQ(tree_2.Size(), 0);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, test_merge_03) {
  s21::Tree<int> tree_1;
  s21::Tree<int> tree_2({1, 3, 5});

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 3);

  std::set<int> orignal_set_1({1, 3, 5});

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  tree_1.Merge(tree_2);

  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_2.Size(), 0);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, test_merge_04) {
  s21::Tree<int> tree_1({2, 4, 6, 8});
  s21::Tree<int> tree_2;

  EXPECT_EQ(tree_1.Size(), 4);
  EXPECT_EQ(tree_2.Size(), 0);

  std::set<int> orignal_set_1({2, 4, 6, 8});

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  tree_1.Merge(tree_2);

  EXPECT_EQ(tree_1.Size(), 4);
  EXPECT_EQ(tree_2.Size(), 0);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, test_merge_05) {
  s21::Tree<int> tree_1;
  s21::Tree<int> tree_2;

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);

  std::set<int> orignal_set_1;

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  tree_1.Merge(tree_2);

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, test_merge_06) {
  s21::Tree<int> tree_1;
  s21::Tree<int> tree_2;

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);

  std::set<int> orignal_set_1;

  //  EXPECT_EQ(orignal_set_1.size(), 3);
  //  EXPECT_EQ(orignal_set_2.size(), 4);

  tree_1.Merge(tree_1);
  tree_2.Merge(tree_2);

  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_2.Size(), 0);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(tree_test, test_contains) {
  s21::Tree<double> tree_1({1.1, 2.2, 3.3, 4.4, 5.5});
  std::set<double> orignal_set_1({1.1, 2.2, 3.3, 4.4, 5.5});
  EXPECT_EQ(tree_1.Size(), 5);

  auto res_test_1 = tree_1.Contains(3.3);
  auto orig_test_1 = orignal_set_1.find(3.3);
  EXPECT_EQ(res_test_1.second, true);
  EXPECT_DOUBLE_EQ(res_test_1.first.operator*(), orig_test_1.operator*());
  res_test_1 = tree_1.Contains(3.2);
  EXPECT_EQ(res_test_1.second, false);
}

/*
 * different rotation test
 */

TEST(tree_test, test_insert_just_left_rotation) {
  s21::Tree<int> tree_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  std::set<int> orignal_set_1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  EXPECT_EQ(tree_1.Size(), 12);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_insert_just_right_rotation) {
  s21::Tree<int> tree_1({12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
  std::set<int> orignal_set_1({12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
  EXPECT_EQ(tree_1.Size(), 12);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_insert_test) {
  s21::Tree<int> tree_1({100, 50, 200, 250, 150, 49, 79, 80, 85, 60});
  std::set<int> orignal_set_1({100, 50, 200, 250, 150, 49, 79, 80, 85, 60});
  EXPECT_EQ(tree_1.Size(), 10);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_two_red_inide_left) {
  s21::Tree<int> tree_1({50, 20, 75, 60, 90, 80, 79});
  std::set<int> orignal_set_1({50, 20, 75, 60, 90, 80, 79});
  EXPECT_EQ(tree_1.Size(), 7);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_two_red_inide_left_02) {
  s21::Tree<int> tree_1({50, 20, 75, 85, 60, 59, 58, 57});
  std::set<int> orignal_set_1({50, 20, 75, 85, 60, 59, 58, 57});
  EXPECT_EQ(tree_1.Size(), 8);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, two_red_inide_right) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 27, 15, 17});
  std::set<int> orignal_set_1({50, 20, 75, 10, 27, 15, 17});
  EXPECT_EQ(tree_1.Size(), 7);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, two_red_inide_right_02) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 25, 26, 27, 28});
  std::set<int> orignal_set_1({50, 20, 75, 10, 25, 26, 27, 28});
  EXPECT_EQ(tree_1.Size(), 8);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, inside_right_rotation_left_rot) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});
  EXPECT_EQ(tree_1.Size(), 5);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, inside_left_rotation_right_rot) {
  s21::Tree<int> tree_1({50, 20, 75, 77, 76});
  std::set<int> orignal_set_1({50, 20, 75, 77, 76});
  EXPECT_EQ(tree_1.Size(), 5);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

// TEST(tree_test, test_20mln) {
//   s21::Tree<int> tree_1;
//   std::set<int> orignal_set_1;
//
//   for (int i = 10000000; i < 20000000; i++) {
//     tree_1.Insert(i,true);
//     orignal_set_1.insert(i);
//   }
//
//   for (int i = 6000001; i > 4000000; i--) {
//     tree_1.Insert(i,true);
//     orignal_set_1.insert(i);
//   }
//
//   for (int i = 2000000; i > 0; i--) {
//     tree_1.Insert(i,true);
//     orignal_set_1.insert(i);
//   }
//
//   for (int i = 2000001; i < 4000000; i++) {
//     tree_1.Insert(i,true);
//     orignal_set_1.insert(i);
//   }
//
//   for (int i = 4000001; i < 8000000; i++) {
//     tree_1.Insert(i,true);
//     orignal_set_1.insert(i);
//   }
//
//   for (int i = 10000000; i > 8000001; i--) {
//     tree_1.Insert(i,true);
//     orignal_set_1.insert(i);
//   }
//
//
//   EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//   auto it = tree_1.Begin();
//   auto it_2 = orignal_set_1.begin();
//   for (; it != tree_1.End(); ++it) {
//     EXPECT_DOUBLE_EQ(*it, *it_2);
//     ++it_2;
//   }
//   EXPECT_EQ(tree_1.IsBalanced());
// }

/*
 * deleting elements
 */

TEST(tree_test, test_simple_del) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  for (int i = 1; i < 21; i++) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  tree_1.Insert(19);
  orignal_set_1.insert(19);
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  auto it = tree_1.Contains(19).first;
  auto it_2 = orignal_set_1.find(19);

  tree_1.Erase(it);
  orignal_set_1.erase(it_2);

  EXPECT_EQ(tree_1.Size(), 19);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_simple_del_02) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  for (int i = 1; i < 21; i++) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  tree_1.Insert(19);
  orignal_set_1.insert(19);
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  auto it = tree_1.Contains(20).first;
  auto it_2 = orignal_set_1.find(20);
  tree_1.Erase(it);
  orignal_set_1.erase(it_2);

  EXPECT_EQ(tree_1.Size(), 19);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_simple_del_03) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  for (int i = 1; i < 21; i++) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  tree_1.Insert(19);
  orignal_set_1.insert(19);
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  auto it = tree_1.Contains(18).first;
  auto it_2 = orignal_set_1.find(18);
  tree_1.Erase(it);
  orignal_set_1.erase(it_2);

  EXPECT_EQ(tree_1.Size(), 19);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_simple_del_04) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  for (int i = 1; i < 21; i++) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  tree_1.Insert(19);
  orignal_set_1.insert(19);
  EXPECT_EQ(tree_1.Size(), 20);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  auto it = tree_1.Contains(4).first;
  auto it_2 = orignal_set_1.find(4);
  tree_1.Erase(it);
  orignal_set_1.erase(it_2);

  EXPECT_EQ(tree_1.Size(), 19);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_medium_del) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  for (int i = 100; i < 200; i++) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);

  for (int i = 61; i > 40; i--) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);

  for (int i = 20; i > 0; i--) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);

  for (int i = 21; i < 40; i++) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);

  for (int i = 41; i < 80; i++) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);

  for (int i = 100; i > 81; i--) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);

  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();

  for (int i = 2; i < 199; i++) {
    it = tree_1.Contains(i).first;
    tree_1.Erase(it);
    orignal_set_1.erase(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);

  for (int i = 41; i < 60; i++) {
    it = tree_1.Contains(i).first;
    tree_1.Erase(it);
    orignal_set_1.erase(i);
  }

  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_medium_del_02) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  for (int i = 20; i > 0; i--) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  for (int i = 21; i < 40; i++) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  for (int i = 60; i > 40; i--) {
    tree_1.Insert(i);
    orignal_set_1.insert(i);
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  s21::Tree<int>::iterator it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();

  for (int i = 58; i > 2; i--) {
    it = tree_1.Contains(i).first;
    tree_1.Erase(it);
    orignal_set_1.erase(i);
  }

  EXPECT_EQ(tree_1.Contains(55).second, false);
  EXPECT_EQ(tree_1.Contains(199).second, false);
  EXPECT_EQ(tree_1.Contains(1).second, true);
  EXPECT_EQ(tree_1.Contains(59).second, true);

  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

TEST(tree_test, test_del_root) {
  s21::Tree<double> tree_1;
  std::set<double> orignal_set_1;

  tree_1.Insert(10.0);
  tree_1.Insert(15.0);
  tree_1.Insert(5.0);
  tree_1.Insert(4.0);
  tree_1.Insert(16.0);

  orignal_set_1.insert(10);
  orignal_set_1.insert(15);
  orignal_set_1.insert(5);
  orignal_set_1.insert(4);
  orignal_set_1.insert(16);

  auto it = tree_1.Begin();
  auto it_2 = orignal_set_1.begin();
  it = tree_1.Contains(15).first;
  tree_1.Erase(it);
  EXPECT_EQ(tree_1.IsBalanced(), true);
  it = tree_1.Contains(10).first;
  tree_1.Erase(it);
  EXPECT_EQ(tree_1.IsBalanced(), true);
  it = tree_1.Contains(5).first;
  tree_1.Erase(it);
  EXPECT_EQ(tree_1.IsBalanced(), true);
  it = tree_1.Contains(4).first;
  tree_1.Erase(it);

  orignal_set_1.erase(15.0);
  orignal_set_1.erase(10.0);
  orignal_set_1.erase(5.0);
  orignal_set_1.erase(4.0);

  EXPECT_EQ(tree_1.Contains(16).second, true);

  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End() && it_2 != orignal_set_1.end();) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it;
    ++it_2;
  }
  EXPECT_EQ(tree_1.IsBalanced(), true);
}

// TEST(tree_test, test_del_20mln) {
//   s21::Tree<int> tree_1;
//   std::set<int> orignal_set_1;
//
//   for (int i = 10000000; i < 20000000; i++) {
//     tree_1.Insert(i,true);
//     orignal_set_1.insert(i);
////    EXPECT_EQ(tree_1.IsBalanced(), true);
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//
//  for (int i = 6000001; i > 4000000; i--) {
//    tree_1.Insert(i,true);
//    orignal_set_1.insert(i);
////    EXPECT_EQ(tree_1.IsBalanced(), true);
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//
//  for (int i = 2000000; i > 0; i--) {
//    tree_1.Insert(i,true);
//    orignal_set_1.insert(i);
////    EXPECT_EQ(tree_1.IsBalanced(), true);
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//
//  for (int i = 2000001; i < 4000000; i++) {
//    tree_1.Insert(i,true);
//    orignal_set_1.insert(i);
////    EXPECT_EQ(tree_1.IsBalanced(), true);
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//
//  for (int i = 4000001; i < 8000000; i++) {
//    tree_1.Insert(i,true);
//    orignal_set_1.insert(i);
////    EXPECT_EQ(tree_1.IsBalanced(), true);
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//
//  for (int i = 10000000; i > 8000001; i--) {
//    tree_1.Insert(i,true);
//    orignal_set_1.insert(i);
////    EXPECT_EQ(tree_1.IsBalanced(), true);
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//
//  auto it = tree_1.Begin();
//  auto it_2 = orignal_set_1.begin();
//
//  for (int i = 7999999; i > 4000001; i--) { //4000001
//    it = tree_1.Contains(i).first;
//    tree_1.Erase(it);
//    orignal_set_1.erase(i);
////    EXPECT_EQ(tree_1.IsBalanced(), true);
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//
//  for (int i = 10000000; i > 8000001; i--) {
//    it = tree_1.Contains(i).first;
//    tree_1.Erase(it);
//    orignal_set_1.erase(i);
////    EXPECT_EQ(tree_1.IsBalanced(), true);
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//
//  for (int i = 19900000; i > 11000000; i--) {
//    it = tree_1.Contains(i).first;
//    tree_1.Erase(it);
//    orignal_set_1.erase(i);
////    EXPECT_EQ(tree_1.IsBalanced(), true);
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//
//  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
//  it = tree_1.Begin();
//  it_2 = orignal_set_1.begin();
//  for (; it != tree_1.End(); ++it) {
//    EXPECT_DOUBLE_EQ(*it, *it_2);
//    ++it_2;
//  }
//  EXPECT_EQ(tree_1.IsBalanced(), true);
//}

TEST(tree_test, test_const_iter) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Tree<int>::const_iterator it = tree_1.Cbegin();
  std::set<int>::const_iterator it_2 = orignal_set_1.cbegin();
  EXPECT_EQ(*it, *it_2);
}

TEST(tree_test, test_const_iter_empty) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  s21::Tree<int>::const_iterator it = tree_1.Cbegin();
  std::set<int>::const_iterator it_2 = orignal_set_1.cbegin();
  EXPECT_EQ(*it, *it_2);
}

TEST(tree_test, test_iter_end) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Tree<int>::iterator it = tree_1.End();
  std::set<int>::iterator it_2 = orignal_set_1.end();
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(tree_test, test_iter_end_empty) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  s21::Tree<int>::iterator it = tree_1.End();
  std::set<int>::iterator it_2 = orignal_set_1.end();
  EXPECT_EQ(*it, *it_2);

  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  --it;
  it--;
  it = tree_1.End();
  ++it;
  it++;
}

TEST(tree_test, test_const_iter_end_empty) {
  s21::Tree<int> tree_1;
  std::set<int> orignal_set_1;

  s21::Tree<int>::const_iterator it = tree_1.Cend();
  std::set<int>::const_iterator it_2 = orignal_set_1.cend();
  EXPECT_EQ(*it, *it_2);

  it = tree_1.Cbegin();
  --it;
  it--;
  it = tree_1.Cend();
  ++it;
  it++;
}

TEST(tree_test, test_const_iter_end_pref) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Tree<int>::const_iterator it = tree_1.Cend();
  std::set<int>::const_iterator it_2 = orignal_set_1.end();
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(tree_test, test_const_iter_begin_pref) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Tree<int>::const_iterator it = tree_1.Cbegin();
  std::set<int>::const_iterator it_2 = orignal_set_1.cbegin();
  ++it;
  ++it_2;
  EXPECT_EQ(*it, *it_2);
  ++it;
  ++it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(tree_test, test_const_iter_end_post) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Tree<int>::const_iterator it = tree_1.Cend();
  std::set<int>::const_iterator it_2 = orignal_set_1.end();
  it--;
  it_2--;
  EXPECT_EQ(*it, *it_2);
  it--;
  it_2--;
  EXPECT_EQ(*it, *it_2);
}

TEST(tree_test, test_const_iter_begin_post) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Tree<int>::const_iterator it = tree_1.Cbegin();
  std::set<int>::const_iterator it_2 = orignal_set_1.cbegin();
  it++;
  it_2++;
  EXPECT_EQ(*it, *it_2);
  it++;
  it_2++;
  EXPECT_EQ(*it, *it_2);
}

TEST(tree_test, test_iter_plus) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Tree<int>::iterator it = tree_1.Begin();
  std::set<int>::iterator it_2 = orignal_set_1.begin();
  for (; it != tree_1.End() && it_2 != orignal_set_1.end();) {
    EXPECT_EQ(*it, *it_2);
    ++it;
    ++it_2;
  }
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  for (; it != tree_1.End() && it_2 != orignal_set_1.end();) {
    EXPECT_EQ(*it, *it_2);
    it++;
    it_2++;
  }
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());
}

TEST(tree_test, test_iter_minus) {
  s21::Tree<int> tree_1({50, 20, 75, 10, 11});
  std::set<int> orignal_set_1({50, 20, 75, 10, 11});

  s21::Tree<int>::iterator it = tree_1.End();
  std::set<int>::iterator it_2 = orignal_set_1.end();
  for (; it != tree_1.Begin() && it_2 != orignal_set_1.begin();) {
    --it;
    --it_2;
    EXPECT_EQ(*it, *it_2);
  }
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  it = tree_1.End();
  it_2 = orignal_set_1.end();
  for (; it != tree_1.Begin() && it_2 != orignal_set_1.begin();) {
    it--;
    it_2--;
    EXPECT_EQ(*it, *it_2);
  }
  EXPECT_EQ(tree_1.Size(), orignal_set_1.size());

  it = tree_1.Begin();
  it_2 = orignal_set_1.begin();
  --it;
  --it_2;
  it--;
  it_2--;
  it = tree_1.End();
  it_2 = orignal_set_1.end();
  ++it;
  ++it_2;
  it++;
  it_2++;
}

TEST(tree_test, test_equal_range) {
  s21::Tree<int> multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  std::multiset<int> orignal_multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  EXPECT_EQ(multiset_1.Size(), 6);

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

TEST(tree_test, test_LowerBound) {
  s21::Tree<int> multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  std::multiset<int> orignal_multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  EXPECT_EQ(multiset_1.Size(), 6);

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
  //    orig_test_1 = orignal_multiset_1.LowerBound(16);
  //    EXPECT_EQ(res_test_1.operator*(), orig_test_1.operator*());
}

TEST(tree_test, test_LowerBound_02) {
  s21::Tree<int> multiset_1;
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

TEST(tree_test, test_upper_bound) {
  s21::Tree<int> multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  std::multiset<int> orignal_multiset_1({1, 3, 5, 8, 11, 15, 11, 5});
  EXPECT_EQ(multiset_1.Size(), 6);

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

TEST(tree_test, test_upper_bound_02) {
  s21::Tree<int> multiset_1;
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
};

TEST(tree_test, test_emplace) {
  s21::Tree<President> tree_1;
  std::set<President> orignal_tree_1;
  EXPECT_EQ(tree_1.Size(), 0);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  tree_1.Emplace("Nelson Mandela", "South Africa", 1994);
  orignal_tree_1.emplace("Nelson Mandela", "South Africa", 1994);

  EXPECT_EQ(tree_1.Size(), 1);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  auto it = tree_1.Begin();
  auto it_2 = orignal_tree_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  s21::Tree<President> list_2;
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

  EXPECT_EQ(tree_1.Size(), 1);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  tree_1.Emplace("Lionel Messi", "Barcelona", 2010);
  orignal_tree_1.emplace("Lionel Messi", "Barcelona", 2010);

  EXPECT_EQ(tree_1.Size(), 2);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  it = tree_1.Begin();
  it_2 = orignal_tree_1.begin();
  for (; it != tree_1.End(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  EXPECT_EQ(tree_1.Size(), 2);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  tree_1.Emplace("Franklin Delano Roosevelt", "the USA", 1936);
  orignal_tree_1.emplace("Franklin Delano Roosevelt", "the USA", 1936);

  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  it = tree_1.Begin();
  it_2 = orignal_tree_1.begin();
  for (; it != tree_1.End() && it_2 != orignal_tree_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  EXPECT_EQ(tree_1.Size(), 3);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  it = tree_1.Begin();
  it_2 = orignal_tree_1.begin();
  ++it;
  ++it_2;

  auto vec = tree_1.Emplace("Cristiano Ronaldo", "Real Madrid", 2016);
  auto vec_2 = orignal_tree_1.emplace("Cristiano Ronaldo", "Real Madrid", 2016);

  auto itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(tree_1.Size(), 4);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  it = tree_1.Begin();
  it_2 = orignal_tree_1.begin();
  for (; it != tree_1.End() && it_2 != orignal_tree_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = tree_1.Emplace("Cristiano", "Real", 2016);
  vec_2 = orignal_tree_1.emplace("Cristiano", "Real", 2016);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, false);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(tree_1.Size(), 4);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  it = tree_1.Begin();
  it_2 = orignal_tree_1.begin();
  for (; it != tree_1.End() && it_2 != orignal_tree_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = tree_1.Emplace("Luka Modrić", "Real Madrid", 2018);
  vec_2 = orignal_tree_1.emplace("Luka Modrić", "Real Madrid", 2018);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(tree_1.Size(), 5);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  it = tree_1.Begin();
  it_2 = orignal_tree_1.begin();
  for (; it != tree_1.End() && it_2 != orignal_tree_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = tree_1.Emplace("Karim Benzema", "Real Madrid", 2022);
  vec_2 = orignal_tree_1.emplace("Karim Benzema", "Real Madrid", 2022);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, true);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(tree_1.Size(), 6);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  it = tree_1.Begin();
  it_2 = orignal_tree_1.begin();
  for (; it != tree_1.End() && it_2 != orignal_tree_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  vec = tree_1.Emplace("Kevin De Bruyne", "Manchester City", 2022);
  vec_2 = orignal_tree_1.emplace("Kevin De Bruyne", "Manchester City", 2022);

  itr_vec = vec.begin();
  EXPECT_EQ(itr_vec->second, false);
  EXPECT_EQ(itr_vec->second, vec_2.second);
  EXPECT_EQ((*itr_vec->first).name, (*vec_2.first).name);
  EXPECT_EQ((*itr_vec->first).country, (*vec_2.first).country);
  EXPECT_EQ((*itr_vec->first).year, (*vec_2.first).year);

  EXPECT_EQ(tree_1.Size(), 6);
  EXPECT_EQ(tree_1.Size(), orignal_tree_1.size());

  it = tree_1.Begin();
  it_2 = orignal_tree_1.begin();
  for (; it != tree_1.End() && it_2 != orignal_tree_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }
}