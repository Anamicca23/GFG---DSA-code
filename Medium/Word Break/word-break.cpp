//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int helper(int ind,string prefix,string &s, unordered_set<string>&dict){
        if(ind==s.size())return 0;
        
        prefix+=s[ind];
        if(ind==s.size()-1){
            return dict.find(prefix)!=dict.end();
        }
        
        int op1=0;
        int op2=0;
        if(dict.find(prefix)!=dict.end()){
            op1= helper(ind+1,"",s,dict);
        }
        op2= helper(ind+1,prefix,s,dict);
        return op1||op2;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_set<string>dict;
        for(auto it:dictionary){
            dict.insert(it);
        }
        return helper(0,"",s,dict);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends