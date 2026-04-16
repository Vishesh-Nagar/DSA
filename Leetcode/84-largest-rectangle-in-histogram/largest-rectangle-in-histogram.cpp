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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL_idx = NSL(heights);
        vector<int> NSR_idx = NSR(heights);
        vector<int> width(n), res(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = NSL_idx[i], b = NSR_idx[i];
            width[i] = b - a - 1;
            res[i] = width[i] * heights[i];
            ans = max(ans, res[i]);
        }
        return ans;
    }
};