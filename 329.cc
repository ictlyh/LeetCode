
// Time Limit Exceeded
class Solution {
  public:
    int longestIncreasingPathDFS(vector<vector<int>>& matrix, int i, int j, int cur_len) {
      int len = cur_len;
      if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
        len = max(len, longestIncreasingPathDFS(matrix, i - 1, j, cur_len + 1));
      if (i + 1 < matrix.size() && matrix[i + 1][j] > matrix[i][j])
        len = max(len, longestIncreasingPathDFS(matrix, i + 1, j, cur_len + 1));
      if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
        len = max(len, longestIncreasingPathDFS(matrix, i, j - 1, cur_len + 1));
      if (j + 1 < matrix[0].size() && matrix[i][j + 1] > matrix[i][j])
        len = max(len, longestIncreasingPathDFS(matrix, i, j + 1, cur_len + 1));
      return len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int len = 0;
      for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
          len = max(len, longestIncreasingPathDFS(matrix, i, j, 1));
      return len;
    }
};
