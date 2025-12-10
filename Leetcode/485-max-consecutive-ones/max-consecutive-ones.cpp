class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && nums[j] == 1) {
                ans = max(ans, (j - i + 1));
                j++;
            }
            while (j < n && nums[j] == 0) {
                j++;
            }
            if (j < n) {
                i = j;
            }
        }
        return ans;
    }
};