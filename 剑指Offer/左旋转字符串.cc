class Solution {
  public:
    void reverse(string& str, int b, int e) {
      while (b < e) {
        swap(str[b++], str[e--]);
      }
    }
    string LeftRotateString(string str, int n) {
      if (str.size() < 2) return str;
      n = n % str.size();
      if (n == 0) return str;
      reverse(str, 0, n - 1);
      reverse(str, n, str.size() - 1);
      reverse(str, 0, str.size() - 1);
      return str;
    }
};
