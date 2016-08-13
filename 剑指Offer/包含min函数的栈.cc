class Solution {
  public:
    void push(int value) {
      stack1.push(value);
      if (stack2.empty() || value < stack2.top()) stack2.push(value);
      else stack2.push(stack2.top());
    }
    void pop() {
      if (stack1.empty()) return;
      stack1.pop();
      stack2.pop();
    }
    int top() {
      if (stack1.empty()) return -1;
      return stack1.top();
    }
    int min() {
      if (stack1.empty()) return -1;
      return stack2.top();
    }
  private:
    stack<int> stack1;
    stack<int> stack2;
};
