class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			bool valid = true;
			for(int i = 0; i < 9; i++){
				if(!isValid(board, i, 0, i, 8)){
					return false;
				}
				if(!isValid(board, 0, i, 8, i)){
					return false;
				}
			}
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if(!isValid(board, 3 * i, 3 * j, 3 * i + 2, 3 * j + 2)){
						return false;
					}
				}
			}
			return true;
		}

		bool isValid(vector<vector<char>>& board, int startX, int startY, int endX, int endY){
			int temp=0;
			for(int i = startX; i <= endX; i++){
				for(int j = startY; j <= endY; j++){
					if(board[i][j] == '.'){
						continue;
					}
					int k = board[i][j] - '0';
					if((temp & (1 << k)) != 0){
						return false;
					}
					temp = temp | (1 << k);
				}
			}
			return true;
		}
};
