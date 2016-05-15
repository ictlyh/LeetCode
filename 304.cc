class NumMatrix {
  public:
    vector<vector<int>> matrix_;
    NumMatrix(vector<vector<int>> &matrix) {
      int m = matrix.size();
      if (m == 0)
        matrix_.push_back(vector<int>(1, 0));
      else {
        int n = matrix[0].size();
        if (n == 0) matrix_.push_back(vector<int>(1, 0));
        else {
          matrix_.push_back(vector<int>(n + 1, 0));
          for (int i = 0; i < m; i++) {
            vector<int> row;
            row.push_back(0);
            for (int j = 0; j < n; j++)
              row.push_back(matrix[i][j] + row.back() + matrix_[i][j + 1] - matrix_[i][j]);
            matrix_.push_back(row);
          }
        }
      }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      return matrix_[row2 + 1][col2 + 1] \
        - matrix_[row2 + 1][col1] \
        - matrix_[row1][col2 + 1] \
        + matrix_[row1][col1];
    }
};

// Time Limit Exceeded
class NumMatrix {
  public:
    vector<vector<int>> matrix_;
    NumMatrix(vector<vector<int>> &matrix) {
      matrix_ = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      int sum = 0;
      for (int i = row1; i <= row2; i++)
        for (int j = col1; j <= col2; j++)
          sum += matrix_[i][j];
      return sum;
    }
};
