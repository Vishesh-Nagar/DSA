class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<ll> ans(n);
        for (int j = 0; j < m; j++) {
            ll time = 0;
            for (int i = 0; i < n; i++) {
                time = max(time, ans[i]) + skill[i] * mana[j];
            }
            ans[n - 1] = time;
            for (int i = n - 2; i >= 0; i--) {
                ans[i] = ans[i + 1] - skill[i + 1] * mana[j];
            }
        }
        return ans[n - 1];
    }
};