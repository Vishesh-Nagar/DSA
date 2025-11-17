class Solution {
public:
    bool kLengthApart(vector<int>& a, int k) {
        int n = a.size();
        int j = 0, i = -1;
        while (j < n) {
            if (a[j] == 1) {
                if (i != -1 && j - i - 1 < k)
                    return false;
                i = j;
            }
            j++;
        }
        return true;
    }
};