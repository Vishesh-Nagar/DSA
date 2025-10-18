//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int, int>> items;
        for (int i = 0; i < val.size(); i++) {
            items.push_back(pair<int, int>{val.at(i), wt.at(i)});
        }
        sort(items.begin(), items.end(), comp);
        int currWt = 0;
        double ans = 0.0;
        for (int i = 0; i < val.size(); i++) {
            if (currWt + items[i].second <= capacity) {
                currWt += items[i].second;
                ans += items[i].first;
            } else {
                int remain = capacity - currWt;
                ans += (items[i].first / (double)items[i].second) * (double)remain;
                break;
            }
        }
        return ans;
    }
    bool static comp(pair<int, int>& a, pair<int, int>& b) {
        double result1 = (double)a.first / (double)a.second;
        double result2 = (double)b.first / (double)b.second;
        return result1 > result2;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends