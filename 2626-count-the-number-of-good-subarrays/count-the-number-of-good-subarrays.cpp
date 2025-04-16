class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int, int> mp;
        int val = 0, right = -1;
        for (int i = 0; i < n; i++) {
            while (val < k && right + 1 < n) {
                right++;
                val += mp[nums[right]];
                mp[nums[right]]++;
            }
            if (val >= k)
                ans += n - right;
            mp[nums[i]]--;
            val -= mp[nums[i]];
        }
        return ans;
    }
};