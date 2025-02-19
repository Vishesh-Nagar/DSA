class Solution {
public:
    string getHappyString(int n, int k) {
        string curr = "";
        string ans = "";
        int idx = 0;
        helper(n, k, curr, idx, ans);
        return ans;
    }

    void helper(int n, int k, string& curr, int& idx, string& ans) {
        if (curr.size() == n) {
            idx++;
            if (idx == k)
                ans = curr;
            return;
        }
        for (char c = 'a'; c <= 'c'; c++) {
            if (curr.size() > 0 && curr.back() == c)
                continue;
            curr += c;
            helper(n, k, curr, idx, ans);
            if (ans != "")
                return;
            curr.pop_back();
        }
    }
};