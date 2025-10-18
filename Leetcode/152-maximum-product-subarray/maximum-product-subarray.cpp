class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int prev = 1, suff = 1;
        for (int i = 0; i < n; i++) {
            if (prev == 0)
                prev = 1;
            if (suff == 0)
                suff = 1;
            prev *= nums[i];
            suff *= nums[n - i - 1];
            ans = max(ans, max(prev, suff));
        }
        return ans;
    }
};