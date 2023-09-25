//
// Created by Slava on 30.04.2023.
//
#ifndef CPP2_S21_CONTAINERS_1_DEVELOP_SLAVA_REF_TREE_H
#define CPP2_S21_CONTAINERS_1_DEVELOP_SLAVA_REF_TREE_H

#include <cmath>
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace s21 {
template <class KEY, class Compare = std::less<KEY>>
class Tree {
 private:
  class Element;

 public:
  class TreeIterator;
  class TreeConstIterator;

  using value_type = KEY;
  using reference = KEY &;
  using const_reference = const KEY &;
  using size_type = size_t;
  using iterator = TreeIterator;
  using const_iterator = TreeConstIterator;
  using tree_type = Tree<value_type, Compare>;
  using tree_element = tree_type::Element;
  using difference_type = std::ptrdiff_t;
  using node_alloc = std::allocator<Element>;
  using node_traits = std::allocator_traits<node_alloc>;

  Tree();
  Tree(std::initializer_list<value_type> const &list);
  Tree(const Tree<value_type, Compare> &other);
  Tree(Tree<value_type, Compare> &&other) noexcept;
  virtual ~Tree();

  Tree<value_type, Compare> &operator=(Tree &&other) noexcept;
  Tree<value_type, Compare> &operator=(const Tree &other);

  bool Empty();
  size_type Size() const noexcept;
  size_type MaxSize() const noexcept;

  void Clear() noexcept;
  std::pair<iterator, bool> Insert(value_type data);
  std::pair<iterator, bool> Contains(const value_type &data);
  void Erase(iterator pos);
  void Swap(Tree &other) noexcept;
  void Merge(Tree &other);
  size_type Count(const value_type &key);
  std::pair<iterator, iterator> EqualRange(const KEY &key);
  iterator LowerBound(const KEY &key);
  iterator UpperBound(const KEY &key);

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
  void Advance(TreeIterator &it, long long int n) const;
  bool IsBalanced() const;

  class TreeIterator {
   public:
    using Element = Tree::Element;
    using value_type = Tree::value_type;
    using reference = value_type &;
    using const_reference = const value_type &;
    using iterator = Tree::iterator;

    TreeIterator() = delete;

    TreeIterator(Element *pElement, Element *pElement_max);

    explicit TreeIterator(Element *pElement);

    inline void operator=(Element *new_ptr) { current = new_ptr; }

    inline reference operator*() const;

    inline bool operator!=(const iterator &other) const noexcept {
      return current != other.current;
    }

    inline bool operator==(const iterator &other) const noexcept {
      return current == other.current;
    }

    iterator &operator++() noexcept;

    iterator operator++(int) noexcept;

    iterator &operator--() noexcept;

    iterator operator--(int) noexcept;

   private:
    friend class Tree;
    Element *current{};
    Element *marker{};
  };

  class TreeConstIterator {
   public:
    using Element = Tree::Element;
    using value_type = Tree::value_type;
    using const_reference = const value_type &;
    using const_iterator = Tree::const_iterator;

    TreeConstIterator() = delete;

    TreeConstIterator(Element *pElement, Element *pElement_max);

    explicit TreeConstIterator(Element *pElement);

    inline void operator=(Element *new_ptr) { current = new_ptr; }

    const_reference operator*() const;

    inline bool operator!=(const TreeConstIterator &other) const noexcept {
      return current != other.current;
    }

    inline bool operator==(const TreeConstIterator &other) const noexcept {
      return current == other.current;
    }

    const_iterator &operator++() noexcept;

    const_iterator operator++(int) noexcept;

    const_iterator &operator--() noexcept;

    const_iterator operator--(int) noexcept;

   private:
    friend class Tree;
    const Element *current{};
    const Element *marker{};
  };

 private:
  class Element {
    friend class Tree;

   public:
    Element(const value_type &value = value_type(), bool is_red = bool(),
            Element *parent = nullptr, Element *right_child = nullptr,
            Element *left_child = nullptr)
        : value(value) {  // explicit
      this->is_red = is_red;
      this->parent = parent;
      this->right_child = right_child;
      this->left_child = left_child;
    }

    Element &operator=(const Element &) = delete;
    Element *PreviousElement(Element *n) noexcept;
    const Element *PreviousElement(const Element *n) const noexcept;
    Element *NextElement(Element *n) noexcept;
    const Element *NextElement(const Element *n) const noexcept;
    bool GrandpaPaIsRightChild(const Element *n) const;
    bool GrandpaPaIsLeftChild(const Element *n) const;
    bool GrandpaIsRightChild(const Element *n) const;
    bool GrandpaIsLeftChild(const Element *n) const;

    bool is_red{};
    value_type value{};
    Element *parent{};
    Element *right_child{};
    Element *left_child{};
  };
  Element *root{};
  int count_elements{};
  Compare comp{};

  // insert && rotation
  void ClearElements(Element **n);
  void CopyElements(Element *n);
  std::pair<Element *, bool> InsertStage2(value_type data);
  Element *InsertRightWay(Element *currElement, value_type data);
  Element *InsertLeftWay(Element *currElement, value_type data);
  bool CheckGrGrGrandfather(Element *n, bool left);
  bool UncleIsRed(Element *n, bool left);
  void LeftTurn(Element *n);
  void RightTurn(Element *n);
  void JustLeft(Element *n);
  void JustRight(Element *n);
  void InsideLeftTurn(Element *n);
  void InsideRightTurn(Element *n);
  void ChoosingTheNextPath(Element *n, bool left);

  // delete
  void DeleteCase1(Element *find_data);
  void DeleteCase2(Element *find_data);
  void DeleteCase3(Element *find_data);
  void DeleteStep1(Element *find_data, Element *replaceElement);
  void DeleteStep2(Element *find_data, Element *replaceElement);
  void YesRightChild(Element *find_data);
  void NoRightChild(Element *find_data);
  void Neph(Element *n);
  void CaseBlackSibling(Element *n);
  void ChangeColorToRed(Element *n);
  void ChangeColorBase(Element *n);
  void ChangeColor(Element *n);
  void PushUpBlackLevelLeft(Element *n);
  void PushUpBlackLevelRight(Element *n);
  bool CheckFarRightNephew(Element *n);
  bool CheckCloseRightNephew(Element *n);
  bool CheckFarLeftNephew(Element *n);
  bool CheckCloseLeftNephew(Element *n);
  bool CheckSiblingRight(Element *n);
  bool CheckSiblingLeft(Element *n);
  bool CheckChildfree(Element *n);
  bool IsRightChild(Element *n);
  bool IsLeftChild(Element *n);
  Element *FindElementToReplace(Element *n);
  Element *MinimumElement() const noexcept;
  Element *MaximumElement() const noexcept;

  // For tests
  bool IsBalancedUtil(Element *n, int &maxh, int &minh) const;
};
}  // namespace s21

