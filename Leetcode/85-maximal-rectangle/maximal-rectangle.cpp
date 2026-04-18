class Solution {
public:
    vector<int> NSL(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= arr[i])
                st.pop();
            res[i] = st.empty() ? -1 : st.top().second;
            st.push({arr[i], i});
        }
        return res;
    }

    vector<int> NSR(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= arr[i])
                st.pop();
            res[i] = st.empty() ? n : st.top().second;
            st.push({arr[i], i});
        }
        return res;
    }

    int MAH(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int area = (right[i] - left[i] - 1) * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int> arr(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    arr[j]++;
                else
                    arr[j] = 0;
            }
            ans = max(ans, MAH(arr));
        }
        return ans;
    }
};