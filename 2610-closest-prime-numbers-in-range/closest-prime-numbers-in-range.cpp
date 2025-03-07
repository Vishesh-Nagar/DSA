class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int prevPrime = -1, cA = -1, cB = -1;
        int diff = 1e6;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                if (prevPrime != -1) {
                    int difference = i - prevPrime;
                    if (difference < diff) {
                        diff = difference;
                        cA = prevPrime;
                        cB = i;
                    }
                    if (difference == 2 or difference == 1)
                        return {prevPrime, i};
                }
                prevPrime = i;
            }
        }
        return (cA == -1) ? vector<int>{-1, -1} : vector<int>{cA, cB};
    }
};