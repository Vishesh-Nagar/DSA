class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int len = nums.size(), count = 0, left = 0, right = 0;
        for (int i : nums)
            right += i;
        for (int i = 0; i < len; i++) {
            left += nums[i];
            right -= nums[i];
            if (nums[i] != 0)
                continue;
            if (left == right)
                count += 2;
            if (abs(left - right) == 1)
                count++;
        }
        return count;
    }
};