class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        vector<int> maxL(n), maxR(n);
        
        maxL[0] = arr[0];
        for(int i = 1; i < n; i++){
            maxL[i] = max(maxL[i - 1], arr[i]);
        }
        
        maxR[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            maxR[i] = max(maxR[i + 1], arr[i]);
        }
        
        vector<int> water(n);
        for(int i = 0; i < n; i++){
            water[i] = min(maxL[i], maxR[i]) - arr[i];
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += water[i];
        }
        return ans;
    }
};