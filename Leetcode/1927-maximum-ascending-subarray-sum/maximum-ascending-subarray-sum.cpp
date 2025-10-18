class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int curr = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                ans = max(ans, curr);
                curr = 0;
            }
            curr += nums[i];
        }
        return max(ans, curr);
    }
};