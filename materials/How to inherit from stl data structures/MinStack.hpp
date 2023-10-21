#include <algorithm>
#include <iostream>
#include <stack>

using std::stack;

// Overriding means that you are going to inherit from STL container. Don't do
// this! STL containers are not designed for inheriting from them.
// For instance, std::stack  doesn't contain virtual function specifier

// template <class T>
// class MinStack : public stack<Pair<T>> {
//  public:
//   using TPair = Pair<T>;
//   using Base = stack<TPair>;
//   void push(const T& value) {
//     Base::emplace(
//         value, Base::empty() ? value : std::min(value,
//         Base::top().min_value));
//   }
//   T GetMin() { return Base::top().min_value; }
// };

// Do it like this
template <class T>
class MinStack {
 public:
  void Push(const T& value) {
    stack_.emplace(
        value, stack_.empty() ? value : std::min(value, stack_.top().min_value));
  }
  T GetMin() { return stack_.top().min_value; }
  void Pop() { stack_.pop(); }

 private:
  struct Pair {
    T value;
    T min_value;
    Pair(T value, T min_value) {
      this->value = value;
      this->min_value = min_value;
    }
  };
  stack<Pair> stack_;
};
