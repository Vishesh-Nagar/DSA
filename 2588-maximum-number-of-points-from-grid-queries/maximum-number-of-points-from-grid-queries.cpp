class Solution {
public:
#define ai3 array<int, 3>
    static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int queryCount = queries.size();
        vector<int> result(queryCount);
        int n = grid.size();
        int m = grid[0].size();

        int cells = n * m;
        vector<int> threshold(cells + 1);

        vector<vector<int>> val(n, vector<int>(m, INT_MAX));

        val[0][0] = grid[0][0];

        priority_queue<ai3, vector<ai3>, greater<ai3>> pq;
        pq.push({grid[0][0], 0, 0});
        int visited = 0;

        while (!pq.empty()) {
            ai3 curr = pq.top();
            pq.pop();

            threshold[++visited] = curr[0];

            for (const auto& d : dir) {
                int nrow = curr[1] + d[0];
                int ncol = curr[2] + d[1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    val[nrow][ncol] == INT_MAX) {
                    val[nrow][ncol] = max(curr[0], grid[nrow][ncol]);

                    pq.push({val[nrow][ncol], nrow, ncol});
                }
            }
        }

        for (int i = 0; i < queryCount; i++) {
            int limit = queries[i];
            int left = 0, right = cells;

            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (threshold[mid] < limit)
                    left = mid;
                else
                    right = mid - 1;
            }

            result[i] = left;
        }

        return result;
    }
};