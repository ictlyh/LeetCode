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