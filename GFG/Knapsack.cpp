#include <bits/stdc++.h>
int memoization(vector<int> weight, vector<int> value, int n, int maxWeight, int ind, vector<vector<int>> &dp) {
    if (ind == n || maxWeight == 0)
        return 0;
    if (dp[ind][maxWeight] != -1)
        return dp[ind][maxWeight];
    int notTake = memoization(weight, value, n, maxWeight, ind + 1, dp);
    int take = 0;
    if (weight[ind] <= maxWeight)
        take = value[ind] + memoization(weight, value, n, maxWeight - weight[ind], ind + 1, dp);
    return dp[ind][maxWeight] = max(take, notTake);
}
int tabulation(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int>> &dp) {
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxWeight; j++) {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (weight[i - 1] <= j)
                take = value[i - 1] + dp[i - 1][j - weight[i - 1]];
            dp[i][j] = max(notTake, take);
        }
    }
    return dp[n][maxWeight];
}
int spaceOptimized(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxWeight; j++) {
            int notTake = prev[j];
            int take = 0;
            if (weight[i - 1] <= j)
                take = value[i - 1] + prev[j - weight[i - 1]];
            curr[j] = max(notTake, take);
        }
        prev = curr;
    }
    return prev[maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    // vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1)); //Memoization
    // return memoization(weight, value, n, maxWeight, 0, dp);
    // vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0)); //Tabulation
    // return tabulation(weight, value, n, maxWeight, dp);
    return spaceOptimized(weight, value, n, maxWeight);
}