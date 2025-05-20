class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> del(nums.size() + 1);
        for (auto& q : queries) {
            del[q[0]]++;
            if (q[1] + 1 < del.size())
                del[q[1] + 1]--;
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += del[i];
            if (cnt < nums[i])
                return false;
        }
        return true;
    }
};