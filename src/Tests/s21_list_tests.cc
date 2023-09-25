#include <list>

#include "../Includes/Containers/s21_list.h"
#include "gtest/gtest.h"

TEST(list_test, basic_constr) {
  s21::List<double> list_d;
  s21::List<int> list_i;
  s21::List<char> list_c;
  EXPECT_EQ(list_d.Size(), 0);
  EXPECT_EQ(list_i.Size(), 0);
  EXPECT_EQ(list_c.Size(), 0);
}

TEST(list_test, constr_with_indefinite_number_of_elements) {
  s21::List<double> list_1({1.1, 2.2, 3.3, 4.4, 5.5});
  EXPECT_EQ(list_1.Size(), 5);
  auto it = list_1.Begin();
  double res = 1.1;
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, res);
    res = res + 1.1;
  }
}

TEST(list_test, constr_with_the_list_of_Size_n) {
  s21::List<double> list_1(5);
  EXPECT_EQ(list_1.Size(), 5);
  auto it = list_1.Begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, 0.0);
  }
}

TEST(list_test, constr_with_indefinite_number_of_elements_string) {  // NEW
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  std::list<char> orignal_list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);

  auto it = list_1.Begin();
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'w');
  ++it;
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'r');

  it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, parameterized_constructor_creates_the_list_of_size_n) {  // NEW
  s21::List<char> list_1(50);
  std::list<char> orignal_list_1(50);
  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }

  s21::List<int> list_2(100);
  std::list<int> orignal_list_2(100);
  auto it_3 = list_2.Begin();
  auto it_4 = orignal_list_2.begin();
  for (; it_3 != list_2.End(); ++it_3) {
    EXPECT_EQ(*it_3, *it_4);
    ++it_4;
  }

  s21::List<std::string> list_3(150);
  std::list<std::string> orignal_list_3(150);
  auto it_5 = list_3.Begin();
  auto it_6 = orignal_list_3.begin();
  for (; it_5 != list_3.End(); ++it_5) {
    EXPECT_EQ(*it_5, *it_6);
    ++it_6;
  }
}

TEST(list_test, constr_copy_to_yourself) {  // NEW
  s21::List<char> list_1(list_1);
  std::list<char> orignal_list_1(orignal_list_1);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test,
     parameterized_constructor_creates_the_list_of_2000000) {  // NEW
  s21::List<char> list_1(200000);
  EXPECT_EQ(list_1.Size(), 200000);
}

TEST(list_test, copy_constr) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);
  s21::List<char> list_2(list_1);

  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_2.Size(), 4);

  auto it = list_1.Begin();
  auto it_2 = list_2.Begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, copy_operator_01) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);
  s21::List<char> list_2({'J', 'P', 'M'});
  EXPECT_EQ(list_2.Size(), 3);

  list_1 = list_2;
  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_2.Size(), 3);
  auto it = list_1.Begin();
  auto it_2 = list_2.Begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, copy_operator_02) {
  s21::List<int> list_1({1, 2});
  s21::List<int> list_2;

  EXPECT_EQ(list_1.Size(), 2);

  list_1 = list_2;
  EXPECT_EQ(list_1.Size(), 0);
  EXPECT_EQ(list_2.Size(), 0);
}

TEST(list_test, copy_operator_03) {
  s21::List<int> list_1({1, 2});
  s21::List<int> list_2({11, 22, 33});

  EXPECT_EQ(list_1.Size(), 2);
  EXPECT_EQ(list_2.Size(), 3);

  list_1 = list_2;
  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_2.Size(), 3);

  auto it = list_1.Begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
  it = list_1.Begin();
  auto it_2 = list_2.Begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, copy_operator_04) {  // NEW
  s21::List<int> list_1({1, 2});

  EXPECT_EQ(list_1.Size(), 2);

  list_1 = list_1;
  EXPECT_EQ(list_1.Size(), 2);
}

