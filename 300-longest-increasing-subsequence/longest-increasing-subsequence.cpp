class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n, 1);
        int ans = 1;
        int last = 0;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > ans) {
                ans = dp[i];
                last = i;
            }
        }
        vector<int> lis;
        lis.push_back(nums[last]);
        while (hash[last] != last) {
            last = hash[last];
            lis.push_back(nums[last]);
        }
        reverse(lis.begin(), lis.end());
        for (auto it : lis)
            cout << it << " ";
        cout << endl;
        return ans;
    }
};