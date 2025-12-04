class Solution {
public:
    int countCollisions(string s) {
        stack<char> st;
        int ans = 0;
        for (char c : s) {
            if (!st.empty() && st.top() == 'R' && c == 'L') {
                ans += 2;
                st.pop();
                st.push('S');
            }

            else if (!st.empty() && st.top() == 'R' && c == 'S') {
                ans += 1;
                st.pop();
                st.push('S');
            }

            else if (!st.empty() && st.top() == 'S' && c == 'L') {
                ans += 1;
            }

            else {
                st.push(c);
            }
        }

        while (!st.empty() && st.top() == 'R') {
            st.pop();
        }

        while (!st.empty()) {
            if (st.top() == 'R')
                ans++;
            st.pop();
        }

        return ans;
    }
};