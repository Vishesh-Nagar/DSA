class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            if (s.size() % 2 != 0)
                continue;
            int n = s.size() / 2;
            int leftSum = 0, rightSum = 0;
            for (int j = 0; j < n; j++)
                leftSum += s[j] - '0';
            for (int j = n; j < 2 * n; j++)
                rightSum += s[j] - '0';
            if (leftSum == rightSum)
                ans++;
        }
        return ans;
    }
};