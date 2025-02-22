class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return helper(traversal, index, 0);
    }

    TreeNode* helper(const string& traversal, int& index, int depth) {
        if (index >= traversal.size())
            return nullptr;

        int dash = 0;
        while (index + dash < traversal.size() &&
               traversal[index + dash] == '-')
            dash++;

        if (dash != depth)
            return nullptr;

        index += dash;

        int val = 0;
        while (index < traversal.size() && isdigit(traversal[index])) {
            val = val * 10 + (traversal[index] - '0');
            index++;
        }

        TreeNode* node = new TreeNode(val);

        node->left = helper(traversal, index, depth + 1);
        node->right = helper(traversal, index, depth + 1);

        return node;
    }
};