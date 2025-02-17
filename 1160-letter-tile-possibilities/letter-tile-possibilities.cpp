class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        vector<bool> vis(tiles.length(), false);
        helper(tiles, "", vis, st);
        return st.size() - 1;
    }

    void helper(string& tiles, string current, vector<bool>& vis,
                unordered_set<string>& st) {
        st.insert(current);
        for (int i = 0; i < tiles.length(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                helper(tiles, current + tiles[i], vis, st);
                vis[i] = false;
            }
        }
    }
};