#include <iostream>

#include "BinaryTree.hpp"

using std::cin;

// recursion <-> loop
int Add(int n) {
  if (n == 0) {
    return 0;
  }
  return Add(n - 1);
}

void f1() {
  for (int i = 0; i < 10; ++i) {
    // some code
  }
}

void f2(int i = 0) {
  if (i >= 10) {
    return;
  }
  // some code
  f2(++i);
}

int main() {
  Add(8);
  size_t N;
  BinaryTree<int> *bin_tree = new BinaryTree<int>();
  int key;

  for (size_t i = 0; i < N; i++) {
    cin >> key;
    bin_tree->Insert(key);
  }
  InOrderTraversal(bin_tree->GetRoot());
  delete bin_tree;
}
