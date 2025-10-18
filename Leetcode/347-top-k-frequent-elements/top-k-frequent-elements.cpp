class Solution {
public:
#define pii pair<int, int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto it : nums)
            mp[it]++;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};