class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int idx = 0;
        while (idx < traversal.size()) {
            int depth = 0;
            while (idx < traversal.size() && traversal[idx] == '-') {
                depth++;
                idx++;
            }
            int value = 0;
            while (idx < traversal.size() && isdigit(traversal[idx])) {
                value = value * 10 + (traversal[idx] - '0');
                idx++;
            }
            TreeNode* node = new TreeNode(value);
            while (st.size() > depth)
                st.pop();

            if (!st.empty()) {
                if (st.top()->left == nullptr)
                    st.top()->left = node;
                else
                    st.top()->right = node;
            }
            st.push(node);
        }

        while (st.size() > 1)
            st.pop();

        return st.top();
    }
};