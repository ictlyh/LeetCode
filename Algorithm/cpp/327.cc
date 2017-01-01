

// Time Limit Exceeded
class Solution {
  public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
      int count = 0;
      for (int i = 0; i < nums.size(); i++) {
        long tmp = 0;
        for (int j = i; j < nums.size(); j++) {
          tmp += nums[j];
          if (tmp <= upper && tmp >= lower)
            count++;
        }
      }
      return count;
    }
};
