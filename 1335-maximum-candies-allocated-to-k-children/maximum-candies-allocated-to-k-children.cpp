class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxi = 0;
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += candies[i];
            maxi = max(maxi, candies[i]);
        }

        if (total < k)
            return 0;

        int l = 1, r = maxi, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long count = 0;
            for (int i = 0; i < n; i++)
                count += candies[i] / mid;

            if (count >= k) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }

        return ans;
    }
};