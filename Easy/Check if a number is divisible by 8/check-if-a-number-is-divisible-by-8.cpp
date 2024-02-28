//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        if (s.length() == 1) {
            return s[0] % 8 == 0 ? 1 : -1;
        }
        else if (s.length() == 2) {
            return ((s[0] * 10) + s[1]) % 8 == 0 ? 1 : -1;
        }
        else {
            return ((s[s.length() - 3] * 100) + (s[s.length() - 2] * 10) + s[s.length() - 1]) % 8 == 0 ? 1 : -1;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends