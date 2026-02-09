class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int m, n = arr.size();
        if(arr[0]<arr[n-1])return 0;
        int i=0,j=n-1;
        
        while(i<j){
            m = i+(j-i)/2;
            if(m>0 && arr[m-1]>arr[m])return m;
            if(arr[0]<arr[m])i=m+1;
            else j=m;
        }
    }
};