class Solution {
public:
    bool checkPowersOfThree(int n) {
        return helper(0, n);
    }

    bool helper(int power, int n) {
        if (n == 0)
            return true;
        if (pow(3, power) > n)
            return false;
        bool take = helper(power + 1, n - pow(3, power));
        bool notTake = helper(power + 1, n);
        return take || notTake;
    }
};