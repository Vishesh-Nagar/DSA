class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int prev = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > prev)
                ans = max(ans, nums[i] - prev);
            else
                prev = nums[i];
        }
        return ans;
    }
};