class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pivot = rand() % (right - left + 1) + left;
            int newPivot = partition(nums, left, right, pivot);
            if (newPivot == nums.size() - k) {
                return nums[newPivot];
            } else if (newPivot > nums.size() - k) {
                right = newPivot - 1;
            } else {
                left = newPivot + 1;
            }
        }
    }

    int partition(vector<int>& nums, int left, int right, int pivot) {
        int pvt = nums[pivot];
        swap(nums[pivot], nums[right]);
        int idx = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pvt) {
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        swap(nums[right], nums[idx]);
        return idx;
    }
};