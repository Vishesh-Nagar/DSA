class Solution {
public:
    void addPair(pair<int, int> p, unordered_map<int, int>& freq,
                 multiset<pair<int, int>>& top, multiset<pair<int, int>>& rest,
                 long long& sum, int x) {
        if (top.size() < x || p > *top.begin()) {
            sum += 1LL * p.first * p.second;
            top.insert(p);
            if (top.size() > x) {
                auto t = *top.begin();
                sum -= 1LL * t.first * t.second;
                top.erase(top.begin());
                rest.insert(t);
            }
        } else
            rest.insert(p);
    }

    void removePair(pair<int, int> p, unordered_map<int, int>& freq,
                    multiset<pair<int, int>>& top,
                    multiset<pair<int, int>>& rest, long long& sum, int x) {
        if (!top.empty() && p >= *top.begin()) {
            sum -= 1LL * p.first * p.second;
            top.erase(top.find(p));
            if (!rest.empty()) {
                auto it = prev(rest.end());
                sum += 1LL * it->first * it->second;
                top.insert(*it);
                rest.erase(it);
            }
        } else
            rest.erase(rest.find(p));
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> freq;
        multiset<pair<int, int>> top, rest;
        long long sum = 0;
        vector<long long> ans;

        auto add = [&](int num) {
            if (freq[num])
                removePair({freq[num], num}, freq, top, rest, sum, x);
            freq[num]++;
            addPair({freq[num], num}, freq, top, rest, sum, x);
        };

        auto remove = [&](int num) {
            removePair({freq[num], num}, freq, top, rest, sum, x);
            freq[num]--;
            if (freq[num])
                addPair({freq[num], num}, freq, top, rest, sum, x);
        };

        for (int i = 0; i < nums.size(); ++i) {
            add(nums[i]);
            if (i >= k)
                remove(nums[i - k]);
            if (i >= k - 1)
                ans.push_back(sum);
        }
        return ans;
    }
};