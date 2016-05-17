

// Time Limit Exceeded
class Solution {
  public:
    bool isPalindrome(string& str, size_t begin, size_t end) {
      while (begin <= end) {
        if (str[begin++] != str[end--]) return false;
      }
      return true;
    }

    int minCutHelper(string&s, int begin, int end) {
      if (end - begin == 0) return 0;
      string str = s.substr(begin, end - begin + 1);
      if (isPalindrome(str, 0 , str.size() - 1)) return 0;
      int count = str.size() - 1;
      for (int i = begin; i < end; i++) {
        int head = minCutHelper(s, begin, i);
        int tail = minCutHelper(s, i + 1, end);
        count = count < head + tail + 1 ? count : head + tail + 1;
      }
      return count;
    }

    int minCut(string s) {
      if (s.size() < 2) return 0;
      return minCutHelper(s, 0, s.size() - 1);
    }
};
