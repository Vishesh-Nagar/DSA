class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        vector<int> row(n, m), col(m, n);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                mp[mat[r][c]] = {r, c};
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            auto [r, c] = mp[val];
            if (--row[r] == 0 || --col[c] == 0) {
                return i;
            }
        }
        return -1;
    }
};