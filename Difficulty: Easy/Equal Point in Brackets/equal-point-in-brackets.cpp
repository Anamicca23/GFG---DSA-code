class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n=s.length();
        int i=0,j=n;
        while(i<j){
            if(s[i]=='(' && s[j-1]==')'){
                i++;
                j--;
            }else if(s[i]==')'){
                i++;
            }else if(s[j-1]=='('){
                j--;
            }
        }
        return i;
    }
};