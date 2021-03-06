﻿class Solution {
  public:
    int minSubArrayLen(int s, vector<int>& nums) {
      int minLen = INT_MAX;
      int left = 0, sum = 0;
      for(int right = 0; right < nums.size();) {
        sum += nums[right++];
        while(sum >= s) {
          minLen = min(minLen, right - left);
          sum -= nums[left++];
        }
      }
      return minLen == INT_MAX ? 0 : minLen;
    }
};

class Solution {
  public:
    bool sumsOver(int s, vector<int> nums, int num) {
      int res;
      for (int i = 0; i <= nums.size() - num; i++) {
        res = 0;
        for (int j = 0; j < num; j++) {
          res += nums[i + j];
          if (res >=s ) return true;
        }
      }
      return false;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
      if (nums.size() == 0) return 0;
      for (int i = nums.size(); i > 0; i--) {
        if (!sumsOver(s, nums, i)) {
          if (i == nums.size()) return 0;
          else return i + 1;
        }
      }
      return 1;
    }
};
