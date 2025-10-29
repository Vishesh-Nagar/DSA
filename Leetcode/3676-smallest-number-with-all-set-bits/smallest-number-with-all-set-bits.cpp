class Solution {
public:
    int smallestNumber(int n) {
        string s = "";
        while (n) {
            if (n % 2 == 0)
                s.push_back('0');
            else
                s.push_back('1');
            n /= 2;
        }
        for (int i = 0; i < s.size(); i++)
            s[i] = '1';
        int ans = 0, p = 1;
        for (char c : s) {
            ans += p;
            p *= 2;
        }
        return ans;
    }
};