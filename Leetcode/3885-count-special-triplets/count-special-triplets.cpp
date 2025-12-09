class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int, int> r, l;
        for (int val : nums)
            r[val]++;

        for (int j = 0; j < n; ++j) {
            int mid = nums[j];
            r[mid]--;
            int left = l[2 * mid];
            int right = r[2 * mid];
            ans = (ans + 1LL * left * right) % MOD;
            l[mid]++;
        }

        return ans;
    }
};