TEST(list_test, move_constr) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);
  s21::List<char> list_2(std::move(list_1));

  EXPECT_EQ(list_1.Size(), 0);
  EXPECT_EQ(list_2.Size(), 4);

  std::list<char> orignal_list_1({'t', 'w', 't', 'r'});

  auto it = list_2.Begin();
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'w');
  ++it;
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'r');

  it = list_2.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_2.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(List, test_move_const) {
  s21::List<double> list_1{1.1, 2.2, 3.3, 4.4, 5.5};
  std::list<double> orignal_list_1{1.1, 2.2, 3.3, 4.4, 5.5};

  s21::List<double> list_move(std::move(list_1));

  std::list<double> orignal_list_move(std::move(orignal_list_1));
  s21::List<double>::iterator it = list_move.Begin();
  std::list<double>::iterator it_2 = orignal_list_move.begin();
  for (; it != list_move.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(list_move.Size(), orignal_list_move.size());
  EXPECT_EQ(list_move.Empty(), orignal_list_move.empty());
  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  EXPECT_EQ(list_1.Empty(), orignal_list_1.empty());
}

TEST(List, test_operator_move) {
  s21::List<double> list_1{1.1, 2.2, 3.3, 4.4, 5.5};
  std::list<double> orignal_list_1{1.1, 2.2, 3.3, 4.4, 5.5};

  s21::List<double> list_move;
  list_move = (std::move(list_1));

  std::list<double> orignal_list_move;
  orignal_list_move = (std::move(orignal_list_1));
  s21::List<double>::iterator it = list_move.Begin();
  std::list<double>::iterator it_2 = orignal_list_move.begin();
  for (; it != list_move.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(list_move.Size(), orignal_list_move.size());
  EXPECT_EQ(list_move.Empty(), orignal_list_move.empty());
  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  EXPECT_EQ(list_1.Empty(), orignal_list_1.empty());
}

TEST(List, test_front_empty) {
  s21::List<int> list_1;
  std::list<int> orignal_list_1;
  EXPECT_EQ(list_1.Front(), orignal_list_1.front());
}

TEST(list_test, constr_move_to_yourself) {
  s21::List<char> list_1(std::move(list_1));
  EXPECT_EQ(list_1.Size(), 0);
}

TEST(list_test, move_operator) {
  s21::List<int> list_1({1, 2});
  EXPECT_EQ(list_1.Size(), 2);
  s21::List<int> list_2({11, 22, 33});
  EXPECT_EQ(list_2.Size(), 3);

  list_1 = std::move(list_2);

  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_2.Size(), 0);

  auto it = list_1.Begin();
  EXPECT_EQ(*it, 11);
  ++it;
  EXPECT_EQ(*it, 22);
  ++it;
  EXPECT_EQ(*it, 33);
}

TEST(list_test, move_operator_02) {
  s21::List<int> list_1({1, 2});
  EXPECT_EQ(list_1.Size(), 2);
  s21::List<int> list_2({11, 22, 33});
  EXPECT_EQ(list_2.Size(), 3);

  list_2 = std::move(list_1);

  EXPECT_EQ(list_1.Size(), 0);
  EXPECT_EQ(list_2.Size(), 2);

  auto it = list_2.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(list_test, move_operator_to_yourself) {
  s21::List<int> list_1({1, 2});
  EXPECT_EQ(list_1.Size(), 2);

  list_1 = std::move(list_1);

  EXPECT_EQ(list_1.Size(), 2);
  auto it = list_1.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(list_test, reverse) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  std::list<char> orignal_list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);

  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 'r');
  list_1.Reverse();
  orignal_list_1.reverse();

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  EXPECT_EQ(*it, 'r');
  ++it;
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'w');
  ++it;
  EXPECT_EQ(*it, 't');

  EXPECT_EQ(list_1.Front(), 'r');
  EXPECT_EQ(list_1.Back(), 't');

  it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, reverse_01) {
  s21::List<char> list_1({'t'});
  std::list<char> orignal_list_1({'t'});

  EXPECT_EQ(list_1.Size(), 1);
  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 't');

  list_1.Reverse();
  orignal_list_1.reverse();

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 't');

  auto it = list_1.Begin();
  EXPECT_EQ(*it, 't');
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, reverse_02) {
  s21::List<char> list_1({'t', 'r'});
  std::list<char> orignal_list_1({'t', 'r'});

  EXPECT_EQ(list_1.Size(), 2);
  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 'r');

  list_1.Reverse();
  orignal_list_1.reverse();

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  EXPECT_EQ(list_1.Front(), 'r');
  EXPECT_EQ(list_1.Back(), 't');

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, Push_front_01) {
  s21::List<int> list_1;
  std::list<int> orignal_list_1;

  EXPECT_EQ(list_1.Size(), 0);

  for (int i = 1; i < 5; i++) {
    list_1.PushFront(i);
    orignal_list_1.push_front(i);
  }

  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, Push_front_02) {
  s21::List<char> list_1({'r'});
  EXPECT_EQ(list_1.Size(), 1);

  list_1.PushFront('t');
  list_1.PushFront('w');
  list_1.PushFront('t');

  EXPECT_EQ(list_1.Size(), 4);
  auto it = list_1.Begin();
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'w');
  ++it;
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'r');
}

