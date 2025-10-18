//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, int c, int d, vector <int>& vis) {
        for(auto it : adj[node]) {
            if(!vis[it] && !(node == c && it == d || node == d && it == c)) {
                vis[it] = 1;
                dfs(it, adj, c, d, vis);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>>& edges, int c, int d) {
        vector <int> vis(V, 0);
        vector<vector<int>> adj(V);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(c, adj, c, d, vis);
        if(!vis[d])
            return true;
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends