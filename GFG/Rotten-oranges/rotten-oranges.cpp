//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,1,0,-1};

    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, time = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2)
                    q.push({i, j});
                if(mat[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;

        while(!q.empty()) {
            int s = q.size();
            bool rotted = false;
            while(s--) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1) {
                        mat[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if(rotted)
                time++;
        }

        return fresh == 0 ? time : -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends