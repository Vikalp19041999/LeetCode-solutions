class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1;
    stack<int> min;
    MinStack() {
    }
    
    void push(int val) {
        s1.push(val);
        if(min.empty() || min.top() >= val) {
            min.push(val);
        }
    }
    
    void pop() {
        if(min.top() == s1.top()) {
            min.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */