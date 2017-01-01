class Solution {
  private:
    bool isValid(char c) {
      return (c >= '1' && c <= '9');
    }

    bool isValid(char c1, char c2) {
      return (c1 == '1' && c2 >= '0' && c2 <= '9') ||
        (c1 == '2' && c2 >= '0' && c2 <= '6');
    }

  public:
    int numDecodings(string s) {
      int size = s.size();
      if (size == 0 || s[0] == '0') return 0;
      vector<int> dp(size + 1, 0);
      dp[0] = dp[1] = 1;
      for (int i = 1; i < size; i++) {
        if (isValid(s[i]))
          dp[i + 1] += dp[i];
        if (isValid(s[i - 1], s[i]))
          dp[i + 1] += dp[i - 1];
      }
      return dp[size];
    }
};


// Time Limit Exceeded
class Solution {
  public:
    void numDecodingsHelper(string& s, int idx, int lastVal, int& count) {
      if (idx > s.size() || lastVal > 26) return;
      if (idx == s.size() && lastVal <= 26) count++;
      numDecodingsHelper(s, idx + 1, 10 * lastVal + s[idx] - '0', count);
      numDecodingsHelper(s, idx + 1, s[idx] - '0', count);
    }

    int numDecodings(string s) {
      if (s.size() < 2) return s.size();
      int count = 0;
      numDecodingsHelper(s, 1, s[0] - '0', count);
      return count;
    }
};
