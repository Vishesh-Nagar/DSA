class Solution {
public:
    string answerString(string word, int nF) {
        if (nF == 1)
            return word;
        int n = word.size();
        string ans;
        for (int i = 0; i < n; i++)
            ans = max(ans, word.substr(i, min(n - nF + 1, n - i)));
        return ans;
    }
};