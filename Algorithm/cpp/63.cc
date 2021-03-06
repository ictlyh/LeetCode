﻿class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      if (m == 0 || n == 0) return 0;
      vector<int> x(m, 1);
      vector<int> y(n, 1);
      for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1) {
          for (; i < m; i++)
            x[i] = 0;
        }
      }
      for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 1) {
          for (; i < n; i++)
            y[i] = 0;
        }
      }
      for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (obstacleGrid[i][j] == 1)
            y[j] = 0;
          else if (j == 0)
            y[j] = x[i];
          else y[j] += y[j - 1];
        }
      }     
      return y[n - 1];
    }
};
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      int matrix[m][n];
      for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 0)
          matrix[i][0] = 1;
        else {
          for (; i < m; i++)
            matrix[i][0] = 0;
        }
      }
      for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 0)
          matrix[0][i] = 1;
        else {
          for (; i < n; i++)
            matrix[0][i] = 0;
        }
      }
      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          if (obstacleGrid[i][j] == 1)
            matrix[i][j] = 0;
          else matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }
      }     
      return matrix[m - 1][n - 1];
    }
};
