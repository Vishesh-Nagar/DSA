class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int ans = 0, prefixSum = 0;
        int odd = 0, even = 1;
        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }
            ans %= MOD;
        }
        return ans;
    }
};