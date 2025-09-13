class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        int a = 0, b = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (isVowel('a' + i))
                    a = max(a, freq[i]);
                else
                    b = max(b, freq[i]);
            }
        }
        return a + b;
    }
};
