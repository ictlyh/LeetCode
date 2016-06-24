void rotate(vector<vector<int>>& matrix) {
  int matrixSize = matrix.size();
  if (!matrixSize) return;
  for (int i = 0; i < matrixSize; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
  for (int i = 0; i < matrixSize; i++ ) {
    for (int j = 0; j < (matrixSize - i - 1); j++) {
      swap(matrix[i][j], matrix[matrixSize - j - 1][matrixSize - i - 1]);
    }
  }
}
class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
      vector<vector<int>> res;
      for (int i = 0; i < matrix[0].size(); i++) {
        vector<int> row;
        for (int j = matrix.size() - 1; j >= 0; j--)
          row.push_back(matrix[j][i]);
        res.push_back(row);
      }
      matrix = res;
    }
};