template <class KEY, class Compare>
s21::Tree<KEY, Compare>::Tree() {
  count_elements = 0;
  root = nullptr;
}

template <class KEY, class Compare>
s21::Tree<KEY, Compare>::Tree(std::initializer_list<value_type> const &list) {
  count_elements = 0;
  root = nullptr;
  for (auto var : list) {
    Insert(var);
  }
}

template <class KEY, class Compare>
s21::Tree<KEY, Compare>::Tree(const Tree<KEY, Compare> &other) {
  if (this != &other && other.root != nullptr) {
    CopyElements(other.root);
  }
}

template <class KEY, class Compare>
s21::Tree<KEY, Compare>::Tree(Tree<KEY, Compare> &&other) noexcept {
  if (this != &other && other.root != nullptr) {
    std::swap(root, other.root);
    std::swap(count_elements, other.count_elements);
    std::swap(comp, other.comp);
  }
}

template <class KEY, class Compare>
s21::Tree<KEY, Compare>::~Tree() {
  Clear();
  delete root;
  root = nullptr;
}

template <class value_type, class Compare>
s21::Tree<value_type, Compare> &s21::Tree<value_type, Compare>::operator=(
    Tree &&other) noexcept {
  this->Clear();
  if (this != &other) {
    std::swap(root, other.root);
    std::swap(count_elements, other.count_elements);
    std::swap(comp, other.comp);
  }
  return *this;
}

