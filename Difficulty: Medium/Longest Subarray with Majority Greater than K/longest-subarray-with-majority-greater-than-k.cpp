class Solution {
  public:
    virtual int longestSubarray(vector<int> &arr, int k) {
      int n=arr.size();
      vector<int> cal(n, 0);
      
      for(int i=0; i<n; i++){
        if(arr[i]>k) cal[i]=1;
        else cal[i]=-1;
      }
      
      vector<int> psumCal(n, 0);
      psumCal[0]=cal[0];
      for(int i=1; i<n; i++){
        psumCal[i]=psumCal[i-1]+cal[i];   
      }
      unordered_map<int, int> um;
      int ans=0;
      for(int i=0; i<n; i++){
        if(psumCal[i]>0) ans=max(ans, i+1);
        else{
          if(um.find(psumCal[i]-1) != um.end()){
            ans=max(ans, i-um[psumCal[i]-1]);  
          }
          if(um.find(psumCal[i]) != um.end()){
            continue;  
          }
          um[psumCal[i]]=i;
        }
      }
      
      return ans;
    }
};