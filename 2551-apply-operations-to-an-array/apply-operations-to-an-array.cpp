class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == 0)
                continue;
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int nonZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZero] = nums[i];
                nonZero++;
            }
        }
        for (int i = nonZero; i < nums.size(); i++) {
            nums[i] = 0;
        }
        return nums;
    }
};