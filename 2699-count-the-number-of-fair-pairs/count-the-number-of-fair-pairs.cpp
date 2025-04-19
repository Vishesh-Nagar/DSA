class Solution {
public:
    long long lb(vector<int>& nums, int value) {
        int left = 0, right = nums.size() - 1;
        long long res = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < value) {
                res += (right - left);
                left++;
            } else
                right--;
        }
        return res;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return lb(nums, upper + 1) - lb(nums, lower);
    }
};