//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    
    bool merchandiseEligibility(int sum) {
        if(sum % 20 == 0 || sum % 24 == 0 || sum == 2024)   return true;
        return false;
    }
    
    bool pickNotPick(int idx, int sum, int coins[], int N) {
        if(sum > 0 && merchandiseEligibility(sum))  return true;
        if(idx >= N)    return false;
        return pickNotPick(idx + 1, sum + coins[idx], coins, N) ||
               pickNotPick(idx + 1, sum, coins, N);
    }
    
    int isPossible(int N , int coins[]) 
    {
        return pickNotPick(0, 0, coins, N);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends