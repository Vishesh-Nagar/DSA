class Solution {
public:
    int dfs(int node, int parentNode, vector<int> adj[],
            vector<int>& nodeValues, int k, int& ans) {
        int sum = 0;
        for (auto it : adj[node]) {
            if (it != parentNode) {
                sum += dfs(it, node, adj, nodeValues, k, ans);
                sum %= k;
            }
        }
        sum += nodeValues[node];
        sum %= k;
        if (sum == 0)
            ans++;
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<int> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        dfs(0, -1, adj, values, k, ans);
        return ans;
    }
};