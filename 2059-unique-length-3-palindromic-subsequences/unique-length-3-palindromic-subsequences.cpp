class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if (indices[idx].first == -1)
                indices[idx].first = i;

            indices[idx].second = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (indices[i] == make_pair(-1, -1))
                continue;

            unordered_set<char> st;
            for (int m = indices[i].first + 1; m <= indices[i].second - 1; m++)
                st.insert(s[m]);

            ans += st.size();
        }
        return ans;
    }
};