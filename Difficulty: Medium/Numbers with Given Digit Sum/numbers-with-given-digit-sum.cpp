class Solution {
  public:
  static const int N=10;
  int memo[N][82];
  int solve(int n, int digit, int sum){
      if(digit==n) return sum==0;
      
      if(memo[digit][sum] != -1) 
      return memo[digit][sum];
      
      int cnt=0;
      for(int i=(digit==0); i<10; i++){
          if(sum-i < 0) break;
          cnt+=solve(n, digit+1, sum-i);
      }
      
      if(digit==0 && cnt==0) return -1;
      return memo[digit][sum]=cnt;
      
  }
    int countWays(int n, int sum) {
        // code here
        memset(memo, -1, sizeof(memo));
        return solve(n, 0, sum);
        
    }
};
