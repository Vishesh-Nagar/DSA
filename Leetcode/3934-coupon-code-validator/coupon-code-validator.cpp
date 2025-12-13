class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();

        unordered_map<string, int> mp = {{"electronics", 0},
                                         {"grocery", 1},
                                         {"pharmacy", 2},
                                         {"restaurant", 3}};

        vector<pair<pair<int, string>, string>> coupons;

        for (int i = 0; i < n; ++i) {
            if (!isActive[i])
                continue;

            if (mp.find(businessLine[i]) == mp.end())
                continue;

            if (code[i].empty())
                continue;
            bool isCodeValid = true;
            for (char c : code[i]) {
                if (!(isalnum(c) || c == '_')) {
                    isCodeValid = false;
                    break;
                }
            }
            if (!isCodeValid)
                continue;

            int idx = mp[businessLine[i]];
            coupons.push_back({{idx, code[i]}, code[i]});
        }

        sort(coupons.begin(), coupons.end());

        vector<string> ans;
        for (auto& it : coupons) {
            ans.push_back(it.second);
        }

        return ans;
    }
};