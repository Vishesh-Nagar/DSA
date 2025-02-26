class Solution {
public:
    int memo(string& word1, string& word2, int m, int n, vector<vector<int>>& dp) {
        if (m == 0)
            return dp[m][n] = n;
        if (n == 0)
            return dp[m][n] = m;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (word1[m - 1] == word2[n - 1])
            return dp[m][n] = memo(word1, word2, m - 1, n - 1, dp);
        else {
            int insertChar = memo(word1, word2, m, n - 1, dp);
            int deleteChar = memo(word1, word2, m - 1, n, dp);
            int replaceChar = memo(word1, word2, m - 1, n - 1, dp);
            return dp[m][n] = 1 + min({insertChar, deleteChar, replaceChar});
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return memo(word1, word2, m, n, dp);
    }
};