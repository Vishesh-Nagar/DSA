/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
  public:
    int solve(int n, vector<int> &coins, int target, int ind) {
        if (ind == 0) {
            if (target % coins[ind] == 0)
                return 1;
            else
                return 0;
        }
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        int notTake = solve(n, coins, target, ind - 1);
        int take = 0;
        if (coins[ind] <= target)
            take = solve(n, coins, target - coins[ind], ind);
        return notTake + take;
    }
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        if (n == 0)
            return 0;
        return solve(n, coins, amount, n - 1);
    }
};
// @lc code=end