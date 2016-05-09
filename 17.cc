class Solution {
  public:
    void letterCombinationsHelper(string& digits, unordered_map<int, string>& maps,
        int idx, string tmp, vector<string>& res) {
      if (idx > digits.size()) return;
      if (idx == digits.size()) res.push_back(tmp);
      if (idx < digits.size()) {
        for (size_t i = 0; i < maps[digits[idx] - '0'].size(); i++) {
          letterCombinationsHelper(digits, maps, idx + 1,
              tmp + maps[digits[idx] - '0'][i], res);
        }
      }
    }

    vector<string> letterCombinations(string digits) {
      vector<string> res;
      if (digits.empty()) return res;
      unordered_map<int, string> maps;
      maps[2] = string("abc");
      maps[3] = string("def");
      maps[4] = string("ghi");
      maps[5] = string("jkl");
      maps[6] = string("mno");
      maps[7] = string("pqrs");
      maps[8] = string("tuv");
      maps[9] = string("wxyz");
      letterCombinationsHelper(digits, maps, 0, string(""), res);
      return res;
    }
};
