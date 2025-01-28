class Solution {
public:
    int helper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }
        visited[row][col] = true;
        return grid[row][col] + (helper(grid, visited, row, col + 1) +
                                 helper(grid, visited, row, col - 1) +
                                 helper(grid, visited, row + 1, col) +
                                 helper(grid, visited, row - 1, col));
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] > 0 && !visited[row][col]) {
                    ans = max(ans, helper(grid, visited, row, col));
                }
            }
        }
        return ans;
    }
};