class Solution {
  public:
    vector<vector<int> > FindContinuousSequence(int sum) {
      vector<vector<int>> res;
      if (sum <= 1) return res;
      vector<int> nums(sum, 0);
      for (int i = 0; i < sum; i++)
        nums[i] = i + 1;
      int cursum = 0;
      for (int i = 0, j = 0; i <= sum / 2;) {
        cursum += nums[j];
        if (cursum == sum && i < j) {
          res.push_back(vector<int>(nums.begin() + i, nums.begin() + j + 1));
          cursum -= nums[i++];
        } else if (cursum > sum) {
          while (cursum > sum)
            cursum -= nums[i++];
          if (cursum == sum && i < j) {
            res.push_back(vector<int>(nums.begin() + i, nums.begin() + j + 1));
            cursum -= nums[i++];
          }
        }
        j++;
      }
      return res;
    }
};
