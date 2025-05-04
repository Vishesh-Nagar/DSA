class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        int ans = 0;
        for (auto d : dominoes) {
            if (d[0] > d[1])
                swap(d[0], d[1]);
            pair<int, int> key = {d[0], d[1]};
            ans += mp[key]++;
        }
        return ans;
    }
};