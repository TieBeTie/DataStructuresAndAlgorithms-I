#include <algorithm>
// This code defines a struct IsLess, which is a function object that returns
// true if its left-hand operand is less than its right-hand operand.
template <typename T>
struct IsLess {
  bool operator()(const T &l, const T &r) const { return l < r; }
};

/* In this function declaration, the template arguments T and TLess are used to
 * provide a generic implementation of the Merge function for any type T and any
 * comparison function object type TLess. The last parameter is_less is a
 * function object that is used to compare elements of type T. This parameter is
 * optional, and its default value is IsLess<T>, which is a function object that
 * returns true if its left-hand operand is less than its right-hand operand. By
 * default, the Merge function uses the IsLess function object to compare
 * elements, but you can provide a custom function object that implements a
 * different comparison algorithm if needed.
 */

/* This function merges two SORTED
 * arrays (l_array and r_array) of sizes l_count and r_count respectively, and
 * stores the result in a dynamically allocated buffer array. The result is
 * sorted according to the comparison function object is_less.
 */
template <class T, class TLess = IsLess<T>>
void Merge(T *l_array, T *r_array, int l_count, int r_count,
           const TLess &is_less = TLess()) {
  T *buffer = new T[r_count + l_count];

  // Merge the two arrays, maintaining the sorted order.
  int i = 0, j = 0;
  while (i < l_count && j < r_count) {
    if (is_less(l_array[i], r_array[j])) {
      // buffer[i + j] = l_array[i++];
      // =>
      // l_array[i]; i++; buffer[i + j]; :(
      buffer[i++ + j] = l_array[i];
    } else {
      buffer[i + j++] = r_array[j];
    }
  }

  // Copy any remaining elements from the left array to the buffer.
  while (i < l_count) {
    buffer[i++ + j] = l_array[i];
  }

  // Copy any remaining elements from the right array to the buffer.
  while (j < r_count) {
    buffer[i + j++] = r_array[j];
  }

  // Copy the sorted elements back into the original array.
  for (int i = 0; i < l_count + r_count; l_array[i++] = buffer[i])
    ;
  delete[] buffer;
}

// This function sorts an array of n elements using the MergeSort algorithm.
// The elements are sorted according to the comparison function object is_less.
template <class T, class TLess = IsLess<T>>
void MergeSort(T *base, int n, const TLess &is_less = TLess()) {
  // Split the array into smaller subarrays, merge them, and repeat until the
  // entire array is sorted.
  // split_size / 2 < n - incorrect
  for (int split_size = 1; split_size < n; split_size *= 2) {
    for (int i = 0; i < n - split_size; i += split_size * 2) {
      Merge(base + i, base + i + split_size, split_size,
            std::min(split_size, n - split_size), is_less);
    }
  }
}
