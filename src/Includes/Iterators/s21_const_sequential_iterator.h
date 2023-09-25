#ifndef SRC_INCLUDES_ITERATORS_S21_CONSTSEQUENTIALITERATOR_H
#define SRC_INCLUDES_ITERATORS_S21_CONSTSEQUENTIALITERATOR_H
template <typename T>
class ConstSequentialIterator {
 public:
  typedef ConstSequentialIterator<T> s21_iterator;
  typedef T IteratorType;

  ConstSequentialIterator() noexcept {}
  ConstSequentialIterator(IteratorType* IteratorData) noexcept
      : ptr_to_data{IteratorData} {}
  ConstSequentialIterator(s21_iterator& OtherIterator) noexcept
      : ptr_to_data{OtherIterator.ptr_to_data} {}
  ConstSequentialIterator(s21_iterator&& iterator) noexcept {
    std::swap(ptr_to_data, iterator.ptr_to_data);
    iterator.ptr_to_data = nullptr;
  }
  ~ConstSequentialIterator() { ptr_to_data = nullptr; }

  inline IteratorType operator*() { return ptr_to_data; }
  inline IteratorType operator*() const { return ptr_to_data; }

  inline void operator=(s21_iterator& other) noexcept {
    ptr_to_data = other.ptr_to_data;
  }

  inline s21_iterator operator++() {
    ptr_to_data++;
    return *this;
  }

  inline s21_iterator operator++(int) {
    s21_iterator copy(ptr_to_data);
    ptr_to_data++;
    return copy;
  }

  inline s21_iterator operator--() {
    ptr_to_data--;
    return *this;
  }

  inline s21_iterator operator--(int) {
    s21_iterator copy(ptr_to_data);
    ptr_to_data--;
    return copy;
  }

  inline bool operator==(s21_iterator other) const noexcept {
    return ptr_to_data == other.ptr_to_data;
  }
  inline bool operator!=(s21_iterator other) const noexcept {
    return !(*this == other);
  }

 private:
  IteratorType* ptr_to_data{};
};

#endif  //  SRC_INCLUDES_ITERATORS_S21_CONSTSEQUENTIALITERATOR_H