TEST(list_test, Push_back_01) {
  s21::List<char> list_1({'t'});
  EXPECT_EQ(list_1.Size(), 1);

  list_1.PushBack('w');
  list_1.PushBack('t');
  list_1.PushBack('r');

  EXPECT_EQ(list_1.Size(), 4);

  auto it = list_1.Begin();
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'w');
  ++it;
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'r');
}

TEST(list_test, Push_back_02) {
  s21::List<int> list_1;
  EXPECT_EQ(list_1.Size(), 0);

  list_1.PushBack(1);
  list_1.PushBack(2);
  list_1.PushBack(3);
  list_1.PushBack(4);

  EXPECT_EQ(list_1.Size(), 4);

  auto it = list_1.Begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
  ++it;
  EXPECT_EQ(*it, 4);
}

TEST(list_test, Push_back_03) {
  s21::List<int> list_1;
  std::list<int> orignal_list_1;

  EXPECT_EQ(list_1.Size(), 0);

  for (int i = 1; i < 5; i++) {
    list_1.PushBack(i);
    orignal_list_1.push_back(i);
  }

  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, pop_front) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);

  list_1.PopFront();
  list_1.PopFront();
  EXPECT_EQ(list_1.Size(), 2);

  auto it = list_1.Begin();
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'r');
}

TEST(list_test, pop_front_trow) {
  s21::List<char> list_1;
  EXPECT_EQ(list_1.Size(), 0);

  EXPECT_THROW(list_1.PopFront(), std::out_of_range);
}

TEST(list_test, pop_back) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);

  list_1.PopBack();
  list_1.PopBack();
  EXPECT_EQ(list_1.Size(), 2);

  auto it = list_1.Begin();
  EXPECT_EQ(*it, 't');
  ++it;
  EXPECT_EQ(*it, 'w');
}

TEST(list_test, pop_back_trow) {
  s21::List<char> list_1;
  EXPECT_EQ(list_1.Size(), 0);

  EXPECT_THROW(list_1.PopBack(), std::out_of_range);
}

TEST(list_test, clear_test) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);

  list_1.Clear();
  EXPECT_EQ(list_1.Size(), 0);
}

TEST(list_test, clear_test_empty_list) {
  s21::List<char> list_1;
  EXPECT_EQ(list_1.Size(), 0);

  list_1.Clear();
  EXPECT_EQ(list_1.Size(), 0);
}

TEST(list_test, empty_test_01) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);

  list_1.Clear();
  EXPECT_EQ(list_1.Empty(), 1);
}

TEST(list_test, empty_test_02) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);

  EXPECT_EQ(list_1.Empty(), 0);
}

TEST(list_test, max_size_test) {
  s21::List<char> list_1;
  std::list<char> orignal_list_1;

  EXPECT_EQ(list_1.MaxSize(), orignal_list_1.max_size());
}

TEST(list_test, max_size_test_02) {
  s21::List<std::string> list_1;
  std::list<std::string> orignal_list_1;

  EXPECT_EQ(list_1.MaxSize(), orignal_list_1.max_size());
}

TEST(list_test, max_size_test_03) {
  s21::List<double> list_1;
  std::list<double> orignal_list_1;

  EXPECT_EQ(list_1.MaxSize(), orignal_list_1.max_size());
}

TEST(list_test, back_test) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);

  EXPECT_EQ(list_1.Back(), 'r');
}

TEST(list_test, front_test) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);

  EXPECT_EQ(list_1.Front(), 't');
}

TEST(list_test, insert_01) {
  s21::List<double> list_1({2.2, 3.3, 4.4, 6.6, 7.7, 8.8, 10.0});
  std::list<double> orignal_list_1({2.2, 3.3, 4.4, 6.6, 7.7, 8.8, 10.0});
  EXPECT_EQ(list_1.Size(), 7);

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();

  list_1.Insert(it, 1.1);
  orignal_list_1.insert(it_2, 1.1);
  EXPECT_EQ(list_1.Size(), 8);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }

  EXPECT_EQ(list_1.Size(), 8);
  it = list_1.Begin();
  it_2 = orignal_list_1.begin();

  for (int i = 0; i < 5; i++) {
    ++it;
    ++it_2;
  }
  list_1.Insert(it, 5.5);
  orignal_list_1.insert(it_2, 5.5);
  EXPECT_EQ(list_1.Size(), 9);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }

  EXPECT_EQ(list_1.Size(), 9);
  it = list_1.Begin();
  it_2 = orignal_list_1.begin();

  for (int i = 0; i < 8; i++) {
    ++it;
    ++it_2;
  }
  list_1.Insert(it, 9.9);
  orignal_list_1.insert(it_2, 9.9);
  EXPECT_EQ(list_1.Size(), 10);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, insert_02) {
  s21::List<double> list_1({2.2, 3.3, 4.4, 6.6, 7.7, 8.8, 10.0});
  std::list<double> orignal_list_1({2.2, 3.3, 4.4, 6.6, 7.7, 8.8, 10.0});
  EXPECT_EQ(list_1.Size(), 7);

  auto it = list_1.End();
  auto it_2 = orignal_list_1.end();

  it = list_1.Insert(it, 100);
  it_2 = orignal_list_1.insert(it_2, 100);
  EXPECT_EQ(list_1.Size(), 8);
  EXPECT_DOUBLE_EQ(*it, *it_2);
  EXPECT_DOUBLE_EQ(*it, 100);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.End();
  --it;
  EXPECT_DOUBLE_EQ(*it, 100);
  --it;
  EXPECT_DOUBLE_EQ(*it, 10.0);

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, insert_trow_01) {
  s21::List<char> list_1;
  EXPECT_EQ(list_1.Size(), 0);

  auto it = list_1.Begin();

  EXPECT_EQ(list_1.Insert(it, 't').operator*(), 't');
}

