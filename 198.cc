


// Time Limit Exceeded
class Solution {
  public:
    int robHelper(vector<int>& nums, int idx, bool lastRobbed, int res) {
      if (idx == nums.size()) return res;
      int rob = 0;
      int unrob = robHelper(nums, idx + 1, false, res);
      if (!lastRobbed) rob = robHelper(nums, idx + 1, true, res + nums[idx]);
      return max(rob, unrob);
    }

    int rob(vector<int>& nums) {
      int size = nums.size();
      if (size == 0) return 0;
      if (size == 1) return nums[1];
      if (size == 2) return max(nums[0], nums[1]);
      return robHelper(nums, 0 , false, 0);
    }
};

class Solution {
  public:
    int robHelper(vector<int>& nums, int idx) {
      if (idx == 0) return nums[0];
      if (idx == 1) return max(nums[0], nums[1]);
      if (idx == 2) return max(nums[0] + nums[2], nums[1]);
      return max(robHelper(nums, idx - 2) + nums[idx], robHelper(nums, idx - 1));
    }

    int rob(vector<int>& nums) {
      int size = nums.size();
      if (size == 0) return 0;
      if (size == 1) return nums[1];
      if (size == 2) return max(nums[0], nums[1]);
      return robHelper(nums, size - 1);
    }
};
