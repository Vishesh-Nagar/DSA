class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        int f1 = 0, f2 = s.size();
        for (int val : freq) {
            if (val == 0)
                continue;
            if (val % 2 == 1)
                f1 = max(f1, val);
            else
                f2 = min(f2, val);
        }
        if (f2 == s.size())
            f2 = 0;
        return f1 - f2;
    }
};