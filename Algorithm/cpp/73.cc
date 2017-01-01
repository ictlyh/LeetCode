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

class Solution {
  public:
    // O(1) extra space 
    void setZeroes(vector<vector<int>>& matrix) {
      int xsize = matrix.size();
      if(xsize == 0){
        return;
      }
      int ysize = matrix[0].size();

      bool fr = false, fc = false;// first row and first column
      for(int i = 0; i < xsize; ++i){
        for(int j = 0; j < ysize; ++j){
          if(matrix[i][j] == 0){
            if(i == 0){
              fr = true;
            }
            if(j == 0){
              fc = true;
            }
            matrix[i][0] = 0;
            matrix[0][j] = 0;
          }
        }
      }
      for(int i = 1; i < xsize; ++i){
        for(int j = 1; j < ysize; ++j){
          if(matrix[i][0] == 0 || matrix[0][j] == 0){
            matrix[i][j] = 0;
          }
        }
      }
      if(fr){
        for(int i = 0; i < ysize; ++i){
          matrix[0][i] = 0;
        }
      }
      if(fc){
        for(int i = 0; i < xsize; ++i){
          matrix[i][0] = 0;
        }
      }
    }
    // a naive O(m + n) extra space solution
    /*
       void setZeroes(vector<vector<int>>& matrix) {
       int xsize = matrix.size();
       if(xsize == 0){
       return;
       }
       int ysize = matrix[0].size();
       if(ysize == 0){
       return;
       }
       vector<bool> x(xsize, false);
       vector<bool> y(ysize, false);
       for(int i = 0; i < xsize; ++i){
       for(int j = 0; j < ysize; ++j){
       if(matrix[i][j] == 0){
       x[i] = true;
       y[j] = true;
       }
       }
       }
       for(int i = 0; i < xsize; ++i){
       for(int j = 0; j < ysize; ++j){
       if(x[i] || y[j]){
       matrix[i][j] = 0;
       }
       }
       }
       }
       */
};
