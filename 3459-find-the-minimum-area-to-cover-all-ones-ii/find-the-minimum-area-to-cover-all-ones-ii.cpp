class Solution {
    int minimumSum(vector<vector<int>>& grid, int u, int d, int l, int r) {
        int mini = grid.size(), maxi = 0;
        int minj = grid[0].size(), maxj = 0;
        for (int i = u; i <= d; i++) {
            for (int j = l; j <= r; j++) {
                if (grid[i][j] == 1) {
                    mini = min(mini, i);
                    minj = min(minj, j);
                    maxi = max(maxi, i);
                    maxj = max(maxj, j);
                }
            }
        }
        return mini <= maxi ? (maxi - mini + 1) * (maxj - minj + 1)
                            : INT_MAX / 3;
    }

    vector<vector<int>> rotate(vector<vector<int>>& vec) {
        int n = vec.size(), m = vec[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[m - j - 1][i] = vec[i][j];
            }
        }
        return ret;
    }

    int solve(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = n * m;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                res =
                    min(res, minimumSum(grid, 0, i, 0, m - 1) +
                                 minimumSum(grid, i + 1, n - 1, 0, j) +
                                 minimumSum(grid, i + 1, n - 1, j + 1, m - 1));
                res = min(res, minimumSum(grid, 0, i, 0, j) +
                                   minimumSum(grid, 0, i, j + 1, m - 1) +
                                   minimumSum(grid, i + 1, n - 1, 0, m - 1));
            }
        }
        for (int i = 0; i + 2 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                res = min(res, minimumSum(grid, 0, i, 0, m - 1) +
                                   minimumSum(grid, i + 1, j, 0, m - 1) +
                                   minimumSum(grid, j + 1, n - 1, 0, m - 1));
            }
        }
        return res;
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        auto rgrid = rotate(grid);
        return min(solve(grid), solve(rgrid));
    }
};