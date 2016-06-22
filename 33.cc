class Solution {
  public:
    int search(vector<int>& nums, int target) {
      //sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++)
        if (nums[i] == target) return i;
      return -1;
    }
};

https://leetcode.com/discuss/94276/simple-concise-solution-detailed-explanation-thought-process
class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int l = 0, r = nums.size() - 1;

      while(l <= r){ 
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > nums[r]){
          if(target > nums[mid] || target <= nums[r]) l = mid + 1;   // condition for pick right side
          else r = mid - 1;    // else, pick left side
        }else{
          if(target <= nums[r] && target > nums[mid]) l = mid + 1;  // condition for pick right side
          else r = mid - 1;     // else, pick left side
        } 
      }
      return -1;
    }
};
