/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
  public:
    int mod = (int)1e9 + 7;
    int findWays(int n, vector<int> &nums, int sum) {
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        dp[0][0] = (nums[0] == 0) ? 2 : 1;
        if (nums[0] != 0 && nums[0] <= sum)
            dp[0][nums[0]] = 1;
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= sum; tar++) {
                int notTake = dp[ind - 1][tar];
                int take = 0;
                if (nums[ind] <= tar)
                    take = dp[ind - 1][tar - nums[ind]];
                dp[ind][tar] = (notTake + take) % mod;
            }
        }
        return dp[n - 1][sum];
    }

    int findTargetSumWays(vector<int> &nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (target > totalSum || (totalSum - target) < 0 ||
            (totalSum - target) % 2 != 0)
            return 0;
        int subsetSum = (totalSum - target) / 2;
        return findWays(nums.size(), nums, subsetSum);
    }
};
// @lc code=end