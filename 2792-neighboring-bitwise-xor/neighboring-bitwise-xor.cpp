class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for (int num : derived) {
            x ^= num;
        }
        return x == 0;
    }
};