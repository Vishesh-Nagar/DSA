class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 2; i < n; i++) {
            int start = 0;
            int end = i - 1;
            while (start < end) {
                int pairSum = arr[start] + arr[end];
                if (pairSum > arr[i])
                    end--;
                else if (pairSum < arr[i])
                    start++;
                else {
                    dp[end][i] = dp[start][end] + 1;
                    ans = max(dp[end][i], ans);
                    end--;
                    start++;
                }
            }
        }
        return ans == 0 ? 0 : ans + 2;
    }
};