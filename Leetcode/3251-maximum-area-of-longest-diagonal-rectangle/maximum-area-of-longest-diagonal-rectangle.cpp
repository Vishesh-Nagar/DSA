class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int ans = 0, diag = 0;
        for (int i = 0; i < d.size(); i++) {
            int l = d[i][0];
            int w = d[i][1];
            int val = l * l + w * w;

            if (val > diag || (val == diag && l * w > ans)) {
                diag = val;
                ans = l * w;
            }
        }
        return ans;
    }
};