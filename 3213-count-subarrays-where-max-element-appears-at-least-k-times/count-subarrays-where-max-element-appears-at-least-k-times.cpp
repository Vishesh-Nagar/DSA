class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEl = 0;
        for (int i = 0; i < n; i++)
            maxEl = max(maxEl, nums[i]);
        
        long long count = 0;
        long long int i = 0, j = 0, ans = 0;
        while (j < n) {
            if (nums[j] == maxEl)
                count++;
            while (count >= k) {
                if (nums[i] == maxEl)
                    count--;
                i++;
                ans += n - j;
            }
            j++;
        }
        return ans;
    }
};