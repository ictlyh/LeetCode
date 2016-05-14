class Solution {
  public:
    double findMedianSortArray(vector<int>& nums) {
      int size = nums.size();
      if (size == 1) return nums[0];
      int mid = size / 2;
      if (size % 2) return nums[mid];
      else return (nums[mid] + nums[mid - 1]) / 2.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> nums;
      int i = 0, j = 0;
      while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) nums.push_back(nums1[i++]);
        else nums.push_back(nums2[j++]);
      }
      while (i < nums1.size())
        nums.push_back(nums1[i++]);
      while (j < nums2.size())
        nums.push_back(nums2[j++]);
      return findMedianSortArray(nums);
    }
};
