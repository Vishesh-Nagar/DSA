class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long helper(string word, int k) {
        long ans = 0;
        int i = 0, j = 0;
        unordered_map<char, int> vowels;
        int cons = 0;

        while (j < word.length()) {
            char c = word[j];
            if (isVowel(c))
                vowels[c]++;
            else
                cons++;

            while (vowels.size() == 5 and cons >= k) {
                ans += word.length() - j;
                char ch = word[i];
                if (isVowel(ch)) {
                    if (--vowels[ch] == 0)
                        vowels.erase(ch);
                } else
                    cons--;
                i++;
            }
            j++;
        }
        return ans;
    }

    long countOfSubstrings(string word, int k) {
        return helper(word, k) - helper(word, k + 1);
    }
};