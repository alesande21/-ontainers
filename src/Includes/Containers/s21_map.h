//
// Created by Slava on 01.05.2023.
//
#ifndef CPP2_S21_CONTAINERS_1_DEVELOP_SLAVA_REF_MAP_H
#define CPP2_S21_CONTAINERS_1_DEVELOP_SLAVA_REF_MAP_H

#include <cmath>
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

#include "s21_tree.h"

namespace s21 {
template <class KEY, class T, class Compare = std::less<KEY>>
class Map {
 public:
  using key_type = KEY;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  class Value_compare {
   public:
    bool operator()(const value_type& lhs,
                    const value_type& rhs) const noexcept {
      return comp(lhs.first, rhs.first);
    }

    Value_compare() : comp(Compare()) {}

    Compare comp{};
  };
  using tree_type = Tree<value_type, Value_compare>;
  using iterator = typename tree_type::iterator;
  using const_iterator = typename tree_type::const_iterator;

  Map() : tree_(new tree_type{}){};
  Map(std::initializer_list<value_type> const& list);
  Map(const Map& other);
  Map(Map&& other) noexcept;
  ~Map();

  Map& operator=(Map&& other) noexcept;
  Map& operator=(const Map& other);
  mapped_type& operator[](const KEY& key);

  mapped_type& At(const KEY& key);
  std::pair<iterator, bool> Insert(value_type value);
  std::pair<iterator, bool> Insert(const KEY& key, const T& obj);
  std::pair<iterator, bool> InsertOrAssign(const KEY& key, const T& obj);

  bool Contains(const KEY& key);
  size_type Size() const noexcept;
  size_type MaxSize() const noexcept;

  bool Empty() const noexcept;
  void Clear() noexcept;
  void Swap(Map& other) noexcept;
  void Erase(iterator pos);
  void Merge(Map& other) noexcept;

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> Emplace(Args&&... args);

  inline iterator Begin() noexcept;
  inline const_iterator Cbegin() const noexcept;
  inline iterator End() noexcept;
  inline const_iterator Cend() const noexcept;

  inline iterator Rbegin() noexcept;
  inline const_iterator Crbegin() const noexcept;
  inline iterator Rend() noexcept;
  inline const_iterator Crend() const noexcept;

  inline iterator Root() noexcept;

  // For tests
  void Advance(iterator& pos, long long int n) const;
  bool IsBalanced() const;

 private:
  Tree<value_type, Value_compare>* tree_;
};
}  // namespace s21

template <class KEY, class T, class Compare>
s21::Map<KEY, T, Compare>::Map(const std::initializer_list<value_type>& list)
    : Map() {
  for (auto var : list) {
    tree_->Insert(var);
  }
}

template <class KEY, class T, class Compare>
s21::Map<KEY, T, Compare>::Map(const Map& other) : Map() {
  if (!other.Empty()) {
    delete tree_;
    tree_ = nullptr;
    tree_ = new tree_type(*other.tree_);
  }
}

template <class KEY, class T, class Compare>
s21::Map<KEY, T, Compare>::Map(Map&& other) noexcept : Map() {
  if (tree_ != other.tree_) {
    delete tree_;
    tree_ = nullptr;
    tree_ = new tree_type(std::move(*other.tree_));
  }
}

template <class KEY, class T, class Compare>
s21::Map<KEY, T, Compare>::~Map() {
  delete tree_;
  tree_ = nullptr;
}

template <class KEY, class T, class Compare>
s21::Map<KEY, T, Compare>& s21::Map<KEY, T, Compare>::operator=(
    Map&& other) noexcept {
  *tree_ = std::move(*other.tree_);
  return *this;
}

template <class KEY, class T, class Compare>
s21::Map<KEY, T, Compare>& s21::Map<KEY, T, Compare>::operator=(
    const Map& other) {
  *tree_ = *other.tree_;
  return *this;
}

template <class KEY, class T, class Compare>
T& s21::Map<KEY, T, Compare>::At(const KEY& key) {
  auto n = tree_->Contains({key, mapped_type{}});
  if (!n.second) {
    throw std::out_of_range("Out of range Map::at");
  }
  return n.first.operator*().second;
}

