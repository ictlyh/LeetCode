class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0)  return false;
        int col = board.size();
        int row = board[0].size();
        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                if(find(board, i, j, 0, word))  return true;
            }
        }
        return false;
    }

    bool find(vector<vector<char>>& board, int i, int j, int idx, string word){
        if(idx == word.size())   return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())  return false;
        if(board[i][j] != word[idx] || board[i][j] == '*')  return false;
        char ch=board[i][j];
        board[i][j]='*';
        bool result= find(board, i + 1, j, idx + 1, word) ||
                     find(board, i - 1, j, idx + 1, word) ||
                     find(board, i, j + 1, idx + 1, word) ||
                     find(board, i, j - 1, idx + 1, word);
        board[i][j]=ch;
        return result;
    }
};