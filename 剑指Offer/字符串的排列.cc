class Solution {
  public:
    vector<string> Permutation(string str) {
      vector<string> res;
      if (str.size() == 0) return res;
      PermutationHelper(str, 0, res);
      //　按字典序排列
      sort(res.begin(), res.end());
      //　去重
      vector<string>::iterator ite = res.begin();
      while (ite != res.end()) {
        vector<string>::iterator tmp = ite;
        tmp++;
        if (tmp != res.end() && *ite == *tmp) {
          res.erase(tmp);
        } else ite++;
      }
      return res;
    }
    void PermutationHelper(string str, int idx, vector<string>& res) {
      if (idx == str.size()) {
        res.push_back(str);
        return;
      }
      for (int i = idx; i < str.size(); i++) {
        swap(str[i], str[idx]);
        PermutationHelper(str, idx + 1, res);
        swap(str[i], str[idx]);
      }
    }
};
