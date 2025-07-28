class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;
        for (int num : nums)
            maxOR |= num;

        vector<vector<int>> dp(n, vector<int>(maxOR + 1, -1));
        return count(nums, 0, 0, maxOR, dp);
    }

    int count(vector<int>& nums, int index, int currOR, int targetOr,
              vector<vector<int>>& dp) {
        if (index == nums.size())
            return (currOR == targetOr) ? 1 : 0;

        if (dp[index][currOR] != -1)
            return dp[index][currOR];

        int take = count(nums, index + 1, currOR | nums[index], targetOr, dp);
        int notTake = count(nums, index + 1, currOR, targetOr, dp);

        return dp[index][currOR] = notTake + take;
    }
};