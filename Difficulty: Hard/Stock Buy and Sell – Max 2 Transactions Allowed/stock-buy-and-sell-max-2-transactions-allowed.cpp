//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,vector<int> &prices,int k,bool canBuy){
        if(k==0) return 0;
        if(i>=prices.size())return 0;
        int profit=0;
        if(canBuy){
            int buyIt=solve(i+1,prices,k,0)-prices[i];
            int doNotBuyIt=solve(i+1,prices,k,1);
            profit=max(buyIt,doNotBuyIt);
            
        }else{
            int sellit=solve(i+1,prices,k-1,1)+prices[i];
            int doNotSellit=solve(i+1,prices,k,0);
            profit=max(sellit,doNotSellit);
        }
        return profit;
    }
    int solveMem(int i,vector<int> &prices,int k,bool canBuy,vector<vector<vector<int>>>&dp){
        if(k==0) return 0;
        if(i>=prices.size())return 0;
        if(dp[i][k][canBuy]!=-1) return dp[i][k][canBuy];
        int profit=0;
        if(canBuy){
            int buyIt=solveMem(i+1,prices,k,0,dp)-prices[i];
            int doNotBuyIt=solveMem(i+1,prices,k,1,dp);
            profit=max(buyIt,doNotBuyIt);
            
        }else{
            int sellit=solveMem(i+1,prices,k-1,1,dp)+prices[i];
            int doNotSellit=solveMem(i+1,prices,k,0,dp);
            profit=max(sellit,doNotSellit);
        }
        return dp[i][k][canBuy]=profit;
    }
    int solveTab(vector<int> &prices){
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(3,vector<int>(3,0)));
        for(int i=prices.size()-1;i>=0;i--){
            for(int k=1;k<=2;k++){
                for(int cb=0;cb<=1;cb++){
                     int profit=0;
                        if(cb){
                            int buyIt=dp[i+1][k][0]-prices[i];
                            int doNotBuyIt=dp[i+1][k][1];
                            profit=max(buyIt,doNotBuyIt);
                            
                        }else{
                            int sellit=dp[i+1][k-1][1]+prices[i];
                            int doNotSellit=dp[i+1][k][0];
                            profit=max(sellit,doNotSellit);
                        }
                        dp[i][k][cb]=profit;
                }
            }
        }
        return dp[0][2][1];
    }
    int solveSpa(vector<int> &prices){
        vector<vector<int>>curr(3,vector<int>(3,0));
        vector<vector<int>>next(3,vector<int>(3,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int k=1;k<=2;k++){
                for(int cb=0;cb<=1;cb++){
                     int profit=0;
                        if(cb){
                            int buyIt=next[k][0]-prices[i];
                            int doNotBuyIt=next[k][1];
                            profit=max(buyIt,doNotBuyIt);
                            
                        }else{
                            int sellit=next[k-1][1]+prices[i];
                            int doNotSellit=next[k][0];
                            profit=max(sellit,doNotSellit);
                        }
                        curr[k][cb]=profit;
                }
            }
            next=curr;
        }
        return next[2][1];
    }
    int maxProfit(vector<int> &prices) {
        // return solve(0,prices,2,1);
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(3,vector<int>(3,-1)));
        // return solveMem(0,prices,2,1,dp);
        // return solveTab(prices);
        return solveSpa(prices);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends