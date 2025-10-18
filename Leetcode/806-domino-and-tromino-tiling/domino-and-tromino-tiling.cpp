class Solution {
public:
    const long mod = 1e9 + 7;
    long rec(int i, int n, bool flag, vector<vector<long>>& dp) {
        if (i == n)
            return !flag;
        if (i > n)
            return 0;
        if (dp[i][flag] != -1)
            return dp[i][flag];
        if (flag)
            return dp[i][flag] =
                       (rec(i + 1, n, false, dp) + rec(i + 1, n, true, dp)) %
                       mod;
        return dp[i][flag] =
                   (rec(i + 1, n, false, dp) + rec(i + 2, n, false, dp) +
                    2L * rec(i + 2, n, true, dp)) %
                   mod;
    }

    int numTilings(int n) {
        vector<vector<long>> dp(n + 2, vector<long>(2, -1));
        return rec(0, n, false, dp);
    }
};
