class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        while (true) {
            bool flag = false;
            for (int i : nums) {
                if (i == original) {
                    flag = true;
                    break;
                }
            }
            if (flag == true)
                original *= 2;
            else
                return original;
        }
        return -1;
    }
};