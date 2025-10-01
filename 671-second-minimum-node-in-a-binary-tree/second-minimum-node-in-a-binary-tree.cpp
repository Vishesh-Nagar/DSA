/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long ans = -1;
    void dfs(TreeNode* node, int rootVal) {
        if (!node)
            return;
        if (node->val > rootVal) {
            if (ans == -1 || node->val < ans)
                ans = node->val;
            return;
        }
        dfs(node->left, rootVal);
        dfs(node->right, rootVal);
    }

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root, root->val);
        return ans == -1 ? -1 : (int)ans;
    }
};