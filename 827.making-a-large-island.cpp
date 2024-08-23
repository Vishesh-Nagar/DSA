/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
class DisjointSet {
  public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  private:
    bool isValid(int nrow, int ncol, int n) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
    }

  public:
    int largestIsland(vector<vector<int>> &grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int idx = 0; idx < 4; idx++) {
                    int nrow = row + dr[idx];
                    int ncol = col + dc[idx];
                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int idx = 0; idx < 4; idx++) {
                    int nrow = row + dr[idx];
                    int ncol = col + dc[idx];
                    if (isValid(nrow, ncol, n)) {
                        if (grid[nrow][ncol] == 1) {
                            components.insert(ds.findUParent(nrow * n + ncol));
                        }
                    }
                }
                int totalSize = 0;
                for (auto it : components) {
                    totalSize += ds.size[it];
                }
                mx = max(mx, totalSize + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUParent(cellNo)]);
        }
        return mx;
    }
};
// @lc code=end
