#include <iostream>
#include <string>

using std::cin;
using std::cout;

int main() {
  char c;
  std::cin >> c;
  // https://en.wikipedia.org/wiki/ASCII#Printable_characters tables are
  // different, we using just order The following code above will work for each
  // ASCII standard
  //  if ('a' <= c <= 'z' || 'A' <= c <= 'Z') 
  // that is incorrect because 'a' <= c <= 'z' => '(a' <= c) <= 'z' => true/false <= 'z' is always true
  if ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z') {
    // c is letter
  }
  if ('0' <= c && c <= '9') {
    // c is number
  }
  // Captitalize problem
  int lowercase_uppercase_difference =
      'B' - 'b';  // or 'A' - 'a', 'J' - 'j' whatever
  if ('a' <= c && c <= 'z') {
    std::cout << c + lowercase_uppercase_difference;
  }
}
