class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int len = 0 + next[prev + 1];
                if (prev == -1 || nums[ind] > nums[prev])
                    len = max(len, 1 + next[ind + 1]);
                curr[prev + 1] = len;
            }
            next = curr;
        }
        return next[0];
    }
};