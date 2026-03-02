class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int lmax=0, rmax=0, total=0;
        int l=0, r=n-1;

        while(l<r){
          if(arr[l]<arr[r]){
            if(lmax>arr[l]){
              total+=lmax-arr[l];
            }else{
              lmax=arr[l];
            }
            l++;
          }else{
            if(rmax>arr[r]){
              total+=rmax-arr[r];
            }else{
              rmax=arr[r];
            }
            r--;
          }
        }

        return total;        
    }
};