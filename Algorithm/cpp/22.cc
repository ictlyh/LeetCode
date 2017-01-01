class Solution {
  public:
    void generateParenthesisHelper(int open, int close, string s, vector<string>& res) {
      if (open < 0 || close < 0 || open > close) return ;
      if (open == 0 && close == 0) res.push_back(s);
      generateParenthesisHelper(open - 1, close, s + '(', res);
      generateParenthesisHelper(open, close - 1, s + ')', res);
    }

    vector<string> generateParenthesis(int n) {
      vector<string> res;
      generateParenthesisHelper(n, n, "", res);
      return res;
    }
};
