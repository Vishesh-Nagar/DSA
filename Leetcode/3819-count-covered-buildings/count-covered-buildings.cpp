class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> leftLimit(n + 1, INT_MAX), rightLimit(n + 1, INT_MIN);
        vector<int> downLimit(n + 1, INT_MAX), upLimit(n + 1, INT_MIN);

        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            leftLimit[y] = min(leftLimit[y], x);
            rightLimit[y] = max(rightLimit[y], x);
            downLimit[x] = min(downLimit[x], y);
            upLimit[x] = max(upLimit[x], y);
        }

        int ans = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            if ((leftLimit[y] < x && x < rightLimit[y]) &&
                (downLimit[x] < y && y < upLimit[x]))
                ans++;
        }

        return ans;
    }
};