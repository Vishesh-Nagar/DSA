class Solution {
public:
    const int MOD = 1e9 + 7;
    long long modExp(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        long long evenPow = modExp(5, even, MOD);
        long long oddPow = modExp(4, odd, MOD);
        return (evenPow * oddPow) % MOD;
    }
};