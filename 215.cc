class Solution {
  public:
    int partition(vector<int>& nums, int l, int r) {
      int pivotStartIndx = (r + l) / 2;
      int pivot = nums[pivotStartIndx], pivotCurrentIndx = l; 
      swap(nums[pivotStartIndx], nums[r]);
      for (int i = l; i < r; ++i) {
        if (nums[i] < pivot) {
          swap(nums[i], nums[pivotCurrentIndx]);
          ++pivotCurrentIndx;
        }
      }
      swap(nums[pivotCurrentIndx], nums[r]);
      return pivotCurrentIndx;
    }
    int findKthLargest(vector<int>& nums, int k) {
      int indx = nums.size() - k;
      int l = 0, r = nums.size() - 1;
      while (l < r) {
        int pivotFinalIndx = partition(nums, l, r);
        if (pivotFinalIndx == indx)
          return nums[pivotFinalIndx];
        else if (pivotFinalIndx < indx)
          l = pivotFinalIndx + 1;
        else
          r = pivotFinalIndx - 1;
      }
      if (nums[l] > nums[r])
        swap(nums[l], nums[r]);
      return nums[indx];    
    }
};
