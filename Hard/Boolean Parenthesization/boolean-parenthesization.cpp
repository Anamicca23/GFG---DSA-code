//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    const long long MOD = 1003;

    pair<int, int> dfs(string& s, int low, int high, vector<vector<pair<int, int>>>& dp) {
        if (low == high) {
            if (s[low] == 'T') return {1, 0};
            else return {0, 1};
        }

        if (dp[low][high] != make_pair(-1, -1)) return dp[low][high];

        long long truth = 0, falsy = 0;

        for (int i = low; i < high; i += 2) {
            auto left = dfs(s, low, i, dp);
            auto right = dfs(s, i + 2, high, dp);

            if (s[i + 1] == '|') {
                truth = (truth + (left.first * right.first + left.first * right.second + left.second * right.first) % MOD) % MOD;
                falsy = (falsy + left.second * right.second) % MOD;
            } else if (s[i + 1] == '&') {
                truth = (truth + left.first * right.first) % MOD;
                falsy = (falsy + (left.first * right.second + left.second * right.first + left.second * right.second) % MOD) % MOD;
            } else {
                truth = (truth + (left.first * right.second + left.second * right.first) % MOD) % MOD;
                falsy = (falsy + (left.first * right.first + left.second * right.second) % MOD) % MOD;
            }
        }

        return dp[low][high] = {truth, falsy};
    }

    int countWays(int n, string s) {
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
        return dfs(s, 0, n - 1, dp).first;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends