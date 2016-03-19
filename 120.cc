class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> result(triangle.back());
        for(int layer=n-2; layer>=0; layer--){
            for(int i=0; i<=layer; i++){
                result[i]=min(result[i], result[i+1])+triangle[layer][i];
            }
        }
        return result[0];
    }
};


// 思路不对
class Solution {
public:
    int minimum(vector<vector<int>>& triangle, int m, int n) {
        int sum = triangle[m][n];
        for (int i = m - 1; i >= 0; i--) {
            if (n == 0) sum += triangle[i][0];
            else if (n == i + 1) sum += triangle[i][--n];
            else {
                if (triangle[i][n - 1] > triangle[i][n])
                    sum += triangle[i][n];
                else sum += triangle[i][--n];
            }
        }
        return sum;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m == 1) return triangle[0][0];
        int res = minimum(triangle, m - 1 ,0);
        for (int i = 1; i < m; i++)
            res = min(res, minimum(triangle, m - 1, i));
        return res;
    }
};