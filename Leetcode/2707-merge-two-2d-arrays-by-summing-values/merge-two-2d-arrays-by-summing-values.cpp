class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < N1 && j < N2) {
            if (nums1[i][0] == nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < N1) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < N2) {
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
};