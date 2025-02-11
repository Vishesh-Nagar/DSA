class Solution {
public:
    string removeOccurrences(string s, string part) {
        vector<int> kmp = helper(part);
        stack<char> st;
        vector<int> pattern(s.length() + 1, 0);
        for (int i = 0, j = 0; i < s.length(); i++) {
            char c = s[i];
            st.push(c);
            if (c == part[j]) {
                pattern[st.size()] = ++j;
                if (j == part.length()) {
                    int rem = part.length();
                    while (rem != 0) {
                        st.pop();
                        rem--;
                    }
                    j = st.empty() ? 0 : pattern[st.size()];
                }
            } else {
                if (j != 0) {
                    i--;
                    j = kmp[j - 1];
                    st.pop();
                } else {
                    pattern[st.size()] = 0;
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
    
    vector<int> helper(string pattern) {
        vector<int> lps(pattern.length(), 0);
        for (int i = 1, j = 0; i < pattern.length();) {
            if (pattern[i] == pattern[j]) {
                lps[i] = ++j;
                i++;
            } else if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }
};