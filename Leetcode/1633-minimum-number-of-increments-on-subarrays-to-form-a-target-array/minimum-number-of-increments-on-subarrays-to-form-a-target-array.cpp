class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = 0;
        stack<pair<int, int>> st;
        st.push({0, 0});
        for (int i = 0; i <= n; ++i) {
            int height = i < n ? target[i] : INT_MAX;
            int work = max(0, height - st.top().first);
            while (st.size() && height > st.top().first) {
                ans += st.top().second;
                st.pop();
            }
            st.push({height, work});
        }
        return ans;
    }
};