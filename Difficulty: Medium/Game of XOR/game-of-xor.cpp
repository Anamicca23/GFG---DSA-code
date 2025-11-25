class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int len = arr.size();
        int ans = 0;
        
        for(int i=0;i<arr.size();i++){
            int val = (i+1)*(len-i);
            if(val%2){
                ans^=arr[i];
            }
            
        }
        return ans;
    }
};