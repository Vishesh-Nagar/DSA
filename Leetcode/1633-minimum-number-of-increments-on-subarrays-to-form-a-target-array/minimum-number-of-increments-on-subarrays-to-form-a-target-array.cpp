class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        int prev, curr;
        for (int i = 1; i < target.size(); i++) {
            prev = target[i - 1], curr = target[i];
            if (curr > prev)
                ans += (curr - prev);
        }
        return ans;
    }
};