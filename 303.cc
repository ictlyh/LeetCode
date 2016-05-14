class NumArray {
  public:
    vector<int> nums_;
    NumArray(vector<int> &nums) {
      nums_ = nums;
    }

    int sumRange(int i, int j) {
      int sum = 0;
      for (int k = i; k <= j; k++)
        sum += nums_[k];
      return sum;
    }
};