TEST(list_test, swap_01) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);
  s21::List<char> list_2({'J', 'P', 'M'});
  EXPECT_EQ(list_2.Size(), 3);

  list_1.Swap(list_2);
  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_2.Size(), 4);
  auto it = list_1.Begin();
  EXPECT_EQ(*it, 'J');
  ++it;
  EXPECT_EQ(*it, 'P');
  ++it;
  EXPECT_EQ(*it, 'M');

  auto it_3 = list_2.Begin();
  EXPECT_EQ('t', *it_3);
  ++it_3;
  EXPECT_EQ('w', *it_3);
  ++it_3;
  EXPECT_EQ('t', *it_3);
  ++it_3;
  EXPECT_EQ('r', *it_3);

  std::list<char> orignal_list_1({'t', 'w', 't', 'r'});
  std::list<char> orignal_list_2({'J', 'P', 'M'});
  orignal_list_1.swap(orignal_list_2);
  it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  it_3 = list_2.Begin();
  auto it_4 = orignal_list_2.begin();
  for (; it_3 != list_2.End(); ++it_3) {
    EXPECT_DOUBLE_EQ(*it_3, *it_4);
    ++it_4;
  }
}

TEST(list_test, swap_02) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  EXPECT_EQ(list_1.Size(), 4);
  s21::List<char> list_2;
  EXPECT_EQ(list_2.Size(), 0);

  list_1.Swap(list_1);
  list_2.Swap(list_2);

  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_2.Size(), 0);
}

TEST(list_test, sort_01) {
  s21::List<double> list_1({27, 0.1, 3, 15, 100, 0.2, 70, 8.8, 0, 2});
  std::list<double> orignal_list_1({27, 0.1, 3, 15, 100, 0.2, 70, 8.8, 0, 2});
  EXPECT_EQ(list_1.Size(), 10);

  list_1.Sort();
  orignal_list_1.sort();
  EXPECT_EQ(list_1.Size(), 10);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, sort_02) {
  s21::List<double> list_1({27, 0.1, 3, 15, -100, 0.2, 70, 8.8, 0});
  std::list<double> orignal_list_1({27, 0.1, 3, 15, -100, 0.2, 70, 8.8, 0});

  list_1.Sort();
  orignal_list_1.sort();

  EXPECT_EQ(list_1.Size(), 9);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, sort_03) {
  s21::List<double> list_1({27, 0.1});
  std::list<double> orignal_list_1({27, 0.1});

  list_1.Sort();
  orignal_list_1.sort();

  EXPECT_EQ(list_1.Size(), 2);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, sort_04) {
  s21::List<double> list_1({27});
  std::list<double> orignal_list_1({27});

  list_1.Sort();
  orignal_list_1.sort();

  EXPECT_EQ(list_1.Size(), 1);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, sort_05) {
  s21::List<double> list_1;
  std::list<double> orignal_list_1;

  list_1.Sort();
  orignal_list_1.sort();

  EXPECT_EQ(list_1.Size(), 0);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, merge_01) {
  s21::List<double> list_1({27, 0.1, 3, 15, -100, 0.2, 70, 8.8, 0});
  s21::List<double> list_2({40, 30, 10});
  EXPECT_EQ(list_1.Size(), 9);
  EXPECT_EQ(list_2.Size(), 3);

  list_1.Merge(list_2);

  EXPECT_EQ(list_1.Size(), 12);
  EXPECT_EQ(list_2.Size(), 0);

  std::list<double> orignal_list_1({27, 0.1, 3, 15, -100, 0.2, 70, 8.8, 0});
  std::list<double> orignal_list_2({40, 30, 10});
  orignal_list_1.merge(orignal_list_2);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  auto it_3 = list_2.Begin();
  auto it_4 = orignal_list_2.begin();
  for (; it_3 != list_2.End(); ++it_3) {
    EXPECT_DOUBLE_EQ(*it_3, *it_4);
    ++it_4;
  }
}

