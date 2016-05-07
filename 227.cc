class Solution {
  public:
    int calculate(string s) {
      if (s.empty()) return 0;
      stack<char> operators;
      stack<int> operands;
      for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ') continue;
        if (s[i] <= '9' && s[i] >= '0') {
          int val = s[i] - '0';
          int ten = 1;
          i--;
          while (i >= 0 && s[i] <= '9' && s[i] >= '0') {
            ten = ten * 10;
            val =  (s[i] - '0') * ten + val;
            i--;
          }
          i++;
          operands.push(val);
        } else if (s[i] == '*' || s[i] == '/') {
          operators.push(s[i]);
        } else if (s[i] == '+' || s[i] == '-') {
          while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
            int a = operands.top();
            operands.pop();
            int b = operands.top();
            operands.pop();
            if (operators.top() == '*') operands.push(a * b);
            else operands.push(a / b);
            operators.pop();
          }
          operators.push(s[i]);
        }
      }
      while (!operators.empty()) {
        int a = operands.top();
        operands.pop();
        int b = operands.top();
        operands.pop();
        if (operators.top() == '*') operands.push(a * b);
        else if (operators.top() == '/') operands.push(a / b);
        else if (operators.top() == '+') operands.push(a + b);
        else operands.push(a - b);
        operators.pop();
      }
      return operands.top();
    }
};
