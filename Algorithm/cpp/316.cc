class Solution {
  public:
    string removeDuplicateLetters(string s) {
      vector<int> mp(26);
      for (int i = 0; i < s.size(); i++)
        mp[s[i] - 'a']++;
      stack<char> S;
      vector<bool> visited(26, false);
      for (int i = 0; i < s.size(); i++) {
        mp[s[i] - 'a']--;
        if (visited[s[i] - 'a']) continue;
        while (!S.empty() && S.top() >= s[i] && mp[S.top() - 'a'] > 0) {
          visited[S.top() - 'a'] = false;
          S.pop();
        }
        S.push(s[i]);
        visited[s[i] - 'a'] = true;
      }
      string result = "";
      while (!S.empty()) {
        result = S.top() + result;
        S.pop();
      }
      return result;
    }
};
