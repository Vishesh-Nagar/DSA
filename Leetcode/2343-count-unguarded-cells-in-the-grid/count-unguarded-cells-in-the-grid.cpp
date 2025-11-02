class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = m * n;
        vector<vector<char>> mat(m, vector<char>(n, 'u'));
        for (auto it : guards) {
            int x = it[0], y = it[1];
            mat[x][y] = 'g';
            ans--;
        }
        for (auto it : walls) {
            int x = it[0], y = it[1];
            mat[x][y] = 'w';
            ans--;
        }
        for (auto it : guards) {
            int x = it[0], y = it[1];
            int i = x - 1, j = y;
            while (i >= 0 && mat[i][j] != 'w' && mat[i][j] != 'g') {
                if (mat[i][j] == 'u') {
                    mat[i][j] = 's';
                    ans--;
                }
                i--;
            }

            i = x + 1, j = y;
            while (i < m && mat[i][j] != 'w' && mat[i][j] != 'g') {
                if (mat[i][j] == 'u') {
                    mat[i][j] = 's';
                    ans--;
                }
                i++;
            }

            i = x, j = y - 1;
            while (j >= 0 && mat[i][j] != 'w' && mat[i][j] != 'g') {
                if (mat[i][j] == 'u') {
                    mat[i][j] = 's';
                    ans--;
                }
                j--;
            }

            i = x, j = y + 1;
            while (j < n && mat[i][j] != 'w' && mat[i][j] != 'g') {
                if (mat[i][j] == 'u') {
                    mat[i][j] = 's';
                    ans--;
                }
                j++;
            }
        }
        return ans;
    }
};