//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans=0;
        int j=1;
        int i=s.size()-1;
        while(i>0){
            if(s[i]>'9' || s[i]<'0'){
                return -1;
            }
            ans+=(s[i]-'0')*j;
            j*=10;
            i--;
        }
        if(s[0]=='-'){
            return -ans;
        }
        return ans+=(s[0]-'0')*j;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends