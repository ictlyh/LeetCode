class Solution {
  public:
    bool topTwoIsSharp(stack<int>& s) {
      if (s.size() < 2) return false;
      char t1 = s.top();
      s.pop();
      char t2 = s.top();
      if (t1 == '#' && t2 == '#') return true;
      else return false;
    }

    bool isValidSerialization(string preorder) {
      stack<int> s;
      int size = preorder.size();
      for (int i = 0; i < size; i++) {
        if (preorder[i] == ',') continue;
        if (preorder[i] != '#') {
          int v = 0;
          while (i < size && isdigit(preorder[i])) {
            v = v * 10 + preorder[i] - '0';
            i++;
          }
          if (i == size || preorder[i] != ',') return false;
          s.push(v);
        } else {
          if (s.empty()) {
            if (i == size - 1) return true;
            else return false;
          }
          s.push(preorder[i]);
          while (topTwoIsSharp(s)) {
            s.pop();
            s.pop();
            s.push('#');
          }
          if (s.size() == 1 && s.top() == '#') {
            if (i == size - 1)  return true;
            else return false;
          }
          s.push('#');
        }
      }
      return s.size() == 1 && s.top() == '#';
    }
};
