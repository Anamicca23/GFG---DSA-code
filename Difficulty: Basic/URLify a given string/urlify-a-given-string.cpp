class Solution {
  public:
    virtual string URLify(string &s){
      string rep="%20";
      string ans="";
      
      int sn=s.size();
      for(int i=0; i<sn; i++){
        if(s[i]==' ') ans+=rep;
        else ans+=s[i];
      }
      
      return ans;
    }
};