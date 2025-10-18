class Solution {
  public:
    int mod = (int)1e9 + 7;
    // int countPartitionsUtil(int ind, int target, vector<int>& arr,
    // vector<vector<int>>& dp) {
    //     if (ind == 0) {
    //         if (target == 0 && arr[0] == 0)
    //             return 2;
    //         if (target == 0 || target == arr[0])
    //             return 1;
    //         return 0;
    //     }

    //     if (dp[ind][target] != -1)
    //         return dp[ind][target];

    //     int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);
    //     int taken = 0;
    //     if (arr[ind] <= target)
    //         taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);

    //     return dp[ind][target] = (notTaken + taken) % mod;
    // }

    // int countPartitions(int n, int d, vector<int>& arr) {
    //     int totalSum = 0;
    //     for (int i = 0; i < arr.size(); i++)
    //         totalSum += arr[i];
    //     if (totalSum - d < 0)
    //         return 0;
    //     if ((totalSum - d) % 2 == 1)
    //         return 0;
    //     int s2 = (totalSum - d) / 2;
    //     vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    //     return countPartitionsUtil(n - 1, s2, arr, dp);
    // }

    int findWays(int n, vector<int> &num, int tar) {
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        if (num[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (num[0] != 0 && num[0] <= tar)
            dp[0][num[0]] = 1;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= tar; target++) {

                int notTaken = dp[ind - 1][target];

                int taken = 0;
                if (num[ind] <= target)
                    taken = dp[ind - 1][target - num[ind]];

                dp[ind][target] = (notTaken + taken) % mod;
            }
        }
        return dp[n - 1][tar];
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += arr[i];

        if (totalSum - d < 0 || (totalSum - d) % 2)
            return 0;

        return findWays(n, arr, (totalSum - d) / 2);
    }
};