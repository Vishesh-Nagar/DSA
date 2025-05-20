class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> del(nums.size() + 1, 0);
        for (const auto& q : queries) {
            int left = q[0];
            int right = q[1];
            del[left] += 1;
            del[right + 1] -= 1;
        }
        vector<int> ops;
        int count = 0;
        for (int d : del) {
            count += d;
            ops.push_back(count);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (ops[i] < nums[i])
                return false;
        }
        return true;
    }
};