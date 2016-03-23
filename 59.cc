class Solution {
public:
    void generate(vector<vector<int>>& res, int n, int val, int i, int j, int direc) {
        res[i][j] = val;
        if (val == n * n) return;
        val++;
        switch(direc) {
            case 0:
                if (j + 1 == n || res[i][j + 1]) {
                    direc = 1;
                    return generate(res, n, val, i + 1, j, direc);
                } else {
                    return generate(res, n, val, i, j + 1, direc);
                }
                break;
            case 1:
                if (i + 1 == n || res[i + 1][j]) {
                    direc = 2;
                    return generate(res, n, val, i, j - 1, direc);
                } else {
                    return generate(res, n, val, i + 1, j, direc);
                }
                break;
            case 2:
                if (j - 1 < 0 || res[i][j - 1]) {
                    direc = 3;
                    return generate(res, n, val, i - 1, j, direc);
                } else {
                    return generate(res, n, val, i, j - 1, direc);
                }
                break;
            case 3:
                if (i - 1 < 0 || res[i - 1][j]) {
                    direc = 0;
                    return generate(res, n, val, i, j + 1, direc);
                } else {
                    return generate(res, n, val, i - 1, j, direc);
                }
                break;
            default: break;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if (n == 0) return res;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
                tmp.push_back(0);
            res.push_back(tmp);
        }
        generate(res, n, 1, 0, 0, 0);
        return res;
    }
};