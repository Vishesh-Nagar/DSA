class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int req = target - val;
            if (mp.find(req) != mp.end()) {
                int idx = mp[req];
                return {idx, i};
            }
            mp[val] = i;
        }
        return {-1, -1};
    }
};