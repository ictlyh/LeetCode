class Solution {
  public:
    vector<int> countSmaller(vector<int>& nums) {
      vector<int> ans(nums.size(), 0), sortedNums;
      for(int i = nums.size() - 1; i >= 0; i--){
        int idx = binarySearch(sortedNums, nums[i]);
        ans[i] = idx;
        sortedNums.insert(sortedNums.begin() + idx, nums[i]);
      }
      return ans;
    }
    // find the first position greater than or equal to target in sortedNums
    int binarySearch(vector<int>& sortedNums, int target){
      int l = 0, r = sortedNums.size();
      while(l < r){
        int m = l + (r - l) / 2; 
        if(sortedNums[m] < target) l = m + 1;
        else r = m;
      }
      return l;
    }
};
class Solution {
  public:
    vector<int> countSmaller(vector<int>& nums) {
      vector<int> db;
      vector<int> result(nums.size());
      for(int i = nums.size() - 1; i >= 0; i--) {
        auto it = lower_bound(db.begin(), db.end(), nums[i]);
        result[i] = it - db.begin();
        db.insert(it, nums[i]);
      }
      return result;
    }
};

// Time Limit Exceeded
class Solution {
  public:
    vector<int> countSmaller(vector<int>& nums) {
      vector<int> res(nums.size(), 0);
      for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++)
          res[i] += nums[j] < nums[i] ? 1 : 0;
      }
      return res;
    }
};
