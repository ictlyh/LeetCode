class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int depth = triangle.size();
      for (int i = depth - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++)
          triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
      }
      return triangle[0][0];
    }
};
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
