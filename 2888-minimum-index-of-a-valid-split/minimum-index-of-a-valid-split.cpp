class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp1, mp2;

        for (int num : nums)
            mp2[num]++;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            mp2[num]--;
            mp1[num]++;
            if (mp1[num] * 2 > i + 1 &&
                mp2[num] * 2 > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
};