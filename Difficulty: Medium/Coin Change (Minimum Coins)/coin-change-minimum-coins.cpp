//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(int i, int sum, vector<int> &coins, vector<vector<int>> &dp, bool &isFound){
        if(sum==0){
            isFound = true;
            return 0;
        }
        if(i<0)
            return 100000;
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        int t=100000;
        int nt = fun(i-1, sum, coins, dp, isFound);
        
        if(coins[i] <= sum)
            t = 1 + fun(i,sum-coins[i],coins,dp,isFound);
        
        return dp[i][sum] = min(t,nt);
        
    }
  
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        bool isFound = false;
        int ans = fun(n-1, sum, coins, dp, isFound);
        
        return isFound?ans:-1;
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends