class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ans = 0;
        for (int i = 0, j = 0; i < n && j < m; i++, j++) {
            while (j < m && players[i] > trainers[j])
                j++;
            if (j < m)
                ans++;
        }
        return ans;
    }
};