TEST(list_test, merge_02) {
  s21::List<double> list_1({27, 0.1, 3, 15, -100, 0.2, 70, 8.8, 0});
  s21::List<double> list_2;
  EXPECT_EQ(list_1.Size(), 9);
  EXPECT_EQ(list_2.Size(), 0);

  list_1.Merge(list_2);

  EXPECT_EQ(list_1.Size(), 9);
  EXPECT_EQ(list_2.Size(), 0);

  std::list<double> orignal_list_1({27, 0.1, 3, 15, -100, 0.2, 70, 8.8, 0});
  std::list<double> orignal_list_2;
  orignal_list_1.merge(orignal_list_2);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  auto it_3 = list_2.Begin();
  auto it_4 = orignal_list_2.begin();
  for (; it_3 != list_2.End(); ++it_3) {
    EXPECT_DOUBLE_EQ(*it_3, *it_4);
    ++it_4;
  }
}

TEST(list_test, merge_03) {
  s21::List<double> list_1({1, 3, 5});
  s21::List<double> list_2({2, 4, 6});
  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_2.Size(), 3);

  list_1.Merge(list_2);

  EXPECT_EQ(list_1.Size(), 6);
  EXPECT_EQ(list_2.Size(), 0);

  std::list<double> orignal_list_1({1, 3, 5});
  std::list<double> orignal_list_2({2, 4, 6});
  orignal_list_1.merge(orignal_list_2);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  auto it_3 = list_2.Begin();
  auto it_4 = orignal_list_2.begin();
  for (; it_3 != list_2.End(); ++it_3) {
    EXPECT_DOUBLE_EQ(*it_3, *it_4);
    ++it_4;
  }
}

TEST(list_test, merge_04) {
  s21::List<double> list_1;
  s21::List<double> list_2({2, 4, 6});
  EXPECT_EQ(list_1.Size(), 0);
  EXPECT_EQ(list_2.Size(), 3);

  list_1.Merge(list_2);

  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_2.Size(), 0);

  std::list<double> orignal_list_1;
  std::list<double> orignal_list_2({2, 4, 6});
  orignal_list_1.merge(orignal_list_2);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
  auto it_3 = list_2.Begin();
  auto it_4 = orignal_list_2.begin();
  for (; it_3 != list_2.End(); ++it_3) {
    std::cout << *it << " " << *it_2 << std::endl;
    EXPECT_DOUBLE_EQ(*it_3, *it_4);
    ++it_4;
  }
}

