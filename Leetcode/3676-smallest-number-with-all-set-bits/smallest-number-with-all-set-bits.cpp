class Solution {
public:
    int smallestNumber(int n) {
        int k = ceil(log2(n + 1));
        return pow(2, k) - 1;
    }
};