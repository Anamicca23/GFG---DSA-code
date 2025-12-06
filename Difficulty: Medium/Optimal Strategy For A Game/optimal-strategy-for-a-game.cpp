class Solution {
  public:
    virtual int getMaxInGame(int l, int r, vector<int> &arr, vector<vector<int>> &dp){
      if(l>r)
        return 0;
      if(dp[l][r] != -1)
        return dp[l][r];
        
      int ch1 = arr[l] + min(getMaxInGame(l+2, r, arr, dp), getMaxInGame(l+1, r-1, arr, dp));
      int ch2 = arr[r] + min(getMaxInGame(l, r-2, arr, dp), getMaxInGame(l+1, r-1, arr, dp));
      
      return dp[l][r] = max(ch1, ch2); 
    }
  
    virtual int maximumAmount(vector<int> &arr){
      int n=arr.size();
      vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
      
      return getMaxInGame(0, n-1, arr, dp);
    }
};