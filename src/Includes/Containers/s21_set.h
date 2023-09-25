//
// Created by slava on 02.05.2023.
//
#ifndef CPP2_S21_CONTAINERS_0_MASTER_S21_SET_H
#define CPP2_S21_CONTAINERS_0_MASTER_S21_SET_H
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

#include "s21_tree.h"

namespace s21 {
template <class KEY, class Compare = std::less<KEY>>
class Set {
 public:
  using key_type = KEY;
  using value_type = const KEY;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using tree_type = Tree<value_type, Compare>;
  using iterator = typename tree_type::iterator;
  using const_iterator = typename tree_type::const_iterator;

  Set() : tree_(new tree_type{}){};
  Set(std::initializer_list<value_type> const &list);
  Set(const Set &other);
  Set(Set &&other) noexcept;
  ~Set();

  Set &operator=(Set &&other) noexcept;
  Set &operator=(const Set &other);

  bool Empty() const noexcept;
  size_type Size() const noexcept;
  size_type MaxSize() const noexcept;

  void Clear() noexcept;
  std::pair<iterator, bool> Insert(const value_type &value);
  void Erase(iterator pos);
  void Swap(Set &other) noexcept;
  void Merge(Set &other) noexcept;

  bool Contains(const KEY &key);
  iterator Find(const KEY &key);

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> Emplace(Args &&...args);

  inline iterator Begin() noexcept;
  inline const_iterator Cbegin() const noexcept;
  inline iterator End() noexcept;
  inline const_iterator Cend() const noexcept;

  inline iterator Rbegin() noexcept;
  inline const_iterator Crbegin() const noexcept;
  inline iterator Rend() noexcept;
  inline const_iterator Crend() const noexcept;

  // For tests
  void Advance(iterator &pos, long long int n) const;
  bool IsBalanced() const;

 private:
  Tree<value_type, Compare> *tree_;
};

}  // namespace s21

template <class KEY, class Compare>
s21::Set<KEY, Compare>::Set(const std::initializer_list<value_type> &list)
    : Set() {
  for (auto var : list) {
    tree_->Insert(var);
  }
}

template <class KEY, class Compare>
s21::Set<KEY, Compare>::Set(const Set &other) : Set() {
  if (!other.Empty()) {
    delete tree_;
    tree_ = nullptr;
    tree_ = new tree_type(*other.tree_);
  }
}

template <class KEY, class Compare>
s21::Set<KEY, Compare>::Set(Set &&other) noexcept : Set() {
  if (tree_ != other.tree_) {
    delete tree_;
    tree_ = nullptr;
    tree_ = new tree_type(std::move(*other.tree_));
  }
}

template <class KEY, class Compare>
s21::Set<KEY, Compare>::~Set() {
  delete tree_;
  tree_ = nullptr;
}

template <class KEY, class Compare>
s21::Set<KEY, Compare> &s21::Set<KEY, Compare>::operator=(
    Set &&other) noexcept {
  *tree_ = std::move(*other.tree_);
  return *this;
}

template <class KEY, class Compare>
s21::Set<KEY, Compare> &s21::Set<KEY, Compare>::operator=(const Set &other) {
  *tree_ = *other.tree_;
  return *this;
}

template <class KEY, class Compare>
bool s21::Set<KEY, Compare>::Empty() const noexcept {
  return tree_->Empty();
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::size_type s21::Set<KEY, Compare>::Size()
    const noexcept {
  return tree_->Size();
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::size_type s21::Set<KEY, Compare>::MaxSize()
    const noexcept {
  return tree_->MaxSize();
}

template <class KEY, class Compare>
void s21::Set<KEY, Compare>::Clear() noexcept {
  tree_->Clear();
}

template <class KEY, class Compare>
std::pair<typename s21::Set<KEY, Compare>::iterator, bool>
s21::Set<KEY, Compare>::Insert(const value_type &value) {
  return tree_->Insert(value);
}

template <class KEY, class Compare>
void s21::Set<KEY, Compare>::Erase(iterator pos) {
  tree_->Erase(pos);
}

template <class KEY, class Compare>
void s21::Set<KEY, Compare>::Swap(Set &other) noexcept {
  tree_->Swap(*other.tree_);
}

template <class KEY, class Compare>
void s21::Set<KEY, Compare>::Merge(Set &other) noexcept {
  tree_->Merge(*other.tree_);
}

template <class KEY, class Compare>
bool s21::Set<KEY, Compare>::Contains(const KEY &key) {
  return tree_->Contains(key).second;
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::iterator s21::Set<KEY, Compare>::Find(
    const KEY &key) {
  return tree_->Contains(key).first;
}

template <class KEY, class Compare>
template <typename... Args>
std::vector<std::pair<typename s21::Set<KEY, Compare>::iterator, bool>>
s21::Set<KEY, Compare>::Emplace(Args &&...args) {
  return tree_->Emplace(std::forward<Args>(args)...);
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::iterator
s21::Set<KEY, Compare>::Begin() noexcept {
  return tree_->Begin();
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::const_iterator s21::Set<KEY, Compare>::Cbegin()
    const noexcept {
  return tree_->Cbegin();
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::iterator
s21::Set<KEY, Compare>::End() noexcept {
  return tree_->End();
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::const_iterator s21::Set<KEY, Compare>::Cend()
    const noexcept {
  return tree_->Cend();
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::iterator
s21::Set<KEY, Compare>::Rbegin() noexcept {
  return tree_->Rbegin();
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::const_iterator
s21::Set<KEY, Compare>::Crbegin() const noexcept {
  return tree_->Crbegin();
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::iterator
s21::Set<KEY, Compare>::Rend() noexcept {
  return tree_->Rend();
}

template <class KEY, class Compare>
typename s21::Set<KEY, Compare>::const_iterator s21::Set<KEY, Compare>::Crend()
    const noexcept {
  return tree_->Crend();
}

template <class KEY, class Compare>
void s21::Set<KEY, Compare>::Advance(iterator &pos, long long int n) const {
  tree_->Advance(pos, n);
}

template <class KEY, class Compare>
bool s21::Set<KEY, Compare>::IsBalanced() const {
  return tree_->IsBalanced();
}

#endif  // CPP2_S21_CONTAINERS_0_MASTER_S21_SET_H
