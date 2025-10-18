class Solution {
public:
    unordered_map<int, int> bobPath;
    vector<bool> visited;
    vector<vector<int>> adj;

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(), ans = INT_MIN;
        adj.resize(n);
        visited.assign(n, false);
        queue<vector<int>> q;
        q.push({0, 0, 0});

        for (vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        findBobPath(bob, 0);

        visited.assign(n, false);
        while (!q.empty()) {
            int src = q.front()[0], time = q.front()[1], income = q.front()[2];
            if (bobPath.find(src) == bobPath.end() || time < bobPath[src])
                income += amount[src];

            else if (time == bobPath[src])
                income += (amount[src] / 2);

            if (adj[src].size() == 1 && src != 0)
                ans = max(ans, income);

            for (int it : adj[src]) {
                if (!visited[it]) {
                    q.push({it, time + 1, income});
                }
            }

            visited[src] = true;
            q.pop();
        }
        return ans;
    }

    bool findBobPath(int src, int time) {
        bobPath[src] = time;
        visited[src] = true;

        if (src == 0)
            return true;

        for (auto it : adj[src]) {
            if (!visited[it]) {
                if (findBobPath(it, time + 1)) {
                    return true;
                }
            }
        }
        bobPath.erase(src);
        return false;
    }
};