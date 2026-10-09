class MinStack {
public:
    vector<int> st;
    vector<int> min;
    
    MinStack() = default;
    
    void push(int val) {
        st.push_back(val);
        if(min.empty() || val <= min.back())
            min.push_back(val);
    }
    
    void pop() {
        if (st.empty())
            return ;
        if (min.back() == st.back())
            min.pop_back();
        st.pop_back();
    }
    
    int top() {
        if (st.empty())
            return 0;
        return st.back();
    }
    
    int getMin() {
        if (st.empty())
            return 0;
        return min.back();
    }
};
