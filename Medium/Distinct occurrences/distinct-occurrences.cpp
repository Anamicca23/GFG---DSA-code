//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int mod=1e9+7;
        unordered_map<string,int>mp;
        mp[""]=1;
        for(int i=0;i<s.size();i++)
        {
            string k=t;
            for(int j=t.size()-1;j>=0;j--)
            {
                
                if(t[j]==s[i])
                {
                    
                     string l=k;
                     l.pop_back();
                  
                     mp[k]=(mp[k]+mp[l])%mod;
                }
               k.pop_back();
            }
        }
        return mp[t]%mod;
      //Your code here
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends