
// Time Limit Exceeded
class Solution {
  public:
    void wordBreakHelper(string& s,  unordered_set<string>& wordDict, int maxlen, int idx, vector<int> pos, vector<string>& res) {
      if (idx == s.size()) {
        pos.pop_back();
        string tmp(s.size() + pos.size(), ' ');
        for (int i = tmp.size() - 1; i >= 0; i--) {
          if (pos.empty() || i - pos.size() + 1 != pos.back())
            tmp[i] = s[i - pos.size()];
          else
            pos.pop_back();
        }
        res.push_back(tmp);
        return;
      }
      for (int i = 1; i <= maxlen && idx + i <= s.size(); i++) {
        if (wordDict.find(s.substr(idx, i)) != wordDict.end()) {
          pos.push_back(idx + i);
          wordBreakHelper(s, wordDict, maxlen, idx + i, pos, res);
          pos.pop_back();
        }
      }
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
      vector<string> res;
      int maxlen = 0;
      for (string str : wordDict)
        maxlen = maxlen > str.size() ? maxlen : str.size();
      vector<int> pos;
      wordBreakHelper(s, wordDict, maxlen, 0, pos, res);
      return res;
    }
};
