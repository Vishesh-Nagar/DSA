class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int val = 0, ans = 0, count = 0;
        for (int num : nums) {
            if (val < num) {
                val = num;
                ans = count = 0;
            }
            if (val == num)
                count++;
            else
                count = 0;
            ans = max(ans, count);
        }
        return ans;
    }
};