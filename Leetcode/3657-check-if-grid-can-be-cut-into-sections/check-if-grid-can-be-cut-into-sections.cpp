class Solution {
public:
    bool check(vector<vector<int>>& rectangles, int dim) {
        int count = 0;
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
             });

        int j = rectangles[0][dim + 2];

        for (int i = 1; i < rectangles.size(); i++) {
            vector<int>& rect = rectangles[i];
            if (j <= rect[dim])
                count++;
            j = max(j, rect[dim + 2]);
        }

        return count >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return check(rectangles, 0) || check(rectangles, 1);
    }
};