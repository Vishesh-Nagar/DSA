class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        for (int a : nums) {
            while (!st.empty() && st.top() > a)
                st.pop();
            if (a == 0)
                continue;
            if (st.empty() || st.top() < a) {
                ans++;
                st.push(a);
            }
        }
        return ans;
    }
};