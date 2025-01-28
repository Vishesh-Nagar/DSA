class Solution {
public:
    int helper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int n = grid.size(), m = grid[0].size(), val = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};
        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            val += grid[row][col];
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] &&
                    !visited[nr][nc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return val;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    ans = max(ans, helper(grid, visited, i, j));
                }
            }
        }
        return ans;
    }
};