TEST(list_test, unique) {
  s21::List<double> list_1({100, 100, 100, 15, 100, 2, 2, 7, 7, 7, 7});
  std::list<double> orignal_list_1({100, 100, 100, 15, 100, 2, 2, 7, 7, 7, 7});
  EXPECT_EQ(list_1.Size(), 11);
  //  EXPECT_EQ(original.size(), 11);

  list_1.Unique();
  orignal_list_1.unique();

  EXPECT_EQ(list_1.Size(), 5);
  EXPECT_EQ(orignal_list_1.size(), 5);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();

  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, unique_02) {
  s21::List<double> list_1({100, 100});
  std::list<double> orignal_list_1({100, 100});
  EXPECT_EQ(list_1.Size(), 2);
  EXPECT_EQ(orignal_list_1.size(), 2);

  list_1.Unique();
  orignal_list_1.unique();

  EXPECT_EQ(list_1.Size(), 1);
  EXPECT_EQ(orignal_list_1.size(), 1);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();

  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, unique_03) {
  s21::List<double> list_1({100});
  std::list<double> orignal_list_1({100});
  EXPECT_EQ(list_1.Size(), 1);
  EXPECT_EQ(orignal_list_1.size(), 1);

  list_1.Unique();
  orignal_list_1.unique();

  EXPECT_EQ(list_1.Size(), 1);
  EXPECT_EQ(orignal_list_1.size(), 1);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();

  for (; it != list_1.End(); ++it) {
    EXPECT_DOUBLE_EQ(*it, *it_2);
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
};

TEST(list_test, test_emplace) {
  s21::List<President> list_1;
  std::list<President> orignal_list_1;
  EXPECT_EQ(list_1.Size(), 0);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  list_1.EmplaceBack("Nelson Mandela", "South Africa", 1994);
  orignal_list_1.emplace_back("Nelson Mandela", "South Africa", 1994);

  EXPECT_EQ(list_1.Size(), 1);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  s21::List<President> list_2;
  std::list<President> orignal_list_2;
  EXPECT_EQ(list_2.Size(), 0);
  EXPECT_EQ(list_2.Size(), orignal_list_2.size());

  list_2.EmplaceBack(President("Franklin Delano Roosevelt", "the USA", 1936));
  orignal_list_2.emplace_back(
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

  EXPECT_EQ(list_1.Size(), 1);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  list_1.EmplaceFront("Lionel Messi", "Barcelona", 2010);
  orignal_list_1.emplace_front("Lionel Messi", "Barcelona", 2010);

  EXPECT_EQ(list_1.Size(), 2);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  EXPECT_EQ(list_1.Size(), 2);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  list_1.EmplaceFront("Franklin Delano Roosevelt", "the USA", 1936);
  orignal_list_1.emplace_front("Franklin Delano Roosevelt", "the USA", 1936);

  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End() && it_2 != orignal_list_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  ++it;
  ++it_2;

  it = list_1.Emplace(it, "Cristiano Ronaldo", "Real Madrid", 2016);
  it_2 = orignal_list_1.emplace(it_2, "Cristiano Ronaldo", "Real Madrid", 2016);

  EXPECT_EQ((*it).name, (*it_2).name);
  EXPECT_EQ((*it).country, (*it_2).country);
  EXPECT_EQ((*it).year, (*it_2).year);

  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End() && it_2 != orignal_list_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();

  it = list_1.Emplace(it, "Luka Modrić", "Real Madrid", 2018);
  it_2 = orignal_list_1.emplace(it_2, "Luka Modrić", "Real Madrid", 2018);

  EXPECT_EQ((*it).name, (*it_2).name);
  EXPECT_EQ((*it).country, (*it_2).country);
  EXPECT_EQ((*it).year, (*it_2).year);

  EXPECT_EQ(list_1.Size(), 5);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End() && it_2 != orignal_list_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }

  it = list_1.End();
  it_2 = orignal_list_1.end();

  it = list_1.Emplace(it, "Karim Benzema", "Real Madrid", 2022);
  it_2 = orignal_list_1.emplace(it_2, "Karim Benzema", "Real Madrid", 2022);

  EXPECT_EQ((*it).name, (*it_2).name);
  EXPECT_EQ((*it).country, (*it_2).country);
  EXPECT_EQ((*it).year, (*it_2).year);

  EXPECT_EQ(list_1.Size(), 6);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End() && it_2 != orignal_list_1.end(); ++it) {
    EXPECT_EQ((*it).name, (*it_2).name);
    EXPECT_EQ((*it).country, (*it_2).country);
    EXPECT_EQ((*it).year, (*it_2).year);
    ++it_2;
  }
}

TEST(list_test, splice_01) {
  s21::List<double> list_1({27, 0.1, 3, 15, -100, 0.2, 70, 8.8, 0});
  s21::List<double> list_2({40, 30, 10});
  EXPECT_EQ(list_1.Size(), 9);
  EXPECT_EQ(list_2.Size(), 3);

  auto it = list_1.Begin();
  ++it;
  list_1.Splice(it, list_2);

  EXPECT_EQ(list_1.Size(), 12);
  EXPECT_EQ(list_2.Size(), 0);

  std::list<double> orignal_list_1({27, 0.1, 3, 15, -100, 0.2, 70, 8.8, 0});
  std::list<double> orignal_list_2({40, 30, 10});

  auto it_2 = orignal_list_1.begin();
  ++it_2;
  orignal_list_1.splice(it_2, orignal_list_2);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  EXPECT_EQ(list_2.Size(), orignal_list_2.size());
  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
  auto it_3 = list_2.Begin();
  auto it_4 = orignal_list_2.begin();
  for (; it_3 != list_2.End(); ++it_3) {
    EXPECT_EQ(*it_3, *it_4);
    ++it_4;
  }
}

TEST(list_test, splice_02) {
  s21::List<double> list_1({27, 0.1, 3});
  s21::List<double> list_2({40, 30, 10});
  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_2.Size(), 3);

  auto it = list_1.Begin();
  ++it;
  ++it;
  list_1.Splice(it, list_2);

  EXPECT_EQ(list_1.Size(), 6);
  EXPECT_EQ(list_2.Size(), 0);

  std::list<double> orignal_list_1({27, 0.1, 3});
  std::list<double> orignal_list_2({40, 30, 10});

  auto it_2 = orignal_list_1.begin();
  ++it_2;
  ++it_2;
  orignal_list_1.splice(it_2, orignal_list_2);

  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  EXPECT_EQ(list_2.Size(), orignal_list_2.size());
  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
  auto it_3 = list_2.Begin();
  auto it_4 = orignal_list_2.begin();
  for (; it_3 != list_2.End(); ++it_3) {
    EXPECT_EQ(*it_3, *it_4);
    ++it_4;
  }
}

