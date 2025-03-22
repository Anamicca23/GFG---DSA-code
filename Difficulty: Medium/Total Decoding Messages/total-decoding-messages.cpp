//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string &s,int st,vector<int>&dp){
        int n = s.size();
        if(st >= n)return 1;
        if(s[st] == '0')return 0;
        if(st == n-1){
            return 1;
        }
        if(dp[st]!=-1){
            return dp[st];
        }
        string sp = "";
        sp += s[st];
        sp += s[st+1];
        
        if(stoi(sp) <= 26){
            return dp[st]=solve(s,st+1,dp) + solve(s,st+2,dp);
        }
        
        return dp[st]=solve(s,st+1,dp);
    }
    int countWays(string &digits) {
        vector<int>dp(digits.size(),-1);
        return solve(digits,0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends