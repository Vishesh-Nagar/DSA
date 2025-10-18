//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
#define pii pair<int, int>
    vector<int> replaceWithRank(vector<int>& arr, int N) {
        vector<int> ans(N);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < N; i++) {
            pq.push({ arr[i], i });
        }
        int rank = 1;
        pii prev = pq.top();
        pq.pop();
        ans[prev.second] = rank;
        while (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();
            if (curr.first != prev.first) {
                rank++;
            }
            ans[curr.second] = rank;
            prev = curr;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends