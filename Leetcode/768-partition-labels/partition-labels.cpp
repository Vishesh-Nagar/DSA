class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int last[26] = {0}, first[26] = {0};
        int start = 0, end = 0;

        for (int i = 0; i < s.length(); i++)
            last[s[i] - 'a'] = i;

        for (int i = 0; i < s.length(); i++) {
            if (!first[s[i] - 'a'])
                first[s[i] - 'a'] = i;

            if (end < first[s[i] - 'a']) {
                ans.push_back(end - start + 1);
                start = i;
                end = i;
            }

            end = max(end, last[s[i] - 'a']);
        }

        if (end - start + 1 > 0)
            ans.push_back(end - start + 1);

        return ans;
    }
};