#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

const int EMPTY = 0;

struct Node {
  const char letter;
  Node *left = nullptr;
  Node *right = nullptr;

  explicit Node(const char other) : letter(other) {}
};

int DFS(Node *node, std::unordered_set<int> &set_of_letters, int &result) {
  if (node == nullptr) {
    return EMPTY;
  }

  int letters = 0;
  letters |= DFS(node->left, set_of_letters, result);
  letters |= DFS(node->right, set_of_letters, result);
  letters |= 1 << (node->letter - 'A');

  if (set_of_letters.count(letters)) {
    result = letters;
  }

  if (letters != EMPTY) {
    set_of_letters.insert(letters);
  }

  return letters;
}

class BinaryTree {
 public:
  explicit BinaryTree(std::string &str) {
    root = nullptr;
    int cur_h = 0;
    int h = floor(log2(str.size())) + 1;
    int i = 0;
    root = GrowBinaryTree(str, i, cur_h, h);
  }
  ~BinaryTree() { Clear(root); }
  void Clear(Node *node) {
    if (node == nullptr) {
      return;
    }
    Clear(node->left);
    Clear(node->right);
    delete node;
  }

  Node *root;

 private:
  Node *GrowBinaryTree(std::string s, int &i, int &cur_h, int h) {
    if (i == s.size() || cur_h == h) {
      --cur_h;
      return nullptr;
    }
    if (s[i] == '0') {
      i++;
      --cur_h;
      return nullptr;
    }
    Node *node = new Node(s[i++]);
    node->left = GrowBinaryTree(s, i, ++cur_h, h);
    node->right = GrowBinaryTree(s, i, ++cur_h, h);
    --cur_h;
    return node;
  }
};

int main() {
  std::string s;
  std::cin >> s;
  BinaryTree tree(s);
  int result = EMPTY;
  std::unordered_set<int> set;
  DFS(tree.root, set, result);

  if (result == EMPTY) {
    std::cout << "None\n";
    return 0;
  }

  for (int i = 0; i < 26; ++i) {
    int letter = 1 << i;
    if ((result & letter) != 0) {
      std::cout << char('A' + i);
    }
  }
}