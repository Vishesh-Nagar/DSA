class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, count = 0, ans = INT_MAX;
        for (int r = 0; r < blocks.size(); r++) {
            if (blocks[r] == 'W')
                count++;
            if (r - l + 1 == k) {
                ans = min(ans, count);
                if (blocks[l] == 'W')
                    count--;
                l++;
            }
        }
        return ans;
    }
};