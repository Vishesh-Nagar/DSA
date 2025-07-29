class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& a) {
        int n = a.size();
        vector<int> last(31, -1), res(n);
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 31; b++) {
                if (a[i] & (1 << b))
                    last[b] = i;
            }
            int far = i;
            for (int b = 0; b < 31; b++) {
                if (last[b] != -1)
                    far = max(far, last[b]);
            }
            res[i] = far - i + 1;
        }
        return res;
    }
};