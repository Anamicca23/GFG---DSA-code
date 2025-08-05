class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int m=mat.size(),n=mat[0].size(),ans=-1e9;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1e9));
        //prefix sum
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        //
        int sum;
        //each row
        for(int r=0;r<m;r++){
            //each subarray
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    sum=mat[r][j]-(i==0?0:mat[r][i-1]);
                    dp[i][j]=max((dp[i][j]+sum),sum);
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        //
        return ans;
    }
};