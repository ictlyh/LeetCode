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