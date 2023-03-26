#include <iostream>

using std::cout;

int main() {
  // new expression
  /*Creates and initializes objects
    with dynamic storage (Heap) duration, that is,
    objects whose lifetime is not limited by the scope
    {
        I live only here
    }
    in which they were created.
    New expression returns a POINTER to the object.*/

  int* p1 = new int(4);         // value
  double* p2 = new double[10];  // array

  // delete expression
  /*Destroys object(s) previously allocated
    by the new expression and
    releases obtained memory area.*/

  /*delete expression - destroys one non-array object created by a
    delete[] expression - destroys an array created by a new[]-expression*/

  // delete p1;
  delete[] p2;

  // Ḿ̵͎̼E̶̲̓M̴̪̓Ö̷̥̜̚R̵͉̃Y̸̝̺͋͝  L̶̗͗̊Ȅ̷͙A̴͍̐K̶̢͔̓̾S̵̡͔͑
  /*The objects created by new-expressions
  (objects with dynamic storage (Heap) duration)
  persist until the pointer returned by the
  new-expression is used in a matching delete-expression.
  If the original value of pointer is lost,
  the object becomes unreachable and cannot be deallocated:
  a memory leak occurs.*/

  int* p = new int(7);  // dynamically allocated int with value 7
  p = nullptr;          // memory leak :(
  p1 = new int(4);      // memory leak ;<

  // Double Free

  delete p;  // object is not exist
  char* p3 = new char('c');
  delete p3;  // ok
  // delete p3;  // double free

  // Create array of pointers
  int* array = new int[5];

  // take element from array
  array[3];
  /*<=>*/
  *(array + 3);

  // How to create 2D-arrays?
  //
  //
  //
  //
  //
  //
  //
  // a is a pointer to pointers
  int** a = new int*[3];
  // and create arrays
  for (int i = 0; i < 3; ++i) {
    a[i] = new int[2]{42}; // 42 0
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      cout << (a[i])[j] /*a[i][j]*/ << '=' << *(*(a + i) + j) << ' ';
    }
    cout << '\n';
  }
  // Then we should delete whole pointers;
  for (int i = 0; i < 3; ++i) {
    delete[] a[i];
  }
  // And the pointer to pointers (to addresses (to numbers))
  delete[] a;
}
// 10D arrays???
// https://www.youtube.com/watch?v=xFtYY-Rmf1Y
