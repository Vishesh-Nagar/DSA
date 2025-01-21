class Solution {
public:
    typedef pair<int, pair<int, int>> Cell;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        priority_queue<Cell, vector<Cell>, greater<>> pq;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int r = 0; r < rows; ++r) {
            for (int c : {0, cols - 1}) {
                pq.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }
        for (int c = 0; c < cols; ++c) {
            for (int r : {0, rows - 1}) {
                pq.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }
        int ans = 0;
        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            int x = pos.first;
            int y = pos.second;
            for (vector<int>& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                    !visited[nx][ny]) {
                    ans += max(0, h - heightMap[nx][ny]);
                    pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
                    visited[nx][ny] = true;
                }
            }
        }
        return ans;
    }
};