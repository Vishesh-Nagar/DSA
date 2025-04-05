class Solution {
public:
    void gen(const vector<int>& nums, int index, vector<int> curr, vector<vector<int>>& subsets) {
        if (index == nums.size()) {
            subsets.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        gen(nums, index + 1, curr, subsets);

        curr.pop_back();
        gen(nums, index + 1, curr, subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        gen(nums, 0, {}, subsets);

        int ans = 0;
        for (auto& it : subsets) {
            int subsetXORTotal = 0;
            for (int num : it)
                subsetXORTotal ^= num;
            ans += subsetXORTotal;
        }
        return ans;
    }
};