class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;

        while (exp > 0) {

            if (exp % 2 == 1) {
                res = ((res * base) % MOD);
            }

            base = (base * base) % MOD;
            exp /= 2;
        }

        return res;
    }

    vector<int> sieve(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for (int number = 2; number <= limit; number++) {
            if (!isPrime[number])
                continue;

            primes.push_back(number);

            for (long long multiple = (long long)number * number;
                 multiple <= limit; multiple += number) {
                isPrime[multiple] = false;
            }
        }

        return primes;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);

        int maxEL = 0;
        for (int i = 0; i < n; i++)
            maxEL = max(maxEL, nums[i]);

        vector<int> primes = sieve(maxEL);

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int prime : primes) {
                if (prime * prime > num)
                    break;
                if (num % prime != 0)
                    continue;

                primeScores[i]++;
                while (num % prime == 0)
                    num /= prime;
            }

            if (num > 1)
                primeScores[i]++;
        }

        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && primeScores[st.top()] < primeScores[i]) {
                int topIndex = st.top();
                st.pop();

                nextDominant[topIndex] = i;
            }

            if (!st.empty())
                prevDominant[i] = st.top();

            st.push(i);
        }

        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = (long long)(nextDominant[i] - i) * (i - prevDominant[i]);
        }

        vector<pair<int, int>> sortedArray(n);
        for (int i = 0; i < n; i++) {
            sortedArray[i] = {nums[i], i};
        }

        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        long long score = 1;
        int idx = 0;

        while (k > 0) {

            auto [num, i] = sortedArray[idx++];

            long long operations = min((long long)k, v[i]);

            score = (score * power(num, operations)) % MOD;

            k -= operations;
        }

        return score;
    }
};