template <class KEY, class T, class Compare>
T& s21::Map<KEY, T, Compare>::operator[](const KEY& key) {
  auto search_element = tree_->Contains({key, mapped_type{}});
  if (!search_element.second) {
    return tree_->Insert({key, mapped_type{}}).first.operator*().second;
  }
  return search_element.first.operator*().second;
};

template <class KEY, class T, class Compare>
std::pair<typename s21::Map<KEY, T, Compare>::iterator, bool>
s21::Map<KEY, T, Compare>::Insert(value_type value) {
  return tree_->Insert(value);
}

template <class KEY, class T, class Compare>
std::pair<typename s21::Map<KEY, T, Compare>::iterator, bool>
s21::Map<KEY, T, Compare>::Insert(const KEY& key, const T& obj) {
  return tree_->Insert({key, obj});
}

template <class KEY, class T, class Compare>
std::pair<typename s21::Map<KEY, T, Compare>::iterator, bool>
s21::Map<KEY, T, Compare>::InsertOrAssign(const KEY& key, const T& obj) {
  std::pair<iterator, bool> result_insert = this->Insert(key, obj);
  if (!result_insert.second) {
    (*this)[key] = obj;
  }
  return result_insert;
}

template <class KEY, class T, class Compare>
bool s21::Map<KEY, T, Compare>::Contains(const KEY& key) {
  return tree_->Contains({key, mapped_type{}}).second;
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::iterator
s21::Map<KEY, T, Compare>::Root() noexcept {
  return tree_->Root();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::iterator
s21::Map<KEY, T, Compare>::Begin() noexcept {
  return tree_->Begin();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::const_iterator
s21::Map<KEY, T, Compare>::Cbegin() const noexcept {
  return tree_->Cbegin();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::iterator
s21::Map<KEY, T, Compare>::End() noexcept {
  return tree_->End();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::const_iterator
s21::Map<KEY, T, Compare>::Cend() const noexcept {
  return tree_->Cend();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::iterator
s21::Map<KEY, T, Compare>::Rbegin() noexcept {
  return tree_->Rbegin();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::const_iterator
s21::Map<KEY, T, Compare>::Crbegin() const noexcept {
  return tree_->Crbegin();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::iterator
s21::Map<KEY, T, Compare>::Rend() noexcept {
  return tree_->Rend();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::const_iterator
s21::Map<KEY, T, Compare>::Crend() const noexcept {
  return tree_->Crend();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::size_type s21::Map<KEY, T, Compare>::Size()
    const noexcept {
  return tree_->Size();
}

template <class KEY, class T, class Compare>
typename s21::Map<KEY, T, Compare>::size_type
s21::Map<KEY, T, Compare>::MaxSize() const noexcept {
  return tree_->MaxSize();
}

template <class KEY, class T, class Compare>
bool s21::Map<KEY, T, Compare>::Empty() const noexcept {
  return tree_->Empty();
}

template <class KEY, class T, class Compare>
void s21::Map<KEY, T, Compare>::Clear() noexcept {
  tree_->Clear();
}

template <class KEY, class T, class Compare>
void s21::Map<KEY, T, Compare>::Swap(Map& other) noexcept {
  tree_->Swap(*other.tree_);
}

template <class KEY, class T, class Compare>
void s21::Map<KEY, T, Compare>::Erase(iterator pos) {
  tree_->Erase(pos);
}

template <class KEY, class T, class Compare>
void s21::Map<KEY, T, Compare>::Merge(Map& other) noexcept {
  tree_->Merge(*other.tree_);
}

template <class KEY, class T, class Compare>
template <typename... Args>
std::vector<std::pair<typename s21::Map<KEY, T, Compare>::iterator, bool>>
s21::Map<KEY, T, Compare>::Emplace(Args&&... args) {
  return tree_->Emplace(std::forward<Args>(args)...);
}

template <class KEY, class T, class Compare>
void s21::Map<KEY, T, Compare>::Advance(iterator& pos, long long int n) const {
  tree_->Advance(pos, n);
}

template <class KEY, class T, class Compare>
bool s21::Map<KEY, T, Compare>::IsBalanced() const {
  return tree_->IsBalanced();
}

#endif  // CPP2_S21_CONTAINERS_1_DEVELOP_SLAVA_REF_MAP_H
