class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        unordered_map<int, int> colorMap, ballMap;
        for (auto it : queries) {
            int ball = it[0], color = it[1];
            if (ballMap.find(ball) != ballMap.end()) {
                int prev = ballMap[ball];
                colorMap[prev]--;
                if (colorMap[prev] == 0)
                    colorMap.erase(prev);
            }
            ballMap[ball] = color;
            colorMap[color]++;
            ans.push_back(colorMap.size());
        }
        return ans;
    }
};