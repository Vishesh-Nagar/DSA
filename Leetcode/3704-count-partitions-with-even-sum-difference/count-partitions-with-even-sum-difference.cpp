class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int leftSum = 0, rightSum = 0;
            for (int j = 0; j <= i; j++) {
                leftSum += nums[j];
            }
            for (int j = i + 1; j < n; j++) {
                rightSum += nums[j];
            }
            if (abs(leftSum - rightSum) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};