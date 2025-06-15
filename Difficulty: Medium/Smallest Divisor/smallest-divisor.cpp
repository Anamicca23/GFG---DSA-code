class Solution {
  public:
    int fun(int mid,vector<int>&arr){
      int ans=0;
      for(int i=0;i<arr.size();i++){
          ans+=ceil((double)arr[i]/(double)mid);
      }
      return ans;
  }
    int smallestDivisor(vector<int>& arr, int k) {
        int n=arr.size();
        int l=1;
        int h=INT_MIN;
        for(int i=0;i<arr.size();i++){
            h=max(h,arr[i]);
        }
        int ans=INT_MAX;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(fun(mid,arr)<=k){
                ans=min(mid,ans);
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};

