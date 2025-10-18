class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        int last = INT_MIN;
        for (int i = 0; i < n; i++) {
            int mn = nums[i] - k;
            int mx = nums[i] + k;
            if (last < mn) {
                last = mn;
                ans++;
            } else if (last < mx) {
                last++;
                ans++;
            }
        }
        return ans;
    }
};