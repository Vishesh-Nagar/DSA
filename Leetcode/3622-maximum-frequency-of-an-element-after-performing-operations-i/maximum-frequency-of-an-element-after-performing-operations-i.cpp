class Solution {
public:
    int leftBound(vector<int>& nums, int value) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < value)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }

    int rightBound(vector<int>& nums, int value) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (nums[m] > value)
                r = m - 1;
            else
                l = m;
        }
        return l;
    }

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> mp;
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[idx]) {
                mp[nums[idx]] = i - idx;
                ans = max(ans, i - idx);
                idx = i;
            }
        }
        mp[nums[idx]] = nums.size() - idx;
        ans = max(ans, (int)nums.size() - idx);
        for (int i = nums.front(); i <= nums.back(); i++) {
            int l = leftBound(nums, i - k);
            int r = rightBound(nums, i + k);
            int temp;
            if (mp.count(i))
                temp = min(r - l + 1, mp[i] + numOperations);
            else
                temp = min(r - l + 1, numOperations);
            ans = max(ans, temp);
        }
        return ans;
    }
};