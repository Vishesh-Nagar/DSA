class Solution {
public:
    int sum(int n) {
        int val = 0;
        while (n) {
            val += n % 10;
            n /= 10;
        }
        return val;
    }

    int countLargestGroup(int n) {
        vector<int> v(37, 0);
        for (int i = 1; i <= n; i++)
            v[sum(i)]++;

        int count = 0, ans = 0;
        for (int i = 1; i < 37; i++) {
            if (v[i] > count) {
                count = v[i];
                ans = 1;
            } else if (v[i] == count)
                ans++;
        }
        return ans;
    }
};