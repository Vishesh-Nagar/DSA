class FindSumPairs {
public:
    vector<int> a, b;
    unordered_map<int, int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->a = nums1;
        this->b = nums2;
        for (int i : b) {
            mp[i]++;
        }
    }

    void add(int index, int val) {
        mp[b[index]]--;
        b[index] += val;
        mp[b[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int i : a) {
            int diff = tot - i;
            ans += mp[diff];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */