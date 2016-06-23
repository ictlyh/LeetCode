vector<vector<int>> generateMatrix(int n) {
  // 2d vector initialization  vector<vector<int>> myvec(rowsize,vector<int>(colsize,0));
  vector<vector<int>> res(n,vector<int>(n,0));
  if(!n) return res;

  int l=0,r=n-1,t=0,b=n-1,limit=n*n+1;  // l=left column , r=right column , t=top row, b=bottom row 
  int count=1;

  while(count<limit){         // loop until count == n*n 
    for(int i=l;i<=r;i++) res[t][i]=count++; // process top row
    t++;
    for(int i=t;i<=b;i++) res[i][r]=count++; // process right column
    r--;
    if(count==limit) break;         // termination condition to avoid overwritting          
    for(int i=r; i>=l;i--) res[b][i]=count++; // process bottom row
    b--;
    for(int i=b;i>=t;i--) res[i][l]=count++;  //process left column
    l++;
  }

  return res;
}
class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> res;
      if (n == 0) return res;
      for (int i = 0; i < n; i++)
        res.push_back(vector<int>(n, 0));
      int direction = 1;
      int i = 0;
      int j = 0;
      for (int k = 1; k <= n * n; k++) {
        res[i][j] = k;
        switch (direction) {
          case 1:
            if (j + 1 < n && !res[i][j + 1])
              j++;
            else {
              direction = 2;
              i++;
            }
            break;
          case 2:
            if (i + 1 < n && !res[i + 1][j])
              i++;
            else {
              direction = 3;
              j--;
            }
            break;
          case 3:
            if (j > 0 && !res[i][j - 1])
              j--;
            else {
              direction = 4;
              i--;
            }
            break;
          case 4: {
                    if (i > 0 && !res[i - 1][j])
                      i--;
                    else {
                      direction = 1;
                      j++;
                    }
                    break;
                  }
        }
      }
      return res;
    }
};
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
