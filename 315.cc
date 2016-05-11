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
