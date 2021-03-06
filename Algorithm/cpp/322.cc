class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      int Max = amount + 1;
      vector<int> dp(amount + 1, Max);
      dp[0] = 0;
      for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
          if (coins[j] <= i) {
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
          }
        }
      }
      return dp[amount] > amount ? -1 : dp[amount];
    }
};

// Time Limit Exceeded
class Solution {
  public:
    int coinChangeHelper(vector<int>& coins, int idx, int left) {
      if (idx == -1) return -1;
      if (left % coins[idx] == 0) return left / coins[idx];
      int count = INT_MAX;
      for (int i = left / coins[idx]; i >= 0; i--) {
        int sub = coinChangeHelper(coins, idx - 1, left - coins[idx] * i);
        if (sub != -1)
          count = count < sub + i ? count : sub + i;
      }
      return count == INT_MAX ? -1 : count;
    }

    int coinChange(vector<int>& coins, int amount) {
      int size = coins.size();
      if (size == 0) return -1;
      if (amount <= 0) return 0;
      sort(coins.begin(), coins.end());
      return coinChangeHelper(coins, size - 1, amount);
    }
};
