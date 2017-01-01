class NumArray {
  public:
    NumArray(vector<int> &nums) {
      vals = nums;
    }

    void update(int i, int val) {
      vals[i] = val;
    }

    int sumRange(int i, int j) {
      int sum = 0;
      for (int k = i; k <= j; k++)
        sum += vals[k];
      return sum;
    }
  private:
    vector<int> vals;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
