class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>min_prefix(n),max_prefix(n);
       int curr=arr[0],curr1=arr[0];
       int mini=INT_MAX,maxi=INT_MIN;
       min_prefix[0]=arr[0],max_prefix[0]=arr[0];
       
       for(int i=1;i<n;i++){
           curr=min(arr[i],curr+arr[i]);
           mini=min(mini,curr);
           min_prefix[i]=mini;
           
           curr1=max(arr[i],curr1+arr[i]);
           maxi=max(maxi,curr1);
           max_prefix[i]=maxi;
       }
        mini=INT_MAX,maxi=INT_MIN;
        curr=0,curr1=0;
        int ans=0;
        for(int i=n-1;i>=1;i--){
            curr=min(arr[i],curr+arr[i]);
            mini=min(mini,curr);
            ans=max(ans,abs(max_prefix[i-1]-mini));
            
              curr1=max(arr[i],curr1+arr[i]);
            maxi=max(maxi,curr1);
            ans=max(ans,abs(min_prefix[i-1]-maxi));
        }
        return ans;
       
    }
};