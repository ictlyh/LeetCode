class Solution {
  public:
    bool canJump(vector<int>& nums) {
      int lastReachableIdx = nums.size() - 1;
      for (int i = nums.size() - 2; i >= 0; i--)
        if (lastReachableIdx - nums[i] <= i)
          lastReachableIdx = i;
      return lastReachableIdx == 0;
    }
};

class Solution {
  public:
    bool canJump(vector<int>& nums) {
      if (nums.size() <= 1) return true;
      int i;
      for (i = 0; i <= nums.size() - 2; i++) {
        if (i + nums[i] >= nums.size() - 1) break;
      }
      if (i == nums.size() - 1) return false;
      vector<bool> res(nums.size(), false);
      res[0] = true;
      for (int i = 0; i < nums.size(); i++) {
        if (res[i] == true) {
          if (i + nums[i] >= nums.size() - 1) return true;
          for (int j = i + 1; j <= i + nums[i]; j++) {
            res[j] = true;
          }
        }
      }
      return res.back();
    }
};

// Time Limit Exceeded
class Solution {
  public:
    bool multiJumps(vector<int>& nums, int begin, int end) {
      if (nums[begin] >= end - begin) return true;
      for (int i = begin + 1; i < end; i++) {
        if (multiJumps(nums, begin, i) && multiJumps(nums, i, end)) return true;
      }
      return false;
    }
    bool canJump(vector<int>& nums) {
      if (nums.size() <= 0) return true;
      return multiJumps(nums, 0, nums.size() - 1);
    }
};
class Solution {
  public:
    bool canJump(vector<int>& nums) {
      vector<bool> res(nums.size(), false);
      res[0] = true;
      for (int i = 0; i < nums.size(); i++) {
        if (!res[i]) return false;
        if (i + nums[i] >= nums.size() - 1) return true;
        for (int j = i + 1; j <= i + nums[i]; j++) {
          res[j] = true;
          if (j + nums[j] >= nums.size() - 1) return true;
        }
      }
      return false;
    }
};
