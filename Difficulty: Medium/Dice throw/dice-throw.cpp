class Solution {
  public:
    int ch;
    vector<vector<int>> dp;
    int f(int i,int x){
        if(i==0) return x==0;
        if(x<0) return 0;
        if(dp[i][x]!=-1) return dp[i][x];
        
        int t=0;
        for(int k=1;k<=ch;k++) t+=f(i-1,x-k);
        return dp[i][x]=t;
    }
  
    int noOfWays(int m, int n, int x) {
        ch=m;
        dp=vector<vector<int>>(n+1,vector<int>(x+1,-1));
        return f(n,x);
    }
};