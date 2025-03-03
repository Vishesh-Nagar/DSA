class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0, equal = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot)
                less++;
            if (nums[i] == pivot)
                equal++;
        }
        int i = 0, j = less, k = less + equal;
        vector<int> ans(nums.size());
        for (int it = 0; it < nums.size(); it++) {
            if (nums[it] < pivot) {
                ans[i] = nums[it];
                i++;
            }
            if (nums[it] == pivot) {
                ans[j] = nums[it];
                j++;
            }
            if (nums[it] > pivot) {
                ans[k] = nums[it];
                k++;
            }
        }
        return ans;
    }
};