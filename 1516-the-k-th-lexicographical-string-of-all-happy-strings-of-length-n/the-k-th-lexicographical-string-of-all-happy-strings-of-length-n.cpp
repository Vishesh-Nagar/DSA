class Solution {
public:
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> ans;
        helper(n, curr, ans);
        if (ans.size() < k)
            return "";
        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }

    void helper(int n, string curr, vector<string>& ans) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        for (char c = 'a'; c <= 'c'; c++) {
            if (curr.size() > 0 && curr.back() == c)
                continue;
            helper(n, curr + c, ans);
        }
    }
};