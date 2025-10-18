class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minPref = 0, maxPref = 0;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            minPref = min(minPref, prefixSum);
            maxPref = max(maxPref, prefixSum);
        }
        return maxPref - minPref;
    }
};