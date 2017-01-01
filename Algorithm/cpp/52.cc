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

    void NQueensHelper(int n, int i, vector<int>& queens, int& count) {
      if (i == n) {
        count++;
        return;
      }
      for (int j = 0; j < n; j++) {
        if (satisfied(n, j, queens)) {
          queens.push_back(j);
          NQueensHelper(n, i + 1, queens, count);
          queens.pop_back();
        }
      }
    }

    int totalNQueens(int n) {
      int count = 0;
      vector<int> queens;
      NQueensHelper(n, 0, queens, count);
      return count;
    }
};
