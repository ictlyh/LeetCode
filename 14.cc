class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.size() == 0) return "";
      if (strs.size() == 1) return strs[0];
      int min_size = INT_MAX;
      for (int i = 0; i < strs.size(); i++)
        min_size = min_size < strs[i].size() ? min_size : strs[i].size();
      int i = 0;
      for (; i < min_size; i++) {
        for (int j = 1; j < strs.size(); j++) {
          if (strs[0][i] != strs[j][i])
            return strs[0].substr(0, i);
        }
      }
      return strs[0].substr(0, min_size);
    }
};
