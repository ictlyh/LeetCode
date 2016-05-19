


// Time Limit Exceeded
class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      int size = nums.size();
      for (int i = 0; i < size - 1; i++) {
        for (int j = 1; j <= k && i + j < size; j++)
          if (abs(nums[i] - nums[i + j]) <= t) return true;
      }
      return false;
    }
};
