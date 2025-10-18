class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> st1;
        for (int i : nums)
            st1.insert(i);
        int total = st1.size();
        unordered_map<int, int> mp;
        int ans = 0, i = 0;
        for (int j = 0; j < n; ++j) {
            mp[nums[j]]++;
            while (mp.size() == total) {
                ans += n - j;
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};