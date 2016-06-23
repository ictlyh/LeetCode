class Solution {
  public:
    int uniquePaths(int m, int n) {
      if (m == 0 || n == 0) return 0;
      vector<int> p(n, 1);
      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++)
          p[j] += p[j - 1];
      }
      return p[n - 1];
    }
};
class Solution {
  public:
    int uniquePaths(int m, int n) {
      int matrix[m][n];
      for (int i = 0; i < m; i++)
        matrix[i][0] = 1;
      for (int i = 0; i < n; i++)
        matrix[0][i] = 1;
      for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
          matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
      return matrix[m - 1][n - 1];
    }
};

// Time Limit Exceeded
class Solution {
  public:
    int uniquePaths(int m, int n) {
      if (m == 1 || n == 1) return 1;
      else return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
    }
};
