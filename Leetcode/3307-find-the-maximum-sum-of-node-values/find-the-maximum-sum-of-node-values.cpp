class Solution {
public:
    long long help(int index, int isEven, vector<int>& nums, int k,
                   vector<vector<long long>>& dp) {
        if (index == nums.size())
            return isEven == 1 ? 0 : INT_MIN;

        if (dp[index][isEven] != -1)
            return dp[index][isEven];

        long long notTake = nums[index] + help(index + 1, isEven, nums, k, dp);
        long long take =
            (nums[index] ^ k) + help(index + 1, isEven ^ 1, nums, k, dp);

        return dp[index][isEven] = max(take, notTake);
    }

    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return help(0, 1, nums, k, dp);
    }
};