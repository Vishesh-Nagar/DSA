/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
  public:
    int coinChange(vector<int> &coins, int target) {
        int n = coins.size();
        vector<int> dp(target + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[target] == INT_MAX ? -1 : dp[target];
    }
};
// @lc code=end