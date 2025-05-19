class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        if (a + b <= c || a + c <= b || b + c <= a)
            return "none";
        unordered_set<int> s(nums.begin(), nums.end());
        if (s.size() == 1)
            return "equilateral";
        if (s.size() == 2)
            return "isosceles";
        return "scalene";
    }
};