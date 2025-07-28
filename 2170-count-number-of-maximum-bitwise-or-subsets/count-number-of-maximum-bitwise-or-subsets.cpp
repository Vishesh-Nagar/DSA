class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int num : nums)
            maxOR |= num;
        return count(nums, 0, 0, maxOR);
    }

    int count(vector<int>& nums, int index, int currOR, int targetOR) {
        if (index == nums.size())
            return (currOR == targetOR) ? 1 : 0;

        int take = count(nums, index + 1, currOR | nums[index], targetOR);
        int notTake = count(nums, index + 1, currOR, targetOR);
        return notTake + take;
    }
};