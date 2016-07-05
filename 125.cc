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
class Solution {
  public:
    bool isPalindrome(string s) {
      int j = 0;
      for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
          s[j++] = tolower(s[i]);
        } else if (isdigit(s[i]))
          s[j++] = s[i];
      }
      s.resize(j);
      for (int l = 0, r = j - 1; l < r; l++, r--)
        if (s[l] != s[r]) return false;
      return true;
    }
};
