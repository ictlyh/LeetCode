class Solution {
  public:
    int lengthOfLastWord(string s) {
      int i = s.size() - 1;
      for (; i >= 0; i--)
        if (s[i] != ' ') break;
      if (i == 0) return 1;
      if (i == -1) return 0;
      int j = i;
      for (; j >= 0; j--)
        if (s[j] == ' ') break;
      return i - j;
    }
};
