class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for (char c : s) {
            if (isdigit(c)) {
                if (!ans.empty())
                    ans.pop_back();
            } else
                ans.push_back(c);
        }
        return ans;
    }
};