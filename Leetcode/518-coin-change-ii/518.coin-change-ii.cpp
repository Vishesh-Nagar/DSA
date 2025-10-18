/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
  public:
    int spaceOptimized(int ind, int target, vector<int> &coins, int n,
                       vector<int> &prev, vector<int> &curr) {
        for (int tar = 0; tar <= target; tar++) {
            prev[tar] = (tar % coins[0] == 0);
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= target; tar++) {
                int notTake = prev[tar];
                int take = 0;
                if (coins[ind] <= tar)
                    take = curr[tar - coins[ind]];
                curr[tar] = notTake + take;
            }
            prev = curr;
        }
        return prev[target];
    }
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        return spaceOptimized(n - 1, amount, coins, n, prev, curr);
    }
};
// @lc code=end