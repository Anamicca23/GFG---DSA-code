//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	   bool sameFreq(string s)
    {
        // code here 
        unordered_map<char,int>mp;
        for(auto it: s)mp[it]++; 
        
        for(char ch = 'a'; ch<='z'; ch++){
            unordered_map<char,int>mp1;
            mp[ch]--; 
            for(auto it:mp){
                if(it.second>0)mp1[it.second]++; 
                if(mp1.size()>1)break;
            }
            if(mp1.size()==1)return true; 
            mp[ch]++; 
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends