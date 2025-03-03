class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small, equal, large;
        for (auto i : nums) {
            if (i < pivot)
                small.push_back(i);
            if (i == pivot)
                equal.push_back(i);
            if (i > pivot)
                large.push_back(i);
        }
        vector<int> ans;
        for (auto i : small)
            ans.push_back(i);
        for (auto i : equal)
            ans.push_back(i);
        for (auto i : large)
            ans.push_back(i);

        return ans;
    }
};