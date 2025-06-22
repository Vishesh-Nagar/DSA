class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int extra = s.size() % k;
        if (extra != 0)
            s.append(k - extra, fill);
        vector<string> ans;
        string temp = "";
        for (char c : s) {
            temp.push_back(c);
            if (temp.size() == k) {
                ans.push_back(temp);
                temp = "";
            }
        }
        return ans;
    }
};