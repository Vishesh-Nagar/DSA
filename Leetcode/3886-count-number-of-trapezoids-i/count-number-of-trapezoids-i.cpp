class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        const int mod = 1e9 + 7;
        long long ans = 0, sum = 0;
        for (auto& it : points) {
            mp[it[1]]++;
        }
        for (auto& [key, val] : mp) {
            long long edge = (long long)val * (val - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }
        return ans % mod;
    }
};