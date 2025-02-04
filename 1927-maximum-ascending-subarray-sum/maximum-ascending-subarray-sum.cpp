class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            for (int j = i + 1; j < nums.size() && nums[j] > nums[j - 1]; j++)
                curr += nums[j];
            ans = max(ans, curr);
        }
        return ans;
    }
};