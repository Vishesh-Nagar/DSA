class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, i = 0, diff = 0;
        for (int k = 0; k < n; k++) {
            ans = max(ans, diff * nums[k]);
            diff = max(diff, i - nums[k]);
            i = max(i, (long long)(nums[k]));
        }
        return ans;
    }
};