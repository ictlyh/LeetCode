class Solution {
  public:
    int minDistance(string word1, string word2) {
      size_t  m = word1.size();
      size_t n = word2.size();
      vector<vector<int>> d;
      for (size_t i = 0; i <= m; i++) {
        vector<int> row(n + 1, i);
        d.push_back(row);
      }
      for (size_t j = 0; j <= n; j++) {
        d[0][j] = j;
      }
      for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= n; j++) {
          int cost = word1[i - 1] == word2[j - 1] ? 0 : 1;
          d[i][j] = min(d[i - 1][j] + 1, min(d[i][j - 1] + 1, d[i - 1][j - 1] + cost));
        }
      }
      return d[m][n];
    }
};
