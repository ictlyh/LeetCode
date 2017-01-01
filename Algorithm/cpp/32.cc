class Solution {
  public:
    int longestValidParentheses(string s) {
      int ans = 0, l = s.size(), sum = 0, start = 0;
      for (int i = 0; i < l; i++) {
        sum += (s[i] == '(')? 1 : -1;
        if (sum < 0) {
          sum = 0;
          start = i + 1;
        } else if (sum == 0) {
          ans = max(ans, i - start + 1);
        }
      }
      start = l - 1;
      sum = 0;
      for (int i = l - 1; i >= 0; i--) {
        sum += (s[i] == '(')? 1 : -1;
        if (sum > 0) {
          sum = 0;
          start = i - 1;
        } else if (sum == 0) {
          ans = max(ans, start - i + 1);
        }
      }
      return ans;
    }
};


// Time Limit Exceeded
class Solution {
  public:
    bool validParenthesis(string str) {
      stack<char> st;
      size_t size = str.size();
      for (size_t i = 0; i < size; i++) {
        if (str[i] == '(') st.push(str[i]);
        else if (str[i] == ')') {
          if (st.empty()) return false;
          else st.pop();
        } else return false;
      }
      return st.empty();
    }

    int longestValidParentheses(string s) {
      if (s.size() < 2) return 0;
      for (size_t i = s.size(); i > 1; i--) {
        for (size_t j = 0; j <= s.size() - i; j++)
          if (validParenthesis(s.substr(j, i)))
            return i;
      }
      return 0;
    }
};
