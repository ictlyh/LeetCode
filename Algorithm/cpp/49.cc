class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> mp;
      for (string s : strs) {
        string copy = s;
        sort(copy.begin(), copy.end());
        mp[copy].push_back(s);
      }
      vector<vector<string>> result;
      for (auto kv : mp)
        result.push_back(kv.second);
      return result;   
    }
};
