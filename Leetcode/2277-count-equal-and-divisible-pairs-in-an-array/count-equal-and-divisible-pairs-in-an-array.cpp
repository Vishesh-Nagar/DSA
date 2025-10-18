class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
        vector<int> div;
        for (int d = 1; d * d <= k; d++) {
            if (k % d == 0) {
                div.push_back(d);
                if (d != k / d)
                    div.push_back(k / d);
            }
        }
        for (auto [key, vec] : mp) {
            unordered_map<int, int> mpp;
            for (int i : vec) {
                int gcdd = gcd(i, k);
                int need = k / gcdd;
                ans += mpp[need];
                for (int d : div) {
                    if (i % d == 0)
                        mpp[d]++;
                }
            }
        }
        return ans;
    }
};