/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
  public:
    int memoization(int n, vector<int> &dp) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = memoization(n - 1, dp) + memoization(n - 2, dp);
    }
    int tabulation(int n, vector<int> &dp) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int spaceOptimization(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        // return memoization(n, dp);
        // return tabulation(n, dp);
        return spaceOptimization(n);
    }
};
// @lc code=end
