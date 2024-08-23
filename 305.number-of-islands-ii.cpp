class DisjointSet {
    vector<int> parent, rank, size;

  public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
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

        if (ulp_u != ulp_v) {
            if (rank[ulp_u] > rank[ulp_v])
                parent[ulp_v] = ulp_u;
            else if (rank[ulp_u] < rank[ulp_v])
                parent[ulp_u] = ulp_v;
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        return;
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u != ulp_v) {
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_v];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
        return;
    }
};
class Solution {
  private:
    bool isValid(int adjr, int adjc, int n, int m) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }

  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;
        for (auto it : operators) {
            int row = it[0], col = it[1];
            if (vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int idx = 0; idx < 4; idx++) {
                int adjr = row + drow[idx];
                int adjc = col + dcol[idx];
                if (isValid(adjr, adjc, n, m)) {
                    if (vis[adjr][adjc] == 1) {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        if (ds.findParent(nodeNo) != ds.findParent(adjNodeNo)) {
                            ds.unionBySize(nodeNo, adjNodeNo);
                            cnt--;
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};