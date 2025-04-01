class Solution {
public:
    long long rec(vector<vector<int>>& q, int index, vector<long long>& dp) {
        if (index >= q.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        long long take = q[index][0] + rec(q, index + q[index][1] + 1, dp);
        long long notTake = rec(q, index + 1, dp);
        return dp[index] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& q) {
        vector<long long> dp(q.size(), -1);
        long long ans = rec(q, 0, dp);
        return ans;
    }
};