class Solution {
public:
    bool isInvalid(vector<vector<int>>& m, int r, int c) {
        return r < 0 || c < 0 || r >= m.size() || c >= m.size() || m[r][c] != 0;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        int dir = 0, val = 0, r = 0, c = 0, limit = n * n;
        while (val++ < limit) {
            mat[r][c] = val;
            r += dr[dir];
            c += dc[dir];
            if (isInvalid(mat, r, c)) {
                r -= dr[dir];
                c -= dc[dir];
                dir = (dir + 1) % 4;
                r += dr[dir];
                c += dc[dir];
            }
        }
        return mat;
    }
};
