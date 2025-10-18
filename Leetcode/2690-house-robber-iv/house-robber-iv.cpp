class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1, maxR = *max_element(nums.begin(), nums.end());
        while (ans < maxR) {
            int minR = (ans + maxR) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= minR) {
                    count += 1;
                    i++;
                }
            }
            if (count >= k)
                maxR = minR;
            else
                ans = minR + 1;
        }
        return ans;
    }
};