class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
        int h = triangle.size(), j = h;
        vector<vector<int>> dp(h, vector<int>(j, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < h; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else
                    dp[i][j] =
                        min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        return *min_element(dp[h - 1].begin(), dp[h - 1].end());
    }
};