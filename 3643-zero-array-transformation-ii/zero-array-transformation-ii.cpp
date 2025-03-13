class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), left = 0, right = queries.size();
        if (!helper(nums, queries, right))
            return -1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (helper(nums, queries, middle))
                right = middle - 1;
            else
                left = middle + 1;
        }
        return left;
    }

    bool helper(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size(), sum = 0;
        vector<int> diff(n + 1);

        for (int idx = 0; idx < k; idx++) {
            int start = queries[idx][0], end = queries[idx][1], val = queries[idx][2];
            diff[start] += val;
            diff[end + 1] -= val;
        }

        for (int numIndex = 0; numIndex < n; numIndex++) {
            sum += diff[numIndex];
            if (sum < nums[numIndex])
                return false;
        }
        return true;
    }
};