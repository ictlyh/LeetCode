//do dynamic programming from 0----->n-2 and 1----->n-1 repsectively, and get the maximum
//dp[i] indicates the maximum amount you can rob ending in indexing i
//dp[i] = max{dp[i-1], dp[i-2] + nums[i]}
class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if (n == 0) return 0;
      if (n == 1) return nums[0];
      if (n == 2) return max(nums[0], nums[1]);
      //first calcualte from 0----->n-2
      int previous = nums[0];
      int current = max(nums[0], nums[1]);
      for (int i = 2; i <= n - 2; i++) {
        int tmp = current;
        current = max(previous + nums[i], current);
        previous = tmp;
      }
      int maxInPreviousHalf = current;
      //next calculate from 1------->n-1
      previous = nums[1];
      current = max(nums[1], nums[2]);
      for (int i = 3; i <= n - 1; i++) {
        int tmp = current;
        current = max(previous + nums[i], current);
        previous = tmp;
      }
      return max(maxInPreviousHalf, current);
    }
};


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
