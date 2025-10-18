class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> A(n + 1, INT_MAX), B(n + 1, INT_MAX);
        for (const auto& pair : conflictingPairs) {
            int a = min(pair[0], pair[1]), b = max(pair[0], pair[1]);
            if (A[a] > b) {
                B[a] = A[a];
                A[a] = b;
            } else if (B[a] > b) {
                B[a] = b;
            }
        }
        long long ans = 0;
        int x = n, b2 = INT_MAX;
        vector<long long> v(n + 1, 0);
        for (int i = n; i >= 1; i--) {
            if (A[x] > A[i]) {
                b2 = min(b2, A[x]);
                x = i;
            } else {
                b2 = min(b2, A[i]);
            }
            ans += min(A[x], n + 1) - i;
            v[x] += min(min(b2, B[x]), n + 1) - min(A[x], n + 1);
        }
        return ans + *max_element(v.begin(), v.end());
    }
};