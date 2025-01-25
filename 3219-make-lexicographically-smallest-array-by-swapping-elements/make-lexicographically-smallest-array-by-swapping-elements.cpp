class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());

        int groupNum = 0;
        unordered_map<int, int> mp;
        mp[v[0]] = groupNum;
        unordered_map<int, list<int>> mpl;
        mpl[groupNum].push_back(v[0]);

        for (int i = 1; i < n; i++) {
            if (abs(v[i] - v[i - 1]) > limit) {
                groupNum += 1;
            }
            mp[v[i]] = groupNum;
            mpl[groupNum].push_back(v[i]);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = mp[num];
            ans[i] = *mpl[group].begin();
            mpl[group].pop_front();
        }
        return ans;
    }
};