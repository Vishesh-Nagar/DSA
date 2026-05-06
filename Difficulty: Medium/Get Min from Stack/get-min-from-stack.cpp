class SpecialStack {
  public:
    stack<int> st;
    stack<int> ss;
    
    SpecialStack() {}

    void push(int x) {
        if(ss.empty() || x <= ss.top())
            ss.push(x);
        st.push(x);
    }

    void pop() {
        if(st.empty())
            return;
        if(ss.top() == st.top())
            ss.pop();
        st.pop();
    }

    int peek() {
        if(st.empty())
            return -1;
        return st.top();
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {
        if(ss.empty())
            return -1;
        return ss.top();
    }
};