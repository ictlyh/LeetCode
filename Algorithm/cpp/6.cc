class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows <= 1) return s;
      vector<string> res(numRows);
      int n = s.length();
      for (int i = 0, j = 0, inc = -1; i < n; ++i, j += inc) {
        res[j] += s[i];
        if (j == 0 || j == numRows-1)
          inc = -inc;
      }
      string result;
      for (int i = 0; i < numRows; ++i)
        result += res[i];
      return result;
    }
};
