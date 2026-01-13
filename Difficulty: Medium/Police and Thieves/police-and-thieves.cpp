class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int i=0,j=1,n=arr.size();
        int count=0;
        while(i<n&&j<n){
            if(arr[i]=='P'){
                while(j<n&&arr[j]!='T')j++;
                if(j<n&&j-i<=k){
                    arr[i]='C';
                    arr[j]='C';
                    count++;
                    j++;
                }
            }
            else if(arr[i]=='T'){
                while(j<n&&arr[j]!='P')j++;
                if(j<n&&j-i<=k){
                    arr[i]='C';
                    arr[j]='C';
                    count++;
                    j++;
                }
            }
            i++;
        }
        return count;
    }
};