class Solution {
  public:
    bool satisfied(int n, int i, vector<int>& queens) {
      for (int j = 0; j < queens.size(); j++) {
        if (i == queens[j]) return false;
        if (abs(int(j - queens.size())) == abs(queens[j] - i))
          return false;
      }
      return true;
    }

    void NQueensHelper(int n, int i, vector<int>& queens, vector<vector<int>>& res) {
      if (i == n) {
        res.push_back(queens);
        return;
      }
      for (int j = 0; j < n; j++) {
        if (satisfied(n, j, queens)) {
          queens.push_back(j);
          NQueensHelper(n, i + 1, queens, res);
          queens.pop_back();
        }
      }
    }

    vector<vector<string>> solveNQueens(int n) {
      vector<vector<int>> res;
      vector<int> queens;
      NQueensHelper(n, 0, queens, res);
      vector<vector<string>> result;
      for (int i = 0; i < res.size(); i++) {
        vector<string> tmp;
        for (int j = 0; j < n; j++) {
          string str(n, '.');
          str[res[i][j]] = 'Q';
          tmp.push_back(str);
        }
        result.push_back(tmp);
      }
      return result;
    }
};
