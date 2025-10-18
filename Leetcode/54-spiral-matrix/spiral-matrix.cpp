class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        vector<int> result;
        while (left <= right && top <= bottom) {
            // Top row traversal, increase top row index
            for (int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;

            // Right col traversal, reduce right col index
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;
            
            // Bottom row traversal, decrease bottom row index
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }
            
            // Left col traversal, increase left col index
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }
        return result;
    }
};