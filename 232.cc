class Queue {
public:
    stack<int> elements;
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmp;
        while(elements.size()) {
            tmp.push(elements.top());
            elements.pop();
        }
        elements.push(x);
        while(tmp.size()) {
            elements.push(tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        elements.pop();
    }

    // Get the front element.
    int peek(void) {
        return elements.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return elements.size() ? false : true;
    }
};