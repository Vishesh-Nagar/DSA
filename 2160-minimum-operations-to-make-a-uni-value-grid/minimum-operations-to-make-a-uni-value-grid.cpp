class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int ans = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] % x != grid[0][0] % x)
                    return -1;
                nums.push_back(grid[row][col]);
            }
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int pref = 0;
        int suff = n - 1;

        while (pref < suff) {
            if (pref < n - suff - 1) {
                int prefOps = (pref + 1) * (nums[pref + 1] - nums[pref]) / x;
                ans += prefOps;
                pref++;
            } else {
                int suffOps = (n - suff) * (nums[suff] - nums[suff - 1]) / x;
                ans += suffOps;
                suff--;
            }
        }

        return ans;
    }
};