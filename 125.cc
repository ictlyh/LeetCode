class Solution {
  public:
    string strToLower(string s) {
      for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
      return s;
    }

    bool isPalindrome(string s) {
      if (s.size() < 2) return true;
      s = strToLower(s);
      for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        while (i < j && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) i++;
        while (i < j && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))) j--;
        if (i >= j) return true;
        if (s[i] != s[j]) return false;
      }
      return true;
    }
};
