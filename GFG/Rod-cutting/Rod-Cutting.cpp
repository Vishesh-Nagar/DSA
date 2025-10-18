class Solution {
  public:
    int Recursion(int price[], int N, int ind) {
        if (ind == 0)
            return N * price[0];
        int notTake = Recursion(price, N, ind - 1);
        int rodLen = ind + 1;
        int take = INT_MIN;
        if (rodLen <= N) {
            take = price[ind] + Recursion(price, N - rodLen, ind);
        }
        return max(take, notTake);
    }
    int Memoization(int price[], int N, int ind, vector<vector<int>> &dp) {
        if (ind == 0)
            return N * price[0];
        if (dp[ind][N] != -1)
            return dp[ind][N];
        int notTake = Memoization(price, N, ind - 1, dp);
        int rodLen = ind + 1;
        int take = INT_MIN;
        if (rodLen <= N) {
            take = price[ind] + Memoization(price, N - rodLen, ind, dp);
        }
        return dp[ind][N] = max(take, notTake);
    }
    int Tabulation(int price[], int N, int ind) {
        vector<vector<int>> dp(N, vector<int>(N + 1, 0));
        for (int ind = 0; ind <= N; ind++) {
            dp[0][ind] = ind * price[0];
        }
        for (int ind = 1; ind < N; ind++) {
            for (int n = 0; n <= N; n++) {
                int notTake = dp[ind - 1][n];
                int rodLen = ind + 1;
                int take = INT_MIN;
                if (rodLen <= n) {
                    take = price[ind] + dp[ind][n - rodLen];
                }
                dp[ind][n] = max(take, notTake);
            }
        }
        return dp[ind][N];
    }
    int spaceOptimization(int price[], int N) {
        vector<int> prev(N + 1, 0), curr(N + 1, 0);
        for (int ind = 0; ind <= N; ind++) {
            prev[ind] = ind * price[0];
        }
        for (int ind = 1; ind < N; ind++) {
            for (int n = 0; n <= N; n++) {
                int notTake = prev[n];
                int rodLen = ind + 1;
                int take = INT_MIN;
                if (rodLen <= n) {
                    take = price[ind] + curr[n - rodLen];
                }
                curr[n] = max(notTake, take);
            }
            prev = curr;
        }
        return prev[N];
    }
    int cutRod(int price[], int N) {
        // return Recursion(price, N, N - 1); // Recursion
        // vector<vector<int>> dp(N, vector<int>(N + 1, -1));
        // return Memoization(price, N, N - 1, dp); // Memoization
        // return Tabulation(price, N, N - 1);
        return spaceOptimization(price, N); // Space Optimization
    }
};