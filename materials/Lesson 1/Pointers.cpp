#include <iostream>
#include <string>

using std::cin;
using std::cout;
int main() {
  int a = 1;
  int b;
  // the pointer contains address just a hexadecimal number - the number of a
  // cell in a limited area of RAM (Stack, Static, and Heap
  // https://stackoverflow.com/questions/408670/stack-static-and-heap-in-c)
  int* px;
  px = &a;  // *px point to 1 too
  b = *px;  // b = 1

  a = 10;

  cout << &a << '\n';   // take address of a
  cout << a << '\n';    // 10
  cout << *px << '\n';  // dereference px (take an object in memory)
  cout << px << '\n';   // address (hexadecimal 64 bit number)

  px = nullptr;
  if (!px /*converts to !px == 0*/) {
  }
  if (px != NULL /*same thing NULL is 0 or (void*)0 */) {
  }
  // but it C++20, we should use nullptr
  if (px != nullptr) {
    // that's ok
  }
  cout << px << '\n';
}
