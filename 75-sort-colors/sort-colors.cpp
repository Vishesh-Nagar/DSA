class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0, ones = 0, twos = 0;
        for (int i : nums) {
            if (i == 0)
                zeros++;
            else if (i == 1)
                ones++;
            else
                twos++;
        }
        int i = 0;
        while (zeros--)
            nums[i++] = 0;
        while (ones--)
            nums[i++] = 1;
        while (twos--)
            nums[i++] = 2;
        return;
    }
};