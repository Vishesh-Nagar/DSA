class Solution {
public:
    void helper(vector<int> nums, int i, vector<int>& ds,
                vector<vector<int>>& ans) {
        int n = nums.size();
        if (i == n) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        helper(nums, i + 1, ds, ans);
        ds.pop_back();
        while (i + 1 < n && nums[i] == nums[i + 1]) {
            i++;
        }
        helper(nums, i + 1, ds, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        helper(nums, 0, ds, ans);
        return ans;
    }
};