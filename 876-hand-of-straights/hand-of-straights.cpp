class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> map;
        for (int card : hand)
            map[card]++;

        for (auto& entry : map)
            pq.push(entry.first);

        while (!pq.empty()) {
            int start = pq.top();
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                if (map[card] == 0)
                    return false;

                map[card]--;
                if (map[card] == 0 && card == pq.top())
                    pq.pop();
            }
        }
        return true;
    }
};