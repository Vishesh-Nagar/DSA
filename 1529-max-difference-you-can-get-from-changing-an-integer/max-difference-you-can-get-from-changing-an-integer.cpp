class Solution {
public:
    int maxDiff(int num) {
        auto change = [&](int x, int y) {
            string num_s = to_string(num);
            for (char& digit : num_s) {
                if (digit - '0' == x) {
                    digit = '0' + y;
                }
            }
            return num_s;
        };

        int mini = num;
        int maxi = num;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                string res = change(x, y);
                if (res[0] != '0') {
                    int res_i = stoi(res);
                    mini = min(mini, res_i);
                    maxi = max(maxi, res_i);
                }
            }
        }
        return maxi - mini;
    }
};