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

    void addMode(set<int>& modes, int value, int k, vector<int>& nums) {
        modes.insert(value);
        if (value - k >= nums.front())
            modes.insert(value - k);
        if (value + k <= nums.back())
            modes.insert(value + k);
    }

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> numCount;
        set<int> modes;
        int lastNumIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = max(ans, i - lastNumIndex);
                addMode(modes, nums[lastNumIndex], k, nums);
                lastNumIndex = i;
            }
        }
        numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
        ans = max(ans, (int)nums.size() - lastNumIndex);
        addMode(modes, nums[lastNumIndex], k, nums);
        for (int mode : modes) {
            int l = leftBound(nums, mode - k);
            int r = rightBound(nums, mode + k);
            int tempAns;
            if (numCount.count(mode))
                tempAns = min(r - l + 1, numCount[mode] + numOperations);
            else
                tempAns = min(r - l + 1, numOperations);
            ans = max(ans, tempAns);
        }
        return ans;
    }
};