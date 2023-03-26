#include <vector>

const size_t CAPACITY = 256;

template <class T>
class Queue {
 public:
  Queue();
  Queue(size_t capacity);
  ~Queue();
  void PushFront(T value);
  void PopBack();
  T Back() const;
  T Front() const;
  void Resize(size_t capacity);
  size_t Size() const;
  void Clear();

 private:
  size_t Mod(size_t i, size_t n) const;

 private:
  T* data_;
  size_t capacity_;
  size_t head_;
  size_t tail_;
};

template <class T>
Queue<T>::Queue() : Queue(CAPACITY) {}

template <class T>
Queue<T>::Queue(size_t capacity) : capacity_{capacity}, head_{0}, tail_{0} {
  data_ = new T[capacity_];
}

template <class T>
Queue<T>::~Queue() {
  delete[] data_;
}

template <class T>
size_t Queue<T>::Size() const {
  return Mod(tail_ - head_, capacity_);
}

template <class T>
void Queue<T>::Clear() {
  delete[] data_;
  capacity_ = CAPACITY;
  data_ = new T[capacity_];
  head_ = tail_ = 0;
}

template <class T>
void Queue<T>::PopBack() {
  if (Size() == capacity_ / 4) {
    Resize(capacity_ / 2);
  }
  tail_ = Mod(--tail_, capacity_);
}

template <class T>
T Queue<T>::Back() const {
  return data_[Mod(tail_ - 1, capacity_)];
}

template <class T>
T Queue<T>::Front() const {
  return data_[Mod(head_, capacity_)];
}

template <class T>
void Queue<T>::PushFront(T value) {
  if (Size() == capacity_) {
    Resize(capacity_ * 2);
  }
  head_ = Mod(--head_, capacity_);
  data_[head_] = value;
}

template <class T>
void Queue<T>::Resize(size_t new_capacity) {
  T* clipboard = new T[new_capacity];
  for (int i = 0, j = head_; i < Size(); ++i) {
    clipboard[i] = data_[Mod(j++, capacity_)];
  }
  delete[] data_;
  data_ = clipboard;
  capacity_ = new_capacity;
  head_ = 0;
  tail_ = Size();
}

template <class T>
size_t Queue<T>::Mod(size_t i, size_t n) const {
  return (i % n + n) % n;
}
