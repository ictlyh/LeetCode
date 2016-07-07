class Solution {
  public:
    vector<string> letterCombinations(string digits) {
      vector<string> res;
      if (!digits.size()) return res;
      string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      res.push_back(string(digits.size(), '\0'));
      for (int i = 0; i < digits.size(); i++) {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
          for (int j = 0; j < res.size();j++) {
            res[j][i] = chars[c];
            tempres.push_back(res[j]);
          }
        res = tempres;
      }
      return res;
    }
};
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
