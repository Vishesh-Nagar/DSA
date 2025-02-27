class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
            for (int j = 0; j < i; j++) {
                int diff = arr[i] - arr[j];
                int prev = (mp.find(diff) != mp.end()) ? mp[diff] : -1;
                if (diff < arr[j] && prev >= 0)
                    dp[j][i] = dp[prev][j] + 1;
                else
                    dp[j][i] = 2;
                ans = max(ans, dp[j][i]);
            }
        }
        return ans > 2 ? ans : 0;
    }
};