


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
