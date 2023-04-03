#include <iostream>
#include <iterator>
#include <ostream>

#include "MergeSort.hpp"

using std::cout;

class Date {
 public:
  Date() = default;
  Date(int day, int month, int year) : year_(year), month_(month), day_(day) {}
  friend class DateComparator;
  // Do not use Print...(...) for printing, use this
  friend std::ostream &operator<<(std::ostream &os, const Date &value) {
    os << value.day_ << '.' << value.month_ << '.' << value.year_;
    return os;
  }

 private:
  int day_;
  int month_;
  int year_;
};

class DateComparator {
 public:
  DateComparator() {}
  // to reject using, for example:
  // DataComparator a;
  // DataComparator a(b);
  // a = b;
  DateComparator(const DateComparator &) = delete;

  DateComparator(DateComparator &&) = delete;

  DateComparator &operator=(DateComparator &&) = delete;

  DateComparator &operator=(DateComparator &r) = delete;

  bool operator()(const Date &l, const Date &r) const {
    if (l.year_ != r.year_) {
      return l.year_ < r.year_;
    }
    if (l.month_ != r.month_) {
      return l.month_ < r.month_;
    }
    return l.day_ <= r.day_;
  }
};

void TestMergeSort() {
  Date *dates =
      new Date[10]{Date{12, 04, 2001}, Date{12, 04, 2000}, Date{12, 03, 2001},
                   Date{15, 04, 2001}, Date{11, 04, 2001}, Date{12, 03, 2005},
                   Date{14, 04, 2001}, Date{10, 04, 2000}, Date{12, 04, 2003},
                   Date{12, 04, 2007}};
  // MergeSort<Date, DateComparator>(dates, 10, DateComparator());
  // or
  MergeSort(dates, 10, DateComparator());
  cout << "Dates example:" << '\n';
  for (int i = 0; i < 10; ++i) {
    cout << dates[i] << '\n';
  }
  delete[] dates;
  cout << '\n';

  int nums[] = {1, 4, 6, 7, 8, 3, 9, 2, 5, 0};
  MergeSort(nums, 10);
  cout << "Nums example:" << '\n';
  for (int i = 0; i < 10; ++i) {
    cout << nums[i] << ' ';
  }
}

int main() { TestMergeSort(); }