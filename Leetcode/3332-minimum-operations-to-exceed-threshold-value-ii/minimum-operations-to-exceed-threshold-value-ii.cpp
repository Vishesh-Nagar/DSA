class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        if (n < 2)
            return 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long i : nums)
            pq.push(i);
        while (pq.size() >= 2) {
            long long val1 = pq.top();
            pq.pop();
            long long val2 = pq.top();
            pq.pop();
            if (val1 >= k && val2 >= k)
                return ans;
            ans++;
            long long minVal = min(val1, val2);
            long long maxVal = max(val1, val2);
            pq.push(minVal * 2 + maxVal);
        }
        return (int)ans;
    }
};