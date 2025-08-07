class Solution {
  public:
    int getLPSLength(string &s) {
        int n=s.size();
        vector<int> ans(n,0);
        int prefix=0,suffix=1;
        while(suffix<n){
            if(s[prefix]==s[suffix]){
                ans[suffix]=prefix+1;
                prefix++;
                suffix++;
                
            }
            else{
                if(prefix==0){
                    ans[suffix]=0;
                    suffix++;
                }
                else{
                    prefix=ans[prefix-1];
                }
            }
        }
        return ans[n-1];
        
    }
};

