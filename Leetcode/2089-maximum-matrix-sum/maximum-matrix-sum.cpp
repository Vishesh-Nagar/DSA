class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int negatives = 0;
        int minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                if (val < 0)
                    negatives++;
                minVal = min(minVal, abs(val));
                sum += abs(val);
            }
        }
        if (negatives % 2 != 0)
            sum -= 2 * minVal;
        return sum;
    }
};