class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int firstDiff = 0, secDiff = 0, count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (count > 2)
                    return false;
                else if (count == 1)
                    firstDiff = i;
                else
                    secDiff = i;
            }
        }
        return (s1[firstDiff] == s2[secDiff]) && (s1[secDiff] == s2[firstDiff]);
    }
};