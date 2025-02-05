class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            char c1 = s1[i];
            char c2 = s2[i];
            if (c1 != c2) {
                count++;
                if (count > 2)
                    return false;
            }
            mp1[c1 - 'a']++;
            mp2[c2 - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (mp1[i] != mp2[i])
                return false;
        }
        return true;
    }
};