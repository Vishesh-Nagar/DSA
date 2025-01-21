/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
  public:
    int memoization(vector<int> &nums, int i, vector<int> &dp) {
        if (i < 0)
            return 0;
        if (i == 0)
            return nums[0];
        if (dp[i] != -1)
            return dp[i];
        int pick = nums[i] + memoization(nums, i - 2, dp);
        int notPick = memoization(nums, i - 1, dp);
        return dp[i] = max(pick, notPick);
    }

    int tabulation(vector<int> &nums, vector<int> &dp) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]); // max(notTake, take)
        }
        return dp[nums.size() - 1];
    }

    int spaceOptimization(vector<int> &nums) {
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int notTake = 0 + prev;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int> &nums) {
        // vector<int> dp(nums.size() + 1, -1);
        // return memoization(nums, nums.size() - 1, dp);
        // vector<int> dp(nums.size(), 0);
        // return tabulation(nums, dp);
        return spaceOptimization(nums);
    }
};
// @lc code=end
