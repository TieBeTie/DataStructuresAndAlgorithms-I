// recursion
// recursion <-> loop
#include <iostream>
#include <stack>

using std::cout;

template <class T>
struct Node {
  T key;
  Node *left;
  Node *right;

  Node(T k) {
    key = k;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
void Visit(T key) {
  cout << key << " ";
}

template <class T>
void InOrderTraversal(Node<T> *root) {
  if (root == nullptr) return;

  std::stack<Node<T> *> states;
  Node<T> *tmp = root;

  while (states.size() != 0 || tmp != nullptr) {
    while (tmp != nullptr) {
      states.push(tmp);
      tmp = tmp->left;
    }

    tmp = states.top();
    states.pop();
    Visit(tmp->key);

    tmp = tmp->right;
  }
}

template <typename T>
struct IsLess {
  bool IsGreater(const T &l, const T &r) const { return l <= r; }
  bool operator()(const T &l, const T &r) const { return l <= r; }
};

template <class T, class TLess = IsLess<T>>
class BinaryTree {
 public:
  BinaryTree(TLess comparator = TLess()) {
    root_ = nullptr;
    this->comparator_ = comparator;
  }

  BinaryTree(const BinaryTree &) = delete;

  BinaryTree(BinaryTree &&) = delete;

  BinaryTree &operator=(const BinaryTree &) = delete;

  BinaryTree &operator=(BinaryTree &&) = delete;
  // void clear(Node<T>* a){
  //   if(a == nullptr){
  //     return;
  //   }
  //   clear(a->left);
  //   clear(a->right);
  //   delete a;
  // }
  // ~BinaryTree() {
  //   clear(root);

  // }

  ~BinaryTree() {
    std::stack<Node<T> *> states;
    Node<T> *tmp;

    if (root_ == nullptr) {
      return;
    }

    states.push(root_);

    while (states.size() != 0) {
      tmp = states.top();
      states.pop();

      if (tmp->left != nullptr) states.push(tmp->left);

      if (tmp->right != nullptr) states.push(tmp->right);

      delete tmp;
    }
  }

  void Insert(T key) {
    if (root_ == nullptr) {
      root_ = new Node<T>(key);
      return;
    }

    Node<T> *head = root_;
    Node<T> *tale = root_;
    bool direction;

    while (head != nullptr) {
      if (comparator_(head->key, key)) {
        tale = head;
        head = head->right;
        direction = false;
      } else {
        tale = head;
        head = head->left;
        direction = true;
      }
    }

    if (!direction) {
      tale->right = new Node<T>(key);
    } else {
      tale->left = new Node<T>(key);
    }
  }

  Node<T> *GetRoot() { return (this->root_); }

 private:
  Node<T> *root_;
  TLess comparator_;
};