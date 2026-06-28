class Solution {
  public:
    virtual int svc(int i, int j, vector<int> &a, vector<int> &b, vector<vector<int>> &dp){
      if(j==b.size()) return 0;
      if(i==a.size()) return -1e9;
      if(dp[i][j] != -1) return dp[i][j];
      int take0=svc(i+1, j, a, b, dp);
      int take=a[i]*b[j] + svc(i+1, j+1, a, b, dp);
      return dp[i][j]=max(take0, take);
      
    }
    
    virtual int maxDotProduct(vector<int> &a, vector<int> &b){
      vector<vector<int>> dp((a.size())+1, vector<int>((b.size())+1, -1));    
      return svc(0, 0, a, b, dp);
    }
};

