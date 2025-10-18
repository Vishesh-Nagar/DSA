/*
 * @lc app=leetcode id=2035 lang=cpp
 *
 * [2035] Partition Array Into Two Arrays to Minimize Sum Difference
 */

// @lc code=start
class Solution {
  public:
    int minimumDifference(vector<int> &nums) {
        int n = nums.size();
        int N = n / 2;
        vector<vector<int>> left(N + 1), right(N + 1);
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        for (int mask = 0; mask < (1 << N); mask++) {
            int size = 0;
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < N; j++) {
                if (mask & (1 << j)) {
                    size++;
                    sum1 += nums[j];
                    sum2 += nums[j + N];
                }
            }
            left[size].push_back(sum1);
            right[size].push_back(sum2);
        }
        for (int i = 0; i < N; i++) {
            sort(right[i].begin(), right[i].end());
        }
        int ans = abs(totalSum - 2 * left[N][0]);
        for (int i = 1; i < N; i++) {
            for (auto it : left[i]) {
                int b = (totalSum - 2 * it) / 2;
                int right_indx = N - i;
                auto itr = lower_bound(right[right_indx].begin(),
                                       right[right_indx].end(), b);
                if (itr != right[right_indx].end()) {
                    ans = min(ans, abs(totalSum - 2 * (it + *itr)));
                }
            }
        }
        return ans;
    }
};
// @lc code=end