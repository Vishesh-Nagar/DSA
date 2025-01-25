class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > K)
                pq.pop();
        }
    }

    int add(int val) {
        if (pq.size() < K || pq.top() < val) {
            pq.push(val);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        return pq.top();
    }
};