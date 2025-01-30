class Solution {
public:
    // 1 : Red
    // 0 : Green
    bool isBipartite(unordered_map<int, vector<int>>& adj, int curr, vector<int>& colors, int currColor) {
        colors[curr] = currColor;
        for (int& it : adj[curr]) {
            if (colors[it] == colors[curr]) {
                return false;
            }
            if (colors[it] == -1) {
                if (isBipartite(adj, it, colors, 1 - currColor) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(unordered_map<int, vector<int>>& adj, int currNode, int n) {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(currNode);
        visited[currNode] = true;
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                for (int& it : adj[curr]) {
                    if (visited[it])
                        continue;
                    q.push(it);
                    visited[it] = true;
                }
            }
            level++;
        }
        return level - 1;
    }

    int maxofEach(unordered_map<int, vector<int>>& adj, int curr, vector<bool>& visited, vector<int>& levels) {
        int maxG = levels[curr];
        visited[curr] = true;
        for (int& it : adj[curr]) {
            if (!visited[it]) {
                maxG = max(maxG, maxofEach(adj, it, visited, levels));
            }
        }
        return maxG;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] == -1) {
                if (isBipartite(adj, node, colors, 1) == false) {
                    return -1;
                }
            }
        }
        vector<int> levels(n, 0);
        for (int node = 0; node < n; node++) {
            levels[node] = bfs(adj, node, n);
        }
        int ans = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                ans += maxofEach(adj, node, visited, levels);
            }
        }
        return ans;
    }
};