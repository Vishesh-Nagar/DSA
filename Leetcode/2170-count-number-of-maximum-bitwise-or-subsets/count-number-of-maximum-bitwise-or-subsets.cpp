class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int num : nums)
            maxOR |= num;

        int totalSubs = 1 << nums.size();
        int ans = 0;
        for (int mask = 0; mask < totalSubs; mask++) {
            int currOR = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (((mask >> i) & 1) == 1)
                    currOR |= nums[i];
            }
            if (currOR == maxOR)
                ans++;
        }
        return ans;
    }
};