class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i;
        for (i = matrix.size() - 1; i >=0; i--) {
            if (matrix[i][0] <= target) break;
        }
        if (i == -1) return false;
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == target) return true;
        }
        return false;
    }
};