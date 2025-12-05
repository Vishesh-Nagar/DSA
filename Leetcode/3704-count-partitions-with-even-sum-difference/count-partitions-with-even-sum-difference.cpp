class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 1; i < n; i++) {
            leftSum += nums[i - 1];
            totalSum -= nums[i - 1];
            if (abs(leftSum - totalSum) % 2 == 0)
                ans++;
        }
        return ans;
    }
};