class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;

        while (exp > 0) {
            if (exp % 2 == 1)
                res = ((res * base) % MOD);

            base = (base * base) % MOD;
            exp /= 2;
        }

        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    primeScores[i]++;

                    while (num % factor == 0)
                        num /= factor;
                }
            }

            if (num >= 2)
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
        for (int i = 0; i < n; i++)
            v[i] = (long long)(nextDominant[i] - i) * (i - prevDominant[i]);

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        long long score = 1;

        while (k > 0) {
            auto [num, i] = pq.top();
            pq.pop();

            long long ops = min((long long)k, v[i]);

            score = (score * power(num, ops)) % MOD;

            k -= ops;
        }

        return score;
    }
};