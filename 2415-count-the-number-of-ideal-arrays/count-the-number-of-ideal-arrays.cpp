class Solution {
public:
    int mod = 1e9 + 7;
    int idealArrays(int n, int maxValue) {
        vector<vector<int>> dp(15, vector<int>(maxValue + 1, 0));
        for (int i = 1; i <= maxValue; i++)
            dp[1][i] = 1;
        for (int len = 2; len < 15; len++) {
            for (int i = 1; i <= maxValue; i++) {
                for (int j = 2 * i; j <= maxValue; j += i)
                    dp[len][j] = (dp[len][j] + dp[len - 1][i]) % mod;
            }
        }
        vector<vector<int>> comb(n + 1, vector<int>(15, 0));
        for (int i = 0; i <= n; i++) {
            comb[i][0] = 1;
            for (int j = 1; j < 15 && j <= i; j++)
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
        }
        int res = 0;
        for (int len = 1; len < 15; len++) {
            for (int x = 1; x <= maxValue; x++) {
                res = (res + 1LL * dp[len][x] * comb[n - 1][len - 1] % mod) % mod;
            }
        }
        return res;
    }
};