class Solution {
  public:
    bool good(vector<int>& arr, int mid, int k){
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=ceil((double)arr[i]/mid);
            
        }
        return k>=ans;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int i=1;
        int j=*max_element(arr.begin(),arr.end());
        int ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(good(arr,mid,k)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};