template <class value_type, class Compare>
s21::Tree<value_type, Compare> &s21::Tree<value_type, Compare>::operator=(
    const Tree &other) {
  if (this != &other) {
    this->Clear();
    CopyElements(other.root);
  }
  return *this;
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::Empty() {
  return !count_elements && !(root);
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::size_type
s21::Tree<value_type, Compare>::Size() const noexcept {
  return count_elements;
}

template <class KEY, class Compare>
typename s21::Tree<KEY, Compare>::size_type s21::Tree<KEY, Compare>::MaxSize()
    const noexcept {
  return std::min<size_type>(node_traits::max_size(node_alloc()),
                             std::numeric_limits<difference_type>::max());
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::Clear() noexcept {
  ClearElements(&root);
}

template <class value_type, class Compare>
std::pair<typename s21::Tree<value_type, Compare>::iterator, bool>
s21::Tree<value_type, Compare>::Insert(value_type data) {
  std::pair<Element *, bool> result;
  if (count_elements == 0) {
    root = new Element(data);
    result = {root, true};
  } else {
    result = InsertStage2(data);
  }
  if (result.second) {
    count_elements++;
    result.second = true;
  } else {
    result.second = false;
  }
  return {iterator(result.first), result.second};
}

template <class value_type, class Compare>
std::pair<typename s21::Tree<value_type, Compare>::iterator, bool>
s21::Tree<value_type, Compare>::Contains(const value_type &data) {
  Element *find_data = root;
  bool find_status = false;
  for (; find_status != true && find_data;) {
    if ((!comp(find_data->value, data) && !comp(data, find_data->value)) ||
        (comp(find_data->value, data) && comp(data, find_data->value))) {
      find_status = true;
    } else if (comp(find_data->value, data)) {
      if (find_data->right_child == nullptr)
        find_data = nullptr;
      else
        find_data = find_data->right_child;
    } else {
      if (find_data->left_child == nullptr)
        find_data = nullptr;
      else
        find_data = find_data->left_child;
    }
  }
  return {iterator(find_data), find_status};
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::Erase(iterator pos) {
  if (count_elements <= 0 || pos == End()) return;
  if ((pos.current)->is_red && CheckChildfree(pos.current))
    DeleteCase1(pos.current);
  else if ((pos.current)->left_child)
    DeleteCase2(pos.current);
  else if (!(pos.current)->is_red && !(pos.current)->left_child)
    DeleteCase3(pos.current);

  delete pos.current;
  pos.current = nullptr;

  count_elements--;
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::Swap(Tree &other) noexcept {
  std::swap(root, other.root);
  std::swap(count_elements, other.count_elements);
  std::swap(comp, other.comp);
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::Merge(Tree &other) {
  if (!other.root) return;
  for (auto it = other.Begin(); it != other.End(); ++it) Insert((*it));
  other.Clear();
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::size_type
s21::Tree<value_type, Compare>::Count(const value_type &key) {
  size_type n = 0;
  auto res = Contains(key);
  if (res.second) {
    auto it_copy = res.first;
    ++it_copy;
    n++;
    while (*it_copy == *res.first) {
      n++;
      ++it_copy;
    }
    it_copy = res.first;
    --it_copy;
    while (*it_copy == *res.first) {
      n++;
      --it_copy;
    }
  }
  return n;
}

template <class KEY, class Compare>
std::pair<typename s21::Tree<KEY, Compare>::iterator,
          typename s21::Tree<KEY, Compare>::iterator>
s21::Tree<KEY, Compare>::EqualRange(const KEY &key) {
  return {s21::Tree<KEY, Compare>::LowerBound(key),
          s21::Tree<KEY, Compare>::UpperBound(key)};
}

template <class KEY, class Compare>
typename s21::Tree<KEY, Compare>::iterator s21::Tree<KEY, Compare>::LowerBound(
    const KEY &key) {
  auto it = Begin();
  bool stop = false;
  for (; stop != true && it != End();) {
    if (*it >= key) {
      stop = true;
    } else {
      ++it;
    }
  }
  if (!stop) it = End();
  return it;
}

template <class KEY, class Compare>
typename s21::Tree<KEY, Compare>::iterator s21::Tree<KEY, Compare>::UpperBound(
    const KEY &key) {
  auto it = Begin();
  bool stop = false;
  for (; stop != true && it != End();) {
    if (*it > key)
      stop = true;
    else
      ++it;
  }
  if (!stop) it = End();
  return it;
}

template <class KEY, class Compare>
template <typename... Args>
std::vector<std::pair<typename s21::Tree<KEY, Compare>::iterator, bool>>
s21::Tree<KEY, Compare>::Emplace(Args &&...args) {
  std::vector<std::pair<iterator, bool>> result;
  std::pair<iterator, bool> res =
      Insert(value_type(std::forward<Args>(args)...));
  result.push_back(res);
  return result;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::iterator
s21::Tree<value_type, Compare>::Begin() noexcept {
  return iterator(MinimumElement());
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::const_iterator
s21::Tree<value_type, Compare>::Cbegin() const noexcept {
  return const_iterator(MinimumElement());
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::iterator
s21::Tree<value_type, Compare>::End() noexcept {
  return iterator(nullptr, MaximumElement());
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::const_iterator
s21::Tree<value_type, Compare>::Cend() const noexcept {
  return const_iterator(nullptr, MaximumElement());
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::iterator
s21::Tree<value_type, Compare>::Rbegin() noexcept {
  return iterator(MaximumElement());
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::const_iterator
s21::Tree<value_type, Compare>::Crbegin() const noexcept {
  return const_iterator(MaximumElement());
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::iterator
s21::Tree<value_type, Compare>::Rend() noexcept {
  return iterator(nullptr, MinimumElement());
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::const_iterator
s21::Tree<value_type, Compare>::Crend() const noexcept {
  return const_iterator(nullptr, MinimumElement());
}

//внутри элемента
template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::Element *
s21::Tree<value_type, Compare>::Element::PreviousElement(Element *n) noexcept {
  if (!n) return n;
  if (n->left_child) {
    n = n->left_child;
    while (n->right_child) {
      n = n->right_child;
    }
  } else if (n->parent && n->parent->right_child == n) {
    n = n->parent;
  } else if (GrandpaPaIsRightChild(n)) {
    n = n->parent->parent->parent;
  } else if (GrandpaIsRightChild(n)) {
    n = n->parent->parent;
  } else {
    n = nullptr;
  }
  return n;
}

template <class value_type, class Compare>
const typename s21::Tree<value_type, Compare>::Element *
s21::Tree<value_type, Compare>::Element::PreviousElement(
    const Element *n) const noexcept {
  if (!n) return n;
  if (n->left_child) {
    n = n->left_child;
    while (n->right_child) {
      n = n->right_child;
    }
  } else if (n->parent && n->parent->right_child == n) {
    n = n->parent;
  } else if (GrandpaPaIsRightChild(n)) {
    n = n->parent->parent->parent;
  } else if (GrandpaIsRightChild(n)) {
    n = n->parent->parent;
  } else {
    n = nullptr;
  }
  return n;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::Element *
s21::Tree<value_type, Compare>::Element::NextElement(Element *n) noexcept {
  if (!n) return n;
  if (n->right_child) {
    n = n->right_child;
    while (n->left_child) {
      n = n->left_child;
    }
  } else if (n->parent && n->parent->left_child == n) {
    n = n->parent;
  } else if (GrandpaPaIsLeftChild(n)) {
    n = n->parent->parent->parent;
  } else if (GrandpaIsLeftChild(n)) {
    n = n->parent->parent;
  } else {
    n = nullptr;
  }
  return n;
}

template <class value_type, class Compare>
const typename s21::Tree<value_type, Compare>::Element *
s21::Tree<value_type, Compare>::Element::NextElement(
    const Element *n) const noexcept {
  if (!n) return n;
  if (n->right_child) {
    n = n->right_child;
    while (n->left_child) {
      n = n->left_child;
    }
  } else if (n->parent && n->parent->left_child == n) {
    n = n->parent;
  } else if (GrandpaPaIsLeftChild(n)) {
    n = n->parent->parent->parent;
  } else if (GrandpaIsLeftChild(n)) {
    n = n->parent->parent;
  } else {
    n = nullptr;
  }
  return n;
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::Element::GrandpaPaIsRightChild(
    const Element *n) const {
  bool status = false;

  status = (n->parent && n->parent->left_child == n);
  status = (status && n->parent->parent &&
            n->parent->parent->left_child == n->parent);
  status = (status && n->parent->parent->parent &&
            n->parent->parent->parent->right_child == n->parent->parent);

  return status;
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::Element::GrandpaIsRightChild(
    const Element *n) const {
  bool status = false;
  status = (n->parent && n->parent->left_child == n);
  status = (status && n->parent->parent &&
            n->parent->parent->right_child == n->parent);

  return status;
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::Element::GrandpaPaIsLeftChild(
    const Element *n) const {
  bool status = false;

  status = (n->parent && n->parent->right_child == n);
  status = (status && n->parent->parent &&
            n->parent->parent->right_child == n->parent);
  status = (status && n->parent->parent->parent &&
            n->parent->parent->parent->left_child == n->parent->parent);

  return status;
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::Element::GrandpaIsLeftChild(
    const Element *n) const {
  bool status = false;

  status = (n->parent && n->parent->right_child == n);
  status = (status && n->parent->parent &&
            n->parent->parent->left_child == n->parent);

  return status;
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::ClearElements(Element **n) {
  if ((*n) == nullptr) return;
  ClearElements(&(*n)->left_child);
  ClearElements(&(*n)->right_child);
  if ((*n) != nullptr) {
    delete (*n);
    (*n) = nullptr;
  }
  count_elements--;
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::CopyElements(Element *n) {
  if (n == nullptr) return;
  Insert(n->value);
  CopyElements(n->left_child);
  CopyElements(n->right_child);
}

template <class value_type, class Compare>
std::pair<typename s21::Tree<value_type, Compare>::Element *, bool>
s21::Tree<value_type, Compare>::InsertStage2(value_type data) {
  Element *curr_element = root;
  bool status_insert = true;
  for (int stop = 0; stop <= 0;) {
    if (comp(curr_element->value, data)) {
      if (curr_element->right_child == nullptr) {
        curr_element = InsertRightWay(curr_element, data);
        stop = true;
      } else {
        curr_element = curr_element->right_child;
      }
    } else if (comp(data, curr_element->value)) {
      if (curr_element->left_child == nullptr) {
        curr_element = InsertLeftWay(curr_element, data);
        stop = true;
      } else {
        curr_element = curr_element->left_child;
      }
    } else {
      stop = true;
      status_insert = false;
    }
  }
  return {curr_element, status_insert};
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::Element *
s21::Tree<value_type, Compare>::InsertRightWay(Element *currElement,
                                               value_type data) {
  currElement->right_child = new Element(data, true, currElement);
  Element *element_insert = currElement->right_child;
  if (currElement->parent && currElement->parent->right_child != currElement) {
    RightTurn(currElement->right_child);
  } else if (currElement->is_red != false) {
    LeftTurn(currElement->right_child);
  }
  return element_insert;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::Element *
s21::Tree<value_type, Compare>::InsertLeftWay(Element *currElement,
                                              value_type data) {
  currElement->left_child = new Element(data, true, currElement);
  Element *element_insert = currElement->left_child;
  if (currElement->parent && currElement->parent->left_child != currElement) {
    LeftTurn(currElement->left_child);
  } else if (currElement->is_red != false) {
    RightTurn(currElement->left_child);
  }
  return element_insert;
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::CheckGrGrGrandfather(Element *n,
                                                          bool left) {
  if (!n->parent->parent->parent) return false;
  if (!n->parent->parent->parent->parent) return false;
  bool status = false;
  if (left && n->parent->parent->parent ==
                  n->parent->parent->parent->parent->left_child) {
    status = true;
  } else if (!left && n->parent->parent->parent ==
                          n->parent->parent->parent->parent->right_child) {
    status = true;
  }
  return status;
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::UncleIsRed(Element *n, bool left) {
  bool status = false;
  if (n->is_red != true) {
    status = false;
  } else if (!n->parent || !n->parent->is_red) {
    status = false;
  } else if (left && n->parent->parent->left_child &&
             n->parent->parent->left_child->is_red) {
    status = true;
  } else if (!left && n->parent->parent->right_child &&
             n->parent->parent->right_child->is_red) {
    status = true;
  }
  return status;
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::LeftTurn(Element *n) {
  if (n->parent && n->parent->is_red == false) {
  } else if (UncleIsRed(n, 1)) {
    n->parent->is_red = false;
    n->parent->parent->left_child->is_red = false;
    if (n->parent->parent != root) {
      n->parent->parent->is_red = true;

      ChoosingTheNextPath(n, 1);
    }
  } else if (n->parent && n->parent->is_red && n->parent->parent && n->is_red) {
    if (n == n->parent->right_child) {
      JustLeft(n);
      LeftTurn(n->parent);
    } else {
      InsideLeftTurn(n);
      LeftTurn(n->right_child);
    }
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::RightTurn(Element *n) {
  if (n->parent && n->parent->is_red == false) {
  } else if (UncleIsRed(n, 0)) {
    n->parent->is_red = false;
    n->parent->parent->right_child->is_red = false;
    if (n->parent->parent != root) {
      n->parent->parent->is_red = true;
      ChoosingTheNextPath(n, 0);
    }
  } else if (n->parent && n->parent->is_red && n->parent->parent && n->is_red) {
    if (n == n->parent->left_child) {
      JustRight(n);
      RightTurn(n->parent);
    } else {
      InsideRightTurn(n);
      RightTurn(n->left_child);
    }
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::JustLeft(Element *n) {
  n->parent->parent->right_child = n->parent->left_child;
  std::swap(n->parent->left_child, n->parent->parent);
  n->parent->parent = n->parent->left_child->parent;
  if (n->parent->left_child == root)
    root = n->parent;
  else if (n->parent->left_child->parent->right_child == n->parent->left_child)
    n->parent->left_child->parent->right_child = n->parent;
  else
    n->parent->left_child->parent->left_child = n->parent;

  n->parent->left_child->parent = n->parent;
  n->parent->left_child->is_red = true;
  n->parent->is_red = false;

  if (n->parent->left_child->right_child)
    n->parent->left_child->right_child->parent = n->parent->left_child;
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::JustRight(Element *n) {
  n->parent->parent->left_child = n->parent->right_child;
  std::swap(n->parent->right_child, n->parent->parent);
  n->parent->parent = n->parent->right_child->parent;
  if (n->parent->right_child == root)
    root = n->parent;
  else if (n->parent->right_child->parent->left_child == n->parent->right_child)
    n->parent->right_child->parent->left_child = n->parent;
  else
    n->parent->right_child->parent->right_child = n->parent;

  n->parent->right_child->parent = n->parent;
  n->parent->right_child->is_red = true;
  n->parent->is_red = false;

  if (n->parent->right_child->left_child)
    n->parent->right_child->left_child->parent = n->parent->right_child;
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::InsideLeftTurn(Element *n) {
  n->parent->parent->right_child = n->parent->left_child;
  n->parent->left_child = n->right_child;
  n->right_child = n->parent;
  n->parent = n->right_child->parent;
  n->right_child->parent = n;
  if (n->right_child->left_child)
    n->right_child->left_child->parent = n->right_child;
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::InsideRightTurn(Element *n) {
  n->parent->parent->left_child = n->parent->right_child;
  n->parent->right_child = n->left_child;
  n->left_child = n->parent;
  n->parent = n->left_child->parent;
  n->left_child->parent = n;
  if (n->left_child->right_child)
    n->left_child->right_child->parent = n->left_child;
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::ChoosingTheNextPath(Element *n,
                                                         bool left) {
  if ((!(CheckGrGrGrandfather(n, left) | left) ^ left) &&
      ((CheckGrGrGrandfather(n, left) ^ (!left)))) {
    RightTurn(n->parent->parent);
  } else {
    LeftTurn(n->parent->parent);
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::DeleteCase1(Element *find_data) {
  if (find_data->parent && find_data == find_data->parent->right_child) {
    find_data->parent->right_child = find_data->right_child;
  } else if (find_data->parent && find_data == find_data->parent->left_child) {
    find_data->parent->left_child = find_data->right_child;
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::DeleteCase2(Element *find_data) {
  Element *replaceElement = FindElementToReplace(find_data->left_child);
  DeleteStep1(find_data, replaceElement);
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::DeleteCase3(Element *find_data) {
  if (find_data->right_child) {
    YesRightChild(find_data);
  } else if (count_elements != 1) {
    Neph(find_data);
    NoRightChild(find_data);
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::DeleteStep1(Element *find_data,
                                                 Element *replaceElement) {
  if (find_data->parent && find_data == find_data->parent->left_child) {
    DeleteStep2(find_data, replaceElement);
    replaceElement->parent->left_child = replaceElement;
  } else if (find_data->parent && find_data == find_data->parent->right_child) {
    DeleteStep2(find_data, replaceElement);
    replaceElement->parent->right_child = replaceElement;
  } else {
    replaceElement->is_red = false;
    if (find_data->left_child != replaceElement) {
      std::swap(find_data->left_child, replaceElement->left_child);
      replaceElement->left_child->parent = replaceElement;
    }
    if (find_data->right_child) {
      std::swap(find_data->right_child, replaceElement->right_child);
      replaceElement->right_child->parent = replaceElement;
    }
    root = replaceElement;
    replaceElement->parent = nullptr;
    if (!replaceElement->left_child) {
      ChangeColorToRed(replaceElement);
    }
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::DeleteStep2(Element *find_data,
                                                 Element *replaceElement) {
  replaceElement->is_red = find_data->is_red;
  std::swap(find_data->parent, replaceElement->parent);
  if (find_data->left_child != replaceElement) {
    std::swap(find_data->left_child, replaceElement->left_child);
  } else {
    replaceElement->left_child = nullptr;
  }
  std::swap(find_data->right_child, replaceElement->right_child);
  if (replaceElement->left_child) {
    replaceElement->left_child->parent = replaceElement;
  }
  if (replaceElement->right_child) {
    replaceElement->right_child->parent = replaceElement;
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::YesRightChild(Element *find_data) {
  if (find_data != root) {
    find_data->right_child->is_red = find_data->is_red;
    find_data->right_child->parent = find_data->parent;
  } else if (find_data->right_child) {
    find_data->right_child->is_red = find_data->is_red;
    root = find_data->right_child;
    find_data->right_child->parent = nullptr;
  }
  if (IsRightChild(find_data)) {
    find_data->parent->right_child = find_data->right_child;
  } else if (IsLeftChild(find_data)) {
    find_data->parent->left_child = find_data->right_child;
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::NoRightChild(Element *find_data) {
  if (IsRightChild(find_data)) {
    find_data->parent->right_child = nullptr;
    if (find_data->parent->is_red) {
      find_data->parent->is_red = false;
      find_data->parent->left_child->is_red = true;
    }
  } else if (IsLeftChild(find_data)) {
    find_data->parent->left_child = nullptr;
    if (find_data->parent->is_red) {
      find_data->parent->is_red = false;
      find_data->parent->right_child->is_red = true;
    }
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::Neph(Element *n) {
  if ((!CheckSiblingLeft(n->parent) && IsRightChild(n)) ||
      (!CheckSiblingRight(n->parent) && IsLeftChild(n))) {  // спускаем цвет
    CaseBlackSibling(n);
  } else if (CheckSiblingLeft(n->parent) && IsRightChild(n)) {
    JustRight(n->parent->left_child->left_child);
    Neph(n);
  } else if (CheckSiblingRight(n->parent) && IsLeftChild(n)) {
    JustLeft(n->parent->right_child->right_child);
    Neph(n);
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::CaseBlackSibling(Element *n) {
  if (!CheckCloseLeftNephew(n->parent) && !CheckFarLeftNephew(n->parent) &&
      IsRightChild(n)) {
    PushUpBlackLevelLeft(n->parent);
  } else if (!CheckFarRightNephew(n->parent) &&
             !CheckCloseRightNephew(n->parent) && IsLeftChild(n)) {
    PushUpBlackLevelRight(n->parent);
  } else if (CheckFarRightNephew(n->parent) && IsLeftChild(n)) {
    bool color_save = n->parent->is_red;
    JustLeft(n->parent->right_child->right_child);
    n->parent->is_red = color_save;
    ChangeColorBase(n);
  } else if (CheckFarLeftNephew(n->parent) && IsRightChild(n)) {
    bool color_save = n->parent->is_red;
    JustRight(n->parent->left_child->left_child);
    n->parent->is_red = color_save;
    ChangeColorBase(n);
  } else if (IsLeftChild(n)) {
    bool save_color = n->parent->is_red;
    InsideLeftTurn(n->parent->right_child->left_child);
    n->parent->right_child->right_child->is_red = true;
    n->parent->is_red = false;
    JustLeft(n->parent->right_child->right_child);
    n->parent->is_red = save_color;
    ChangeColorBase(n);
  } else if (IsRightChild(n)) {
    bool save_color = n->parent->is_red;
    InsideRightTurn(n->parent->left_child->right_child);
    n->parent->left_child->left_child->is_red = true;
    n->parent->is_red = false;
    JustRight(n->parent->left_child->left_child);
    n->parent->is_red = save_color;
    ChangeColorBase(n);
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::ChangeColorToRed(Element *n) {
  n->is_red = false;
  if (n->right_child) {
    n->right_child->is_red = true;
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::ChangeColorBase(Element *n) {
  ChangeColor(n->parent->parent);
  if (n->parent->is_red && IsRightChild(n)) {
    n->parent->is_red = false;
    n->parent->right_child->is_red = true;
  } else if (n->parent->is_red && IsLeftChild(n)) {
    n->parent->is_red = false;
    n->parent->left_child->is_red = true;
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::ChangeColor(Element *n) {
  if (n != root && n->right_child && n->right_child->is_red && n->left_child &&
      n->left_child->is_red) {
    n->right_child->is_red = false;
    n->left_child->is_red = false;
    n->is_red = true;
  } else {
    n->is_red = false;
    n->right_child->is_red = false;
    n->left_child->is_red = false;
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::PushUpBlackLevelLeft(Element *n) {
  n->left_child->is_red = true;
  if (n->is_red) {
    n->is_red = false;
  } else {
    n->is_red = false;
    if (n != root) {
      Neph(n);
    }
  }
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::PushUpBlackLevelRight(Element *n) {
  n->right_child->is_red = true;
  if (n->is_red) {
    n->is_red = false;
  } else {
    n->is_red = false;
    if (n != root) {
      Neph(n);
    }
  }
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::CheckFarRightNephew(Element *n) {
  return (n->right_child && n->right_child->right_child &&
          n->right_child->right_child->is_red);
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::CheckCloseRightNephew(Element *n) {
  return (n->right_child && n->right_child->left_child &&
          n->right_child->left_child->is_red);
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::CheckFarLeftNephew(Element *n) {
  return (n->left_child && n->left_child->left_child &&
          n->left_child->left_child->is_red);
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::CheckCloseLeftNephew(Element *n) {
  return (n->left_child && n->left_child->right_child &&
          n->left_child->right_child->is_red);
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::CheckSiblingRight(Element *n) {
  return (n->right_child && n->right_child->is_red);
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::CheckSiblingLeft(Element *n) {
  return (n->left_child && n->left_child->is_red);
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::CheckChildfree(Element *n) {
  return !(n->left_child && n->right_child);
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::IsRightChild(Element *n) {
  return (n->parent && n->parent->right_child == n);
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::IsLeftChild(Element *n) {
  return (n->parent && n->parent->left_child == n);
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::Element *
s21::Tree<value_type, Compare>::FindElementToReplace(Element *n) {
  if (n->right_child) {
    while (n->right_child) {
      n = n->right_child;
    }
    if (n->left_child) {
      n->parent->right_child = n->left_child;
      n->left_child->parent = n->parent;
      n->left_child->is_red = n->is_red;
    } else {
      if (!n->is_red) {
        Neph(n);
      }
      n->parent->right_child = nullptr;
    }

  } else if (n->parent != root) {
    if (!n->is_red && !n->left_child) {
      Neph(n);
    }
    n->parent->left_child = n->left_child;
    if (n->left_child) {
      n->left_child->parent = n->parent;
      n->left_child->is_red = n->is_red;
    }
  } else {
    if (n->left_child) {
      n->left_child->is_red = false;
    }
  }
  return n;
};

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::Element *
s21::Tree<value_type, Compare>::MinimumElement() const noexcept {
  Element *n = root;
  if (!n) {
    return nullptr;
  }
  while (n->left_child != nullptr) {
    n = n->left_child;
  }
  return n;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::Element *
s21::Tree<value_type, Compare>::MaximumElement() const noexcept {
  Element *n = root;
  if (!n) return nullptr;
  while (n->right_child != nullptr) {
    n = n->right_child;
  }
  return n;
}

template <class value_type, class Compare>
void s21::Tree<value_type, Compare>::Advance(TreeIterator &it,
                                             long long int n) const {
  if (std::abs(n) < count_elements) {
    if (n < 0) {
      while (n++) --it;
    } else {
      while (n--) ++it;
    }
  }
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::IsBalanced() const {
  int maxh, minh;
  return IsBalancedUtil(root, maxh, minh);
}

template <class value_type, class Compare>
s21::Tree<value_type, Compare>::TreeIterator::TreeIterator(
    Element *pElement, Element *pElement_max) {
  current = pElement;
  marker = pElement_max;
}

template <class value_type, class Compare>
s21::Tree<value_type, Compare>::TreeIterator::TreeIterator(Element *pElement) {
  current = pElement;
  marker = nullptr;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeIterator::reference
s21::Tree<value_type, Compare>::TreeIterator::operator*() const {
  if (!current) {
    static value_type default_value_{};
    return default_value_;
  }
  return current->value;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeIterator::iterator &
s21::Tree<value_type, Compare>::TreeIterator::operator++() noexcept {
  current = current->NextElement(current);
  return *this;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeIterator::iterator
s21::Tree<value_type, Compare>::TreeIterator::operator++(int) noexcept {
  iterator temp(*this);
  current = current->NextElement(current);
  return temp;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeIterator::iterator &
s21::Tree<value_type, Compare>::TreeIterator::operator--() noexcept {
  if (!current)
    current = marker;
  else
    current = current->PreviousElement(current);
  return *this;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeIterator::iterator
s21::Tree<value_type, Compare>::TreeIterator::operator--(int) noexcept {
  iterator temp(*this);
  if (!current)
    current = marker;
  else
    current = current->PreviousElement(current);
  return temp;
}

template <class value_type, class Compare>
s21::Tree<value_type, Compare>::TreeConstIterator::TreeConstIterator(
    Element *pElement, Element *pElement_max) {
  current = pElement;
  marker = pElement_max;
}

template <class value_type, class Compare>
s21::Tree<value_type, Compare>::TreeConstIterator::TreeConstIterator(
    Element *pElement) {
  current = pElement;
  marker = nullptr;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeConstIterator::const_reference
s21::Tree<value_type, Compare>::TreeConstIterator::operator*() const {
  if (!current) {
    static value_type default_value_{};
    return default_value_;
  }
  return current->value;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeConstIterator::const_iterator &
s21::Tree<value_type, Compare>::TreeConstIterator::operator++() noexcept {
  current = const_cast<const Element *>(current)->NextElement(current);
  return *this;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeConstIterator::const_iterator
s21::Tree<value_type, Compare>::TreeConstIterator::operator++(int) noexcept {
  const_iterator temp(*this);
  ++(*this);
  return temp;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeConstIterator::const_iterator &
s21::Tree<value_type, Compare>::TreeConstIterator::operator--() noexcept {
  if (!current)
    current = marker;
  else
    current = const_cast<const Element *>(current)->PreviousElement(current);
  return *this;
}

template <class value_type, class Compare>
typename s21::Tree<value_type, Compare>::TreeConstIterator::const_iterator
s21::Tree<value_type, Compare>::TreeConstIterator::operator--(int) noexcept {
  const_iterator temp(*this);
  if (!current)
    current = marker;
  else
    --(*this);
  return temp;
}

template <class value_type, class Compare>
bool s21::Tree<value_type, Compare>::IsBalancedUtil(Element *n, int &maxh,
                                                    int &minh) const {
  if (n == nullptr) {
    maxh = minh = 0;
    return true;
  }
  int lmxh, lmnh;
  int rmxh, rmnh;

  if (IsBalancedUtil(n->left_child, lmxh, lmnh) == false) return false;

  if (IsBalancedUtil(n->right_child, rmxh, rmnh) == false) return false;

  maxh = fmax(lmxh, rmxh) + 1;
  minh = fmin(lmnh, rmnh) + 1;

  if (maxh <= 2 * minh) return true;

  return false;
}

#endif  // CPP2_S21_CONTAINERS_1_DEVELOP_SLAVA_REF_TREE_H
