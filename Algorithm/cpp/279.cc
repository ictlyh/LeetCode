class Solution {
  public:
    int numSquares(int n) {
      vector<int> nums;
      vector<int> dp(n + 1,INT_MAX);
      int mul = 1;
      int i = 1;
      while (mul <= n) {
        if (mul == n) return 1;
        nums.push_back(mul);
        dp[mul] = 1;
        i++;
        mul = i * i;
      }
      for (int i = 1;i < n; i++)
        for (int j = 0;j < nums.size(); j++)
          if (dp[i] != INT_MAX && i + nums[j] <= n)
            dp[i + nums[j]] = min(dp[i + nums[j]], dp[i] + 1);
      return dp[n] == INT_MAX ? n : dp[n];  
    }
};
