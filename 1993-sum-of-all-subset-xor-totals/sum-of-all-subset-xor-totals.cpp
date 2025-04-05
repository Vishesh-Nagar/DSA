class Solution {
public:
    int XORSum(vector<int>& nums, int idx, int curr) {
        if (idx == nums.size())
            return curr;
        int take = XORSum(nums, idx + 1, curr ^ nums[idx]);
        int notTake = XORSum(nums, idx + 1, curr);
        return take + notTake;
    }

    int subsetXORSum(vector<int>& nums) {
        return XORSum(nums, 0, 0);
    }
};