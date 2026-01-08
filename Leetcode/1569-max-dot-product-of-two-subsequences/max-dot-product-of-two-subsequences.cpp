class Solution {
public:
    vector<int> nums1, nums2;
    vector<vector<int>> dp;
    int n, m;
    const int NEG_INF = -1e9;

    int memo(int i, int j) {
        if (i == n || j == m)
            return NEG_INF;

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int take = nums1[i] * nums2[j];

        int res = max({
            take + memo(i + 1, j + 1), // take both and continue
            take,                      // take and end here
            memo(i + 1, j),            // skip nums1[i]
            memo(i, j + 1)             // skip nums2[j]
        });

        return dp[i][j] = res;
    }

    int maxDotProduct(vector<int>& a, vector<int>& b) {
        nums1 = a;
        nums2 = b;
        n = nums1.size();
        m = nums2.size();

        dp.assign(n, vector<int>(m, INT_MIN));
        return memo(0, 0);
    }
};