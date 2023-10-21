#include <iostream>

#include "Queue.hpp"

using std::cout;

int main() {
  { Queue<int> a; }
  Queue<double> b(1);
  b.PushFront(1);
  cout << b.Front() << ' ' << b.Back() << ' ' << b.Size() << '\n';
  b.PushFront(2);
  b.PopBack();
  cout << b.Front() << ' ' << b.Back() << ' ' << b.Size() << '\n';
  b.PushFront(3);
  cout << b.Front() << ' ' << b.Back() << ' ' << b.Size() << '\n';
  b.PushFront(4);
  b.PopBack();
  cout << b.Front() << ' ' << b.Back() << ' ' << b.Size() << '\n';
  b.PushFront(5);
  cout << b.Front() << ' ' << b.Back() << ' ' << b.Size() << '\n';
  b.PopBack();
  b.PopBack();
  b.PushFront(6);
  cout << b.Front() << ' ' << b.Back() << ' ' << b.Size() << '\n';
  std::cout << -2 % 5;
}
