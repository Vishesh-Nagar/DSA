/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for (int &i : nums) {
            for (int j = i; j <= target; j++) {
                for (auto v : dp[j - i]) {
                    v.push_back(i);
                    dp[j].push_back(v);
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end