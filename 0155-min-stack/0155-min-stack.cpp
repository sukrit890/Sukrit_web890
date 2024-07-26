class MinStack {
public:
    // as the range is -2^32 to 2^32
    long long mini;
    stack<long long > st;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                long long ele =2*val*1LL-mini;
                st.push(ele);
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        long long ele = st.top();
        st.pop();
        if(ele <mini ){
            mini = 2*mini - ele;
        }
    }
    
    int top() {
        if(st.empty())  return -1;
        if(st.top()>mini)   return st.top();
        else{
            return mini;
        }
    }
    
    int getMin() {
        return mini;
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