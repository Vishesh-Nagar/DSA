class Solution {
public:
    int maximum69Number(int num) {
        int n = num, pos = -1, i = 0;
        while (n > 0) {
            if (n % 10 == 6)
                pos = i;
            n /= 10;
            i++;
        }
        if (pos == -1)
            return num;
        return num + 3 * pow(10, pos);
    }
};