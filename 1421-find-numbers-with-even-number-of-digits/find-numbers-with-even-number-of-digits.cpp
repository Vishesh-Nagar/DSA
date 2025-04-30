class Solution {
public:
    bool hasEvenDigits(int n) {
        int d = 0;
        while (n) {
            d++;
            n /= 10;
        }
        return d % 2 == 0;
    }

    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            if (hasEvenDigits(i))
                ans++;
        }
        return ans;
    }
};