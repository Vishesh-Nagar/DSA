class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for (auto x : nums) {
            sum = (sum + x) % p;
        }

        int target = sum % p;
        if (target == 0)
            return 0;

        unordered_map<int, int> mp;
        int curr = 0;
        mp[0] = -1;

        int result = nums.size();
        for (int j = 0; j < nums.size(); j++) {
            curr = (curr + nums[j]) % p;
            int prev = (curr - target + p) % p;

            if (mp.find(prev) != mp.end())
                result = min(result, j - mp[prev]);

            mp[curr] = j;
        }
        return result == nums.size() ? -1 : result;
    }
};