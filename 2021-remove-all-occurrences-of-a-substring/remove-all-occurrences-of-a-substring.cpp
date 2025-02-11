class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = s.length();
        int m = part.length();
        for (int i = 0; i < n; i++) {
            st.push(s[i]);
            if (st.size() >= m && checkMatch(st, part, m)) {
                for (int j = 0; j < m; j++) {
                    st.pop();
                }
            }
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }

    bool checkMatch(stack<char>& st, string& part, int m) {
        stack<char> temp = st;
        for (int i = m - 1; i >= 0; i--) {
            if (temp.top() != part[i]) {
                return false;
            }
            temp.pop();
        }
        return true;
    }
};