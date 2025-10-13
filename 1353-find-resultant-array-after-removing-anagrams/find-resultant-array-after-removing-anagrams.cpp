class Solution {
public:
    bool compare(const string& w1, const string& w2) {
        vector<int> f(26);
        for (char c : w1)
            ++f[c - 'a'];
        for (char c : w2)
            --f[c - 'a'];
        return all_of(f.begin(), f.end(), [](int x) {
            return x == 0;
        });
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> res = {words[0]};
        for (int i = 1; i < n; ++i) {
            if (compare(words[i], words[i - 1]))
                continue;
            res.push_back(words[i]);
        }
        return res;
    }
};