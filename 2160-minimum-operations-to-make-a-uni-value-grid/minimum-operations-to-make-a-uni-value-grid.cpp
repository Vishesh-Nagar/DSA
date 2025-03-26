class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int ans = INT_MAX;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] % x != grid[0][0] % x)
                    return -1;
                nums.push_back(grid[row][col]);
            }
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);

        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + nums[i - 1];

        for (int i = n - 2; i >= 0; i--)
            suff[i] = suff[i + 1] + nums[i + 1];

        for (int i = 0; i < n; i++) {
            int left = (nums[i] * i - pref[i]) / x;

            int right = (suff[i] - nums[i] * (n - i - 1)) / x;

            ans = min(ans, left + right);
        }

        return ans;
    }
};