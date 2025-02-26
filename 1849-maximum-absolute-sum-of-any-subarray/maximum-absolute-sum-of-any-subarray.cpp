class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPref = INT_MAX, maxPref = INT_MIN;
        int pref = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            minPref = min(minPref, pref);
            maxPref = max(maxPref, pref);
            if (pref >= 0)
                ans = max(ans, max(pref, pref - minPref));
            else if (pref <= 0)
                ans = max(ans, max(abs(pref), abs(pref - maxPref)));
        }
        return ans;
    }
};