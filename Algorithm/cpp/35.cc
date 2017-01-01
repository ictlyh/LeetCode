int searchInsert(vector<int>& nums, int target) {
  if (target > nums.back()) return nums.size();
  int left = 0, right = nums.size() - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] >= target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      if (nums.size() == 0) return 0;
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums[mid] == target)
          return mid;
        else if (nums[mid] < target) {
          if (mid == nums.size() - 1 || nums[mid + 1] > target)
            return mid + 1;
          else l = mid + 1;
        } else {
          if (mid == 0 || nums[mid - 1] < target)
            return mid;
          else r = mid - 1;
        }
      }
      return l;
    }
};
class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) return i;
      }
      return nums.size();
    }
};
