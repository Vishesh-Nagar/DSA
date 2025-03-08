class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        queue<char> q;
        int count = 0;
        while (q.size() < k) {
            char c = blocks[q.size()];
            if (c == 'W')
                count++;
            q.push(c);
        }

        int ans = count;
        for (int i = k; i < blocks.size(); i++) {
            if (q.front() == 'W')
                count--;
            q.pop();

            if (blocks[i] == 'W')
                count++;
            q.push(blocks[i]);

            ans = min(ans, count);
        }
        return ans;
    }
};