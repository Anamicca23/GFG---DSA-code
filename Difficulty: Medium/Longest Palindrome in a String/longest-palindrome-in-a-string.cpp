//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        int ind = -1;
        int length = -1;
        
        for(int len=0;len<n;len++){
            int i,j;
            
            for(i=0,j=i+len; j<n; i++,j++){
                if(i==j)
                    dp[i][j] = true;
                else if(j==i+1 && s[i]==s[j])
                    dp[i][j] = true;
                else if(s[i]==s[j] && dp[i+1][j-1])
                    dp[i][j] = true;
            
                if(dp[i][j] && (length<(j-i+1))){
                    ind = i;
                    length = j-i+1;
                    
                }
                    
            }
            
        }
        
        return s.substr(ind, length);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends