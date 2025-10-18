class Solution {
public:
    int brute(int n, int m, string& s1, string& s2) {
        if (n == 0 or m == 0)
            return 0;
        if (s1[n - 1] == s2[m - 1])
            return brute(n - 1, m - 1, s1, s2) + 1;
        return max(brute(n - 1, m, s1, s2), brute(n, m - 1, s1, s2));
    }

    int memo(int n, int m, string& s1, string& s2, vector<vector<int>>& dp) {
        if (n == 0 or m == 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = memo(n - 1, m - 1, s1, s2, dp) + 1;
        return dp[n][m] = max(memo(n - 1, m, s1, s2, dp), memo(n, m - 1, s1, s2, dp));
    }

    int tabulation(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    int optimized(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<int> dp(m + 1, 0), curr(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + dp[j - 1];
                else
                    curr[j] = max(dp[j], curr[j - 1]);
            }
            dp = curr;
        }
        return dp[m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // return brute(n, m, text1, text2);
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return memo(n, m, text1, text2, dp);
        // return tabulation(text1, text2);
        return optimized(text1, text2);
    }
};