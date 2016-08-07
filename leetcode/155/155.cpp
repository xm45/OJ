class MinStack {
public:
    stack<int> descStack;
    stack<int> valStack;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(descStack.size() == 0 || x <= descStack.top())
            descStack.push(x);
        valStack.push(x);
    }

    void pop() {
        if(descStack.top() == valStack.top())
            descStack.pop();
        valStack.pop();
    }

    int top() {
        return valStack.top();
    }

    int getMin() {
        return descStack.top();
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