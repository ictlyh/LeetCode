


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
