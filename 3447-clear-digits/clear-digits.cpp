class Solution {
public:
    bool isDigit(char c) {
        int x = c - '0';
        return x >= 0 && x <= 9;
    }
    string clearDigits(string s) {
        stack<char> st;
        for (char c : s) {
            if (isDigit(c) && !st.empty()) {
                st.pop();
            } else if (!isDigit(c))
                st.push(c);
        }
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};