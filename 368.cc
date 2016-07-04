class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      vector<int> res;
      if (nums.size() == 0) return res;
      sort(nums.begin(), nums.end());
      vector<int> dp(nums.size(), 1);
      vector<int> lastIdx(nums.size(), -1);
      for (int i = 1; i < nums.size(); i++){
        for (int j = i - 1; j >= 0; j--){
          if (nums[i] % nums[j] == 0){
            if (dp[j] + 1 > dp[i]) {
              dp[i] = dp[j] + 1;
              lastIdx[i] = j;
            }
          }
        }
      }
      int maxIndex = 0;
      for (int i = 1; i < nums.size(); i++){
        maxIndex = dp[i] > dp[maxIndex] ?  i :  maxIndex;
      }
      for (int i = maxIndex; i >= 0;){
        res.push_back(nums[i]);
        i = lastIdx[i];
      }
      return res;
    }
};
