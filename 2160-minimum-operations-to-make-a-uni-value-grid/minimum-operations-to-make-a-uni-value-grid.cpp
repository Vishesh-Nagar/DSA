class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int ans = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                nums.push_back(grid[row][col]);
            }
        }

        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int num = nums[n / 2];

        for (int number : nums) {
            if (number % x != num % x)
                return -1;
            ans += abs(num - number) / x;
        }

        return ans;
    }
};