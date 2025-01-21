/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
class DisjointSet {
    vector<int> rank, parent, size;
  public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }
    void unionByRank(int x, int y) {
        int u = find(x);
        int v = find(y);
        if (u == v)
            return;
        if (rank[v] < rank[u])
            parent[v] = u;
        else if (rank[u] < rank[v])
            parent[u] = v;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    void unionBySize(int x, int y) {

        int u = find(x);
        int v = find(y);

        if (u == v)
            return;

        if (size[u] > size[v]) {
            parent[v] = u;
            size[u] += size[v];
        } else {
            parent[u] = v;
            size[v] += size[u];
        }
    }
};
class Solution {
  private:
    bool isValid(int nrow, int ncol, int n) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
    }

  public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int start = grid[0][0], end = grid[n - 1][n - 1];
        int time[n * n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                time[grid[i][j]] = i * n + j;
            }
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int t = 0; t < n * n; t++) {
            int row = time[t] / n;
            int col = time[t] % n;
            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (isValid(nrow, ncol, n) && grid[nrow][ncol] <= t)
                    ds.unionBySize(t, grid[nrow][ncol]);
            }
            if (ds.find(start) == ds.find(end))
                return t;
        }
        return (n * n) - 1;
    }
};
// @lc code=end
