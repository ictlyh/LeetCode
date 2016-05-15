


// Time Limit Exceeded
class Solution {
  public:
    int robCircleHelper(vector<int>& nums, int idx, bool lastRobbed, bool firstRobbed, int res) {
      if (idx == nums.size()) return res;
      int rob = 0;
      int unrob = robCircleHelper(nums, idx + 1, false, firstRobbed, res);
      if (!lastRobbed){
        if (idx == nums.size() - 1)
          rob = firstRobbed ? res : res + nums[idx];
        else rob = robCircleHelper(nums, idx + 1, true, firstRobbed, res + nums[idx]);
      }
      return max(rob, unrob);
    }

    int rob(vector<int>& nums) {
      int size = nums.size();
      if (size == 0 || size == 2) return 0;
      if (size == 1) return nums[1];
      if (size == 3) return max(nums[0], max(nums[1], nums[2]));
      return max(robCircleHelper(nums, 1, false, false, 0), robCircleHelper(nums, 1, true, true, nums[0]));
    }
};
