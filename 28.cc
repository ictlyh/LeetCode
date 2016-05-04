class Solution {
  public:
    void makeNext(string pattern,vector<int>& next) {
      int q, k;
      int m = pattern.size();
      next.push_back(0);
      for (q = 1,k = 0; q < m; ++q) {
        while (k > 0 && pattern[q] != pattern[k])
          k = next[k-1];
        if (pattern[q] == pattern[k])
          k++;
        next.push_back(k);
      }
    }

    int strStr(string haystack, string needle) {
      if (needle.size() == 0) return 0;
      vector<int> next;
      makeNext(needle, next);
      for (int i = 0, q = 0; i < haystack.size(); ++i) {
        while(q > 0 && needle[q] != haystack[i])
          q = next[q-1];
        if (needle[q] == haystack[i])
          q++;
        if (q == needle.size()) return i - needle.size() + 1;
      }
      return -1;
    }
};
