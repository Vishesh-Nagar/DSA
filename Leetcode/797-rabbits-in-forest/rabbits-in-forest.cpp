class Solution {
public:
    int numRabbits(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        for (auto p : mp)
            ans += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        return ans;
    }
};