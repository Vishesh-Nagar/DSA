class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0);
        int ans = 0;

        for (const auto& row : matrix) {
            for (int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }

            // Calculate max area using stack-based method
            stack<int> st;
            for (int i = 0; i < heights.size(); i++) {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    int w = st.empty() ? i : i - st.top() - 1;
                    ans = max(ans, h * w);
                }
                st.push(i);
            }
        }

        return ans;
    }
};