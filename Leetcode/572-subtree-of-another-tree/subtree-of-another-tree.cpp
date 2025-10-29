class Solution {
public:
    bool isSame(TreeNode* s, TreeNode* t) {
        if (s == NULL || t == NULL)
            return s == NULL && t == NULL;
        else if (s->val == t->val)
            return isSame(s->left, t->left) && isSame(s->right, t->right);
        else
            return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL)
            return false;
        else if (isSame(s, t))
            return true;
        else
            return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};