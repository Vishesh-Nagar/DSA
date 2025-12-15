class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = 1;
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans += count;
            if (prices[i - 1] - prices[i] == 1)
                count++;
            else
                count = 1;
        }
        ans += count;
        return ans;
    }
};