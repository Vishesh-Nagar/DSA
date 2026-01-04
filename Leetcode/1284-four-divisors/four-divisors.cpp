class Solution {
public:
    pair<int, int> divisorsAndSum(int n) {
        int count = 0, sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i * i == n) {
                    count++;
                    sum += i;
                } else {
                    count += 2;
                    sum += i + n / i;
                }
                if (count > 4)
                    return {count, sum};
            }
        }
        return {count, sum};
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            auto p = divisorsAndSum(i);
            if (p.first == 4)
                ans += p.second;
        }
        return ans;
    }
};
