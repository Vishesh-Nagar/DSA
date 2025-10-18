class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& h, vector<vector<int>>& vis, int r, int c, int ocean) {
        int m = h.size(), n = h[0].size();
        if (vis[r][c] & ocean)
            return;
        vis[r][c] |= ocean;
        for (auto& d : dir) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && h[nr][nc] >= h[r][c])
                dfs(h, vis, nr, nc, ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)), res;
        for (int i = 0; i < m; i++) {
            dfs(h, vis, i, 0, 1);
            dfs(h, vis, i, n - 1, 2);
        }
        for (int j = 0; j < n; j++) {
            dfs(h, vis, 0, j, 1);
            dfs(h, vis, m - 1, j, 2);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 3)
                    res.push_back({i, j});
            }
        }
        return res;
    }
};