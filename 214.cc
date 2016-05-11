

// Time Limit Exceeded
class Solution {
  public:
    bool isPalindrome(string& str, size_t begin, size_t end) {
      while (begin <= end) {
        if (str[begin++] != str[end--]) return false;
      }
      return true;
    }
    string shortestPalindrome(string s) {
      size_t len = s.size();
      for (; len > 1; len--)
        if (isPalindrome(s, 0, len - 1)) break;
      string res(s);
      for (size_t i = len; i < s.size(); i++)
        res.insert(0, 1, s[i]);
      return res;
    }
};
