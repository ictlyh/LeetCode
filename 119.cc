class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> matrix;
        for (int i = 0; i <=rowIndex; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    row.push_back(1);
                else row.push_back(matrix[i - 1][j - 1] + matrix[i - 1][j]);
            }
            matrix.push_back(row);
        }
        return matrix[rowIndex];
    }
};

// Time Limit Exceeded
class Solution {
public:
    int getValue(int row, int col) {
        if (col == 0 || row == col) return 1;
        else return getValue(row - 1, col - 1) + getValue(row - 1, col);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i <=rowIndex; i++)
            res.push_back(getValue(rowIndex, i));
        return res;
    }
};