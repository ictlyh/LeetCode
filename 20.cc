class Solution {
  public:
    bool isValid(string s) {
      stack<char> parents;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') parents.push(s[i]);
        else {
          switch (s[i]) {
            case ')':
              if (parents.empty() || parents.top() != '(') return false;
              else parents.pop();
              break;
            case ']':
              if (parents.empty() || parents.top() != '[') return false;
              else parents.pop();
              break;
            case '}':
              if (parents.empty() || parents.top() != '{') return false;
              else parents.pop();
              break;
            default:
              return false;
          }
        }
      }
      return parents.size() == 0;
    }
};
