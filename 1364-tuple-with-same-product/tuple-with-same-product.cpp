class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> prod;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                ans += 8 * prod[product];
                prod[product]++;
            }
        }
        return ans;
    }
};