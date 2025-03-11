class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        
        priority_queue<pair<int, char>> pq;
        for (auto& [ch, freq] : mp)
            pq.push({freq, ch});
        
        string ans;
        while (pq.size() >= 2) {
            auto [freq1, char1] = pq.top();
            pq.pop();
            auto [freq2, char2] = pq.top();
            pq.pop();
            ans += char1;
            ans += char2;
            if (--freq1 > 0)
                pq.push({freq1, char1});
            if (--freq2 > 0)
                pq.push({freq2, char2});
        }
        
        if (!pq.empty()) {
            auto [freq, ch] = pq.top();
            if (freq > 1)
                return "";
            ans += ch;
        }
        return ans;
    }
};