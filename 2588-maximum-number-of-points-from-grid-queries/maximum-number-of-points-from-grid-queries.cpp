class Solution {
public:
#define pii pair<int, int>
    vector<pii> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(queries.size(), 0);

        vector<pii> newQueries;
        for (int i = 0; i < queries.size(); i++)
            newQueries.push_back({queries[i], i});

        sort(newQueries.begin(), newQueries.end());

        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int points = 0;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        for (auto [val, idx] : newQueries) {
            while (!pq.empty() && pq.top().first < val) {
                auto [value, pos] = pq.top();
                pq.pop();
                int row = pos.first, col = pos.second;
                points++;

                for (auto [drow, dcol] : dir) {
                    int nrow = row + drow, ncol = col + dcol;

                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        !visited[nrow][ncol]) {
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                        visited[nrow][ncol] = true;
                    }
                }
            }
            ans[idx] = points;
        }
        return ans;
    }
};