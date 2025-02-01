class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        int i = 0;
        while (i < n) {
            if (s[i] == ')') {
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            else if (s[i] == '}') {
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
            }
            else if (s[i] == ']') {
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
            else 
                st.push(s[i]);
            i++;
        }
        return st.empty();
    }
};