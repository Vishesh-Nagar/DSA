class Spreadsheet {
public:
    int value(string a) {
        if (a[0] < 'A' || a[0] > 'Z') {
            return stoi(a);
        }
        auto [c, r] = location(a);
        return grid[r][c];
    }

    pair<int, int> location(string a) {
        int c = a[0] - 'A';
        int r = 0;
        for (int i = 1; i < a.length(); i++) {
            int v = a[i] - '0';
            r = r * 10 + v;
        }
        r--;
        return {c, r};
    }

    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        grid.assign(rows, vector<int>(27, 0));
    }

    void setCell(string cell, int value) {
        auto [c, r] = location(cell);
        grid[r][c] = value;
    }

    void resetCell(string cell) {
        auto [c, r] = location(cell);
        grid[r][c] = 0;
    }

    int getValue(string formula) {
        string a = "";
        int i = 1;
        while (formula[i] != '+') {
            a += formula[i++];
        }

        i++;
        string b = "";
        while (i < formula.length()) {
            b += formula[i++];
        }

        int a1 = value(a), b1 = value(b);
        return a1 + b1;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */