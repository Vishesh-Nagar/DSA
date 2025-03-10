class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long countOfSubstrings(string word, int k) {
        long ans = 0;
        int i = 0, j = 0;
        unordered_map<char, int> vowels;
        int cons = 0;

        vector<int> v(word.size());
        int idx = word.size();
        for (int i = word.size() - 1; i >= 0; i--) {
            v[i] = idx;
            if (!isVowel(word[i]))
                idx = i;
        }

        while (j < word.size()) {
            char c = word[j];
            if (isVowel(c))
                vowels[c]++;
            else
                cons++;

            while (cons > k) {
                char ch = word[i];
                if (isVowel(ch)) {
                    vowels[ch]--;
                    if (vowels[ch] == 0)
                        vowels.erase(ch);
                } else
                    cons--;
                i++;
            }
            while (i < word.size() && vowels.size() == 5 && cons == k) {
                ans += v[j] - j;
                char ch = word[i];
                if (isVowel(ch)) {
                    vowels[ch]--;
                    if (vowels[ch] == 0)
                        vowels.erase(ch);
                } else
                    cons--;
                i++;
            }
            j++;
        }
        return ans;
    }
};