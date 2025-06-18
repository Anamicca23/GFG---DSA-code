class Solution {
  public:
  
    bool ispalindrome(string&s){
        int i=0; 
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(int id,string&s,vector<string>&curr,vector<vector<string>>&res){
        if(id==s.size()){
            res.push_back(curr);
            return;
        }
        string temp="";
        for(int i=id; i<s.size(); i++){
            temp+=s[i];
            if(ispalindrome(temp)){
                curr.push_back(temp);
                backtrack(i+1,s,curr,res);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
    
       vector<vector<string>>res;
       vector<string>curr;
       backtrack(0,s,curr,res);
       return res;
    }
};