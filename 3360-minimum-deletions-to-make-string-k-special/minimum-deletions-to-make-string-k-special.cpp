class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for (auto ch : word)
            mp[ch]++;
        int ans = word.size();
        for (auto& [_, a] : mp) {
            int del = 0;
            for (auto& [_, b] : mp) {
                if (a > b) {
                    del += b;
                } else if (b > a + k) {
                    del += b - (a + k);
                }
            }
            ans = min(ans, del);
        }
        return ans;
    }
};