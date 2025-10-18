class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long res = 0;
        int prefix = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i] % modulo == k;
            res += mp[(prefix - k + modulo) % modulo];
            mp[prefix % modulo]++;
        }
        return res;
    }
};