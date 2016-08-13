class Solution {
  public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
      vector<int> res;
      int m = matrix.size();
      int n = matrix[0].size();
      int left = 0, right = n - 1, up = 0, down = m - 1;
      while (res.size() < m * n) {
        for (int i = left; i <= right; i++) {
          res.push_back(matrix[up][i]);
        }
        up++;
        for (int i = up; i <= down; i++) {
          res.push_back(matrix[i][right]);
        }
        right--;
        if (res.size() == m * n) break;
        for (int i = right; i >= left; i--) {
          res.push_back(matrix[down][i]);
        }
        down--;
        for (int i = down; i >= up; i--) {
          res.push_back(matrix[i][left]);
        }
        left++;
      }
      return res;
    }
};
