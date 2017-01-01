class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      vector<pair<long, int>> vec;
      for (int i = 0; i < nums.size(); ++i) {
        vec.push_back(make_pair(nums[i], i));
      }
      sort(vec.begin(), vec.end());
      for (int i = 0; i < nums.size(); ++i) 
        for (int j = i + 1; j < nums.size() && vec[j].first-vec[i].first <= t; j++)
          if (abs(vec[j].second-vec[i].second) <= k)
            return true;
      return false;
    }
};


// Time Limit Exceeded
class Solution {
  public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      int size = nums.size();
      for (int i = 0; i < size - 1; i++) {
        for (int j = 1; j <= k && i + j < size; j++)
          if (abs(nums[i] - nums[i + j]) <= t) return true;
      }
      return false;
    }
};
