class Solution {
public:
    bool memoization(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (ind == 0)
            return nums[0] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool notTaken = memoization(ind - 1, target, nums, dp);
        bool taken = false;
        if (nums[ind] <= target)
            taken = memoization(ind - 1, target - nums[ind], nums, dp);
        return dp[ind][target] = notTaken || taken;
    }

    bool tabulation(int n, int k, vector<int>& nums) {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= k) {
            dp[0][nums[0]] = true;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTaken = dp[ind - 1][target];
                bool taken = false;
                if (nums[ind] <= target) {
                    taken = dp[ind - 1][target - nums[ind]];
                }
                dp[ind][target] = notTaken || taken;
            }
        }
        return dp[n - 1][k];
    }

    bool spaceOptimization(int n, int k, vector<int>& nums) {
        vector<bool> prev(k + 1, false);
        prev[0] = true;
        if (nums[0] <= k) {
            prev[nums[0]] = true;
        }
        for (int ind = 1; ind < n; ind++) {
            vector<bool> cur(k + 1, false);
            cur[0] = true;
            for (int target = 1; target <= k; target++) {
                bool notTaken = prev[target];
                bool taken = false;
                if (nums[ind] <= target) {
                    taken = prev[target - nums[ind]];
                }
                cur[target] = notTaken || taken;
            }
            prev = cur;
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += nums[i];
        if (totalSum % 2 != 0)
            return false;
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return memoization(n - 1, sum, nums, dp);
        // return tabulation(n, sum, nums);
        return spaceOptimization(n, target, nums);
    }
};