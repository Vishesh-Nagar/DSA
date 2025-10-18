class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[j - 1]) {
                    curr++;
                } else {
                    break;
                }
            }
            ans = max(ans, curr);
        }
        for (int i = 0; i < nums.size(); i++) {
            int curr = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[j - 1]) {
                    curr++;
                } else {
                    break;
                }
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};