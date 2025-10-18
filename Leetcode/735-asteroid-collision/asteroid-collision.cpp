class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        for (int i = 0; i < a.size(); i++) {
            int curr = a[i];
            if (curr > 0 || s.empty())
                s.push(curr);
            else {
                while (!s.empty() && s.top() > 0 && s.top() < abs(curr))
                    s.pop();
                if (!s.empty() && s.top() == abs(curr))
                    s.pop();
                else if (s.empty() || s.top() < 0)
                    s.push(curr);
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};