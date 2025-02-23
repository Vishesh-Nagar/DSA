class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int preIndex = 0;
        int postIndex = 0;
        return constructTree(preIndex, postIndex, pre, post);
    }

    TreeNode* constructTree(int& preIndex, int& postIndex, vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preIndex]);
        preIndex++;
        if (root->val != post[postIndex])
            root->left = constructTree(preIndex, postIndex, pre, post);

        if (root->val != post[postIndex])
            root->right = constructTree(preIndex, postIndex, pre, post);
        
        postIndex++;
        return root;
    }
};