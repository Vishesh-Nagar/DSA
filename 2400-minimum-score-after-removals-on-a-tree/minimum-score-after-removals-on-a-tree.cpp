class Solution {
public:
    void comp(int node, int parent, int& timer, vector<int>& nums,
                    vector<vector<int>>& graph, vector<int>& xorSum,
                    vector<int>& in, vector<int>& out) {
        in[node] = timer++;
        xorSum[node] = nums[node];
        for (int i : graph[node]) {
            if (i == parent)
                continue;
            comp(i, node, timer, nums, graph, xorSum, in, out);
            xorSum[node] ^= xorSum[i];
        }
        out[node] = timer;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), timer = 0;
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> xorSum(n), in(n), out(n);
        comp(0, -1, timer, nums, graph, xorSum, in, out);

        int ans = INT_MAX;
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int a, b, c;
                if (in[v] > in[u] && out[v] <= out[u]) {
                    a = xorSum[0] ^ xorSum[u];
                    b = xorSum[u] ^ xorSum[v];
                    c = xorSum[v];
                } else if (in[u] > in[v] && out[u] <= out[v]) {
                    a = xorSum[0] ^ xorSum[v];
                    b = xorSum[v] ^ xorSum[u];
                    c = xorSum[u];
                } else {
                    a = xorSum[0] ^ xorSum[u] ^ xorSum[v];
                    b = xorSum[u];
                    c = xorSum[v];
                }
                ans = min(ans, max({a, b, c}) - min({a, b, c}));
            }
        }

        return ans;
    }
};