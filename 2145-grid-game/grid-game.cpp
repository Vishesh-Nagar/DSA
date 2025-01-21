class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long ans = LLONG_MAX;
        long long r1 = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long r2 = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            r1 -= grid[0][i];
            ans = min(ans, max(r1, r2));
            r2 += grid[1][i];
        }
        return ans;
    }
};