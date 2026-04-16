class Solution {
  public:
    virtual int myAtoi(string &s){
      long long int ans=1LL*0;
      bool flag=true;
      
      long long int limit=1LL*2147483647;
      long long int negLimit=-1LL*2147483648;
      
      for(char ch: s){
        if(ch>='0' && ch<='9'){
          int x=(ch-48);
          ans=(1LL*ans*10)+(1LL*x);
          
          if(flag && ans>limit) return (int)(limit);
          if(!flag && ((-1LL*ans)<negLimit)) return (int)(negLimit);
          
        }
        else if(ch=='-') flag=false;
        
        if(!(ch>='0' && ch<='9') && (ch!='-') && (ch!='+') && (ch!=' ')) break;
        
      }

      if(flag && ans>limit) return (int)(limit);
      if(!flag && ((-1LL*ans)<negLimit)) return (int)(negLimit);
      
      if(flag) return (int)(ans);
      return (int)(-1LL*ans);      
    }
};