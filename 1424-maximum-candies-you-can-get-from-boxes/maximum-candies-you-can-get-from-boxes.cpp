class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> vis(n, false);
        vector<bool> boxPresent(n, false);
        queue<int> q;
        for (int b : initialBoxes) {
            boxPresent[b] = true;
            if (status[b])
                q.push(b);
        }

        int ans = 0;
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            if (vis[box])
                continue;
            vis[box] = true;
            ans += candies[box];

            for (int k : keys[box]) {
                status[k] = 1;
                if (boxPresent[k] && !vis[k])
                    q.push(k);
            }
            for (int b : containedBoxes[box]) {
                boxPresent[b] = true;
                if (status[b] && !vis[b])
                    q.push(b);
            }
        }
        return ans;
    }
};