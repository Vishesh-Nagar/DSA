#define vvc vector<vector<char>>

class Solution {
public:
    bool solve(vvc& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isvalid(i, j, k, board)) {
                            board[i][j] = k;

                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    bool isvalid(int r, int c, char digit, vvc& board) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == digit) {
                return false;
            }

            if (board[i][c] == digit) {
                return false;
            }

            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == digit) {
                return false;
            }
        }

        return true;
    }

    void solveSudoku(vvc& board) {
        solve(board);
    }
};