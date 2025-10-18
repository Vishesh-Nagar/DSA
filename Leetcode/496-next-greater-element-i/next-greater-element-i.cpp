class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        for (int i = 0; i < n1; i++) {
            int val1 = nums1[i];
            int j = 0;
            while (j < n2 && nums2[j] != val1) {
                j++;
            }
            int val2 = -1;
            j++;
            while (j < n2) {
                if (nums2[j] > val1) {
                    val2 = nums2[j];
                    break;
                }
                j++;
            }
            ans.push_back(val2);
        }
        return ans;
    }
};