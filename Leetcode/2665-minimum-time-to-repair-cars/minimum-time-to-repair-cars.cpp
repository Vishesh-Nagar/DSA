class Solution {
public:
    long repairCars(vector<int>& ranks, int cars) {
        int minRank = ranks[0], maxRank = ranks[0];
        for (int i : ranks) {
            minRank = min(minRank, i);
            maxRank = max(maxRank, i);
        }

        vector<int> freq(maxRank + 1);
        for (int i : ranks) {
            minRank = min(minRank, i);
            freq[i]++;
        }

        long long low = 1, high = 1LL * minRank * cars * cars;
        while (low < high) {
            long long mid = (low + high) / 2;
            long long count = 0;
            for (int i = 1; i <= maxRank; i++)
                count += freq[i] * (long long)sqrt(mid / (long long)i);

            if (count >= cars)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};