class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
      for (int i = 0; i < nums.size(); i++)
        if (i == 0 || nums[i - 1] < nums[i])
          if (i == nums.size() - 1 || nums[i] > nums[i + 1])
            return i;
      return -1;
    }
};
class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
      int size = nums.size();
      if (size <= 1) return 0;
      if (size == 2) return nums[0] > nums[1] ? 0 : 1;
      if (nums[0] > nums[1]) return 0;
      if (nums[size  -1] > nums[size - 2]) return size - 1;
      int mid = nums.size() / 2;
      if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
      if (nums[mid] > nums[mid - 1]) {
        for (int i = mid + 1; i < size - 1; i++) {
          if (nums[i] > nums[i + 1]) return i;
        }
      }
      if (nums[mid] < nums[mid - 1]) {
        for (int i = mid - 1; i > 0; i--) {
          if (nums[i] > nums[i - 1]) return i;
        }
      }
    }
};
