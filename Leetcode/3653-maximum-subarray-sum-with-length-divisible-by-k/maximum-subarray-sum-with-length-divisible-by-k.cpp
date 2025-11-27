class Solution {
public:
    using ll = long long;
    ll maxSubarraySum(vector<int>& nums, int k) {
        ll pref = 0;
        ll ans = LLONG_MIN;
        vector<ll> minSoFar(k, LLONG_MAX / 2);
        minSoFar[(k - 1) % k] = 0;

        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            ans = max(ans, pref - minSoFar[i % k]);
            minSoFar[i % k] = min(minSoFar[i % k], pref);
        }

        return ans;
    }
};
