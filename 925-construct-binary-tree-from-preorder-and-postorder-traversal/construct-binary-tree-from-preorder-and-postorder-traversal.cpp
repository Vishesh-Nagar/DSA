class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        vector<int> v(n + 1);
        for (int index = 0; index < n; index++)
            v[post[index]] = index;
        return helper(0, n - 1, 0, pre, v);
    }

    TreeNode* helper(int preStart, int preEnd, int postStart, vector<int>& pre,
                     vector<int>& v) {
        if (preStart > preEnd)
            return NULL;

        if (preStart == preEnd)
            return new TreeNode(pre[preStart]);

        int leftRoot = pre[preStart + 1];
        int nleft = v[leftRoot] - postStart + 1;

        TreeNode* root = new TreeNode(pre[preStart]);
        root->left = helper(preStart + 1, preStart + nleft, postStart, pre, v);
        root->right =
            helper(preStart + nleft + 1, preEnd, postStart + nleft, pre, v);
        return root;
    }
};