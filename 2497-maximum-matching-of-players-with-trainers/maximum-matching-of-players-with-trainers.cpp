class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& pl, vector<int>& tr) {
        priority_queue<int, vector<int>, greater<int>> p(pl.begin(), pl.end());
        priority_queue<int, vector<int>, greater<int>> q(tr.begin(), tr.end());
        int ans = 0;
        while (!p.empty() && !q.empty()) {
            if (p.top() > q.top())
                q.pop();
            else if (p.top() <= q.top()) {
                ans++;
                p.pop();
                q.pop();
            }
        }
        return ans;
    }
};