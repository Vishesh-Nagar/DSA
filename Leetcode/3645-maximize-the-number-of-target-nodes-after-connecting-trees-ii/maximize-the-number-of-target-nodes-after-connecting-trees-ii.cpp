class Solution {
public:
    vector<bool> oddEven(vector<vector<int>>& adj) {
        vector<bool> v(adj.size());

        bool isEven = false;
        queue<pair<int, int>> q;
        q.emplace(make_pair(0, -1));

        while (!q.empty()) {
            isEven ^= true;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                v[node] = isEven;
                for (int it : adj[node]) {
                    if (it == parent)
                        continue;
                    q.emplace(it, node);
                }
            }
        }

        return v;
    }

    vector<int> findOddEvenCount(vector<bool>& vertex) {
        vector<int> v = {0, 0};
        for (bool b : vertex)
            v[b]++;

        return v;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {

        vector<vector<int>> tree1(edges1.size() + 1);
        vector<vector<int>> tree2(edges2.size() + 1);

        for (auto e : edges1) {
            int u = e[0], v = e[1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }
        for (auto e : edges2) {
            int u = e[0], v = e[1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        vector<bool> buildTree1 = oddEven(tree1);
        vector<int> build1 = findOddEvenCount(buildTree1);

        vector<bool> buildTree2 = oddEven(tree2);
        vector<int> build2 = findOddEvenCount(buildTree2);

        int val = max(build2.front(), build2.back());
        vector<int> ans(tree1.size(), val);

        for (int i = 0; i < tree1.size(); i++) {
            if (buildTree1[i])
                ans[i] += build1[1];
            else
                ans[i] += build1[0];
        }

        return ans;
    }
};