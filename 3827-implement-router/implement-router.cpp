class Router {
public:
    map<vector<int>, int> mp;             // to track duplicates
    queue<vector<int>> queue;             // to store packets in FIFO order
    unordered_map<int, vector<int>> time; // for timestamps tracking
    unordered_map<int, int> st;
    int maxSize = 0;

    Router(int memoryLimit) {
        maxSize = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        // checking for duplicate
        if (mp.count(packet))
            return false;
        if (queue.size() == maxSize) {
            // remove the first element if queue is full
            vector<int> res = queue.front();
            mp.erase(res);
            int temp = res[1];
            st[temp]++;
            queue.pop();
        }
        queue.push(packet);
        mp[packet]++;
        time[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (queue.empty())
            return {};
        vector<int> res = queue.front();
        queue.pop();
        mp.erase(res);
        int temp = res[1];
        st[temp]++;
        return res;
    }

    int getCount(int destination, int startTime, int endTime) {
        if (time.find(destination) == time.end())
            return 0;
        auto& p = time[destination];
        int temp = st[destination];
        auto right = lower_bound(p.begin() + temp, p.end(), startTime);
        auto left = upper_bound(p.begin() + temp, p.end(), endTime);
        return int(left - right);
    }
};