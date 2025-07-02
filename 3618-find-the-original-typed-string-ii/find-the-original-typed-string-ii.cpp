class Solution {
public:
    static const int mod = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        int n = word.size(), cnt = 1;
        vector<int> v;
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1])
                cnt++;
            else {
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);

        int ans = 1;
        for (int i : v)
            ans = static_cast<long long>(ans) * i % mod;

        if (v.size() >= k)
            return ans;

        vector<int> f(k), g(k, 1);
        f[0] = 1;
        for (int i = 0; i < v.size(); i++) {
            vector<int> f_new(k);
            for (int j = 1; j < k; j++) {
                f_new[j] = g[j - 1];
                if (j - v[i] - 1 >= 0) {
                    f_new[j] = (f_new[j] - g[j - v[i] - 1] + mod) % mod;
                }
            }
            vector<int> g_new(k);
            g_new[0] = f_new[0];
            for (int j = 1; j < k; j++) {
                g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
            }
            f = move(f_new);
            g = move(g_new);
        }
        return (ans - g[k - 1] + mod) % mod;
    }
};