class Solution {
public:
    bool isVowel(char c) {
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
                c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string sortVowels(string s) {
        int n = s.size();
        vector<char> vowel;
        string t(n, '*');
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isVowel(c)) {
                vowel.push_back(c);
            } else {
                t[i] = s[i];
            }
        }
        int idx = 0;
        sort(vowel.begin(), vowel.end());
        for (int i = 0; i < n; i++) {
            if (t[i] == '*') {
                t[i] = vowel[idx];
                idx++;
            }
        }
        return t;
    }
};