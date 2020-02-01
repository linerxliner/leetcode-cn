class MinStack {
public:
    stack<int> s, min_s;
    
    /** initialize your data structure here. */
    MinStack() {
        
    }

    void push(int x) {
        if (min_s.empty() || x <= min_s.top()) min_s.push(x);
        s.push(x);
    }
    
    void pop() {
        if (s.top() == min_s.top()) min_s.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
