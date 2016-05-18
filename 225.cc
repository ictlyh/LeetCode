class Stack {
  public:
    queue<int> q1;
    queue<int> q2;
    // Push element x onto stack.
    void push(int x) {
      if (!q1.empty()) q1.push(x);
      else q2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
      if (q1.empty() && q2.empty()) return;
      if (q1.empty()) {
        while (q2.size() > 1) {
          q1.push(q2.front());
          q2.pop();
        }
        q2.pop();
      } else {
        while (q1.size() > 1) {
          q2.push(q1.front());
          q1.pop();
        }
        q1.pop();
      }
    }

    // Get the top element.
    int top() {
      if (!q1.empty()) {
        while (q1.size() > 1) {
          q2.push(q1.front());
          q1.pop();
        }
        int res = q1.front();
        q2.push(res);
        q1.pop();
        return res;
      } else {
        while (q2.size() > 1) {
          q1.push(q2.front());
          q2.pop();
        }
        int res = q2.front();
        q1.push(res);
        q2.pop();
        return res;
      }
    }

    // Return whether the stack is empty.
    bool empty() {
      return q1.empty() && q2.empty();
    }
};
