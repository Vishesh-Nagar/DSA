//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>

    void find(int u, int parent, vi& disc, vi& low, vb& isArt, vvi& adj, int& time) {
        disc[u] = low[u] = ++time;
        int children = 0;
        for(auto v : adj[u]) {
            if(disc[v] == -1) {
                children++;
                find(v, u, disc, low, isArt, adj, time);

                low[u] = min(low[u], low[v]);
                if(parent == -1 && children > 1)
                    isArt[u] = true;
                if(parent != -1 && low[v] >= disc[u])
                    isArt[u] = true;

            } else if(v != parent)
                low[u] = min(low[u], disc[v]);

        }
    }

    vector<int> articulationPoints(int n, vvi& edges) {
        vvi adj(n);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vi disc(n, -1), low(n, -1);
        vb isArt(n, false);
        int time = 0;
        for(int i = 0; i < n; i++) {
            if(disc[i] == -1)
                find(i, -1, disc, low, isArt, adj, time);
        }

        vi res;
        for(int i = 0; i < n; i++)
            if(isArt[i])
                res.push_back(i);
        if(res.empty())
            return {-1};
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends