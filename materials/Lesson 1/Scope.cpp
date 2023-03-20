#include <iostream>

// Each name that appears in a C++ program is only visible in some possibly
// discontiguous portion of the source code called its scope.

// global scope
int i = 1;  // always accessible using ::

int main() {
  if (int i = 2; i < 5) {
    std::cout << i;  // 2
  }

  int i = 3;
  {
    int i = 4;
    std::cout << i << '\n';  // 4, i = 3 is not accessible
    {
      int i = 5;
      std::cout << i << '\n';  // 5, i = 3 and i = 4 is not accessible
    }
  }

  {
    /*statement 1*/
    while (/*condition &&*/ true) {
      /*some code*/
      /*statement 2*/
    }
  }
  // <=>
  for (/*statement 1*/; /*condition*/; /*statement 2*/) {
    /*some code*/
  }
  // we can do something like this
  for (std::cin >> i; i < 5; std::cin >> i) {
    std::cout << i << ' ';
  }
  // or this
  for (;;)
    ;
}