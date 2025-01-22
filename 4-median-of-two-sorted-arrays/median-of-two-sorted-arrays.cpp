class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int total = n + m;
        int ind0 = (total - 1) / 2;
        int ind1 = total / 2;
        int i = 0, j = 0, count = 0;
        int curr = 0, prev = 0;
        while (i < n || j < m) {
            prev = curr;
            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }
            if (count == ind1) {
                if (total % 2 == 0) {
                    return (prev + curr) / 2.0;
                } else {
                    return curr;
                }
            }
            count++;
        }
        return 0.0;
    }
};