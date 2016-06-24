class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      int size = nums.size();
      if (size < 3) return res;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < size - 2; i++) {
        int left = i + 1;
        int right = size - 1;
        while (left < right) {
          int sum = nums[i] + nums[left] + nums[right];
          if (sum == 0) {
            vector<int> col;
            col.push_back(nums[i]);
            col.push_back(nums[left]);
            col.push_back(nums[right]);
            res.push_back(col);
            left++;
            while (left < right && nums[left] == nums[left - 1]) left++;
            right--;
            while (left < right && nums[right] == nums[right + 1]) right--;
          } else if (sum < 0) {
            left++;
            while (left < right && nums[left] == nums[left - 1]) left++;
          } else {
            right--;
            while (left < right && nums[right] == nums[right + 1]) right--;
          }
        }
        while (i < size - 2 && nums[i] == nums[i + 1]) i++;
      }
      return res;
    }
};

class Solution {
  public:
    void threeSumHelper(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, int target, int start) {
      if (target == 0 && tmp.size() == 3) {
        res.push_back(tmp);
        return;
      } else if (tmp.size() == 3 || target < 0) return;
      else {
        for (int i = start; i < nums.size(); i++) {
          if (i == start || nums[i - 1] != nums[i]) {
            tmp.push_back(nums[i]);
            threeSumHelper(nums, res, tmp, target - nums[i], i + 1);
            tmp.pop_back();
          }
        }
      }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> res;
      vector<int> tmp;
      threeSumHelper(nums, res, tmp, 0, 0);
      return res;
    }
};
