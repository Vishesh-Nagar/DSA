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
    int solve(TreeNode* curr, TreeNode* parent, TreeNode* grandParent) {
        if (curr == NULL)
            return 0;
        int sum = 0;
        if (grandParent != NULL && grandParent->val % 2 == 0)
            sum += curr->val;
        sum += solve(curr->left, curr, parent);
        sum += solve(curr->right, curr, parent);
        return sum;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root, NULL, NULL);
    }
};