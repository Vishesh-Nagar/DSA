class Solution {
public:
    int solve(int i, int j, vector<int>& v, unordered_map<int, int>& dp,
              int n) {
        if (i + 2 > j)
            return 0;
        if (i + 2 == j)
            return v[i] * v[i + 1] * v[j];

        int key = i * n + j;
        if (dp.count(key))
            return dp[key];

        int best = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cost = v[i] * v[k] * v[j] + 
                       solve(i, k, v, dp, n) +
                       solve(k, j, v, dp, n);

            best = min(best, cost);
        }
        return dp[key] = best;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        unordered_map<int, int> dp;
        return solve(0, n - 1, values, dp, n);
    }
};