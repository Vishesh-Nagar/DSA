class Solution {
public:
    int help(vector<int>& tops, vector<int>& bottoms, int target) {
        int rot = 0;
        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] == target)
                continue;
            if (bottoms[i] == target)
                rot++;
            else
                return INT_MAX;
        }
        return rot;
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        for (int i = 1; i <= 6; i++) {
            ans = min(ans, help(tops, bottoms, i));
            ans = min(ans, help(bottoms, tops, i));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};