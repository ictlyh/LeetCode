class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      int m = matrix.size();
      if (m == 0) return res;
      int n = matrix[0].size();
      if (n == 0) return res;
      int l = 0, r = n - 1, t = 0, d = m - 1;
      while (res.size() < m * n) {
        for (int i = l; i <= r; i++)
          res.push_back(matrix[t][i]);
        t++;
        for (int i = t; i <= d; i++)
          res.push_back(matrix[i][r]);
        r--;
        if (res.size() == m * n) return res;
        for (int i = r; i >= l; i--)
          res.push_back(matrix[d][i]);
        d--;
        for (int i = d; i >= t; i--)
          res.push_back(matrix[i][l]);
        l++;
      }
      return res;
    }
};
class Solution {
  public:
    void spiral(vector<vector<int>>& matrix, vector<vector<bool>>& visited,
        int i, int j, int direc, vector<int>& res) {
      int m = matrix.size();
      int n = matrix[0].size();
      if (res.size() == m * n) return;
      res.push_back(matrix[i][j]);
      visited[i][j] = true;
      switch(direc) {
        case 0:
          if (j + 1 == n || visited[i][j + 1]) {
            direc = 1;
            return spiral(matrix, visited, i + 1, j, direc, res);
          } else {
            return spiral(matrix, visited, i, j + 1, direc, res);
          }
          break;
        case 1:
          if (i + 1 == m || visited[i + 1][j]) {
            direc = 2;
            return spiral(matrix, visited, i, j - 1, direc, res);
          } else {
            return spiral(matrix, visited, i + 1, j, direc, res);
          }
          break;
        case 2:
          if (j - 1 < 0 || visited[i][j - 1]) {
            direc = 3;
            return spiral(matrix, visited, i - 1, j, direc, res);
          } else {
            return spiral(matrix, visited, i, j - 1, direc, res);
          }
          break;
        case 3:
          if (i - 1 < 0 || visited[i - 1][j]) {
            direc = 0;
            return spiral(matrix, visited, i, j + 1, direc, res);
          } else {
            return spiral(matrix, visited, i - 1, j, direc, res);
          }
          break;
        default: break;
      }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      int m = matrix.size();
      if (m == 0) return res;
      int n = matrix[0].size();
      if (n == 0) return res;
      vector<vector<bool>> visited;
      for (int i = 0; i < m; i++) {
        vector<bool> row;
        for (int j = 0; j < n; j++)
          row.push_back(false);
        visited.push_back(row);
      }
      spiral(matrix, visited, 0, 0, 0, res);
      return res;
    }
};
