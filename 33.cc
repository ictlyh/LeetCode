class Solution {
  public:
    int search(vector<int>& nums, int target) {
      //sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++)
        if (nums[i] == target) return i;
      return -1;
    }
};
class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] <= nums[r]) {
          if (target > nums[mid] && target <= nums[r])
            l = mid + 1;
          else r = mid - 1;
        } else {
          if (target < nums[mid] && target >= nums[l])
            r = mid - 1;
          else l = mid + 1;
        }
      }
      return -1;
    }
};
