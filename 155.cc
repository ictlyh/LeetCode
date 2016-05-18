class MinStack {
  public:
    int minVal;
    stack<int> vals;
    stack<int> tmp;
    /** initialize your data structure here. */
    MinStack() {
      minVal = INT_MAX;
    }

    void push(int x) {
      vals.push(x);
      minVal = x < minVal ? x : minVal;
    }

    void pop() {
      minVal = INT_MAX;
      if (vals.size() == 0) return;
      else if (vals.size() == 1) vals.pop();
      else {
        vals.pop();
        while (!vals.empty()) {
          tmp.push(vals.top());
          vals.pop();
        }
        while (!tmp.empty()) {
          int f = tmp.top();
          tmp.pop();
          minVal = minVal < f ? minVal : f;
          vals.push(f);
        }
      }
    }

    int top() {
      return vals.top();
    }

    int getMin() {
      return minVal;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
