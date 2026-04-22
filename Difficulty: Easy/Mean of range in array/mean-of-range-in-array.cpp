class Solution {
  public:
    virtual vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries){
      int n = arr.size();
      vector<int> prefSum(n, 0);
      prefSum[0]=arr[0];
      
      for(int i=1; i<n; i++) prefSum[i]=prefSum[i-1]+arr[i];
      
      
      vector<int> ans;
      
      for(auto x: queries){
        int l=x[0], r=x[1];
        int len=r-l+1;
        int sum=prefSum[r]-(l>0? prefSum[l-1]: 0);
        
        int res=(1.0*sum)/(1.0*len);
        ans.push_back(res);
        
      }
      
      return ans;
    }
};