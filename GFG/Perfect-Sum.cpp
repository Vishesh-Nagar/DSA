class Solution {
  private:
    const int mod = 1e9 + 7;
    int knapsack(int wt[], int W, int n, vector<vector<int>> &dp) {
        if (W == 0 && n == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][W] != -1)
            return dp[n][W];
        if (W - wt[n - 1] >= 0) {
            int a = knapsack(wt, W - wt[n - 1], n - 1, dp) % mod;
            int b = knapsack(wt, W, n - 1, dp) % mod;
            return dp[n][W] = (a + b) % mod;
        } else
            return dp[n][W] = knapsack(wt, W, n - 1, dp) % mod;
    }

  public:
    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        knapsack(arr, sum, n, dp);
        return dp[n][sum];
    }
};