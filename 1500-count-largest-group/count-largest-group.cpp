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
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
            mp[sum(i)]++;

        int count = 0, ans = 0;
        for (auto it : mp) {
            if (it.second > count) {
                count = it.second;
                ans = 1;
            } else if (it.second == count) {
                ans++;
            }
        }
        return ans;
    }
};