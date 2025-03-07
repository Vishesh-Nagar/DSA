class Solution {
public:
    vector<int> sieve(int upperLimit) {
        vector<int> sieve(upperLimit + 1, 1);
        sieve[0] = 0;
        sieve[1] = 0;
        for (int n = 2; n * n <= upperLimit; n++) {
            if (sieve[n] == 1) {
                for (int multiple = n * n; multiple <= upperLimit; multiple += n)
                    sieve[multiple] = 0;
            }
        }
        return sieve;
    }

    vector<int> closestPrimes(int left, int right) {
        int upperLimit = right;
        vector<int> sieveArray = sieve(upperLimit);
        vector<int> primes;
        for (int num = left; num <= right; num++) {
            if (sieveArray[num] == 1)
                primes.push_back(num);
        }

        if (primes.size() < 2)
            return vector<int>{-1, -1};

        int minDifference = INT_MAX;
        vector<int> closestPair(2, -1);

        for (int index = 1; index < primes.size(); index++) {
            int difference = primes[index] - primes[index - 1];
            if (difference < minDifference) {
                minDifference = difference;
                closestPair[0] = primes[index - 1];
                closestPair[1] = primes[index];
            }
        }
        return closestPair;
    }
};