TEST(list_test, erase_01) {
  s21::List<char> list_1({'t'});
  std::list<char> orignal_list_1({'t'});

  EXPECT_EQ(list_1.Size(), 1);
  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 't');

  auto it = list_1.Begin();
  auto it_2 = orignal_list_1.begin();
  list_1.Erase(it);
  orignal_list_1.erase(it_2);

  EXPECT_EQ(list_1.Size(), 0);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, erase_02) {
  s21::List<char> list_1({'t', 'w'});
  std::list<char> orignal_list_1({'t', 'w'});

  EXPECT_EQ(list_1.Size(), 2);
  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 'w');

  auto it = list_1.Begin();
  ++it;
  auto it_2 = orignal_list_1.begin();
  ++it_2;
  list_1.Erase(it);
  orignal_list_1.erase(it_2);

  EXPECT_EQ(list_1.Size(), 1);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, erase_03) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  std::list<char> orignal_list_1({'t', 'w', 't', 'r'});

  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 'r');

  auto it = list_1.Begin();
  ++it;
  ++it;
  auto it_2 = orignal_list_1.begin();
  ++it_2;
  ++it_2;
  list_1.Erase(it);
  orignal_list_1.erase(it_2);

  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, erase_04) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  std::list<char> orignal_list_1({'t', 'w', 't', 'r'});

  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 'r');

  auto it = list_1.End();
  auto it_2 = orignal_list_1.end();
  list_1.Erase(--it);
  orignal_list_1.erase(--it_2);

  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 't');
  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); ++it) {
    EXPECT_EQ(*it, *it_2);
    ++it_2;
  }
}

TEST(list_test, other_test) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  std::list<char> orignal_list_1({'t', 'w', 't', 'r'});

  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 'r');

  auto it = list_1.End();
  auto it_2 = orignal_list_1.end();
  it--;
  list_1.Erase(it);
  it_2--;
  orignal_list_1.erase(it_2);

  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 't');
  EXPECT_EQ(list_1.Size(), 3);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); it++) {
    EXPECT_EQ(*it, *it_2);
    it_2++;
  }
}

TEST(list_test, other_test_02) {
  s21::List<char> list_1({'t', 'w', 't', 'r'});
  std::list<char> orignal_list_1({'t', 'w', 't', 'r'});

  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 'r');

  s21::List<char>::const_iterator it = list_1.End();
  auto it_2 = orignal_list_1.end();

  ++it;
  EXPECT_EQ(*it, 't');
  it--;
  EXPECT_EQ(*it, '\0');
  --it;
  EXPECT_EQ(*it, 'r');

  EXPECT_EQ(list_1.Front(), 't');
  EXPECT_EQ(list_1.Back(), 'r');
  EXPECT_EQ(list_1.Size(), 4);
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); it++) {
    EXPECT_EQ(*it, *it_2);
    it_2++;
  }
}

TEST(List, test_empty_insert) {
  s21::List<int> list_1;
  std::list<int> orignal_list_1;
  s21::List<int>::iterator it = list_1.Begin();
  std::list<int>::iterator it_2 = orignal_list_1.begin();
  it = list_1.Insert(it, 666);
  it_2 = orignal_list_1.insert(it_2, 666);
  ASSERT_EQ(*it, *it_2);
  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End(); it++) {
    EXPECT_EQ(*it, *it_2);
    it_2++;
  }
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
  EXPECT_EQ(list_1.Empty(), orignal_list_1.empty());
}

TEST(list_test, test_const_iter) {
  s21::List<int> list_1({50, 20, 75, 10, 11});
  std::list<int> orignal_list_1({50, 20, 75, 10, 11});

  s21::List<int>::const_iterator it = list_1.Cbegin();
  std::list<int>::const_iterator it_2 = orignal_list_1.cbegin();
  EXPECT_EQ(*it, *it_2);
}

TEST(list_test, test_const_iter_empty) {
  s21::List<int> list_1;
  std::list<int> orignal_list_1;

  s21::List<int>::const_iterator it = list_1.Cbegin();
  std::list<int>::const_iterator it_2 = orignal_list_1.cbegin();
  EXPECT_EQ(*it, *it_2);
}

