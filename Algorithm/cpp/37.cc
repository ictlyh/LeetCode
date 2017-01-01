class Solution {
	public:
		void solveSudoku(vector<vector<char>>& board) {
			help(board, 0, 0);
		}
		bool help(vector<vector<char>>& board, int row, int col){
			if(row == 9)
				return true;
			if(col == 9)
				return help(board, row+1, 0);
			if(board[row][col] != '.')
				return help(board, row, col+1);
			for(int i=1; i<=9; i++){
				if(isValid(board, row, col, i)){
					board[row][col] = i+'0';
					if(help(board, row, col+1))
						return true;
					board[row][col] = '.';
				}
			}
			return false;
		}
		bool isValid(vector<vector<char>>& board, int row, int col, int num){
			for(int i=0; i<9; i++){
				if(board[i][col] == num+'0')
					return false;
			}
			for(int j=0; j<9; j++){
				if(board[row][j] == num+'0')
					return false;
			}
			for(int i=(row/3)*3; i<(row/3)*3+3; i++){
				for(int j=(col/3)*3; j<(col/3)*3+3; j++){
					if(board[i][j] == num+'0')
						return false;
				}
			}
			return true;
		}
};
