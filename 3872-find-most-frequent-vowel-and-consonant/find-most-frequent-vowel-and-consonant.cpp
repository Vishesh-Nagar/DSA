class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> vowel, cons;
        for (char c : s) {
            if (isVowel(c))
                vowel[c]++;
            else
                cons[c]++;
        }
        int a = 0, b = 0;
        for (auto it : vowel) {
            a = max(a, it.second);
        }
        for (auto it : cons) {
            b = max(b, it.second);
        }
        return a + b;
    }
};