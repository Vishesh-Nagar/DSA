class Solution {
public:
    int dfs(int box, vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
            vector<bool>& vis, vector<bool>& boxPresent) {
        if (!status[box] || vis[box])
            return 0;
        vis[box] = true;
        int res = candies[box];
        for (int k : keys[box]) {
            status[k] = 1;
            if (boxPresent[k] && !vis[k]) {
                res += dfs(k, status, candies, keys, containedBoxes, vis,
                           boxPresent);
            }
        }
        for (int b : containedBoxes[box]) {
            boxPresent[b] = true;
            if (status[b] && !vis[b]) {
                res += dfs(b, status, candies, keys, containedBoxes, vis,
                           boxPresent);
            }
        }
        return res;
    }

    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> vis(n, false);
        vector<bool> boxPresent(n, false);
        int total = 0;

        for (int b : initialBoxes)
            boxPresent[b] = true;

        bool found;
        do {
            found = false;
            for (int i = 0; i < n; i++) {
                if (boxPresent[i] && status[i] && !vis[i]) {
                    total += dfs(i, status, candies, keys, containedBoxes, vis,
                                 boxPresent);
                    found = true;
                }
            }
        } while (found);

        return total;
    }
};