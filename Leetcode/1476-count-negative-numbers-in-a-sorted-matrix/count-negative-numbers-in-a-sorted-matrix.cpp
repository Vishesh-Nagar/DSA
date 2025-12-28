class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = n - 1;
        int j = 0;
        int ans = 0;
        while (i >= 0 && j < m) {
            if (grid[i][j] < 0) {
                ans += m - j;
                i--;
            } else
                j++;
        }
        return ans;
    }
};