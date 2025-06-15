class Solution {
public:
    int maxDiff(int num) {
        auto replace = [](string& s, char x, char y) {
            for (char& digit : s) {
                if (digit == x) {
                    digit = y;
                }
            }
        };

        string mini = to_string(num);
        string maxi = to_string(num);
        for (char digit : maxi) {
            if (digit != '9') {
                replace(maxi, digit, '9');
                break;
            }
        }
        for (int i = 0; i < mini.size(); ++i) {
            char digit = mini[i];
            if (i == 0) {
                if (digit != '1') {
                    replace(mini, digit, '1');
                    break;
                }
            } else {
                if (digit != '0' && digit != mini[0]) {
                    replace(mini, digit, '0');
                    break;
                }
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};