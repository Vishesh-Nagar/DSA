class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        int f1 = 1, f2 = s.size();
        for (auto [c, value] : mp) {
            if (value % 2 == 1)
                f1 = max(f1, value);
            else
                f2 = min(f2, value);
        }
        return f1 - f2;
    }
};