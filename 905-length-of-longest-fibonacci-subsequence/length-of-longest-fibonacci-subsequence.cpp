class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());
        int ans = 0;
        for (int start = 0; start < n; ++start) {
            for (int next = start + 1; next < n; ++next) {
                int prev = arr[next];
                int curr = arr[start] + arr[next];
                int len = 2;
                while (st.find(curr) != st.end()) {
                    int temp = curr;
                    curr += prev;
                    prev = temp;
                    len++;
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};