TEST(list_test, test_iter_end) {
  s21::List<int> list_1({50, 20, 75, 10, 11});
  std::list<int> orignal_list_1({50, 20, 75, 10, 11});

  s21::List<int>::iterator it = list_1.End();
  std::list<int>::iterator it_2 = orignal_list_1.end();
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(list_test, test_iter_end_empty) {
  s21::List<int> list_1;
  std::list<int> orignal_list_1;

  s21::List<int>::iterator it = list_1.End();
  std::list<int>::iterator it_2 = orignal_list_1.end();
  EXPECT_EQ(*it, *it_2);

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  --it;
  it--;
  it = list_1.End();
  ++it;
  it++;
}

TEST(list_test, test_const_iter_end_empty) {
  s21::List<int> list_1;
  std::list<int> orignal_list_1;

  s21::List<int>::const_iterator it = list_1.Cend();
  std::list<int>::const_iterator it_2 = orignal_list_1.cend();
  EXPECT_EQ(*it, *it_2);

  it = list_1.Cbegin();
  --it;
  it--;
  it = list_1.Cend();
  ++it;
  it++;
}

TEST(list_test, test_const_iter_end_pref) {
  s21::List<int> list_1({50, 20, 75, 10, 11});
  std::list<int> orignal_list_1({50, 20, 75, 10, 11});

  s21::List<int>::const_iterator it = list_1.Cend();
  std::list<int>::const_iterator it_2 = orignal_list_1.end();
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
  --it;
  --it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(list_test, test_const_iter_begin_pref) {
  s21::List<int> list_1({50, 20, 75, 10, 11});
  std::list<int> orignal_list_1({50, 20, 75, 10, 11});

  s21::List<int>::const_iterator it = list_1.Cbegin();
  std::list<int>::const_iterator it_2 = orignal_list_1.cbegin();
  ++it;
  ++it_2;
  EXPECT_EQ(*it, *it_2);
  ++it;
  ++it_2;
  EXPECT_EQ(*it, *it_2);
}

TEST(list_test, test_const_iter_end_post) {
  s21::List<int> list_1({50, 20, 75, 10, 11});
  std::list<int> orignal_list_1({50, 20, 75, 10, 11});

  s21::List<int>::const_iterator it = list_1.Cend();
  std::list<int>::const_iterator it_2 = orignal_list_1.end();
  it--;
  it_2--;
  EXPECT_EQ(*it, *it_2);
  it--;
  it_2--;
  EXPECT_EQ(*it, *it_2);
}

TEST(list_test, test_const_iter_begin_post) {
  s21::List<int> list_1({50, 20, 75, 10, 11});
  std::list<int> orignal_list_1({50, 20, 75, 10, 11});

  s21::List<int>::const_iterator it = list_1.Cbegin();
  std::list<int>::const_iterator it_2 = orignal_list_1.cbegin();
  it++;
  it_2++;
  EXPECT_EQ(*it, *it_2);
  it++;
  it_2++;
  EXPECT_EQ(*it, *it_2);
}

TEST(list_test, test_iter_plus) {
  s21::List<int> list_1({50, 20, 75, 10, 11});
  std::list<int> orignal_list_1({50, 20, 75, 10, 11});

  s21::List<int>::iterator it = list_1.Begin();
  std::list<int>::iterator it_2 = orignal_list_1.begin();
  for (; it != list_1.End() && it_2 != orignal_list_1.end();) {
    EXPECT_EQ(*it, *it_2);
    ++it;
    ++it_2;
  }
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  for (; it != list_1.End() && it_2 != orignal_list_1.end();) {
    EXPECT_EQ(*it, *it_2);
    it++;
    it_2++;
  }
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());
}

TEST(list_test, test_iter_minus) {
  s21::List<int> list_1({50, 20, 75, 10, 11});
  std::list<int> orignal_list_1({50, 20, 75, 10, 11});

  s21::List<int>::iterator it = list_1.End();
  std::list<int>::iterator it_2 = orignal_list_1.end();
  for (; it != list_1.Begin() && it_2 != orignal_list_1.begin();) {
    --it;
    --it_2;
    EXPECT_EQ(*it, *it_2);
  }
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.End();
  it_2 = orignal_list_1.end();
  for (; it != list_1.Begin() && it_2 != orignal_list_1.begin();) {
    it--;
    it_2--;
    EXPECT_EQ(*it, *it_2);
  }
  EXPECT_EQ(list_1.Size(), orignal_list_1.size());

  it = list_1.Begin();
  it_2 = orignal_list_1.begin();
  --it;
  --it_2;
  it--;
  it_2--;
  it = list_1.End();
  it_2 = orignal_list_1.end();
  ++it;
  ++it_2;
  it++;
  it_2++;
}
