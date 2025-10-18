class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] == 0) {
                i = j;
                while (j < n && nums[j] == 0)
                    j++;
                long long len = j - i;
                ans += (len * (len + 1)) / 2;
            } else {
                j++;
            }
        }
        return ans;
    }
};