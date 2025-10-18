class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        int sum = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.size(); i++) {
            char c = s[s.size() - 1 - i];
            if (c == '1') {
                if (i < bits && sum + (1 << i) <= k) {
                    sum += 1 << i;
                    ans++;
                }
            } else
                ans++;
        }
        return ans;
    }
};