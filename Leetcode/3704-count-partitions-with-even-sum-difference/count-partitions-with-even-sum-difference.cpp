class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        return totalSum % 2 == 0 ? n - 1 : 0;
    }
};