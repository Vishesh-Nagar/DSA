class Solution {
public:
    int maxDepth = 0;
    TreeNode* lca = NULL;
    
    int dfs(TreeNode* node, int depth) {
        maxDepth = max(maxDepth, depth);
        if (node == NULL)
            return depth;
        int l = dfs(node->left, depth + 1);
        int r = dfs(node->right, depth + 1);
        if (l == maxDepth && r == maxDepth)
            lca = node;
        return max(l, r);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return lca;
    }
};