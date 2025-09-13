class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int a = 0, b = 0;
        for (char c : s) {
            int i = c - 'a';
            freq[i]++;
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
                a = max(a, freq[i]);
            else
                b = max(b, freq[i]);
        }
        return a + b;
    }
};
