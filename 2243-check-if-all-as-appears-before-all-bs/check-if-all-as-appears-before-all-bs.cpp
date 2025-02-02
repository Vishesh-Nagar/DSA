class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int i = 0;
        while (s[i] == 'a')
            i++;
            
        int j = i + 1;
        while (j < n) {
            if (s[j] == 'a')
                return false;
            j++;
        }
        return true;
    }
};