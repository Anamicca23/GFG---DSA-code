class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
        int d=256;
        int q=101;
        int n=txt.size();
        int m=pat.size();
        int p=0;
        int t=0;
        int h=1;
        
        vector<int>str;
        for(int i=0; i<m-1; i++){
            h=(h*d)%q;
        }
        for(int i=0; i<m; i++){
            p=(d*p+pat[i])%q;
            t=(d*t+txt[i])%q;
        }
        for(int i=0; i<=n-m; i++){
            if(t==p){
                bool matched=true;
                for(int j=0; j<m; j++){
                    if(txt[i+j]!=pat[j]){
                        matched=false;
                        break;
                    }
                }
                if(matched) str.push_back(i+1);
                
            }
        
        if(i<n-m){
            t=(d*(t-txt[i]*h)+txt[i+m])%q;
            if(t<0){
                t+=q;
            }
        }
        }
        return str;
    }
};