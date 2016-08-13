class Solution {
  public:
    bool Find(vector<vector<int> > array,int target) {
      int m = array.size();
      if (0 == m) return false;
      int n = array[0].size();
      if (0 == n) return false;
      int i = m - 1, j = 0;
      for (; i >= 0; i--) {
        if (array[i][j] == target) return true;
        if (array[i][j] < target) {
          j++;
          for (int k = j; k < n; k++)
            if (array[i][k] == target) return true;
        }
      }
      return false;
    }
};
