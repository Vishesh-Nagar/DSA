class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int rows = isWater.size();
        int cols = isWater[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (isWater[r][c]) {
                    q.push({r, c});
                    result[r][c] = 0;
                }
            }
        }
        int height = 1;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (isValidCell(nx, ny, rows, cols) &&
                        result[nx][ny] == -1) {
                        result[nx][ny] = height;
                        q.push({nx, ny});
                    }
                }
            }
            height++;
        }
        return result;
    }
    bool isValidCell(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
};