class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int row = 0; row <= n; row++)
            dp[row][0] = row;
        for (int col = 0; col <= m; col++)
            dp[0][col] = col;

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= m; col++) {
                if (str1[row - 1] == str2[col - 1])
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                else
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
            }
        }
        string ans = "";
        int row = n, col = m;
        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                ans += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                ans += str1[row - 1];
                row--;
            } else {
                ans += str2[col - 1];
                col--;
            }
        }
        while (row > 0) {
            ans += str1[row - 1];
            row--;
        }
        while (col > 0) {
            ans += str2[col - 1];
            col--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};