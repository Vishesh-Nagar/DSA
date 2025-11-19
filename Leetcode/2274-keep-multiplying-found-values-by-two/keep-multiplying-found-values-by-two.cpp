class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st(nums.begin(), nums.end());
        while (true) {
            if (st.find(original) != st.end())
                original *= 2;
            else
                return original;
        }
        return -1;
    }
};