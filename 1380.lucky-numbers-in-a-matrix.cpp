/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    vector<int> temp1,temp2;
    vector<int> ans;
    int n = matrix.size(), m = matrix[0].size();
    for (int r = 0; r < n; r++) {
      int minr = matrix[r][0];
      for (int c = 0; c < m; c++) {
        minr = min(minr, matrix[r][c]);
      }
      temp1.push_back(minr);
    }
    for (int c = 0; c < m; c++) {
      int maxc = matrix[0][c];
      for (int r = 0; r < n; r++) {
        maxc = max(maxc, matrix[r][c]);
      }
      temp2.push_back(maxc);
    }
    for (int i = 0; i < temp.size(); i++) {
      bool flag = true;
      for (int j = 0; j < temp.size(); j++) {
        if (i != j && temp[i] > temp[j]) {
          flag = false;
        }
      }
      if (flag) {
        ans.push_back(temp[i]);
      }
    }
    return ans;
  }
};
// @lc code=end
