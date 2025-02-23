class Solution {
public:
#define vi vector<int>
    TreeNode* constructFromPrePost(vi& pre, vi& post) {
        int n = pre.size();
        return helper(0, n - 1, 0, pre, post);
    }

    TreeNode* helper(int preStart, int preEnd, int postStart, vi& pre,
                     vi& post) {
        if (preStart > preEnd)
            return NULL;

        if (preStart == preEnd)
            return new TreeNode(pre[preStart]);

        int leftRoot = pre[preStart + 1];
        int nleft = 1;
        while (post[postStart + nleft - 1] != leftRoot)
            nleft++;

        TreeNode* root = new TreeNode(pre[preStart]);
        root->left =
            helper(preStart + 1, preStart + nleft, postStart, pre, post);
        root->right =
            helper(preStart + nleft + 1, preEnd, postStart + nleft, pre, post);
        return root;
    }
};