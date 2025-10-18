//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'L' && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    while(!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for(int k = 0; k < 8; k++) {
                            int nr = row + dr[k];
                            int nc = col + dc[k];
                            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                grid[nr][nc] == 'L' && !vis[nr][nc]) {
                                q.push({nr, nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends