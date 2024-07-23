/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
  int spaceOptimization(vector<int> &nums) {
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      int take = nums[i];
      if (i > 1)
        take += prev2;
      int notTake = 0 + prev;
      int curr = max(take, notTake);
      prev2 = prev;
      prev = curr;
    }
    return prev;
  }
  int rob(vector<int> &nums) {
    vector<int> temp1,temp2;
    for(int i=0;i<nums.size();i++){
        if(i != 0) temp1.push_back(nums[i]);
        if(i != nums.size()-1) temp2.push_back(nums[i]);
    }
    return max(spaceOptimization(temp1),spaceOptimization(temp2));
  }
};
// @lc code=end
