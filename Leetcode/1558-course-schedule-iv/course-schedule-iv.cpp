class Solution {
public:
#define vvi vector<vector<int>>
    vector<bool> checkIfPrerequisite(int n, vvi& pre, vvi& que) {
        vector<vector<bool>> isPre(n, vector<bool>(n, false));
        for (auto edge : pre)
            isPre[edge[0]][edge[1]] = true;

        for (int inter = 0; inter < n; inter++) {
            for (int src = 0; src < n; src++) {
                for (int t = 0; t < n; t++)
                    isPre[src][t] = isPre[src][t] || (isPre[src][inter] && isPre[inter][t]);
            }
        }

        vector<bool> ans;
        for (auto q : que)
            ans.push_back(isPre[q[0]][q[1]]);

        return ans;
    }
};