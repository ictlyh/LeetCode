

// Time Limit Exceeded
class Solution {
  public:
    bool isPalindrome(string str) {
      int i = 0;
      int j = str.size() - 1;
      while (i <= j) {
        if (str[i++] != str[j--]) return false;
      }
      return true;
    }

    string longestPalindrome(string s) {
      if (s.size() < 3) return s;
      for (int i = s.size(); i > 2; i--) {
        for (int j = 0; j <= s.size() - i; j++)
          if (isPalindrome(s.substr(j, i)))
            return s.substr(j, i);
      }
      return s.substr(0, 2);
    }
};
