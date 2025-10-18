//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool fun(int i, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathvis) {
        vis[i] = true;
        pathvis[i] = true;
        for(auto x : adj[i]) {
            if(!vis[x]) {
                if(fun(x, adj, vis, pathvis))
                    return true;

            } else if(pathvis[x])
                return true;
        }
        pathvis[i] = false;
        return false;
    }


    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto z : edges)
            adj[z[0]].push_back(z[1]);

        vector<bool> vis(V, false);
        vector<bool> pathvis(V, false);

        for(int i = 0; i < V; i++) {
            if(!vis[i] && fun(i, adj, vis, pathvis))
                return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends