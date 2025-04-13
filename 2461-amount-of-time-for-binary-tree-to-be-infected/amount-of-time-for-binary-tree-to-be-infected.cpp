class Solution {
public:
    void markParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (node == NULL)
            return;
        if (node->left)
            parent[node->left] = node;
        if (node->right)
            parent[node->right] = node;
        markParent(node->left, parent);
        markParent(node->right, parent);
    }

    TreeNode* find(int start, TreeNode* node) {
        if (node == NULL)
            return NULL;
        if (node->val == start)
            return node;
        TreeNode* l = find(start, node->left);
        if (l) return l;
        return find(start, node->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        
        TreeNode* src = find(start, root);
        q.push(src);
        vis[src] = true;
        
        int count = 0;
        while (!q.empty()) {
            int s = q.size();
            count++;
            for (int i = 0; i < s; i++) {
                TreeNode* f = q.front();
                q.pop();

                if (f->left && !vis[f->left]) {
                    q.push(f->left);
                    vis[f->left] = true;
                }

                if (f->right && !vis[f->right]) {
                    q.push(f->right);
                    vis[f->right] = true;
                }

                if (parent[f] && !vis[parent[f]]) {
                    q.push(parent[f]);
                    vis[parent[f]] = true;
                }
            }
        }
        return count - 1;
    }
};