class Solution {
  public:
    bool isVowels(char c) {
      if (c == 'a' || c == 'A' ||
          c == 'e' || c == 'E' ||
          c == 'i' || c == 'I' ||
          c == 'o' || c == 'O' ||
          c == 'u' || c == 'U')
        return true;
      return false;
    }

    string reverseVowels(string s) {
      if (s.size() < 2) return s;
      for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        while (i < j && !isVowels(s[i])) i++;
        while (i < j && !isVowels(s[j])) j--;
        if (i >= j) return s;
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
      }
      return s;
    }
};
