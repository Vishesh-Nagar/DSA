class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> count(26, 0);

        for (char c : s)
            count[c - 'a']++;

        for (int j = 0; j < t; j++) {
            vector<long long> temp(26, 0);
            for (int i = 0; i < 26; i++) {
                if (i == 25) {
                    temp[0] = (temp[0] + count[i]) % MOD;
                    temp[1] = (temp[1] + count[i]) % MOD;
                } else
                    temp[i + 1] = (temp[i + 1] + count[i]) % MOD;
            }
            count = temp;
        }

        long long ans = 0;
        for (long long c : count)
            ans = (ans + c) % MOD;

        return ans;
    }
};