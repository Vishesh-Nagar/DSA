//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        if (a.size() > b.size())
            return kthElement(b, a, k);
        int n = a.size(), m = b.size(),
            l = max(0, k - m), r = min(k, n);
        while (l <= r) {
            int midA = (l + r) / 2, midB = k - midA;
            int l1 = midA ? a[midA - 1] : INT_MIN,
                l2 = midB ? b[midB - 1] : INT_MIN;
            int r1 = midA < n ? a[midA] : INT_MAX,
                r2 = midB < m ? b[midB] : INT_MAX;
            if (l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            if (l1 > r2)
                r = midA - 1;
            else
                l = midA + 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends