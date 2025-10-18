class Solution {
public:
    int maxDistance(string st, int k) {
        int ans = 0;
        int n = 0, s = 0, e = 0, w = 0;
        for (char it : st) {
            switch (it) {
            case 'N':
                n++;
                break;
            case 'S':
                s++;
                break;
            case 'E':
                e++;
                break;
            case 'W':
                w++;
                break;
            }
            int t1 = min({n, s, k});
            int t2 = min({e, w, k - t1});
            ans = max(ans, count(n, s, t1) + count(e, w, t2));
        }
        return ans;
    }

    int count(int drt1, int drt2, int times) {
        return abs(drt1 - drt2) + times * 2;
    }
};