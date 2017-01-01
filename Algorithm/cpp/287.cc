class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int slow = 0, fast = 0, finder = 0;
      while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
          break;
      }
      while (true) {
        finder = nums[finder];
        slow = nums[slow];
        if (finder == slow)
          return finder;
      }
    }
};
