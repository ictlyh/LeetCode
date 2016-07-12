class Solution {
  public:
    int rob(vector<int>& nums) {
      int rob = 0, norob = 0;
      for (int num : nums) {
        int robcur = norob + num;
        norob = max(norob, rob);
        rob = robcur;
      }
      return max(rob, norob);
    }
};

//dp[i] indicates the maximum amount you can rob ending in indexing i
//dp[i] = max{dp[i-1], dp[i-2] + nums[i]}
class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if (n == 0) return 0;
      if (n == 1) return nums[0];
      if (n == 2) return max(nums[0], nums[1]);
      if (n == 3) return max(nums[1], nums[0] + nums[2]);
      int previous = nums[0];
      int current = max(nums[0], nums[1]);
      for (int i = 2; i < n; i++) {
        int tmp = current;
        current = max(previous + nums[i], current);
        previous = tmp;
      }
      return current;
    }
};

// Time Limit Exceeded
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
