//maunal approach       TC:O(n)      SC:O(2*n)

#include <stack>

class MinStack {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    MinStack() {

    }
    
    void push(int val) {
        stack1.push(val);
        if(stack2.empty() || val <= stack2.top())
            stack2.push(val);
    }
    
    void pop() {
        int poped=stack1.top();
        stack1.pop();
        if(poped==stack2.top())
            stack2.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
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


// formula based approach  TC:O(n)      SC:O(n)
class MinStack {
public:
    stack<long long int> s;
    long long int minval;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push(val);
            minval=val;
        }
        else
        {
            if(val<minval)
            {
                s.push((long long)2*val-minval);
                minval=val;
            }
            else
                s.push(val);
        }
    }
    
    void pop() {
        if(s.top()<minval)
            minval=2*minval-s.top();
        s.pop();
    }
    
    int top(){
        if(s.top()<minval)
            return minval;
        return s.top();
    }
    
    int getMin(){
        return minval;
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