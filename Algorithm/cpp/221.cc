int maximalSquare(vector<vector<char>>& matrix) {
  if (matrix.size() == 0) return 0;
  vector<int> temp(matrix[0].size(), 0);
  vector<vector<int>> dp(matrix.size(), temp);
  int max_len = 0;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == '0') continue;
      if (i == 0 || j == 0) dp[i][j] = 1;
      else dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j],dp[i - 1][j - 1])) + 1;
      if (dp[i][j] > max_len) max_len = dp[i][j];
    }
  }
  return max_len * max_len;
}
