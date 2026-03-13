class Solution {
  public:
    virtual bool isValid(string s){
      if(s.size()<1) return false;
      if(s.size()>1 && s[0]=='0' && (s[1]=='0' || s[1]!='0')) return false;
      if(s.size()>3) return false;
      
      int num=stoi(s);
      if(num>=0 && num<=255) return true;
      return false;
    }
    
    virtual vector<string> generateIp(string &s) {
      vector<string> ans;
      
      int n=s.size();
      
      for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
          for(int k=j+1; k<n; k++){
            
            vector<string> temp(4, "");
            temp[0]=s.substr(0, i+1);  
            temp[1]=s.substr(i+1, j-i);  
            temp[2]=s.substr(j+1, k-j);  
            temp[3]=s.substr(k+1, n-k-1);
            
            int c=0;
            for(c=0; c<4; c++){
              if(!isValid(temp[c])) break;    
            }
            
            if(c==4){ 
              string gens=temp[0]+"."+temp[1]+"."+temp[2]+"."+temp[3];    
              ans.push_back(gens); 
            }
            
          }    
        }  
      }
      return ans; 
    }
};