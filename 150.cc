class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      int size = tokens.size();
      if (size == 0) return 0;
      stack<int> operands;
      for (int i = 0; i < size; i++) {
        if (tokens[i].size() == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-'
              || tokens[i][0] == '*' || tokens[i][0] == '/')) {
          int b = operands.top();
          operands.pop();
          int a = operands.top();
          operands.pop();
          if (tokens[i][0] == '+') operands.push(a + b);
          else if (tokens[i][0] == '-') operands.push(a - b);
          else if (tokens[i][0] == '*') operands.push(a * b);
          else if (tokens[i][0] == '/') operands.push(a / b);
        }
        else operands.push(atoi(tokens[i].c_str()));
      }
      return operands.top();
    }
};
