class Solution {
public:
    int digitSum(int n) {
        int val = 0;
        while (n > 0) {
            val += n % 10;
            n /= 10;
        }
        return val;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int sum = digitSum(nums[i]);
            if (mp.find(sum) != mp.end()) {
                ans = max(ans, nums[i] + mp[sum]);
                mp[sum] = max(mp[sum], nums[i]);
            } else
                mp[sum] = nums[i];
        }
        return ans;
    }
};