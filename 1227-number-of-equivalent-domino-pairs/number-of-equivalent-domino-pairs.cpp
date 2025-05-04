class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& D) {
        int n = D.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = D[i][0];
            int b = D[i][1];
            for (int j = i + 1; j < n; j++) {
                int c = D[j][0];
                int d = D[j][1];
                if (a == c && b == d || a == d && b == c)
                    ans++;
            }
        }
        return ans;
    }
};