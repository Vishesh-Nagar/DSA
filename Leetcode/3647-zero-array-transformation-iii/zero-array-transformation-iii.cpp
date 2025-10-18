class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), cmp);

        priority_queue<int> pq;
        vector<int> del(nums.size() + 1, 0);
        int ops = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            ops += del[i];
            while (j < queries.size() && queries[j][0] == i) {
                pq.push(queries[j][1]);
                j++;
            }
            while (ops < nums[i] && !pq.empty() && pq.top() >= i) {
                ops += 1;
                del[pq.top() + 1] -= 1;
                pq.pop();
            }
            if (ops < nums[i]) {
                return -1;
            }
        }
        return pq.size();
    }
};