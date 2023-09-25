#ifndef SRC_INCLUDES_CONTAINERS_S21_ARRAY_H
#define SRC_INCLUDES_CONTAINERS_S21_ARRAY_H

#include <initializer_list>
#include <iostream>

#include "../Iterators/s21_sequential_iterator.h"
namespace s21 {
template <typename T, size_t N>
class Array {
 public:
  typedef SequentialIterator<T> s21_iterator;

  Array();
  Array(std::initializer_list<T> const& items);
  Array(const Array& a);
  Array(Array&& a);
  ~Array();

  void operator=(Array&& a);
  void operator=(Array& a);

  T& At(size_t pos);
  T At(size_t pos) const;

  T& operator[](size_t pos);
  T operator[](size_t pos) const;

  const T& Front();
  const T& Back();

  s21_iterator Data();
  s21_iterator Begin();
  s21_iterator End();

  inline bool Empty() const noexcept;
  inline size_t Size() const noexcept;
  inline size_t MaxSize() const noexcept;

  inline void Swap(Array& other);
  inline void Fill(const T& value);

 private:
  size_t arr_size{N};
  T arr_data[N]{};
};
};  // namespace s21

template <typename T, size_t N>
s21::Array<T, N>::Array() {}

template <typename T, size_t N>
s21::Array<T, N>::Array(std::initializer_list<T> const& items)
    : arr_size{items.size()} {
  if (items.size() > arr_size)
    throw std::invalid_argument("Initialization list is greater than array");
  std::copy(items.begin(), items.end(), arr_data);
}

template <typename T, size_t N>
s21::Array<T, N>::Array(const Array& a) {
  if (a.arr_size != arr_size)
    throw std::invalid_argument("Arrays are not equal");
  if (this != &a) {
    arr_size = a.arr_size;
    std::copy(a.arr_data, a.arr_data + a.arr_size, arr_data);
  }
}

template <typename T, size_t N>
s21::Array<T, N>::Array(Array&& a) {
  if (a.arr_size != arr_size)
    throw std::invalid_argument("Arrays are not equal");
  if (this != &a) {
    arr_size = 0;
    std::swap(arr_size, a.arr_size);
    std::swap(arr_data, a.arr_data);
  }
}

template <typename T, size_t N>
s21::Array<T, N>::~Array() {
  arr_size = 0;
}

template <typename T, size_t N>
void s21::Array<T, N>::operator=(Array&& a) {
  if (a.arr_size != arr_size)
    throw std::invalid_argument("Arrays are not equal");
  if (this != &a) {
    arr_size = 0;
    std::swap(arr_size, a.arr_size);
    std::swap(arr_data, a.arr_data);
  }
}

template <typename T, size_t N>
void s21::Array<T, N>::operator=(Array& a) {
  if (a.arr_size != arr_size)
    throw std::invalid_argument("Arrays are not equal");
  if (this != &a) {
    arr_size = a.arr_size;
    std::copy(a.arr_data, a.arr_data + arr_size, arr_data);
  }
}

template <typename T, size_t N>
T& s21::Array<T, N>::At(size_t pos) {
  if (pos >= arr_size) throw std::out_of_range("Out of range!");
  return arr_data[pos];
}

template <typename T, size_t N>
T s21::Array<T, N>::At(size_t pos) const {
  if (pos >= arr_size) throw std::out_of_range("Out of range!");
  return arr_data[pos];
}

template <typename T, size_t N>
T& s21::Array<T, N>::operator[](size_t pos) {
  return arr_data[pos];
}

template <typename T, size_t N>
T s21::Array<T, N>::operator[](size_t pos) const {
  return arr_data[pos];
}

template <typename T, size_t N>
inline const T& s21::Array<T, N>::Front() {
  return arr_data[0];
}

template <typename T, size_t N>
inline const T& s21::Array<T, N>::Back() {
  return arr_data[arr_size - 1];
}

template <typename T, size_t N>
inline bool s21::Array<T, N>::Empty() const noexcept {
  return !arr_size;
}

template <typename T, size_t N>
inline size_t s21::Array<T, N>::Size() const noexcept {
  return arr_size;
}

template <typename T, size_t N>
inline size_t s21::Array<T, N>::MaxSize() const noexcept {
  return arr_size;
}

template <typename T, size_t N>
inline void s21::Array<T, N>::Swap(Array& other) {
  if (arr_size != other.arr_size)
    throw std::invalid_argument("Arrays are not equal");
  if (this != &other) {
    std::swap(arr_data, other.arr_data);
    std::swap(arr_size, other.arr_size);
  }
}

template <typename T, size_t N>
inline void s21::Array<T, N>::Fill(const T& value) {
  std::fill(arr_data, arr_data + arr_size, value);
}

template <typename T, size_t N>
inline SequentialIterator<T> s21::Array<T, N>::Data() {
  s21_iterator new_it(arr_data);
  return new_it;
}

template <typename T, size_t N>
inline SequentialIterator<T> s21::Array<T, N>::Begin() {
  s21_iterator new_it(arr_data);
  return new_it;
}

template <typename T, size_t N>
inline SequentialIterator<T> s21::Array<T, N>::End() {
  s21_iterator new_it(arr_data + arr_size);
  return new_it;
}

#endif  //  SRC_INCLUDES_CONTAINERS_S21_ARRAY_H