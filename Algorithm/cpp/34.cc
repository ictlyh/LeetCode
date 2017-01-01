class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int start = findPosition(nums, target, false);
      int end = findPosition(nums, target, true);
      vector<int> res;
      res.push_back(start);
      res.push_back(end);
      return res;
    }

    int findPosition(vector<int>& nums, int target, bool isLast) {
      int low = 0, high = nums.size() - 1, index = -1;
      while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if(isLast){
          if (nums[mid] <= target) low = mid + 1;
          else high = mid-1;
        } else{
          if (nums[mid] < target) low = mid + 1;
          else high = mid-1;
        }
        if(nums[mid] == target) index = mid;
      }
      return index;
    }
};
class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      if (nums.front() > target || nums.back() < target ||
          std::find(nums.begin(), nums.end(), target) == nums.end()) {
        vector<int> res(2,-1);
        return res;
      }
      vector<int> res;
      vector<int>::iterator low = std::lower_bound(nums.begin(), nums.end(), target);
      res.push_back(low - nums.begin());
      vector<int>::iterator up = std::upper_bound(nums.begin(), nums.end(), target);
      res.push_back(up - nums.begin() - 1);
      return res;
    }
};
