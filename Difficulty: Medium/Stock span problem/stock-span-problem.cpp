class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n), ans(n);
        stack<pair<int, int>> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first <= arr[i])
                st.pop();
            v[i] = st.empty() ? -1 : st.top().second;
            st.push({arr[i], i});
        }
        for(int i = 0; i < n; i++)
            ans[i] = i - v[i];
        return ans;
    }
};