class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto it : nums)
            mp[it]++;
        priority_queue<pair<int, int>> pq;
        for (auto it : mp)
            pq.push({it.second, it.first});
        while (k-- && !pq.empty()) {
            int val = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            ans.push_back(val);
        }
        return ans;
    }
};