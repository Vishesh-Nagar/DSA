class Solution {
public:
    int minimumDeletions(string& s, int k) {
        vector<int> freq(26, 0);
        for (char& c : s)
            freq[c - 'a']++;
        int ans = s.size();
        for (int& a : freq) {
            int del = 0;
            for (int& b : freq) {
                if (b < a)
                    del += b;
                else if (b > a + k)
                    del += (b - (a + k));
            }
            ans = min(ans, del);
        }
        return ans;
    }
};