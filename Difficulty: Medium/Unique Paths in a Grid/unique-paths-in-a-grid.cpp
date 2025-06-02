class Solution {
  public:
    int f(int r,int c ,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(r==0 && c==0) return 1; //valid path found..
        if(r<0||c<0 || grid[r][c]==1) return 0; //no path possible..
        if(dp[r][c]!=-1) return dp[r][c];
        //explore the left and up direction..
        int up=f(r-1,c,grid,dp);
        int left=f(r,c-1,grid,dp);
        return dp[r][c]=left+up;
    }
    int uniquePaths(vector<vector<int>> &grid) {
        if(grid[0][0]==1) return 0; //not possible to travel..
        //using dp..
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};