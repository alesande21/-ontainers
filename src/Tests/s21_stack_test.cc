#include "../Includes/Containers/s21_stack.h"

#include <gtest/gtest.h>

#include <stack>

TEST(stack_test, test1) {
  EXPECT_NO_THROW({
    std::stack<int> s;
    s21::Stack<int> ms;
    int push_value = 0;

    for (int i = 0; i < 10; i++) {
      push_value = i * 25;
      s.push(push_value);
      ms.Push(push_value);
    }

    EXPECT_EQ(s.top(), ms.Top());
  });
}

TEST(stack_test, test2) {
  EXPECT_NO_THROW({
    std::stack<std::string> s;
    s21::Stack<std::string> ms;
    std::string str =
        "Hello! I'm in stack and it's a tests for stack. Love you!";
    s.push(str);
    ms.Push(str);

    EXPECT_EQ(s.top(), ms.Top());
  });
}

TEST(stack_test, test3) {
  EXPECT_NO_THROW({
    std::stack<int> s;
    s21::Stack<int> ms;

    EXPECT_EQ(s.empty(), ms.Empty());
  });
}

TEST(stack_test, test4) {
  EXPECT_NO_THROW({
    std::stack<int> s;
    s21::Stack<int> ms;

    s.push(-2134567);
    ms.Push(-2134567);

    EXPECT_EQ(s.top(), ms.Top());
  });
}

TEST(stack_test, test5) {
  EXPECT_NO_THROW({
    std::stack<int> s;
    s21::Stack<int> ms;

    for (int i = 0; i < 50000; i++) {
      s.push(i);
      ms.Push(i);
    }

    EXPECT_EQ(s.top(), ms.Top());
  });
}

TEST(stack_test, test6) {
  EXPECT_NO_THROW({
    std::stack<int> s;
    s21::Stack<int> ms;

    for (int i = 0; i < 50000; i++) {
      s.push(i);
      ms.Push(i);
    }

    EXPECT_EQ(s.size(), ms.Size());
  });
}

TEST(stack_test, test7) {
  EXPECT_NO_THROW({
    std::stack<int> s;
    s21::Stack<int> ms;

    for (int i = 0; i < 10000; i++) {
      s.push(i);
      ms.Push(i);
    }

    for (int i = 0; i < 5000; i++) {
      s.pop();
      ms.Pop();
      EXPECT_EQ(s.top(), ms.Top());
    }
  });
}

TEST(stack_test, test8) {
  srand(time(NULL));
  struct s_tmp {
    int x;
    float y;
    std::string z;
  };
  std::stack<s_tmp> s;
  s21::Stack<s_tmp> ms;

  for (int i = 0; i < 200; i++) {
    int x = rand() % 256;
    float y = rand() % 256 - ((rand() % 100) / 100);
    std::string rand_str;
    for (int i = 0; i < 32; i++) {
      rand_str.push_back(rand() % 26 + 'a');
    }
    EXPECT_NO_THROW({
      s.push({x, y, rand_str});
      ms.Push({x, y, rand_str});
    });
  }
}

TEST(stack_test, test9) {
  s21::Stack<int> obj = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21::Stack<int> obj_two = obj;
  for (int i = 0; i < 3; i++) obj_two.Pop();
  EXPECT_EQ(obj_two.Top(), 6);
}
