class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        for (int i : nums) {
            if (st.find(i) == st.end())
                st.insert(i);
            else
                return i;
        }
        return -1;
    }
};