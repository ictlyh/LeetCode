// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
  Data* data;
  public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};


class PeekingIterator : public Iterator {
  public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {}

    int peek() {
      if (peeked_) {
        return next_val_;
      }
      next_val_ = Iterator::next();
      peeked_ = true;
      return next_val_;
    }

    int next() {
      if (peeked_) {
        peeked_ = false;
        return next_val_;
      }
      return Iterator::next();
    }

    bool hasNext() const {
      if (peeked_) {
        return true;
      }
      return Iterator::hasNext();
    }

  private:
    bool peeked_ = false;
    int next_val_ = 0;
};
