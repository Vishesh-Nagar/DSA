class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            int start = s.find(part);
            s = s.substr(0, start) + s.substr(start + part.length());
        }
        return s;
    }
};