class Solution {
public:
    bool nextState(vector<vector<int>>& board, int m, int n) {
       int live_nei = 0;
       for (int i = m - 1; i <= m + 1; i++) {
           if (i < 0 || i >= board.size()) continue;
           for (int j = n - 1; j <= n + 1; j++) {
               if (j < 0 || j >= board[0].size()) continue;
               live_nei += board[i][j];
           }
       }
       live_nei -= board[m][n];
       if (board[m][n] == 1) {
           if (live_nei < 2 || live_nei > 3) return false;
           else return true;
       } else {
           if (live_nei == 3) return true;
           else return false;
       }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> backup(board);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (nextState(backup, i, j)) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};