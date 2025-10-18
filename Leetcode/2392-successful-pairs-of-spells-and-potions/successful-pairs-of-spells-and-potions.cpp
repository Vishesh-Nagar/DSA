class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int s : spells) {
            long long need = (success + s - 1) / s;
            int idx = lower_bound(potions.begin(), potions.end(), need) -
                      potions.begin();
            ans.push_back(m - idx);
        }
        return ans;
    }
};