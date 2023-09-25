# cpp_containers
## Implementing our own containers from the standard C++ library.

Namespace of project is `s21::<type>`
# Containers

| Container name          | Containers |
| ----------------------- | ---------- |
| `s21_container.h`       | `List, Map, Queue, Set, Stack, Vector`
| `s21_containerplus.h`   | `Array, Multiset`
# Stack description
| Methods                       | Meaning                                                       |
| ----------------------------- | ------------------------------------------------------------- |
| constructor()                 | Create stack object                                           |
| constructor(s21_stack& an)    | Copy constructor                                              |
| void push(new_element)        | Push new element on top of stack                              |
| void pop()                    | Pop element from top of stack                                 |
| int size()                    | Return size of stack                                          |
| bool is_empty()               | Return boolean is empty stack or not                          |
| void clear()                  | Clear container from all elements                             |
| top()                         | Return element from top of stack                              |
| void swap()                   | Swap elements in stack                                        |

# Queue description
| Methods                       | Meaning                                                       |
| ----------------------------- | ------------------------------------------------------------- |
| constructor()                 | Create queue object                                           |
| void push(new_element)        | Push new element on back of queue                             |
| void pop()                    | Pop element from front of queue                               |
| front()                       | Return first element in queue                                 |
| back()                        | Return last element in queue                                  |
| bool is_empty()               | Return boolean is empty queue or not                          |
| int size()                    | Return size of queue                                          |
| void swap()                   | Swap elements in queue                                        |
| emplace(new_element)          | Push new element on back of queue                             |
| operator=                     | Allow initialize object by other object                       |

# Array description
| Methods                       | Meaning                                                       |
| ----------------------------- | ------------------------------------------------------------- |
| constructor()                 | Create array object                                           |
| constructor(init_list< T >)   | Initialize queue object with values                           |
| constructor(s21_array& an)    | Copy constructor                                              |
| at(i)                         | Return [ i ] element in array (w check for out-of-range)      |
| back()                        | Return last element in array                                  |
| front()                       | Return first element in array                                 |
| is_empty()                    | Return boolean is empty array or not                          |
| size()                        | Return size of array                                          |
| data()                        | Return pointer to first element in array                      |       
| fill(value)                   | Fill all array with input value                               |
| operator[ i ]                 | Return [ i ] element in array (w/o check for out-of-range)    |    
| operator=                     | Allow initialize object by other object                       |     
# Throws
Array.at() method throw out-of-range exception when i pos more than size of array.
Another containers throw exception only when no memory to allocate container or when the user tries to access a foreign memory space (empty stack and user call stack.top() and etc.);


# Iterators
| Operations        | Meaning |
| ----------------- | ------- |
| `*iter`           | `Getting the element that the iterator points to`|
| `++iter`          | `Increase iterator`|
| `--iter`          | `Descrease iterator`|
| `iter1 == iter2`  | `Iterators are equal, if they point to the same element`|
| `iter1 != iter2`  | `Iterator are not equal, if they point to the different element`|

| Methods                                    | Meaning          | Containers  |
| ------------------------------------------ | ---------------- | ----------- |
| `iterator emplace(const_iterator pos, Args&& args)`   | `Insert new elements into the container directly before pos` | List, Vector
| `void emplace_back(Args&&... args)`   | `Appends new elements to the end of the container` | List, Vector, Queue
| `void emplace_front(Args&&... args)`   | `Appends new elements to the top of the container` | List, Stack
| `std::pair < iterator, bool > emplace(Args&&... args)` | `Inserts new element into the container` | Map, Set, Multiset
