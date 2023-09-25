#include "../Includes/Containers/s21_queue.h"

#include <gtest/gtest.h>

#include <queue>

TEST(queue_test, back_test) {
  EXPECT_NO_THROW({
    std::queue<int> q;
    s21::Queue<int> mq;

    for (int i = 0; i < 10; i++) {
      q.push(i);
      mq.Push(i);
    }

    EXPECT_EQ(q.back(), mq.Back());
  });
}

TEST(queue_test, front_test) {
  EXPECT_NO_THROW({
    std::queue<int> q;
    s21::Queue<int> mq;

    q.push(4);
    mq.Push(4);

    EXPECT_EQ(q.front(), mq.Front());
  });
}

TEST(queue_test, swap_test) {
  EXPECT_NO_THROW({
    std::queue<int> q;
    std::queue<int> q2;
    s21::Queue<int> mq;
    s21::Queue<int> mq2;
    for (int i = 0; i < 10; i++) {
      q.push(i);
      mq.Push(i);
    }

    for (int i = 50; i < 60; i++) {
      q2.push(i);
      mq2.Push(i);
    }

    q.swap(q2);
    mq.Swap(mq2);

    for (size_t i = 0; i < q.size(); i++) {
      EXPECT_EQ(q.front(), mq.Front());
      q.pop();
      mq.Pop();
    }
  });
}

TEST(queue_test, string_test) {
  EXPECT_NO_THROW({
    std::queue<std::string> q;
    s21::Queue<std::string> mq;
    std::string text = "Hello! I'm inside of queue test!";
    q.push(text);
    mq.Push(text);

    EXPECT_EQ(q.front(), mq.Front());
  });
}

TEST(queue_test, long_double_test) {
  EXPECT_NO_THROW({
    std::queue<long double> q;
    s21::Queue<long double> mq;
    q.push(31342.256356);
    mq.Push(31342.256356);

    EXPECT_DOUBLE_EQ(q.back(), mq.Back());
  });
}

TEST(queue_test, pop_test) {
  EXPECT_NO_THROW({
    std::queue<int> q;
    s21::Queue<int> mq;

    for (int i = 0; i < 20; i++) {
      q.push(i);
      mq.Push(i);
    }

    for (int i = 0; i < 10; i++) {
      q.pop();
      mq.Pop();
    }

    EXPECT_EQ(q.back(), mq.Back());
  });
}

TEST(queue_test, long_size_test) {
  EXPECT_NO_THROW({
    std::queue<int> q;
    s21::Queue<int> mq;

    for (int i = 0; i < 50000; i++) {
      q.push(i);
      mq.Push(i);
      EXPECT_EQ(q.back(), mq.Back());
    }

    EXPECT_EQ(q.back(), mq.Back());
  });
}

TEST(queue_test, copy_operator) {
  s21::Queue<int> obj1 = {1, 2, 3, 4, 5};
  s21::Queue<int> obj2;
  obj2 = obj1;
  EXPECT_EQ(obj2.Back(), 5);
}

TEST(queue_test, move_constructor) {
  s21::Queue<int> obj1 = {1, 2, 3, 4, 5};
  s21::Queue<int> obj2 = std::move(obj1);
  EXPECT_EQ(obj2.Back(), 5);
}

TEST(queue_test, move_operator) {
  s21::Queue<int> obj1 = {1, 2, 3, 4, 5};
  s21::Queue<int> obj2;
  obj2 = std::move(obj1);
  EXPECT_EQ(obj2.Back(), 5);
}

TEST(queue_test, greater_test) {
  std::queue<int> q;
  s21::Queue<int> mq;
  q.push(63);
  mq.Push(45);

  EXPECT_GT(q.back(), mq.Back());
}

TEST(queue_test, back_front) {
  s21::Queue<int> q = {256, 0, 0, 512};
  EXPECT_EQ(q.Front(), 256);
  EXPECT_EQ(q.Back(), 512);
}

TEST(queue_test, front_push_test) {
  s21::Queue<int> q = {12, 24, 48, 100, 200};
  std::queue<int> stdq;
  stdq.push(12);
  stdq.push(24);
  stdq.push(48);
  stdq.push(100);
  stdq.push(200);

  for (size_t i = 0; i < q.Size(); i++) {
    EXPECT_EQ(q.Front(), stdq.front());
    q.Pop();
    stdq.pop();
  }
}

TEST(queue_test, emplace_test) {
  struct a {
    a() {}
    a(int age, std::string name) {
      this->age = age;
      this->name = name;
    }
    int age;
    std::string name;
  };

  s21::Queue<a> queue;
  queue.EmplaceBack(15, "hello");
  a obj = queue.Back();

  EXPECT_EQ(obj.age, 15);
  EXPECT_STREQ(obj.name.c_str(), "hello");
}
