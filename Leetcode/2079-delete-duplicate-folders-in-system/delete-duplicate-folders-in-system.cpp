struct Trie {
    string serial;
    unordered_map<string, Trie*> children;
};

class Solution {
public:
#define vvs vector<vector<string>>
    vvs deleteDuplicateFolder(vvs& paths) {
        Trie* root = new Trie();
        for (const vector<string>& path : paths) {
            Trie* cur = root;
            for (const string& node : path) {
                if (!cur->children.count(node))
                    cur->children[node] = new Trie();
                cur = cur->children[node];
            }
        }

        unordered_map<string, int> mp;
        function<void(Trie*)> construct = [&](Trie* node) {
            if (node->children.empty())
                return;

            vector<string> v;
            for (const auto& [folder, child] : node->children) {
                construct(child);
                v.push_back(folder + "(" + child->serial + ")");
            }
            sort(v.begin(), v.end());
            for (string& s : v)
                node->serial += move(s);
            mp[node->serial]++;
        };

        construct(root);

        vvs ans;
        vector<string> path;

        function<void(Trie*)> operate = [&](Trie* node) {
            if (mp[node->serial] > 1)
                return;
            if (!path.empty())
                ans.push_back(path);
            for (const auto& [folder, child] : node->children) {
                path.push_back(folder);
                operate(child);
                path.pop_back();
            }
        };

        operate(root);
        return ans;
    }
};