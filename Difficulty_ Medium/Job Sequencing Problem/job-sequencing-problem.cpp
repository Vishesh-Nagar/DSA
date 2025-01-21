//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> JobSequencing(vector<int>& id, vector<int>& deadline, vector<int>& profit) {
        int n = id.size();
        vector<pair<int, int>> jobs;
        int maxDeadline = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, deadline[i]);
            jobs.push_back({ profit[i], deadline[i] });
        }
        sort(jobs.rbegin(), jobs.rend());
        vector<int> days(maxDeadline + 1, -1);
        int totalProfit = 0, countJobs = 0;
        for (int i = 0; i < n; i++) {
            int p = jobs[i].first;
            int dl = jobs[i].second;
            for (int j = dl; j > 0; j--) {
                if (days[j] == -1) {
                    days[j] = i;
                    totalProfit += p;
                    countJobs++;
                    break;
                }
            }
        }
        return { countJobs, totalProfit };
    }
};

//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends