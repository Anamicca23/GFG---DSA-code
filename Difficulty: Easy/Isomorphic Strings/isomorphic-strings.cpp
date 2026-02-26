class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        int n=s1.length();
        int f1[26], f2[26];
        for(int i=0; i<26; i++){
            f1[i]=-1;
            f2[i]=-1;
        }

        for(int i=0; i<n; i++){
          int c1=s1[i]-'a';
          int c2=s2[i]-'a';
          if(f1[c1]==-1){
            if(f2[c2]!=-1) return false;
            f1[c1]=c2;
            f2[c2]=c1;
          }else{
            if(f1[c1]!=c2 || f2[c2]!=c1) return false;
          }
        }

        return  true;        
    }
};