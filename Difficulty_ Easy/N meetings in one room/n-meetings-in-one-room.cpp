//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> pairs;
        int n = start.size();
        for (int i = 0; i < n; i++) {
            pairs.push_back({ start[i],end[i] });
        }
        int ans = 1;
        sort(pairs.begin(), pairs.end());
        int prev = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (pairs[prev].first > pairs[i].second) {
                ans++;
                prev = i;
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends