class Solution {
  public:
    int totalsum;
    int dp[51][301];
    int solve(vector<int>&arr,int diff,int i,int sum){
        if(i>=arr.size()){
            return (totalsum-2*sum)==diff;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take=solve(arr,diff,i+1,sum+arr[i]);
        int nottake=solve(arr,diff,i+1,sum);
        return dp[i][sum]=take+nottake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum=0;
        memset(dp,-1,sizeof(dp));
        totalsum=accumulate(begin(arr),end(arr),0);
        return solve(arr,diff,0,sum);
    }
};