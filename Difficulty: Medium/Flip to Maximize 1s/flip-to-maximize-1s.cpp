class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int c1=0,curr=0,m=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                c1++;
            }
        }
        for(int i:arr){
            int v=(i==0)?1:-1;
            curr=max(v,curr+v);
            m=max(m,curr);
        }
        return c1+m;
        
    }
};