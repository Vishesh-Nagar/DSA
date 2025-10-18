class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<int> idx;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxEl)
                idx.push_back(i);

            int freq = idx.size();
            if (freq >= k)
                ans += idx[freq - k] + 1;
        }

        return ans;
    }
};