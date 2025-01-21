class Solution {
  public:
    int memoization(int ind, int W, int val[], int wt[],
                    vector<vector<int>> &dp) {
        if (ind == 0)
            if (W >= wt[0])
                return (W / wt[0]) * val[0];
            else
                return 0;
        if (W == 0)
            return 0;
        if (dp[ind][W] != -1)
            return dp[ind][W];
        int nottake = memoization(ind - 1, W, val, wt, dp);
        int take = INT_MIN;
        if (wt[ind] <= W)
            take = val[ind] + memoization(ind, W - wt[ind], val, wt, dp);
        return dp[ind][W] = max(take, nottake);
    }

    int Tabulation(int N, int W, int val[], int wt[]) {
        vector<vector<int>> dp(N, vector<int>(W + 1, 0));
        for (int j = 0; j <= W; j++)
            dp[0][j] = (j / wt[0]) * val[0];
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= W; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (wt[i] <= j)
                    take = val[i] + dp[i - 1][j - wt[i]];
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[N - 1][W];
    }

    int spaceOptimized(int N, int W, int val[], int wt[]) {
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < N; i++) {
            for (int j = wt[i]; j <= W; j++) {
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
            }
        }
        return dp[W];
    }

    int knapSack(int N, int W, int val[], int wt[]) {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        return memoization(N - 1, W, val, wt, dp);
        // return Tabulation(N, W, val, wt);
        // return spaceOptimized(N, W, val, wt);
    }
};