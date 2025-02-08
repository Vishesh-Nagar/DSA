//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
public:
#define pii pair<int, int>
    vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
        int v = adj.size();
        vector<int> dis(v, 999999);
        vector<bool> vis(v, false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        dis[src] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            if (vis[i])
                continue;
            vis[i] = true;
            for (auto it : adj[i]) {
                if (dis[it.first] > dis[i] + it.second) {
                    dis[it.first] = dis[i] + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends