class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n=s.length();
        for(int i=0; i<n; i++){
            char maxi=s[i];
            int ind=i;
            for(int j=n-1; j>i; j--){
                if(s[j]>maxi){
                    maxi=s[j];
                    ind=j;
                }
            }
            if(maxi>s[i]){
                swap(s[ind], s[i]);
                break;
            }
        }
        return s;
    }
};