class Solution {
public:
    vector<vector<int>> indexOfZeros(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    } 
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeros = indexOfZeros(matrix);
        vector<vector<int>>::iterator ite = zeros.begin();
        while (ite != zeros.end()) {
            int i = (*ite)[0];
            int j = (*ite)[1];
            for (int m = 0; m < matrix.size(); m++)
                matrix[m][j] = 0;
            for (int m = 0; m < matrix[0].size(); m++)
                matrix[i][m] = 0;
            ite++;
        }
    }
};