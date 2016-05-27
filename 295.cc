class MedianFinder {
  public:
    vector<int> number;
    int size = 0;
    // Adds a number into the data structure.
    void addNum(int num) {
      int l = 0, h = size - 1;
      while (l <= h) {
        int mid = (l + h) / 2;
        if (num > number[mid]) l = mid + 1;
        else h = mid - 1;
      }
      number.insert(number.begin() + l, num);
      size++;
    }

    // Returns the median of current data stream
    double findMedian() {
      if (size == 0) return 0;
      else if (size % 2 == 0)
        return (number[size / 2] + number[size / 2 - 1]) / 2.0;
      else return number[size / 2];

    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

// Time Limit Exceeded
class MedianFinder {

  public:
    vector<int> nums;
    // Adds a number into the data structure.
    void addNum(int num) {
      if (nums.size() == 0 || num <= nums.front()) nums.insert(nums.begin(), num);
      else if (num >= nums.back()) nums.push_back(num);
      else {
        vector<int>::iterator ite = nums.begin();
        while (ite != nums.end() && *ite < num) ite++;
        nums.insert(ite, num);
      }
    }

    // Returns the median of current data stream
    double findMedian() {
      int size = nums.size();
      if (size % 2 == 1)
        return (nums[size / 2  - 1] + nums[size / 2]) / 2.0;
      else return nums[size / 2];
    }
};
// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
