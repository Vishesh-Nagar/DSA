class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vis(n * n + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                vis[val]++;
            }
        }
        int twice, miss;
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == 0)
                miss = i;
            if (vis[i] == 2)
                twice = i;
        }
        return {twice, miss};
    }
};