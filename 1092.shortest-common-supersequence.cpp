/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence
 */

// @lc code=start
class Solution {
  public:
    string solve(string &str1, string &str2, int i, int j) {
        if (i < 0 && j < 0)
            return "";
        if (j < 0)
            return str1.substr(0, i + 1);
        if (i < 0)
            return str2.substr(0, j + 1);
        if (str1[i] == str2[j]) {
            return solve(str1, str2, i - 1, j - 1) + str1[i];
        } else {
            string ans1 = solve(str1, str2, i - 1, j) + str1[i];
            string ans2 = solve(str1, str2, i, j - 1) + str2[j];
            if (ans1.size() < ans2.size())
                return ans1;
            return ans2;
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return solve(str1, str2, str1.size() - 1, str2.size() - 1);
    }
};
// @lc code=end
