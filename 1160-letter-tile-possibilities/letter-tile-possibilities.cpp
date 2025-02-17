class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        sort(tiles.begin(), tiles.end());
        return helper(tiles, "", 0, st) - 1;
    }

    int factorial(int n) {
        if (n <= 1)
            return 1;
        int result = 1;
        for (int num = 2; num <= n; num++)
            result *= num;
        return result;
    }

    int permutations(string& seq) {
        vector<int> count(26, 0);
        for (char ch : seq)
            count[ch - 'A']++;
        int total = factorial(seq.length());
        for (int count : count) {
            if (count > 1)
                total /= factorial(count);
        }
        return total;
    }

    int helper(string& tiles, string current, int pos,
               unordered_set<string>& st) {
        if (pos >= tiles.length()) {
            if (st.insert(current).second)
                return permutations(current);
            return 0;
        }
        return helper(tiles, current, pos + 1, st) +
               helper(tiles, current + tiles[pos], pos + 1, st);
    }
};