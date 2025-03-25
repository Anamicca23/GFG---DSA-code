//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int solve(string &s,bool f,int lo,int hi,vector<vector<vector<int>>>&dp){
        if(lo > hi){
            return 0;
        }
        else if(lo == hi){
            if(f == false){
                return (s[lo] == 'F')?1:0;
            }
            else{
                return (s[lo] == 'T')?1:0;
            }
        }
        if(dp[lo][hi][int(f)]!=-1)return dp[lo][hi][int(f)];
        int ans = 0;
        for(int i=lo+1;i<hi;i+=2){
            int l1 = solve(s,true,lo,i-1,dp);
            int l2 = solve(s,false,lo,i-1,dp);
            int r1 = solve(s,true,i+1,hi,dp);
            int r2 = solve(s,false,i+1,hi,dp);
            if(f){
                if(s[i] == '&'){
                    ans += l1*r1;
                }
                else if(s[i] == '|'){
                    ans += r2*l1 + r1*l1 + r1*l2; 
                }
                else{
                    ans += l1*r2 + r1*l2;
                }
            }
            else{
                if(s[i] == '&'){
                    ans += l1*r2 + l2*r1 + r2*l2;
                }
                else if(s[i] == '|'){
                    ans += r2*l2; 
                }
                else{
                    ans += l1*r1 + r2*l2;
                }
            }
        }
        return dp[lo][hi][int(f)]=ans;
    }
    int countWays(string &s) {
        bool f = true;
        int n = s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(s,f,0,n-1,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends